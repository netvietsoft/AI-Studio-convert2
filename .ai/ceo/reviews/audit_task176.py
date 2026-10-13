"""Read-only CEO audit of TASK_176's 683 source/export/Ghidra records."""

from __future__ import annotations

import hashlib
import json
import math
import re
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_176_REPORT_R1"
OLD = ROOT / "RULES/REPORT/TASK_156_REPORT_R1"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
SOURCES = {"libbmpKit.so": ("550e87fbfd13b8de0833789df04038c659e0472606e6a161eaf775ba126cd168", 316),
           "libfftw3.so": ("0968cee954c2bcbbb8df9daca5a9d122343b280462aaad9533f083f15a4b1c32", 367)}


def sha(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read(path: Path):
    return json.loads(path.read_text(encoding="utf-8"))


def main() -> None:
    seal_path = REPORT / "COMPLETE.json"
    original_seal_sha = sha(seal_path)
    seal = read(seal_path)
    standard = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
    task = ROOT / "RULES/TASK/TASK_176_SO45_CODEX_EXPORT_RECOVERY_ACTIVE.md"
    assert (seal["task_id"], seal["revision"], seal["status"], seal["result_class"]) == ("TASK_176", 1, "COMPLETE", "REVALIDATED_HISTORICAL_STATIC_EXPORT_RESEARCH")
    assert seal["standard_sha256"] == sha(standard) and seal["task_sha256"] == sha(task)
    assert (seal["original_export_vas"], seal["historical_c_like_bodies_revalidated"], seal["fresh_ghidra_memory_bodies_verified"], seal["fresh_imports"], seal["fresh_decompilations"]) == (683, 683, 683, 0, 0)
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {"COMPLETE.json", "PROGRESS.json"}
    assert set(seal["files"]) == actual and len(actual) == 29
    for relative, digest in seal["files"].items():
        assert sha(REPORT / relative) == digest, relative
    for relative, digest in seal["code_files"].items():
        assert sha(ROOT / relative) == digest, relative
    assert len(seal["code_files"]) == 5
    for relative, digest in seal["scratch_files"].items():
        assert sha(ROOT / relative) == digest, relative
    assert len(seal["scratch_files"]) == 18
    audit_text = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    assert seal["standard_sha256"] in audit_text and seal["task_sha256"] in audit_text
    old_seal = read(OLD / "COMPLETE.json")
    assert old_seal["task_id"] == "TASK_156" and old_seal["revision"] == 1
    assert sha(OLD / "COMPLETE.json") == read(REPORT / "source_batch_index.json")["historical_complete_sha256"]

    projects = read(REPORT / "project_copy_manifest.json")["projects"]
    batch = read(REPORT / "source_batch_index.json")
    run = read(REPORT / "memory_run_receipt.json")
    assert run["status"] == "OUTPUT_READY" and len(run["libraries"]) == 2
    totals = {"bodies": 0, "bytes": 0, "instructions": 0, "direct": 0, "indirect": 0, "sample": 0}
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    aliases_allowed = {("b.cc", "b.lo"), ("b.cs", "b.hs"), ("orr", "mov"), ("dup", "mov"), ("bfm", "bfi"), ("negs", "cmp")}
    for lib, (source_sha, count) in SOURCES.items():
        assert sha(SOURCE / lib) == source_sha
        folder = REPORT / lib
        source_index = read(folder / "source_index.json")
        old_index = read(folder / "historical_target_index.json")
        old_raw = read(folder / "historical_ghidra_raw.json")
        old_command = read(folder / "historical_ghidra_command.json")
        fresh = read(folder / "fresh_memory_raw.json")
        fresh_command = read(folder / "fresh_memory_command.json")
        verified = read(folder / "independent_verification.json")
        assert (source_index["original_unique_export_vas"], len(source_index["targets"]), len(old_index["targets"]), len(old_raw["targets"]), len(fresh["targets"])) == (count, count, count, count, count)
        assert fresh["target_count"] == count and fresh["fresh_imports"] == fresh["fresh_decompilations"] == 0
        assert old_command["status"] == fresh_command["status"] == "OUTPUT_READY"
        assert old_command["exit_code"] == fresh_command["exit_code"] == 0
        assert old_command["result_sha256"] == sha(folder / "historical_ghidra_raw.json")
        assert old_command["stdout_sha256"] == sha(folder / "historical_ghidra_stdout.log")
        assert old_command["stderr_sha256"] == sha(folder / "historical_ghidra_stderr.log")
        assert fresh_command["result_sha256"] == sha(folder / "fresh_memory_raw.json")
        assert fresh_command["stdout_sha256"] == sha(folder / "fresh_memory_stdout.log")
        assert fresh_command["stderr_sha256"] == sha(folder / "fresh_memory_stderr.log")
        assert "-readOnly" in fresh_command["command"] and "-noanalysis" in fresh_command["command"] and "-import" not in fresh_command["command"]
        assert "VerifyMemory176.java" in fresh_command["command"] and fresh_command["elapsed_seconds"] <= 900
        assert old_command["source_sha256"] == fresh_command["source_sha256"] == source_sha
        assert sha(folder / "historical_ghidra_raw.json") == sha(OLD / lib / "ghidra_raw.json")
        for filename in ("target_index.json", "targets.tsv", "ghidra_raw.json", "ghidra_command.json", "ghidra_stdout.log", "ghidra_stderr.log"):
            assert sha(folder / ("historical_" + filename)) == sha(OLD / lib / filename)
        project = projects[lib]
        old_project = ROOT / "RESEARCH_WORK/TASK_156_R1" / lib / "ghidra_project"
        copied = ROOT / "RESEARCH_WORK/TASK_176_R1" / lib / "ghidra_project"
        assert Path(project["original_project_path"]) == old_project and Path(project["copy_project_path"]) == copied
        for item in project["files"]:
            old_file = old_project / item["relative_path"]
            copy_file = copied / item["relative_path"]
            assert sha(old_file) == item["source_sha256"] == item["copy_sha256"]
            if "db.1.gbf" in item["relative_path"] or item["relative_path"].endswith("00000000.prp"):
                assert sha(copy_file) == item["copy_sha256"]
        assert len(project["files"]) == 10
        with (SOURCE / lib).open("rb") as stream:
            elf = ELFFile(stream)
            assert elf["e_machine"] == "EM_AARCH64"
            by_va = {}
            for sym in elf.get_section_by_name(".dynsym").iter_symbols():
                if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0:
                    by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
            loads = [seg for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"]
        assert len(by_va) == count
        raw_source = (SOURCE / lib).read_bytes()
        base = int(fresh["image_base"], 16)
        assert base == int(old_raw["image_base"], 16)
        take = math.ceil(count * .12)
        sample_indices = {1 + round(k * (count - 1) / (take - 1)) for k in range(take)}
        evidence_rows = []
        sample_rows = []
        lib_counts = {"bodies": 0, "bytes": 0, "instructions": 0, "direct": 0, "indirect": 0}
        for index, va in enumerate(sorted(by_va), 1):
            symbol, size = sorted(by_va[va], key=lambda x: (-x[1], x[0]))[0]
            aliases = [n for n, _ in sorted(by_va[va], key=lambda x: (-x[1], x[0]))]
            mapped = [int(seg["p_offset"]) + va - int(seg["p_vaddr"]) for seg in loads if int(seg["p_vaddr"]) <= va and va + size <= int(seg["p_vaddr"]) + int(seg["p_filesz"])]
            assert len(mapped) == 1
            body = raw_source[mapped[0]:mapped[0] + size]
            body_sha = hashlib.sha256(body).hexdigest()
            srow, irow, hrow, frow = (source_index["targets"][index - 1], old_index["targets"][index - 1], old_raw["targets"][index - 1], fresh["targets"][index - 1])
            assert srow["index"] == irow["index"] == hrow["index"] == frow["index"] == index
            assert srow["elf_va"] == irow["elf_va"] == hrow["elf_va"] == frow["elf_va"] == f"0x{va:x}"
            assert srow["symbol"] == irow["symbol"] == hrow["symbol"] == frow["symbol"] == symbol
            assert srow["size_bytes"] == irow["size_bytes"] == hrow["size_bytes"] == frow["size_bytes"] == size
            assert srow["aliases"] == irow["aliases"] == aliases
            assert int(srow["file_offset"], 16) == int(irow["file_offset"], 16) == mapped[0]
            assert srow["source_body_sha256"] == irow["source_body_sha256"] == hrow["expected_source_sha256"] == hrow["ghidra_memory_sha256"] == frow["ghidra_memory_sha256"] == body_sha
            assert hrow["source_bytes_match"] is frow["source_bytes_match"] is frow["function_present"] is True
            assert hrow["decompile_success"] is True and bool(hrow["pseudocode"].strip()) and not hrow["error"]
            assert int(hrow["database_va"], 16) == int(frow["database_va"], 16) == base + va
            decoded = {ins.address: ins for ins in decoder.disasm(body, base + va)}
            assert len(decoded) * 4 == len(body)
            assert len(hrow["instructions"]) == hrow["instruction_count_observed"] == frow["instruction_starts"]
            previous = 0
            for line in hrow["instructions"]:
                match = re.match(r"^([0-9a-fA-F]+):\s+(\S+)", line)
                assert match is not None
                pc, mnemonic = int(match.group(1), 16), match.group(2).lower()
                assert pc in decoded and pc > previous
                previous = pc
                cap_mnemonic = decoded[pc].mnemonic.lower()
                assert mnemonic == cap_mnemonic or (mnemonic, cap_mnemonic) in aliases_allowed
                lib_counts["instructions"] += 1
            direct = indirect = 0
            for call in hrow["calls"]:
                pc_text, target_text = call.split(" -> ", 1)
                ins = decoded[int(pc_text, 16)]
                if target_text == "INDIRECT":
                    assert ins.mnemonic == "blr"
                    indirect += 1
                else:
                    assert ins.mnemonic in ("bl", "b")
                    target = int(target_text.split(" ", 1)[0], 16)
                    assert target == int(ins.op_str.lstrip("#"), 0)
                    direct += 1
            lib_counts["direct"] += direct
            lib_counts["indirect"] += indirect
            lib_counts["bodies"] += 1
            lib_counts["bytes"] += len(body)
            evidence_rows.append({"index": index, "elf_va": f"0x{va:x}", "source_body_sha256": body_sha, "ghidra_memory_sha256": frow["ghidra_memory_sha256"], "historical_c_like_sha256": hashlib.sha256(hrow["pseudocode"].encode()).hexdigest(), "historical_instruction_rows": len(hrow["instructions"]), "fresh_instruction_starts": frow["instruction_starts"]})
            if index in sample_indices:
                sample_rows.append({"index": index, "elf_va": f"0x{va:x}", "symbol": symbol, "source_body_sha256": body_sha, "c_like_sha256": hashlib.sha256(hrow["pseudocode"].encode()).hexdigest(), "capstone_decoded_instructions": len(decoded), "ghidra_instruction_pcs": len(hrow["instructions"]), "direct_or_tail_calls": direct, "indirect_calls": indirect})
        assert len(sample_rows) >= math.ceil(.1 * count)
        assert sample_rows == verified["ordinary_spread_sample"] and evidence_rows == verified["all_export_evidence_rows"]
        checks = verified["all_critical_checks"]
        assert (lib_counts["bodies"], lib_counts["bytes"], lib_counts["instructions"], lib_counts["direct"], lib_counts["indirect"]) == (checks["original_pt_load_body_hashes_cross_checked"], checks["source_body_bytes_cross_checked"], checks["historical_instruction_pcs_cross_checked"], checks["direct_call_branch_targets_cross_checked"], checks["indirect_calls_cross_checked"])
        assert fresh["body_bytes_hashed"] == lib_counts["bytes"]
        totals["sample"] += len(sample_rows)
        for key in lib_counts:
            totals[key] += lib_counts[key]
    assert (totals["bodies"], totals["bytes"], totals["instructions"], totals["direct"], totals["indirect"], totals["sample"]) == (683, 99352, 23900, 1813, 60, 83)
    assert sha(seal_path) == original_seal_sha
    print(json.dumps({"result": "PASS", "task": "TASK_176", "manifest_files": len(actual), "code_files": len(seal["code_files"]), "scratch_files": len(seal["scratch_files"]), **totals}, sort_keys=True))


if __name__ == "__main__":
    main()
