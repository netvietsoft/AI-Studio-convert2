"""Enumerate all C++ shared exports, source-hash and chunk 256 VAs."""

from __future__ import annotations

import hashlib
import json

from elftools.elf.elffile import ELFFile

from common import (CHUNK_SIZE, FENCE, LEASE_ID, PROJECT,
                    REPORT, SCRATCH, SOURCE, SOURCE_SHA,
                    STANDARD, STANDARD_SHA, TASK_SHA, atomic_bytes,
                    check_lease, now, sha256, write_json)


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
    raise RuntimeError(f"no source PT_LOAD mapping 0x{va:x}+{size}")


def main() -> None:
    check_lease()
    if sha256(SOURCE) != SOURCE_SHA:
        raise RuntimeError("source changed")
    if REPORT.exists() or SCRATCH.exists():
        raise RuntimeError("TASK_172 report/scratch already exists")
    with SOURCE.open("rb") as f:
        elf = ELFFile(f)
        if elf["e_machine"] != "EM_AARCH64":
            raise RuntimeError("source architecture changed")
        dynsym = elf.get_section_by_name(".dynsym")
        by_va: dict[int, list[tuple[str, int]]] = {}
        for symbol in dynsym.iter_symbols():
            if (symbol["st_info"]["type"] != "STT_FUNC" or
                    symbol["st_shndx"] == "SHN_UNDEF" or
                    int(symbol["st_size"]) <= 0 or int(symbol["st_value"]) <= 0):
                continue
            by_va.setdefault(int(symbol["st_value"]), []).append(
                (symbol.name, int(symbol["st_size"])))
        if sum(map(len, by_va.values())) != 1582 or len(by_va) != 1376:
            raise RuntimeError("source export census changed")
        targets = []
        for va in sorted(by_va):
            aliases = sorted(by_va[va], key=lambda x: (-x[1], x[0]))
            symbol, size = aliases[0]
            body, offset = mapped_bytes(elf, va, size)
            targets.append({"index": len(targets) + 1, "elf_va": f"0x{va:x}",
                "size_bytes": size, "file_offset": f"0x{offset:x}",
                "source_body_sha256": hashlib.sha256(body).hexdigest(),
                "symbol": symbol, "aliases": [x for x, _ in aliases]})
    SCRATCH.mkdir(parents=True)
    PROJECT.mkdir(parents=True)
    chunks = []
    for start in range(0, len(targets), CHUNK_SIZE):
        number = len(chunks)
        group = targets[start:start + CHUNK_SIZE]
        folder = REPORT / f"chunk_{number:02d}"
        lines = ["\t".join((str(x["index"]), x["elf_va"], str(x["size_bytes"]),
                             x["source_body_sha256"], x["symbol"])) for x in group]
        path = folder / "targets.tsv"
        atomic_bytes(path, ("\n".join(lines) + "\n").encode("utf-8"))
        chunks.append({"chunk": number, "first_index": group[0]["index"],
                       "last_index": group[-1]["index"], "count": len(group),
                       "target_tsv_sha256": sha256(path)})
    if len(chunks) != 6 or sum(x["count"] for x in chunks) != 1376:
        raise RuntimeError("chunk layout changed")
    write_json(REPORT / "target_index.json", {
        "schema_version": "2.1.2", "task_id": "TASK_172", "revision": 1,
        "generated_at": now(), "standard_sha256": STANDARD_SHA,
        "task_sha256": TASK_SHA, "source_sha256": SOURCE_SHA,
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "defined_nonzero_function_symbols": 1582,
        "unique_export_vas": 1376, "chunks": chunks, "targets": targets})
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_172", "revision": 1,
        "status": "TARGETS_VERIFIED", "generated_at": now(),
        "lease_id": LEASE_ID, "fencing_token": FENCE,
        "source_bodies_rehashed": 1376, "chunks": 6,
        "ghidra_chunks_started": 0})
    audit = ("# TASK_172 R1 audit index\n\n"
             f"Canonical standard read: `{STANDARD}` SHA-256 `{STANDARD_SHA}`.\n\n"
             f"Task SHA-256 `{TASK_SHA}`; lease `{LEASE_ID}`, fence `{FENCE}`.\n\n"
             f"Original source `{SOURCE}` SHA-256 `{SOURCE_SHA}`. "
             "All exported body ranges PT_LOAD mapped and hashed. "
             "Real Codex subagent lane; no AGY.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    print(json.dumps({"export_symbols": 1582, "unique_export_vas": 1376,
                      "chunks": len(chunks)}))


if __name__ == "__main__":
    main()
