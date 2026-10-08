"""Diagnostic reproduction and reference comparison for container classification failures (Investigation 1).

Extracts the minimal pure R3 classification fragment from scripts/task063_r3/generate_deliverables_r3.py
and contrasts it with a unified diagnostic reference classifier.
Never mutates original binary inputs on disk; all mutations are in-memory.
"""

import hashlib
import struct
import zlib
from pathlib import Path
from typing import Dict, Any, Tuple, Optional


def sha256_bytes(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def crc32_bytes(b: bytes) -> int:
    return zlib.crc32(b) & 0xFFFFFFFF


# =====================================================================
# Fragment 1: R3 Original Classification Logic (Pure Extraction)
# Source Anchor: scripts/task063_r3/generate_deliverables_r3.py:252-278 & 658-665
# =====================================================================

def parse_zip_entry_r3(data: bytes, idx: int) -> Optional[Dict[str, Any]]:
    """Pure extraction of R3 local file header parsing (lines 252-278)."""
    if idx + 30 > len(data):
        return None
    sig, version, flags, method, mtime, mdate, crc, compressed, declared, nlen, elen = struct.unpack_from(
        "<IHHHHHIIIHH", data, idx
    )
    nameend = idx + 30 + nlen
    begin = nameend + elen
    if nameend > len(data) or begin > len(data):
        return None

    name = data[idx + 30:nameend].decode("utf-8", errors="replace")
    available_bytes = min(declared, len(data) - begin)
    payload_data = data[begin:begin + available_bytes]
    complete = (begin + declared <= len(data)) and (available_bytes == declared)

    return {
        "header_offset": idx,
        "data_offset": begin,
        "flags": flags,
        "method": method,
        "declared_bytes": declared,
        "available_bytes": available_bytes,
        "complete": complete,
        "missing_bytes": declared - available_bytes,
        "declared_crc32": f"0x{crc:08x}",
        "available_crc32": f"0x{crc32_bytes(payload_data):08x}",
        "available_sha256": sha256_bytes(payload_data),
        "payload_bytes": payload_data,
        "name": name,
    }


def classify_status_r3(entry: Optional[Dict[str, Any]], disk_data: bytes) -> Tuple[str, str, bool]:
    """Pure extraction of R3 status determination (lines 658-665).

    Bugs documented in CEO review:
    1. Computes byte_match, but never uses byte_match in the if/else condition!
    2. Uses entry['complete'] alone to select EXACT_PAYLOAD_MATCH.
    3. Fails to check declared CRC, flags, compression method, or disk byte match.
    4. For incomplete entries, claims PARTIAL_CONTAINER_TRUNCATED without verifying prefix equality.
    """
    if not entry:
        return "NOT_IN_XAPK", "Absent from XAPK container", False

    # Check byte equality with on-disk data (computed in R3 line 658, but ignored in branching!)
    byte_match = (entry["payload_bytes"] == disk_data)

    if entry["complete"]:
        c_status = "EXACT_PAYLOAD_MATCH"
        trunc_note = "None (Fully bounded ELF64, declared size/CRC/payload match container byte-for-byte)"
    else:
        c_status = "PARTIAL_CONTAINER_TRUNCATED"
        c_decl = entry["declared_bytes"]
        c_avail = entry["available_bytes"]
        c_data = entry["data_offset"]
        missing = entry["missing_bytes"]
        pct = (missing / c_decl * 100) if c_decl else 0.0
        trunc_note = (
            f"Container interrupted before EOF. On-disk size {len(disk_data)} B matches "
            f"container prefix (bytes {c_data}..{c_data+c_avail}). Deficit: {missing} B missing "
            f"({pct:.2f}% data loss). Tail UNKNOWN."
        )

    return c_status, trunc_note, byte_match


# =====================================================================
# Fragment 2: Unified Diagnostic Reference Classifier
# Demonstrates correct unified gating on header, compression, CRC, and payload bytes.
# =====================================================================

def classify_container_entry_reference(
    container_data: bytes,
    header_offset: int,
    disk_data: bytes,
    container_total_len: int
) -> Dict[str, Any]:
    """Unified reference classifier enforcing all invariants.

    Invariants checked:
    1. Local header signature is PK\\x03\\x04.
    2. Header offsets and length boundaries within container length.
    3. General purpose bit flags must be 0 (no data descriptors / encryption).
    4. Compression method must be 0 (STORED).
    5. Compressed size must equal declared uncompressed size.
    6. If complete (data_offset + declared <= container_len):
       - available_bytes == declared_bytes == len(disk_data)
       - CRC32(payload) == declared_crc
       - payload_bytes == disk_data
       -> EXACT_PAYLOAD_MATCH
    7. If incomplete (container interrupted before declared payload):
       - available_bytes < declared_bytes
       - available_bytes == container_total_len - data_offset (cut at EOF)
       - disk_data[:available_bytes] == payload_bytes (prefix equality)
       -> PARTIAL_CONTAINER_TRUNCATED
    8. Any failure returns specific rejection status:
       - UNSUPPORTED_FLAGS
       - UNSUPPORTED_COMPRESSION
       - CORRUPTED_HEADER
       - CORRUPTED_CRC
       - PAYLOAD_MISMATCH
       - TRUNCATION_NOT_AT_EOF
    """
    if header_offset + 30 > len(container_data):
        return {
            "status": "CORRUPTED_HEADER",
            "reason": f"Header offset {header_offset} exceeds container bounds ({len(container_data)} B)",
            "valid": False,
        }

    sig, version, flags, method, mtime, mdate, crc, compressed, declared, nlen, elen = struct.unpack_from(
        "<IHHHHHIIIHH", container_data, header_offset
    )

    if sig != 0x04034B50:  # PK\x03\x04
        return {
            "status": "CORRUPTED_HEADER",
            "reason": f"Invalid signature 0x{sig:08x}, expected 0x04034b50",
            "valid": False,
        }

    nameend = header_offset + 30 + nlen
    data_offset = nameend + elen

    if nameend > len(container_data) or data_offset > len(container_data):
        return {
            "status": "CORRUPTED_HEADER",
            "reason": f"Filename/extra length exceeds container bounds (data_offset={data_offset}, total={len(container_data)})",
            "valid": False,
        }

    entry_name = container_data[header_offset + 30:nameend].decode("utf-8", errors="replace")

    # Flag check
    if flags != 0:
        return {
            "status": "UNSUPPORTED_FLAGS",
            "reason": f"Non-zero flags 0x{flags:04x} (bit 3 data descriptor / encryption not supported for raw payload comparison)",
            "valid": False,
            "entry_name": entry_name,
        }

    # Method check (must be STORED = 0)
    if method != 0:
        return {
            "status": "UNSUPPORTED_COMPRESSION",
            "reason": f"Compression method {method} != 0 (STORED required for direct payload equality)",
            "valid": False,
            "entry_name": entry_name,
        }

    # Stored compression invariant: compressed == declared
    if compressed != declared:
        return {
            "status": "CORRUPTED_HEADER",
            "reason": f"Stored compression size mismatch: compressed {compressed} != declared {declared}",
            "valid": False,
            "entry_name": entry_name,
        }

    available_bytes = min(declared, len(container_data) - data_offset)
    payload_slice = container_data[data_offset:data_offset + available_bytes]
    is_complete = (data_offset + declared <= len(container_data))

    if is_complete:
        # Must match declared size exactly
        if len(payload_slice) != declared:
            return {
                "status": "CORRUPTED_PAYLOAD_SIZE",
                "reason": f"Available payload {len(payload_slice)} != declared {declared}",
                "valid": False,
            }

        # Check declared CRC32
        actual_crc = crc32_bytes(payload_slice)
        if actual_crc != crc:
            return {
                "status": "CORRUPTED_CRC",
                "reason": f"Calculated CRC 0x{actual_crc:08x} != declared CRC 0x{crc:08x}",
                "valid": False,
                "declared_crc": f"0x{crc:08x}",
                "actual_crc": f"0x{actual_crc:08x}",
            }

        # Check on-disk byte equality
        if len(disk_data) != declared:
            return {
                "status": "PAYLOAD_MISMATCH",
                "reason": f"Disk file size {len(disk_data)} != declared {declared}",
                "valid": False,
            }

        if payload_slice != disk_data:
            return {
                "status": "PAYLOAD_MISMATCH",
                "reason": "Container payload bytes do not match on-disk extracted bytes",
                "valid": False,
            }

        return {
            "status": "EXACT_PAYLOAD_MATCH",
            "valid": True,
            "entry_name": entry_name,
            "declared_bytes": declared,
            "available_bytes": available_bytes,
            "declared_crc": f"0x{crc:08x}",
            "actual_crc": f"0x{actual_crc:08x}",
            "sha256": sha256_bytes(payload_slice),
            "note": "Fully validated: header constraints, size, CRC32, and byte-for-byte disk match satisfied",
        }

    else:
        # Partial container entry: interrupted before EOF
        # Invariant 1: Truncation must be exactly at container EOF
        if data_offset + available_bytes != container_total_len:
            return {
                "status": "TRUNCATION_NOT_AT_EOF",
                "reason": f"Entry ends at {data_offset + available_bytes}, before container EOF {container_total_len}",
                "valid": False,
            }

        # Invariant 2: Disk data prefix must match available container payload exactly
        if len(disk_data) < available_bytes:
            return {
                "status": "PAYLOAD_MISMATCH",
                "reason": f"On-disk file size {len(disk_data)} smaller than available container prefix {available_bytes}",
                "valid": False,
            }

        disk_prefix = disk_data[:available_bytes]
        if payload_slice != disk_prefix:
            return {
                "status": "PAYLOAD_MISMATCH",
                "reason": "Available container prefix bytes do not match on-disk file prefix",
                "valid": False,
            }

        missing_bytes = declared - available_bytes
        # Invariant 3: We MUST NOT claim a complete CRC match for a truncated file!
        partial_crc = crc32_bytes(payload_slice)

        return {
            "status": "PARTIAL_CONTAINER_TRUNCATED",
            "valid": True,
            "entry_name": entry_name,
            "declared_bytes": declared,
            "available_bytes": available_bytes,
            "missing_bytes": missing_bytes,
            "deficit_pct": (missing_bytes / declared * 100) if declared else 0.0,
            "declared_crc": f"0x{crc:08x}",
            "partial_crc": f"0x{partial_crc:08x}",
            "prefix_sha256": sha256_bytes(payload_slice),
            "note": (
                f"Container truncated at EOF. Available prefix ({available_bytes} B) matches on-disk "
                f"prefix byte-for-byte. Deficit: {missing_bytes} B missing. Complete CRC unverifiable without missing tail."
            ),
        }
