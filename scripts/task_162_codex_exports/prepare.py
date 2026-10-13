"""Independently pin all original ELF export bodies before Ghidra work."""
from __future__ import annotations

import hashlib
import json

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs
from elftools.elf.elffile import ELFFile

from common import (AGENT_ID, FENCE, LEASE_ID, LIBRARIES, REPORT, SOURCE_DIR,
                    STANDARD, STANDARD_SHA, TASK_SHA, atomic_bytes, check_lease,
                    now, sha256, write_json)

CHUNK_SIZE = 128

def main() -> None:
    check_lease()
    if REPORT.exists():
        raise RuntimeError("TASK_162 report already prepared")
    batch = []
    disassembler = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    disassembler.skipdata = True
    for name, (expected_sha, expected_count) in LIBRARIES.items():
        source = SOURCE_DIR / name
        raw = source.read_bytes()
        if hashlib.sha256(raw).hexdigest() != expected_sha:
            raise RuntimeError("source SHA mismatch: " + name)
        with source.open("rb") as handle:
            elf = ELFFile(handle)
            if elf["e_machine"] != "EM_AARCH64":
                raise RuntimeError("ELF architecture mismatch: " + name)
            segments = [{"index": i, "va": int(p["p_vaddr"]), "file_offset": int(p["p_offset"]),
                         "file_size": int(p["p_filesz"]), "memory_size": int(p["p_memsz"])}
                        for i, p in enumerate(elf.iter_segments()) if p["p_type"] == "PT_LOAD"]
            dynsym = elf.get_section_by_name(".dynsym")
            if dynsym is None:
                raise RuntimeError("missing dynsym: " + name)
            by_va = {}
            for symbol in dynsym.iter_symbols():
                if symbol["st_info"]["type"] != "STT_FUNC" or symbol["st_shndx"] == "SHN_UNDEF":
                    continue
                size = int(symbol["st_size"])
                if size <= 0:
                    continue
                by_va.setdefault(int(symbol["st_value"]), []).append((symbol.name, size))
        if len(by_va) != expected_count:
            raise RuntimeError(f"export count changed for {name}: {len(by_va)}")
        folder = REPORT / name
        targets = []
        assembly_lines = []
        for va in sorted(by_va):
            aliases = sorted(by_va[va], key=lambda item: (-item[1], item[0]))
            symbol, size = aliases[0]
            mappings = [(s["index"], s["file_offset"] + va - s["va"])
                        for s in segments if s["va"] <= va and va + size <= s["va"] + s["file_size"]]
            if len(mappings) != 1:
                raise RuntimeError(f"ambiguous PT_LOAD mapping {name}:0x{va:x}+{size}")
            segment_index, offset = mappings[0]
            body = raw[offset:offset + size]
            if len(body) != size:
                raise RuntimeError("truncated body: " + name)
            record = {"index": len(targets) + 1, "elf_va": f"0x{va:x}", "size_bytes": size,
                      "file_offset": f"0x{offset:x}", "pt_load_segment_index": segment_index,
                      "source_body_sha256": hashlib.sha256(body).hexdigest(), "symbol": symbol,
                      "aliases": [{"name": alias, "size_bytes": sz} for alias, sz in aliases]}
            targets.append(record)
            instructions = [f"0x{i.address:x}: {i.mnemonic} {i.op_str}".rstrip()
                            for i in disassembler.disasm(body, va)]
            assembly_lines.append(json.dumps({"index": record["index"], "elf_va": record["elf_va"],
                                              "source_bytes_hex": body.hex(),
                                              "capstone_source_assembly": instructions},
                                             ensure_ascii=False))
        chunks = []
        for start in range(0, len(targets), CHUNK_SIZE):
            subset = targets[start:start + CHUNK_SIZE]
            chunk_folder = folder / f"chunk_{len(chunks):03d}"
            lines = ["\t".join([str(t["index"]), t["elf_va"], str(t["size_bytes"]),
                                t["source_body_sha256"], t["symbol"]]) for t in subset]
            path = chunk_folder / "targets.tsv"
            atomic_bytes(path, ("\n".join(lines) + "\n").encode("utf-8"))
            chunks.append({"chunk": len(chunks), "folder": chunk_folder.relative_to(REPORT).as_posix(),
                           "count": len(subset), "first_index": subset[0]["index"],
                           "last_index": subset[-1]["index"], "target_tsv_sha256": sha256(path)})
        atomic_bytes(folder / "source_assembly.ndjson", ("\n".join(assembly_lines) + "\n").encode("utf-8"))
        write_json(folder / "source_index.json", {"task_id": "TASK_162", "revision": 1,
            "library": name, "source_path": str(source), "source_sha256": expected_sha,
            "source_file_size": len(raw), "elf_machine": "EM_AARCH64", "pt_load_segments": segments,
            "defined_nonzero_function_symbols": sum(map(len, by_va.values())),
            "unique_export_vas": len(targets), "targets": targets,
            "chunks": chunks, "generated_at": now(), "task_sha256": TASK_SHA,
            "standard_sha256": STANDARD_SHA, "lease_id": LEASE_ID, "fencing_token": FENCE})
        batch.append({"library": name, "source_sha256": expected_sha,
                      "unique_export_vas": len(targets), "chunks": len(chunks),
                      "max_body_size_bytes": max(t["size_bytes"] for t in targets)})
    write_json(REPORT / "source_batch_index.json", {"task_id": "TASK_162", "revision": 1,
        "generated_at": now(), "libraries": batch,
        "total_unique_export_vas": sum(x["unique_export_vas"] for x in batch)})
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_162", "revision": 1,
        "status": "SOURCE_BODIES_VERIFIED", "generated_at": now(), "lease_id": LEASE_ID,
        "fencing_token": FENCE, "source_bodies_rehashed": 1670, "ghidra_imports_started": 0})
    audit = (f"# TASK_162 R1 audit index\n\nFull canonical standard read: `{STANDARD}` "
             f"SHA-256 `{STANDARD_SHA}`.\n\nExact task SHA-256 `{TASK_SHA}`; "
             f"assignee `{AGENT_ID}`; lease `{LEASE_ID}`; fence `{FENCE}`.\n\n"
             "Pinned original source paths, PT_LOAD maps, all exported body hashes and "
             "source assembly are in per-library indexes. Codex subagent lane; no AGY.\n")
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    print(json.dumps({"source_vas": 1670, "libraries": batch}), flush=True)

if __name__ == "__main__":
    main()
