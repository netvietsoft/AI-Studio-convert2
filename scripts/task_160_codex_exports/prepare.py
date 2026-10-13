"""Enumerate and hash all original defined nonzero AArch64 export function VAs."""

from __future__ import annotations

import hashlib
import json

from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, LEASE_ID, LIBRARIES, REPORT, SOURCE_DIR,
                    STANDARD, STANDARD_SHA, TASK_SHA, atomic_bytes, check_lease,
                    now, sha256, write_json)

CHUNK_SIZE = 256


def mapped_bytes(elf: ELFFile, source, va: int, size: int) -> tuple[bytes, int]:
    for segment in elf.iter_segments():
        if segment["p_type"] != "PT_LOAD":
            continue
        start, length = int(segment["p_vaddr"]), int(segment["p_filesz"])
        if start <= va and va + size <= start + length:
            offset = int(segment["p_offset"]) + va - start
            with source.open("rb") as stream:
                stream.seek(offset)
                data = stream.read(size)
            if len(data) == size:
                return data, offset
    raise RuntimeError(f"unmapped original PT_LOAD body: {source.name}:0x{va:x}+{size}")


def main() -> None:
    check_lease()
    if REPORT.exists():
        raise RuntimeError("TASK_160 report already exists")
    summaries = []
    for name, (expected_sha, expected_count) in LIBRARIES.items():
        source = SOURCE_DIR / name
        if sha256(source) != expected_sha:
            raise RuntimeError("source identity changed: " + name)
        with source.open("rb") as stream:
            elf = ELFFile(stream)
            if elf["e_machine"] != "EM_AARCH64":
                raise RuntimeError("source architecture changed: " + name)
            symbols = elf.get_section_by_name(".dynsym")
            if symbols is None:
                raise RuntimeError(".dynsym absent: " + name)
            by_va = {}
            for symbol in symbols.iter_symbols():
                if (symbol["st_info"]["type"] != "STT_FUNC" or
                    symbol["st_shndx"] == "SHN_UNDEF" or
                    int(symbol["st_size"]) <= 0 or int(symbol["st_value"]) == 0):
                    continue
                by_va.setdefault(int(symbol["st_value"]), []).append((symbol.name, int(symbol["st_size"])))
            if len(by_va) != expected_count:
                raise RuntimeError(f"export VA count changed for {name}: {len(by_va)}")
            targets = []
            for va in sorted(by_va):
                aliases = sorted(by_va[va], key=lambda pair: (-pair[1], pair[0]))
                symbol, size = aliases[0]
                if size > 65536:
                    raise RuntimeError(f"target exceeds 64KiB: {name}:0x{va:x}")
                body, offset = mapped_bytes(elf, source, va, size)
                targets.append({"index": len(targets) + 1, "elf_va": f"0x{va:x}",
                                "size_bytes": size, "file_offset": f"0x{offset:x}",
                                "source_body_sha256": hashlib.sha256(body).hexdigest(),
                                "symbol": symbol, "aliases": [alias for alias, _ in aliases]})
        folder = REPORT / name
        chunks = []
        for start in range(0, len(targets), CHUNK_SIZE):
            number = len(chunks) + 1
            subset = targets[start:start + CHUNK_SIZE]
            chunk_folder = folder / f"chunk_{number:02d}"
            tsv = chunk_folder / "targets.tsv"
            lines = ["\t".join((str(item["index"]), item["elf_va"],
                     str(item["size_bytes"]), item["source_body_sha256"], item["symbol"]))
                     for item in subset]
            atomic_bytes(tsv, ("\n".join(lines) + "\n").encode("utf-8"))
            chunks.append({"chunk": number, "count": len(subset),
                           "first_index": subset[0]["index"], "last_index": subset[-1]["index"],
                           "target_tsv_sha256": sha256(tsv)})
        write_json(folder / "target_index.json", {
            "schema_version": "2.1.2", "task_id": "TASK_160", "revision": 1,
            "library": name, "generated_at": now(), "source_path": str(source),
            "standard_sha256": STANDARD_SHA, "task_sha256": TASK_SHA,
            "source_sha256": expected_sha, "source_size": source.stat().st_size,
            "lease_id": LEASE_ID, "fencing_token": FENCE,
            "defined_nonzero_function_symbols": sum(len(group) for group in by_va.values()),
            "unique_export_vas": len(targets), "targets": targets, "chunks": chunks})
        summaries.append({"library": name, "source_path": str(source),
                          "source_sha256": expected_sha, "source_size": source.stat().st_size,
                          "defined_nonzero_function_symbols": sum(len(group) for group in by_va.values()),
                          "unique_export_vas": len(targets), "chunks": len(chunks)})
    if sum(item["unique_export_vas"] for item in summaries) != 3326:
        raise RuntimeError("aggregate target count changed")
    write_json(REPORT / "source_batch_index.json", {
        "task_id": "TASK_160", "revision": 1, "generated_at": now(),
        "libraries": summaries, "total_unique_export_vas": 3326})
    write_json(REPORT / "PROGRESS.json", {
        "task_id": "TASK_160", "revision": 1, "status": "TARGETS_VERIFIED",
        "generated_at": now(), "lease_id": LEASE_ID, "fencing_token": FENCE,
        "libraries_verified": 1, "source_bodies_rehashed": 3326,
        "ghidra_imports_started": 0})
    audit = ("# TASK_160 R1 audit index\n\n"
             f"Canonical standard fully read: `{STANDARD}` SHA-256 `{STANDARD_SHA}`.\n\n"
             f"Task SHA-256 `{TASK_SHA}`; actor `{AGENT_ID}`; lease `{LEASE_ID}`; fence `{FENCE}`.\n\n"
             "Original ELF paths, hashes, sizes, PT_LOAD body hashes, VA aliases and chunk boundaries "
             "are recorded in `source_batch_index.json` and per-library `target_index.json`. "
             "Static research only; no product or device behavior claim.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    print(json.dumps({"libraries": 1, "unique_export_vas": 3326,
                      "chunks": sum(x["chunks"] for x in summaries)}))


if __name__ == "__main__":
    main()
