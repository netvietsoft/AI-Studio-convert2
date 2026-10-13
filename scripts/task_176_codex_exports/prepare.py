"""Revalidate two historical TASK_156 export bodies against original ELF sources."""

from __future__ import annotations

import hashlib
import json
import shutil
from pathlib import Path

from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, HISTORICAL, HISTORICAL_PROJECTS,
                    LEASE_ID, LIBRARIES, REPORT, SCRATCH, SOURCE_DIR,
                    STANDARD, STANDARD_SHA, TASK_SHA, atomic_bytes,
                    check_lease, now, sha256, write_json)

HISTORICAL_COMPLETE_SHA = "dc21cbe1c55d07e4d857998dc8d0133802eece52288112e663afd7ff66a83b5d"
HISTORICAL_FILES = ("target_index.json", "targets.tsv", "ghidra_raw.json",
                    "ghidra_command.json", "ghidra_stdout.log", "ghidra_stderr.log")


def mapped_bytes(elf: ELFFile, source: Path, va: int, size: int) -> tuple[bytes, int]:
    for segment in elf.iter_segments():
        if segment["p_type"] != "PT_LOAD":
            continue
        base, length = int(segment["p_vaddr"]), int(segment["p_filesz"])
        if base <= va and va + size <= base + length:
            offset = int(segment["p_offset"]) + va - base
            with source.open("rb") as stream:
                stream.seek(offset)
                body = stream.read(size)
            if len(body) == size:
                return body, offset
    raise RuntimeError(f"PT_LOAD mapping absent for {source.name}:0x{va:x}+{size}")


def verify_source_and_historical(name: str, expected_sha: str, expected_vas: int) -> dict:
    source = SOURCE_DIR / name
    old = HISTORICAL / name
    if sha256(source) != expected_sha:
        raise RuntimeError("pinned original SO differs: " + name)
    prior_index = json.loads((old / "target_index.json").read_text(encoding="utf-8"))
    raw = json.loads((old / "ghidra_raw.json").read_text(encoding="utf-8"))
    command = json.loads((old / "ghidra_command.json").read_text(encoding="utf-8"))
    if (prior_index.get("source_sha256") != expected_sha or
        prior_index.get("unique_export_vas") != expected_vas or
        raw.get("program_name") != name or len(raw.get("targets", [])) != expected_vas or
        command.get("source_sha256") != expected_sha or
        command.get("status") != "OUTPUT_READY" or command.get("exit_code") != 0):
        raise RuntimeError("historical report provenance/coverage differs: " + name)
    if (command.get("result_sha256") != sha256(old / "ghidra_raw.json") or
        command.get("stdout_sha256") != sha256(old / "ghidra_stdout.log") or
        command.get("stderr_sha256") != sha256(old / "ghidra_stderr.log") or
        command.get("target_tsv_sha256") != sha256(old / "targets.tsv") or
        "-import" not in command["command"] or "-max-cpu" not in command["command"]):
        raise RuntimeError("historical exact commands/logs/result hashes differ: " + name)
    if len(prior_index["targets"]) != expected_vas:
        raise RuntimeError("historical target index count differs: " + name)
    source_rows = []
    with source.open("rb") as stream:
        elf = ELFFile(stream)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("original ELF architecture differs: " + name)
        dynsym = elf.get_section_by_name(".dynsym")
        if dynsym is None:
            raise RuntimeError("original .dynsym missing: " + name)
        by_va: dict[int, list[tuple[str, int]]] = {}
        for symbol in dynsym.iter_symbols():
            if (symbol["st_info"]["type"] == "STT_FUNC" and
                symbol["st_shndx"] != "SHN_UNDEF" and
                int(symbol["st_value"]) > 0 and int(symbol["st_size"]) > 0):
                by_va.setdefault(int(symbol["st_value"]), []).append(
                    (symbol.name, int(symbol["st_size"])))
        if len(by_va) != expected_vas:
            raise RuntimeError(f"original unique export VAs differ: {name}, {len(by_va)}")
        for index, va in enumerate(sorted(by_va), 1):
            aliases = sorted(by_va[va], key=lambda item: (-item[1], item[0]))
            symbol, size = aliases[0]
            body, offset = mapped_bytes(elf, source, va, size)
            body_sha = hashlib.sha256(body).hexdigest()
            old_index = prior_index["targets"][index - 1]
            old_raw = raw["targets"][index - 1]
            if (old_index["index"] != index or old_index["elf_va"] != f"0x{va:x}" or
                old_index["size_bytes"] != size or old_index["symbol"] != symbol or
                old_index["aliases"] != [entry[0] for entry in aliases] or
                old_index["file_offset"] != f"0x{offset:x}" or
                old_index["source_body_sha256"] != body_sha or
                old_raw["index"] != index or old_raw["elf_va"] != f"0x{va:x}" or
                old_raw["symbol"] != symbol or old_raw["size_bytes"] != size or
                old_raw["expected_source_sha256"] != body_sha or
                old_raw["ghidra_memory_sha256"] != body_sha or
                old_raw["source_bytes_match"] is not True or
                old_raw["decompile_success"] is not True or
                not old_raw["pseudocode"].strip() or
                old_raw["instruction_count_observed"] != len(old_raw["instructions"])):
                raise RuntimeError(f"historical C-like/body identity differs: {name} index {index}")
            source_rows.append({"index": index, "elf_va": f"0x{va:x}",
                                "size_bytes": size, "file_offset": f"0x{offset:x}",
                                "symbol": symbol, "aliases": [item[0] for item in aliases],
                                "source_body_sha256": body_sha,
                                "historical_database_va": old_raw["database_va"],
                                "historical_ghidra_memory_sha256": old_raw["ghidra_memory_sha256"],
                                "historical_c_like_chars": len(old_raw["pseudocode"]),
                                "historical_instruction_rows": len(old_raw["instructions"])})
    folder = REPORT / name
    copied = []
    for filename in HISTORICAL_FILES:
        check_lease()
        original = old / filename
        destination = folder / ("historical_" + filename)
        digest = sha256(original)
        atomic_bytes(destination, original.read_bytes())
        if sha256(destination) != digest:
            raise RuntimeError("historical raw copy changed: " + str(original))
        copied.append({"original_path": str(original),
                       "report_path": destination.relative_to(REPORT).as_posix(),
                       "bytes": destination.stat().st_size, "sha256": digest})
    write_json(folder / "source_index.json", {
        "schema_version": "2.1.2", "task_id": "TASK_176", "revision": 1,
        "library": name, "source_path": str(source), "source_sha256": expected_sha,
        "source_bytes": source.stat().st_size,
        "original_unique_export_vas": expected_vas,
        "historical_evidence_class": "UNREVIEWED_TASK_156_STATIC_EXPORT_C_LIKE",
        "historical_raw_sha256": sha256(old / "ghidra_raw.json"),
        "targets": source_rows})
    return {"library": name, "source_sha256": expected_sha,
            "original_unique_export_vas": expected_vas,
            "revalidated_original_pt_load_bodies": len(source_rows),
            "historical_c_like_bodies_nonempty": len(source_rows),
            "historical_files": copied,
            "historical_command_sha256": sha256(old / "ghidra_command.json")}


