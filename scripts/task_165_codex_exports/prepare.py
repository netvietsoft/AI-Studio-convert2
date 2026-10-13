"""Re-pin original MTFilter exports and freeze earlier raw receipts for independent audit."""
from __future__ import annotations

import hashlib
import json
import math
import shutil
from pathlib import Path

from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, HIST151, HIST152, LEASE_ID, REPORT, SCRATCH,
                    SOURCE, SOURCE_SHA, STANDARD, STANDARD_SHA, TASK_SHA,
                    atomic_bytes, check_lease, now, sha256, write_json)

PROJECT_OLD = Path(__file__).resolve().parents[2] / "RESEARCH_WORK/TASK_151_R1/ghidra_project"
PROJECT_NEW = SCRATCH / "ghidra_project"
EXPECTED = 2362

def tree_hashes(folder: Path) -> dict[str, str]:
    return {path.relative_to(folder).as_posix(): sha256(path)
            for path in sorted(folder.rglob("*")) if path.is_file()}

def verify_manifest(folder: Path, task_id: str) -> dict:
    seal = json.loads((folder / "COMPLETE.json").read_text(encoding="utf-8"))
    if (seal.get("schema_version"), seal.get("task_id"), seal.get("revision"),
            seal.get("status"), seal.get("source_sha256")) != (
            "2.1.2", task_id, 1, "COMPLETE", SOURCE_SHA):
        raise RuntimeError("historical seal identity invalid: " + task_id)
    for rel, digest in seal["files"].items():
        path = folder / rel
        if not path.is_file() or sha256(path) != digest:
            raise RuntimeError("historical sealed report file changed: " + str(path))
    for rel, digest in seal["code_files"].items():
        path = Path(__file__).resolve().parents[2] / rel
        if not path.is_file() or sha256(path) != digest:
            raise RuntimeError("historical sealed code file changed: " + str(path))
    return seal

def copy_checked(source: Path, dest: Path, archive: dict[str, dict]) -> None:
    check_lease()
    digest = sha256(source)
    dest.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(source, dest)
    if sha256(dest) != digest:
        raise RuntimeError("archive copy hash mismatch: " + str(source))
    archive[dest.relative_to(REPORT).as_posix()] = {
        "original_path": str(source), "sha256": digest, "bytes": dest.stat().st_size}

