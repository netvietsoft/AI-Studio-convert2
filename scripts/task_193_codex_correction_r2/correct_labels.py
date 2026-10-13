"""TASK_193 R2: sealed, label-only correction of the R1 verification summary."""

from __future__ import annotations

import copy
import hashlib
import json
import os
from datetime import datetime, timezone
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
REPORT = ROOT / "RULES/REPORT/TASK_193_REPORT_R2"
SCRIPT = Path(__file__).resolve()
STANDARD = ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt"
TASK = ROOT / "RULES/TASK/TASK_193_SO45_CODEX_INTERNAL_ACTIVE.md"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_193_internal_targets.json"
R1_COMPLETE = ROOT / "RULES/REPORT/TASK_193_REPORT_R1/COMPLETE.json"
R1_VERIFICATION = ROOT / "RULES/REPORT/TASK_193_REPORT_R1/WORKER_VERIFICATION.json"
CEO_REVIEW = ROOT / ".ai/ceo/reviews/TASK_193-1949fc2bf631717871e80b7e35f862f9d9c0232084184ce8d0cb78d6957d5202.md"
EXPECTED = {
    STANDARD: "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
    TASK: "555ee794be1651ef718d83df662269c11aef8a31a23ab71343194b750d7bcb66",
    MANIFEST: "44c08dc8cb67c4e3dec44dbd29726602dcd74e5be771d8ba926252c7d8e95d44",
    R1_COMPLETE: "043a7b9232dd43630b3cf3bd9155c3bc37492e9d19230017f2f36780e49799d5",
    R1_VERIFICATION: "df46aa0a024a4de4750d21931fca6814c805622224e4a4b6d048bf404271ab6c",
    CEO_REVIEW: "bcad460333000d0129037deb702c6228ae6554e0cc7f88b560e2b6229719762e",
}
LEASE_ID = "LEASE-CEO-WORKER-TASK_193-R2"
AGENT_ID = "/root/so45_mtfilter_next"
FENCE = 1227
DEADLINE = datetime.fromisoformat("2026-10-13T13:11:10.526083+00:00")


def digest(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def canonical(value: object) -> bytes:
    return json.dumps(value, sort_keys=True, separators=(",", ":"), ensure_ascii=False).encode("utf-8")


def checked_lease() -> None:
    now = datetime.now(timezone.utc)
    assert now < DEADLINE, "TASK_193 R2 deadline expired"
    end = ROOT / ".ai/ceo/END_AGENT_SESSION.flag"
    assert not (end.is_file() and end.read_text(encoding="utf-8").strip().upper() == "TRUE"), "END_AGENT_SESSION = TRUE"
    locks = json.loads((ROOT / ".ai/locks.json").read_text(encoding="utf-8"))
    matches = [entry for entry in locks["active_locks"] if entry.get("lease_id") == LEASE_ID]
    assert len(matches) == 1, "R2 lease missing or duplicated"
    lease = matches[0]
    assert lease["agent_id"] == AGENT_ID
    assert lease["task_id"] == "TASK_193" and lease["task_revision"] == 2
    assert lease["task_sha"].lower() == EXPECTED[TASK]
    assert lease["fencing_token"] == FENCE and lease["status"] == "ACTIVE"
    assert datetime.fromisoformat(lease["expiry"]) > now
    for rel in ["RULES/REPORT/TASK_193_REPORT_R2/**", "scripts/task_193_codex_correction_r2/**"]:
        assert rel in lease["files_allowed"]


def atomic_write(path: Path, payload: bytes) -> None:
    checked_lease()
    assert path == SCRIPT or path.is_relative_to(REPORT), "outside R2 write scope"
    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_name(path.name + f".tmp-{os.getpid()}")
    with temp.open("xb") as stream:
        stream.write(payload)
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temp, path)


def json_bytes(value: object) -> bytes:
    return (json.dumps(value, ensure_ascii=False, indent=2) + "\n").encode("utf-8")


