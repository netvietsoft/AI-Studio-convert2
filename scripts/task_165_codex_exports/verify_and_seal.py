"""Independent original-byte/Ghidra audit; seal TASK_165's consolidated export map."""
from __future__ import annotations

import hashlib
import json
import re
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

from common import (FENCE, HIST151, HIST152, LEASE_ID, REPORT, ROOT, SCRIPTS,
                    SCRATCH, SOURCE, SOURCE_SHA, STANDARD_SHA, TASK_SHA,
                    atomic_bytes, check_lease, now, sha256, write_json)
from prepare import EXPECTED, tree_hashes, verify_manifest

MAX_REPORT_BYTES = 134217728
OLD151 = REPORT / "historical_raw/TASK_151"
OLD152 = REPORT / "historical_raw/TASK_152"

def rows_by_chunk(index: dict) -> tuple[dict[int, dict], list[dict]]:
    old_batch = json.loads((OLD151 / "batch_run_receipt.json").read_text(encoding="utf-8"))
    if old_batch.get("task_id") != "TASK_151" or len(old_batch.get("chunks", [])) != 10:
        raise RuntimeError("historical batch identity/count invalid")
    steps = {item["chunk"]: item for item in old_batch["chunks"]}
    if len(steps) != 10:
        raise RuntimeError("historical chunk duplication")
    result: dict[int, dict] = {}
    receipts = []
    for meta in index["chunks"]:
        number = meta["chunk"]
        folder = OLD151 / f"chunk_{number:02d}"
        receipt = json.loads((folder / "ghidra_command.json").read_text(encoding="utf-8"))
        raw_file = folder / "ghidra_raw.json"
        if (steps[number]["status"] != "OUTPUT_READY" or receipt["status"] != "OUTPUT_READY" or
                receipt["exit_code"] != 0 or receipt["task_id"] != "TASK_151" or
                receipt["source_sha256"] != SOURCE_SHA or receipt["elapsed_seconds"] > 900 or
                receipt["command"][3:9] != ["-process", SOURCE.name, "-noanalysis", "-readOnly", "-max-cpu", "1"] or
                "-import" in receipt["command"] or
                receipt["target_tsv_sha256"] != meta["target_tsv_sha256"] or
                receipt["target_tsv_sha256"] != sha256(folder / "targets.tsv") or
                receipt["script_sha256"] != sha256(ROOT / "scripts/task151_direct_mtfilter/ExportMTFilterChunk151.java") or
                receipt["result_sha256"] != sha256(raw_file) or
                receipt["stdout_sha256"] != sha256(folder / "ghidra_stdout.log") or
                receipt["stderr_sha256"] != sha256(folder / "ghidra_stderr.log")):
            raise RuntimeError(f"historical chunk {number} raw receipt invalid")
        log = (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        if ("Processing read-only project file: /libMTFilterKernel.so" not in log or
                f"[TASK_151] processed {meta['count']}/{meta['count']}" not in log):
            raise RuntimeError(f"historical chunk {number} completion log invalid")
        raw = json.loads(raw_file.read_text(encoding="utf-8"))
        expected_indices = list(range(meta["first_index"], meta["last_index"] + 1))
        lines = (folder / "targets.tsv").read_text(encoding="utf-8").splitlines()
        if (raw.get("task_id") != "TASK_151" or raw.get("program_name") != SOURCE.name or
                raw.get("image_base") != "0x100000" or len(raw["targets"]) != meta["count"] or
                [row["index"] for row in raw["targets"]] != expected_indices or
                [int(line.split("\t", 1)[0]) for line in lines] != expected_indices):
            raise RuntimeError(f"historical chunk {number} raw rows invalid")
        for row in raw["targets"]:
            if row["index"] in result:
                raise RuntimeError("duplicate historical Ghidra row")
            result[row["index"]] = row
        receipts.append({"chunk": number, "count": meta["count"],
                         "elapsed_seconds": receipt["elapsed_seconds"],
                         "raw_sha256": sha256(raw_file)})
    if len(result) != EXPECTED:
        raise RuntimeError("historical Ghidra row coverage incomplete")
    return result, receipts

def check_152(row151: dict, target: dict) -> dict:
    old = json.loads((OLD152 / "parseoldfilter_ghidra_raw.json").read_text(encoding="utf-8"))
    receipt = json.loads((OLD152 / "ghidra_command.json").read_text(encoding="utf-8"))
    rows = old["targets"]
    if (len(rows) != 1 or old.get("task_id") != "TASK_152" or old.get("program_name") != SOURCE.name or
            old.get("image_base") != "0x100000" or receipt.get("status") != "OUTPUT_READY" or
            receipt.get("exit_code") != 0 or receipt.get("source_sha256") != SOURCE_SHA or
            receipt.get("elapsed_seconds") > 900 or
            receipt["command"][3:9] != ["-process", SOURCE.name, "-noanalysis", "-readOnly", "-max-cpu", "1"] or
            "-import" in receipt["command"] or
            receipt["target_tsv_sha256"] != sha256(OLD152 / "target.tsv") or
            receipt["script_sha256"] != sha256(ROOT / "scripts/task152_direct_mtfilter_timeout/ExportMTFilterTimeout152.java") or
            receipt["result_sha256"] != sha256(OLD152 / "parseoldfilter_ghidra_raw.json") or
            receipt["stdout_sha256"] != sha256(OLD152 / "ghidra_stdout.log") or
            receipt["stderr_sha256"] != sha256(OLD152 / "ghidra_stderr.log")):
        raise RuntimeError("historical timeout-correction receipt invalid")
    row = rows[0]
    if (row151["elf_va"] != "0x1741e4" or row151["decompile_success"] is not False or
            row["elf_va"] != target["elf_va"] or row["size_bytes"] != target["size_bytes"] or
            row["expected_source_sha256"] != target["source_body_sha256"] or
            row["ghidra_memory_sha256"] != target["source_body_sha256"] or
            row["source_bytes_match"] is not True or row["decompile_success"] is not True or
            not row["pseudocode"].strip() or row["error"]):
        raise RuntimeError("historical correction row does not resolve exact source body")
    if hashlib.sha256(row["pseudocode"].encode("utf-8")).hexdigest() != sha256(OLD152 / "parseoldfilter_pseudocode.c"):
        raise RuntimeError("historical corrected C output file differs")
    return row

def listing_addresses(row: dict, image_base: int, source_instructions: dict[int, object],
                      position: int) -> tuple[int, int]:
    instructions = row["instructions"]
    if len(instructions) != row["instruction_count_observed"]:
        raise RuntimeError(f"Ghidra listing count differs at index {position}")
    addresses = []
    for line in instructions:
        match = re.match(r"^([0-9a-fA-F]+):\s+", line)
        if not match:
            raise RuntimeError(f"Ghidra listing parse failed at index {position}")
        address = int(match.group(1), 16) - image_base
        if address not in source_instructions:
            raise RuntimeError(f"Ghidra listing address not in original at index {position}")
        addresses.append(address)
    if addresses != sorted(set(addresses)):
        raise RuntimeError(f"Ghidra listing order/duplicate at index {position}")
    for call in row["calls"]:
        match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
        if not match:
            raise RuntimeError(f"Ghidra call parse failed at index {position}")
        address = int(match.group(1), 16) - image_base
        if address not in source_instructions or source_instructions[address].mnemonic not in ("bl", "blr", "b", "br"):
            raise RuntimeError(f"Ghidra call opcode not in original at index {position}")
    return len(addresses), len(row["calls"])

def main() -> None:
    check_lease()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("TASK_165 already sealed")
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError("original SO changed")
    verify_manifest(HIST151, "TASK_151")
    verify_manifest(HIST152, "TASK_152")
    archive = json.loads((REPORT / "archive_receipt.json").read_text(encoding="utf-8"))
    for rel, item in archive["copied_raw_files"].items():
        owned = REPORT / rel
        original = Path(item["original_path"])
        if sha256(owned) != item["sha256"] or sha256(original) != item["sha256"]:
            raise RuntimeError("historical raw copy/original changed: " + rel)
    if archive["fresh_imports_this_revision"] != 0:
        raise RuntimeError("unexpected fresh import")
    old_index = json.loads((OLD151 / "target_index.json").read_text(encoding="utf-8"))
    index = json.loads((REPORT / "source_index.json").read_text(encoding="utf-8"))
    if (index.get("task_sha256") != TASK_SHA or index.get("standard_sha256") != STANDARD_SHA or
            index.get("lease_id") != LEASE_ID or index.get("fencing_token") != FENCE or
            index.get("unique_export_vas") != EXPECTED or len(index["targets"]) != EXPECTED or
            index.get("source_sha256") != SOURCE_SHA or
            sha256(REPORT / "audit_sample/targets.tsv") != index["audit_sample_tsv_sha256"]):
        raise RuntimeError("owned source index identity changed")
    raw_source = SOURCE.read_bytes()
    with SOURCE.open("rb") as handle:
        elf = ELFFile(handle)
        by_va: dict[int, list[tuple[str, int]]] = {}
        for symbol in elf.get_section_by_name(".dynsym").iter_symbols():
            if (symbol["st_info"]["type"] == "STT_FUNC" and symbol["st_shndx"] != "SHN_UNDEF" and
                    int(symbol["st_size"]) > 0):
                by_va.setdefault(int(symbol["st_value"]), []).append((symbol.name, int(symbol["st_size"])))
        segments = [{"index": i, "va": int(segment["p_vaddr"]), "offset": int(segment["p_offset"]),
                     "file_size": int(segment["p_filesz"]), "memory_size": int(segment["p_memsz"])}
                    for i, segment in enumerate(elf.iter_segments()) if segment["p_type"] == "PT_LOAD"]
    if len(by_va) != EXPECTED or sum(map(len, by_va.values())) != 2634 or segments != index["pt_load_segments"]:
        raise RuntimeError("independent original ELF/PT_LOAD census differs")
    old_rows, old_receipts = rows_by_chunk(old_index)
    correction = check_152(old_rows[1781], index["targets"][1780])
    audit_receipt = json.loads((REPORT / "audit_sample/ghidra_command.json").read_text(encoding="utf-8"))
    audit_path = REPORT / "audit_sample/ghidra_raw.json"
    if (audit_receipt.get("status") != "OUTPUT_READY" or audit_receipt.get("exit_code") != 0 or
            audit_receipt.get("lease_id") != LEASE_ID or audit_receipt.get("fencing_token") != FENCE or
            audit_receipt.get("source_sha256") != SOURCE_SHA or audit_receipt.get("elapsed_seconds", 901) > 900 or
            audit_receipt.get("target_tsv_sha256") != index["audit_sample_tsv_sha256"] or
            audit_receipt.get("script_sha256") != sha256(SCRIPTS / "AuditMTFilter165.java") or
            audit_receipt.get("result_sha256") != sha256(audit_path) or
            audit_receipt.get("stdout_sha256") != sha256(REPORT / "audit_sample/ghidra_stdout.log") or
            audit_receipt.get("stderr_sha256") != sha256(REPORT / "audit_sample/ghidra_stderr.log") or
            audit_receipt["command"][3:9] != ["-process", SOURCE.name, "-noanalysis", "-readOnly", "-max-cpu", "1"] or
            "-import" in audit_receipt["command"]):
        raise RuntimeError("current independent Ghidra spot-check receipt invalid")
    audit_data = json.loads(audit_path.read_text(encoding="utf-8"))
    sample_positions = index["audit_sample_positions"]
    if (audit_data.get("task_id") != "TASK_165" or audit_data.get("program_name") != SOURCE.name or
            audit_data.get("image_base") != "0x100000" or
            [row["index"] for row in audit_data["targets"]] != sample_positions or
            len(sample_positions) < 237):
        raise RuntimeError("current Ghidra spread target/row identity invalid")
    sampled = {row["index"]: row for row in audit_data["targets"]}
    capstone = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    map_lines = []
    ordinary = []
    partial_listings = 0
    warnings = 0
    c_like = 0
    source_instruction_count = 0
    listed_instruction_count = 0
    calls = 0
    c_text_sample_equal = 0
    c_text_sample_compared = 0
    unresolved = []
    for position, target in enumerate(index["targets"], 1):
        va, size = int(target["elf_va"], 16), target["size_bytes"]
        aliases = sorted(by_va.get(va, []), key=lambda item: (-item[1], item[0]))
        mapped = [(segment["index"], segment["offset"] + va - segment["va"])
                  for segment in segments if segment["va"] <= va and va + size <= segment["va"] + segment["file_size"]]
        if (target["index"] != position or len(mapped) != 1 or not aliases or
                aliases[0] != (target["symbol"], size) or mapped[0] !=
                (target["pt_load_segment_index"], int(target["file_offset"], 16))):
            raise RuntimeError(f"original ELF/body mapping invalid at {position}")
        body = raw_source[mapped[0][1]:mapped[0][1] + size]
        digest = hashlib.sha256(body).hexdigest()
        if len(body) != size or digest != target["source_body_sha256"]:
            raise RuntimeError(f"original body hash invalid at {position}")
        decoded = list(capstone.disasm(body, va))
        if sum(instruction.size for instruction in decoded) != size:
            raise RuntimeError(f"original body not fully AArch64 decoded at {position}")
        instruction_map = {instruction.address: instruction for instruction in decoded}
        if len(instruction_map) != len(decoded):
            raise RuntimeError(f"duplicate original instruction address at {position}")
        source_instruction_count += len(decoded)
        historic = old_rows[position]
        if (historic["index"] != position or historic["symbol"] != target["symbol"] or
                historic["elf_va"] != target["elf_va"] or historic["size_bytes"] != size or
                int(historic["database_va"], 16) != va + 0x100000 or
                historic["expected_source_sha256"] != digest or
                historic["ghidra_memory_sha256"] != digest or
                historic["source_bytes_match"] is not True):
            raise RuntimeError(f"historical Ghidra memory/original mismatch at {position}")
        source_row = correction if position == 1781 else historic
        listed, flow = listing_addresses(source_row, 0x100000, instruction_map, position)
        listed_instruction_count += listed
        calls += flow
        partial_listings += listed != len(decoded)
        if source_row["decompile_success"] is not True or not source_row["pseudocode"].strip() or source_row["error"]:
            unresolved.append({"index": position, "elf_va": target["elf_va"], "error": source_row["error"]})
        else:
            c_like += 1
        warnings += "WARNING:" in source_row["pseudocode"]
        c_digest = hashlib.sha256(source_row["pseudocode"].encode("utf-8")).hexdigest()
        historical_path = ("historical_raw/TASK_152/parseoldfilter_ghidra_raw.json" if position == 1781
                           else f"historical_raw/TASK_151/chunk_{(position - 1) // 256:02d}/ghidra_raw.json")
        map_lines.append(json.dumps({
            "index": position, "elf_va": target["elf_va"], "symbol": target["symbol"],
            "aliases": target["aliases"], "size_bytes": size, "file_offset": target["file_offset"],
            "pt_load_segment_index": target["pt_load_segment_index"],
            "source_body_sha256": digest, "ghidra_memory_sha256": source_row["ghidra_memory_sha256"],
            "c_like_recovered": source_row["decompile_success"] is True and bool(source_row["pseudocode"].strip()),
            "c_like_utf8_sha256": c_digest, "c_like_characters": len(source_row["pseudocode"]),
            "c_warning_present": "WARNING:" in source_row["pseudocode"],
            "source_aarch64_instructions": len(decoded), "ghidra_listed_instructions": listed,
            "ghidra_listing_partial": listed != len(decoded), "source_aligned_flow_transfers": flow,
            "raw_ghidra_result": historical_path,
            "historical_decompile_timeout_seconds": 180 if position == 1781 else 15,
            "independently_ghidra_resampled_this_revision": position in sampled,
        }, ensure_ascii=False))
        if position in sampled:
            fresh = sampled[position]
            if (fresh["elf_va"] != target["elf_va"] or fresh["symbol"] != target["symbol"] or
                    fresh["size_bytes"] != size or int(fresh["database_va"], 16) != va + 0x100000 or
                    fresh["expected_source_sha256"] != digest or fresh["ghidra_memory_sha256"] != digest or
                    fresh["source_bytes_match"] is not True):
                raise RuntimeError(f"independent Ghidra spread sample differs from original at {position}")
            fresh_listed, fresh_flows = listing_addresses(fresh, 0x100000, instruction_map, position)
            if fresh["decompile_success"] is True and fresh["pseudocode"].strip():
                c_text_sample_compared += 1
                c_text_sample_equal += hashlib.sha256(fresh["pseudocode"].encode("utf-8")).hexdigest() == c_digest
            ordinary.append({"index": position, "elf_va": target["elf_va"],
                             "source_body_sha256": digest,
                             "fresh_ghidra_memory_sha256": fresh["ghidra_memory_sha256"],
                             "fresh_c_like_recovered": fresh["decompile_success"] is True and
                                                       bool(fresh["pseudocode"].strip()),
                             "fresh_listed_source_aligned_instructions": fresh_listed,
                             "fresh_flow_transfers_source_aligned": fresh_flows,
                             "fresh_historical_c_utf8_equal": c_digest ==
                                 hashlib.sha256(fresh["pseudocode"].encode("utf-8")).hexdigest()})
    if len(ordinary) < 237 or source_instruction_count != 170169:
        raise RuntimeError("independent ordinary/source-instruction coverage below expected")
    full = c_like == EXPECTED and not unresolved
    disposition = "BOUNDED_EXPORT_CANDIDATE" if full else "PARTIAL_EXPORT_CANDIDATE"
    atomic_bytes(REPORT / "export_map.ndjson", ("\n".join(map_lines) + "\n").encode("utf-8"))
    write_json(REPORT / "unresolved.json", {"task_id": "TASK_165", "revision": 1, "rows": unresolved})
    verification = {"task_id": "TASK_165", "revision": 1, "generated_at": now(),
        "source_sha256": SOURCE_SHA, "original_dynsym_function_symbols": 2634,
        "original_unique_export_vas": EXPECTED, "original_pt_load_bodies_rehashed": EXPECTED,
        "original_fully_decoded_aarch64_bodies": EXPECTED,
        "original_aarch64_instructions": source_instruction_count,
        "historical_ghidra_memory_bodies_rehashed": EXPECTED,
        "consolidated_c_like_bodies": c_like,
        "historical_task151_c_like_bodies": c_like - 1 if full else None,
        "historical_task152_corrected_va": "0x1741e4",
        "historical_task152_decompile_timeout_seconds": 180,
        "current_task_ghidra_decompile_timeout_seconds": 15,
        "current_task_fresh_imports": 0,
        "current_task_fresh_ghidra_processes": 1,
        "historical_chunk_receipts": old_receipts,
        "current_task_ghidra_spread_samples": len(ordinary),
        "current_task_spread_c_outputs_compared": c_text_sample_compared,
        "current_task_spread_c_text_equal": c_text_sample_equal,
        "historical_listed_source_aligned_instructions": listed_instruction_count,
        "historical_partial_instruction_listings": partial_listings,
        "historical_c_bodies_with_warnings": warnings,
        "historical_source_aligned_flow_transfers": calls,
        "unresolved_count": len(unresolved), "disposition": disposition,
        "ordinary_spread_provenance": ordinary,
        "internal_nonexported_functions_covered": False,
        "semantic_equivalence_proven": False, "runtime_pixel_behavior_proven": False}
    write_json(REPORT / "independent_verification.json", verification)
    report = f"""# TASK_165 R1 — MTFilterKernel original export map

Status: **{disposition}; independent CEO review pending**.

The original `{SOURCE.name}` SHA-256 `{SOURCE_SHA}` contains 2,634 defined nonzero-size `.dynsym` STT_FUNC names at **2,362 unique export VAs**. This revision independently re-enumerated every ELF/PT_LOAD range, rehashed all **2,362 original function bodies**, and checked all historical Ghidra memory hashes against those bodies. All **{c_like} / 2,362** have nonempty C-like text in the consolidated raw evidence; the per-VA path/hash/limitations are in `export_map.ndjson`.

The earlier TASK_151 Ghidra batch supplied 2,361 C-like bodies in ten read-only chunks. The one 15-second timeout at VA `0x1741e4` was recovered in historical TASK_152 using a **180-second per-function limit**, with 62.279 seconds of decompilation. TASK_165 did **not** re-execute that long decompilation. It verified both historical seals and scripts, copied 64 raw command/log/result files hash-identically, and ran one new read-only Ghidra process over **{len(ordinary)} evenly spread export VAs** (10.0%) using a 15-second per-function limit, 1 CPU, 1 GiB, and no new import. The fresh process rechecked original-source bytes and Ghidra memory at every sample; {c_text_sample_equal}/{c_text_sample_compared} comparable fresh C texts matched historical UTF-8 hashes exactly. Historical commands remain labeled as historical; current execution has its own receipt.

Capstone independently decoded all **{source_instruction_count:,} AArch64 instructions** across the original export bodies. The consolidated Ghidra listings cover **{listed_instruction_count:,}** source-aligned instructions, with **{partial_listings}** partial bodies, and the C-like texts contain **{warnings}** bodies with `WARNING:`. These outputs are a static export map, not a proof of exact source semantics. Non-exported functions, dynamic dispatch, linked providers, shaders/models, device behavior and pixel parity remain outside this evidence. No product Phase PASS, V4 or P7 gate is claimed. No AGY, production edits, self-review, commit or push occurred.
"""
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", report.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_165", "revision": 1,
        "generated_at": now(), "status": disposition, "lease_id": LEASE_ID,
        "fencing_token": FENCE, "c_like_export_bodies": c_like,
        "ordinary_spread_ghidra_samples": len(ordinary), "independent_ceo_review_pending": True})
    files = {path.relative_to(REPORT).as_posix(): sha256(path)
             for path in sorted(REPORT.rglob("*")) if path.is_file() and
             path != REPORT / "COMPLETE.json" and path.name != "PROGRESS.json"}
    total = sum((REPORT / rel).stat().st_size for rel in files)
    if total > MAX_REPORT_BYTES or not files:
        raise RuntimeError(f"report exceeds 128 MiB cap or empty: {total}")
    code_files = {path.relative_to(ROOT).as_posix(): sha256(path)
                  for path in sorted(SCRIPTS.iterdir()) if path.is_file() and
                  path.suffix in (".py", ".java")}
    check_lease()
    write_json(REPORT / "COMPLETE.json", {"schema_version": "2.1.2", "task_id": "TASK_165",
        "revision": 1, "status": "COMPLETE", "semantic_disposition": disposition,
        "generated_at": now(), "standard_sha256": STANDARD_SHA, "task_sha256": TASK_SHA,
        "source_sha256": SOURCE_SHA, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "execution_mode": "CODEX_SUBAGENT_NO_AGY", "review_state": "AWAITING_INDEPENDENT_CEO_REVIEW",
        "original_export_vas": EXPECTED, "source_bodies_rehashed": EXPECTED,
        "ghidra_memory_bodies_rehashed": EXPECTED, "c_like_bodies_recovered": c_like,
        "fresh_spread_ghidra_samples": len(ordinary), "unresolved_export_vas": [x["elf_va"] for x in unresolved],
        "fresh_imports": 0, "fresh_ghidra_processes": 1,
        "historical_long_timeout_exception_va": "0x1741e4",
        "report_bytes_excluding_seal_and_progress": total,
        "internal_nonexported_functions_covered": False,
        "semantic_equivalence_proven": False, "phase_pass": False,
        "files": files, "code_files": code_files})
    print(json.dumps({"disposition": disposition, "source_export_vas": EXPECTED,
        "c_like_bodies": c_like, "fresh_samples": len(ordinary),
        "partial_listings": partial_listings, "warnings": warnings,
        "report_files": len(files), "report_bytes": total}), flush=True)

if __name__ == "__main__":
    main()
