"""Verify immutable R1 evidence, pin R2 targets, and copy analyzed Ghidra project."""

from __future__ import annotations

import json
import shutil
from pathlib import Path

from common import (AGENT, CEO_REVIEW, FENCE, LEASE, ORIGINAL_PROJECT,
                    OWN_PROJECT, R1_REPORT, R1_SEAL_SHA, REPORT, SOURCE, SOURCE_SHA,
                    STANDARD, STANDARD_SHA, TARGETS, TARGETS_SHA, TASK, TASK_SHA,
                    atomic_bytes, guard, now, sha, write_json)


def hashes(root: Path) -> dict[str, str]:
    return {p.relative_to(root).as_posix(): sha(p)
            for p in sorted(root.rglob("*")) if p.is_file()}


def main() -> None:
    guard()
    if REPORT.exists() or OWN_PROJECT.exists():
        raise RuntimeError("R2 preparation already exists")
    target_manifest = json.loads(TARGETS.read_text(encoding="utf-8"))
    targets = target_manifest["targets"]
    if len(targets) != 141:
        raise RuntimeError("target count changed")
    r1_seal = json.loads((R1_REPORT / "COMPLETE.json").read_text(encoding="utf-8"))
    if r1_seal["task_id"] != "TASK_184" or r1_seal["revision"] != 1:
        raise RuntimeError("R1 seal identity mismatch")
    for name, digest in r1_seal["files"].items():
        if sha(R1_REPORT / name) != digest:
            raise RuntimeError("R1 sealed report changed: " + name)
    r1_candidate_hashes = {}
    for index in range(1, 142):
        chunk = (index - 1) // 47 + 1
        path = R1_REPORT / "ghidra" / f"chunk_{chunk:02d}" / "candidates" / f"candidate_{index:03d}.json"
        relative = path.relative_to(R1_REPORT).as_posix()
        if r1_seal["files"].get(relative) != sha(path):
            raise RuntimeError(f"R1 candidate {index} not sealed")
        r1_candidate_hashes[relative] = sha(path)
    write_json(REPORT / "r1_reference_receipt.json", {
        "schema": "task184-r2-immutable-r1-reference-v1", "generated_at": now(),
        "review_file": str(CEO_REVIEW), "review_sha256": sha(CEO_REVIEW),
        "r1_seal_sha256": R1_SEAL_SHA, "r1_report_files_verified": len(r1_seal["files"]),
        "r1_141_candidate_file_sha256": r1_candidate_hashes,
        "r1_source_index_sha256": sha(R1_REPORT / "source/source_index.json"),
        "r1_assembly_sha256": sha(R1_REPORT / "source/assembly.ndjson"),
        "r1_coverage_index_sha256": sha(R1_REPORT / "coverage_index.json"),
        "r1_project_copy_receipt_sha256": sha(R1_REPORT / "project_copy_receipt.json"),
        "r1_immutable": True,
    })
    atomic_bytes(REPORT / "targets.tsv", "".join(
        f"{index}\t{row['elf_va']}\t{row['size_bytes']}\t{row['file_offset']}\t{row['body_sha256']}\n"
        for index, row in enumerate(targets, 1)
    ).encode("utf-8"))
    original_before = hashes(ORIGINAL_PROJECT)
    if len(original_before) != 9 or not (ORIGINAL_PROJECT / "Task158.gpr").is_file():
        raise RuntimeError("original analyzed project unavailable")
    guard()
    OWN_PROJECT.parent.mkdir(parents=True, exist_ok=True)
    shutil.copytree(ORIGINAL_PROJECT, OWN_PROJECT)
    (OWN_PROJECT / "Task158.gpr").rename(OWN_PROJECT / "Task184R2.gpr")
    (OWN_PROJECT / "Task158.rep").rename(OWN_PROJECT / "Task184R2.rep")
    original_after = hashes(ORIGINAL_PROJECT)
    copied = hashes(OWN_PROJECT)
    expected_copy = {name.replace("Task158", "Task184R2", 1): digest
                     for name, digest in original_before.items()}
    if original_before != original_after or copied != expected_copy:
        raise RuntimeError("project source changed or copy byte mismatch")
    write_json(REPORT / "project_copy_receipt.json", {
        "source_project": str(ORIGINAL_PROJECT), "owned_project": str(OWN_PROJECT),
        "fresh_imports": 0, "source_project_unchanged": True,
        "copied_file_count": len(copied), "copied_file_sha256": copied,
    })
    atomic_bytes(REPORT / "00_AUDIT_INDEX.md", (
        "# TASK_184 R2 audit index\n\n"
        f"Canonical fully read: `{STANDARD}` SHA-256 `{STANDARD_SHA}`.\n\n"
        f"Exact R2 task `{TASK}` SHA-256 `{TASK_SHA}`; 141-target manifest `{TARGETS}` SHA-256 `{TARGETS_SHA}`.\n\n"
        f"Actor `{AGENT}`, lease `{LEASE}`, fence `{FENCE}`. Original SO `{SOURCE}` SHA-256 `{SOURCE_SHA}`.\n\n"
        f"This is a report-only correction of immutable R1 seal `{R1_SEAL_SHA}` following CEO review `{CEO_REVIEW}`. "
        "R1 candidates and C-like strings are referenced by SHA-256, never rewritten. "
        "Ghidra body address-set membership is separately checked against every pinned FDE byte. "
        "No behavior, pixel parity, product Phase PASS, or V4/P7 claim.\n"
    ).encode("utf-8"))
    write_json(REPORT / "PROGRESS.json", {"task_id": "TASK_184", "revision": 2,
              "status": "R1_REFERENCE_AND_PROJECT_COPY_VERIFIED", "generated_at": now(),
              "lease_id": LEASE, "fencing_token": FENCE, "r1_candidates_verified": 141,
              "project_copy_files": len(copied), "fresh_imports": 0})
    print(json.dumps({"r1_report_files_verified": len(r1_seal["files"]),
                      "r1_candidates_verified": 141, "project_files_copied": len(copied)}))


if __name__ == "__main__":
    main()
