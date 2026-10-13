"""Independently pin five original SO export bodies and archive immutable raw receipts."""
from __future__ import annotations

import hashlib
import json
import shutil

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, LEASE_ID, LIBRARIES, NEW_LIBRARIES,
                    REPORT, REUSED_LIBRARIES, ROOT, SOURCE_DIR, STANDARD,
                    STANDARD_SHA, TASK_SHA, atomic_bytes, check_lease,
                    now, sha256, write_json)

CHUNK_SIZE = 256
HISTORICAL_FILES = ("COMPLETE.json", "target_index.json", "targets.tsv",
                    "ghidra_command.json", "ghidra_stdout.log", "ghidra_stderr.log",
                    "ghidra_raw.json")

def verify_historical(name: str, source_sha: str, prior_task: str) -> dict:
    prior = ROOT / "RULES/REPORT" / f"{prior_task}_REPORT_R1"
    seal = json.loads((prior / "COMPLETE.json").read_text(encoding="utf-8"))
    if (seal.get("schema_version"), seal.get("task_id"), seal.get("revision"), seal.get("status")) != (
            "2.1.2", prior_task, 1, "COMPLETE"):
        raise RuntimeError("historical seal identity invalid: " + prior_task)
    for rel, digest in seal["files"].items():
        if sha256(prior / rel) != digest:
            raise RuntimeError("historical sealed report changed: " + rel)
    for rel, digest in seal["code_files"].items():
        if sha256(ROOT / rel) != digest:
            raise RuntimeError("historical sealed script changed: " + rel)
    folder = prior / name
    old_index = json.loads((folder / "target_index.json").read_text(encoding="utf-8"))
    if old_index.get("source_sha256") != source_sha:
        raise RuntimeError("historical original source identity invalid: " + name)
    return {"prior_task": prior_task, "source_folder": str(folder),
            "seal_sha256": sha256(prior / "COMPLETE.json"), "old_index": old_index}

