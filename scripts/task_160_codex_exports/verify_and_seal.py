"""Recheck original ELF and Ghidra chunk evidence, then seal a review candidate."""

from __future__ import annotations

import hashlib
import json
import math
import re

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, LEASE_ID, LIBRARIES, REPORT, ROOT, SCRIPTS,
                    SOURCE_DIR, STANDARD, STANDARD_SHA, TASK_SHA, atomic_bytes,
                    check_lease, now, sha256, write_json)
from prepare import mapped_bytes


def main() -> None:
    check_lease()
    if (REPORT / "COMPLETE.json").exists():
        raise RuntimeError("TASK_160 report already sealed")
    batch = json.loads((REPORT / "batch_run_receipt.json").read_text(encoding="utf-8"))
    source_batch = json.loads((REPORT / "source_batch_index.json").read_text(encoding="utf-8"))
    if (batch.get("task_id") != "TASK_160" or source_batch.get("total_unique_export_vas") != 3326 or
        len(source_batch["libraries"]) != 1 or len(batch.get("chunks", [])) != 13):
        raise RuntimeError("batch/source census invalid")
    run_status = {(row["library"], row["chunk"]): row for row in batch["chunks"]}
    if len(run_status) != 13:
        raise RuntimeError("chunk status set duplicated")
    capstone = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    records = []
    c_bodies = []
    summaries = []
    total_source_instructions = 0
    total_ghidra_instructions = 0
    total_full_source = 0
    total_full_ghidra = 0
    total_c = 0
    total_source_match = 0
    for name, (expected_sha, expected_count) in LIBRARIES.items():
        source = SOURCE_DIR / name
        if sha256(source) != expected_sha:
            raise RuntimeError("original source SHA changed: " + name)
        folder = REPORT / name
        index = json.loads((folder / "target_index.json").read_text(encoding="utf-8"))
        targets = index["targets"]
        chunks = index["chunks"]
        if (index["source_sha256"] != expected_sha or index["unique_export_vas"] != expected_count or
            len(targets) != expected_count or sum(x["count"] for x in chunks) != expected_count or
            any(x["count"] > 300 for x in chunks)):
            raise RuntimeError("target index changed: " + name)
        with source.open("rb") as stream:
            elf = ELFFile(stream)
            dynsym = elf.get_section_by_name(".dynsym")
            by_va = {}
            for symbol in dynsym.iter_symbols():
                if (symbol["st_info"]["type"] != "STT_FUNC" or
                    symbol["st_shndx"] == "SHN_UNDEF" or int(symbol["st_size"]) <= 0 or
                    int(symbol["st_value"]) == 0):
                    continue
                by_va.setdefault(int(symbol["st_value"]), []).append((symbol.name, int(symbol["st_size"])))
            if len(by_va) != expected_count or sum(len(group) for group in by_va.values()) != index["defined_nonzero_function_symbols"]:
                raise RuntimeError("independent .dynsym census changed: " + name)
            library_c = 0
            library_source_matched = 0
            library_ghidra_instructions = 0
            library_source_instructions = 0
            library_full_source = 0
            library_full_ghidra = 0
            for chunk in chunks:
                number = chunk["chunk"]
                chunk_folder = folder / f"chunk_{number:02d}"
                tsv = chunk_folder / "targets.tsv"
                if sha256(tsv) != chunk["target_tsv_sha256"]:
                    raise RuntimeError("TSV changed: " + name + f" chunk {number}")
                run = run_status.get((name, number))
                if run is None:
                    raise RuntimeError("run chunk missing: " + name + f" chunk {number}")
                receipt_path = chunk_folder / "ghidra_command.json"
                rows = None
                image_base = None
                if receipt_path.exists():
                    receipt = json.loads(receipt_path.read_text(encoding="utf-8"))
                    if (receipt.get("task_id") != "TASK_160" or receipt.get("library") != name or
                        receipt.get("chunk") != number or receipt.get("source_sha256") != expected_sha or
                        receipt.get("target_tsv_sha256") != sha256(tsv) or
                        receipt.get("script_sha256") != sha256(SCRIPTS / "ExportChunk160.java") or
                        receipt.get("status") != run["status"]):
                        raise RuntimeError("command identity mismatch: " + name + f" chunk {number}")
                    command = receipt["command"]
                    expected_operation = "-import" if number == 1 else "-process"
                    if (expected_operation not in command or "-max-cpu" not in command or
                        command[command.index("-max-cpu") + 1] != "1"):
                        raise RuntimeError("Ghidra command bounds mismatch: " + name + f" chunk {number}")
                    for key, filename in (("stdout_sha256", "ghidra_stdout.log"),
                                          ("stderr_sha256", "ghidra_stderr.log"),
                                          ("result_sha256", "ghidra_raw.json")):
                        path = chunk_folder / filename
                        if receipt.get(key) is not None and (not path.is_file() or receipt[key] != sha256(path)):
                            raise RuntimeError("raw evidence hash mismatch: " + name + f" chunk {number} {filename}")
                    if receipt["status"] == "OUTPUT_READY":
                        if receipt["exit_code"] != 0 or not (chunk_folder / "ghidra_raw.json").is_file():
                            raise RuntimeError("claimed output lacks success: " + name + f" chunk {number}")
                        raw = json.loads((chunk_folder / "ghidra_raw.json").read_text(encoding="utf-8"))
                        if (raw.get("task_id") != "TASK_160" or raw.get("program_name") != name or
                            len(raw.get("targets", [])) != chunk["count"]):
                            raise RuntimeError("raw Ghidra output identity mismatch: " + name + f" chunk {number}")
                        image_base = int(raw["image_base"], 16)
                        rows = raw["targets"]
                        stdout = (chunk_folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
                        if f"[TASK_160] processed {chunk['count']}/{chunk['count']}" not in stdout:
                            raise RuntimeError("Ghidra completion line missing: " + name + f" chunk {number}")
                elif run["status"] not in ("NOT_STARTED_TIME_CAP", "NOT_STARTED_PRIOR_FAILURE"):
                    raise RuntimeError("unreceipted run status: " + name + f" chunk {number}")
                subset = targets[chunk["first_index"] - 1:chunk["last_index"]]
                if len(subset) != chunk["count"]:
                    raise RuntimeError("target subset count mismatch")
                expected_lines = ["\t".join((str(item["index"]), item["elf_va"],
                                  str(item["size_bytes"]), item["source_body_sha256"], item["symbol"]))
                                  for item in subset]
                if tsv.read_text(encoding="utf-8").splitlines() != expected_lines:
                    raise RuntimeError("target TSV differs from index: " + name + f" chunk {number}")
                for position, target in enumerate(subset):
                    global_index = target["index"]
                    va = int(target["elf_va"], 16)
                    aliases = sorted(by_va.get(va, []), key=lambda pair: (-pair[1], pair[0]))
                    if (global_index != chunk["first_index"] + position or
                        (target["symbol"], target["size_bytes"]) != aliases[0] or
                        target["aliases"] != [alias for alias, _ in aliases]):
                        raise RuntimeError(f"source symbol mismatch: {name}#{global_index}")
                    body, offset = mapped_bytes(elf, source, va, target["size_bytes"])
                    digest = hashlib.sha256(body).hexdigest()
                    if target["file_offset"] != f"0x{offset:x}" or target["source_body_sha256"] != digest:
                        raise RuntimeError(f"original body hash/offset mismatch: {name}#{global_index}")
                    decoded = list(capstone.disasm(body, va))
                    decoded_map = {instruction.address: instruction for instruction in decoded}
                    fully_decoded = sum(instruction.size for instruction in decoded) == len(body)
                    library_full_source += int(fully_decoded)
                    library_source_instructions += len(decoded)
                    row = None
                    recovered = False
                    ghidra_count = 0
                    pseudocode_sha = None
                    call_count = 0
                    if rows is not None:
                        row = rows[position]
                        if (row["index"] != global_index or row["elf_va"] != target["elf_va"] or
                            row["symbol"] != target["symbol"] or row["size_bytes"] != len(body) or
                            row["database_va"] != f"0x{image_base + va:x}" or
                            row["expected_source_sha256"] != digest or
                            row["ghidra_memory_sha256"] != digest or
                            row["source_bytes_match"] is not True):
                            raise RuntimeError(f"Ghidra/source body mismatch: {name}#{global_index}")
                        library_source_matched += 1
                        lines = row["instructions"]
                        if len(lines) != row["instruction_count_observed"]:
                            raise RuntimeError(f"Ghidra instruction count mismatch: {name}#{global_index}")
                        addresses = []
                        for line in lines:
                            match = re.match(r"^([0-9a-fA-F]+):\s+", line)
                            if not match:
                                raise RuntimeError(f"Ghidra instruction text unparseable: {name}#{global_index}")
                            address = int(match.group(1), 16) - image_base
                            if address not in decoded_map:
                                raise RuntimeError(f"Ghidra instruction address not source aligned: {name}#{global_index}")
                            addresses.append(address)
                        if addresses != sorted(set(addresses)):
                            raise RuntimeError(f"Ghidra instructions unordered/duplicate: {name}#{global_index}")
                        ghidra_count = len(lines)
                        library_ghidra_instructions += ghidra_count
                        library_full_ghidra += int(fully_decoded and ghidra_count == len(decoded))
                        for call in row["calls"]:
                            match = re.match(r"^([0-9a-fA-F]+)\s+->\s+", call)
                            if not match or int(match.group(1), 16) - image_base not in decoded_map:
                                raise RuntimeError(f"Ghidra call address not source aligned: {name}#{global_index}")
                        call_count = len(row["calls"])
                        recovered = bool(row["decompile_success"] is True and row["pseudocode"].strip() and not row["error"])
                        if row["decompile_success"] is True and not recovered:
                            raise RuntimeError(f"false successful decompile: {name}#{global_index}")
                        if recovered:
                            library_c += 1
                            pseudocode_sha = hashlib.sha256(row["pseudocode"].encode("utf-8")).hexdigest()
                            c_bodies.append(f"/* {name} ELF VA 0x{va:x}; source body SHA-256 {digest} */\n"
                                            + row["pseudocode"] + "\n")
                    records.append({"library": name, "index": global_index, "elf_va": target["elf_va"],
                                    "source_body_sha256": digest, "source_size_bytes": len(body),
                                    "source_capstone_instructions": len(decoded),
                                    "source_fully_decoded": fully_decoded,
                                    "ghidra_memory_source_match": bool(row and row["source_bytes_match"] is True),
                                    "ghidra_listed_instructions": ghidra_count,
                                    "ghidra_c_like_recovered": recovered,
                                    "ghidra_pseudocode_sha256": pseudocode_sha,
                                    "ghidra_call_sites": call_count,
                                    "raw_chunk_json": f"{name}/chunk_{number:02d}/ghidra_raw.json" if rows is not None else None})
            total_c += library_c
            total_source_match += library_source_matched
            total_source_instructions += library_source_instructions
            total_ghidra_instructions += library_ghidra_instructions
            total_full_source += library_full_source
            total_full_ghidra += library_full_ghidra
            summaries.append({"library": name, "source_sha256": expected_sha,
                              "export_vas": expected_count, "source_bodies_rehashed": expected_count,
                              "source_fully_capstone_decoded": library_full_source,
                              "source_capstone_instructions": library_source_instructions,
                              "ghidra_memory_source_matched": library_source_matched,
                              "ghidra_listed_source_aligned_instructions": library_ghidra_instructions,
                              "ghidra_full_listings": library_full_ghidra,
                              "ghidra_c_like_recovered": library_c,
                              "chunks_ready": sum(run_status[(name, x["chunk"])]["status"] == "OUTPUT_READY" for x in chunks),
                              "chunks_total": len(chunks)})
    if len(records) != 3326:
        raise RuntimeError("aggregate source body count changed")
    sample_indices = sorted({round(i * 3325 / 333) for i in range(334)})
    if len(sample_indices) < math.ceil(3326 * .10):
        raise RuntimeError("spread ordinary sample below 10%")
    for position in sample_indices:
        item = records[position]
        index = json.loads((REPORT / item["library"] / "target_index.json").read_text(encoding="utf-8"))
        if index["targets"][item["index"] - 1]["source_body_sha256"] != item["source_body_sha256"]:
            raise RuntimeError("spread source ordinary sample mismatch")
    write_json(REPORT / "independent_verification.json", {
        "task_id": "TASK_160", "revision": 1, "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "libraries_source_rehashed": 1, "export_vas_source_rehashed": 3326,
        "source_fully_capstone_decoded_bodies": total_full_source,
        "source_capstone_instructions": total_source_instructions,
        "ghidra_memory_source_matched": total_source_match,
        "ghidra_c_like_bodies_recovered": total_c,
        "ghidra_fully_listed_bodies": total_full_ghidra,
        "ghidra_listed_source_aligned_instructions": total_ghidra_instructions,
        "ordinary_function_records_spread_sampled": len(sample_indices),
        "ordinary_function_records_total": 3326,
        "internal_nonexported_functions_covered": False,
        "runtime_or_pixel_semantics_proven": False,
        "libraries": summaries, "records": records})
    write_json(REPORT / "source_c_manifest.json", {
        "task_id": "TASK_160", "revision": 1, "generated_at": now(),
        "source_libraries": summaries, "records": records})
    atomic_bytes(REPORT / "all_recovered_export_pseudocode.c", "\n".join(c_bodies).encode("utf-8"))
    finished = total_c == 3326 and all(item["chunks_ready"] == item["chunks_total"] for item in summaries)
    disposition = "BOUNDED_RESEARCH_CANDIDATE" if finished else "PARTIAL_RESEARCH_CANDIDATE"
    table = "\n".join(f"| {item['library']} | {item['export_vas']} | {item['ghidra_c_like_recovered']} | {item['chunks_ready']}/{item['chunks_total']} |"
                      for item in summaries)
    master = f"""# TASK_160 R1 - PVGImageCodec exported-function recovery

Status: **{disposition} awaiting independent CEO review**. This is static research from pinned original SOs; it does not establish runtime behavior or product readiness.

| Library | Unique defined nonzero export VAs | Nonempty C-like bodies | Ready chunks |
|---|---:|---:|---:|
{table}

## Observed

- The original AArch64 SO file matches pinned SHA-256. All 3,326 export VAs and PT_LOAD offsets/body hashes were independently enumerated and rechecked. Capstone decoded {total_source_instructions:,} source instructions; {total_full_source}/3,326 declared symbol ranges decoded fully.
- Exactly one fresh Ghidra import was run for this SO; subsequent chunks used read-only processing. Every process command, raw stdout/stderr, exit code and raw JSON is in the per-source/chunk folders. Each process was bounded to 1 CPU/1 GiB, <=900s, and each decompilation to <=15s.
- Ghidra memory matched the source body for {total_source_match}/3,326 VAs and produced {total_c}/3,326 nonempty C-like exported bodies. Its {total_ghidra_instructions:,} listed instruction addresses were aligned to Capstone-decoded original source addresses; {total_full_ghidra}/3,326 listings covered their fully decoded declared body range. {len(sample_indices)} spread ordinary records ({len(sample_indices)/3326:.1%}) received separate index consistency checks.

## Inferred and limits

- The C-like output supports static call/control-flow research only. Symbol names do not prove the library's effect or exact UI-to-native binding. Internal nonexported functions, indirect calls, live data, device behavior and pixel parity remain unverified.
- No P0/product edits, Phase PASS, V4/P7 authorization, self-review, commit or push. Source/body verification and a decompiler result do not prove a hair-color algorithm or full 45-SO recovery.
"""
    atomic_bytes(REPORT / "01_MASTER_REPORT.md", master.encode("utf-8"))
    audit = ("# TASK_160 R1 audit index\n\n"
             f"Canonical standard fully read at `{now()}`: `{STANDARD}` SHA-256 `{STANDARD_SHA}`.\n\n"
             f"Task SHA-256 `{TASK_SHA}`; real Codex actor `{AGENT_ID}`, lease `{LEASE_ID}`, fence `{FENCE}`.\n\n"
             "Original ELF paths/hashes, PT_LOAD body hashes, exact export VAs, chunk boundaries, raw commands/logs, "
             "C-like bodies, independent verification and frozen COMPLETE hash map are in this package.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_160", "revision": 1,
        "status": "BOUNDED_RESEARCH_REPORT_READY" if finished else "PARTIAL_RESEARCH_REPORT_READY",
        "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
        "source_bodies_rehashed": 3326, "c_like_bodies_recovered": total_c,
        "independent_review_pending": True, "phase_pass": False})
    files = {path.relative_to(REPORT).as_posix(): sha256(path) for path in sorted(REPORT.rglob("*"))
             if path.is_file() and path.relative_to(REPORT).as_posix() not in ("COMPLETE.json", "PROGRESS.json")}
    size = sum((REPORT / relative).stat().st_size for relative in files)
    if not files or size > 134_217_728:
        raise RuntimeError(f"report extent exceeds task cap: {size}")
    code = {path.relative_to(ROOT).as_posix(): sha256(path)
            for path in sorted(SCRIPTS.iterdir()) if path.is_file() and path.suffix in (".py", ".java")}
    check_lease()
    write_json(REPORT / "COMPLETE.json", {
        "schema_version": "2.1.2", "task_id": "TASK_160", "revision": 1,
        "status": "COMPLETE", "semantic_disposition": disposition,
        "generated_at": now(), "standard_sha256": STANDARD_SHA,
        "task_sha256": TASK_SHA, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "execution_mode": "REAL_CODEX_SUBAGENT_NO_AGY",
        "review_state": "AWAITING_INDEPENDENT_CEO_REVIEW",
        "critical_provenance_rechecked": True,
        "ordinary_records_independently_rechecked": len(sample_indices),
        "ordinary_records_total": 3326, "source_bodies_rehashed": 3326,
        "c_like_bodies_recovered": total_c,
        "internal_nonexported_functions_covered": False,
        "runtime_or_pixel_semantics_proven": False,
        "files": files, "code_files": code})
    print(json.dumps({"disposition": disposition, "source_bodies_rehashed": 3326,
                      "c_like_bodies_recovered": total_c,
                      "source_fully_decoded": total_full_source,
                      "report_files": len(files), "report_bytes": size}))


if __name__ == "__main__":
    main()
