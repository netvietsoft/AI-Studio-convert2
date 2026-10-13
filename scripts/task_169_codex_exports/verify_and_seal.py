"""Independently verify LayerFlow source, historical reuse, current Ghidra output and seal."""

from __future__ import annotations

import hashlib
import json
import math
import re

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

from common import (EXPECTED_SYMBOLS, EXPECTED_VAS, FENCE, LEASE_ID, MAX_REPORT_BYTES,
                    PROJECT, REPORT, ROOT, SCRIPTS, SOURCE, SOURCE_SHA, STANDARD,
                    STANDARD_SHA, TASK_SHA, atomic_bytes, check_lease, now,
                    sha256, tree_hashes, write_json)
from prepare import HISTORICAL_ROOTS, PROJECT_DB_REL, mapped_bytes


def historical_rows(index: dict) -> tuple[dict[int, dict], dict[int, int]]:
    reuse = json.loads((REPORT / "historical_reuse.json").read_text(encoding="utf-8"))
    if (reuse["task_id"] != "TASK_169" or reuse["source_sha256"] != SOURCE_SHA or
            reuse["historical_reused_vas"] != 15 or len(reuse["rows"]) != 15):
        raise RuntimeError("historical reuse identity/count mismatch")
    by_task = {}
    for task, old_folder in HISTORICAL_ROOTS.items():
        folder = REPORT / "historical" / old_folder.name
        complete = json.loads((folder / "COMPLETE.json").read_text(encoding="utf-8"))
        if complete["task_id"] != task or complete["source_sha256"] != SOURCE_SHA:
            raise RuntimeError("copied historical package source mismatch")
        if sha256(folder / "COMPLETE.json") != sha256(old_folder / "COMPLETE.json"):
            raise RuntimeError("copied historical COMPLETE mismatch")
        for rel, digest in complete["files"].items():
            if sha256(folder / rel) != digest:
                raise RuntimeError(f"copied historical file mismatch: {task}/{rel}")
        receipt = json.loads((folder / "ghidra_command.json").read_text(encoding="utf-8"))
        raw_name = "layerflow_hair_ghidra_raw.json" if task == "TASK_146" else "applylayer_ghidra_raw.json"
        raw_path = folder / raw_name
        if (receipt["status"] != "OUTPUT_READY" or receipt["exit_code"] != 0 or
                receipt["result_sha256"] != sha256(raw_path) or
                receipt["stdout_sha256"] != sha256(folder / "ghidra_stdout.log") or
                receipt["stderr_sha256"] != sha256(folder / "ghidra_stderr.log")):
            raise RuntimeError(f"copied historical command/raw mismatch: {task}")
        raw = json.loads(raw_path.read_text(encoding="utf-8"))
        if raw["task_id"] != task or raw["program_name"] != SOURCE.name:
            raise RuntimeError(f"copied historical Ghidra program mismatch: {task}")
        by_task[task] = (raw, raw_name, sha256(raw_path))
    rows = {}
    bases = {}
    for item in reuse["rows"]:
        n, va, task = item["index"], int(item["elf_va"], 16), item["task_id"]
        if n < 1 or n > EXPECTED_VAS or index["targets"][n - 1]["elf_va"] != item["elf_va"]:
            raise RuntimeError("historical current index/VA mismatch")
        raw, raw_name, raw_sha = by_task[task]
        matches = [r for r in raw["targets"] if r["index"] == item["original_row_index"] and int(r["elf_va"], 16) == va]
        if (len(matches) != 1 or item["original_raw_sha256"] != raw_sha or
                item["raw_file"] != f"historical/{task}_REPORT_R1/{raw_name}" or
                item["source_body_sha256"] != index["targets"][n - 1]["source_body_sha256"]):
            raise RuntimeError("historical row provenance/body mismatch")
        row = dict(matches[0]); row["index"] = n
        if (row["source_bytes_match"] is not True or row["decompile_success"] is not True or
                not row["pseudocode"].strip() or row["error"] or
                row["ghidra_memory_sha256"] != item["source_body_sha256"]):
            raise RuntimeError("historical reused row not successful")
        if va == 0x3f94fc:
            if task != "TASK_147" or item["historical_decompile_timeout_seconds"] != 180:
                raise RuntimeError("historical applyLayer 180s exception not disclosed")
        elif task != "TASK_146" or item["historical_decompile_timeout_seconds"] != 15:
            raise RuntimeError("historical TASK_146 attribution mismatch")
        if n in rows:
            raise RuntimeError("duplicate historical row")
        rows[n] = row
        bases[n] = int(raw["image_base"], 16)
    if len(rows) != 15:
        raise RuntimeError("historical rows incomplete")
    return rows, bases


