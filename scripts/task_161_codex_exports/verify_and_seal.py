"""Recheck all body/source/Ghidra claims for one pinned TASK_161 library."""

from __future__ import annotations

import hashlib
import json
import math
import re

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

from common import (BASE_REPORT, EXPECTED_VAS, FENCE, LEASE_ID, MAX_REPORT_BYTES, PROJECT, PROJECT_NAME,
                    REPORT, ROOT, SCRIPTS, SOURCE, SOURCE_SHA, STANDARD,
                    STANDARD_SHA, TASK_SHA, atomic_bytes, check_lease, now,
                    sha256, tree_hashes, write_json)
from prepare import mapped_bytes


def main() -> None:
    check_lease()
    if (REPORT / "SOURCE_COMPLETE.json").exists():
        raise RuntimeError("TASK_161 source already sealed")
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError("source changed")
    index = json.loads((REPORT / "target_index.json").read_text(encoding="utf-8"))
    batch = json.loads((REPORT / "batch_run_receipt.json").read_text(encoding="utf-8"))
    import_receipt = json.loads((REPORT / "ghidra_import_command.json").read_text(encoding="utf-8"))
    if (index["source_sha256"] != SOURCE_SHA or
            index["defined_nonzero_function_symbols"] < EXPECTED_VAS or
            index["unique_export_vas"] != EXPECTED_VAS or len(index["targets"]) != EXPECTED_VAS or
            len(index["chunks"]) != math.ceil(EXPECTED_VAS / 256) or batch["task_id"] != "TASK_161" or
            len(batch["chunks"]) > 5 or
            import_receipt["task_id"] != "TASK_161" or
            import_receipt["source_sha256"] != SOURCE_SHA or
            import_receipt["stdout_sha256"] != sha256(REPORT / "ghidra_import_stdout.log") or
            import_receipt["stderr_sha256"] != sha256(REPORT / "ghidra_import_stderr.log") or
            import_receipt["command"][3:5] != ["-import", str(SOURCE)]):
        raise RuntimeError("source/index/batch/project identity changed")
    gpr = PROJECT / (PROJECT_NAME + ".gpr")
    if import_receipt["status"] == "PROJECT_READY":
        if (not gpr.is_file() or import_receipt["exit_code"] != 0 or
                import_receipt["project_gpr_sha256"] != sha256(gpr)):
            raise RuntimeError("Ghidra import project receipt mismatch")
    by_chunk = {x["chunk"]: x for x in batch["chunks"]}
    if set(by_chunk) != set(range(len(by_chunk))):
        raise RuntimeError("nonsequential/duplicate chunk outcome")
    raw_rows: dict[int, dict] = {}
    row_bases: dict[int, int] = {}
    imported = 0
    failed_chunks = []
    for meta in index["chunks"]:
        number = meta["chunk"]
        folder = REPORT / f"chunk_{number:02d}"
        if (meta["target_tsv_sha256"] != sha256(folder / "targets.tsv") or
                meta["count"] > 256 or meta["first_index"] < 1 or
                meta["last_index"] > EXPECTED_VAS):
            raise RuntimeError(f"chunk {number} target split changed")
        status = by_chunk.get(number, {}).get("status", "NOT_STARTED")
        receipt_path = folder / "ghidra_command.json"
        if status != "OUTPUT_READY":
            failed_chunks.append({"chunk": number, "status": status})
            continue
        receipt = json.loads(receipt_path.read_text(encoding="utf-8"))
        raw_path = folder / "ghidra_raw.json"
        if (receipt["task_id"] != "TASK_161" or receipt["chunk"] != number or
                receipt["source_sha256"] != SOURCE_SHA or
                receipt["status"] != "OUTPUT_READY" or receipt["exit_code"] != 0 or
                receipt["result_sha256"] != sha256(raw_path) or
                receipt["stdout_sha256"] != sha256(folder / "ghidra_stdout.log") or
                receipt["stderr_sha256"] != sha256(folder / "ghidra_stderr.log") or
                receipt["target_tsv_sha256"] != meta["target_tsv_sha256"] or
                receipt["script_sha256"] != sha256(SCRIPTS / "ExportTask161Chunk.java") or
                receipt["command"][3:9] != ["-process", SOURCE.name, "-noanalysis", "-readOnly", "-max-cpu", "1"] or
                "-import" in receipt["command"]):
            raise RuntimeError(f"chunk {number} raw command/hash mismatch")
        stdout = (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        if (f"Processing read-only project file: /{SOURCE.name}" not in stdout or
                f"[TASK_161] processed {meta['count']}/{meta['count']}" not in stdout):
            raise RuntimeError(f"chunk {number} Ghidra completion log missing")
        raw = json.loads(raw_path.read_text(encoding="utf-8"))
        if (raw["task_id"] != "TASK_161" or raw["program_name"] != SOURCE.name or
                len(raw["targets"]) != meta["count"]):
            raise RuntimeError(f"chunk {number} raw identity/count mismatch")
        expected_indices = list(range(meta["first_index"], meta["last_index"] + 1))
        got_indices = [x["index"] for x in raw["targets"]]
        if got_indices != expected_indices:
            raise RuntimeError(f"chunk {number} row order/index mismatch")
        image_base = int(raw["image_base"], 16)
        for row in raw["targets"]:
            if row["index"] in raw_rows:
                raise RuntimeError("duplicate target across Ghidra chunks")
            raw_rows[row["index"]] = row
            row_bases[row["index"]] = image_base
        imported += 1
    if len(set(row_bases.values())) > 1:
        raise RuntimeError("Ghidra image base changed across chunks")
    if sorted(x["index"] for x in index["targets"]) != list(range(1, EXPECTED_VAS + 1)):
        raise RuntimeError("source target ordering changed")
    with SOURCE.open("rb") as f:
        elf = ELFFile(f)
        dynsym = elf.get_section_by_name(".dynsym")
        by_va: dict[int, list[tuple[str, int]]] = {}
        for symbol in dynsym.iter_symbols():
            if (symbol["st_info"]["type"] != "STT_FUNC" or
                    symbol["st_shndx"] == "SHN_UNDEF" or
                    int(symbol["st_size"]) <= 0 or int(symbol["st_value"]) <= 0):
                continue
            by_va.setdefault(int(symbol["st_value"]), []).append(
                (symbol.name, int(symbol["st_size"])))
        if sum(map(len, by_va.values())) != index["defined_nonzero_function_symbols"] or len(by_va) != EXPECTED_VAS:
            raise RuntimeError("independent .dynsym census changed")
        cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
        records = []
        source_instructions = 0
        ghidra_instructions = 0
        source_full = 0
        ghidra_full = 0
        c_recovered = 0
        c_failed = []
        warnings = 0
        transfers = {"bl": 0, "blr": 0, "b": 0, "br": 0}
        for target in index["targets"]:
            n = target["index"]
            va = int(target["elf_va"], 16)
            aliases = sorted(by_va[va], key=lambda x: (-x[1], x[0]))
            if (target["symbol"], target["size_bytes"]) != aliases[0] or target["aliases"] != [x for x, _ in aliases]:
                raise RuntimeError(f"target symbol/alias mismatch at {n}")
            body, offset = mapped_bytes(elf, va, target["size_bytes"])
            digest = hashlib.sha256(body).hexdigest()
            if target["file_offset"] != f"0x{offset:x}" or target["source_body_sha256"] != digest:
                raise RuntimeError(f"source PT_LOAD/body hash mismatch at {n}")
            decoded = list(cap.disasm(body, va))
            by_addr = {i.address: i for i in decoded}
            full = sum(i.size for i in decoded) == len(body)
            source_full += full
            source_instructions += len(decoded)
            row = raw_rows.get(n)
            c_good = False
            listed_count = 0
            flow_count = 0
            c_chars = 0
            c_warning = False
            if row is not None:
                image_base = row_bases[n]
                if (row["symbol"] != target["symbol"] or row["elf_va"] != target["elf_va"] or
                        row["size_bytes"] != target["size_bytes"] or
                        row["database_va"] != f"0x{va + image_base:x}" or
                        row["expected_source_sha256"] != digest or
                        row["ghidra_memory_sha256"] != digest or
                        row["source_bytes_match"] is not True):
                    raise RuntimeError(f"Ghidra/source body mismatch at {n}")
                listed = row["instructions"]
                if len(listed) != row["instruction_count_observed"]:
                    raise RuntimeError(f"Ghidra instruction count mismatch at {n}")
                addresses = []
                for line in listed:
                    m = re.match(r"^([0-9a-fA-F]+):\s+", line)
                    if not m:
                        raise RuntimeError(f"Ghidra listing parse failed at {n}")
                    address = int(m.group(1), 16) - image_base
                    if address not in by_addr:
                        raise RuntimeError(f"Ghidra address not aligned to original source at {n}")
                    addresses.append(address)
                if addresses != sorted(set(addresses)):
                    raise RuntimeError(f"Ghidra listing order/duplicate at {n}")
                listed_count = len(listed)
                ghidra_instructions += listed_count
                ghidra_full += bool(full and listed_count == len(decoded))
                for call in row["calls"]:
                    m = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
                    if not m:
                        raise RuntimeError(f"Ghidra transfer parse failed at {n}")
                    address = int(m.group(1), 16) - image_base
                    if address not in by_addr or by_addr[address].mnemonic not in transfers:
                        raise RuntimeError(f"Ghidra flow edge not source transfer at {n}")
                    transfers[by_addr[address].mnemonic] += 1
                flow_count = len(row["calls"])
                c_chars = len(row["pseudocode"])
                c_warning = "WARNING:" in row["pseudocode"]
                c_good = bool(row["decompile_success"] is True and row["pseudocode"].strip() and not row["error"])
                if c_good:
                    c_recovered += 1
                else:
                    c_failed.append({"index": n, "elf_va": target["elf_va"],
                                     "symbol": target["symbol"], "error": row["error"]})
                warnings += c_warning
            else:
                c_failed.append({"index": n, "elf_va": target["elf_va"],
                                 "symbol": target["symbol"], "error": "chunk not recovered"})
            records.append({"index": n, "elf_va": target["elf_va"],
                "symbol": target["symbol"], "size_bytes": len(body),
                "source_body_sha256": digest,
                "source_capstone_instructions": len(decoded),
                "source_fully_decoded": full,
                "ghidra_listed_instructions": listed_count,
                "ghidra_flow_transfers_source_verified": flow_count,
                "ghidra_c_like_recovered": c_good,
                "ghidra_c_like_characters": c_chars,
                "ghidra_c_warning_present": c_warning})
    sample_count = math.ceil(EXPECTED_VAS * 0.1)
    sample_indices = sorted({round(i * (EXPECTED_VAS - 1) / (sample_count - 1)) for i in range(sample_count)})
    if len(sample_indices) < sample_count:
        raise RuntimeError("ordinary sample below 10%")
    for i in sample_indices:
        if records[i]["source_body_sha256"] != index["targets"][i]["source_body_sha256"]:
            raise RuntimeError(f"ordinary source sample differs at {i}")
    verified = {"task_id": "TASK_161", "revision": 1, "source_name": SOURCE.name,
        "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
        "source_sha256": SOURCE_SHA, "export_symbols_recounted": sum(map(len, by_va.values())),
        "unique_export_vas_recounted": EXPECTED_VAS,
        "chunks_output_ready": imported, "chunks_failed": failed_chunks,
        "source_bodies_rehashed": EXPECTED_VAS,
        "ghidra_memory_bodies_rehashed": len(raw_rows),
        "ghidra_c_like_bodies_recovered": c_recovered,
        "unrecovered_c_like_bodies": c_failed,
        "source_fully_capstone_decoded_bodies": source_full,
        "source_capstone_instructions": source_instructions,
        "ghidra_fully_listed_bodies": ghidra_full,
        "ghidra_listed_source_aligned_instructions": ghidra_instructions,
        "ghidra_flow_transfer_source_opcode_counts": transfers,
        "c_bodies_with_warnings": warnings,
        "ordinary_records_spread_sampled": len(sample_indices),
        "ordinary_records_total": EXPECTED_VAS,
        "internal_nonexported_functions_covered": False,
        "runtime_or_pixel_semantics_proven": False,
        "records": records}
    write_json(REPORT / "worker_source_verification.json", verified)
    project_files = tree_hashes(PROJECT) if PROJECT.is_dir() else {}
    write_json(REPORT / "project_inventory.json", {
        "task_id": "TASK_161", "revision": 1, "generated_at": now(),
        "project_root": str(PROJECT), "files": project_files})
    audit = (f"# TASK_161 R1 {SOURCE.name} audit index\n\n"
             f"Canonical standard read at `{now()}`: `{STANDARD}` SHA-256 `{STANDARD_SHA}`.\n\n"
             f"Task SHA-256 `{TASK_SHA}`; lease `{LEASE_ID}`, fence `{FENCE}`.\n\n"
             f"Original source `{SOURCE}` SHA-256 `{SOURCE_SHA}`. "
             f"All {EXPECTED_VAS:,} PT_LOAD body hashes and the fresh import receipt were verified; "
             "per-chunk raw commands, logs and C/disassembly are in this package. "
             "Real Codex subagent; no AGY.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    complete = c_recovered == EXPECTED_VAS and imported == len(index["chunks"])
    disposition = "BOUNDED_RESEARCH_CANDIDATE" if complete else "PARTIAL_RESEARCH_CANDIDATE"
    master = f"""# TASK_161 R1 - {SOURCE.name} exported-function recovery

Status: **{disposition} awaiting independent CEO review**. Tony assigned a real Codex subagent; no AGY. This pass is export-complete only if every selected C-like body was recovered; it does not include all static/internal code or prove product Phase PASS/V4/P7.

## Observed

- Original `{SOURCE.name}` SHA-256 `{SOURCE_SHA}` has {sum(map(len, by_va.values())):,} defined nonzero-size `.dynsym` names at {EXPECTED_VAS:,} unique VAs. All {EXPECTED_VAS:,} original PT_LOAD body hashes were rechecked. One fresh Ghidra project was imported in this source's TASK_161 scratch.
- {imported}/{len(index['chunks'])} sequential 1-CPU/1-GiB read-only Ghidra chunks produced parseable output; {c_recovered}/{EXPECTED_VAS:,} nonempty C-like bodies were recovered. {len(c_failed)} selected VAs remain without recovered C. Raw commands/logs and each body are in chunk folders.
- Capstone decoded {source_instructions:,} original AArch64 instructions; {source_full}/{EXPECTED_VAS:,} symbol bodies decoded through full size. Ghidra listed {ghidra_instructions:,} source-aligned instruction addresses and fully listed {ghidra_full}/{EXPECTED_VAS:,} bodies. Source-verified Ghidra flow transfers: {transfers['bl']} `bl`, {transfers['blr']} `blr`, {transfers['b']} tail `b`, {transfers['br']} `br`. Ghidra C text emitted warnings in {warnings} bodies. {len(sample_indices)} spread-out ordinary records ({len(sample_indices)/EXPECTED_VAS:.1%}) received a second source hash comparison.

## Inferred

- The C-like bodies are a static research map for this source. Export names or decompiler output alone cannot establish behavior, parameter range, or device output.

## Unknown / blocked input

- Non-exported code, imported providers, model data, indirect dispatch and physical-device execution require separate work. Any failed C bodies and partial Ghidra instruction listings remain explicit in `worker_source_verification.json`.
- TASK_063 remains BLOCKED and TASK_064A-G/065/066 remain PLANNED. No CEO self-ack ACCEPTED or unreviewed commit/push.
"""
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", master.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_161", "revision": 1, "source_name": SOURCE.name,
        "status": "BOUNDED_RESEARCH_REPORT_READY" if complete else "PARTIAL_RESEARCH_REPORT_READY",
        "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
        "source_bodies_rehashed": EXPECTED_VAS, "c_like_bodies_recovered": c_recovered,
        "independent_review_pending": True, "phase_pass": False})
    files = {p.relative_to(REPORT).as_posix(): sha256(p) for p in sorted(REPORT.rglob("*"))
             if p.is_file() and p.relative_to(REPORT).as_posix() not in ("SOURCE_COMPLETE.json", "PROGRESS.json")}
    total = sum((REPORT / name).stat().st_size for name in files)
    if not files or total > MAX_REPORT_BYTES:
        raise RuntimeError("report extent/cap invalid")
    code = {p.relative_to(ROOT).as_posix(): sha256(p)
            for p in sorted(SCRIPTS.iterdir()) if p.is_file() and p.suffix in (".py", ".java")}
    check_lease()
    write_json(REPORT / "SOURCE_COMPLETE.json", {
        "schema_version": "2.1.2", "task_id": "TASK_161", "revision": 1,
        "source_name": SOURCE.name,
        "status": "SOURCE_COMPLETE", "semantic_disposition": disposition,
        "generated_at": now(), "standard_sha256": STANDARD_SHA,
        "task_sha256": TASK_SHA, "source_sha256": SOURCE_SHA,
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "execution_mode": "REAL_CODEX_SUBAGENT_NO_AGY",
        "review_state": "AWAITING_INDEPENDENT_REVIEW",
        "critical_provenance_rechecked": True,
        "ordinary_records_independently_rechecked": len(sample_indices),
        "ordinary_records_total": EXPECTED_VAS,
        "source_bodies_rehashed": EXPECTED_VAS,
        "c_like_bodies_recovered": c_recovered,
        "unrecovered_c_like_vas": [x["elf_va"] for x in c_failed],
        "internal_nonexported_functions_covered": False,
        "runtime_or_pixel_semantics_proven": False,
        "files": files, "code_files": code})
    print(json.dumps({"status": disposition, "source_vas": EXPECTED_VAS,
                      "chunks_ready": imported, "c_like_bodies_recovered": c_recovered,
                      "unrecovered_count": len(c_failed),
                      "report_bytes": total, "report_files": len(files)}))


if __name__ == "__main__":
    main()
