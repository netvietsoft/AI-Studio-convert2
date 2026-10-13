"""Independent CEO check of the corrected TASK_186 evidence, without writing to it."""
import hashlib
import json
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_186_REPORT_R2"
R1 = ROOT / "RULES/REPORT/TASK_186_REPORT_R1"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGColorFunctions.so")
TARGET = ROOT / ".ai/ceo/reviews/TASK_186_internal_targets.json"
TASK = ROOT / "RULES/TASK/TASK_186_SO45_CODEX_INTERNAL_ACTIVE.md"


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def load(path):
    return json.loads(path.read_text(encoding="utf8"))


def main():
    seal = load(REPORT / "COMPLETE.json")
    assert seal["task_id"] == "TASK_186" and seal["revision"] == 2 and seal["status"] == "COMPLETE"
    assert sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == seal["standard_sha256"]
    assert sha(TASK) == seal["task_sha256"] and sha(TARGET) == seal["target_manifest_sha256"]
    assert sha(SOURCE) == seal["original_so_sha256"] and sha(R1 / "COMPLETE.json") == seal["r1_seal_sha256"]
    present = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {"COMPLETE.json", "PROGRESS.json"}
    assert set(seal["files"]) == present
    for relative, expected in seal["files"].items():
        assert sha(REPORT / relative) == expected, relative
    for relative, expected in seal["code_files"].items():
        assert sha(ROOT / relative) == expected, relative
    inventory = load(REPORT / "r1_reference_inventory.json")
    for section in ("report_files", "code_files", "project_files"):
        for relative, expected in inventory["inventory"][section].items():
            path = R1 / relative if section == "report_files" else ROOT / relative
            assert sha(path) == expected, relative
    assert len(inventory["inventory"]["report_files"]) == 35
    assert len(inventory["inventory"]["code_files"]) == 6
    assert len(inventory["inventory"]["project_files"]) == 9
    assert inventory["failed_serializer_attempt"]["status"] == "PARTIAL_OR_FAILED"
    assert inventory["successful_corrected_retry"]["status"] == "OUTPUT_READY"

    targets = load(TARGET)["targets"]
    body_report = load(REPORT / "body_verification.json")
    instruction_report = load(REPORT / "instruction_verification.json")
    raw_rows = []
    for name in ("chunk_00_retry1", "chunk_01", "chunk_02", "chunk_03"):
        raw_rows += [json.loads(line) for line in (R1 / name / "ghidra_raw.ndjson").read_text(encoding="utf8").splitlines() if line]
    source_rows = [json.loads(line) for line in (R1 / "source_assembly.ndjson").read_text(encoding="utf8").splitlines() if line]
    assert len(targets) == len(raw_rows) == len(source_rows) == len(body_report["rows"]) == 128
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf["e_machine"] == "EM_AARCH64"
        fdes = sorted((int(x["initial_location"]), int(x["address_range"])) for x in elf.get_dwarf_info().EH_CFI_entries() if isinstance(x, FDE) and int(x["address_range"]) > 0)
        exports = {int(x["st_value"]) for x in elf.get_section_by_name(".dynsym").iter_symbols() if x["st_info"]["type"] == "STT_FUNC" and x["st_shndx"] != "SHN_UNDEF" and int(x["st_size"]) > 0}
        loads = [(int(x["p_vaddr"]), int(x["p_offset"]), int(x["p_filesz"])) for x in elf.iter_segments() if x["p_type"] == "PT_LOAD"]
    selected = [(va, size) for va, size in fdes if va not in exports][128:256]
    assert len(fdes) == 753 and len(exports) == 81 and len(selected) == 128
    source = SOURCE.read_bytes()
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    slots = []
    for idx, (target, raw, source_row, reported, (va, size)) in enumerate(zip(targets, raw_rows, source_rows, body_report["rows"], selected), 1):
        offset = int(target["file_offset"], 16)
        assert (int(target["elf_va"], 16), target["size_bytes"]) == (va, size)
        assert sum(base <= va and va + size <= base + length and offset == off + va - base for base, off, length in loads) == 1
        body = source[offset:offset + size]
        body_hash = hashlib.sha256(body).hexdigest()
        assert body_hash == target["body_sha256"] == reported["original_body_sha256"] == reported["ghidra_raw_memory_body_sha256"] == raw["copy_memory_body_sha256"]
        assert reported["index"] == raw["index"] == source_row["index"] == idx
        assert raw["fde_member_bytes"] == raw["function_body_address_count"] == size
        assert raw["fde_missing_bytes"] == raw["extra_body_bytes"] == 0 and raw["fde_missing_ranges"] == []
        assert raw["boundary_classification"] == reported["boundary_classification"] == "GHIDRA_BODY_EQUALS_FDE_RANGE"
        assert hashlib.sha256(raw["c_like_text"].encode("utf8")).hexdigest() == reported["c_like_sha256"]
        decoded = list(decoder.disasm(body, va))
        assert len(decoded) == len(raw["instructions"]) == len(source_row["instructions"]) == size // 4
        for local, ins in enumerate(decoded):
            src = source_row["instructions"][local]
            ghidra = raw["instructions"][local]
            assert int(src["va"], 16) == ins.address and src["word_le"] == body[local * 4:local * 4 + 4].hex()
            assert src["mnemonic"] == ins.mnemonic and src["operands"] == ins.op_str
            assert int(ghidra.split(":", 1)[0], 16) == ins.address + 0x100000
            assert ghidra.split(":", 1)[1].strip().split(" ", 1)[0].lower() == ins.mnemonic.lower()
            slots.append((idx, local, ins, src, ghidra, offset + local * 4))
    assert len(slots) == seal["source_instruction_slots_redecoded"] == 790
    samples = instruction_report["samples"]
    positions = [k * (len(slots) - 1) // (79 - 1) for k in range(79)]
    assert len(samples) == 79 and len(set(positions)) == 79 and len({x["index"] for x in samples}) == 57
    for position, sample in zip(positions, samples):
        index, local, ins, src, ghidra, offset = slots[position]
        assert (sample["global_slot"], sample["index"], sample["local_slot"]) == (position, index, local)
        assert int(sample["elf_va"], 16) == ins.address and int(sample["source_file_offset"], 16) == offset
        assert sample["original_word_le"] == src["word_le"] and sample["capstone_mnemonic"] == ins.mnemonic
        assert sample["capstone_operands"] == ins.op_str and sample["ghidra_listing_text"] == ghidra
    master = (REPORT / "01_MASTER_REPORT.md").read_text(encoding="utf8")
    assert "zero boundary-limited exceptional rows" in master and "does not establish behavioral or pixel equivalence" in master
    print(json.dumps({"result": "PASS", "task": "TASK_186", "revision": 2,
                      "bodies": 128, "source_and_ghidra_slots": len(slots), "sampled": len(samples),
                      "r1_inventory": sum(len(x) for x in inventory["inventory"].values()),
                      "seal_sha256": sha(REPORT / "COMPLETE.json")}))


if __name__ == "__main__":
    main()
