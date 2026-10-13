"""Verify original ELF and copy TASK_156's project without a new import."""

from __future__ import annotations

import hashlib
import json
import shutil

from elftools.elf.elffile import ELFFile

from common import (FENCE, LEASE_ID, PRIOR_PROJECT, PRIOR_REPORT, PROJECT,
                    REPORT, SCRATCH, SOURCE, SOURCE_SHA, STANDARD, STANDARD_SHA,
                    TASK_SHA, atomic_bytes, check_lease, now, sha256, tree_hashes,
                    write_json)


def main() -> None:
    check_lease()
    if REPORT.exists() or SCRATCH.exists():
        raise RuntimeError("TASK_159 report/scratch already exists; no repeat")
    previous = json.loads((PRIOR_REPORT / "target_index.json").read_text(encoding="utf-8"))
    if (previous.get("task_id") != "TASK_156" or
            previous.get("source_sha256") != SOURCE_SHA or
            previous.get("unique_export_vas") != 284 or
            len(previous.get("targets", [])) != 284):
        raise RuntimeError("TASK_156 read-only target index mismatch")
    old_project_hashes = tree_hashes(PRIOR_PROJECT)
    if len(old_project_hashes) != 10 or "SmallLib156.gpr" not in old_project_hashes:
        raise RuntimeError("TASK_156 imported project incomplete or changed")

    source_bytes = SOURCE.read_bytes()
    with SOURCE.open("rb") as handle:
        elf = ELFFile(handle)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("wrong source architecture")
        dynsym = elf.get_section_by_name(".dynsym")
        if dynsym is None:
            raise RuntimeError("missing .dynsym")
        by_va: dict[int, list[tuple[str, int]]] = {}
        for symbol in dynsym.iter_symbols():
            if (symbol["st_info"]["type"] == "STT_FUNC" and
                    symbol["st_shndx"] != "SHN_UNDEF" and int(symbol["st_size"]) > 0):
                by_va.setdefault(int(symbol["st_value"]), []).append(
                    (symbol.name, int(symbol["st_size"])))
        if len(by_va) != 284 or sum(map(len, by_va.values())) != 284:
            raise RuntimeError("independent source export census changed")
        segments = [(int(s["p_vaddr"]), int(s["p_filesz"]), int(s["p_offset"]))
                    for s in elf.iter_segments() if s["p_type"] == "PT_LOAD"]
        verified = []
        for index, row in enumerate(previous["targets"], start=1):
            va = int(row["elf_va"], 16)
            size = int(row["size_bytes"])
            if row["index"] != index or va not in by_va or (row["symbol"], size) != by_va[va][0]:
                raise RuntimeError(f"source symbol/index changed at {index}")
            mapped = [(offset + va - base) for base, length, offset in segments
                      if base <= va and va + size <= base + length]
            if len(mapped) != 1:
                raise RuntimeError(f"PT_LOAD mapping ambiguous at {index}")
            file_offset = mapped[0]
            body = source_bytes[file_offset:file_offset + size]
            digest = hashlib.sha256(body).hexdigest()
            if (len(body) != size or row["file_offset"] != f"0x{file_offset:x}" or
                    row["source_body_sha256"] != digest):
                raise RuntimeError(f"PT_LOAD body hash changed at {index}")
            verified.append(row)
    huge = [row for row in verified if row["size_bytes"] > 65536]
    if len(huge) != 1 or huge[0]["index"] != 232 or huge[0]["elf_va"] != "0x29cd4" or huge[0]["size_bytes"] != 224440:
        raise RuntimeError("oversized target identity changed")
    ordinary = [row for row in verified if row["index"] != 232]
    if len(ordinary) != 283:
        raise RuntimeError("ordinary target count changed")

    check_lease()
    REPORT.mkdir(parents=True)
    SCRATCH.mkdir(parents=True)
    shutil.copytree(PRIOR_PROJECT, PROJECT)
    copied_hashes = tree_hashes(PROJECT)
    if copied_hashes != old_project_hashes:
        raise RuntimeError("copied Ghidra project differs from TASK_156")
    write_json(REPORT / "project_copy_receipt.json", {
        "task_id": "TASK_159", "revision": 1, "generated_at": now(),
        "source_original_project": str(PRIOR_PROJECT), "own_project": str(PROJECT),
        "read_only_input": True, "fresh_imports": 0,
        "project_file_hashes": old_project_hashes,
        "copied_file_hashes_match": True,
        "prior_import_analysis_timeout_seconds": 480,
        "prior_import_analysis_completed": False,
    })
    chunks = []
    for number in range(3):
        selected = ordinary[number * 100:(number + 1) * 100]
        if not selected or len(selected) > 100:
            raise RuntimeError("invalid ordinary chunk")
        name = f"chunk_{number:02d}"
        folder = REPORT / name
        folder.mkdir()
        tsv = "".join(f"{r['index']}\t{r['elf_va']}\t{r['size_bytes']}\t{r['source_body_sha256']}\t{r['symbol']}\n"
                      for r in selected)
        atomic_bytes(folder / "targets.tsv", tsv.encode("utf-8"))
        chunks.append({"chunk": number, "folder": name, "count": len(selected),
                       "first_index": selected[0]["index"],
                       "last_index": selected[-1]["index"],
                       "target_tsv_sha256": sha256(folder / "targets.tsv")})
    huge_folder = REPORT / "huge_232"
    huge_folder.mkdir()
    row = huge[0]
    atomic_bytes(huge_folder / "targets.tsv",
                 f"{row['index']}\t{row['elf_va']}\t{row['size_bytes']}\t{row['source_body_sha256']}\t{row['symbol']}\n".encode("utf-8"))
    chunks.append({"chunk": 3, "folder": "huge_232", "count": 1,
                   "first_index": 232, "last_index": 232, "isolated_oversized": True,
                   "target_tsv_sha256": sha256(huge_folder / "targets.tsv")})
    write_json(REPORT / "target_index.json", {
        "schema_version": "2.1.2", "task_id": "TASK_159", "revision": 1,
        "generated_at": now(), "standard_sha256": STANDARD_SHA,
        "task_sha256": TASK_SHA, "source_sha256": SOURCE_SHA,
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "prior_task156_index_sha256": sha256(PRIOR_REPORT / "target_index.json"),
        "defined_nonzero_function_symbols": 284, "unique_export_vas": 284,
        "ordinary_vas": 283, "oversized_vas": 1,
        "chunks": chunks, "targets": verified,
    })
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_159", "revision": 1, "status": "SOURCE_AND_PROJECT_COPIED",
        "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
        "source_bodies_rehashed": 284, "project_files_copied_verified": len(old_project_hashes),
        "ghidra_processes_started": 0, "independent_review_pending": True,
    })
    print(json.dumps({"status": "PREPARED", "export_vas": 284,
                      "ordinary_chunks": [x["count"] for x in chunks[:3]],
                      "isolated_size_bytes": huge[0]["size_bytes"],
                      "project_files": len(old_project_hashes)}), flush=True)


if __name__ == "__main__":
    main()
