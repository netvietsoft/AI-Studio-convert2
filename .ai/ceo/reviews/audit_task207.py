"""Independent source/raw census for the sealed TASK_207 research slice."""

import hashlib
import json
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
REPORT = ROOT / "RULES/REPORT/TASK_207_REPORT_R1"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_207_internal_targets.json"
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libLayerFlow.so")
SOURCE_SHA = "ef8d1581038778b72abca3ca8fd5046e49fd44e0465871b023647fe42a582262"
SEAL_SHA = "abe172a57571f93c0781e45d6dd193910021b9f49717df2222779ce72f8f6964"


def sha(data):
    return hashlib.sha256(data).hexdigest()


def ndjson(path):
    return [json.loads(line) for line in path.read_text(encoding="utf-8").splitlines() if line]


def check(condition, message):
    if not condition:
        raise AssertionError(message)


def main():
    check(sha(SOURCE.read_bytes()) == SOURCE_SHA, "source SHA")
    check(sha((REPORT / "COMPLETE.json").read_bytes()) == SEAL_SHA, "seal SHA")
    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    seal = json.loads((REPORT / "COMPLETE.json").read_text(encoding="utf-8"))
    check(sha(MANIFEST.read_bytes()) == seal["target_manifest_sha256"], "manifest SHA")
    for name, expected in seal["files"].items():
        check(sha((REPORT / name).read_bytes()) == expected, "report hash: " + name)
    for name, expected in seal["code_files"].items():
        check(sha((ROOT / name).read_bytes()) == expected, "code hash: " + name)
    scratch = ROOT / "RESEARCH_WORK/TASK_207_R1/ghidra_project"
    for name, expected in seal["scratch_project_files"].items():
        check(sha((scratch / name).read_bytes()) == expected, "scratch hash: " + name)
    source_index = json.loads((REPORT / "source_index.json").read_text(encoding="utf-8"))
    candidate_index = json.loads((REPORT / "candidate_index.json").read_text(encoding="utf-8"))
    assembly = ndjson(REPORT / "source_assembly.ndjson")
    raw = [row for chunk in range(8) for row in ndjson(REPORT / f"chunk_{chunk:02d}/ghidra_raw.ndjson")]
    check(len(raw) == len(assembly) == len(manifest["targets"]) == 128, "row census")
    raw.sort(key=lambda row: row["index"])
    check([row["index"] for row in raw] == list(range(1, 129)), "row index order")
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    count_slots = count_listing = count_pcode = count_ops = count_exact = count_gap = 0
    gap_bytes = 0
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        entries = [entry for entry in elf.get_dwarf_info().EH_CFI_entries()
                   if entry.__class__.__name__ == "FDE"]
        exports = {int(sym["st_value"]) for sym in elf.get_section_by_name(".dynsym").iter_symbols()
                   if sym["st_info"]["type"] == "STT_FUNC"
                   and sym["st_shndx"] != "SHN_UNDEF" and int(sym["st_size"]) > 0}
        candidates = sorted((int(x["initial_location"]), int(x["address_range"]))
                            for x in entries if int(x["initial_location"]) not in exports)
        check(len(entries) == 8935 and len(exports) == 5082 and len(candidates) == 3853, "ELF census")
        segments = [segment for segment in elf.iter_segments() if segment["p_type"] == "PT_LOAD"]
        for i, (target, source_row, asm_row, ghidra) in enumerate(zip(
                manifest["targets"], source_index["targets"], assembly, raw)):
            va, size = candidates[128 + i]
            check((target["global_nonexport_fde_index"], int(target["elf_va"], 16), target["size_bytes"])
                  == (128 + i, va, size), f"target {i}")
            check(source_row["index"] == asm_row["index"] == ghidra["index"] == i + 1, f"row {i}")
            segment = next((s for s in segments if int(s["p_vaddr"]) <= va
                            and va + size <= int(s["p_vaddr"]) + int(s["p_filesz"])), None)
            check(segment is not None, f"PT_LOAD {i}")
            file_offset = int(segment["p_offset"]) + va - int(segment["p_vaddr"])
            stream.seek(file_offset)
            body = stream.read(size)
            check(len(body) == size and sha(body) == target["body_sha256"]
                  == source_row["source_body_sha256"] == ghidra["original_body_sha256"]
                  == ghidra["copy_memory_body_sha256"], f"body {i}")
            check(file_offset == int(target["file_offset"], 16)
                  == int(source_row["file_offset"], 16), f"file offset {i}")
            decoded = list(md.disasm(body, va))
            check(len(decoded) == size // 4 == len(asm_row["instructions"])
                  == len(ghidra["instruction_pcode"]), f"slot count {i}")
            check(ghidra["body_bytes_match"], f"Ghidra body hash {i}")
            for slot, (ins, reported, pcode) in enumerate(zip(
                    decoded, asm_row["instructions"], ghidra["instruction_pcode"])):
                word = body[slot * 4:slot * 4 + 4].hex()
                check(ins.address == int(reported["va"], 16) and reported["word_le"] == word
                      == pcode["word_le"], f"source word {i}:{slot}")
                check(ins.mnemonic == reported["mnemonic"] and ins.op_str == reported["operands"],
                      f"Capstone text {i}:{slot}")
                if not pcode["missing_instruction"]:
                    count_listing += 1
                    if pcode["pcode_ops"]:
                        count_pcode += 1
                        count_ops += len(pcode["pcode_ops"])
            check(sha(ghidra["c_like_text"].encode("utf-8")) == ghidra["c_like_sha256"],
                  f"C-like hash {i}")
            check(ghidra["c_like_present"] and len(ghidra["fde_membership_bits"]) == size,
                  f"membership {i}")
            members = ghidra["fde_membership_bits"].count("1")
            missing = ghidra["fde_membership_bits"].count("0")
            check(members == ghidra["fde_member_bytes"]
                  and missing == ghidra["fde_missing_bytes"]
                  and members + missing == size and ghidra["extra_body_bytes"] == 0,
                  f"membership accounting {i}")
            count_exact += missing == 0
            count_gap += missing > 0
            gap_bytes += missing
            count_slots += len(decoded)
    check((count_slots, count_listing, count_pcode, count_ops, count_exact, count_gap, gap_bytes)
          == (3655, 3563, 3556, 11508, 122, 6, 368), "aggregate mismatch")
    check(candidate_index["source_instruction_slots"] == count_slots
          and candidate_index["ghidra_listing_positions"] == count_listing
          and candidate_index["ghidra_nonempty_pcode_positions"] == count_pcode,
          "candidate index aggregate")
    print(json.dumps({"task":"TASK_207","status":"INDEPENDENT_CENSUS_MATCH",
                      "candidate_rows":128,"source_slots":count_slots,"listings":count_listing,
                      "nonempty_pcode":count_pcode,"pcode_ops":count_ops,"exact_bodies":count_exact,
                      "gap_rows":count_gap,"gap_bytes":gap_bytes,"sealed_report_files":len(seal["files"]),
                      "sealed_code_files":len(seal["code_files"]),
                      "sealed_scratch_files":len(seal["scratch_project_files"])}, sort_keys=True))


if __name__ == "__main__":
    main()
