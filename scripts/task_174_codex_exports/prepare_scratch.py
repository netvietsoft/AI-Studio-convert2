"""Make a clearly labeled, bounded Ghidra-only copy of the truncated ELF.

This never changes the original source. Missing program/section ranges are removed
from the scratch metadata so the loader cannot silently treat absent bytes as code.
"""

from __future__ import annotations

import hashlib
import json
import struct
from pathlib import Path

from forensic import PINNED_SHA, SOURCE, parse
from package import require_lease
from unwind import parse_unwind


ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / "RESEARCH_WORK/TASK_174_R1/scratch/libmfxkit_truncated_repaired_for_ghidra.so"
META = ROOT / "RULES/REPORT/TASK_174_REPORT_R1/raw/scratch_repair.json"
TARGETS = ROOT / "RULES/REPORT/TASK_174_REPORT_R1/raw/ghidra_sample_targets.tsv"


def main() -> None:
    require_lease()
    original = SOURCE.read_bytes()
    if hashlib.sha256(original).hexdigest() != PINNED_SHA:
        raise ValueError("original SHA differs from pinned task")
    elf = parse(original)
    unwind = parse_unwind(original)
    complete = [r for r in unwind["records"] if r["body_complete_in_input"]]
    if len(complete) != 1020:
        raise ValueError("unexpected complete unwind range count")
    if OUT.exists() or META.exists() or TARGETS.exists():
        raise RuntimeError("scratch repair or target selection already exists")
    repaired = bytearray(original)
    # Clear absent section table pointer/count. Only the scratch copy is changed.
    struct.pack_into("<Q", repaired, 40, 0)
    struct.pack_into("<HHH", repaired, 58, 0, 0, 0)
    changes = ["e_shoff/e_shentsize/e_shnum/e_shstrndx cleared"]
    for p in elf["program_headers"]:
        ph = elf["header"]["phoff"] + p["index"] * elf["header"]["phentsize"]
        reg = p["file_region"]
        if p["type"] == 1 and p["flags"] & 1:
            if p["index"] != 1 or p["file_offset"] != 0:
                raise ValueError("unexpected executable load")
            struct.pack_into("<QQ", repaired, ph + 32, len(original), len(original))
            changes.append(f"PHDR {p['index']} RX filesz/memsz clamped to retained EOF")
        elif p["file_size"] and not reg["entirely_present"]:
            # Missing non-executable PT_LOAD/PT_DYNAMIC/PT_GNU_RELRO are made
            # inert only in this scratch copy; original locations stay in raw JSON.
            repaired[ph : ph + elf["header"]["phentsize"]] = b"\x00" * elf["header"]["phentsize"]
            changes.append(f"PHDR {p['index']} unbacked header zeroed in scratch")
    selected = []
    for ordinal in range(20):
        pos = round(ordinal * (len(complete) - 1) / 19)
        selected.append(complete[pos])
    if len({r["index"] for r in selected}) != 20:
        raise ValueError("sample not unique")
    OUT.parent.mkdir(parents=True, exist_ok=True)
    META.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_bytes(repaired)
    TARGETS.write_text("".join(
        f"{i}\t0x{r['function_va']:x}\t{r['function_size']}\t"
        f"{r['retained_body_sha256']}\tFDE_{r['index']:04d}\n"
        for i, r in enumerate(selected, 1)
    ), encoding="utf-8")
    META.write_text(json.dumps({
        "schema": "task174-ghidra-scratch-repair-v1",
        "original_path": str(SOURCE),
        "original_sha256": PINNED_SHA,
        "original_bytes": len(original),
        "scratch_path": str(OUT),
        "scratch_sha256": hashlib.sha256(repaired).hexdigest(),
        "scratch_bytes": len(repaired),
        "modified_metadata_only": True,
        "changes": changes,
        "purpose": "one bounded Ghidra import/decompile sample of 20 byte-complete unwind ranges",
        "not_for_runtime_or_export_census": True,
        "sample_count": len(selected),
        "sample_fde_indices": [r["index"] for r in selected],
        "targets_sha256": hashlib.sha256(TARGETS.read_bytes()).hexdigest(),
    }, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"scratch_sha256": hashlib.sha256(repaired).hexdigest(),
                      "targets": len(selected), "changes": len(changes)}))


if __name__ == "__main__":
    main()
