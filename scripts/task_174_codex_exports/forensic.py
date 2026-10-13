"""Bounded ELF64 forensics for TASK_174; never repairs the original input."""

from __future__ import annotations

import argparse
import hashlib
import json
import struct
from pathlib import Path


SOURCE = Path(
    r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libmfxkit.so"
)
PINNED_SHA = "78923a90997d34c5dd51215a6cd2bc26c9731806fd9037e4aa71fd3873d3bb4f"


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def region(data: bytes, offset: int, length: int) -> dict:
    if offset < 0 or length < 0:
        raise ValueError("negative ELF region")
    end = offset + length
    available = max(0, min(end, len(data)) - offset)
    if offset >= len(data):
        available = 0
    raw = data[offset : offset + available]
    return {
        "declared_offset": offset,
        "declared_length": length,
        "declared_end": end,
        "available_length": available,
        "missing_length": length - available,
        "entirely_present": available == length,
        "available_sha256": digest(raw),
    }


def parse(data: bytes) -> dict:
    if len(data) < 64 or data[:4] != b"\x7fELF":
        raise ValueError("ELF magic/header missing")
    elf_class, endian = data[4], data[5]
    if (elf_class, endian) != (2, 1):
        raise ValueError(f"expected ELF64 little-endian, got {elf_class}/{endian}")
    values = struct.unpack_from("<HHIQQQIHHHHHH", data, 16)
    names = (
        "type", "machine", "version", "entry", "phoff", "shoff", "flags",
        "ehsize", "phentsize", "phnum", "shentsize", "shnum", "shstrndx",
    )
    hdr = dict(zip(names, values))
    if hdr["ehsize"] != 64 or hdr["phentsize"] != 56 or hdr["phnum"] > 64:
        raise ValueError("unsupported or unreasonable ELF/program-header layout")
    ph_table = region(data, hdr["phoff"], hdr["phentsize"] * hdr["phnum"])
    if not ph_table["entirely_present"]:
        raise ValueError("program header table itself truncated")
    sh_table = region(data, hdr["shoff"], hdr["shentsize"] * hdr["shnum"])
    phdrs = []
    for i in range(hdr["phnum"]):
        off = hdr["phoff"] + i * hdr["phentsize"]
        typ, flags, p_off, vaddr, paddr, filesz, memsz, align = struct.unpack_from(
            "<IIQQQQQQ", data, off
        )
        phdrs.append(
            {
                "index": i,
                "type": typ,
                "flags": flags,
                "file_offset": p_off,
                "virtual_address": vaddr,
                "physical_address": paddr,
                "file_size": filesz,
                "memory_size": memsz,
                "alignment": align,
                "file_region": region(data, p_off, filesz),
            }
        )
    loads = [p for p in phdrs if p["type"] == 1]
    dynamics = [p for p in phdrs if p["type"] == 2]
    dynamic_entries = []
    for p in dynamics:
        if not p["file_region"]["entirely_present"]:
            continue
        if p["file_size"] % 16:
            raise ValueError("PT_DYNAMIC length not multiple of 16")
        for i in range(p["file_size"] // 16):
            tag, value = struct.unpack_from("<qQ", data, p["file_offset"] + i * 16)
            dynamic_entries.append({"tag": tag, "value": value})
            if tag == 0:
                break

    # PT_GNU_EH_FRAME is an unwind index. Its addresses are not dynamic exports.
    eh_headers = []
    for p in phdrs:
        if p["type"] != 0x6474E550 or not p["file_region"]["entirely_present"]:
            continue
        b = data[p["file_offset"] : p["file_offset"] + p["file_size"]]
        item = {
            "program_header_index": p["index"],
            "version": b[0] if len(b) >= 1 else None,
            "eh_frame_ptr_encoding": b[1] if len(b) >= 2 else None,
            "fde_count_encoding": b[2] if len(b) >= 3 else None,
            "table_encoding": b[3] if len(b) >= 4 else None,
        }
        # Common Android AArch64 .eh_frame_hdr: all three values sdata4 pcrel.
        # Decode only the count when its encoding makes the interpretation exact.
        if len(b) >= 12 and b[2] == 0x03:
            item["fde_count_unsigned"] = struct.unpack_from("<I", b, 8)[0]
        elif len(b) >= 12 and b[2] == 0x0B:
            item["fde_count_signed"] = struct.unpack_from("<i", b, 8)[0]
        eh_headers.append(item)

    original_sha = digest(data)
    return {
        "schema": "task174-elf-forensics-v1",
        "source": str(SOURCE),
        "file_bytes": len(data),
        "sha256": original_sha,
        "pinned_sha_match": original_sha == PINNED_SHA,
        "header": hdr,
        "program_header_table": ph_table,
        "section_header_table": sh_table,
        "program_headers": phdrs,
        "load_segments": len(loads),
        "dynamic_segments": len(dynamics),
        "dynamic_entries_recovered": dynamic_entries,
        "dynamic_export_census": "UNKNOWN" if not dynamic_entries else "REQUIRES_SYMBOL_COUNT_VALIDATION",
        "unwind_headers": eh_headers,
        "interpretation": (
            "PT_DYNAMIC is absent from retained file bytes; no DT_SYMTAB/DT_HASH/"
            "DT_GNU_HASH can be read. Dynamic export count is UNKNOWN, not zero. "
            "Available PT_LOAD bytes are only a retained prefix of original input."
            if dynamics and not dynamic_entries
            else "Inspect recovered dynamic entries before claiming any export count."
        ),
    }


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--output", type=Path, required=True)
    args = ap.parse_args()
    data = SOURCE.read_bytes()
    result = parse(data)
    if not result["pinned_sha_match"]:
        raise ValueError("source hash differs from exact task pin")
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(
        json.dumps(
            {
                "sha256": result["sha256"],
                "file_bytes": result["file_bytes"],
                "phnum": result["header"]["phnum"],
                "sh_table_missing": result["section_header_table"]["missing_length"],
                "dynamic_entries": len(result["dynamic_entries_recovered"]),
                "dynamic_export_census": result["dynamic_export_census"],
            }
        )
    )


if __name__ == "__main__":
    main()
