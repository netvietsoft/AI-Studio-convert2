"""Independent, read-only CEO audit of the sealed TASK_174 R1 research."""

from __future__ import annotations

import hashlib
import json
import math
import struct
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs


ROOT = Path(__file__).resolve().parents[3]
SOURCE = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libmfxkit.so")
REPORT = ROOT / "RULES/REPORT/TASK_174_REPORT_R1"
RESEARCH = ROOT / "RESEARCH_WORK/TASK_174_R1"
TASK = ROOT / "RULES/TASK/TASK_174_SO45_MFXKIT_ELF_FORENSIC_ACTIVE.md"
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def read(path: Path):
    return json.loads(path.read_text(encoding="utf-8"))


def check_manifest(seal: dict) -> dict:
    groups = {
        "files": REPORT,
        "code_files": ROOT,
        "research_files": ROOT,
    }
    totals = {}
    for group, base in groups.items():
        entries = seal[group]
        for relative, expected in entries.items():
            target = (base / relative).resolve()
            assert target.is_relative_to(base.resolve()), (group, relative)
            assert target.is_file(), (group, relative)
            assert sha(target.read_bytes()) == expected, (group, relative)
        totals[group] = len(entries)
    listed = set(seal["files"])
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()}
    assert actual - {"COMPLETE.json", "PROGRESS.json"} == listed
    assert sum((REPORT / r).stat().st_size for r in listed) == seal["report_bytes_excluding_seal_and_progress"]
    assert seal["standard_sha256"] == sha(STANDARD.read_bytes())
    assert seal["task_sha256"] == sha(TASK.read_bytes())
    return totals


