"""Recheck original-byte, unwind, package and scratch-Ghidra claims for TASK_174."""

from __future__ import annotations

import hashlib
import json
import math
import struct
from datetime import datetime, timezone
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs

from forensic import PINNED_SHA, SOURCE, parse
from package import require_lease
from unwind import parse_unwind


ROOT = Path(__file__).resolve().parents[2]
REPORT = ROOT / "RULES/REPORT/TASK_174_REPORT_R1"
RAW = REPORT / "raw"
RESEARCH = ROOT / "RESEARCH_WORK/TASK_174_R1"


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def read_json(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def main() -> None:
    require_lease()
    source = SOURCE.read_bytes()
    assert len(source) == 773652 and sha(source) == PINNED_SHA
    elf = parse(source)
    assert elf["header"]["machine"] == 183
    assert elf["header"]["shoff"] == 1352944
    assert elf["section_header_table"]["available_length"] == 0
    assert elf["section_header_table"]["declared_length"] == 1792
    dynamic = [p for p in elf["program_headers"] if p["type"] == 2]
    assert len(dynamic) == 1
    assert dynamic[0]["file_offset"] == 1330424
    assert dynamic[0]["file_size"] == 560
    assert dynamic[0]["file_region"]["available_length"] == 0
    assert elf["dynamic_entries_recovered"] == []
    assert elf["dynamic_export_census"] == "UNKNOWN"
    exec_load = [p for p in elf["program_headers"] if p["type"] == 1 and p["flags"] & 1]
    assert len(exec_load) == 1
    assert exec_load[0]["file_size"] == 1307184
    assert exec_load[0]["file_region"]["available_length"] == len(source)
    saved_elf = read_json(RAW / "elf_forensics.json")
    assert saved_elf == elf

    unwind = parse_unwind(source)
    saved_unwind = read_json(RAW / "unwind_ranges.json")
    assert saved_unwind == unwind
    assert unwind["fde_table_count"] == 1513
    assert unwind["complete_original_body_ranges"] == 1020
    assert unwind["partial_original_body_ranges"] == 1
    assert unwind["absent_original_body_ranges"] == 492
    complete = [r for r in unwind["records"] if r["body_complete_in_input"]]
    assert len(complete) == 1020
    assert sum(r["function_size"] for r in complete) == 447620
    assert all(r["in_declared_executable_load"] for r in complete)
    partial = [r for r in unwind["records"] if 0 < r["retained_body_bytes"] < r["function_size"]]
    assert len(partial) == 1 and partial[0]["retained_body_bytes"] == 2448
    assert partial[0]["function_size"] == 5284

    index = read_json(RESEARCH / "complete_fde_index.json")
    blob = (RESEARCH / "complete_fde_bodies.bin").read_bytes()
    asm_lines = (RESEARCH / "complete_fde_assembly.ndjson").read_text(encoding="utf-8").splitlines()
    assert index["count"] == 1020 and index["aggregate_bytes"] == 447620
    assert len(blob) == 447620 and sha(blob) == index["blob_sha256"]
    assert len(index["items"]) == len(asm_lines) == 1020
    for expected, item in zip(complete, index["items"]):
        assert item["fde_index"] == expected["index"]
        assert item["va"] == expected["function_va"]
        assert item["size"] == expected["function_size"]
        assert item["original_file_offset"] == expected["body_file_offset"]
        body = blob[item["blob_offset"] : item["blob_offset"] + item["size"]]
        assert body == source[item["original_file_offset"] : item["original_file_offset"] + item["size"]]
        assert sha(body) == item["sha256"] == expected["retained_body_sha256"]
    # Independent spread ≥10% of ordinary assembly rows, plus all body SHA checks above.
    sample_positions = sorted({round(i * (len(complete) - 1) / 102) for i in range(103)})
    assert len(sample_positions) >= math.ceil(len(complete) * 0.10)
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoder.skipdata = True
    for pos in sample_positions:
        item = index["items"][pos]
        row = json.loads(asm_lines[pos])
        body = source[item["original_file_offset"] : item["original_file_offset"] + item["size"]]
        decoded = [{"va": ins.address, "mnemonic": ins.mnemonic, "op_str": ins.op_str}
                   for ins in decoder.disasm(body, item["va"])]
        assert row["fde_index"] == item["fde_index"]
        assert row["va"] == item["va"] and row["body_sha256"] == item["sha256"]
        assert row["instructions"] == decoded

    repair = read_json(RAW / "scratch_repair.json")
    scratch = (RESEARCH / "scratch/libmfxkit_truncated_repaired_for_ghidra.so").read_bytes()
    assert len(scratch) == len(source) and sha(scratch) == repair["scratch_sha256"]
    expected_scratch = bytearray(source)
    struct.pack_into("<Q", expected_scratch, 40, 0)
    struct.pack_into("<HHH", expected_scratch, 58, 0, 0, 0)
    for p in elf["program_headers"]:
        off = elf["header"]["phoff"] + p["index"] * elf["header"]["phentsize"]
        if p["type"] == 1 and p["flags"] & 1:
            struct.pack_into("<QQ", expected_scratch, off + 32, len(source), len(source))
        elif p["file_size"] and not p["file_region"]["entirely_present"]:
            expected_scratch[off : off + 56] = b"\0" * 56
    assert scratch == expected_scratch
    assert len(repair["sample_fde_indices"]) == 20

    chunks = read_json(RAW / "ghidra_chunks/manifest.json")
    assert chunks["remaining_count"] == 1000 and len(chunks["chunks"]) == 5
    rows = []
    sample = read_json(RAW / "ghidra_sample_raw.json")
    assert sample["task_id"] == "TASK_174" and len(sample["targets"]) == 20
    rows.extend(sample["targets"])
    import_receipt = read_json(RAW / "ghidra_command.json")
    assert import_receipt["status"] == "EXIT_ZERO" and import_receipt["exit_code"] == 0
    assert import_receipt["scratch_sha256"] == sha(scratch)
    assert import_receipt["output_sha256"] == sha((RAW / "ghidra_sample_raw.json").read_bytes())
    assert import_receipt["max_cpu"] == 1 and import_receipt["heap_limit"] == "1G"
    assert import_receipt["elapsed_seconds"] <= 900
    total_ghidra_seconds = import_receipt["elapsed_seconds"]
    warning_count = (RAW / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace").count("WARN  Decompiling")
    for entry in chunks["chunks"]:
        folder = ROOT / entry["folder"]
        tsv = folder / "targets.tsv"
        assert sha(tsv.read_bytes()) == entry["targets_sha256"]
        raw = read_json(folder / "ghidra_raw.json")
        receipt = read_json(folder / "ghidra_command.json")
        assert raw["task_id"] == "TASK_174" and len(raw["targets"]) == 200
        assert receipt["status"] == "OUTPUT_READY" and receipt["exit_code"] == 0
        assert receipt["output_sha256"] == sha((folder / "ghidra_raw.json").read_bytes())
        assert receipt["read_only_project"] is True and receipt["fresh_imports"] == 0
        assert receipt["max_cpu"] == 1 and receipt["heap_limit"] == "1G"
        assert receipt["elapsed_seconds"] <= 900
        total_ghidra_seconds += receipt["elapsed_seconds"]
        warning_count += (folder / "ghidra_stdout.log").read_text(encoding="utf-8", errors="replace").count("WARN  Decompiling")
        rows.extend(raw["targets"])
    assert total_ghidra_seconds < 3600
    assert len(rows) == len(complete) == 1020
    by_fde = {r["index"]: r for r in complete}
    seen = set()
    c_like = 0
    failures = []
    no_instruction_rows = 0
    for row in rows:
        idx = int(row["symbol"].removeprefix("FDE_"))
        assert idx not in seen and idx in by_fde
        seen.add(idx)
        expected = by_fde[idx]
        assert int(row["elf_va"], 16) == expected["function_va"]
        assert row["size_bytes"] == expected["function_size"]
        assert row["expected_source_sha256"].lower() == expected["retained_body_sha256"]
        assert row["ghidra_memory_sha256"].lower() == expected["retained_body_sha256"]
        assert row["source_bytes_match"] is True
        if row["instruction_count_observed"] == 0:
            no_instruction_rows += 1
        if row["decompile_success"] and row["pseudocode"].strip():
            c_like += 1
        else:
            failures.append({"fde_index": idx, "va": row["elf_va"], "error": row["error"]})
    assert seen == set(by_fde)
    assert c_like == 1010 and len(failures) == 10
    assert all("timeout" in f["error"].lower() for f in failures)
    assert sha(SOURCE.read_bytes()) == PINNED_SHA
    verification = {
        "schema": "task174-independent-worker-rerun-v1",
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "task_id": "TASK_174", "revision": 1,
        "source_sha256": PINNED_SHA, "source_bytes": len(source),
        "section_header_table_unavailable_bytes": 1792,
        "pt_dynamic_unavailable_bytes": 560,
        "declared_executable_load_bytes": 1307184,
        "retained_executable_load_bytes": len(source),
        "dynamic_export_census": "UNKNOWN",
        "unwind_fde_count": 1513,
        "complete_original_body_ranges": 1020,
        "complete_original_body_bytes": 447620,
        "partial_original_body_ranges": 1,
        "absent_original_body_ranges": 492,
        "all_complete_original_body_hashes_rechecked": 1020,
        "ordinary_spread_assembly_samples_redecoded": len(sample_positions),
        "ordinary_spread_assembly_sample_positions": sample_positions,
        "scratch_metadata_delta_reconstructed_exactly": True,
        "scratch_import_processes": 1,
        "scratch_readonly_chunk_processes": 5,
        "total_ghidra_process_seconds": round(total_ghidra_seconds, 3),
        "ghidra_source_memory_hashes_rechecked": 1020,
        "ghidra_c_like_bodies": c_like,
        "ghidra_timeout_failures": failures,
        "ghidra_rows_without_instructions": no_instruction_rows,
        "ghidra_decompilation_warning_lines": warning_count,
        "semantic_equivalence_proven": False,
        "export_identity_proven": False,
        "verified": True,
    }
    (RAW / "verification.json").write_text(json.dumps(verification, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({
        "verified": True, "unwind": 1513, "complete_bodies": 1020,
        "ghidra_c_like": c_like, "ghidra_timeout": len(failures),
        "ordinary_samples": len(sample_positions), "warning_lines": warning_count,
        "total_ghidra_process_seconds": verification["total_ghidra_process_seconds"],
    }))


if __name__ == "__main__":
    main()