def main() -> None:
    checked_lease()
    actual = {str(path.relative_to(ROOT)): digest(path) for path in EXPECTED}
    for path, expected_sha in EXPECTED.items():
        assert actual[str(path.relative_to(ROOT))] == expected_sha, path
    r1_complete = json.loads(R1_COMPLETE.read_text(encoding="utf-8"))
    assert r1_complete["files"]["WORKER_VERIFICATION.json"] == EXPECTED[R1_VERIFICATION]
    source = json.loads(R1_VERIFICATION.read_text(encoding="utf-8"))
    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    assert source["task_id"] == "TASK_193" and source["revision"] == 1
    assert source["target_manifest_sha256"] == EXPECTED[MANIFEST]
    original_rows = source["rows"]
    targets = manifest["targets"]
    assert len(original_rows) == len(targets) == 60
    assert manifest["excluded_oversized_global_indices"] == [201, 211, 216, 235]
    corrected = copy.deepcopy(source)
    deltas = []
    for original, row, target in zip(original_rows, corrected["rows"], targets, strict=True):
        global_index = target["global_nonexport_fde_index"]
        assert row["index"] == global_index
        assert row["elf_va"] == target["elf_va"]
        assert row["fde_size_bytes"] == target["size_bytes"]
        assert row["original_pt_load_body_sha256"] == target["body_sha256"]
        assert original["selected_zero_index"] == global_index - 1
        row["selected_zero_index"] = global_index
        before_other = {key: value for key, value in original.items() if key != "selected_zero_index"}
        after_other = {key: value for key, value in row.items() if key != "selected_zero_index"}
        assert canonical(before_other) == canonical(after_other)
        deltas.append({
            "global_nonexport_fde_index": global_index,
            "elf_va": target["elf_va"],
            "old_selected_zero_index": original["selected_zero_index"],
            "new_selected_zero_index": row["selected_zero_index"],
            "unchanged_other_fields_canonical_sha256": hashlib.sha256(canonical(before_other)).hexdigest(),
        })
    original_outer = {key: value for key, value in source.items() if key != "rows"}
    corrected_outer = {key: value for key, value in corrected.items() if key != "rows"}
    assert canonical(original_outer) == canonical(corrected_outer)
    assert [row["selected_zero_index"] for row in corrected["rows"]] == [target["global_nonexport_fde_index"] for target in targets]
    assert set(range(192, 256)) - set(row["index"] for row in corrected["rows"]) == {201, 211, 216, 235}

    correction = {
        "schema_version": "2.1.2", "task_id": "TASK_193", "revision": 2,
        "correction_scope": "60 R1 WORKER_VERIFICATION.rows[*].selected_zero_index labels only",
        "canonical_read_path": str(STANDARD), "canonical_read_sha256": EXPECTED[STANDARD],
        "source_sha256": actual, "source_outer_fields_canonical_sha256": hashlib.sha256(canonical(original_outer)).hexdigest(),
        "corrected_outer_fields_canonical_sha256": hashlib.sha256(canonical(corrected_outer)).hexdigest(),
        "changed_row_count": len(deltas), "unchanged_other_field_count_assertion": "all rows canonical-equal with selected_zero_index omitted",
        "deltas": deltas,
        "limits": "label-only overlay; R1 raw evidence immutable; four oversized indices excluded; no semantic/product phase claim",
    }
    atomic_write(REPORT / "WORKER_VERIFICATION_CORRECTED.json", json_bytes(corrected))
    atomic_write(REPORT / "CORRECTION_DELTA.json", json_bytes(correction))
    audit = f"""# TASK_193 R2 audit index

I fully reread the canonical Standard at `{STANDARD}` and verified SHA-256 `{EXPECTED[STANDARD]}` before claiming or writing. I also reread `AGENTS.md`, `Docs/rules.md`, `.ai/ceo/SO45_TO_V4_PLAN.md`, project memory, task, manifest and controller state/locks/END. R2 task SHA-256 `{EXPECTED[TASK]}`; target manifest SHA-256 `{EXPECTED[MANIFEST]}`.

Lease `{LEASE_ID}` was claimed by `{AGENT_ID}`, revision 2, fence `{FENCE}`. This package is an overlay correcting only 60 `selected_zero_index` fields in the R1 summary. R1 `COMPLETE.json` SHA-256 `{EXPECTED[R1_COMPLETE]}` and R1 `WORKER_VERIFICATION.json` SHA-256 `{EXPECTED[R1_VERIFICATION]}` remain unchanged. CEO review SHA-256 `{EXPECTED[CEO_REVIEW]}` records independent verifier and fresh replay of 60 original rows, 3 transient corrections and 3 rollback checks.

`CORRECTION_DELTA.json` records each old/new value and canonical hash of all other row fields. `WORKER_VERIFICATION_CORRECTED.json` retains the R1 schema and all other values. `COMPLETE.json` seals all fixed R2 report/code files.
"""
    master = """# TASK_193 R2 master report

The R1 summary assigned each of 60 selected nonexport FDE candidates the preceding global zero-based index. This overlay sets `selected_zero_index` equal to the exact manifest `global_nonexport_fde_index` in every row, with a 60/60 one-field delta audit. All other row fields and all top-level fields compare equal under canonical JSON, and the input hashes match the sealed R1 task, manifest, verification, and CEO review.

This is a bounded static-research PARTIAL result for MTFilter candidate indices 192..255 excluding oversized indices 201, 211, 216 and 235. It inherits the immutable R1 raw ELF/Ghidra evidence and the CEO R1 independent verifier/replay. No Ghidra run, original/project edit, behavioral assertion, all-45 coverage claim, product Phase PASS, V4 or P7 authorization follows from this label correction. Independent CEO review of R2 is still required.
"""
    atomic_write(REPORT / "00_AUDIT_INDEX.md", audit.encode("utf-8"))
    atomic_write(REPORT / "01_MASTER_REPORT.md", master.encode("utf-8"))
    progress = {
        "schema_version": "2.1.2", "task_id": "TASK_193", "revision": 2,
        "status": "REPORTING", "agent_id": AGENT_ID, "lease_id": LEASE_ID,
        "fencing_token": FENCE, "corrected_labels": 60, "other_field_differences": 0,
        "research_result": "PARTIAL_LABEL_ONLY_CORRECTION",
        "updated_at": datetime.now(timezone.utc).isoformat(),
    }
    atomic_write(REPORT / "PROGRESS.json", json_bytes(progress))
    # The controller compares `files` to report-relative fixed files. Progress
    # is volatile, and executable sources belong in the separate code map.
    fixed_report = [
        path for path in REPORT.rglob("*")
        if path.is_file() and path.name not in {"COMPLETE.json", "PROGRESS.json", "PROGRESS.md"}
    ]
    fixed_report.sort(key=lambda path: path.relative_to(REPORT).as_posix())
    seal = {
        "schema_version": "2.1.2", "task_id": "TASK_193", "revision": 2,
        "status": "COMPLETE", "research_result": "PARTIAL_LABEL_ONLY_CORRECTION",
        "generated_at": datetime.now(timezone.utc).isoformat(),
        "agent_id": AGENT_ID, "lease_id": LEASE_ID, "fencing_token": FENCE,
        "standard_path": str(STANDARD), "standard_sha256": EXPECTED[STANDARD],
        "task_sha256": EXPECTED[TASK], "target_manifest_sha256": EXPECTED[MANIFEST],
        "r1_complete_sha256": EXPECTED[R1_COMPLETE], "r1_worker_verification_sha256": EXPECTED[R1_VERIFICATION],
        "ceo_r1_review_sha256": EXPECTED[CEO_REVIEW],
        "corrected_labels": 60, "other_field_differences": 0,
        "files": {path.relative_to(REPORT).as_posix(): digest(path) for path in fixed_report},
        "code_files": {SCRIPT.relative_to(ROOT).as_posix(): digest(SCRIPT)},
        "limits": "R2 summary-only overlay; independent CEO review pending; no behavior/product/V4/P7 claim",
    }
    atomic_write(REPORT / "COMPLETE.json", json_bytes(seal))
    print(json.dumps({"complete_sha256": digest(REPORT / "COMPLETE.json"), "report_files": len(fixed_report), "code_files": 1, "corrected_labels": 60, "other_field_differences": 0}))


if __name__ == "__main__":
    main()
