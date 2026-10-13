"""Independently verify the three pinned internal SO research batches.

This is a read-only source audit.  An unwind FDE is only a candidate entry/range;
the audit intentionally makes no source-level or behavioral recovery claim.
"""

import hashlib
import json
import re
from pathlib import Path

from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile


ROOT = Path(__file__).resolve().parents[3]
SOURCE_ROOT = Path(
    "F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a"
)
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
SPECS = {
    183: "libMTGif.so",
    184: "libVERenderer.so",
    185: "libPVGColorFunctions.so",
}


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def task_json(path: Path) -> dict:
    match = re.search(r"```json\s*(\{.*?\})\s*```", path.read_text(encoding="utf-8"), re.S)
    assert match is not None, path
    return json.loads(match.group(1))


def verify(number: int, library: str) -> dict:
    task_path = ROOT / f"RULES/TASK/TASK_{number}_SO45_CODEX_INTERNAL_ACTIVE.md"
    manifest_path = ROOT / f".ai/ceo/reviews/TASK_{number}_internal_targets.json"
    task = task_json(task_path)
    manifest_bytes = manifest_path.read_bytes()
    manifest = json.loads(manifest_bytes)
    source_path = SOURCE_ROOT / library
    source_bytes = source_path.read_bytes()

    assert task["task_id"] == manifest["task_id"] == f"TASK_{number}"
    assert task["revision"] == manifest["revision"] == 1
    assert task["status"] == "ACTIVE"
    assert task["standard_sha256"] == STANDARD_SHA
    assert task["target_manifest_sha256"] == sha(manifest_bytes)
    assert task["target_candidate_count"] == manifest["selected_count"] == len(manifest["targets"])
    assert manifest["source_library"] == library
    assert manifest["source_sha256"] == task["source_libraries"][library]["sha256"] == sha(source_bytes)
    assert manifest["original_file_bytes"] == len(source_bytes)

    with source_path.open("rb") as stream:
        elf = ELFFile(stream)
        assert elf["e_machine"] == "EM_AARCH64"
        fde = {(int(e["initial_location"]), int(e["address_range"]))
               for e in elf.get_dwarf_info().EH_CFI_entries() if isinstance(e, FDE)}
        dynsym = elf.get_section_by_name(".dynsym")
        exports = {int(s["st_value"]) for s in dynsym.iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and int(s["st_size"]) > 0
                   and s["st_shndx"] != "SHN_UNDEF"}
        executable_loads = [(int(p["p_vaddr"]), int(p["p_vaddr"]) + int(p["p_filesz"]),
                             int(p["p_offset"])) for p in elf.iter_segments()
                            if p["p_type"] == "PT_LOAD" and (int(p["p_flags"]) & 1)]

    assert manifest["all_fde_ranges"] == len(fde)
    assert manifest["defined_nonzero_export_vas"] == len(exports)
    assert task["source_libraries"][library]["defined_nonzero_export_vas"] == len(exports)
    assert manifest["all_nonexport_fde_candidates"] == len({start for start, _ in fde} - exports)
    assert manifest["remaining_nonselected_candidates"] == (
        manifest["all_nonexport_fde_candidates"] - len(manifest["targets"])
    )

    seen = set()
    body_bytes = 0
    instruction_slots = 0
    for row in manifest["targets"]:
        va = int(row["elf_va"], 16)
        offset = int(row["file_offset"], 16)
        size = int(row["size_bytes"])
        assert va not in seen
        seen.add(va)
        assert (va, size) in fde
        assert va not in exports
        assert size > 0 and size % 4 == 0
        assert row["instruction_slots"] == size // 4
        assert any(lo <= va and va + size <= hi and offset == file_base + va - lo
                   for lo, hi, file_base in executable_loads)
        assert sha(source_bytes[offset:offset + size]) == row["body_sha256"]
        body_bytes += size
        instruction_slots += size // 4

    assert [int(row["elf_va"], 16) for row in manifest["targets"]] == sorted(seen)
    return {"task": number, "library": library, "selected": len(seen),
            "original_body_bytes": body_bytes, "instruction_slots": instruction_slots,
            "remaining_nonselected_fde_candidates": manifest["remaining_nonselected_candidates"],
            "task_sha256": sha(task_path.read_bytes()), "manifest_sha256": sha(manifest_bytes),
            "source_sha256": sha(source_bytes)}


def main() -> None:
    assert sha((ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt").read_bytes()) == STANDARD_SHA
    flag = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    assert not (flag.exists() and flag.read_text(encoding="utf-8").strip().upper() == "TRUE")
    result = [verify(number, library) for number, library in SPECS.items()]
    print(json.dumps({"result": "PASS", "batches": result}, ensure_ascii=False, sort_keys=True))


if __name__ == "__main__":
    main()
