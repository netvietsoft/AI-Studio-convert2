"""Read-only CEO audit of TASK_181's two FFmpeg NEON fragment attempts."""
import hashlib
import json
import math
import re
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_181_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_181_SO45_CODEX_CORRECTION_ACTIVE.md"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libffmpeg.so")


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def main():
    task = json.loads(re.search(r"```json\s*(\{.*?\})\s*```", TASK.read_text(encoding="utf-8"), re.S).group(1))
    seal = read(REPORT / "COMPLETE.json")
    source = read(REPORT / "source_verification.json")
    verified = read(REPORT / "verification.json")
    assert seal["task_id"] == "TASK_181" and seal["revision"] == 1 and seal["status"] == "COMPLETE"
    assert seal["research_disposition"] == "PARTIAL_STATIC_FRAGMENT_ONLY"
    assert seal["ghidra_fragment_c_like_count"] == 1 and seal["whole_original_c_like_count"] == 0
    assert not seal["product_phase_pass"] and not seal["behavior_equivalence_tested"]
    assert sha(TASK) == seal["task_sha256"]
    assert sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == seal["standard_sha256"]
    assert sha(SOURCE) == seal["original_so_sha256"] == source["source_sha256"]
    assert seal["lease_id"] == task["expected_lease_id"] and seal["agent_id"] == task["assignee"]
    assert set(seal["files"]) == {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*")
                                   if p.is_file() and p.name not in {"COMPLETE.json", "PROGRESS.json"}}
    for relative, expected in seal["files"].items():
        assert sha(REPORT / relative) == expected, relative
    assert set(seal["code_files"]) == {p.relative_to(ROOT).as_posix() for p in (ROOT / "scripts/task_181_codex_exports").rglob("*") if p.is_file()}
    for relative, expected in seal["code_files"].items():
        assert sha(ROOT / relative) == expected, relative
    audit = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    assert seal["standard_sha256"] in audit and seal["task_sha256"] in audit

    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf["e_machine"] == "EM_AARCH64"
        syms = [sym for sym in elf.get_section_by_name(".dynsym").iter_symbols()
                if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF"
                and int(sym["st_value"]) > 0 and int(sym["st_size"]) > 0]
        loads = [seg for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"]
    assert len({int(sym["st_value"]) for sym in syms}) == source["unique_export_vas"] == verified["original_export_vas"] == 2461
    raw_source = SOURCE.read_bytes()
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    all_decoded = []
    for target, row in zip(task["target_exports"], source["targets"]):
        index, va, size = row["index"], int(row["elf_va"], 16), row["size_bytes"]
        assert index == target["historical_index"] and row["elf_va"] == target["elf_va"]
        assert len([sym for sym in syms if sym.name in row["symbol_names"] and int(sym["st_value"]) == va
                    and int(sym["st_size"]) == size]) >= 1
        mapping = [(int(seg["p_offset"]) + va - int(seg["p_vaddr"]), seg)
                   for seg in loads if int(seg["p_vaddr"]) <= va
                   and va + size <= int(seg["p_vaddr"]) + int(seg["p_filesz"])]
        assert len(mapping) == 1
        offset, segment = mapping[0]
        assert int(row["source_file_offset"], 16) == offset
        assert int(row["pt_load_vaddr"], 16) == int(segment["p_vaddr"])
        assert int(row["pt_load_offset"], 16) == int(segment["p_offset"])
        body = raw_source[offset:offset+size]
        assert hashlib.sha256(body).hexdigest() == row["body_sha256"] == target["source_body_sha256"]
        decoded = list(decoder.disasm(body, va))
        assert len(decoded) == size//4 == row["instruction_count"]
        assembly = (REPORT / f"source_assembly_{index}.txt").read_text(encoding="utf-8").splitlines()
        assert assembly == [f"0x{ins.address:x}: {ins.mnemonic} {ins.op_str}".strip() for ins in decoded]
        all_decoded.extend((index, i, ins) for i, ins in enumerate(decoded))

        fstart, fend = int(row["fragment_start"], 16), int(row["fragment_end"], 16)
        assert va < fstart <= fend < va + size
        fragment = body[fstart-va:fend-va+4]
        assert len(fragment) == row["fragment_size_bytes"]
        assert hashlib.sha256(fragment).hexdigest() == row["original_fragment_sha256"]
        result = read(REPORT / f"fragment_{index}_raw.json")
        command = read(REPORT / f"attempt_{index}_command.json")
        assert result["original_elf_va"] == row["elf_va"] and result["original_body_sha256"] == row["body_sha256"]
        assert result["copied_memory_body_sha256"] == row["body_sha256"]
        assert result["fragment_elf_va"] == row["fragment_start"] and result["fragment_end_elf_va"] == row["fragment_end"]
        assert result["fragment_sha256"] == row["original_fragment_sha256"]
        assert result["fragment_size_bytes"] == len(fragment)
        assert result["fragment_instruction_count"] == len(result["fragment_instructions"]) == len(fragment)//4
        assert not result["whole_original_function_decompiled"]
        for k, line in enumerate(result["fragment_instructions"]):
            pc = int(line.split(":", 1)[0], 16)
            ins = decoded[(fstart-va)//4+k]
            assert pc == ins.address + 0x100000
            assert line.split(":", 1)[1].strip().split()[0].lower() == ins.mnemonic.lower()
        assert all(fstart <= int(line.split(":", 1)[0], 16)-0x100000 <= fend
                   for line in result["fragment_raw_pcode"])
        assert command["script_sha256"] == sha(ROOT / "scripts/task_181_codex_exports/Fragment181.java")
        assert command["source_sha256"] == seal["original_so_sha256"] and command["task_sha256"] == seal["task_sha256"]
        assert command["result_sha256"] == sha(REPORT / f"fragment_{index}_raw.json")
        assert command["stdout_sha256"] == sha(REPORT / f"attempt_{index}_stdout.log")
        assert command["stderr_sha256"] == sha(REPORT / f"attempt_{index}_stderr.log")
        assert command["status"] == "OUTPUT_READY" and command["exit_code"] == 0 and command["wall_seconds"] < 180
        args = command["command"]
        assert "-process" in args and "-noanalysis" in args and "-readOnly" in args and "-max-cpu" in args
        assert "-import" not in args and "Fragment181.java" in args and args[args.index("-max-cpu")+1] == "1"
        assert args[args.index("-postScript")+2] == str(index)
        previous = read(ROOT / f"RULES/REPORT/TASK_173_REPORT_R1/alternative_{index}_raw.json")
        assert previous["alternative_style"] == "normalize" and previous["decompile_completed"]
        assert not previous["c_like"].strip() and previous["expected_source_sha256"] == row["body_sha256"]
        assert previous["ghidra_memory_sha256"] == row["body_sha256"]
        if index == 2283:
            assert result["decompile_completed"] and result["fragment_c_like"].strip() and not result["error"]
            rendered = (REPORT / "fragment_2283_synthetic.c").read_bytes()
            # The readable copy has a provenance header and Windows text-mode CRCRLF expansion.
            normalized = rendered.replace(bytes((13, 13, 10)), bytes((13, 10)))
            assert result["fragment_c_like"].encode() in normalized
        else:
            assert not result["decompile_completed"] and not result["fragment_c_like"].strip()
            assert "Unable to find unique hash for varnode" in result["error"]
    assert len(all_decoded) == verified["original_instruction_rows_fully_redecoded"] == 242
    samples = verified["ordinary_spread_sample"]
    assert len(samples) == verified["ordinary_spread_sample_count"] == 27 >= math.ceil(len(all_decoded)*.1)
    assert len({s["global_ordinal"] for s in samples}) == len(samples)
    assert samples[0]["global_ordinal"] == 0 and samples[-1]["global_ordinal"] == len(all_decoded)-1
    for sample in samples:
        index, ordinal, ins = all_decoded[sample["global_ordinal"]]
        assert sample["target_index"] == index and sample["target_ordinal"] == ordinal
        assert int(sample["elf_va"], 16) == ins.address
        assert sample["direct_redecoded_assembly"] == f"0x{ins.address:x}: {ins.mnemonic} {ins.op_str}".strip()
        assert sample["stored_assembly_exact_match"]

    project = read(REPORT / "project_copy_manifest.json")
    assert project["file_count"] == len(project["files"]) == 9
    source_project, owned_copy = Path(project["historical_project"]), Path(project["owned_copy"])
    for row in project["files"]:
        path = source_project / row["relative_path"]
        copy = owned_copy / row["relative_path"]
        assert path.stat().st_size == row["size_bytes"] and sha(path) == row["sha256"]
        assert copy.is_file() and sha(copy) == row["sha256"]
    print(json.dumps({"task":"TASK_181", "result":"PASS", "seal_sha256":sha(REPORT/"COMPLETE.json"),
                      "original_instructions":len(all_decoded), "spread":len(samples),
                      "synthetic_fragments_with_c_like":1, "whole_original_c_like":0},sort_keys=True))


if __name__ == "__main__":
    main()
