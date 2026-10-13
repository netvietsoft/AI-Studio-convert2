"""Independent CEO verification of TASK_189 source, body, p-code, and rollback evidence."""
import hashlib
import json
import math
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_189_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_189_R1"
TASK = ROOT / "RULES/TASK/TASK_189_SO45_CODEX_INTERNAL_ACTIVE.md"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_189_internal_targets.json"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libMTFilterKernel.so")
PRIOR = ROOT / "RESEARCH_WORK/TASK_187_R1/ghidra_project"
CORRECTED = {167, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 187}
ALIASES = {("b.hs", "b.cs"), ("b.lo", "b.cc"), ("mov", "orr"),
           ("mov", "dup"), ("bfi", "bfm")}


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def load(path):
    return json.loads(path.read_text(encoding="utf8"))


def gaps(bits):
    result = []
    start = None
    for index, bit in enumerate(bits):
        if bit == "0" and start is None:
            start = index
        if bit == "1" and start is not None:
            result.append({"start_offset": start, "end_exclusive": index})
            start = None
    if start is not None:
        result.append({"start_offset": start, "end_exclusive": len(bits)})
    return result


def ordinals(count):
    amount = max(1, math.ceil(.12 * count))
    return [(count - 1) // 2] if amount == 1 else sorted({
        round(step * (count - 1) / (amount - 1)) for step in range(amount)})


