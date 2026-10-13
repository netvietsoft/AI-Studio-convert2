"""Independent CEO ELF, sealed provenance, boundary, and coverage check for TASK_191."""

import hashlib
import json
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_191_REPORT_R1"
TASK = ROOT / "RULES/TASK/TASK_191_SO45_CODEX_INTERNAL_ACTIVE.md"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_191_internal_targets.json"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libPVGColorFunctions.so")
PRIOR = ROOT / "RESEARCH_WORK/TASK_190_R1/ghidra_project"
PROJECT = ROOT / "RESEARCH_WORK/TASK_191_R1/ghidra_project"


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def load(path):
    return json.loads(path.read_text(encoding="utf8"))


def ndjson(path):
    return [json.loads(line) for line in path.read_text(encoding="utf8").splitlines() if line]


def hashes(folder):
    return {p.relative_to(folder).as_posix(): sha(p) for p in folder.rglob("*") if p.is_file()}


def zero_ranges(bits, va):
    out = []
    start = None
    for offset, bit in enumerate(bits + "1"):
        if bit == "0" and start is None:
            start = offset
        elif bit == "1" and start is not None:
            out.append(f"0x{va + start:x}..0x{va + offset - 1:x}")
            start = None
    return out


def main():
    seal = load(REPORT / "COMPLETE.json")
    assert (seal["task_id"], seal["revision"], seal["status"], seal["research_disposition"]) == (
        "TASK_191", 1, "COMPLETE", "PARTIAL_STATIC_FDE_BOUNDARY")
    assert sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == seal["standard_sha256"]
    assert sha(TASK) == seal["task_sha256"] and sha(MANIFEST) == seal["target_manifest_sha256"]
    assert sha(SOURCE) == seal["original_so_sha256"]
    actual = {p.relative_to(REPORT).as_posix() for p in REPORT.rglob("*") if p.is_file()} - {
        "COMPLETE.json", "PROGRESS.json"}
    assert actual == set(seal["files"]) and len(actual) == 29
    for relative, digest in seal["files"].items():
        assert sha(REPORT / relative) == digest, relative
    assert len(seal["code_files"]) == 5
    for relative, digest in seal["code_files"].items():
        assert sha(ROOT / relative) == digest, relative
    project_hashes = hashes(PROJECT)
    assert len(project_hashes) == 9 and hashes(PRIOR) == project_hashes == seal["scratch_project_files"]
    assert load(REPORT / "project_copy_receipt.json")["private_copy_file_sha256"] == project_hashes
    post = load(REPORT / "project_postrun_receipt.json")
    assert post["file_sha256"] == project_hashes and post["pre_post_hashes_match"]

    manifest = load(MANIFEST)["targets"]
    index = load(REPORT / "source_index.json")["targets"]
    assembly = ndjson(REPORT / "source_assembly.ndjson")
    raw = []
    for chunk in range(4):
        folder = REPORT / f"chunk_{chunk:02d}"
        command = load(folder / "ghidra_command.json")
        rows = ndjson(folder / "ghidra_raw.ndjson")
        assert len(rows) == command["rows"] == 16
        assert [r["index"] for r in rows] == list(range(1 + 16 * chunk, 17 + 16 * chunk))
        assert command["status"] == "OUTPUT_READY" and command["exit_code"] == 0
        assert command["termination"] is None and command["fresh_imports"] == 0 and command["read_only_project"]
        assert command["elapsed_seconds"] <= command["timeout_seconds"] <= 1200
        assert "-readOnly" in command["command"] and "-noanalysis" in command["command"]
        assert "-import" not in command["command"] and "-max-cpu" in command["command"]
        assert command["script_sha256"] == sha(ROOT / "scripts/task_191_codex_internal/ExportInternal191.java")
        for field, name in (("stdout_sha256", "ghidra_stdout.log"), ("stderr_sha256", "ghidra_stderr.log"),
                            ("raw_output_sha256", "ghidra_raw.ndjson"), ("target_tsv_sha256", "targets.tsv")):
            assert command[field] == sha(folder / name), (chunk, field)
        raw.extend(rows)
    assert len(manifest) == len(index) == len(assembly) == len(raw) == 64

    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf["e_machine"] == "EM_AARCH64"
        fdes = {(int(f["initial_location"]), int(f["address_range"]))
                for f in elf.get_dwarf_info().EH_CFI_entries() if isinstance(f, FDE) and int(f["address_range"]) > 0}
        exports = {int(s["st_value"]) for s in elf.get_section_by_name(".dynsym").iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF"
                   and int(s["st_value"]) > 0 and int(s["st_size"]) > 0}
        loads = [(int(s["p_vaddr"]), int(s["p_offset"]), int(s["p_filesz"]))
                 for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
    selected = sorted((va, size) for va, size in fdes if va not in exports)
    assert (len(fdes), len(exports), len(selected)) == (753, 81, 672)
    assert [(int(t["elf_va"], 16), t["size_bytes"]) for t in manifest] == selected[384:448]
    source = SOURCE.read_bytes()
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    total = listing = pcode_slots = pcode_ops = exact = missing_rows = extra_rows = c_count = 0
    for number, (target, pre, asm, row) in enumerate(zip(manifest, index, assembly, raw), 1):
        va, size, offset = int(target["elf_va"], 16), target["size_bytes"], int(target["file_offset"], 16)
        assert pre["index"] == asm["index"] == row["index"] == number
        assert sum(base <= va and va + size <= base + length and offset == file_off + va - base
                   for base, file_off, length in loads) == 1
        body = source[offset:offset + size]
        digest = hashlib.sha256(body).hexdigest()
        assert len(body) == size and digest == target["body_sha256"] == pre["source_body_sha256"]
        assert digest == row["original_body_sha256"] == row["copy_memory_body_sha256"] and row["body_bytes_match"]
        slots = size // 4
        decoded = list(decoder.disasm(body, va))
        assert len(decoded) == len(asm["instructions"]) == len(row["instruction_pcode"]) == slots
        assert row["instruction_slots"] == slots
        dbva = int(row["database_va"], 16)
        seen_listing = seen_pcode = seen_ops = 0
        for local, ins in enumerate(decoded):
            recorded = asm["instructions"][local]
            pc = row["instruction_pcode"][local]
            word = body[4 * local:4 * local + 4]
            assert recorded == {"va": hex(ins.address), "word_le": word.hex(),
                                "mnemonic": ins.mnemonic, "operands": ins.op_str}
            assert int(pc["database_va"], 16) == dbva + 4 * local and pc["word_le"] == word.hex()
            if pc["missing_instruction"]:
                assert not pc["assembly"] and not pc["pcode_ops"]
            else:
                assert pc["assembly"]
                seen_listing += 1
            seen_pcode += bool(pc["pcode_ops"])
            seen_ops += len(pc["pcode_ops"])
        assert seen_listing == row["instruction_count_observed"] == len(row["instructions"])
        assert seen_pcode == row["pcode_instruction_count"] and seen_ops == row["pcode_op_count"]
        bits = row["fde_membership_bits"]
        assert len(bits) == size and set(bits) <= {"0", "1"}
        assert bits.count("1") == row["fde_member_bytes"]
        assert bits.count("0") == row["fde_missing_bytes"]
        assert row["fde_missing_ranges"] == zero_ranges(bits, va)
        assert row["function_body_address_count"] == row["fde_member_bytes"] + row["extra_body_bytes"]
        assert row["extra_body_bytes"] == 0 and not row["extra_body_ranges"]
        if row["fde_missing_bytes"]:
            assert row["boundary_classification"] == "FDE_HAS_INTERNAL_GAPS_IN_GHIDRA_BODY"
            missing_rows += 1
        else:
            assert row["boundary_classification"] == "GHIDRA_BODY_EQUALS_FDE_RANGE"
            exact += 1
        assert row["c_like_present"] and row["c_like_text"].strip() and not row["failure"]
        assert hashlib.sha256(row["c_like_text"].encode()).hexdigest() == row["c_like_sha256"]
        assert not row["function_metadata_created_in_owned_copy"]
        total += slots
        listing += seen_listing
        pcode_slots += seen_pcode
        pcode_ops += seen_ops
        c_count += 1
        extra_rows += row["extra_body_bytes"] > 0
    assert (total, listing, pcode_slots, pcode_ops, exact, missing_rows, extra_rows, c_count) == (
        6962, 6836, 6817, 29304, 55, 9, 0, 64)
    candidate = load(REPORT / "candidate_index.json")
    assert len(candidate["candidates"]) == 64
    for key, value in (("target_count", 64), ("source_instruction_slots", total),
                       ("ghidra_instruction_slots", listing), ("ghidra_pcode_instruction_slots", pcode_slots),
                       ("ghidra_pcode_ops", pcode_ops), ("ghidra_c_like_count", c_count),
                       ("ghidra_exact_fde_c_like_count", exact), ("rows_with_missing_fde_bytes", missing_rows),
                       ("rows_with_extra_body_bytes", extra_rows)):
        assert candidate[key] == value
    verification = load(REPORT / "independent_verification.json")
    sample = verification["spread_sample"]
    assert len(sample) == 989 and len({(s["index"], s["slot"]) for s in sample}) == 989
    assert len(sample) / total >= .10
    for item in sample:
        number, local = item["index"], item["slot"]
        target = manifest[number - 1]
        va, offset = int(target["elf_va"], 16), int(target["file_offset"], 16)
        word = source[offset + 4 * local:offset + 4 * local + 4]
        decoded = list(decoder.disasm(word, va + 4 * local))
        assert len(decoded) == 1
        assert item["elf_va"] == hex(va + 4 * local) and item["word_le"] == word.hex()
        assert item["capstone"] == decoded[0].mnemonic + " " + decoded[0].op_str
        assert item["ghidra_missing"] == raw[number - 1]["instruction_pcode"][local]["missing_instruction"]
    master = (REPORT / "01_MASTER_REPORT.md").read_text(encoding="utf8")
    assert "PARTIAL_STATIC_FDE_BOUNDARY" in master and "55/64" in master and "9" in master
    print(json.dumps({"result": "PASS", "task": "TASK_191", "revision": 1,
                      "bodies": 64, "source_slots": total, "listing_slots": listing,
                      "pcode_slots": pcode_slots, "pcode_ops": pcode_ops,
                      "original_exact": exact, "gap_rows": missing_rows,
                      "spread_samples": len(sample), "seal_sha256": sha(REPORT / "COMPLETE.json")}))


if __name__ == "__main__":
    main()