def main() -> None:
    seal = read(REPORT / "COMPLETE.json")
    assert (seal["task_id"], seal["revision"], seal["status"]) == ("TASK_174", 1, "COMPLETE")
    assert seal["semantic_disposition"].startswith("PARTIAL_")
    assert seal["dynamic_export_census"] == "UNKNOWN"
    assert seal["semantic_equivalence_proven"] is False and seal["phase_pass"] is False
    totals = check_manifest(seal)
    src = SOURCE.read_bytes()
    assert len(src) == 773652 and sha(src) == seal["source_sha256"]
    assert src[:4] == b"\x7fELF" and src[4:6] == bytes((2, 1))
    hdr = struct.unpack_from("<HHIQQQIHHHHHH", src, 16)
    _, machine, _, _, phoff, shoff, _, ehsize, phentsize, phnum, shentsize, shnum, _ = hdr
    assert (machine, ehsize, phentsize, phnum, shoff, shentsize * shnum) == (183, 64, 56, 9, 1352944, 1792)
    assert phoff + phentsize * phnum <= len(src) < shoff
    phdrs = [struct.unpack_from("<IIQQQQQQ", src, phoff + i * phentsize) for i in range(phnum)]
    dynamics = [p for p in phdrs if p[0] == 2]
    assert len(dynamics) == 1 and dynamics[0][2:3] == (1330424,) and dynamics[0][5] == 560
    assert dynamics[0][2] >= len(src)
    rx = [p for p in phdrs if p[0] == 1 and p[1] & 1]
    assert len(rx) == 1 and rx[0][2] == 0 and rx[0][5] == 1307184
    eh = [p for p in phdrs if p[0] == 0x6474E550]
    assert len(eh) == 1 and eh[0][2] == 237000 and eh[0][5] == 12116
    assert eh[0][2] + eh[0][5] <= len(src)
    assert src[eh[0][2]:eh[0][2] + 4] == b"\x01\x1b\x03\x3b"
    assert struct.unpack_from("<I", src, eh[0][2] + 8)[0] == 1513

    def map_va(va: int) -> int:
        candidates = [p[2] + va - p[3] for p in phdrs if p[0] == 1 and p[3] <= va < p[3] + p[5]]
        assert len(candidates) == 1, (va, candidates)
        return candidates[0]

    unwind = read(REPORT / "raw/unwind_ranges.json")
    records = unwind["records"]
    assert len(records) == 1513
    complete = []
    partial = []
    absent = []
    prior_va = -1
    cie_offsets = set()
    for i, rec in enumerate(records):
        start_rel, fde_rel = struct.unpack_from("<ii", src, eh[0][2] + 12 + i * 8)
        start_va, fde_va = eh[0][3] + start_rel, eh[0][3] + fde_rel
        fde_off = map_va(fde_va)
        length, cie_ptr, body_rel, span = struct.unpack_from("<IIiI", src, fde_off)
        cie_off = fde_off + 4 - cie_ptr
        cie_offsets.add(cie_off)
        assert length >= 12 and fde_off + 4 + length <= len(src)
        assert struct.unpack_from("<I", src, cie_off + 4)[0] == 0
        assert start_va == fde_va + 8 + body_rel and start_va >= prior_va
        assert (rec["index"], rec["fde_va"], rec["fde_offset"], rec["cie_offset"]) == (i, fde_va, fde_off, cie_off)
        assert (rec["function_va"], rec["function_size"], rec["function_end_va"]) == (start_va, span, start_va + span)
        prior_va = start_va
        body_off = map_va(start_va)
        retained = min(span, max(0, len(src) - body_off))
        assert rec["body_file_offset"] == body_off and rec["retained_body_bytes"] == retained
        assert rec["retained_body_sha256"] == sha(src[body_off:body_off + retained])
        if retained == span:
            assert rec["body_complete_in_input"] is True
            complete.append(rec)
        elif retained:
            partial.append(rec)
        else:
            absent.append(rec)
    assert (len(complete), len(partial), len(absent)) == (1020, 1, 492)
    assert sum(r["function_size"] for r in complete) == 447620
    assert (partial[0]["retained_body_bytes"], partial[0]["function_size"]) == (2448, 5284)
    assert cie_offsets == {x["offset"] for x in unwind["cies"]}

    idx = read(RESEARCH / "complete_fde_index.json")
    blob = (RESEARCH / "complete_fde_bodies.bin").read_bytes()
    asm = (RESEARCH / "complete_fde_assembly.ndjson").read_text(encoding="utf-8").splitlines()
    assert idx["count"] == len(idx["items"]) == len(asm) == 1020
    assert len(blob) == idx["aggregate_bytes"] == 447620 and sha(blob) == idx["blob_sha256"]
    assert idx["skipdata_instruction_count"] == 0
    for rec, item in zip(complete, idx["items"]):
        assert (item["fde_index"], item["va"], item["size"], item["original_file_offset"]) == (rec["index"], rec["function_va"], rec["function_size"], rec["body_file_offset"])
        body = src[item["original_file_offset"]:item["original_file_offset"] + item["size"]]
        assert blob[item["blob_offset"]:item["blob_offset"] + item["size"]] == body
        assert item["sha256"] == sha(body)
    positions = sorted({round(i * 1019 / 102) for i in range(103)})
    assert len(positions) >= math.ceil(1020 * 0.1)
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoder.skipdata = True
    for pos in positions:
        item = idx["items"][pos]
        row = json.loads(asm[pos])
        body = src[item["original_file_offset"]:item["original_file_offset"] + item["size"]]
        decoded = [{"va": ins.address, "mnemonic": ins.mnemonic, "op_str": ins.op_str} for ins in decoder.disasm(body, item["va"])]
        assert row["instructions"] == decoded

    scratch = (RESEARCH / "scratch/libmfxkit_truncated_repaired_for_ghidra.so").read_bytes()
    expected = bytearray(src)
    struct.pack_into("<Q", expected, 40, 0)
    struct.pack_into("<HHH", expected, 58, 0, 0, 0)
    for i, p in enumerate(phdrs):
        off = phoff + i * phentsize
        if p[0] == 1 and p[1] & 1:
            struct.pack_into("<QQ", expected, off + 32, len(src), len(src))
        elif p[5] and p[2] + p[5] > len(src):
            expected[off:off + phentsize] = b"\0" * phentsize
    assert scratch == expected
    repair = read(REPORT / "raw/scratch_repair.json")
    assert repair["scratch_sha256"] == sha(scratch) and repair["not_for_runtime_or_export_census"] is True

    raw = REPORT / "raw"
    sample = read(raw / "ghidra_sample_raw.json")
    chunks = read(raw / "ghidra_chunks/manifest.json")
    tables = [(raw / "ghidra_sample_targets.tsv", raw / "ghidra_sample_raw.json", raw / "ghidra_command.json", raw / "ghidra_stdout.log", 20)]
    for item in chunks["chunks"]:
        folder = ROOT / item["folder"]
        tables.append((folder / "targets.tsv", folder / "ghidra_raw.json", folder / "ghidra_command.json", folder / "ghidra_stdout.log", 200))
    assert len(tables) == 6
    rows = []
    warnings = 0
    seconds = 0.0
    for tsv, result_path, command_path, stdout_path, count in tables:
        result = read(result_path)
        command = read(command_path)
        actual_tsv = [line.split("\t") for line in tsv.read_text(encoding="utf-8").splitlines()]
        assert len(actual_tsv) == len(result["targets"]) == count
        assert command["exit_code"] == 0 and command["elapsed_seconds"] <= 900
        assert command["output_sha256"] == sha(result_path.read_bytes())
        assert command["stdout_sha256"] == sha(stdout_path.read_bytes())
        assert command["max_cpu"] == 1 and command["heap_limit"] == "1G"
        assert "-import" in command["command"] if count == 20 else "-readOnly" in command["command"] and "-import" not in command["command"]
        seconds += command["elapsed_seconds"]
        warnings += stdout_path.read_text(encoding="utf-8", errors="replace").count("WARN  Decompiling")
        for cols, row in zip(actual_tsv, result["targets"]):
            assert len(cols) == 5
            assert (int(cols[0]), int(cols[1], 16), int(cols[2]), cols[3], cols[4]) == (row["index"], int(row["elf_va"], 16), row["size_bytes"], row["expected_source_sha256"], row["symbol"])
            rows.append(row)
    assert len(rows) == 1020 and round(seconds, 3) == 357.954 and warnings == 507
    by_index = {r["index"]: r for r in complete}
    observed = set()
    c_like = 0
    errors = []
    for row in rows:
        fde = int(row["symbol"].split("_")[1])
        assert fde in by_index and fde not in observed
        observed.add(fde)
        record = by_index[fde]
        assert int(row["elf_va"], 16) == record["function_va"] and row["size_bytes"] == record["function_size"]
        assert row["expected_source_sha256"] == row["ghidra_memory_sha256"] == record["retained_body_sha256"]
        assert row["source_bytes_match"] is True and row["instruction_count_observed"] == len(row["instructions"]) > 0
        if row["decompile_success"] and row["pseudocode"].strip():
            c_like += 1
        else:
            errors.append((fde, row["error"]))
    assert observed == set(by_index) and c_like == 1010 and len(errors) == 10
    assert all("timeout" in error.lower() for _, error in errors)
    assert seal["complete_original_body_ranges"] == len(complete)
    assert seal["ghidra_c_like_bodies_recovered"] == c_like
    assert seal["ghidra_decompile_timeouts"] == len(errors)
    assert sha(SOURCE.read_bytes()) == seal["source_sha256"]
    print(json.dumps({"result": "PASS", "task": "TASK_174", "manifest": totals, "fde": len(records), "complete_original": len(complete), "partial": len(partial), "absent": len(absent), "c_like": c_like, "timeouts": len(errors), "ordinary_assembly_redecoded": len(positions), "export_census": "UNKNOWN"}, sort_keys=True))


if __name__ == "__main__":
    main()
