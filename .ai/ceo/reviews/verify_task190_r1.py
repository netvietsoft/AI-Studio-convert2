"""Independent CEO byte, source, report, coverage, and provenance check for TASK_190 R1."""
import hashlib
import json
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_190_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_190_SO45_CODEX_INTERNAL_ACTIVE.md"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_190_internal_targets.json"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGColorFunctions.so")
PRIOR = ROOT / "RESEARCH_WORK/TASK_186_R1/ghidra_project"
PROJECT = ROOT / "RESEARCH_WORK/TASK_190_R1/ghidra_project"


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def load(path):
    return json.loads(path.read_text(encoding="utf8"))


def ndjson(path):
    return [json.loads(line) for line in path.read_text(encoding="utf8").splitlines() if line]


def hashes(folder):
    return {p.relative_to(folder).as_posix(): sha(p) for p in folder.rglob("*") if p.is_file()}


def main():
    seal = load(REPORT / "COMPLETE.json")
    assert seal["task_id"] == "TASK_190" and seal["revision"] == 1 and seal["status"] == "COMPLETE"
    assert seal["research_disposition"] == "PARTIAL_STATIC_FDE_BOUNDARY"
    assert sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == seal["standard_sha256"]
    assert sha(TASK) == seal["task_sha256"] and sha(MANIFEST) == seal["target_manifest_sha256"]
    assert sha(SOURCE) == seal["original_so_sha256"]
    actual_files = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json"}
    assert actual_files == set(seal["files"]) and len(actual_files) == 34
    for relative, digest in seal["files"].items():
        assert sha(REPORT / relative) == digest, relative
    for relative, digest in seal["code_files"].items():
        assert sha(ROOT / relative) == digest, relative
    assert len(seal["code_files"]) == 7
    prior_hashes, project_hashes = hashes(PRIOR), hashes(PROJECT)
    assert len(prior_hashes) == len(project_hashes) == 9
    assert prior_hashes == project_hashes == seal["scratch_project_files"]
    copy_receipt = load(REPORT / "project_copy_receipt.json")
    post_receipt = load(REPORT / "project_postrun_receipt.json")
    assert copy_receipt["historical_file_sha256"] == copy_receipt["private_copy_file_sha256"] == project_hashes
    assert post_receipt["file_sha256"] == project_hashes and post_receipt["pre_post_hashes_match"]
    manifest = load(MANIFEST)["targets"]
    source_index = load(REPORT / "source_index.json")["targets"]
    source_rows = ndjson(REPORT / "source_assembly.ndjson")
    raw = []
    for chunk in range(4):
        folder = REPORT / f"chunk_{chunk:02d}"
        receipt = load(folder / "ghidra_command.json")
        rows = ndjson(folder / "ghidra_raw.ndjson")
        assert len(rows) == receipt["rows"] == 32
        assert [x["index"] for x in rows] == list(range(1 + chunk * 32, 33 + chunk * 32))
        assert receipt["status"] == "OUTPUT_READY" and receipt["exit_code"] == 0
        assert receipt["termination"] is None and receipt["fresh_imports"] == 0 and receipt["read_only_project"]
        assert receipt["elapsed_seconds"] <= receipt["timeout_seconds"] <= 1200
        assert "-readOnly" in receipt["command"] and "-noanalysis" in receipt["command"] and "-import" not in receipt["command"]
        assert receipt["script_sha256"] == sha(ROOT / "scripts/task_190_codex_internal/ExportInternal190.java")
        for key, name in (("stdout_sha256", "ghidra_stdout.log"), ("stderr_sha256", "ghidra_stderr.log"),
                          ("raw_output_sha256", "ghidra_raw.ndjson"), ("target_tsv_sha256", "targets.tsv")):
            assert receipt[key] == sha(folder / name), (chunk, key)
        raw.extend(rows)
    assert len(manifest) == len(source_index) == len(source_rows) == len(raw) == 128
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf["e_machine"] == "EM_AARCH64"
        fdes = sorted((int(f["initial_location"]), int(f["address_range"]))
                      for f in elf.get_dwarf_info().EH_CFI_entries() if isinstance(f, FDE))
        exports = {int(s["st_value"]) for s in elf.get_section_by_name(".dynsym").iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF" and int(s["st_size"]) > 0}
        loads = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"]))
                 for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    selected = [(va, size) for va, size in fdes if size > 0 and va not in exports]
    assert (len(fdes), len(exports), len(selected)) == (753, 81, 672)
    assert [(int(t["elf_va"], 16), t["size_bytes"]) for t in manifest] == selected[256:384]
    source = SOURCE.read_bytes()
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    all_slots = 0
    listing_slots = pcode_slots = c_count = exact = missing_rows = extra_rows = 0
    for i, (target, pre, assembly, row) in enumerate(zip(manifest, source_index, source_rows, raw), 1):
        va, size, offset = int(target["elf_va"], 16), target["size_bytes"], int(target["file_offset"], 16)
        assert (pre["index"], assembly["index"], row["index"]) == (i, i, i)
        assert sum(base <= va and va + size <= base + length and offset == file_off + va - base
                   for base, file_off, length in loads) == 1
        body = source[offset:offset + size]
        digest = hashlib.sha256(body).hexdigest()
        assert len(body) == size and digest == target["body_sha256"] == pre["source_body_sha256"]
        assert digest == row["original_body_sha256"] == row["copy_memory_body_sha256"] and row["body_bytes_match"]
        decoded = list(decoder.disasm(body, va))
        slots = size // 4
        assert len(decoded) == len(assembly["instructions"]) == len(row["instructions"]) == slots
        assert row["instruction_slots"] == row["instruction_count_observed"] == slots
        dbva = int(row["database_va"], 16)
        for local, ins in enumerate(decoded):
            item = assembly["instructions"][local]
            ghidra = row["instructions"][local]
            assert (item["va"], item["word_le"], item["mnemonic"], item["operands"]) == (
                hex(ins.address), body[local * 4:local * 4 + 4].hex(), ins.mnemonic, ins.op_str)
            assert int(ghidra.split(":", 1)[0], 16) == dbva + local * 4
            assert ghidra.split(":", 1)[1].strip()
        assert row["function_body_address_count"] == row["fde_member_bytes"] + row["extra_body_bytes"]
        assert row["fde_missing_bytes"] == size - row["fde_member_bytes"]
        if i < 128:
            assert row["boundary_classification"] == "GHIDRA_BODY_EQUALS_FDE_RANGE"
            assert row["fde_member_bytes"] == row["function_body_address_count"] == size
            assert row["fde_missing_bytes"] == row["extra_body_bytes"] == 0
        else:
            assert row["boundary_classification"] == "GHIDRA_BODY_PREFIX_OF_FDE_RANGE"
            assert row["fde_member_bytes"] == size - 4 and row["fde_missing_bytes"] == 4
            assert row["extra_body_bytes"] == 0 and row["fde_missing_ranges"] == ["0x2d99c..0x2d99f"]
        assert row["c_like_present"] and row["c_like_text"].strip() and not row["failure"]
        assert hashlib.sha256(row["c_like_text"].encode()).hexdigest() == row["c_like_sha256"]
        all_slots += slots
        listing_slots += row["instruction_count_observed"]
        pcode_slots += row["pcode_instruction_count"]
        c_count += bool(row["c_like_present"])
        exact += row["boundary_classification"] == "GHIDRA_BODY_EQUALS_FDE_RANGE"
        missing_rows += row["fde_missing_bytes"] > 0
        extra_rows += row["extra_body_bytes"] > 0
    assert (all_slots, listing_slots, pcode_slots, c_count, exact, missing_rows, extra_rows) == (
        1108, 1108, 1076, 128, 127, 1, 0)
    candidates = load(REPORT / "candidate_index.json")
    for key, expected in (("target_count", 128), ("source_instruction_slots", all_slots),
                          ("ghidra_instruction_slots", listing_slots),
                          ("ghidra_pcode_instruction_slots", pcode_slots),
                          ("ghidra_c_like_count", c_count), ("ghidra_exact_fde_c_like_count", exact),
                          ("rows_with_missing_fde_bytes", missing_rows), ("rows_with_extra_body_bytes", extra_rows)):
        assert candidates[key] == seal[key if key != "target_count" else "target_fde_candidate_count"] == expected
    assert len(candidates["candidates"]) == 128
    correction = load(REPORT / "transient_gap_correction/results/128_2d8ec.json")
    receipt = load(REPORT / "transient_gap_correction/ghidra_command.json")
    assert receipt["status"] == "OUTPUT_READY" and receipt["exit_code"] == 0 and receipt["termination"] is None
    assert "-readOnly" in receipt["command"] and "-noanalysis" in receipt["command"] and receipt["fresh_imports"] == 0
    assert receipt["script_sha256"] == sha(ROOT / "scripts/task_190_codex_internal/RepairMembership190.java")
    assert receipt["target_tsv_sha256"] == sha(REPORT / "transient_gap_correction/anomaly.tsv")
    assert receipt["result_sha256"] == {"results/128_2d8ec.json": sha(REPORT / "transient_gap_correction/results/128_2d8ec.json")}
    assert correction["original_function_fde_membership_bits"] == "1" * 176 + "0" * 4
    assert correction["corrected_function_fde_membership_bits"] == "1" * 180
    assert correction["other_function_byte_count"] == 0 and correction["memory_unchanged_after_rollback"]
    assert correction["full_fde_instruction_count"] == 45 and correction["full_fde_pcode_ops"] == 147
    assert correction["temporary_old_function_removed"] and correction["temporary_full_fde_function_created"]
    assert correction["c_like_nonempty"] and correction["c_like_text"].strip() and not correction["error"]
    assert hashlib.sha256(correction["c_like_text"].encode()).hexdigest() == seal["transient_correction_c_like_sha256"]
    sample = load(REPORT / "independent_verification.json")["sample"]
    assert len(sample) == 128 and len({(x["index"], x["slot"]) for x in sample}) == 128
    assert len(sample) / all_slots >= .1
    for item in sample:
        i, local = item["index"], item["slot"]
        target = manifest[i - 1]
        va, offset = int(target["elf_va"], 16), int(target["file_offset"], 16)
        word = source[offset + local * 4:offset + local * 4 + 4]
        decoded = list(decoder.disasm(word, va + local * 4))
        assert len(decoded) == 1
        assert item["source_va"] == hex(va + local * 4) and item["source_word_le"] == word.hex()
        assert item["capstone"] == source_rows[i - 1]["instructions"][local]
        assert item["capstone"]["mnemonic"] == decoded[0].mnemonic
        assert item["ghidra"] == raw[i - 1]["instructions"][local]
    master = (REPORT / "01_MASTER_REPORT.md").read_text(encoding="utf8")
    assert "PARTIAL_STATIC_FDE_BOUNDARY" in master and "128/128" in master and "127/128" in master
    print(json.dumps({"result": "PASS", "task": "TASK_190", "revision": 1,
                      "bodies": 128, "source_slots": all_slots, "listing_slots": listing_slots,
                      "pcode_slots": pcode_slots, "original_exact": exact,
                      "boundary_assumed": 1, "spread_samples": len(sample),
                      "seal_sha256": sha(REPORT / "COMPLETE.json")}))


if __name__ == "__main__":
    main()
