"""Verify exact ELF/FDE/source evidence and copy the previously analyzed project."""
from __future__ import annotations

import hashlib
import json
import shutil
import struct
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

from common import (FENCE, LEASE_ID, MANIFEST, MANIFEST_SHA, PRIOR_PROJECT,
                    PROJECT, REPORT, SCRATCH, SOURCE, SOURCE_SHA, check_lease,
                    now, sha256, atomic_bytes, write_json)


def path_hashes(folder: Path) -> dict[str, str]:
    return {p.relative_to(folder).as_posix(): sha256(p) for p in sorted(folder.rglob("*")) if p.is_file()}


def main() -> None:
    check_lease()
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError("original source SHA mismatch")
    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    targets = manifest["targets"]
    if (manifest["task_id"], manifest["selected_count"], len(targets), manifest["source_sha256"]) != (
            "TASK_190", 128, 128, SOURCE_SHA):
        raise RuntimeError("target manifest identity/count mismatch")
    if [int(t["elf_va"], 16) for t in targets] != sorted({int(t["elf_va"], 16) for t in targets}):
        raise RuntimeError("target VA order/uniqueness mismatch")

    source_bytes = SOURCE.read_bytes()
    dis = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    rows = []
    assembly = []
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("source architecture mismatch")
        loads = []
        for ix, seg in enumerate(elf.iter_segments()):
            if seg["p_type"] == "PT_LOAD":
                loads.append({"index": ix, "vaddr": int(seg["p_vaddr"]),
                              "offset": int(seg["p_offset"]), "file_size": int(seg["p_filesz"])})
        fdes = [(int(x["initial_location"]), int(x["address_range"]))
                for x in elf.get_dwarf_info().EH_CFI_entries() if isinstance(x, FDE)]
        if len(fdes) != 753:
            raise RuntimeError(f"expected 753 FDEs, got {len(fdes)}")
        fde_set = set(fdes)
        dyn = elf.get_section_by_name(".dynsym")
        exports = [(int(s["st_value"]), int(s["st_size"])) for s in dyn.iter_symbols()
                   if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] != "SHN_UNDEF"
                   and int(s["st_size"]) > 0]
        export_starts = {va for va, _ in exports}
        if len(export_starts) != 81:
            raise RuntimeError(f"expected 81 exported VAs, got {len(export_starts)}")
        candidate_starts = {va for va, size in fdes if va not in export_starts and size > 0}
        if len(candidate_starts) != 672:
            raise RuntimeError(f"expected 672 nonexport FDE starts, got {len(candidate_starts)}")
        sorted_nonexport_fdes = sorted((va, size) for va, size in fdes
                                    if va not in export_starts and size > 0)
        if [(int(t["elf_va"], 16), t["size_bytes"]) for t in targets] != sorted_nonexport_fdes[256:384]:
            raise RuntimeError("TASK_190 rows are not exactly nonexport FDE candidates 256..383")
        prior = json.loads((MANIFEST.parent / "TASK_186_internal_targets.json").read_text(encoding="utf-8"))
        if set(t["elf_va"] for t in targets) & set(t["elf_va"] for t in prior["targets"]):
            raise RuntimeError("TASK_190 target VA overlaps previous TASK_185 batch")

        for ix, target in enumerate(targets, 1):
            va, size, offset = int(target["elf_va"], 16), target["size_bytes"], int(target["file_offset"], 16)
            if (va, size) not in fde_set or va in export_starts or size <= 0 or size % 4:
                raise RuntimeError(f"target {ix} FDE/export/range mismatch")
            covering = [seg for seg in loads if seg["vaddr"] <= va and va + size <= seg["vaddr"] + seg["file_size"]]
            if len(covering) != 1 or covering[0]["offset"] + va - covering[0]["vaddr"] != offset:
                raise RuntimeError(f"target {ix} PT_LOAD translation mismatch")
            body = source_bytes[offset:offset + size]
            actual = hashlib.sha256(body).hexdigest()
            if actual != target["body_sha256"]:
                raise RuntimeError(f"target {ix} original body SHA mismatch")
            ins = list(dis.disasm(body, va))
            instruction_slots = len(ins)
            full_decode = instruction_slots == size // 4 and all(i.address == va + 4 * n for n, i in enumerate(ins))
            if target["instruction_slots"] != size // 4:
                raise RuntimeError(f"target {ix} manifest instruction slot mismatch")
            overlap_export = sorted({hex(start) for start, length in exports
                                     if start < va + size and va < start + length})
            overlap_fde = sorted({hex(start) for start, length in fdes
                                  if start != va and start < va + size and va < start + length})
            rows.append({"index": ix, "elf_va": target["elf_va"], "size_bytes": size,
                         "file_offset": target["file_offset"], "pt_load_segment_index": covering[0]["index"],
                         "source_body_sha256": actual, "source_instruction_slots": size // 4,
                         "capstone_decoded_instructions": instruction_slots,
                         "capstone_full_decode": full_decode,
                         "overlapping_export_starts": overlap_export,
                         "overlapping_other_fde_starts": overlap_fde})
            assembly.append({"index": ix, "elf_va": target["elf_va"],
                             "instructions": [{"va": hex(i.address), "word_le": body[(i.address-va):(i.address-va)+4].hex(),
                                               "mnemonic": i.mnemonic, "operands": i.op_str} for i in ins]})

    check_lease()
    if PROJECT.exists():
        raise RuntimeError("private Ghidra project already exists; no overwrite")
    old = path_hashes(PRIOR_PROJECT)
    if len(old) != 9:
        raise RuntimeError(f"historical analyzed project file count changed: {len(old)}")
    PROJECT.parent.mkdir(parents=True, exist_ok=True)
    shutil.copytree(PRIOR_PROJECT, PROJECT)
    new = path_hashes(PROJECT)
    if old != new:
        raise RuntimeError("copied Ghidra project file hashes differ")

    check_lease()
    REPORT.mkdir(parents=True, exist_ok=True)
    write_json(REPORT / "source_index.json", {"task_id": "TASK_190", "revision": 1,
        "generated_at": now(), "original_source_path": str(SOURCE), "original_source_sha256": SOURCE_SHA,
        "source_file_bytes": len(source_bytes), "target_manifest_path": str(MANIFEST),
        "target_manifest_sha256": MANIFEST_SHA, "all_fde_ranges": len(fdes),
        "nonexport_fde_candidate_starts": len(candidate_starts), "export_unique_vas": len(export_starts),
        "sorted_nonexport_candidate_slice": "zero_based_indices_256_through_383",
        "prior_TASK_186_target_overlap_count": 0,
        "pt_load_segments": loads, "targets": rows})
    atomic_bytes(REPORT / "source_assembly.ndjson", b"".join(
        (json.dumps(row, ensure_ascii=False) + "\n").encode("utf-8") for row in assembly))
    write_json(REPORT / "project_copy_receipt.json", {"task_id": "TASK_190", "revision": 1,
        "historical_task": "TASK_186", "historical_original_path": str(PRIOR_PROJECT),
        "copy_path": str(PROJECT), "copy_count": len(new), "copy_byte_hashes_match": old == new,
        "historical_file_sha256": old, "private_copy_file_sha256": new,
        "no_fresh_import": True, "lease_id": LEASE_ID, "fencing_token": FENCE, "generated_at": now()})
    chunks = []
    for begin in range(0, 128, 32):
        chunk = begin // 32
        selected = targets[begin:begin + 32]
        tsv = REPORT / f"chunk_{chunk:02d}" / "targets.tsv"
        atomic_bytes(tsv, "".join(
            f"{i}\t{x['elf_va']}\t{x['size_bytes']}\t{x['body_sha256']}\n"
            for i, x in enumerate(selected, begin + 1)).encode("utf-8"))
        chunks.append({"chunk": chunk, "start_index": begin + 1, "end_index": begin + len(selected),
                       "target_tsv": tsv.relative_to(REPORT).as_posix(), "target_tsv_sha256": sha256(tsv)})
    write_json(REPORT / "chunk_index.json", {"task_id": "TASK_190", "revision": 1,
        "target_count": 128, "chunks": chunks, "generated_at": now()})
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_190", "revision": 1,
        "status": "SOURCE_VERIFIED_AND_PROJECT_COPIED", "generated_at": now(), "lease_id": LEASE_ID,
        "fencing_token": FENCE, "verified_target_bodies": len(rows),
        "source_instruction_slots": sum(r["source_instruction_slots"] for r in rows),
        "source_full_decode_rows": sum(r["capstone_full_decode"] for r in rows),
        "historical_project_copy_files": len(new), "historical_project_copy_hash_match": True,
        "fresh_imports": 0, "c_like_rows": 0})
    print(json.dumps({"status": "PREPARED", "targets": len(rows), "assembly_rows": len(assembly),
                      "full_decode": sum(r["capstone_full_decode"] for r in rows),
                      "overlap_exports": sum(bool(r["overlapping_export_starts"]) for r in rows),
                      "overlap_other_fdes": sum(bool(r["overlapping_other_fde_starts"]) for r in rows),
                      "project_copy_files": len(new), "chunks": len(chunks)}))


if __name__ == "__main__":
    main()
