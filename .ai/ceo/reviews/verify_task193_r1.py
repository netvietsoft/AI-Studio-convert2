"""Independent CEO audit of TASK_193 sealed static extraction against original ELF."""

import hashlib
import json
import math
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_193_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_193_SO45_CODEX_INTERNAL_ACTIVE.md"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_193_internal_targets.json"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libMTFilterKernel.so")
PRIOR = ROOT / "RESEARCH_WORK/TASK_189_R1/ghidra_project"
PRIVATE = ROOT / "RESEARCH_WORK/TASK_193_R1/ghidra_project"
GAPS = {198, 199, 200}
EXCLUDED = {201, 211, 216, 235}
ALIASES = {("b.hs", "b.cs"), ("b.lo", "b.cc"), ("mov", "orr"),
           ("orr", "mov"), ("mov", "dup"), ("bfi", "bfm"),
           ("ushll2", "uxtl2"), ("ushll", "uxtl")}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def obj(path):
    return json.loads(path.read_text(encoding="utf8"))


def files(folder):
    return {p.relative_to(folder).as_posix(): sha(p) for p in folder.rglob("*") if p.is_file()}


def missing_ranges(bits):
    out, start = [], None
    for offset, bit in enumerate(bits + "1"):
        if bit == "0" and start is None:
            start = offset
        elif bit == "1" and start is not None:
            out.append({"start_offset": start, "end_exclusive": offset})
            start = None
    return out


