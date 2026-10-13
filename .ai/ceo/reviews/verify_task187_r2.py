"""Read-only independent CEO source, raw-tool, and seal audit of TASK_187 R2."""
import hashlib
import json
import math
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
R1 = ROOT / "RULES/REPORT/TASK_187_REPORT_R1"
R2 = ROOT / "RULES/REPORT/TASK_187_REPORT_R2"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_187_internal_targets.json"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libMTFilterKernel.so")
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
CORRECTED = {18, 23, 30, 43, 85, 128}
ALIASES = {("b.hs", "b.cs"), ("b.lo", "b.cc"), ("mov", "orr")}


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def file_sha(path):
    return sha(path.read_bytes())


def read(path):
    return json.loads(path.read_text(encoding="utf8"))


def one(folder, index):
    matches = list(folder.glob(f"{index:03d}_*.json"))
    assert len(matches) == 1, (folder, index, len(matches))
    return matches[0], read(matches[0])


def main():
    assert file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == STANDARD_SHA
    task = ROOT / "RULES/TASK/TASK_187_SO45_CODEX_INTERNAL_ACTIVE.md"
    archive = ROOT / ".ai/ceo/reviews/TASK_187_R1_TASK_SNAPSHOT.md"
    assert not (R1 / "COMPLETE.json").exists()
    seal = read(R2 / "COMPLETE.json")
    assert seal["task_id"] == "TASK_187" and seal["revision"] == 2 and seal["status"] == "COMPLETE"
    assert seal["standard_sha256"] == STANDARD_SHA and seal["task_sha256"] == file_sha(task)
    assert seal["target_manifest_sha256"] == file_sha(MANIFEST)
    assert seal["original_so_sha256"] == file_sha(SOURCE)
    actual_r2 = {p.relative_to(R2).as_posix() for p in R2.rglob("*") if p.is_file()} - {
        "PROGRESS.json", "COMPLETE.json"}
    assert actual_r2 == set(seal["files"]) and len(actual_r2) == 4
    for relative, expected in seal["files"].items():
        assert file_sha(R2 / relative) == expected, relative
    for relative, expected in seal["code_files"].items():
        path = (ROOT / relative).resolve()
        assert path.is_relative_to(ROOT) and file_sha(path) == expected
    inventory = read(R2 / "R1_EVIDENCE_INVENTORY.json")
    assert inventory["r1_unsealed"] and inventory["r1_evidence_file_count"] == 293
    actual_r1 = {"report": R1, "code": ROOT / "scripts/task_187_codex_internal",
                 "scratch": ROOT / "RESEARCH_WORK/TASK_187_R1"}
    for key, folder in actual_r1.items():
        records = inventory["r1_evidence"][key]
        assert {p.relative_to(ROOT).as_posix() for p in folder.rglob("*") if p.is_file()} == set(records)
        for relative, expected in records.items():
            path = ROOT / relative
            assert path.stat().st_size == expected["bytes"] and file_sha(path) == expected["sha256"], (key, relative)
    assert inventory["r1_task_archive"]["sha256"] == file_sha(archive)
    assert inventory["target_manifest"]["sha256"] == file_sha(MANIFEST)
    assert inventory["original_source"]["sha256"] == file_sha(SOURCE)
    source_raw = SOURCE.read_bytes()
    pins = read(MANIFEST)["targets"]
    report = read(R2 / "INDEPENDENT_VERIFICATION.json")
    rows = report["rows"]
    assert len(pins) == len(rows) == 128
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf["e_machine"] == "EM_AARCH64"
        fdes = {(int(f["initial_location"]), int(f["address_range"]))
                for f in elf.get_dwarf_info().EH_CFI_entries() if isinstance(f, FDE)}
        dyn = elf.get_section_by_name(".dynsym")
        exports = {int(s["st_value"]) for s in dyn.iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF"
                   and int(s["st_value"]) > 0 and int(s["st_size"]) > 0}
        loads = [(int(s["p_vaddr"]), int(s["p_vaddr"]) + int(s["p_filesz"]), int(s["p_offset"]))
                 for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    assert len(fdes) == 2873 and len(exports) == 2362
    selected = sorted((va, size) for va, size in fdes if va not in exports)[:128]
    assert len(selected) == 128
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    source_slots = pcode_slots = pcode_ops = missing_slots = 0
    exact_count = 0
    indexed_samples = {}
    for sample in report["spread_sample_addresses"]:
        indexed_samples.setdefault(sample["candidate_index"], []).append(sample)
    assert len(report["spread_sample_addresses"]) == len({(s["candidate_index"], s["instruction_slot"])
                                                     for s in report["spread_sample_addresses"]}) == 1846
    for index, (pin, row) in enumerate(zip(pins, rows), 1):
        va, size, off = int(pin["elf_va"], 16), pin["size_bytes"], int(pin["file_offset"], 16)
        assert (va, size) == selected[index - 1] and (va, size) in fdes and va not in exports
        assert any(lo <= va and va + size <= hi and off == base + va - lo for lo, hi, base in loads)
        body = source_raw[off:off + size]
        assert len(body) == size and sha(body) == pin["body_sha256"] == row["original_body_sha256"]
        assert row["index"] == index and row["elf_va"] == pin["elf_va"] and row["fde_size_bytes"] == size
        source_path, src = one(R1 / "source_assembly", index)
        raw_folder = R1 / ("ghidra_raw_batch1" if index <= 64 else "ghidra_raw_batch2")
        raw_path, initial = one(raw_folder, index)
        assert src["index"] == initial["index"] == index and src["source_body_sha256"] == sha(body)
        assert initial["ghidra_memory_sha256"] == sha(body)
        assert row["first_pass_raw_sha256"] == file_sha(raw_path)
        assert len(initial["fde_byte_membership_bits"]) == size
        assert initial["fde_byte_membership_bits"].count("1") == initial["fde_byte_membership_count"]
        assert initial["function_body_total_address_count"] == initial["fde_byte_membership_count"] + initial["other_function_byte_count"]
        assert row["original_ghidra_body_member_bytes"] == initial["fde_byte_membership_count"]
        correction = None
        if index in CORRECTED:
            corrected_path, correction = one(R1 / "ghidra_correction_raw", index)
            assert row["transient_corrected_full_fde_metadata"]
            assert row["correction_raw_sha256"] == file_sha(corrected_path)
            assert correction["memory_sha256"] == sha(body) and correction["memory_unchanged_after_rollback"]
            assert correction["original_function_fde_membership_bits"] == initial["fde_byte_membership_bits"]
            assert correction["corrected_function_fde_membership_bits"] == "1" * size
            assert correction["corrected_function_fde_membership_count"] == size
            assert correction["corrected_function_body_total_address_count"] == size
            assert correction["temporary_old_function_removed"] and correction["temporary_full_fde_function_created"]
            assert correction["c_like_nonempty"] and not correction["error"]
            effective = correction
        else:
            exact_count += 1
            assert initial["fde_byte_membership_bits"] == "1" * size
            assert not row["transient_corrected_full_fde_metadata"] and row["correction_raw_sha256"] is None
            assert initial["c_like_nonempty"] and not initial["decompile_error"]
            effective = initial
        missing_slots += (size - initial["fde_byte_membership_count"]) // 4
        assert row["effective_c_like_sha256"] == sha(effective["c_like_text"].encode("utf8"))
        assert row["effective_c_like_chars"] == len(effective["c_like_text"])
        decoder_rows = list(decoder.disasm(body, va))
        assert len(decoder_rows) == len(src["instructions"]) == len(effective["instruction_pcode"]) == size // 4
        base = int(effective["database_va"], 16) - va
        for slot, (instruction, src_word, tool_word) in enumerate(
                zip(decoder_rows, src["instructions"], effective["instruction_pcode"])):
            assert instruction.address == int(src_word["elf_va"], 16)
            assert body[slot * 4:slot * 4 + 4].hex() == src_word["word_hex"]
            assert instruction.mnemonic == src_word["assembly"].split()[0]
            assert int(tool_word["database_va"], 16) == instruction.address + base
            source_mnemonic = instruction.mnemonic.lower()
            tool_mnemonic = tool_word["assembly"].split()[0].lower()
            assert source_mnemonic == tool_mnemonic or (source_mnemonic, tool_mnemonic) in ALIASES, (
                index, slot, hex(instruction.address), source_mnemonic, tool_word["assembly"])
        for sample in indexed_samples.get(index, []):
            slot = sample["instruction_slot"]
            instruction = decoder_rows[slot]
            tool_word = effective["instruction_pcode"][slot]
            assert int(sample["elf_va"], 16) == instruction.address
            assert sample["word_hex"] == body[slot * 4:slot * 4 + 4].hex()
            assert sample["source_mnemonic"] == instruction.mnemonic
            assert sample["ghidra_mnemonic"] == tool_word["assembly"].split()[0].lower()
            assert sample["pcode_op_count"] == len(tool_word["pcode_ops"])
            assert sample["pcode_sha256"] == sha("\n".join(tool_word["pcode_ops"]).encode("utf8"))
        source_slots += size // 4
        pcode_slots += len(effective["instruction_pcode"])
        pcode_ops += sum(len(x["pcode_ops"]) for x in effective["instruction_pcode"])
    assert (source_slots, pcode_slots, pcode_ops) == (14865, 14865, 40694)
    assert exact_count == 122 and missing_slots == 66
    assert report["original_full_byte_body_membership"] == 122
    assert report["original_missing_instruction_slots"] == 66
    assert report["transient_full_fde_metadata_corrections"] == sorted(CORRECTED)
    assert report["spread_sample_instruction_count"] == 1846 >= math.ceil(0.1 * source_slots)
    print(json.dumps({"result": "PASS", "task": "TASK_187", "revision": 2,
                      "source_bodies": 128, "source_words_redecoded": source_slots,
                      "raw_full_body": exact_count, "transient_full_fde_corrections": len(CORRECTED),
                      "raw_missing_slots": missing_slots, "pcode_ops": pcode_ops,
                      "spread_words_rechecked": 1846, "r1_file_hashes": 293,
                      "seal_sha256": file_sha(R2 / "COMPLETE.json")}))


if __name__ == "__main__":
    main()
