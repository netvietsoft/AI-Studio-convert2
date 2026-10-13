"""Read-only independent CEO verification of TASK_188 original and Ghidra evidence."""
import hashlib
import json
import math
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_188_REPORT_R1"
SCRATCH = ROOT / "RESEARCH_WORK/TASK_188_R1"
TARGET = ROOT / ".ai/ceo/reviews/TASK_188_internal_targets.json"
TASK = ROOT / "RULES/TASK/TASK_188_SO45_CODEX_INTERNAL_ACTIVE.md"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libMTLReportTool.so")
CORRECTED = {10, 15, 17, 18, 28, 30, 32, 35, 43, 52, 55, 56, 58, 59, 62, 69}
OVERLAP = {47, 57, 60}
ALIASES = {("b.hs", "b.cs"), ("b.lo", "b.cc"), ("mov", "orr")}


def file_sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def read(path):
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
    amount = max(1, math.ceil(0.12 * count))
    return [(count - 1) // 2] if amount == 1 else sorted({round(i * (count - 1) / (amount - 1)) for i in range(amount)})


def main():
    seal = read(REPORT / "COMPLETE.json")
    manifest = read(TARGET)
    verification = read(REPORT / "worker_verification.json")
    assert seal["task_id"] == "TASK_188" and seal["revision"] == 1 and seal["status"] == "COMPLETE"
    assert seal["research_result"] == "PARTIAL_THREE_BOUNDARY_LIMITED_OVERLAPS"
    for path, expected in ((ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt", seal["standard_sha256"]),
                           (TASK, seal["task_sha256"]), (TARGET, seal["target_manifest_sha256"]),
                           (SOURCE, seal["original_so_sha256"])):
        assert file_sha(path) == expected, str(path)
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {"COMPLETE.json", "PROGRESS.json"}
    assert actual == set(seal["files"]) and len(actual) == 263
    for rel, expected in seal["files"].items():
        assert file_sha(REPORT / rel) == expected, rel
    for rel, expected in seal["code_files"].items():
        assert file_sha(ROOT / rel) == expected, rel
    for rel, expected in seal["scratch_files"].items():
        assert file_sha(ROOT / rel) == expected, rel
    assert len(seal["code_files"]) == 7 and len(seal["scratch_files"]) == 12
    index = read(REPORT / "source_project_index.json")
    assert len(index["selected_candidate_rows"]) == 117
    for batch, count in ((1, 60), (2, 57)):
        receipt = read(REPORT / f"ghidra_batch{batch}_command.json")
        assert receipt["exit_code"] == 0 and receipt["status"] == "OUTPUT_READY"
        assert receipt["raw_result_files"] == count and len(receipt["raw_result_hashes"]) == count
        assert receipt["stdout_sha256"] == file_sha(REPORT / f"ghidra_batch{batch}_stdout.log")
        assert receipt["stderr_sha256"] == file_sha(REPORT / f"ghidra_batch{batch}_stderr.log")
        assert receipt["script_sha256"] == file_sha(ROOT / "scripts/task_188_codex_internal/ExtractInternal188.java")
        assert receipt["target_tsv_sha256"] == file_sha(SCRATCH / f"target_batch_{batch}.tsv")
        assert "-readOnly" in receipt["command"] and "-noanalysis" in receipt["command"] and "-import" not in receipt["command"]
        assert receipt["max_cpu"] == 1 and receipt["max_heap"] == "1G" and receipt["elapsed_seconds"] < 1200
        folder = REPORT / f"ghidra_raw_batch{batch}"
        assert {p.name for p in folder.glob("*.json")} == set(receipt["raw_result_hashes"])
        for name, digest in receipt["raw_result_hashes"].items():
            assert file_sha(folder / name) == digest, name
    correction_receipt = read(REPORT / "ghidra_correction_command.json")
    assert correction_receipt["target_indices"] == sorted(CORRECTED)
    assert correction_receipt["raw_result_files"] == 16 and correction_receipt["exit_code"] == 0
    assert correction_receipt["script_sha256"] == file_sha(ROOT / "scripts/task_188_codex_internal/RepairMembership188.java")
    assert correction_receipt["target_tsv_sha256"] == file_sha(SCRATCH / "correction_targets.tsv")
    assert "-readOnly" in correction_receipt["command"] and "-noanalysis" in correction_receipt["command"]
    assert correction_receipt["stdout_sha256"] == file_sha(REPORT / "ghidra_correction_stdout.log")
    assert correction_receipt["stderr_sha256"] == file_sha(REPORT / "ghidra_correction_stderr.log")
    for name, digest in correction_receipt["raw_result_hashes"].items():
        assert file_sha(REPORT / "ghidra_correction_raw" / name) == digest
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf["e_machine"] == "EM_AARCH64"
        fdes = sorted((int(e["initial_location"]), int(e["address_range"])) for e in elf.get_dwarf_info().EH_CFI_entries() if isinstance(e, FDE))
        exports = {int(e["st_value"]) for e in elf.get_section_by_name(".dynsym").iter_symbols() if e["st_info"]["type"] == "STT_FUNC" and e["st_shndx"] != "SHN_UNDEF" and int(e["st_value"]) > 0 and int(e["st_size"]) > 0}
        loads = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"])) for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    selected = [(va, size) for va, size in fdes if va not in exports]
    assert (len(fdes), len(exports), len(selected)) == (147, 30, 117)
    assert [(int(t["elf_va"], 16), t["size_bytes"]) for t in manifest["targets"]] == selected
    source = SOURCE.read_bytes()
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    total_words = pcode_slots = pcode_ops = raw_missing = 0
    full = 0
    samples_expected = []
    report_rows = verification["rows"]
    for position, ((va, size), target, reported) in enumerate(zip(selected, manifest["targets"], report_rows), 1):
        off = int(target["file_offset"], 16)
        assert sum(base <= va and va + size <= base + length and off == file_off + va - base for base, file_off, length in loads) == 1
        body = source[off:off + size]
        digest = hashlib.sha256(body).hexdigest()
        assert len(body) == size and digest == target["body_sha256"] == reported["source_body_sha256"]
        name = f"{position:03d}_{va:x}.json"
        src = read(REPORT / "source_assembly" / name)
        raw = read(REPORT / f"ghidra_raw_batch{1 if position <= 60 else 2}" / name)
        assert raw["ghidra_memory_sha256"] == reported["copied_ghidra_memory_sha256"] == digest
        bits = raw["fde_byte_membership_bits"]
        members = bits.count("1")
        assert len(bits) == size and set(bits) <= {"0", "1"}
        assert members == raw["fde_byte_membership_count"] == reported["first_pass_body_membership_bytes"]
        assert raw["fde_missing_body_ranges"] == reported["first_pass_missing_body_ranges"] == gaps(bits)
        assert raw["function_body_total_address_count"] == members and reported["first_pass_body_extra_address_count"] == 0
        assert raw["fde_byte_membership_transitions"] == sum(bits[k] != bits[k - 1] for k in range(1, size))
        if members == size:
            full += 1
        missing = sum(bool(x.get("missing_analyzed_instruction")) for x in raw["instruction_pcode"])
        assert missing == raw["missing_analyzed_instruction_count"]
        raw_missing += missing
        fixed = None
        if position in CORRECTED:
            fixed = read(REPORT / "ghidra_correction_raw" / name)
            assert members < size and raw["other_function_byte_count"] == 0
            assert fixed["original_function_fde_membership_bits"] == bits
            assert fixed["corrected_function_fde_membership_bits"] == "1" * size
            assert fixed["corrected_function_fde_membership_count"] == size
            assert fixed["full_fde_instruction_count"] == size // 4
            assert fixed["memory_sha256"] == digest and fixed["memory_unchanged_after_rollback"]
            assert fixed["temporary_old_function_removed"] and fixed["temporary_full_fde_function_created"]
            assert fixed["c_like_nonempty"] and fixed["c_like_text"].strip() and not fixed["error"]
        elif position in OVERLAP:
            assert raw["other_function_byte_count"] == 4 and members < size
        else:
            assert members == size and missing == 0 and raw["other_function_byte_count"] == 0
        effective = fixed["instruction_pcode"] if fixed else raw["instruction_pcode"]
        c_text = fixed["c_like_text"] if fixed else raw["c_like_text"]
        assert hashlib.sha256(c_text.encode("utf8")).hexdigest() == reported["effective_c_like_sha256"]
        decoded = list(decoder.disasm(body, va))
        assert len(decoded) == size // 4 == len(src["instructions"]) == len(effective)
        available = []
        for local, (ins, src_ins, gh_ins) in enumerate(zip(decoded, src["instructions"], effective)):
            word = body[local * 4:local * 4 + 4]
            assert int(src_ins["elf_va"], 16) == ins.address and src_ins["word_hex"] == word.hex()
            assert src_ins["assembly"].split()[0].lower() == ins.mnemonic.lower()
            assert int(gh_ins["database_va"], 16) == int(raw["database_va"], 16) + local * 4
            if gh_ins.get("missing_analyzed_instruction") or gh_ins.get("missing_instruction"):
                continue
            assert isinstance(gh_ins["pcode_ops"], list) and gh_ins["assembly"]
            available.append(local)
        assert len(available) == reported["effective_ghidra_instruction_pcode_slots"]
        for number in ordinals(len(available)):
            local = available[number]
            ins = decoded[local]
            gh = effective[local]
            mnemonic = gh["assembly"].split()[0].lower()
            assert mnemonic == ins.mnemonic.lower() or (ins.mnemonic.lower(), mnemonic) in ALIASES
            word = body[local * 4:local * 4 + 4]
            samples_expected.append((position, local, ins.address, hashlib.sha256(word).hexdigest(),
                                     ins.mnemonic, mnemonic, len(gh["pcode_ops"]),
                                     hashlib.sha256("\n".join(gh["pcode_ops"]).encode()).hexdigest()))
        total_words += len(decoded)
        pcode_slots += len(available)
        pcode_ops += sum(len(x.get("pcode_ops", [])) for x in effective)
    assert (total_words, pcode_slots, pcode_ops, raw_missing, full) == (6885, 6760, 21090, 456, 98)
    reported_samples = verification["ordinary_spread_samples"]
    assert len(samples_expected) == len(reported_samples) == 871
    for expected, reported in zip(samples_expected, reported_samples):
        assert (reported["candidate_index"], reported["instruction_ordinal_zero_based"], int(reported["elf_va"], 16),
                reported["source_word_sha256"], reported["source_mnemonic"], reported["ghidra_mnemonic"],
                reported["pcode_count"], reported["pcode_sha256"]) == expected
    assert len(samples_expected) / total_words >= .1
    master = (REPORT / "01_MASTER_REPORT.md").read_text(encoding="utf8")
    assert "PARTIAL static research" in master and "#47, #57 and #60" in master
    print(json.dumps({"result": "PASS", "task": "TASK_188", "revision": 1,
                      "bodies": 117, "source_words": total_words, "pcode_slots": pcode_slots,
                      "pcode_ops": pcode_ops, "original_full": full,
                      "transient_corrected": len(CORRECTED), "overlap_limited": sorted(OVERLAP),
                      "spread_samples": len(samples_expected), "seal_sha256": file_sha(REPORT / "COMPLETE.json")}))


if __name__ == "__main__":
    main()