def main() -> None:
    check_lease()
    if REPORT.exists():
        raise RuntimeError("TASK_171 owned report already prepared")
    disassembler = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    disassembler.skipdata = True
    summary = []
    archives = {}
    for name, (expected_sha, expected_count) in LIBRARIES.items():
        check_lease()
        source = SOURCE_DIR / name
        raw = source.read_bytes()
        if hashlib.sha256(raw).hexdigest() != expected_sha:
            raise RuntimeError("original source SHA mismatch: " + name)
        with source.open("rb") as handle:
            elf = ELFFile(handle)
            if elf["e_machine"] != "EM_AARCH64":
                raise RuntimeError("source architecture mismatch: " + name)
            segments = [{"index": i, "va": int(segment["p_vaddr"]),
                         "offset": int(segment["p_offset"]), "file_size": int(segment["p_filesz"]),
                         "memory_size": int(segment["p_memsz"])}
                        for i, segment in enumerate(elf.iter_segments()) if segment["p_type"] == "PT_LOAD"]
            by_va = {}
            for symbol in elf.get_section_by_name(".dynsym").iter_symbols():
                if (symbol["st_info"]["type"] != "STT_FUNC" or
                        symbol["st_shndx"] == "SHN_UNDEF" or int(symbol["st_size"]) <= 0):
                    continue
                by_va.setdefault(int(symbol["st_value"]), []).append((symbol.name, int(symbol["st_size"])))
        if len(by_va) != expected_count:
            raise RuntimeError(f"original export census changed {name}: {len(by_va)}")
        folder = REPORT / name
        targets, assembly = [], []
        for va in sorted(by_va):
            aliases = sorted(by_va[va], key=lambda pair: (-pair[1], pair[0]))
            symbol, size = aliases[0]
            mapping = [(segment["index"], segment["offset"] + va - segment["va"])
                       for segment in segments if segment["va"] <= va and
                       va + size <= segment["va"] + segment["file_size"]]
            if len(mapping) != 1:
                raise RuntimeError(f"ambiguous PT_LOAD mapping: {name}:0x{va:x}+{size}")
            segment_index, offset = mapping[0]
            body = raw[offset:offset + size]
            if len(body) != size:
                raise RuntimeError("truncated original body: " + name)
            record = {"index": len(targets) + 1, "elf_va": f"0x{va:x}",
                      "size_bytes": size, "file_offset": f"0x{offset:x}",
                      "pt_load_segment_index": segment_index,
                      "source_body_sha256": hashlib.sha256(body).hexdigest(),
                      "symbol": symbol,
                      "aliases": [{"name": alias, "size_bytes": sz} for alias, sz in aliases]}
            targets.append(record)
            instructions = [f"0x{inst.address:x}: {inst.mnemonic} {inst.op_str}".rstrip()
                            for inst in disassembler.disasm(body, va)]
            assembly.append(json.dumps({"index": record["index"], "elf_va": record["elf_va"],
                                        "source_bytes_hex": body.hex(),
                                        "capstone_source_assembly": instructions}, ensure_ascii=False))
        chunks = []
        if name in NEW_LIBRARIES:
            for start in range(0, len(targets), CHUNK_SIZE):
                subset = targets[start:start + CHUNK_SIZE]
                chunk_folder = folder / f"chunk_{len(chunks):02d}"
                lines = ["\t".join((str(x["index"]), x["elf_va"], str(x["size_bytes"]),
                                     x["source_body_sha256"], x["symbol"])) for x in subset]
                path = chunk_folder / "targets.tsv"
                atomic_bytes(path, ("\n".join(lines) + "\n").encode("utf-8"))
                chunks.append({"chunk": len(chunks), "folder": chunk_folder.relative_to(REPORT).as_posix(),
                               "count": len(subset), "first_index": subset[0]["index"],
                               "last_index": subset[-1]["index"], "target_tsv_sha256": sha256(path)})
        atomic_bytes(folder / "source_assembly.ndjson", ("\n".join(assembly) + "\n").encode("utf-8"))
        write_json(folder / "source_index.json", {
            "task_id": "TASK_171", "revision": 1, "library": name,
            "source_path": str(source), "source_sha256": expected_sha,
            "source_file_size": len(raw), "elf_machine": "EM_AARCH64",
            "pt_load_segments": segments,
            "defined_nonzero_function_symbols": sum(map(len, by_va.values())),
            "unique_export_vas": len(targets), "targets": targets, "chunks": chunks,
            "generated_at": now(), "standard_sha256": STANDARD_SHA,
            "task_sha256": TASK_SHA, "lease_id": LEASE_ID, "fencing_token": FENCE})
        if name in REUSED_LIBRARIES:
            prior_task = REUSED_LIBRARIES[name][2]
            historical = verify_historical(name, expected_sha, prior_task)
            old_index = historical.pop("old_index")
            if len(old_index["targets"]) != len(targets):
                raise RuntimeError("historical source count differs: " + name)
            for ours, old in zip(targets, old_index["targets"]):
                for field in ("index", "elf_va", "size_bytes", "file_offset", "source_body_sha256", "symbol"):
                    if ours[field] != old[field]:
                        raise RuntimeError(f"historical source target differs: {name}:{ours['index']}")
            old_folder = ROOT / "RULES/REPORT" / f"{prior_task}_REPORT_R1" / name
            copied = {}
            for filename in HISTORICAL_FILES:
                original = ((ROOT / "RULES/REPORT" / f"{prior_task}_REPORT_R1" / filename)
                            if filename == "COMPLETE.json" else old_folder / filename)
                owned = folder / "historical_raw" / filename
                owned.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(original, owned)
                if sha256(owned) != sha256(original):
                    raise RuntimeError("historical raw copy differs: " + name)
                copied[filename] = {"original": str(original), "sha256": sha256(original),
                                    "bytes": owned.stat().st_size}
            historical["copied_raw_files"] = copied
            archives[name] = historical
        summary.append({"library": name, "source_sha256": expected_sha,
                        "original_function_symbols": sum(map(len, by_va.values())),
                        "unique_export_vas": len(targets), "max_body_bytes": max(x["size_bytes"] for x in targets),
                        "new_ghidra_chunks": len(chunks),
                        "provenance_mode": "new_Ghidra" if name in NEW_LIBRARIES else "verified_historical_raw"})
        print(json.dumps(summary[-1]), flush=True)
    write_json(REPORT / "source_batch_index.json", {"task_id": "TASK_171", "revision": 1,
        "generated_at": now(), "total_export_vas": sum(x["unique_export_vas"] for x in summary),
        "libraries": summary})
    write_json(REPORT / "historical_archive_receipt.json", {"task_id": "TASK_171", "revision": 1,
        "generated_at": now(), "historical_commands_are_reused_evidence_not_current_execution": True,
        "sources": archives})
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_171", "revision": 1,
        "status": "ORIGINAL_SOURCES_AND_HISTORICAL_RAW_PINNED", "generated_at": now(),
        "original_export_vas": 281, "new_ghidra_chunks_pending": 0,
        "lease_id": LEASE_ID, "fencing_token": FENCE})
    audit = (f"# TASK_171 R1 audit index\n\nFull canonical standard read: `{STANDARD}` SHA-256 "
             f"`{STANDARD_SHA}`.\n\nExact task SHA-256 `{TASK_SHA}`; agent `{AGENT_ID}`, "
             f"lease `{LEASE_ID}`, fence `{FENCE}`.\n\nOriginal SO paths, hashes, all "
             "ELF/PT_LOAD function-body hashes and source assembly are in per-library indexes. "
             "Previously sealed TASK_149/153/155 raw commands/results are archived unchanged. "
             "This task performs no fresh Ghidra import or duplicate extraction. No AGY.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    print(json.dumps({"task_id": "TASK_171", "source_export_vas": 281,
                      "new_chunks": 0}), flush=True)

if __name__ == "__main__":
    main()