def main():
    seal, verification = obj(REPORT / "COMPLETE.json"), obj(REPORT / "WORKER_VERIFICATION.json")
    manifest, index = obj(MANIFEST), obj(REPORT / "source_project_index.json")
    assert (seal["task_id"], seal["revision"], seal["status"]) == ("TASK_193", 1, "COMPLETE")
    assert sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == seal["standard_sha256"]
    assert sha(TASK) == seal["task_sha256"] and sha(MANIFEST) == seal["target_manifest_sha256"]
    assert sha(SOURCE) == seal["original_so_sha256"] == index["source_sha256"]
    report_files = files(REPORT)
    for excluded in ("COMPLETE.json", "PROGRESS.json", "PROGRESS.md"):
        report_files.pop(excluded, None)
    assert report_files == seal["files"] and len(report_files) == 143
    assert {path: sha(ROOT / path) for path in seal["code_files"]} == seal["code_files"]
    assert len(seal["code_files"]) == 10
    assert {path: sha(ROOT / path) for path in seal["scratch_files"]} == seal["scratch_files"]
    assert len(seal["scratch_files"]) == 12
    prior_hash, private_hash = files(PRIOR), files(PRIVATE)
    expected_project = {row["relative_path"]: row["sha256"] for row in index["project_files"]}
    assert len(expected_project) == 9 and prior_hash == private_hash == expected_project

    for name, count in (("ghidra_batch1", 30), ("ghidra_batch2", 30),
                        ("ghidra_correction", 3), ("ghidra_postrollback", 3)):
        receipt = obj(REPORT / f"{name}_command.json")
        assert receipt["status"] == "OUTPUT_READY" and receipt["exit_code"] == 0
        assert receipt["raw_result_files"] == count and len(receipt["raw_result_hashes"]) == count
        assert receipt["elapsed_seconds"] <= receipt["max_process_seconds"] <= 1200
        assert receipt["max_cpu"] == 1 and receipt["max_heap"] == "1G"
        assert "-readOnly" in receipt["command"] and "-noanalysis" in receipt["command"]
        assert "-import" not in receipt["command"]
        assert receipt["stdout_sha256"] == sha(REPORT / f"{name}_stdout.log")
        assert receipt["stderr_sha256"] == sha(REPORT / f"{name}_stderr.log")
        folder = REPORT / ("ghidra_raw_batch1" if name == "ghidra_batch1" else
                           "ghidra_raw_batch2" if name == "ghidra_batch2" else
                           "ghidra_correction_raw" if name == "ghidra_correction" else
                           "ghidra_postrollback_raw")
        assert files(folder) == receipt["raw_result_hashes"]

    with SOURCE.open("rb") as handle:
        elf = ELFFile(handle)
        assert elf["e_machine"] == "EM_AARCH64"
        fdes = {(int(x["initial_location"]), int(x["address_range"]))
                for x in elf.get_dwarf_info().EH_CFI_entries()
                if isinstance(x, FDE) and int(x["address_range"]) > 0}
        exports = {int(x["st_value"]) for x in elf.get_section_by_name(".dynsym").iter_symbols()
                   if x["st_info"]["type"] == "STT_FUNC" and x["st_shndx"] != "SHN_UNDEF"
                   and int(x["st_value"]) > 0 and int(x["st_size"]) > 0}
        loads = [(int(x["p_vaddr"]), int(x["p_offset"]), int(x["p_filesz"]))
                 for x in elf.iter_segments() if x["p_type"] == "PT_LOAD"]
    selected = sorted((va, size) for va, size in fdes if va not in exports)
    assert (len(fdes), len(exports), len(selected)) == (manifest["all_fde_ranges"], 2362, 511)
    targets = manifest["targets"]
    expected = [(i, va, size) for i, (va, size) in enumerate(selected)
                if 192 <= i < 256 and i not in EXCLUDED]
    assert len(targets) == len(expected) == len(verification["rows"]) == 60
    assert [(t["global_nonexport_fde_index"], int(t["elf_va"], 16), t["size_bytes"])
            for t in targets] == expected
    assert len(index["selected_candidate_rows"]) == 60
    assert manifest["excluded_oversized_global_indices"] == sorted(EXCLUDED)
    assert sum(selected[i][1] for i in EXCLUDED) == 53328

    binary = SOURCE.read_bytes()
    cs = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    source_slots = original_slots = missing_slots = effective_slots = ops = full = 0
    samples_by_row = {}
    for sample in verification["ordinary_spread_samples"]:
        key = (sample["candidate_index"], sample["instruction_ordinal_zero_based"])
        assert key not in samples_by_row
        samples_by_row[key] = sample
    assert len(samples_by_row) == 1273
    direct_calls = indirect_calls = 0
    wrong_zero_labels = []
    for ordinal, target in enumerate(targets):
        number = target["global_nonexport_fde_index"]
        va, size, offset = int(target["elf_va"], 16), target["size_bytes"], int(target["file_offset"], 16)
        assert size % 4 == 0 and sum(base <= va and va + size <= base + length and
                                      offset == file_offset + va - base
                                      for base, file_offset, length in loads) == 1
        body = binary[offset:offset + size]
        digest = hashlib.sha256(body).hexdigest()
        assert len(body) == size and digest == target["body_sha256"]
        indexed = index["selected_candidate_rows"][ordinal]
        assert indexed["index"] == number and indexed["elf_va"] == target["elf_va"]
        assert indexed["selected_zero_index"] == number
        assert indexed["source_body_sha256"] == digest and not indexed["other_fde_overlap"]
        assert not indexed["export_body_overlap"]
        filename = f"{number:03d}_{va:x}.json"
        asm = obj(REPORT / "source_assembly" / filename)
        rawpath = REPORT / ("ghidra_raw_batch1" if ordinal < 30 else "ghidra_raw_batch2") / filename
        raw = obj(rawpath)
        summary = verification["rows"][ordinal]
        assert asm["index"] == raw["index"] == summary["index"] == number
        assert asm["selected_zero_index"] == number
        if summary["selected_zero_index"] != number:
            wrong_zero_labels.append(number)
        assert asm["source_body_sha256"] == raw["ghidra_memory_sha256"] == digest
        assert summary["original_pt_load_body_sha256"] == summary["copied_ghidra_memory_sha256"] == digest
        assert summary["raw_ghidra_sha256"] == sha(rawpath)
        decoded = list(cs.disasm(body, va))
        assert len(decoded) == len(asm["instructions"]) == len(raw["instruction_pcode"]) == size // 4
        direct = [ins for ins in decoded if ins.mnemonic == "bl"]
        indirect = [ins for ins in decoded if ins.mnemonic in
                    ("blr", "blraa", "blrab", "blraaz", "blrabz")]
        assert summary["source_direct_call_count"] == asm["source_direct_call_count"] == len(direct)
        assert summary["source_indirect_call_count"] == asm["source_indirect_call_count"] == len(indirect)
        assert summary["source_call_sites"] == asm["source_calls"] == indexed["source_calls"]
        direct_calls += len(direct)
        indirect_calls += len(indirect)
        bits = raw["fde_byte_membership_bits"]
        assert len(bits) == size and set(bits) <= {"0", "1"}
        assert bits.count("1") == raw["fde_byte_membership_count"] == summary["original_ghidra_body_membership_bytes"]
        assert missing_ranges(bits) == raw["fde_missing_body_ranges"] == summary["original_ghidra_body_missing_ranges"]
        assert raw["extra_body_address_count"] == raw["other_function_byte_count"] == 0
        assert not raw["extra_body_ranges"] and not summary["extra_body_ranges"]
        assert raw["function_body_total_address_count"] == bits.count("1")
        assert raw["missing_analyzed_instruction_count"] == size // 4 - raw["ghidra_instruction_count"]
        assert raw["decompile_elapsed_ms"] <= 10000 and raw["c_like_nonempty"] and raw["c_like_text"].strip()
        assert not raw["decompile_error"]
        if number in GAPS:
            correction = obj(REPORT / "ghidra_correction_raw" / filename)
            restored = obj(REPORT / "ghidra_postrollback_raw" / filename)
            assert bits.count("0") > 0 and raw["missing_analyzed_instruction_count"] > 0
            assert correction["memory_sha256"] == restored["memory_sha256"] == digest
            assert correction["original_function_fde_membership_bits"] == restored["body_bits"] == bits
            assert correction["corrected_function_fde_membership_bits"] == "1" * size
            assert correction["corrected_function_fde_membership_count"] == size
            assert correction["full_fde_instruction_count"] == size // 4
            assert correction["temporary_old_function_removed"] and correction["temporary_full_fde_function_created"]
            assert correction["memory_unchanged_after_rollback"] and correction["other_function_byte_count"] == 0
            assert restored["function_name"] == raw["function_name"]
            assert restored["function_start"] == raw["function_start"]
            assert restored["other_function_byte_count"] == 0
            assert correction["c_like_nonempty"] and correction["c_like_text"].strip() and not correction["error"]
            assert correction["decompile_elapsed_ms"] <= 10000
            effective = correction["instruction_pcode"]
            c_like = correction["c_like_text"]
            assert summary["corrective_ghidra_sha256"] == sha(REPORT / "ghidra_correction_raw" / filename)
            assert summary["fresh_postrollback_ghidra_sha256"] == sha(REPORT / "ghidra_postrollback_raw" / filename)
        else:
            assert bits == "1" * size and raw["missing_analyzed_instruction_count"] == 0
            effective, c_like = raw["instruction_pcode"], raw["c_like_text"]
            full += 1
        assert len(effective) == size // 4
        assert sha_text(c_like) == summary["effective_c_like_sha256"] and len(c_like) == summary["effective_c_like_chars"]
        for local, ins in enumerate(decoded):
            word = body[4 * local:4 * local + 4]
            record = asm["instructions"][local]
            code = effective[local]
            assert record["elf_va"] == hex(ins.address) and record["word_hex"] == word.hex()
            assert int(code["database_va"], 16) == int(raw["database_va"], 16) + 4 * local
            assert isinstance(code["pcode_ops"], list) and not code.get("missing_analyzed_instruction")
            mnemonic = code["assembly"].split()[0].lower()
            assert mnemonic == ins.mnemonic.lower() or (ins.mnemonic.lower(), mnemonic) in ALIASES, (
                number, local, ins.mnemonic, mnemonic)
            sample = samples_by_row.get((number, local))
            if sample:
                assert sample["elf_va"] == hex(ins.address)
                assert sample["word_sha256"] == hashlib.sha256(word).hexdigest()
                assert sample["source_mnemonic"] == ins.mnemonic and sample["ghidra_mnemonic"] == mnemonic
                assert sample["pcode_ops"] == len(code["pcode_ops"])
                assert sample["pcode_sha256"] == sha_text("\n".join(code["pcode_ops"]))
        source_slots += size // 4
        original_slots += raw["ghidra_instruction_count"]
        missing_slots += raw["missing_analyzed_instruction_count"]
        effective_slots += len(effective)
        local_ops = sum(len(row["pcode_ops"]) for row in effective)
        ops += local_ops
        assert summary["effective_ghidra_pcode_operations"] == local_ops
        assert summary["ordinary_spread_sample_count"] == sum(key[0] == number for key in samples_by_row)
    assert (source_slots, original_slots, missing_slots, effective_slots, ops, full,
            direct_calls, indirect_calls) == (10383, 10323, 60, 10383, 45968, 57, 305, 136)
    assert len(samples_by_row) / source_slots >= .10
    assert (seal["original_fde_candidate_bodies_verified"], seal["original_instruction_words_verified"],
            seal["effective_ghidra_pcode_instruction_positions"], seal["effective_ghidra_pcode_operations"],
            seal["original_full_fde_body_membership"], seal["transient_full_fde_metadata_assumptions"],
            seal["fresh_session_original_metadata_and_memory_replays"],
            seal["ordinary_spread_instruction_sample_count"]) == (60, 10383, 10383, 45968, 57, 3, 3, 1273)
    print(json.dumps({"result": "PASS_WITH_LABEL_FINDING", "task": "TASK_193", "bodies": 60, "source_slots": source_slots,
                      "original_analyzed_slots": original_slots, "effective_pcode_slots": effective_slots,
                      "pcode_ops": ops, "full_original_bodies": full, "corrected_boundaries": 3,
                      "ordinary_samples": len(samples_by_row), "wrong_zero_index_labels": wrong_zero_labels,
                      "seal_sha256": sha(REPORT / "COMPLETE.json")}))


def sha_text(value):
    return hashlib.sha256(value.encode()).hexdigest()


if __name__ == "__main__":
    main()