def main():
    seal = load(REPORT / "COMPLETE.json")
    assert seal["task_id"] == "TASK_189" and seal["revision"] == 1 and seal["status"] == "COMPLETE"
    assert seal["research_result"] == "PARTIAL_BOUNDARY_FOURTEEN_TRANSIENT_FULL_FDE_METADATA"
    for path, expected in ((ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt", seal["standard_sha256"]),
                           (TASK, seal["task_sha256"]), (MANIFEST, seal["target_manifest_sha256"]),
                           (SOURCE, seal["original_so_sha256"])):
        assert sha(path) == expected, str(path)
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json", "PROGRESS.md"}
    assert actual == set(seal["files"]) and len(actual) == 176
    for relative, digest in seal["files"].items():
        assert sha(REPORT / relative) == digest, relative
    for key, count in (("code_files", 10), ("scratch_files", 12)):
        assert len(seal[key]) == count
        for relative, digest in seal[key].items():
            assert sha(ROOT / relative) == digest, relative
    index = load(REPORT / "source_project_index.json")
    assert len(index["selected_candidate_rows"]) == 64
    assert len(index["project_files"]) == 9
    for item in index["project_files"]:
        relative = item["relative_path"]
        assert sha(PRIOR / relative) == sha(SCRATCH / "ghidra_project" / relative) == item["sha256"]
    for name, script, folder, count in (
        ("ghidra_batch1", "ExtractInternal189.java", "ghidra_raw_batch1", 32),
        ("ghidra_batch2", "ExtractInternal189.java", "ghidra_raw_batch2", 32),
        ("ghidra_correction_retry", "RepairMembership189.java", "ghidra_correction_retry_raw", 14),
        ("ghidra_postrollback", "CheckOriginalMembership189.java", "ghidra_postrollback_raw", 14),
    ):
        receipt = load(REPORT / f"{name}_command.json")
        assert receipt["status"] == "OUTPUT_READY" and receipt["exit_code"] == 0
        assert receipt["raw_result_files"] == count and len(receipt["raw_result_hashes"]) == count
        assert receipt["max_cpu"] == 1 and receipt["max_heap"] == "1G" and receipt["elapsed_seconds"] <= 1200
        assert "-noanalysis" in receipt["command"] and "-readOnly" in receipt["command"] and "-import" not in receipt["command"]
        assert receipt["script_sha256"] == sha(ROOT / f"scripts/task_189_codex_internal/{script}")
        tsv = SCRATCH / (f"target_batch_{receipt['batch']}.tsv" if "batch" in receipt else "correction_targets.tsv")
        assert receipt["target_tsv_sha256"] == sha(tsv)
        assert receipt["stdout_sha256"] == sha(REPORT / f"{name}_stdout.log")
        assert receipt["stderr_sha256"] == sha(REPORT / f"{name}_stderr.log")
        assert {p.name for p in (REPORT / folder).glob("*.json")} == set(receipt["raw_result_hashes"])
        for filename, digest in receipt["raw_result_hashes"].items():
            assert sha(REPORT / folder / filename) == digest
    attempt1 = load(REPORT / "ghidra_correction_command.json")
    assert attempt1["status"] == "PARTIAL_OUTPUT" and attempt1["raw_result_files"] == 0
    assert attempt1["script_sha256"] != sha(ROOT / "scripts/task_189_codex_internal/RepairMembership189.java")
    assert attempt1["stdout_sha256"] == sha(REPORT / "ghidra_correction_stdout.log")
    assert attempt1["stderr_sha256"] == sha(REPORT / "ghidra_correction_stderr.log")
    targets = load(MANIFEST)["targets"]
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf["e_machine"] == "EM_AARCH64"
        fdes = sorted({(int(f["initial_location"]), int(f["address_range"]))
                       for f in elf.get_dwarf_info().EH_CFI_entries() if isinstance(f, FDE) and int(f["address_range"]) > 0})
        exports = {int(s["st_value"]) for s in elf.get_section_by_name(".dynsym").iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF" and
                   int(s["st_value"]) > 0 and int(s["st_size"]) > 0}
        loads = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"]))
                 for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    selected = [(va, size) for va, size in fdes if va not in exports]
    assert (len(fdes), len(exports), len(selected)) == (2873, 2362, 511)
    assert [(int(t["elf_va"], 16), t["size_bytes"]) for t in targets] == selected[128:192]
    source = SOURCE.read_bytes()
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    report_rows = load(REPORT / "WORKER_VERIFICATION.json")["rows"]
    samples = load(REPORT / "WORKER_VERIFICATION.json")["ordinary_spread_samples"]
    expected_samples = []
    slots = effective_slots = effective_ops = original_slots = missing_slots = full = corrected_count = 0
    for ordinal, ((va, size), target, reported) in enumerate(zip(selected[128:192], targets, report_rows), 1):
        index = ordinal + 128
        offset = int(target["file_offset"], 16)
        assert sum(base <= va and va + size <= base + length and offset == file_off + va - base
                   for base, file_off, length in loads) == 1
        body = source[offset:offset + size]
        digest = hashlib.sha256(body).hexdigest()
        assert len(body) == size and digest == target["body_sha256"] == reported["original_pt_load_body_sha256"]
        name = f"{index:03d}_{va:x}.json"
        src = load(REPORT / "source_assembly" / name)
        raw = load(REPORT / f"ghidra_raw_batch{1 if ordinal <= 32 else 2}" / name)
        assert (src["index"], raw["index"], reported["index"]) == (index, index, index)
        assert src["source_body_sha256"] == raw["ghidra_memory_sha256"] == reported["copied_ghidra_memory_sha256"] == digest
        bits = raw["fde_byte_membership_bits"]
        assert len(bits) == size and set(bits) <= {"0", "1"}
        assert bits.count("1") == raw["fde_byte_membership_count"] == reported["original_ghidra_body_membership_bytes"]
        assert raw["fde_missing_body_ranges"] == reported["original_ghidra_body_missing_ranges"] == gaps(bits)
        assert raw["function_body_total_address_count"] == bits.count("1") and raw["extra_body_address_count"] == 0
        assert raw["extra_body_ranges"] == [] and raw["other_function_byte_count"] == 0
        assert raw["missing_analyzed_instruction_count"] == size // 4 - raw["ghidra_instruction_count"]
        original_slots += raw["ghidra_instruction_count"]
        missing_slots += raw["missing_analyzed_instruction_count"]
        correction = None
        if index in CORRECTED:
            correction = load(REPORT / "ghidra_correction_retry_raw" / name)
            post = load(REPORT / "ghidra_postrollback_raw" / name)
            assert bits.count("1") < size and raw["missing_analyzed_instruction_count"] > 0
            assert correction["original_function_fde_membership_bits"] == bits
            assert correction["corrected_function_fde_membership_bits"] == "1" * size
            assert correction["corrected_function_fde_membership_count"] == size
            assert correction["full_fde_instruction_count"] == size // 4
            assert correction["memory_sha256"] == digest and correction["memory_unchanged_after_rollback"]
            assert correction["temporary_old_function_removed"] and correction["temporary_full_fde_function_created"]
            assert correction["other_function_byte_count"] == 0 and correction["c_like_nonempty"] and not correction["error"]
            assert post["memory_sha256"] == digest and post["body_bits"] == bits
            assert post["function_name"] == raw["function_name"] and post["function_start"] == raw["function_start"]
            effective = correction["instruction_pcode"]
            c_text = correction["c_like_text"]
            corrected_count += 1
        else:
            assert bits == "1" * size and raw["missing_analyzed_instruction_count"] == 0
            full += 1
            effective = raw["instruction_pcode"]
            c_text = raw["c_like_text"]
        assert hashlib.sha256(c_text.encode()).hexdigest() == reported["effective_c_like_sha256"]
        decoded = list(decoder.disasm(body, va))
        assert len(decoded) == len(src["instructions"]) == len(raw["instruction_pcode"]) == len(effective) == size // 4
        selected_ordinals = ordinals(len(decoded))
        for local, (ins, item, observed, eff) in enumerate(zip(decoded, src["instructions"], raw["instruction_pcode"], effective)):
            word = body[local * 4:local * 4 + 4]
            assert (item["elf_va"], item["word_hex"]) == (hex(ins.address), word.hex())
            assert item["assembly"].split()[0].lower() == ins.mnemonic.lower()
            assert int(observed["database_va"], 16) == int(eff["database_va"], 16) == int(raw["database_va"], 16) + local * 4
            assert not eff.get("missing_instruction") and not eff.get("missing_analyzed_instruction")
            assert isinstance(eff["pcode_ops"], list) and eff["assembly"]
            mnemonic = eff["assembly"].split()[0].lower()
            assert mnemonic == ins.mnemonic.lower() or (ins.mnemonic.lower(), mnemonic) in ALIASES
            if local in selected_ordinals:
                expected_samples.append((index, local, ins.address, hashlib.sha256(word).hexdigest(),
                                         ins.mnemonic, mnemonic, len(eff["pcode_ops"]),
                                         hashlib.sha256("\n".join(eff["pcode_ops"]).encode()).hexdigest()))
        assert sum(len(row["pcode_ops"]) for row in effective) == reported["effective_ghidra_pcode_operations"]
        slots += len(decoded)
        effective_slots += len(effective)
        effective_ops += reported["effective_ghidra_pcode_operations"]
    assert (slots, effective_slots, effective_ops, original_slots, missing_slots, full, corrected_count) == (
        8415, 8415, 26277, 7969, 446, 50, 14)
    assert len(expected_samples) == len(samples) == 1039 and len(samples) / slots >= .1
    for expected, reported in zip(expected_samples, samples):
        assert (reported["candidate_index"], reported["instruction_ordinal_zero_based"], int(reported["elf_va"], 16),
                reported["word_sha256"], reported["source_mnemonic"], reported["ghidra_mnemonic"],
                reported["pcode_ops"], reported["pcode_sha256"]) == expected
    master = (REPORT / "01_MASTER_REPORT.md").read_text(encoding="utf8")
    assert "PARTIAL static research" in master and "first correction attempt failed" in master
    print(json.dumps({"result": "PASS", "task": "TASK_189", "revision": 1,
                      "bodies": 64, "source_words": slots, "effective_pcode_slots": effective_slots,
                      "effective_pcode_ops": effective_ops, "original_full": full,
                      "transient_corrected": corrected_count, "postrollback": corrected_count,
                      "spread_samples": len(samples), "seal_sha256": sha(REPORT / "COMPLETE.json")}))


if __name__ == "__main__":
    main()
