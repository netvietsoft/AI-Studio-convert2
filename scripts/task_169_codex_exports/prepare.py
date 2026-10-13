"""Index every original LayerFlow export and preserve verified TASK_146/147 evidence."""

from __future__ import annotations

import hashlib
import json
import shutil
from pathlib import Path

from elftools.elf.elffile import ELFFile

from common import (CHUNK_SIZE, EXPECTED_SYMBOLS, EXPECTED_VAS, FENCE, LEASE_ID,
                    PROJECT, PROJECT_NAME, REPORT, ROOT, SCRATCH, SOURCE,
                    SOURCE_SHA, STANDARD, STANDARD_SHA, TASK_SHA, atomic_bytes,
                    check_lease, now, sha256, tree_hashes, write_json)

HISTORICAL_ROOTS = {
    "TASK_146": ROOT / "RULES/REPORT/TASK_146_REPORT_R1",
    "TASK_147": ROOT / "RULES/REPORT/TASK_147_REPORT_R1",
}
ORIGINAL_PROJECT = ROOT / "RESEARCH_WORK/TASK_147_R1/ghidra_project"
PROJECT_DB_REL = "LayerFlowHair146.rep/idata/00/~00000000.db/db.1.gbf"


def mapped_bytes(elf: ELFFile, va: int, size: int) -> tuple[bytes, int]:
    for segment in elf.iter_segments():
        if segment["p_type"] != "PT_LOAD":
            continue
        base, length = int(segment["p_vaddr"]), int(segment["p_filesz"])
        if base <= va and va + size <= base + length:
            offset = int(segment["p_offset"]) + va - base
            with SOURCE.open("rb") as f:
                f.seek(offset)
                body = f.read(size)
            if len(body) == size:
                return body, offset
    raise RuntimeError(f"no original PT_LOAD mapping 0x{va:x}+{size}")


def verified_historical() -> tuple[dict[int, dict], dict]:
    """Validate prior source, raw command/result hashes and reusable C bodies."""
    packages = {}
    for task, folder in HISTORICAL_ROOTS.items():
        complete_path = folder / "COMPLETE.json"
        complete = json.loads(complete_path.read_text(encoding="utf-8"))
        if complete["task_id"] != task or complete["status"] != "COMPLETE" or complete["source_sha256"] != SOURCE_SHA:
            raise RuntimeError(f"{task} historical package identity/source mismatch")
        for relative, digest in complete["files"].items():
            if sha256(folder / relative) != digest:
                raise RuntimeError(f"{task} historical report file mismatch: {relative}")
        for relative, digest in complete["code_files"].items():
            if sha256(ROOT / relative) != digest:
                raise RuntimeError(f"{task} historical script mismatch: {relative}")
        receipt = json.loads((folder / "ghidra_command.json").read_text(encoding="utf-8"))
        if receipt["exit_code"] != 0 or receipt["status"] != "OUTPUT_READY" or receipt["source_sha256"] != SOURCE_SHA:
            raise RuntimeError(f"{task} historical command did not finish")
        raw_file = "layerflow_hair_ghidra_raw.json" if task == "TASK_146" else "applylayer_ghidra_raw.json"
        raw_path = folder / raw_file
        if sha256(raw_path) != receipt["result_sha256"]:
            raise RuntimeError(f"{task} historical raw command/result mismatch")
        raw = json.loads(raw_path.read_text(encoding="utf-8"))
        if raw["task_id"] != task or raw["program_name"] != SOURCE.name:
            raise RuntimeError(f"{task} historical program identity mismatch")
        packages[task] = {"folder": folder, "complete": complete, "receipt": receipt,
                          "raw_file": raw_file, "raw_sha256": sha256(raw_path), "raw": raw,
                          "complete_sha256": sha256(complete_path)}
    copy_receipt_path = HISTORICAL_ROOTS["TASK_147"] / "project_copy_receipt.json"
    copy_receipt = json.loads(copy_receipt_path.read_text(encoding="utf-8"))
    expected_project = copy_receipt["project_file_hashes"]
    if (copy_receipt["source_sha256"] != SOURCE_SHA or
            copy_receipt["task146_complete_sha256"] != packages["TASK_146"]["complete_sha256"] or
            expected_project[PROJECT_DB_REL] != sha256(ORIGINAL_PROJECT / PROJECT_DB_REL)):
        raise RuntimeError("historical project DB/source lineage mismatch")
    if not (ORIGINAL_PROJECT / (PROJECT_NAME + ".gpr")).is_file():
        raise RuntimeError("historical project descriptor missing")
    for rel in ("LayerFlowHair146.rep/idata/00/00000000.prp", "LayerFlowHair146.rep/project.prp"):
        if expected_project[rel] != sha256(ORIGINAL_PROJECT / rel):
            raise RuntimeError("historical project property hash mismatch: " + rel)
    prior146 = packages["TASK_146"]["raw"]["targets"]
    prior147 = packages["TASK_147"]["raw"]["targets"]
    if len(prior146) != 15 or len(prior147) != 1:
        raise RuntimeError("historical selected body count changed")
    if prior147[0]["elf_va"] != "0x3f94fc" or not prior147[0]["decompile_success"]:
        raise RuntimeError("historical applyLayer recovery missing")
    by_va = {}
    for row in prior146:
        va = int(row["elf_va"], 16)
        if va in by_va:
            raise RuntimeError("duplicate historical selected VA")
        if va != 0x3f94fc:
            if not row["decompile_success"] or not row["pseudocode"].strip() or row["error"]:
                raise RuntimeError(f"unrecovered TASK_146 historical row 0x{va:x}")
            by_va[va] = {"row": row, "task": "TASK_146", "raw_file": packages["TASK_146"]["raw_file"],
                         "raw_sha256": packages["TASK_146"]["raw_sha256"]}
    by_va[0x3f94fc] = {"row": prior147[0], "task": "TASK_147",
                        "raw_file": packages["TASK_147"]["raw_file"],
                        "raw_sha256": packages["TASK_147"]["raw_sha256"]}
    if len(by_va) != 15:
        raise RuntimeError("historical unique selected VA count changed")
    lineage = {"task146_complete_sha256": packages["TASK_146"]["complete_sha256"],
               "task147_complete_sha256": packages["TASK_147"]["complete_sha256"],
               "task147_project_copy_receipt_sha256": sha256(copy_receipt_path),
               "original_project": str(ORIGINAL_PROJECT),
               "original_project_file_hashes_at_reuse": tree_hashes(ORIGINAL_PROJECT),
               "project_db_sha256": expected_project[PROJECT_DB_REL],
               "original_source_sha256": SOURCE_SHA}
    return by_va, lineage


