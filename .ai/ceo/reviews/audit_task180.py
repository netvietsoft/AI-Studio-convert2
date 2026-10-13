"""Read-only CEO audit of TASK_180's two MTGif fragment experiments."""
import hashlib
import json
import math
import re
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_180_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_180_SO45_CODEX_CORRECTION_ACTIVE.md"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libMTGif.so")
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def main():
    task = read_json_block(TASK)
    seal = read(REPORT / "COMPLETE.json")
    index = read(REPORT / "source_and_project_index.json")
    run = read(REPORT / "run_receipt.json")
    assert seal["task_id"] == "TASK_180" and seal["revision"] == 1 and seal["status"] == "COMPLETE"
    assert seal["research_result"] == "PARTIAL_TWO_FRAGMENTS_NO_WHOLE_C_LIKE"
    assert seal["whole_original_c_like_recovered"] == 0 and seal["synthetic_c_like_fragments"] == 2
    assert digest(TASK) == seal["task_sha256"] == index["task_sha256"]
    assert digest(STANDARD) == seal["standard_sha256"] == index["standard_sha256"]
    assert digest(SOURCE) == seal["original_so_sha256"] == index["source_sha256"]
    assert task["expected_lease_id"] == seal["lease_id"] == index["lease_id"]
    assert task["assignee"] == seal["agent_id"] == index["actor"]
    assert set(seal["files"]) == {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*")
                                   if p.is_file() and p.name not in {"COMPLETE.json", "PROGRESS.json"}}
    for relative, expected in seal["files"].items():
        assert digest(REPORT / relative) == expected, relative
    for key in ("code_files", "scratch_files"):
        assert all(isinstance(k, str) and isinstance(v, str) for k, v in seal[key].items())
        for relative, expected in seal[key].items():
            assert digest(ROOT / relative) == expected, relative
    audit = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    assert seal["standard_sha256"] in audit and seal["task_sha256"] in audit

    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf["e_machine"] == "EM_AARCH64"
        loads = [segment for segment in elf.iter_segments() if segment["p_type"] == "PT_LOAD"]
        syms = [sym for sym in elf.get_section_by_name(".dynsym").iter_symbols()
                if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF"
                and int(sym["st_value"]) > 0 and int(sym["st_size"]) > 0]
    assert len({int(sym["st_value"]) for sym in syms}) == 104
    raw_source = SOURCE.read_bytes()
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    total_instructions = total_pcode = total_spread = 0
    for i, target in enumerate(task["target_exports"], 1):
        va, size = int(target["elf_va"], 16), target["size_bytes"]
        matches = [sym for sym in syms if sym.name == target["symbol"]
                   and int(sym["st_value"]) == va and int(sym["st_size"]) == size]
        assert len(matches) == 1
        offsets = [int(seg["p_offset"]) + va - int(seg["p_vaddr"]) for seg in loads
                   if int(seg["p_vaddr"]) <= va and va + size <= int(seg["p_vaddr"]) + int(seg["p_filesz"])]
        assert len(offsets) == 1
        body = raw_source[offsets[0]:offsets[0] + size]
        body_sha = hashlib.sha256(body).hexdigest()
        assert body_sha == target["source_body_sha256"]
        cfg = read(REPORT / f"target_{i}_source_cfg.json")
        verified = read(REPORT / f"target_{i}_independent_verification.json")
        command = read(REPORT / f"target_{i}/ghidra_command.json")
        output = read(REPORT / f"target_{i}/ghidra_pcode_fragment_raw.json")
        assert cfg["pt_load_file_offset"] == verified["pt_load_file_offset"] == f"0x{offsets[0]:x}"
        assert cfg["source_body_sha256"] == verified["source_body_sha256"] == output["ghidra_original_memory_sha256"] == body_sha
        assert output["memory_unchanged_after_rollback"] is True
        assert command["source_body_sha256"] == body_sha
        assert command["script_sha256"] == digest(ROOT / "scripts/task_180_codex_exports/ExtractPcodeFragment180.java")
        assert command["result_sha256"] == digest(REPORT / f"target_{i}/ghidra_pcode_fragment_raw.json")
        assert command["stdout_sha256"] == digest(REPORT / f"target_{i}/ghidra_stdout.log")
        assert command["stderr_sha256"] == digest(REPORT / f"target_{i}/ghidra_stderr.log")
        assert command["status"] == "OUTPUT_READY" and command["exit_code"] == 0
        assert command["elapsed_seconds"] <= 180 and command["cpu_cap"] == 1 and command["heap_cap"] == "1G"
        args = command["command"]
        assert "-readOnly" in args and "-noanalysis" in args and "-max-cpu" in args
        assert "-import" not in args and args.count("ExtractPcodeFragment180.java") == 1
        assert args[args.index("-max-cpu") + 1] == "1"
        assert len(run["targets"]) == 2 and run["targets"][i-1]["exit_code"] == 0
        stdout = (REPORT / f"target_{i}/ghidra_stdout.log").read_text(encoding="utf-8", errors="replace")
        assert f"[TASK_180] target={i}" in stdout and "fragment_c=true" in stdout
        base = int(output["database_va"], 16) - va
        decoded = list(decoder.disasm(body, va + base))
        assert len(decoded) == size // 4 == output["original_instruction_count"] == verified["original_capstone_instruction_count"]
        pcodes = output["original_instruction_pcode"]
        assert len(pcodes) == len(decoded) == verified["original_ghidra_pcode_instruction_count"]
        assert all(int(row["database_va"], 16) == ins.address
                   and row["assembly"].split()[0].lower() == ins.mnemonic.lower()
                   and row["pcode_ops"] for row, ins in zip(pcodes, decoded))
        n_pcode = sum(len(row["pcode_ops"]) for row in pcodes)
        assert n_pcode == output["original_pcode_operation_count"] == verified["original_ghidra_pcode_operation_count"]
        by_pc = {ins.address: ins for ins in decoded}
        cfg_pc = []
        assert len(cfg["blocks"]) == cfg["block_count"] == verified["source_cfg_block_count"]
        for block in cfg["blocks"]:
            assert len(block["raw_assembly"]) == block["instruction_count"]
            assert int(block["start"], 16) == int(block["raw_assembly"][0].split(":", 1)[0], 16)
            for line in block["raw_assembly"]:
                pc = int(line.split(":", 1)[0], 16)
                assert pc in by_pc and line.split(":", 1)[1].strip().split()[0].lower() == by_pc[pc].mnemonic.lower()
                cfg_pc.append(pc)
        assert sorted(cfg_pc) == sorted(by_pc) and len(set(cfg_pc)) == len(decoded)
        fragment = output["synthetic_fragment"]
        proof = verified["fragment_only"]
        start, end = int(fragment["elf_start"], 16), int(fragment["elf_end_inclusive"], 16)
        assert va < start <= end < va + size
        assert command["fragment_elf_start"] == fragment["elf_start"] == proof["elf_start"]
        assert command["fragment_elf_end_inclusive"] == fragment["elf_end_inclusive"] == proof["elf_end_inclusive"]
        assert fragment["function_created"] and fragment["decompile_success"] and not fragment["error"]
        c_text = fragment["c_like_fragment_only"]
        assert c_text.strip() and "task180_scalar_fragment_" in c_text
        assert hashlib.sha256(c_text.encode()).hexdigest() == proof["c_like_fragment_sha256"]
        assert len(c_text) == proof["c_like_fragment_chars"]
        frag_bytes = body[start-va:end-va+4]
        assert len(frag_bytes) == proof["source_fragment_bytes"]
        assert hashlib.sha256(frag_bytes).hexdigest() == proof["source_fragment_sha256"]
        assert proof["whole_original_c_like_recovered"] is False
        samples = verified["ordinary_spread_sample"]
        assert len(samples) == verified["ordinary_spread_sample_count"] >= math.ceil(len(decoded)*.1)
        assert len({sample["source_instruction_ordinal"] for sample in samples}) == len(samples)
        assert min(s["source_instruction_ordinal"] for s in samples) == 1
        assert max(s["source_instruction_ordinal"] for s in samples) == len(decoded)
        for sample in samples:
            ordinal = sample["source_instruction_ordinal"]
            row, ins = pcodes[ordinal-1], decoded[ordinal-1]
            word = body[4*(ordinal-1):4*ordinal]
            assert sample["database_va"] == row["database_va"]
            assert sample["source_instruction_word_sha256"] == hashlib.sha256(word).hexdigest()
            assert sample["source_mnemonic"] == ins.mnemonic
            assert sample["ghidra_pcode_ops"] == len(row["pcode_ops"])
            assert sample["ghidra_pcode_sha256"] == hashlib.sha256("\n".join(row["pcode_ops"]).encode()).hexdigest()
        total_instructions += len(decoded)
        total_pcode += n_pcode
        total_spread += len(samples)
    assert (total_instructions, total_pcode, total_spread) == (522, 3841, 64)
    assert seal["original_source_instruction_positions_verified"] == total_instructions
    assert seal["original_pcode_operations"] == total_pcode
    assert seal["ordinary_spread_instruction_sample_count"] == total_spread
    history = read(REPORT / "historical_failure_receipt.json")
    prior153 = ROOT / "RULES/REPORT/TASK_153_REPORT_R1/libMTGif.so"
    prior154 = ROOT / "RULES/REPORT/TASK_154_REPORT_R1"
    prior177 = ROOT / "RULES/REPORT/TASK_177_REPORT_R1/libMTGif.so"
    assert digest(prior153 / "ghidra_raw.json") == history["TASK_153_raw_sha256"]
    assert digest(prior154 / "ghidra_raw.json") == history["TASK_154_raw_sha256"]
    assert digest(prior177 / "independent_verification.json") == history["TASK_177_verification_sha256"]
    for prior_dir, prefix in ((prior153, "TASK_153"), (prior154, "TASK_154")):
        for filename, key in (("ghidra_command.json", "command"),
                              ("ghidra_stdout.log", "stdout"), ("ghidra_stderr.log", "stderr")):
            assert digest(prior_dir / filename) == history[f"{prefix}_{key}_sha256"]
    old153 = read(prior153 / "ghidra_raw.json")
    old154 = read(prior154 / "ghidra_raw.json")
    assert len(history["exact_failure_rows"]) == 2
    for item in history["exact_failure_rows"]:
        target = item["target"]
        old = [r for r in old153["targets"] if r["elf_va"] == target["elf_va"]]
        normal = [r for r in old154["targets"] if r["elf_va"] == target["elf_va"]]
        assert old == [item["TASK_153_raw"]] and normal == [item["TASK_154_normalize_raw"]]
        assert not old[0]["decompile_success"] and not old[0]["pseudocode"].strip()
        assert "Unable to find unique hash for varnode" in old[0]["error"]
        assert not normal[0]["pseudocode"].strip()
    for copy in index["analyzed_project_copies"].values():
        source_project = Path(copy["source_project"])
        copied_project = Path(copy["project_dir"])
        assert source_project == ROOT / "RESEARCH_WORK/TASK_153_R1/libMTGif.so/ghidra_project"
        for row in copy["files"]:
            rel = row["relative_path"]
            source_file = source_project / rel
            assert source_file.stat().st_size == row["bytes"] and digest(source_file) == row["sha256"]
            if not rel.endswith(("/idata/~index.bak", "/idata/~journal.bak")):
                assert digest(copied_project / rel) == row["sha256"]
    print(json.dumps({"task": "TASK_180", "result": "PASS", "seal_sha256": digest(REPORT / "COMPLETE.json"),
                      "original_bodies": 2, "instructions": total_instructions, "pcode_ops": total_pcode,
                      "spread": total_spread, "synthetic_fragments_only": 2}, sort_keys=True))


def read_json_block(path):
    match = re.search(r"```json\s*(\{.*?\})\s*```", path.read_text(encoding="utf-8"), re.S)
    assert match is not None
    return json.loads(match.group(1))


if __name__ == "__main__":
    main()
