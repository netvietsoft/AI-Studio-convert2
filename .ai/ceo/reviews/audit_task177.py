"""Independent read-only audit of TASK_177's 229 original SO export bodies."""

import hashlib
import json
import math
import re
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_177_REPORT_R1"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
TASK = ROOT / "RULES/TASK/TASK_177_SO45_CODEX_GAP_RECOVERY_ACTIVE.md"
GAPS = {("libMTGif.so", "0xa1f0"), ("libMTGif.so", "0xaf70")}
ALIASES = {("b.cc", "b.lo"), ("b.cs", "b.hs"), ("orr", "mov"),
           ("dup", "mov"), ("bfm", "bfi"), ("negs", "cmp")}


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read(path):
    return json.loads(path.read_text(encoding="utf-8"))


def main():
    seal_path = REPORT / "COMPLETE.json"
    seal_sha = digest(seal_path)
    seal = read(seal_path)
    task_text = TASK.read_text(encoding="utf-8")
    task = json.loads(re.search(r"```json\s*(\{.*?\})\s*```", task_text, re.S).group(1))
    standard = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
    assert seal["task_id"] == "TASK_177" and seal["revision"] == 1 and seal["status"] == "COMPLETE"
    assert seal["task_sha256"] == digest(TASK)
    assert seal["standard_sha256"] == digest(standard)
    assert (seal["original_export_vas"], seal["source_pt_load_bodies_verified"],
            seal["fresh_ghidra_memory_bodies_verified"], seal["historical_c_like_bodies_revalidated"],
            seal["fresh_imports"], seal["fresh_decompilations"]) == (229, 229, 229, 227, 0, 0)
    assert {(x["library"], x["elf_va"]) for x in seal["unresolved_c_like_bodies"]} == GAPS
    actual_report = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json"}
    assert set(seal["files"]) == actual_report
    for rel, expected in seal["files"].items():
        assert digest(REPORT / rel) == expected, rel
    for key in ("code_files", "scratch_files"):
        for rel, expected in seal[key].items():
            assert digest(ROOT / rel) == expected, rel
    audit_index = (REPORT / "00_AUDIT_INDEX.md").read_text(encoding="utf-8").lower()
    assert seal["standard_sha256"] in audit_index and seal["task_sha256"] in audit_index
    batch = read(REPORT / "source_batch_index.json")
    run = read(REPORT / "memory_run_receipt.json")
    assert run["status"] == "OUTPUT_READY" and len(run["libraries"]) == 11
    total = {"bodies": 0, "c_like": 0, "bytes": 0, "instruction_pcs": 0,
             "direct_targets": 0, "indirect_calls": 0, "sample": 0}
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    for lib, spec in task["source_libraries"].items():
        source = SOURCE / lib
        assert digest(source) == spec["sha256"]
        folder = REPORT / lib
        source_index = read(folder / "source_index.json")
        old_index = read(folder / "historical_target_index.json")
        old_raw = read(folder / "historical_ghidra_raw.json")
        old_cmd = read(folder / "historical_ghidra_command.json")
        fresh = read(folder / "fresh_memory_raw.json")
        fresh_cmd = read(folder / "fresh_memory_command.json")
        verified = read(folder / "independent_verification.json")
        count = spec["expected_unique_export_vas"]
        assert len(source_index["targets"]) == len(old_index["targets"]) == len(old_raw["targets"]) == len(fresh["targets"]) == count
        assert source_index["original_unique_export_vas"] == fresh["target_count"] == count
        assert fresh["fresh_imports"] == fresh["fresh_decompilations"] == 0
        assert old_cmd["status"] == fresh_cmd["status"] == "OUTPUT_READY"
        assert old_cmd["exit_code"] == fresh_cmd["exit_code"] == 0
        assert "-readOnly" in fresh_cmd["command"] and "-noanalysis" in fresh_cmd["command"]
        assert "-import" not in fresh_cmd["command"]
        assert "VerifyMemory177.java" in fresh_cmd["command"]
        for prefix, command in (("historical_ghidra", old_cmd), ("fresh_memory", fresh_cmd)):
            assert command["result_sha256"] == digest(folder / f"{prefix}_raw.json")
            assert command["stdout_sha256"] == digest(folder / f"{prefix}_stdout.log")
            assert command["stderr_sha256"] == digest(folder / f"{prefix}_stderr.log")
        historical_task = source_index["historical_task_id"]
        assert historical_task in ("TASK_149", "TASK_153")
        old_folder = ROOT / f"RULES/REPORT/{historical_task}_REPORT_R1" / lib
        for filename in ("target_index.json", "targets.tsv", "ghidra_raw.json",
                         "ghidra_command.json", "ghidra_stdout.log", "ghidra_stderr.log"):
            assert digest(folder / ("historical_" + filename)) == digest(old_folder / filename)
        with source.open("rb") as stream:
            elf = ELFFile(stream)
            assert elf["e_machine"] == "EM_AARCH64"
            by_va = {}
            for sym in elf.get_section_by_name(".dynsym").iter_symbols():
                if (sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF" and
                        int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0):
                    by_va.setdefault(int(sym["st_value"]), []).append((sym.name, int(sym["st_size"])))
            loads = [seg for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"]
        assert len(by_va) == count
        raw = source.read_bytes()
        base = int(fresh["image_base"], 16)
        take = math.ceil(count * .12)
        sample_indices = ({1} if take == 1 else
                          {1 + round(k * (count - 1) / (take - 1)) for k in range(take)})
        evidence_rows = []
        sample_rows = []
        local = {"bodies": 0, "c_like": 0, "bytes": 0, "instruction_pcs": 0,
                 "direct_targets": 0, "indirect_calls": 0}
        for index, va in enumerate(sorted(by_va), 1):
            aliases = [n for n, _ in sorted(by_va[va], key=lambda x: (-x[1], x[0]))]
            symbol, size = sorted(by_va[va], key=lambda x: (-x[1], x[0]))[0]
            offsets = [int(x["p_offset"]) + va - int(x["p_vaddr"]) for x in loads
                       if int(x["p_vaddr"]) <= va and va + size <= int(x["p_vaddr"]) + int(x["p_filesz"])]
            assert len(offsets) == 1
            body = raw[offsets[0]:offsets[0] + size]
            body_sha = hashlib.sha256(body).hexdigest()
            srow, irow, hrow, frow = (source_index["targets"][index - 1],
                                     old_index["targets"][index - 1], old_raw["targets"][index - 1],
                                     fresh["targets"][index - 1])
            assert srow["index"] == irow["index"] == hrow["index"] == frow["index"] == index
            assert srow["elf_va"] == irow["elf_va"] == hrow["elf_va"] == frow["elf_va"] == f"0x{va:x}"
            assert srow["symbol"] == irow["symbol"] == hrow["symbol"] == frow["symbol"] == symbol
            assert srow["aliases"] == irow["aliases"] == aliases
            assert srow["size_bytes"] == irow["size_bytes"] == hrow["size_bytes"] == frow["size_bytes"] == size
            assert int(srow["file_offset"], 16) == int(irow["file_offset"], 16) == offsets[0]
            assert srow["source_body_sha256"] == irow["source_body_sha256"] == hrow["expected_source_sha256"] == body_sha
            assert hrow["ghidra_memory_sha256"] == frow["ghidra_memory_sha256"] == body_sha
            assert hrow["source_bytes_match"] is frow["source_bytes_match"] is frow["function_present"] is True
            assert int(hrow["database_va"], 16) == int(frow["database_va"], 16) == base + va
            c_text = hrow["pseudocode"]
            has_c = bool(c_text.strip())
            assert has_c == srow["historical_c_like_nonempty"]
            if has_c:
                assert hrow["decompile_success"] is True and not hrow["error"]
                assert hashlib.sha256(c_text.encode()).hexdigest() == srow["historical_c_like_sha256"]
                local["c_like"] += 1
            else:
                assert (lib, f"0x{va:x}") in GAPS
                assert "Unable to find unique hash for varnode" in hrow["error"]
            decoded = {ins.address: ins for ins in decoder.disasm(body, base + va)}
            assert len(decoded) * 4 == len(body)
            assert len(hrow["instructions"]) == hrow["instruction_count_observed"] == frow["instruction_starts"]
            prev = 0
            for line in hrow["instructions"]:
                match = re.match(r"^([0-9a-fA-F]+):\s+(\S+)", line)
                assert match is not None
                pc, mnemonic = int(match.group(1), 16), match.group(2).lower()
                assert pc in decoded and pc > prev
                prev = pc
                cap_mnemonic = decoded[pc].mnemonic.lower()
                assert mnemonic == cap_mnemonic or (mnemonic, cap_mnemonic) in ALIASES
                local["instruction_pcs"] += 1
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
            local["direct_targets"] += direct
            local["indirect_calls"] += indirect
            local["bytes"] += len(body)
            local["bodies"] += 1
            evidence_rows.append({"index": index, "elf_va": f"0x{va:x}", "symbol": symbol,
                                  "source_body_sha256": body_sha,
                                  "fresh_ghidra_memory_sha256": frow["ghidra_memory_sha256"],
                                  "historical_c_like_sha256": hashlib.sha256(c_text.encode()).hexdigest() if has_c else None,
                                  "historical_instruction_rows": len(hrow["instructions"]),
                                  "fresh_instruction_starts": frow["instruction_starts"]})
            if index in sample_indices:
                sample_rows.append({"index": index, "elf_va": f"0x{va:x}", "symbol": symbol,
                                    "source_body_sha256": body_sha,
                                    "fresh_ghidra_memory_sha256": frow["ghidra_memory_sha256"],
                                    "historical_c_like_sha256": hashlib.sha256(c_text.encode()).hexdigest() if has_c else None,
                                    "historical_instruction_rows": len(hrow["instructions"]),
                                    "fresh_instruction_starts": frow["instruction_starts"],
                                    "original_capstone_decoded_instructions": len(decoded),
                                    "historical_call_rows": direct + indirect})
        checks = verified["all_critical_checks"]
        assert evidence_rows == verified["all_export_evidence_rows"], (lib, next(((a,b) for a,b in zip(evidence_rows,verified["all_export_evidence_rows"]) if a!=b), None))
        assert sample_rows == verified["ordinary_spread_sample"], (lib, [x["index"] for x in sample_rows], [x["index"] for x in verified["ordinary_spread_sample"]], sample_rows[0], verified["ordinary_spread_sample"][0])
        assert len(sample_rows) >= math.ceil(.1 * count)
        assert (local["bodies"], local["bodies"], local["c_like"], local["bytes"],
                local["instruction_pcs"], local["direct_targets"], local["indirect_calls"]) == (
                checks["original_pt_load_body_hashes_cross_checked"],
                checks["fresh_ghidra_memory_body_hashes_cross_checked"],
                checks["historical_c_like_bodies_revalidated"],
                checks["original_function_bytes_cross_checked"],
                checks["historical_instruction_pcs_cross_checked"],
                checks["direct_branch_call_targets_cross_checked"],
                checks["indirect_calls_cross_checked"])
        assert fresh["body_bytes_hashed"] == local["bytes"]
        total["sample"] += len(sample_rows)
        for key in local:
            total[key] += local[key]
    assert total["bodies"] == 229 and total["c_like"] == 227
    assert total["sample"] >= math.ceil(.1 * 229)
    assert digest(seal_path) == seal_sha
    print(json.dumps({"result": "PASS", "task": "TASK_177", "seal_sha256": seal_sha,
                      "manifest_files": len(actual_report), "code_files": len(seal["code_files"]),
                      "scratch_files": len(seal["scratch_files"]), **total}, sort_keys=True))


if __name__ == "__main__":
    main()
