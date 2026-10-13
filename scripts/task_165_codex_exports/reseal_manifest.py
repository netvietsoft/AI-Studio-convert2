"""One-shot controller-schema correction: include nested historical COMPLETE.json files."""
from __future__ import annotations

import json

from common import (FENCE, LEASE_ID, REPORT, ROOT, SCRIPTS, check_lease,
                    now, sha256, write_json)

NESTED = {"historical_raw/TASK_151/COMPLETE.json",
          "historical_raw/TASK_152/COMPLETE.json"}

def main() -> None:
    check_lease()
    seal_path = REPORT / "COMPLETE.json"
    seal = json.loads(seal_path.read_text(encoding="utf-8"))
    if (seal.get("task_id"), seal.get("revision"), seal.get("status"),
            seal.get("lease_id"), seal.get("fencing_token")) != (
            "TASK_165", 1, "COMPLETE", LEASE_ID, FENCE):
        raise RuntimeError("existing seal identity changed")
    previous = seal["files"]
    for rel, digest in previous.items():
        if sha256(REPORT / rel) != digest:
            raise RuntimeError("existing sealed evidence changed: " + rel)
    observed = {path.relative_to(REPORT).as_posix(): sha256(path)
                for path in sorted(REPORT.rglob("*")) if path.is_file() and
                path != seal_path and path.name != "PROGRESS.json"}
    if set(observed) - set(previous) != NESTED or set(previous) - set(observed):
        raise RuntimeError("manifest difference is not exactly two nested historical seals")
    if seal["report_bytes_excluding_seal_and_progress"] != sum(
            (REPORT / rel).stat().st_size for rel in previous):
        raise RuntimeError("previous aggregate byte count changed")
    previous_code = seal["code_files"]
    for rel, digest in previous_code.items():
        if rel.endswith("/verify_and_seal.py"):
            continue
        if sha256(ROOT / rel) != digest:
            raise RuntimeError("unrelated code changed: " + rel)
    code = {path.relative_to(ROOT).as_posix(): sha256(path)
            for path in sorted(SCRIPTS.iterdir()) if path.is_file() and
            path.suffix in (".py", ".java")}
    total = sum((REPORT / rel).stat().st_size for rel in observed)
    if total > 134217728:
        raise RuntimeError("corrected report exceeds task cap")
    seal["files"] = observed
    seal["code_files"] = code
    seal["report_bytes_excluding_seal_and_progress"] = total
    seal["generated_at"] = now()
    seal["manifest_correction"] = {
        "reason": "Controller counts nested historical COMPLETE.json as report evidence files",
        "added_paths": sorted(NESTED), "raw_evidence_bytes_modified": 0,
        "corrected_at": now()}
    check_lease()
    write_json(seal_path, seal)
    print(json.dumps({"manifest_sha256": sha256(seal_path),
                      "files": len(observed), "code_files": len(code),
                      "report_bytes": total, "added_paths": sorted(NESTED)}), flush=True)

if __name__ == "__main__":
    main()
