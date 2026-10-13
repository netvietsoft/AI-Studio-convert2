"""Independent CEO source, Ghidra-membership and manifest audit for TASK_184 R2."""
import hashlib
import json
import math
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libVERenderer.so")
REPORT = ROOT / "RULES/REPORT/TASK_184_REPORT_R2"
R1 = ROOT / "RULES/REPORT/TASK_184_REPORT_R1"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_184_internal_targets.json"
CEO = ROOT / ".ai/ceo/reviews/TASK_184_CEO_REPLAY"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def file_sha(path):
    return sha(path.read_bytes())


def lines(path):
    return [json.loads(s) for s in path.read_text(encoding="utf8").splitlines() if s]


def main():
    assert file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == STANDARD_SHA
    task = ROOT / "RULES/TASK/TASK_184_SO45_CODEX_INTERNAL_ACTIVE.md"
    assert file_sha(task) == "7234d568edbee9ce6c39edacc05fc140e88591b332da7b95214e1b57ed67c61a"
    seal_path = REPORT / "COMPLETE.json"
    seal = json.loads(seal_path.read_text(encoding="utf8"))
    assert file_sha(seal_path) == "d6cd86f4c15e97bc394893b2118be692e01fdb3bf7c28265838dc392b4175cac"
    assert seal["task_id"] == "TASK_184" and seal["revision"] == 2 and seal["status"] == "COMPLETE"
    assert seal["task_sha256"] == file_sha(task) and seal["standard_sha256"] == STANDARD_SHA
    assert seal["target_manifest_sha256"] == file_sha(MANIFEST)
    assert seal["correction_of_r1_seal_sha256"] == file_sha(R1 / "COMPLETE.json")
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json"}
    assert actual == set(seal["files"])
    for rel, expected in seal["files"].items():
        assert file_sha(REPORT / rel) == expected, rel
    for key in ("code_files", "research_files"):
        for rel, expected in seal[key].items():
            p = (ROOT / rel).resolve()
            assert p.is_relative_to(ROOT) and file_sha(p) == expected, rel
    assert len(seal["files"]) == 14 and len(seal["code_files"]) == 5 and len(seal["research_files"]) == 9
    source = SOURCE.read_bytes()
    assert sha(source) == seal["source_sha256"]
    target = json.loads(MANIFEST.read_text(encoding="utf8"))
    pins = target["targets"]
    assert len(pins) == 141
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf["e_machine"] == "EM_AARCH64"
        fdes = {(int(entry["initial_location"]), int(entry["address_range"]))
                for entry in elf.get_dwarf_info().EH_CFI_entries() if isinstance(entry, FDE)}
        dynsym = elf.get_section_by_name(".dynsym")
        exports = {int(sym["st_value"]) for sym in dynsym.iter_symbols()
                   if sym["st_info"]["type"] == "STT_FUNC" and int(sym["st_size"]) > 0
                   and sym["st_shndx"] != "SHN_UNDEF"}
        loads = [(int(seg["p_vaddr"]), int(seg["p_vaddr"]) + int(seg["p_filesz"]), int(seg["p_offset"]))
                 for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD" and int(seg["p_flags"]) & 1]
    assert len(fdes) == 1027 and len(exports) == 886
    raw_rows, ceo_body, ceo_missing, corrected = (lines(REPORT / "body_membership.ndjson"),
                                                   lines(CEO / "body_ranges.ndjson"),
                                                   lines(CEO / "omitted_words.ndjson"),
                                                   lines(REPORT / "corrected_candidates.ndjson"))
    assert all(len(rows) == 141 for rows in (raw_rows, ceo_body, ceo_missing, corrected))
    coverage = json.loads((REPORT / "coverage_index.json").read_text(encoding="utf8"))
    omissions = json.loads((REPORT / "missing_instruction_evidence.json").read_text(encoding="utf8"))
    command = json.loads((REPORT / "ghidra_command.json").read_text(encoding="utf8"))
    assert command["exit_code"] == 0 and command["observed"]["parseable_rows"] == 141
    assert command["script_sha256"] == file_sha(ROOT / "scripts/task_184_codex_correction_r2/ReviewBodyMembership184R2.java")
    assert command["output_sha256"] == file_sha(REPORT / "body_membership.ndjson")
    assert "-readOnly" in command["command"] and "-noanalysis" in command["command"]
    assert command["max_cpu"] == 1 and command["max_heap"] == "1G" and command["elapsed_seconds"] < 1200
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoder.skipdata = True
    sample_indices = {1 + round(i * 140 / 19) for i in range(20)}
    r1_asm = {row["index"]: row for row in lines(R1 / "source/assembly.ndjson")}
    missing_total, member_total, original_total, sampled_words = 0, 0, 0, 0
    nonexact = []
    omission_map = {row["index"]: row for row in omissions["rows"]}
    for ordinal, (pin, row, independent, words, fix) in enumerate(zip(pins, raw_rows, ceo_body, ceo_missing, corrected), 1):
        va, size, off = int(pin["elf_va"], 16), pin["size_bytes"], int(pin["file_offset"], 16)
        assert (va, size) in fdes and va not in exports
        assert any(lo <= va and va + size <= hi and off == file_base + va - lo for lo, hi, file_base in loads)
        body = source[off:off + size]
        assert len(body) == size and sha(body) == pin["body_sha256"]
        assert (row["index"], independent["index"], words["index"], fix["index"]) == (ordinal,) * 4
        assert row["elf_va"] == pin["elf_va"] == words["elf_va"] == fix["elf_va"]
        assert row["fde_size_bytes"] == size == words["fde_size_bytes"]
        assert row["expected_original_body_sha256"] == row["owned_project_memory_sha256"] == pin["body_sha256"]
        assert (row["body_equals_fde"], row["body_contains_fde"], row["body_num_addresses"], row["body_min"], row["body_max"]) == (
            independent["body_equals_fde"], independent["body_contains_fde"],
            independent["body_num_addresses"], independent["body_min"], independent["body_max"])
        assert row["body_member_bytes_within_fde"] + row["body_missing_bytes_within_fde"] == size
        assert row["body_extra_bytes_outside_fde"] == 0
        missing_vas = [int(m["elf_va"], 16) for m in row["missing_instructions"]]
        assert missing_vas == [int(x, 16) for x in words["missing_word_vas"]]
        assert len(missing_vas) == row["missing_instruction_slots"] == words["missing_instruction_slots"]
        assert row["body_missing_bytes_within_fde"] == 4 * len(missing_vas)
        for miss in row["missing_instructions"]:
            miss_va, miss_off = int(miss["elf_va"], 16), int(miss["original_file_offset"], 16)
            assert va <= miss_va < va + size and miss_off == off + miss_va - va
            word = source[miss_off:miss_off + 4]
            assert len(word) == 4 and word.hex() == miss["word_le"] and sha(word) == miss["word_sha256"]
        r1_path = ROOT / fix["r1_candidate_path"]
        r1 = json.loads(r1_path.read_text(encoding="utf8"))
        assert file_sha(r1_path) == fix["r1_candidate_sha256"]
        assert r1["pseudocode_sha256"] == fix["r1_c_like_sha256"]
        assert r1["decompile_success"] and bool(r1["pseudocode"].strip()) == fix["r1_c_like_present"]
        assert fix["r2_body_equals_fde"] == row["body_equals_fde"]
        assert fix["r2_body_missing_bytes"] == row["body_missing_bytes_within_fde"]
        assert fix["c_like_scope"] == ("FULL_PINNED_FDE_BODY" if row["body_equals_fde"] else "BOUNDARY_LIMITED_GHIDRA_BODY")
        if not row["body_equals_fde"]:
            nonexact.append(ordinal)
            assert omission_map[ordinal]["missing_bytes"] == row["body_missing_bytes_within_fde"]
            assert [int(x["elf_va"], 16) for x in omission_map[ordinal]["missing_instructions"]] == missing_vas
        if ordinal in sample_indices:
            listed = r1_asm[ordinal]
            decoded = list(decoder.disasm(body, va))
            assert len(decoded) == size // 4 == len(listed["instructions"])
            for position, (ins, listed_ins) in enumerate(zip(decoded, listed["instructions"])):
                chunk = body[position * 4:position * 4 + 4]
                assert ins.address == int(listed_ins["va"], 16)
                assert chunk.hex() == listed_ins["word_le"] and ins.mnemonic == listed_ins["mnemonic"]
                assert ins.op_str == listed_ins["operands"]
            sampled_words += len(decoded)
        missing_total += row["body_missing_bytes_within_fde"]
        member_total += row["body_member_bytes_within_fde"]
        original_total += size
    assert nonexact == [8, 14, 17, 46, 95, 96]
    assert (original_total, member_total, missing_total) == (30644, 30408, 236)
    assert sum(x["body_equals_fde"] for x in raw_rows) == 135
    assert sum(x["missing_instruction_slots"] for x in raw_rows) == 59
    assert len(sample_indices) == 20 and sampled_words >= math.ceil(0.1 * 7661)
    assert coverage["counts"] == seal["counts"]
    assert coverage["counts"]["c_like_texts_with_full_fde_ghidra_body_membership"] == 135
    assert coverage["counts"]["c_like_texts_boundary_limited"] == 6
    assert omissions["candidate_count"] == 6 and omissions["total_missing_bytes"] == 236
    assert omissions["total_missing_instruction_slots"] == 59
    assert [int(x["elf_va"], 16) for x in raw_rows[95]["missing_instructions"]] == list(range(0x5D868, 0x5D894, 4))
    print(json.dumps({"result": "PASS", "task": "TASK_184", "revision": 2,
                      "seal_sha256": file_sha(seal_path), "report_files": len(seal["files"]),
                      "code_files": len(seal["code_files"]), "project_files": len(seal["research_files"]),
                      "source_bodies": len(pins), "exact": 135, "boundary_limited": 6,
                      "missing_bytes": missing_total, "missing_words": 59,
                      "ordinary_spread_words_redecoded": sampled_words}))


if __name__ == "__main__":
    main()
