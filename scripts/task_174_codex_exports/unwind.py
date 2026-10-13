"""Validate retained GNU EH-frame function ranges against original ELF bytes.

Unwind FDEs are not `.dynsym` exports; this script makes that distinction explicit.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import struct
from pathlib import Path

from forensic import SOURCE, PINNED_SHA, parse


def uleb(data: bytes, offset: int) -> tuple[int, int]:
    value = 0
    shift = 0
    for _ in range(10):
        b = data[offset]
        offset += 1
        value |= (b & 0x7F) << shift
        if b < 0x80:
            return value, offset
        shift += 7
    raise ValueError("ULEB128 too long")


def sleb(data: bytes, offset: int) -> tuple[int, int]:
    value = 0
    shift = 0
    for _ in range(10):
        b = data[offset]
        offset += 1
        value |= (b & 0x7F) << shift
        shift += 7
        if b < 0x80:
            if b & 0x40:
                value |= -(1 << shift)
            return value, offset
    raise ValueError("SLEB128 too long")


def cie_encoding(data: bytes, offset: int, cache: dict[int, dict]) -> dict:
    if offset in cache:
        return cache[offset]
    length, cid = struct.unpack_from("<II", data, offset)
    if cid != 0 or length < 8 or offset + 4 + length > len(data):
        raise ValueError(f"invalid CIE at {offset:#x}")
    version = data[offset + 8]
    aug_end = data.index(b"\0", offset + 9, offset + 4 + length)
    aug = data[offset + 9 : aug_end].decode("ascii")
    cur = aug_end + 1
    code_align, cur = uleb(data, cur)
    data_align, cur = sleb(data, cur)
    return_reg, cur = uleb(data, cur)
    encoding = None
    if aug.startswith("z"):
        aug_len, cur = uleb(data, cur)
        aug_data_end = cur + aug_len
        for char in aug[1:]:
            if char == "R":
                encoding = data[cur]
                cur += 1
            elif char == "L":
                cur += 1  # LSDA pointer encoding byte
            elif char == "P":
                pointer_encoding = data[cur]
                cur += 1
                fmt = pointer_encoding & 0x0F
                if fmt == 0x00:  # DW_EH_PE_absptr, ELF64
                    cur += 8
                elif fmt in (0x02, 0x0A):
                    cur += 2
                elif fmt in (0x03, 0x0B):
                    cur += 4
                elif fmt in (0x04, 0x0C):
                    cur += 8
                elif fmt == 0x01:
                    _, cur = uleb(data, cur)
                elif fmt == 0x09:
                    _, cur = sleb(data, cur)
                else:
                    raise ValueError(f"unsupported personality format {fmt:#x}")
            else:
                raise ValueError(f"unsupported CIE augmentation {aug!r}")
        if cur > aug_data_end:
            raise ValueError("CIE augmentation overrun")
    result = {
        "offset": offset,
        "length": length,
        "version": version,
        "augmentation": aug,
        "code_alignment": code_align,
        "data_alignment": data_align,
        "return_register": return_reg,
        "fde_encoding": encoding,
    }
    cache[offset] = result
    return result


def parse_unwind(data: bytes) -> dict:
    elf = parse(data)
    eh = [p for p in elf["program_headers"] if p["type"] == 0x6474E550]
    if len(eh) != 1:
        raise ValueError("expected one PT_GNU_EH_FRAME")
    p = eh[0]
    if not p["file_region"]["entirely_present"]:
        raise ValueError("unwind header truncated")
    offset, vaddr, filesz = p["file_offset"], p["virtual_address"], p["file_size"]
    version, ptr_enc, count_enc, table_enc = struct.unpack_from("<BBBB", data, offset)
    if (version, ptr_enc, count_enc, table_enc) != (1, 0x1B, 0x03, 0x3B):
        raise ValueError("unsupported GNU EH frame header encoding")
    rel = struct.unpack_from("<i", data, offset + 4)[0]
    eh_frame_va = vaddr + 4 + rel
    count = struct.unpack_from("<I", data, offset + 8)[0]
    if count > 20000 or 12 + count * 8 != filesz:
        raise ValueError("unwind table count/size mismatch")
    loads = [p for p in elf["program_headers"] if p["type"] == 1]

    def file_offset_for(va: int) -> int | None:
        for load in loads:
            start = load["virtual_address"]
            end = start + load["file_size"]
            if start <= va < end:
                return load["file_offset"] + va - start
        return None

    eh_frame_offset = file_offset_for(eh_frame_va)
    if eh_frame_offset is None or eh_frame_offset >= len(data):
        raise ValueError("eh_frame pointer missing from retained bytes")
    records = []
    cache: dict[int, dict] = {}
    prior_start = -1
    for i in range(count):
        start_rel, fde_rel = struct.unpack_from("<ii", data, offset + 12 + i * 8)
        table_start_va = vaddr + start_rel
        fde_va = vaddr + fde_rel
        fde_offset = file_offset_for(fde_va)
        if fde_offset is None or fde_offset + 16 > len(data):
            raise ValueError(f"FDE {i} not retained")
        fde_len, cie_pointer = struct.unpack_from("<II", data, fde_offset)
        if fde_len == 0xFFFFFFFF or fde_len < 12 or fde_offset + 4 + fde_len > len(data):
            raise ValueError(f"FDE {i} length invalid/truncated")
        cie_offset = fde_offset + 4 - cie_pointer
        cie = cie_encoding(data, cie_offset, cache)
        if cie["fde_encoding"] != 0x1B:
            raise ValueError(f"FDE {i} CIE encoding unsupported")
        initial_rel, span = struct.unpack_from("<iI", data, fde_offset + 8)
        initial_va = fde_va + 8 + initial_rel
        if initial_va != table_start_va:
            raise ValueError(f"FDE {i} start mismatch with GNU table")
        if initial_va < prior_start:
            raise ValueError(f"FDE {i} table not sorted by start")
        prior_start = initial_va
        exec_load = next(
            (
                load for load in loads
                 if load["flags"] & 1
                 and load["virtual_address"] <= initial_va
                 and initial_va + span <= load["virtual_address"] + load["file_size"]),
            None,
        )
        body_offset = file_offset_for(initial_va)
        retained = (
            0 if body_offset is None else max(0, min(span, len(data) - body_offset))
        )
        body = data[body_offset : body_offset + retained] if body_offset is not None else b""
        records.append(
            {
                "index": i,
                "fde_va": fde_va,
                "fde_offset": fde_offset,
                "cie_offset": cie_offset,
                "function_va": initial_va,
                "function_size": span,
                "function_end_va": initial_va + span,
                "in_declared_executable_load": exec_load is not None,
                "body_file_offset": body_offset,
                "retained_body_bytes": retained,
                "body_complete_in_input": exec_load is not None and retained == span,
                "retained_body_sha256": hashlib.sha256(body).hexdigest(),
            }
        )
    complete = [r for r in records if r["body_complete_in_input"]]
    partial = [r for r in records if 0 < r["retained_body_bytes"] < r["function_size"]]
    absent = [r for r in records if r["retained_body_bytes"] == 0]
    return {
        "schema": "task174-unwind-ranges-v1",
        "source_sha256": hashlib.sha256(data).hexdigest(),
        "source_bytes": len(data),
        "eh_frame_header_offset": offset,
        "eh_frame_header_bytes": filesz,
        "eh_frame_va": eh_frame_va,
        "eh_frame_offset": eh_frame_offset,
        "fde_table_count": count,
        "cies": list(cache.values()),
        "complete_original_body_ranges": len(complete),
        "partial_original_body_ranges": len(partial),
        "absent_original_body_ranges": len(absent),
        "dynamic_export_census": "UNKNOWN",
        "scope_note": "FDEs delimit unwind-covered ranges only, not dynamic exports or semantic parity.",
        "records": records,
    }


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--output", type=Path, required=True)
    args = ap.parse_args()
    data = SOURCE.read_bytes()
    if hashlib.sha256(data).hexdigest() != PINNED_SHA:
        raise ValueError("source hash differs from task pin")
    result = parse_unwind(data)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({k: result[k] for k in (
        "fde_table_count", "complete_original_body_ranges", "partial_original_body_ranges",
        "absent_original_body_ranges", "dynamic_export_census"
    )}))


if __name__ == "__main__":
    main()
