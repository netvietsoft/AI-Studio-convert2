"""Independent, read-only CEO check of TASK_186 R1 source and tool provenance."""
import hashlib
import json
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_186_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_186_SO45_CODEX_INTERNAL_ACTIVE.md"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_186_internal_targets.json"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGColorFunctions.so")
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
VALID_CHUNKS = ("chunk_00_retry1", "chunk_01", "chunk_02", "chunk_03")


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def file_sha(path):
    return sha(path.read_bytes())


def read_json(path):
    return json.loads(path.read_text(encoding="utf8"))


def ndjson(path):
    return [json.loads(line) for line in path.read_text(encoding="utf8").splitlines() if line]


def main():
    assert file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == STANDARD_SHA
    seal = read_json(REPORT / "COMPLETE.json")
    assert seal["task_id"] == "TASK_186" and seal["revision"] == 1 and seal["status"] == "COMPLETE"
    assert seal["task_sha256"] == file_sha(TASK) and seal["standard_sha256"] == STANDARD_SHA
    assert seal["target_manifest_sha256"] == file_sha(MANIFEST)
    assert seal["original_so_sha256"] == file_sha(SOURCE)
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json"}
    assert actual == set(seal["files"])
    assert len(actual) == 35 and len(seal["code_files"]) == 6 and len(seal["scratch_project_files"]) == 9
    for relative, expected in seal["files"].items():
        assert file_sha(REPORT / relative) == expected, relative
    for key in ("code_files", "research_files", "scratch_files", "scratch_project_files"):
        for relative, expected in seal.get(key, {}).items():
            path = (ROOT / relative).resolve()
            assert path.is_relative_to(ROOT) and file_sha(path) == expected, relative
    source = SOURCE.read_bytes()
    pins = read_json(MANIFEST)["targets"]
    source_rows = read_json(REPORT / "source_index.json")["targets"]
    candidate_rows = read_json(REPORT / "candidate_index.json")["candidates"]
    assembly_rows = ndjson(REPORT / "source_assembly.ndjson")
    assert len(pins) == len(source_rows) == len(candidate_rows) == len(assembly_rows) == 128
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf["e_machine"] == "EM_AARCH64"
        fdes = {(int(entry["initial_location"]), int(entry["address_range"]))
                for entry in elf.get_dwarf_info().EH_CFI_entries() if isinstance(entry, FDE)}
        dyn = elf.get_section_by_name(".dynsym")
        exports = {int(sym["st_value"]) for sym in dyn.iter_symbols()
                   if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF"
                   and int(sym["st_size"]) > 0 and int(sym["st_value"]) > 0}
        loads = [(int(seg["p_vaddr"]), int(seg["p_vaddr"]) + int(seg["p_filesz"]), int(seg["p_offset"]))
                 for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"]
    assert len(fdes) == 753 and len(exports) == 81
    selected = sorted((va, size) for va, size in fdes if va not in exports)[128:256]
    assert len(selected) == 128
    raw_rows = []
    for chunk in VALID_CHUNKS:
        folder = REPORT / chunk
        command = read_json(folder / "ghidra_command.json")
        rows = ndjson(folder / "ghidra_raw.ndjson")
        assert command["exit_code"] == 0 and command["rows"] == len(rows) == 32
        assert command["raw_output_sha256"] == file_sha(folder / "ghidra_raw.ndjson")
        assert command["stdout_sha256"] == file_sha(folder / "ghidra_stdout.log")
        assert command["stderr_sha256"] == file_sha(folder / "ghidra_stderr.log")
        assert command["target_tsv_sha256"] == file_sha(folder / "targets.tsv")
        assert command["script_sha256"] == file_sha(ROOT / "scripts/task_186_codex_internal/ExportInternal186.java")
        assert command["read_only_project"] and command["fresh_imports"] == 0
        assert "-readOnly" in command["command"] and "-noanalysis" in command["command"]
        assert "-max-cpu" in command["command"] and command["elapsed_seconds"] < 1200
        raw_rows.extend(rows)
    assert [row["index"] for row in raw_rows] == list(range(1, 129))
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    original_words = pcode_words = 0
    for index, (pin, src, cand, asm, raw) in enumerate(zip(pins, source_rows, candidate_rows, assembly_rows, raw_rows), 1):
        va, size, off = int(pin["elf_va"], 16), pin["size_bytes"], int(pin["file_offset"], 16)
        assert (va, size) == selected[index - 1] and (va, size) in fdes and va not in exports
        assert any(lo <= va and va + size <= hi and off == base + va - lo for lo, hi, base in loads)
        body = source[off:off + size]
        assert len(body) == size and sha(body) == pin["body_sha256"]
        assert (src["index"], cand["index"], asm["index"], raw["index"]) == (index,) * 4
        assert src["source_body_sha256"] == cand["original_body_sha256"] == raw["original_body_sha256"] == sha(body)
        assert cand["copy_memory_body_sha256"] == raw["copy_memory_body_sha256"] == sha(body)
        assert cand["fde_size_bytes"] == raw["fde_size_bytes"] == size
        assert cand["fde_member_bytes"] == raw["fde_member_bytes"] == size
        assert cand["fde_missing_bytes"] == raw["fde_missing_bytes"] == 0
        assert cand["extra_body_bytes"] == raw["extra_body_bytes"] == 0
        assert cand["function_body_address_count"] == raw["function_body_address_count"] == size
        assert cand["boundary_classification"] == raw["boundary_classification"] == "GHIDRA_BODY_EQUALS_FDE_RANGE"
        assert cand["c_like_sha256"] == raw["c_like_sha256"] == sha(raw["c_like_text"].encode("utf8"))
        assert cand["c_like_present"] and raw["c_like_present"] and raw["c_like_text"].strip()
        decoded = list(decoder.disasm(body, va))
        assert len(decoded) == size // 4 == len(asm["instructions"]) == len(raw["instructions"])
        delta = int(raw["database_va"], 16) - va
        for position, (instruction, source_instruction, ghidra_instruction) in enumerate(
                zip(decoded, asm["instructions"], raw["instructions"])):
            expected_word = body[position * 4:position * 4 + 4]
            assert instruction.address == int(source_instruction["va"], 16)
            assert expected_word.hex() == source_instruction["word_le"]
            assert instruction.mnemonic == source_instruction["mnemonic"]
            assert instruction.op_str == source_instruction["operands"]
            ghidra_va, ghidra_text = ghidra_instruction.split(":", 1)
            assert int(ghidra_va, 16) == instruction.address + delta
            assert ghidra_text.strip().split(" ", 1)[0].lower() == instruction.mnemonic.lower()
        original_words += len(decoded)
        pcode_words += raw["pcode_instruction_count"]
    assert original_words == 790 and pcode_words == 758
    assert seal["source_instruction_slots"] == seal["ghidra_instruction_slots_observed"] == 790
    assert seal["ghidra_pcode_instruction_slots"] == 758
    assert seal["ghidra_c_like_function_count"] == seal["exact_fde_boundary_c_like_count"] == 128
    assert seal["spread_verification_instruction_words"] == 36
    master = (REPORT / "01_MASTER_REPORT.md").read_text(encoding="utf8")
    assert "those C-like outputs are boundary-limited" in master
    print(json.dumps({"result": "EVIDENCE_MATCHES_WITH_REPORT_DEFECTS", "source_bodies": 128,
                      "full_body_memberships": 128, "independent_words_redecoded": original_words,
                      "worker_spread_words": 36, "total_words": 790,
                      "report_boundary_sentence_conflicts_with_128_exact": True,
                      "seal_sha256": file_sha(REPORT / "COMPLETE.json")}))


if __name__ == "__main__":
    main()