def main() -> None:
    check_lease()
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError("pinned source SHA changed")
    if REPORT.exists() or SCRATCH.exists():
        raise RuntimeError("TASK_169 report/scratch already exists; no implicit retry")
    historical, lineage = verified_historical()
    with SOURCE.open("rb") as f:
        elf = ELFFile(f)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("source architecture changed")
        dynsym = elf.get_section_by_name(".dynsym")
        by_va: dict[int, list[tuple[str, int]]] = {}
        for symbol in dynsym.iter_symbols():
            if (symbol["st_info"]["type"] != "STT_FUNC" or symbol["st_shndx"] == "SHN_UNDEF" or
                    int(symbol["st_size"]) <= 0 or int(symbol["st_value"]) <= 0):
                continue
            by_va.setdefault(int(symbol["st_value"]), []).append((symbol.name, int(symbol["st_size"])))
        if len(by_va) != EXPECTED_VAS or sum(map(len, by_va.values())) != EXPECTED_SYMBOLS:
            raise RuntimeError("original .dynsym census changed")
        targets = []
        for va in sorted(by_va):
            aliases = sorted(by_va[va], key=lambda x: (-x[1], x[0]))
            symbol, size = aliases[0]
            body, offset = mapped_bytes(elf, va, size)
            target = {"index": len(targets) + 1, "elf_va": f"0x{va:x}", "size_bytes": size,
                      "file_offset": f"0x{offset:x}", "source_body_sha256": hashlib.sha256(body).hexdigest(),
                      "symbol": symbol, "aliases": [x for x, _ in aliases]}
            if va in historical:
                row = historical[va]["row"]
                if (row["symbol"] != symbol or row["size_bytes"] != size or row["elf_va"] != target["elf_va"] or
                        row["expected_source_sha256"] != target["source_body_sha256"] or
                        row["ghidra_memory_sha256"] != target["source_body_sha256"] or
                        row["source_bytes_match"] is not True or not row["pseudocode"].strip()):
                    raise RuntimeError(f"historical body/source mismatch at 0x{va:x}")
            targets.append(target)
    REPORT.mkdir(parents=True)
    SCRATCH.mkdir(parents=True)
    check_lease()
    shutil.copytree(ORIGINAL_PROJECT, PROJECT)
    if sha256(PROJECT / PROJECT_DB_REL) != lineage["project_db_sha256"]:
        raise RuntimeError("copied Ghidra project DB hash mismatch")
    for task, folder in HISTORICAL_ROOTS.items():
        check_lease()
        shutil.copytree(folder, REPORT / "historical" / folder.name)
    copied_hashes = tree_hashes(PROJECT)
    write_json(REPORT / "project_reuse_receipt.json", {
        "task_id": "TASK_169", "revision": 1, "generated_at": now(), "lease_id": LEASE_ID,
        "fencing_token": FENCE, "source_sha256": SOURCE_SHA,
        "execution_mode": "REUSED_ANALYZED_TASK_147_PROJECT_NO_FRESH_IMPORT",
        "historical_lineage": lineage, "copied_project": str(PROJECT),
        "copied_project_initial_file_hashes": copied_hashes,
        "copied_project_db_sha256": copied_hashes[PROJECT_DB_REL],
        "historical_reports": {task: {"source_folder": str(folder),
            "copied_folder": str(REPORT / "historical" / folder.name),
            "source_complete_sha256": sha256(folder / "COMPLETE.json")}
            for task, folder in HISTORICAL_ROOTS.items()}})
    historical_meta = []
    for target in targets:
        va = int(target["elf_va"], 16)
        if va not in historical:
            continue
        prior = historical[va]
        historical_meta.append({"index": target["index"], "elf_va": target["elf_va"],
            "task_id": prior["task"], "raw_file": f"historical/{prior['task']}_REPORT_R1/{prior['raw_file']}",
            "original_row_index": prior["row"]["index"], "original_raw_sha256": prior["raw_sha256"],
            "source_body_sha256": target["source_body_sha256"],
            "historical_decompile_timeout_seconds": 180 if prior["task"] == "TASK_147" else 15})
    write_json(REPORT / "historical_reuse.json", {
        "task_id": "TASK_169", "revision": 1, "source_sha256": SOURCE_SHA,
        "historical_reused_vas": len(historical_meta),
        "excluded_from_new_ghidra_passes": True,
        "exception_note": "TASK_147 applyLayer C-like output used historical isolated 180s timeout; current TASK_169 exporter remains <=15s/function.",
        "rows": historical_meta})
    new_targets = [x for x in targets if int(x["elf_va"], 16) not in historical]
    chunks = []
    for start in range(0, len(new_targets), CHUNK_SIZE):
        number = len(chunks)
        group = new_targets[start:start + CHUNK_SIZE]
        folder = REPORT / f"chunk_{number:02d}"
        lines = ["\t".join((str(x["index"]), x["elf_va"], str(x["size_bytes"]),
                             x["source_body_sha256"], x["symbol"])) for x in group]
        path = folder / "targets.tsv"
        atomic_bytes(path, ("\n".join(lines) + "\n").encode("utf-8"))
        chunks.append({"chunk": number, "first_index": group[0]["index"],
                       "last_index": group[-1]["index"], "indices": [x["index"] for x in group],
                       "count": len(group), "target_tsv_sha256": sha256(path)})
    if len(chunks) != 20 or sum(x["count"] for x in chunks) != EXPECTED_VAS - 15:
        raise RuntimeError("new-only chunk layout changed")
    write_json(REPORT / "target_index.json", {
        "schema_version": "2.1.2", "task_id": "TASK_169", "revision": 1,
        "generated_at": now(), "standard_sha256": STANDARD_SHA, "task_sha256": TASK_SHA,
        "source_sha256": SOURCE_SHA, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "defined_nonzero_function_symbols": EXPECTED_SYMBOLS,
        "unique_export_vas": EXPECTED_VAS, "historical_reused_vas": 15,
        "new_ghidra_target_vas": len(new_targets), "chunks": chunks, "targets": targets})
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_169", "revision": 1, "status": "TARGETS_AND_PROJECT_REUSE_VERIFIED",
        "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
        "source_bodies_rehashed": EXPECTED_VAS, "historical_reused_vas": 15,
        "new_ghidra_targets": len(new_targets), "chunks": len(chunks), "ghidra_chunks_started": 0})
    audit = (f"# TASK_169 R1 audit index\n\nCanonical standard read: {STANDARD} SHA-256 {STANDARD_SHA}.\n\n"
             f"Task SHA-256 {TASK_SHA}; lease {LEASE_ID}, fence {FENCE}.\n\n"
             f"Original source {SOURCE} SHA-256 {SOURCE_SHA}. All {EXPECTED_VAS} defined export VAs"
             " PT_LOAD mapped and hashed. TASK_146/147 raw evidence was rehashed and copied to"
             " historical/; TASK_147 Ghidra project was copied into own scratch. No fresh import."
             " Historical 180s applyLayer decompile is separately attributed; current passes cap 15s."
             " Real Codex subagent; no AGY.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    print(json.dumps({"export_symbols": EXPECTED_SYMBOLS, "unique_export_vas": EXPECTED_VAS,
                      "historical_reused_vas": len(historical_meta), "new_targets": len(new_targets),
                      "chunks": len(chunks), "project_db_sha256": copied_hashes[PROJECT_DB_REL]}))


if __name__ == "__main__":
    main()
