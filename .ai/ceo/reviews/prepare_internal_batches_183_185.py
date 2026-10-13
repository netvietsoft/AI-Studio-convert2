"""Pin three disjoint original-SO unwind candidate batches for Codex workers."""
import hashlib
import json
import os
import sys
import tempfile
from datetime import datetime, timezone
from pathlib import Path

from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[3]
SOURCE = Path("F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a")
sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller, file_sha  # noqa: E402

SPECS = {183: ("libMTGif.so", 51), 184: ("libVERenderer.so", 141),
         185: ("libPVGColorFunctions.so", 128)}
STANDARD = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"


def atomic(path, data):
    fd, temp = tempfile.mkstemp(prefix=".so45-target-", dir=path.parent)
    try:
        with os.fdopen(fd, "wb") as stream:
            stream.write(data)
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temp, path)
    finally:
        if os.path.exists(temp):
            os.unlink(temp)


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested():
        raise RuntimeError("END_AGENT_SESSION=TRUE")
    lease = ctl.ceo_lease(ctl.read_json(ctl.registry))
    assert file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") == STANDARD
    census = json.loads((ROOT / ".ai/ceo/reviews/so45_internal_census_20261013.json").read_text(encoding="utf-8"))
    by_name = {row["library"]: row for row in census["libraries"]}
    for number, (library, take) in SPECS.items():
        source_path = SOURCE / library
        source_sha = file_sha(source_path)
        assert source_sha == by_name[library]["source_sha256"]
        raw = source_path.read_bytes()
        with source_path.open("rb") as stream:
            elf = ELFFile(stream)
            assert elf["e_machine"] == "EM_AARCH64"
            export_vas = {int(sym["st_value"]) for sym in elf.get_section_by_name(".dynsym").iter_symbols()
                          if sym["st_info"]["type"] == "STT_FUNC" and sym["st_shndx"] != "SHN_UNDEF"
                          and int(sym["st_value"]) > 0 and int(sym["st_size"]) > 0}
            fdes = {(int(f["initial_location"]), int(f["address_range"]))
                    for f in elf.get_dwarf_info().EH_CFI_entries()
                    if isinstance(f, FDE) and int(f["address_range"]) > 0}
            loads = [seg for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"]
        assert len(export_vas) == by_name[library]["defined_nonzero_export_vas"]
        assert len(fdes) == by_name[library]["unwind_fde_ranges"]
        nonexport = sorted((va, size) for va, size in fdes if va not in export_vas)
        assert len({va for va, _ in nonexport}) == len(nonexport) == by_name[library]["fde_starts_not_exported_candidates"]
        assert len(nonexport) >= take
        selected = nonexport[:take]
        rows = []
        for va, size in selected:
            assert va % 4 == 0 and size % 4 == 0 and size > 0
            mapped = [(int(seg["p_offset"]) + va - int(seg["p_vaddr"]), seg)
                      for seg in loads if int(seg["p_vaddr"]) <= va
                      and va + size <= int(seg["p_vaddr"]) + int(seg["p_filesz"])]
            assert len(mapped) == 1
            offset, segment = mapped[0]
            body = raw[offset:offset+size]
            assert len(body) == size
            rows.append({"elf_va": f"0x{va:x}", "size_bytes": size,
                         "file_offset": f"0x{offset:x}",
                         "body_sha256": hashlib.sha256(body).hexdigest(),
                         "instruction_slots": size//4})
        payload = {"schema_version": "2.1.2", "task_id": f"TASK_{number}", "revision": 1,
                   "generated_at": datetime.now(timezone.utc).isoformat(),
                   "classification": "UNWIND_FDE_START_NOT_IN_DEFINED_NONZERO_DYNSYM_EXPORTS_CANDIDATE",
                   "source_library": library, "source_sha256": source_sha,
                   "original_file_bytes": len(raw), "defined_nonzero_export_vas": len(export_vas),
                   "all_fde_ranges": len(fdes), "all_nonexport_fde_candidates": len(nonexport),
                   "selection": f"first {take} candidates sorted by ELF VA, exact R1 batch",
                   "selected_count": len(rows), "remaining_nonselected_candidates": len(nonexport)-len(rows),
                   "scope_limit": "FDE candidate does not prove function boundary completeness or all internal functions; no behavior/product claim",
                   "targets": rows}
        output = ROOT / ".ai/ceo/reviews" / f"TASK_{number}_internal_targets.json"
        ctl.authorized(lease, output)
        if output.exists():
            raise RuntimeError("target manifest already exists: " + str(output))
        atomic(output, (json.dumps(payload, indent=2, ensure_ascii=False) + "\n").encode())
        print(json.dumps({"task": number, "source": library, "targets": len(rows),
                          "source_sha256": source_sha, "manifest_sha256": file_sha(output),
                          "body_bytes": sum(row["size_bytes"] for row in rows)}))


if __name__ == "__main__":
    main()