def main() -> None:
    check_lease()
    if REPORT.exists() or SCRATCH.exists():
        raise RuntimeError("TASK_165 owned output already exists")
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError("pinned original source SHA changed")
    seal151 = verify_manifest(HIST151, "TASK_151")
    seal152 = verify_manifest(HIST152, "TASK_152")
    old_index = json.loads((HIST151 / "target_index.json").read_text(encoding="utf-8"))
    if old_index.get("source_sha256") != SOURCE_SHA or old_index.get("unique_export_vas") != EXPECTED:
        raise RuntimeError("historical target index identity changed")
    raw = SOURCE.read_bytes()
    with SOURCE.open("rb") as handle:
        elf = ELFFile(handle)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("source architecture changed")
        segments = [{"index": i, "va": int(segment["p_vaddr"]),
                     "offset": int(segment["p_offset"]), "file_size": int(segment["p_filesz"]),
                     "memory_size": int(segment["p_memsz"])}
                    for i, segment in enumerate(elf.iter_segments()) if segment["p_type"] == "PT_LOAD"]
        by_va: dict[int, list[tuple[str, int]]] = {}
        for symbol in elf.get_section_by_name(".dynsym").iter_symbols():
            if (symbol["st_info"]["type"] == "STT_FUNC" and
                    symbol["st_shndx"] != "SHN_UNDEF" and int(symbol["st_size"]) > 0):
                by_va.setdefault(int(symbol["st_value"]), []).append(
                    (symbol.name, int(symbol["st_size"])))
    if len(by_va) != EXPECTED or sum(map(len, by_va.values())) != 2634:
        raise RuntimeError("original .dynsym census changed")
    targets = []
    for va in sorted(by_va):
        aliases = sorted(by_va[va], key=lambda item: (-item[1], item[0]))
        name, size = aliases[0]
        mapped = [(segment["index"], segment["offset"] + va - segment["va"])
                  for segment in segments if segment["va"] <= va and
                  va + size <= segment["va"] + segment["file_size"]]
        if len(mapped) != 1:
            raise RuntimeError(f"ambiguous original PT_LOAD mapping 0x{va:x}")
        segment_index, offset = mapped[0]
        body = raw[offset:offset + size]
        if len(body) != size:
            raise RuntimeError(f"truncated original body 0x{va:x}")
        target = {"index": len(targets) + 1, "elf_va": f"0x{va:x}",
                  "size_bytes": size, "file_offset": f"0x{offset:x}",
                  "pt_load_segment_index": segment_index,
                  "source_body_sha256": hashlib.sha256(body).hexdigest(),
                  "symbol": name, "aliases": [{"name": alias, "size_bytes": length}
                                               for alias, length in aliases]}
        old = old_index["targets"][len(targets)]
        if any(old[key] != target[key] for key in
               ("index", "elf_va", "size_bytes", "file_offset", "source_body_sha256", "symbol")):
            raise RuntimeError("historical source index differs from original: " + target["elf_va"])
        targets.append(target)
    sample_count = math.ceil(EXPECTED * .1)
    sample_positions = sorted({1 + round(i * (EXPECTED - 1) / (sample_count - 1))
                               for i in range(sample_count)})
    if len(sample_positions) < sample_count:
        raise RuntimeError("spread sample under 10%")
    sample_tsv = REPORT / "audit_sample/targets.tsv"
    atomic_bytes(sample_tsv, ("\n".join("\t".join((str(t["index"]), t["elf_va"],
                    str(t["size_bytes"]), t["source_body_sha256"], t["symbol"]))
                    for t in (targets[position - 1] for position in sample_positions)) + "\n").encode("utf-8"))
    write_json(REPORT / "source_index.json", {
        "schema_version": "2.1.2", "task_id": "TASK_165", "revision": 1,
        "generated_at": now(), "source_path": str(SOURCE), "source_sha256": SOURCE_SHA,
        "source_file_size": len(raw), "elf_machine": "EM_AARCH64",
        "pt_load_segments": segments, "defined_nonzero_function_symbols": 2634,
        "unique_export_vas": EXPECTED, "targets": targets,
        "audit_sample_positions": sample_positions,
        "audit_sample_tsv_sha256": sha256(sample_tsv),
        "historical_task_151_seal_sha256": sha256(HIST151 / "COMPLETE.json"),
        "historical_task_152_seal_sha256": sha256(HIST152 / "COMPLETE.json"),
        "task_sha256": TASK_SHA, "standard_sha256": STANDARD_SHA,
        "lease_id": LEASE_ID, "fencing_token": FENCE})
    archive: dict[str, dict] = {}
    for rel in ("COMPLETE.json", "target_index.json", "project_copy_receipt.json",
                "batch_run_receipt.json", "independent_verification.json"):
        copy_checked(HIST151 / rel, REPORT / "historical_raw/TASK_151" / rel, archive)
    for meta in old_index["chunks"]:
        folder = f"chunk_{meta['chunk']:02d}"
        for name in ("targets.tsv", "ghidra_command.json", "ghidra_stdout.log",
                     "ghidra_stderr.log", "ghidra_raw.json"):
            rel = f"{folder}/{name}"
            copy_checked(HIST151 / rel, REPORT / "historical_raw/TASK_151" / rel, archive)
    for rel in ("COMPLETE.json", "target.tsv", "project_copy_receipt.json", "ghidra_command.json",
                "ghidra_stdout.log", "ghidra_stderr.log", "parseoldfilter_ghidra_raw.json",
                "parseoldfilter_pseudocode.c", "independent_verification.json"):
        copy_checked(HIST152 / rel, REPORT / "historical_raw/TASK_152" / rel, archive)
    if seal151["c_like_bodies_recovered"] != 2361 or not seal152["c_like_decompile_recovered"]:
        raise RuntimeError("historical source scope differs; inspect prior tasks")
    if not (PROJECT_OLD / "MTFilterHair143.gpr").is_file():
        raise RuntimeError("prior Ghidra project missing")
    old_hashes = tree_hashes(PROJECT_OLD)
    if not old_hashes or sum((PROJECT_OLD / rel).stat().st_size for rel in old_hashes) > 100_000_000:
        raise RuntimeError("prior project extent unsafe")
    SCRATCH.mkdir(parents=True)
    shutil.copytree(PROJECT_OLD, PROJECT_NEW)
    if tree_hashes(PROJECT_NEW) != old_hashes:
        raise RuntimeError("owned Ghidra project copy mismatch")
    write_json(REPORT / "archive_receipt.json", {
        "task_id": "TASK_165", "revision": 1, "generated_at": now(),
        "historical_commands_are_reused_evidence_not_current_execution": True,
        "copied_raw_files": archive, "prior_project": str(PROJECT_OLD),
        "owned_project": str(PROJECT_NEW), "project_file_hashes": old_hashes,
        "fresh_imports_this_revision": 0})
    audit = (f"# TASK_165 R1 audit index\n\nFull canonical standard read: `{STANDARD}` "
             f"SHA-256 `{STANDARD_SHA}`.\n\nExact task SHA-256 `{TASK_SHA}`; "
             f"agent `{AGENT_ID}`, lease `{LEASE_ID}`, fence `{FENCE}`.\n\n"
             f"Original source `{SOURCE}` SHA-256 `{SOURCE_SHA}`. "
             "Historical TASK_151/152 raw commands, stdout/stderr and JSON were hash-checked "
             "against their seals, then copied unchanged into `historical_raw`. Those commands "
             "were executed by earlier tasks; TASK_165 independently audits them. No AGY.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_165", "revision": 1,
        "status": "SOURCE_AND_HISTORICAL_RAW_PINNED", "generated_at": now(),
        "source_export_vas": EXPECTED, "historical_raw_files_copied": len(archive),
        "spread_audit_sample": len(sample_positions), "fresh_imports_this_revision": 0,
        "lease_id": LEASE_ID, "fencing_token": FENCE})
    print(json.dumps({"source_export_vas": EXPECTED, "raw_files": len(archive),
                      "sample": len(sample_positions), "project_files": len(old_hashes)}), flush=True)

if __name__ == "__main__":
    main()
