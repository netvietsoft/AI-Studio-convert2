"""Package only byte-complete unwind ranges from the pinned original SO."""

from __future__ import annotations

import argparse
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

from capstone import CS_ARCH_ARM64, CS_MODE_ARM, Cs

from forensic import PINNED_SHA, SOURCE
from unwind import parse_unwind


ROOT = Path(__file__).resolve().parents[2]
LEASE = "LEASE-CEO-WORKER-TASK_174-R1"
FENCE = 1203


def require_lease() -> None:
    locks = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matches = [
        item for item in locks["active_locks"]
        if item.get("lease_id") == LEASE
        and item.get("task_id") == "TASK_174"
        and item.get("fencing_token") == FENCE
        and item.get("status") == "ACTIVE"
    ]
    if len(matches) != 1:
        raise RuntimeError("TASK_174 exact lease/fence not active")
    expiry = datetime.fromisoformat(matches[0]["expiry"].replace("Z", "+00:00"))
    if expiry <= datetime.now(timezone.utc):
        raise RuntimeError("TASK_174 lease expired")


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--output-dir", type=Path, required=True)
    args = ap.parse_args()
    require_lease()
    if args.output_dir.resolve() != (ROOT / "RESEARCH_WORK/TASK_174_R1").resolve():
        raise ValueError("output must be exact task research scope")
    source = SOURCE.read_bytes()
    if hashlib.sha256(source).hexdigest() != PINNED_SHA:
        raise ValueError("pinned source changed")
    parsed = parse_unwind(source)
    complete = [r for r in parsed["records"] if r["body_complete_in_input"]]
    if len(complete) != 1020:
        raise ValueError("unexpected complete FDE count")
    decoder = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    decoder.skipdata = True
    args.output_dir.mkdir(parents=True, exist_ok=True)
    blob_path = args.output_dir / "complete_fde_bodies.bin"
    asm_path = args.output_dir / "complete_fde_assembly.ndjson"
    index_path = args.output_dir / "complete_fde_index.json"
    if blob_path.exists() or asm_path.exists() or index_path.exists():
        raise RuntimeError("package already exists; no overwrite")
    index = []
    aggregate_size = 0
    skipdata_count = 0
    with blob_path.open("wb") as blob, asm_path.open("w", encoding="utf-8", newline="\n") as asm:
        for item in complete:
            offset = item["body_file_offset"]
            length = item["function_size"]
            body = source[offset : offset + length]
            if hashlib.sha256(body).hexdigest() != item["retained_body_sha256"]:
                raise ValueError("body hash mismatch")
            if length == 0 or length % 4:
                raise ValueError("invalid ARM64 body size")
            instructions = list(decoder.disasm(body, item["function_va"]))
            if sum(ins.size for ins in instructions) != length:
                raise ValueError("disassembly does not cover full body")
            skipdata_count += sum(ins.mnemonic == ".byte" for ins in instructions)
            blob.write(body)
            asm.write(json.dumps({
                "fde_index": item["index"],
                "va": item["function_va"],
                "body_sha256": item["retained_body_sha256"],
                "instructions": [
                    {"va": ins.address, "mnemonic": ins.mnemonic, "op_str": ins.op_str}
                    for ins in instructions
                ],
            }, separators=(",", ":")) + "\n")
            index.append({
                "fde_index": item["index"],
                "va": item["function_va"],
                "size": length,
                "original_file_offset": offset,
                "blob_offset": aggregate_size,
                "sha256": item["retained_body_sha256"],
                "instruction_count": len(instructions),
            })
            aggregate_size += length
    index_path.write_text(json.dumps({
        "schema": "task174-complete-unwind-body-index-v1",
        "source_sha256": PINNED_SHA,
        "classification": "complete original PT_LOAD unwind-covered bodies, not dynamic exports",
        "count": len(index),
        "aggregate_bytes": aggregate_size,
        "skipdata_instruction_count": skipdata_count,
        "blob_sha256": hashlib.sha256(blob_path.read_bytes()).hexdigest(),
        "assembly_sha256": hashlib.sha256(asm_path.read_bytes()).hexdigest(),
        "items": index,
    }, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({
        "count": len(index), "aggregate_bytes": aggregate_size,
        "skipdata_instruction_count": skipdata_count,
        "blob_sha256": hashlib.sha256(blob_path.read_bytes()).hexdigest(),
    }))


if __name__ == "__main__":
    main()
