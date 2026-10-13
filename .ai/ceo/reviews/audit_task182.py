"""Read-only CEO audit of TASK_182's WebP SIMD research evidence."""
import hashlib
import json
import math
import re
from collections import Counter
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_182_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_182_SO45_CODEX_CORRECTION_ACTIVE.md"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libglide-webp.so")


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def main():
    task_text = TASK.read_text(encoding="utf-8")
    task = json.loads(re.search(r"```json\s*(\{.*?\})\s*```", task_text, re.S).group(1))
    seal = read(REPORT / "COMPLETE.json")
    assert seal["task_id"] == "TASK_182" and seal["revision"] == 1 and seal["status"] == "COMPLETE"
    assert seal["semantic_disposition"] == "PARTIAL_SIMD_SOURCE_RECOVERY_NO_C_LIKE"
    assert not seal["new_ghidra_vector_c_like"] and not seal["whole_original_c_like"]
    assert not seal["behavior_verified"] and not seal["phase_pass"]
    assert sha(TASK) == seal["task_sha256"]
    assert sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == seal["standard_sha256"]
    assert sha(SOURCE) == seal["source_sha256"] == task["source_libraries"]["libglide-webp.so"]["sha256"]
    assert seal["lease_id"] == task["expected_lease_id"]
    assert set(seal["files"]) == {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*")
                                   if p.is_file() and p.name not in {"COMPLETE.json", "PROGRESS.json"}}
    for relative, expected in seal["files"].items():
        assert sha(REPORT / relative) == expected, relative
    for key in ("code_files", "research_files"):
        assert all(isinstance(k, str) and isinstance(v, str) for k, v in seal[key].items())
        for relative, expected in seal[key].items():
            assert sha(ROOT / relative) == expected, relative
    index = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    assert seal["standard_sha256"] in index and seal["task_sha256"] in index

    target = task["target_exports"][0]
    start, size = int(target["elf_va"], 16), target["size_bytes"]
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf["e_machine"] == "EM_AARCH64"
        syms = [sym for sym in elf.get_section_by_name(".dynsym").iter_symbols()
                if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF"
                and int(sym["st_value"]) > 0 and int(sym["st_size"]) > 0]
        assert len({int(sym["st_value"]) for sym in syms}) == 230
        assert len([sym for sym in syms if sym.name == target["symbol"]
                    and int(sym["st_value"]) == start and int(sym["st_size"]) == size]) == 1
        loads = [seg for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"]
    mappings = [(int(seg["p_offset"]) + start - int(seg["p_vaddr"]), int(seg["p_vaddr"]), int(seg["p_offset"]))
                for seg in loads if int(seg["p_vaddr"]) <= start
                and start + size <= int(seg["p_vaddr"]) + int(seg["p_filesz"])]
    assert len(mappings) == 1
    offset, load_va, load_offset = mappings[0]
    body = SOURCE.read_bytes()[offset:offset+size]
    assert len(body) == 624 and hashlib.sha256(body).hexdigest() == seal["body_sha256"] == target["source_body_sha256"]
    assert (REPORT / "source_body.bin").read_bytes() == body
    evidence = read(REPORT / "vector_source_evidence.json")
    assert (evidence["pt_load_vaddr"], evidence["pt_load_file_offset"]) == (hex(load_va), hex(load_offset))
    assert evidence["source_body_sha256"] == seal["body_sha256"]
    lo, hi = int(evidence["simd_start_va"], 16), int(evidence["simd_end_exclusive_va"], 16)
    assert (lo, hi) == (0x3294c, 0x32ab4) and lo >= start and hi <= start + size
    rows = evidence["rows"]
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    instructions = list(decoder.disasm(body[lo-start:hi-start], lo))
    assert len(rows) == len(instructions) == evidence["simd_instruction_count"] == seal["simd_source_instruction_count"] == 90
    historical = read(REPORT / "historical_raw/TASK_179_instruction_evidence.json")
    historical_by_va = {int(row["elf_va"], 16): row for row in historical["rows"]}
    assert sha(REPORT / "historical_raw/TASK_179_instruction_evidence.json") == sha(ROOT / "RULES/REPORT/TASK_179_REPORT_R1/instruction_evidence.json")
    for i, (row, ins) in enumerate(zip(rows, instructions)):
        va = lo + i*4
        assert int(row["elf_va"], 16) == ins.address == va
        assert int(row["file_offset"], 16) == offset + va - start
        assert row["source_word_hex_le"] == body[va-start:va-start+4].hex()
        assert row["capstone"] == (ins.mnemonic + " " + ins.op_str).strip()
        old = historical_by_va[va]
        assert old["source_word_hex"] == row["source_word_hex_le"]
        assert old["historical_ghidra"] == row["historical_ghidra"]
        assert old["historical_pcode_ops"] == row["historical_pcode_ops"]
    prior = read(REPORT / "historical_raw/TASK_175_normalize_raw.json")
    assert sha(REPORT / "historical_raw/TASK_175_normalize_raw.json") == sha(ROOT / "RULES/REPORT/TASK_179_REPORT_R1/historical_TASK_175_normalize_raw.json")
    pcodes = [op for op in prior["pcode"] if lo <= int(op.split(":", 1)[0], 16) - 0x100000 < hi]
    text = (REPORT / "historical_vector_pcode.txt").read_text(encoding="utf-8").splitlines()
    assert text == pcodes and len(pcodes) == sum(row["historical_pcode_ops"] for row in rows) == 999
    counts = Counter(int(op.split(":", 1)[0], 16) - 0x100000 for op in pcodes)
    assert all(counts[int(row["elf_va"], 16)] == row["historical_pcode_ops"] for row in rows)

    landmarks = read(REPORT / "simd_landmark_verification.json")
    expected = landmarks["key_instruction_landmarks"]
    assert len(expected) == landmarks["key_instruction_landmarks_verified"] == seal["critical_instruction_landmarks"] == 23
    actual = {row["elf_va"]: row["capstone"] for row in rows}
    assert all(actual[va] == asm for va, asm in expected.items())
    sample = landmarks["spread_samples"]
    assert len(sample) == landmarks["spread_sample_count"] == seal["spread_source_words"] == 10
    assert len({row["index"] for row in sample}) == len(sample) >= math.ceil(.1*len(rows))
    assert sample[0]["index"] == 0 and sample[-1]["index"] == len(rows)-1
    for entry in sample:
        row = rows[entry["index"]]
        assert entry["elf_va"] == row["elf_va"]
        assert entry["source_word_hex_le"] == row["source_word_hex_le"]
        assert entry["capstone"] == row["capstone"]

    command = read(REPORT / "vector_probe_command.json")
    output = read(REPORT / "vector_probe_raw.json")
    assert command["script_sha256"] == sha(ROOT / "scripts/task_182_codex_exports/VectorProbe182.java")
    assert command["source_sha256"] == seal["source_sha256"] and command["body_sha256"] == seal["body_sha256"]
    assert command["result_sha256"] == sha(REPORT / "vector_probe_raw.json")
    assert command["stdout_sha256"] == sha(REPORT / "vector_probe_stdout.log")
    assert command["stderr_sha256"] == sha(REPORT / "vector_probe_stderr.log")
    assert command["status"] == "OUTPUT_READY" and command["exit_code"] == 0 and not command["timed_out"]
    assert command["elapsed_seconds"] <= 180 and command["timeout_seconds"] == 180
    assert command["max_cpu"] == 1 and command["max_heap"] == "1G" and command["fresh_imports"] == 0
    args = command["command"]
    assert "-process" in args and "-noanalysis" in args and "-readOnly" in args and "-max-cpu" in args
    assert "-import" not in args and "VectorProbe182.java" in args
    assert args[args.index("-max-cpu")+1] == "1"
    assert output["copied_project_memory_sha256"] == seal["body_sha256"]
    assert output["vector_instruction_count"] == 90 and output["vector_pcode_ops"] == 999
    assert output["synthetic_metadata_only"] and not output["whole_original_function_decompiled"]
    assert not output["entry_register_state_proven"] and not output["decompile_completed"]
    assert not output["vector_fragment_c_like_nonempty"] and not output["vector_fragment_c_like"].strip()
    assert "Unable to find unique hash for varnode" in output["error"]
    assert output["error"] == landmarks["new_vector_probe_error"]
    assert "vector-only completed=false c_like=false" in (REPORT / "vector_probe_stdout.log").read_text(encoding="utf-8", errors="replace")
    receipt = read(REPORT / "project_copy_receipt.json")
    before = command["source_project_files_sha256_before"]
    assert before == command["copied_project_files_sha256_before"] == command["source_project_files_sha256_after"]
    source_project = Path(receipt["source_project"])
    assert {p.relative_to(source_project).as_posix():sha(p) for p in source_project.rglob("*") if p.is_file()} == before
    copied_after = command["copied_project_files_sha256_after"]
    assert copied_after["SmallLib155.rep/idata/00/~00000000.db/db.1.gbf"] == before["SmallLib155.rep/idata/00/~00000000.db/db.1.gbf"]
    assert command["historical_project_unchanged"] and receipt["all_file_sha256_equal_before_pass"]
    print(json.dumps({"task": "TASK_182", "result": "PASS", "seal_sha256": sha(REPORT / "COMPLETE.json"),
                      "simd_instructions": len(rows), "historical_pcode_ops": len(pcodes),
                      "critical_landmarks": len(expected), "spread": len(sample), "new_c_like": False}, sort_keys=True))


if __name__ == "__main__":
    main()
