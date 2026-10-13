"""Independently verify source, four Ghidra receipts and seal a truthful candidate."""

from __future__ import annotations

import hashlib
import json
import math
import re
import shutil

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

from common import (FENCE, LEASE_ID, PRIOR_PROJECT, PRIOR_REPORT, REPORT,
                    ROOT, SCRIPTS, SOURCE, SOURCE_SHA, STANDARD, STANDARD_SHA,
                    TASK_SHA, check_lease, now, sha256, tree_hashes, write_json,
                    atomic_bytes)

MAX_REPORT_BYTES = 33554432


def mapped_body(source: bytes, segments: list[tuple[int, int, int]], va: int,
                size: int) -> tuple[bytes, int]:
    offsets = [file_offset + va - base for base, length, file_offset in segments
               if base <= va and va + size <= base + length]
    if len(offsets) != 1:
        raise RuntimeError(f"ambiguous PT_LOAD mapping at 0x{va:x}")
    offset = offsets[0]
    body = source[offset:offset + size]
    if len(body) != size:
        raise RuntimeError(f"truncated PT_LOAD body at 0x{va:x}")
    return body, offset


def main() -> None:
    check_lease()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("TASK_159 already sealed")
    index = json.loads((REPORT / "target_index.json").read_text(encoding="utf-8"))
    batch = json.loads((REPORT / "batch_run_receipt.json").read_text(encoding="utf-8"))
    project = json.loads((REPORT / "project_copy_receipt.json").read_text(encoding="utf-8"))
    if (index.get("task_id") != "TASK_159" or index.get("task_sha256") != TASK_SHA or
            index.get("source_sha256") != SOURCE_SHA or len(index.get("targets", [])) != 284 or
            len(index.get("chunks", [])) != 4 or batch.get("task_id") != "TASK_159" or
            len(batch.get("chunks", [])) != 4 or batch.get("fresh_imports") != 0 or
            project.get("project_file_hashes") != tree_hashes(PRIOR_PROJECT) or
            project.get("copied_file_hashes_match") is not True):
        raise RuntimeError("task/source/batch/copied-project identity changed")
    prior_log = (PRIOR_REPORT / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
    if ("Analysis timed out at 480 seconds" not in prior_log or
            "IllegalArgumentException: invalid target bounds" not in prior_log or
            "Import succeeded" not in prior_log):
        raise RuntimeError("TASK_156 root-cause log changed")
    for name in ("ghidra_stdout.log", "ghidra_command.json"):
        target = REPORT / f"prior_task156_{name}"
        if target.exists():
            raise RuntimeError("prior log copy already exists")
        shutil.copy2(PRIOR_REPORT / name, target)
        if sha256(target) != sha256(PRIOR_REPORT / name):
            raise RuntimeError("prior log copy hash changed")

    chunk_outcomes = {row["chunk"]: row for row in batch["chunks"]}
    if set(chunk_outcomes) != {0, 1, 2, 3}:
        raise RuntimeError("missing/duplicate Ghidra chunk")
    ghidra_rows = {}
    successful_chunks = 0
    failed_chunks = []
    total_ghidra_seconds = 0.0
    for meta in index["chunks"]:
        number = meta["chunk"]
        folder = REPORT / meta["folder"]
        targets = folder / "targets.tsv"
        if (not targets.is_file() or sha256(targets) != meta["target_tsv_sha256"] or
                meta["count"] > 100):
            raise RuntimeError(f"chunk {number} target split changed")
        outcome = chunk_outcomes[number]
        if outcome["status"] != "OUTPUT_READY":
            failed_chunks.append({"chunk": number, "status": outcome["status"]})
            continue
        receipt = json.loads((folder / "ghidra_command.json").read_text(encoding="utf-8"))
        raw_path = folder / "ghidra_raw.json"
        command = receipt["command"]
        if (receipt["status"] != "OUTPUT_READY" or receipt["exit_code"] != 0 or
                receipt["task_id"] != "TASK_159" or receipt["chunk"] != number or
                receipt["lease_id"] != LEASE_ID or receipt["fencing_token"] != FENCE or
                receipt["target_tsv_sha256"] != meta["target_tsv_sha256"] or
                receipt["script_sha256"] != sha256(SCRIPTS / "ExportDexvmp159.java") or
                receipt["result_sha256"] != sha256(raw_path) or
                receipt["stdout_sha256"] != sha256(folder / "ghidra_stdout.log") or
                receipt["stderr_sha256"] != sha256(folder / "ghidra_stderr.log") or
                command[3:10] != ["-process", SOURCE.name, "-noanalysis", "-readOnly",
                                  "-max-cpu", "1", "-scriptPath"] or
                "-import" in command or receipt.get("fresh_imports") != 0):
            raise RuntimeError(f"chunk {number} command/result hashes invalid")
        if receipt["elapsed_seconds"] > 900 or receipt["timeout_seconds"] > 900:
            raise RuntimeError(f"chunk {number} process exceeded cap")
        total_ghidra_seconds += receipt["elapsed_seconds"]
        stdout = (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        if (f"[TASK_159] processed {meta['count']}/{meta['count']}" not in stdout or
                f"Processing read-only project file: /{SOURCE.name}" not in stdout):
            raise RuntimeError(f"chunk {number} Ghidra completion log missing")
        raw = json.loads(raw_path.read_text(encoding="utf-8"))
        if (raw.get("task_id") != "TASK_159" or raw.get("program_name") != SOURCE.name or
                raw.get("image_base") != "0x100000" or len(raw.get("targets", [])) != meta["count"]):
            raise RuntimeError(f"chunk {number} raw identity/count mismatch")
        expected_indices = [int(line.split("\t", 1)[0]) for line in
                            targets.read_text(encoding="utf-8").splitlines()]
        if [row["index"] for row in raw["targets"]] != expected_indices:
            raise RuntimeError(f"chunk {number} row order/index mismatch")
        for row in raw["targets"]:
            if row["index"] in ghidra_rows:
                raise RuntimeError("duplicate Ghidra target")
            ghidra_rows[row["index"]] = row
        successful_chunks += 1
    if total_ghidra_seconds > 3600:
        raise RuntimeError("aggregate Ghidra time cap exceeded")

    source_bytes = SOURCE.read_bytes()
    if hashlib.sha256(source_bytes).hexdigest() != SOURCE_SHA:
        raise RuntimeError("original source SHA mismatch")
    with SOURCE.open("rb") as handle:
        elf = ELFFile(handle)
        dynsym = elf.get_section_by_name(".dynsym")
        by_va = {}
        for symbol in dynsym.iter_symbols():
            if (symbol["st_info"]["type"] == "STT_FUNC" and
                    symbol["st_shndx"] != "SHN_UNDEF" and int(symbol["st_size"]) > 0):
                by_va.setdefault(int(symbol["st_value"]), []).append(
                    (symbol.name, int(symbol["st_size"])))
        segments = [(int(s["p_vaddr"]), int(s["p_filesz"]), int(s["p_offset"]))
                    for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    if len(by_va) != 284 or sum(map(len, by_va.values())) != 284:
        raise RuntimeError("independent .dynsym recount changed")

    capstone = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    capstone.detail = False
    assembly = []
    c_parts = []
    records = []
    source_decoded_words = 0
    source_undecoded_words = 0
    ghidra_listed = 0
    ghidra_flow_verified = 0
    c_recovered = 0
    c_missing = []
    ghidra_memory_match = 0
    c_warnings = 0
    for target in index["targets"]:
        n = target["index"]
        va = int(target["elf_va"], 16)
        size = target["size_bytes"]
        if n < 1 or n > 284 or va not in by_va or (target["symbol"], size) != by_va[va][0]:
            raise RuntimeError(f"target {n} source symbol differs")
        body, file_offset = mapped_body(source_bytes, segments, va, size)
        digest = hashlib.sha256(body).hexdigest()
        if (target["file_offset"] != f"0x{file_offset:x}" or
                target["source_body_sha256"] != digest):
            raise RuntimeError(f"source PT_LOAD hash differs at {n}")
        assembly.append(f"\n// EXPORT index={n} ELF_VA=0x{va:x} size={size} sha256={digest} symbol={target['symbol']}\n")
        decoded_here = 0
        undecoded_here = 0
        decoded_at = {}
        for offset in range(0, size, 4):
            word = body[offset:offset + 4]
            address = va + offset
            instructions = list(capstone.disasm(word, address, count=1)) if len(word) == 4 else []
            if instructions and instructions[0].size == 4:
                ins = instructions[0]
                decoded_at[address] = ins.mnemonic
                assembly.append(f"0x{address:x}\t{word.hex()}\t{ins.mnemonic}\t{ins.op_str}\n")
                decoded_here += 1
            else:
                assembly.append(f"0x{address:x}\t{word.hex()}\t.UNDECODED_WORD\n")
                undecoded_here += 1
        source_decoded_words += decoded_here
        source_undecoded_words += undecoded_here
        row = ghidra_rows.get(n)
        c_good = False
        listed_count = 0
        flows = 0
        error = "Ghidra chunk missing"
        if row is not None:
            if (row["elf_va"] != target["elf_va"] or row["symbol"] != target["symbol"] or
                    row["size_bytes"] != size or row["database_va"] != f"0x{va + 0x100000:x}" or
                    row["expected_source_sha256"] != digest or
                    row["ghidra_memory_sha256"] != digest or
                    row["source_bytes_match"] is not True):
                raise RuntimeError(f"Ghidra/source body mismatch at {n}")
            ghidra_memory_match += 1
            seen = []
            for line in row["instructions"]:
                match = re.match(r"^([0-9a-fA-F]+):\s+", line)
                if not match:
                    raise RuntimeError(f"Ghidra instruction parse failed at {n}")
                source_address = int(match.group(1), 16) - 0x100000
                if source_address not in decoded_at:
                    raise RuntimeError(f"Ghidra listing lacks original AArch64 opcode at {n}")
                seen.append(source_address)
            if seen != sorted(set(seen)) or len(seen) != row["instruction_count_observed"]:
                raise RuntimeError(f"Ghidra listing order/count differs at {n}")
            listed_count = len(seen)
            ghidra_listed += listed_count
            for call in row["calls"]:
                match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
                if not match:
                    raise RuntimeError(f"Ghidra call parse failed at {n}")
                source_address = int(match.group(1), 16) - 0x100000
                mnemonic = decoded_at.get(source_address, "")
                if mnemonic not in ("bl", "blr", "b", "br", "blraa", "blrab", "braa", "brab"):
                    raise RuntimeError(f"Ghidra flow edge unsupported by source opcode at {n}")
                flows += 1
            ghidra_flow_verified += flows
            error = row["error"]
            c_good = bool(row["decompile_success"] is True and row["pseudocode"].strip() and not error)
            if c_good:
                c_recovered += 1
                c_warnings += "WARNING:" in row["pseudocode"]
                c_parts.append(f"\n/* EXPORT index={n} ELF_VA=0x{va:x} size={size} source_sha256={digest} */\n")
                c_parts.append(row["pseudocode"])
            else:
                c_missing.append({"index": n, "elf_va": target["elf_va"],
                                  "size_bytes": size, "error": error})
        else:
            c_missing.append({"index": n, "elf_va": target["elf_va"],
                              "size_bytes": size, "error": error})
        records.append({"index": n, "elf_va": target["elf_va"], "size_bytes": size,
                        "source_body_sha256": digest, "source_words_decoded": decoded_here,
                        "source_words_undecoded": undecoded_here,
                        "ghidra_memory_bytes_match": row is not None,
                        "ghidra_listed_source_aligned_instructions": listed_count,
                        "ghidra_flow_transfers_source_verified": flows,
                        "ghidra_c_like_recovered": c_good,
                        "ghidra_error": error})
    sample_count = math.ceil(284 * 0.1)
    sample_indices = sorted({round(i * 283 / (sample_count - 1)) for i in range(sample_count)})
    if len(sample_indices) < sample_count:
        raise RuntimeError("ordinary sample count below 10%")
    for sample in sample_indices:
        target = index["targets"][sample]
        body, _ = mapped_body(source_bytes, segments, int(target["elf_va"], 16),
                              target["size_bytes"])
        if hashlib.sha256(body).hexdigest() != records[sample]["source_body_sha256"]:
            raise RuntimeError(f"spread source rehash differed at {sample}")

    check_lease()
    atomic_bytes(REPORT / "all_source_assembly.txt", "".join(assembly).encode("utf-8"))
    atomic_bytes(REPORT / "all_recovered_export_pseudocode.c", "".join(c_parts).encode("utf-8"))
    write_json(REPORT / "independent_verification.json", {
        "task_id": "TASK_159", "revision": 1, "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "source_sha256": SOURCE_SHA, "source_bodies_rehashed": 284,
        "defined_nonzero_function_symbols": 284, "unique_export_vas": 284,
        "ghidra_chunks_output_ready": successful_chunks,
        "ghidra_failed_chunks": failed_chunks,
        "ghidra_memory_bodies_matched": ghidra_memory_match,
        "ghidra_c_like_bodies_recovered": c_recovered,
        "ghidra_c_like_failures": c_missing,
        "source_decoded_aarch64_words": source_decoded_words,
        "source_undecoded_words": source_undecoded_words,
        "ghidra_listed_source_aligned_instructions": ghidra_listed,
        "ghidra_flow_transfers_source_opcode_verified": ghidra_flow_verified,
        "c_bodies_with_warnings": c_warnings,
        "ordinary_records_spread_rehashed": len(sample_indices),
        "ordinary_records_total": 284,
        "prior_import_analysis_completed": False,
        "internal_nonexported_functions_covered": False,
        "runtime_or_pixel_semantics_proven": False,
        "records": records,
    })
    audit = (f"# TASK_159 R1 audit index\n\nCanonical standard read: `{STANDARD}` "
             f"SHA-256 `{STANDARD_SHA}` at `{now()}`.\n\nExact TASK_159 R1 SHA-256 `{TASK_SHA}`; "
             f"lease `{LEASE_ID}`, fence `{FENCE}`. Original source `{SOURCE}` SHA-256 `{SOURCE_SHA}`. "
             "TASK_156 failed raw log and imported project were read-only inputs; the 10-file Ghidra project "
             "was copied with identical hashes, and no fresh import was run. All 284 exported PT_LOAD bodies were "
             "independently rehashed. Raw commands, Ghidra logs, per-target C/listing and source assembly are "
             "included in this report. Actual worker is a Codex subagent, not AGY.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    complete = c_recovered == 284 and successful_chunks == 4
    disposition = "BOUNDED_RESEARCH_CANDIDATE" if complete else "PARTIAL_RESEARCH_CANDIDATE"
    huge = records[231]
    master = f"""# TASK_159 R1 - libdexvmp exported-function correction

Status: **{disposition} awaiting independent CEO review**. This Codex worker corrected a TASK_156 exporter bound; AGY was not used. Static exported-function evidence does not prove the binary's runtime behavior.

## Observed

- Original `libdexvmp.so` SHA-256 `{SOURCE_SHA}` contains 284 defined nonzero-size `.dynsym` function VAs. All 284 PT_LOAD body hashes were checked against original bytes. TASK_156's Ghidra import succeeded but its autoanalysis timed out at 480 seconds; its exporter then failed because VA 0x29cd4 is 224,440 bytes, above its 65,536-byte target guard.
- A 10-file hash-verified project copy was processed in four sequential read-only passes (100/100/83/1 VAs), with zero new imports. {successful_chunks}/4 passes yielded parseable output. {ghidra_memory_match}/284 Ghidra-memory bodies matched original source hashes; {c_recovered}/284 yielded nonempty C-like text. Isolated oversized target index232: memory match={huge['ghidra_memory_bytes_match']}, C-like recovered={huge['ghidra_c_like_recovered']}, error=`{huge['ghidra_error']}`.
- Full original source bytes were retained by hash and disassembled word-by-word: {source_decoded_words:,} AArch64 words decoded and {source_undecoded_words:,} undecoded words explicitly marked. Ghidra listed {ghidra_listed:,} source-aligned instruction addresses and {ghidra_flow_verified:,} source-opcode-verified flow transfers. {len(sample_indices)}/284 spread function records ({len(sample_indices)/284:.1%}) received a separate source-body rehash. C output contains Ghidra warnings in {c_warnings} recovered bodies.

## Inferred

- These results are a bounded static export map. Obfuscated names, partial prior autoanalysis and decompiler warnings limit semantic use. The source assembly file is complete as bytes and address labels, while undecoded words are not asserted to be instructions.

## Unknown / blocked input

- Internal non-exported functions, dynamic dispatch, imported implementations, runtime behavior and pixel formulas are not established. Missing C bodies and partial Ghidra listings are itemized in `independent_verification.json`.
- TASK_063 remains BLOCKED; TASK_064A-G/065/066 remain PLANNED. No product Phase PASS, V4/P7 production, self-review, or unreviewed commit/push is claimed.
"""
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", master.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_159", "revision": 1,
        "status": "BOUNDED_RESEARCH_REPORT_READY" if complete else "PARTIAL_RESEARCH_REPORT_READY",
        "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
        "source_bodies_rehashed": 284, "c_like_bodies_recovered": c_recovered,
        "independent_review_pending": True, "phase_pass": False,
    })
    files = {path.relative_to(REPORT).as_posix(): sha256(path)
             for path in sorted(REPORT.rglob("*")) if path.is_file() and
             path.relative_to(REPORT).as_posix() not in ("COMPLETE.json", "PROGRESS.json")}
    report_bytes = sum((REPORT / name).stat().st_size for name in files)
    if not files or report_bytes > MAX_REPORT_BYTES:
        raise RuntimeError(f"report size exceeds task cap: {report_bytes}")
    code_files = {path.relative_to(ROOT).as_posix(): sha256(path)
                  for path in sorted(SCRIPTS.iterdir())
                  if path.is_file() and path.suffix in (".py", ".java")}
    check_lease()
    write_json(REPORT / "COMPLETE.json", {
        "schema_version": "2.1.2", "task_id": "TASK_159", "revision": 1,
        "status": "COMPLETE", "semantic_disposition": disposition,
        "generated_at": now(), "standard_sha256": STANDARD_SHA,
        "task_sha256": TASK_SHA, "source_sha256": SOURCE_SHA,
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "execution_mode": "REAL_CODEX_SUBAGENT_NO_AGY",
        "review_state": "AWAITING_INDEPENDENT_CEO_REVIEW",
        "critical_provenance_rechecked": True,
        "ordinary_records_independently_rechecked": len(sample_indices),
        "ordinary_records_total": 284,
        "source_bodies_rehashed": 284,
        "ghidra_memory_bodies_matched": ghidra_memory_match,
        "c_like_bodies_recovered": c_recovered,
        "unrecovered_c_like_vas": [row["elf_va"] for row in c_missing],
        "internal_nonexported_functions_covered": False,
        "runtime_or_pixel_semantics_proven": False,
        "files": files, "code_files": code_files,
    })
    print(json.dumps({"status": disposition, "source_vas": 284,
                      "chunks_ready": successful_chunks, "memory_bodies": ghidra_memory_match,
                      "c_like_bodies": c_recovered, "missing_c": len(c_missing),
                      "report_bytes": report_bytes, "report_files": len(files)}), flush=True)


if __name__ == "__main__":
    main()
