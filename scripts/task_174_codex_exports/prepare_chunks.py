"""Prepare disjoint Ghidra batches excluding the 20 already decompiled samples."""

from __future__ import annotations

import hashlib
import json
from pathlib import Path

from package import require_lease


ROOT = Path(__file__).resolve().parents[2]
REPORT = ROOT / "RULES/REPORT/TASK_174_REPORT_R1/raw"
CHUNKS = REPORT / "ghidra_chunks"


def main() -> None:
    require_lease()
    unwind = json.loads((REPORT / "unwind_ranges.json").read_text(encoding="utf-8"))
    repair = json.loads((REPORT / "scratch_repair.json").read_text(encoding="utf-8"))
    sampled = set(repair["sample_fde_indices"])
    complete = [r for r in unwind["records"] if r["body_complete_in_input"]]
    remaining = [r for r in complete if r["index"] not in sampled]
    if len(remaining) != 1000 or len(sampled) != 20:
        raise ValueError("sample/remaining partition mismatch")
    if CHUNKS.exists():
        raise RuntimeError("chunk directory exists; do not regenerate")
    CHUNKS.mkdir(parents=True)
    manifest = {"schema": "task174-disjoint-ghidra-chunks-v1", "source_sha256": unwind["source_sha256"],
                "sampled_fde_indices": sorted(sampled), "remaining_count": len(remaining), "chunks": []}
    for chunk in range(5):
        rows = remaining[chunk * 200 : (chunk + 1) * 200]
        folder = CHUNKS / f"chunk_{chunk + 1:02d}"
        folder.mkdir()
        path = folder / "targets.tsv"
        path.write_text("".join(
            f"{r['index'] + 1}\t0x{r['function_va']:x}\t{r['function_size']}\t"
            f"{r['retained_body_sha256']}\tFDE_{r['index']:04d}\n"
            for r in rows
        ), encoding="utf-8")
        manifest["chunks"].append({
            "chunk": chunk + 1, "count": len(rows),
            "first_fde_index": rows[0]["index"], "last_fde_index": rows[-1]["index"],
            "targets_sha256": hashlib.sha256(path.read_bytes()).hexdigest(),
            "folder": str(folder.relative_to(ROOT)).replace("\\", "/"),
        })
    (CHUNKS / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"remaining": len(remaining), "chunks": len(manifest["chunks"])}))


if __name__ == "__main__":
    main()