def current_rows(index: dict, batch: dict) -> tuple[dict[int, dict], dict[int, int], list[dict], int]:
    if (batch["task_id"] != "TASK_169" or len(batch["chunks"]) > len(index["chunks"]) or
            batch["project"]["status"] != "PROJECT_REUSED" or batch["project"]["fresh_imports"] != 0):
        raise RuntimeError("current batch identity/project mismatch")
    by_chunk = {x["chunk"]: x for x in batch["chunks"]}
    if len(by_chunk) != len(batch["chunks"]) or set(by_chunk) != set(range(len(by_chunk))):
        raise RuntimeError("current chunk outcome order/uniqueness mismatch")
    rows = {}
    bases = {}
    failed = []
    ready = 0
    for meta in index["chunks"]:
        number = meta["chunk"]
        folder = REPORT / f"chunk_{number:02d}"
        if (meta["count"] > 256 or meta["count"] != len(meta["indices"]) or
                meta["target_tsv_sha256"] != sha256(folder / "targets.tsv")):
            raise RuntimeError("new chunk split/hash changed")
        status = by_chunk.get(number, {}).get("status", "NOT_STARTED")
        if status != "OUTPUT_READY":
            failed.append({"chunk": number, "status": status})
            continue
        receipt = json.loads((folder / "ghidra_command.json").read_text(encoding="utf-8"))
        raw_path = folder / "ghidra_raw.json"
        if (receipt["task_id"] != "TASK_169" or receipt["chunk"] != number or
                receipt["source_sha256"] != SOURCE_SHA or
                receipt["status"] != "OUTPUT_READY" or receipt["exit_code"] != 0 or
                receipt["result_sha256"] != sha256(raw_path) or
                receipt["stdout_sha256"] != sha256(folder / "ghidra_stdout.log") or
                receipt["stderr_sha256"] != sha256(folder / "ghidra_stderr.log") or
                receipt["target_tsv_sha256"] != meta["target_tsv_sha256"] or
                receipt["script_sha256"] != sha256(SCRIPTS / "ExportLayerFlowChunk169.java") or
                receipt["command"][3:9] != ["-process", SOURCE.name, "-noanalysis", "-readOnly", "-max-cpu", "1"] or
                "-import" in receipt["command"] or receipt["fresh_import"] is not False):
            raise RuntimeError(f"new chunk {number} command/raw mismatch")
        stdout = (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        if (f"Processing read-only project file: /{SOURCE.name}" not in stdout or
                f"[TASK_169] processed {meta['count']}/{meta['count']}" not in stdout):
            raise RuntimeError(f"new chunk {number} Ghidra completion missing")
        raw = json.loads(raw_path.read_text(encoding="utf-8"))
        if (raw["task_id"] != "TASK_169" or raw["program_name"] != SOURCE.name or
                [x["index"] for x in raw["targets"]] != meta["indices"]):
            raise RuntimeError(f"new chunk {number} raw identity/index mismatch")
        image_base = int(raw["image_base"], 16)
        for row in raw["targets"]:
            n = row["index"]
            if n in rows:
                raise RuntimeError("duplicate new target across chunks")
            rows[n] = row; bases[n] = image_base
        ready += 1
    return rows, bases, failed, ready


def main() -> None:
    check_lease()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("TASK_169 already sealed")
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError("original source changed")
    index = json.loads((REPORT / "target_index.json").read_text(encoding="utf-8"))
    batch = json.loads((REPORT / "batch_run_receipt.json").read_text(encoding="utf-8"))
    project_receipt = json.loads((REPORT / "project_reuse_receipt.json").read_text(encoding="utf-8"))
    if (index["task_id"] != "TASK_169" or index["task_sha256"] != TASK_SHA or
            index["source_sha256"] != SOURCE_SHA or
            index["defined_nonzero_function_symbols"] != EXPECTED_SYMBOLS or
            index["unique_export_vas"] != EXPECTED_VAS or len(index["targets"]) != EXPECTED_VAS or
            index["historical_reused_vas"] != 15 or index["new_ghidra_target_vas"] != EXPECTED_VAS - 15 or
            len(index["chunks"]) != 20 or sum(x["count"] for x in index["chunks"]) != EXPECTED_VAS - 15 or
            project_receipt["source_sha256"] != SOURCE_SHA or
            project_receipt["execution_mode"] != "REUSED_ANALYZED_TASK_147_PROJECT_NO_FRESH_IMPORT"):
        raise RuntimeError("target index/project identity or census mismatch")
    db_sha = sha256(PROJECT / PROJECT_DB_REL)
    if db_sha != project_receipt["copied_project_db_sha256"]:
        raise RuntimeError("reused Ghidra project DB changed")
    historical, hist_bases = historical_rows(index)
    current, current_bases, failed_chunks, ready = current_rows(index, batch)
    if set(historical) & set(current):
        raise RuntimeError("repeated historical VA in new passes")
    all_rows = {**historical, **current}
    row_bases = {**hist_bases, **current_bases}
    if len(set(row_bases.values())) > 1:
        raise RuntimeError("Ghidra image base changed across historical/current passes")
    if sorted(x["index"] for x in index["targets"]) != list(range(1, EXPECTED_VAS + 1)):
        raise RuntimeError("source target index/order changed")
    with SOURCE.open("rb") as f:
        elf = ELFFile(f)
        dynsym = elf.get_section_by_name(".dynsym")
        by_va: dict[int, list[tuple[str, int]]] = {}
        for symbol in dynsym.iter_symbols():
            if (symbol["st_info"]["type"] != "STT_FUNC" or symbol["st_shndx"] == "SHN_UNDEF" or
                    int(symbol["st_size"]) <= 0 or int(symbol["st_value"]) <= 0):
                continue
            by_va.setdefault(int(symbol["st_value"]), []).append((symbol.name, int(symbol["st_size"])))
        if len(by_va) != EXPECTED_VAS or sum(map(len, by_va.values())) != EXPECTED_SYMBOLS:
            raise RuntimeError("independent original .dynsym census changed")
        if [int(x["elf_va"], 16) for x in index["targets"]] != sorted(by_va):
            raise RuntimeError("target VA set/order not source-derived")
        cap = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
        records = []
        c_failed = []
        source_instructions = ghidra_instructions = source_full = ghidra_full = c_recovered = warnings = 0
        listing_mismatches = []
        transfers = {"bl": 0, "blr": 0, "b": 0, "br": 0}
        for target in index["targets"]:
            n = target["index"]; va = int(target["elf_va"], 16)
            aliases = sorted(by_va[va], key=lambda x: (-x[1], x[0]))
            if (target["symbol"], target["size_bytes"]) != aliases[0] or target["aliases"] != [x for x, _ in aliases]:
                raise RuntimeError(f"original symbol/alias mismatch at {n}")
            body, offset = mapped_bytes(elf, va, target["size_bytes"])
            digest = hashlib.sha256(body).hexdigest()
            if target["file_offset"] != f"0x{offset:x}" or target["source_body_sha256"] != digest:
                raise RuntimeError(f"original PT_LOAD/body hash mismatch at {n}")
            decoded = list(cap.disasm(body, va))
            by_addr = {ins.address: ins for ins in decoded}
            full = sum(ins.size for ins in decoded) == len(body)
            source_full += full; source_instructions += len(decoded)
            row = all_rows.get(n)
            c_good = False; listed_count = flow_count = c_chars = 0; c_warning = False
            if row is not None:
                image_base = row_bases[n]
                if (row["symbol"] != target["symbol"] or row["elf_va"] != target["elf_va"] or
                        row["size_bytes"] != target["size_bytes"] or
                        row["database_va"] != f"0x{va + image_base:x}" or
                        row["expected_source_sha256"] != digest or
                        row["ghidra_memory_sha256"] != digest or row["source_bytes_match"] is not True):
                    raise RuntimeError(f"Ghidra/original body mismatch at {n}")
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
                        listing_mismatches.append({"index": n, "elf_va": target["elf_va"], "address": f"0x{address:x}"})
                    addresses.append(address)
                if addresses != sorted(set(addresses)):
                    raise RuntimeError(f"Ghidra instruction order/duplicate at {n}")
                listed_count = len(listed); ghidra_instructions += listed_count
                ghidra_full += bool(full and listed_count == len(decoded) and all(a in by_addr for a in addresses))
                for call in row["calls"]:
                    m = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
                    if not m:
                        raise RuntimeError(f"Ghidra transfer parse failed at {n}")
                    address = int(m.group(1), 16) - image_base
                    if address in by_addr and by_addr[address].mnemonic in transfers:
                        transfers[by_addr[address].mnemonic] += 1
                    else:
                        listing_mismatches.append({"index": n, "elf_va": target["elf_va"],
                                                   "flow_address": f"0x{address:x}"})
                flow_count = len(row["calls"])
                c_chars = len(row["pseudocode"]); c_warning = "WARNING:" in row["pseudocode"]
                c_good = bool(row["decompile_success"] is True and row["pseudocode"].strip() and not row["error"])
                if c_good: c_recovered += 1
                else: c_failed.append({"index": n, "elf_va": target["elf_va"], "symbol": target["symbol"], "error": row["error"]})
                warnings += c_warning
            else:
                c_failed.append({"index": n, "elf_va": target["elf_va"], "symbol": target["symbol"], "error": "chunk not recovered"})
            records.append({"index": n, "elf_va": target["elf_va"], "symbol": target["symbol"],
                "size_bytes": len(body), "source_body_sha256": digest,
                "provenance": "HISTORICAL_TASK_147" if n in historical and va == 0x3f94fc else
                              "HISTORICAL_TASK_146" if n in historical else "TASK_169_NEW",
                "source_capstone_instructions": len(decoded), "source_fully_decoded": full,
                "ghidra_listed_instructions": listed_count, "ghidra_flow_transfers_source_verified": flow_count,
                "ghidra_c_like_recovered": c_good, "ghidra_c_like_characters": c_chars,
                "ghidra_c_warning_present": c_warning})
    sample_count = math.ceil(EXPECTED_VAS / 10)
    sample_indices = sorted({round(i * (EXPECTED_VAS - 1) / (sample_count - 1)) for i in range(sample_count)})
    if len(sample_indices) < sample_count:
        raise RuntimeError("ordinary sample below 10%")
    with SOURCE.open("rb") as f:
        elf = ELFFile(f)
        for i in sample_indices:
            target = index["targets"][i]
            va = int(target["elf_va"], 16)
            body, _ = mapped_bytes(elf, va, target["size_bytes"])
            digest = hashlib.sha256(body).hexdigest()
            if digest != records[i]["source_body_sha256"] or digest != target["source_body_sha256"]:
                raise RuntimeError(f"ordinary second source comparison failed at {i + 1}")
            row = all_rows.get(i + 1)
            if row is not None and row["ghidra_memory_sha256"] != digest:
                raise RuntimeError(f"ordinary Ghidra memory comparison failed at {i + 1}")
    verified = {"task_id": "TASK_169", "revision": 1, "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE, "source_sha256": SOURCE_SHA,
        "export_symbols_recounted": EXPECTED_SYMBOLS, "unique_export_vas_recounted": EXPECTED_VAS,
        "historical_rows_reused": len(historical), "new_ghidra_rows_rehashed": len(current),
        "ghidra_memory_bodies_rehashed_total": len(all_rows),
        "chunks_output_ready": ready, "chunks_total": len(index["chunks"]), "chunks_failed": failed_chunks,
        "source_bodies_rehashed": EXPECTED_VAS, "ghidra_c_like_bodies_recovered": c_recovered,
        "unrecovered_c_like_bodies": c_failed, "source_fully_capstone_decoded_bodies": source_full,
        "source_capstone_instructions": source_instructions,
        "ghidra_fully_listed_bodies": ghidra_full,
        "ghidra_listed_instructions": ghidra_instructions,
        "ghidra_flow_transfer_source_opcode_counts": transfers,
        "ghidra_listing_alignment_mismatches": listing_mismatches,
        "c_bodies_with_warnings": warnings,
        "ordinary_records_spread_sampled": len(sample_indices),
        "ordinary_records_total": EXPECTED_VAS,
        "historical_applylayer_180s_exception": True,
        "current_exporter_decompile_timeout_seconds": 15,
        "fresh_imports": 0, "internal_nonexported_functions_covered": False,
        "runtime_or_pixel_semantics_proven": False, "records": records}
    write_json(REPORT / "worker_source_verification.json", verified)
    project_files = tree_hashes(PROJECT)
    write_json(REPORT / "project_inventory.json", {
        "task_id": "TASK_169", "revision": 1, "generated_at": now(),
        "project_root": str(PROJECT), "files": project_files,
        "database_hash_unchanged_from_TASK_147": db_sha == project_receipt["copied_project_db_sha256"]})
    audit = (f"# TASK_169 R1 audit index\n\nCanonical standard fully read at {now()}: {STANDARD} SHA-256 {STANDARD_SHA}.\n\n"
             f"Task SHA-256 {TASK_SHA}; lease {LEASE_ID}, fence {FENCE}. Original {SOURCE} SHA-256 {SOURCE_SHA}.\n\n"
             f"All {EXPECTED_VAS} original PT_LOAD body hashes checked. {len(historical)} prior successful bodies"
             " copied with TASK_146/147 raw receipts and exact project database; no new import. "
             "TASK_147 applyLayer used a historical isolated 180s decompile timeout, separately attributed. "
             "Current Ghidra script caps each new function at 15s. Real Codex subagent, no AGY.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    complete = (c_recovered == EXPECTED_VAS and ready == len(index["chunks"]) and not listing_mismatches)
    disposition = "BOUNDED_RESEARCH_CANDIDATE" if complete else "PARTIAL_RESEARCH_CANDIDATE"
    master = f"""# TASK_169 R1 - libLayerFlow.so export map

Status: {disposition}; awaiting independent CEO review. This is static export research, not full internal-function recovery, semantic equivalence, device proof or product Phase PASS/V4/P7 authorization.

## Observed

- Original libLayerFlow.so SHA-256 {SOURCE_SHA}: {EXPECTED_SYMBOLS:,} defined nonzero-size .dynsym names, {EXPECTED_VAS:,} unique export VAs; {EXPECTED_VAS:,} source PT_LOAD body hashes rechecked.
- Reused {len(historical)} byte-verified historical successful C-like outputs from TASK_146 (14) and TASK_147 (1); {len(current):,} new Ghidra memory bodies from {ready}/{len(index['chunks'])} sequential read-only chunks. The analyzed TASK_147 project database was copied and rehashed. No new import occurred.
- {c_recovered:,}/{EXPECTED_VAS:,} nonempty C-like bodies; {len(c_failed):,} still missing or failed. {warnings:,} C bodies have decompiler warnings. Capstone decoded {source_instructions:,} source instructions; Ghidra listed {ghidra_instructions:,} instruction addresses, with {ghidra_full:,}/{EXPECTED_VAS:,} full symbol-body listings and {len(listing_mismatches):,} listing/flow alignment discrepancies.
- Source-verified Ghidra transfers: {transfers['bl']} bl, {transfers['blr']} blr, {transfers['b']} tail b, {transfers['br']} br. {len(sample_indices)} spread ordinary records ({len(sample_indices)/EXPECTED_VAS:.1%}) were rechecked against source bytes again.

## Provenance and limits

- Historical TASK_147 applyLayer at VA 0x3f94fc used an isolated 180s decompile timeout. It is copied as historical evidence; current TASK_169 processes cap decompilation at 15s per new function. Original TASK_146 import elapsed 786.897s; this revision reused its analyzed project and did not repeat that import.
- C-like text and aligned assembly are static evidence. Warnings, partial listings, non-exported functions, linked providers, indirect dispatch, model/material data and physical device behavior remain open in worker_source_verification.json.
- TASK_063 remains BLOCKED and TASK_064A-G/065/066 remain PLANNED. No self-review, commit/push or product gate change.
"""
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", master.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_169", "revision": 1,
        "status": "REPORT_READY" if complete else "PARTIAL_REPORT_READY", "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE, "source_bodies_rehashed": EXPECTED_VAS,
        "historical_reused_vas": len(historical), "new_ghidra_rows": len(current),
        "c_like_bodies_recovered": c_recovered, "independent_review_pending": True, "phase_pass": False})
    files = {p.relative_to(REPORT).as_posix(): sha256(p) for p in sorted(REPORT.rglob("*"))
             if p.is_file() and p.relative_to(REPORT).as_posix() not in ("COMPLETE.json", "PROGRESS.json")}
    report_bytes = sum((REPORT / name).stat().st_size for name in files)
    if not files or report_bytes > MAX_REPORT_BYTES:
        raise RuntimeError("report extent/cap invalid")
    code = {p.relative_to(ROOT).as_posix(): sha256(p)
            for p in sorted(SCRIPTS.iterdir()) if p.is_file() and p.suffix in (".py", ".java")}
    check_lease()
    write_json(REPORT / "COMPLETE.json", {
        "schema_version": "2.1.2", "task_id": "TASK_169", "revision": 1,
        "status": "COMPLETE", "semantic_disposition": disposition,
        "generated_at": now(), "standard_sha256": STANDARD_SHA, "task_sha256": TASK_SHA,
        "source_sha256": SOURCE_SHA, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "execution_mode": "REAL_CODEX_SUBAGENT_REUSED_ANALYZED_PROJECT_NO_AGY",
        "review_state": "AWAITING_INDEPENDENT_REVIEW", "source_bodies_rehashed": EXPECTED_VAS,
        "historical_reused_vas": len(historical), "new_ghidra_rows_rehashed": len(current),
        "ghidra_memory_bodies_rehashed_total": len(all_rows),
        "c_like_bodies_recovered": c_recovered, "unrecovered_c_like_vas": [x["elf_va"] for x in c_failed],
        "c_bodies_with_warnings": warnings, "ghidra_fully_listed_bodies": ghidra_full,
        "ghidra_listing_alignment_mismatches": len(listing_mismatches),
        "ordinary_records_independently_rechecked": len(sample_indices),
        "ordinary_records_total": EXPECTED_VAS,
        "historical_applylayer_180s_exception": True,
        "current_exporter_decompile_timeout_seconds": 15,
        "fresh_imports": 0, "internal_nonexported_functions_covered": False,
        "runtime_or_pixel_semantics_proven": False,
        "files": files, "code_files": code})
    print(json.dumps({"disposition": disposition, "source_vas": EXPECTED_VAS,
                      "historical_rows": len(historical), "new_rows": len(current),
                      "C_like_bodies": c_recovered, "warnings": warnings,
                      "fully_listed_bodies": ghidra_full, "alignment_mismatches": len(listing_mismatches),
                      "ordinary_samples": len(sample_indices), "report_files": len(files),
                      "report_bytes": report_bytes}))


if __name__ == "__main__":
    main()