def copy_analyzed_projects() -> dict:
    projects = {}
    for name in LIBRARIES:
        old = HISTORICAL_PROJECTS / name / "ghidra_project"
        new = SCRATCH / name / "ghidra_project"
        source_files = sorted(path for path in old.rglob("*") if path.is_file())
        if not source_files or not (old / "SmallLib156.gpr").is_file():
            raise RuntimeError("historical analyzed project missing: " + name)
        records = []
        for original in source_files:
            check_lease()
            relative = original.relative_to(old)
            destination = new / relative
            destination.parent.mkdir(parents=True, exist_ok=True)
            before = sha256(original)
            shutil.copy2(original, destination)
            after = sha256(destination)
            if before != after or original.stat().st_size != destination.stat().st_size:
                raise RuntimeError("analyzed project copy differs: " + str(relative))
            records.append({"relative_path": relative.as_posix(),
                            "bytes": destination.stat().st_size,
                            "source_sha256": before, "copy_sha256": after})
        projects[name] = {"original_project_path": str(old), "copy_project_path": str(new),
                          "file_count": len(records), "files": records}
    return projects


def main() -> None:
    check_lease()
    if REPORT.exists() or SCRATCH.exists():
        raise RuntimeError("TASK_176 report or scratch already started")
    if sha256(HISTORICAL / "COMPLETE.json") != HISTORICAL_COMPLETE_SHA:
        raise RuntimeError("historical TASK_156 manifest changed")
    libraries = [verify_source_and_historical(name, *pin)
                 for name, pin in LIBRARIES.items()]
    projects = copy_analyzed_projects()
    write_json(REPORT / "project_copy_manifest.json", {
        "task_id": "TASK_176", "revision": 1, "verified_at": now(),
        "historical_complete_sha256": HISTORICAL_COMPLETE_SHA,
        "projects": projects})
    write_json(REPORT / "source_batch_index.json", {
        "task_id": "TASK_176", "revision": 1, "generated_at": now(),
        "actor": AGENT_ID, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "standard_path": str(STANDARD), "standard_sha256": STANDARD_SHA,
        "task_sha256": TASK_SHA, "historical_complete_sha256": HISTORICAL_COMPLETE_SHA,
        "libraries": libraries,
        "total_original_unique_export_vas": sum(row["original_unique_export_vas"] for row in libraries),
        "total_original_pt_load_bodies_revalidated": sum(row["revalidated_original_pt_load_bodies"]
                                                       for row in libraries),
        "total_historical_c_like_bodies": sum(row["historical_c_like_bodies_nonempty"]
                                              for row in libraries)})
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_176", "revision": 1, "status": "ORIGINAL_AND_HISTORICAL_RAW_VERIFIED",
        "generated_at": now(), "libraries_verified": 2,
        "original_pt_load_bodies_revalidated": 683,
        "historical_c_like_bodies_nonempty": 683,
        "project_files_byte_verified": sum(project["file_count"] for project in projects.values()),
        "fresh_ghidra_imports": 0, "fresh_decompilations": 0})
    audit = ("# TASK_176 R1 audit index\n\n"
             f"Canonical standard fully re-read: `{STANDARD}` SHA-256 `{STANDARD_SHA}`.\n\n"
             f"Task SHA-256 `{TASK_SHA}`; actor `{AGENT_ID}`; lease `{LEASE_ID}`; fence `{FENCE}`.\n\n"
             "Pinned originals, historical raw files and byte-verified analyzed project copies "
             "are enumerated here. Historical C-like output is not newly recovered or "
             "independently accepted. No fresh Ghidra import or decompilation.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    print(json.dumps({"libraries": 2, "pt_load_bodies_revalidated": 683,
                      "historical_c_like_bodies_nonempty": 683,
                      "project_files_byte_verified":
                      sum(project["file_count"] for project in projects.values())}))


if __name__ == "__main__":
    main()
