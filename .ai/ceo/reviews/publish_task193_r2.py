"""Publish a narrow TASK_193 correction revision without resetting its deadline."""

import copy
import datetime as dt
import hashlib
import json

from prepare_publish_tasks189_190 import ROOT, STANDARD_SHA, atomic_file
from controller import Controller, file_sha


TASK = ROOT / "RULES/TASK/TASK_193_SO45_CODEX_INTERNAL_ACTIVE.md"
OLD_SHA = "2b54c486f2acb3702bb966d65809381c75121825a35c13592e217d7e5769e9f0"
OLD_SEAL = "043a7b9232dd43630b3cf3bd9155c3bc37492e9d19230017f2f36780e49799d5"
OLD_FINGERPRINT = "1949fc2bf631717871e80b7e35f862f9d9c0232084184ce8d0cb78d6957d5202"
REVIEW = ROOT / f".ai/ceo/reviews/TASK_193-{OLD_FINGERPRINT}.md"
ARCHIVE = ROOT / f".ai/ceo/reviews/TASK_193_R1_TASK_ARCHIVE_{OLD_SHA}.md"
R1_REPORT = ROOT / "RULES/REPORT/TASK_193_REPORT_R1"
MANIFEST = ROOT / ".ai/ceo/reviews/TASK_193_internal_targets.json"
SOURCE_SHA = "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4"
DEADLINE = "2026-10-13T13:11:10.526083+00:00"


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    if file_sha(TASK) != OLD_SHA or file_sha(R1_REPORT / "COMPLETE.json") != OLD_SEAL:
        raise RuntimeError("immutable R1 baseline changed")
    if file_sha(MANIFEST) != "44c08dc8cb67c4e3dec44dbd29726602dcd74e5be771d8ba926252c7d8e95d44":
        raise RuntimeError("target manifest changed")
    if ARCHIVE.exists() or (ROOT / "RULES/REPORT/TASK_193_REPORT_R2").exists():
        raise RuntimeError("R2 already prepared")
    now = dt.datetime.now(dt.timezone.utc)
    if now >= dt.datetime.fromisoformat(DEADLINE):
        raise RuntimeError("original deadline passed")
    stamp = now.isoformat(timespec="microseconds").replace("+00:00", "Z")
    report = "RULES/REPORT/TASK_193_REPORT_R2"
    meta = {"schema_version": "2.1.2", "task_id": "TASK_193", "revision": 2,
            "status": "ACTIVE", "assignee": "/root/so45_mtfilter_next",
            "agent_id": "/root/so45_mtfilter_next", "priority": "P1",
            "dependencies": [{"task_id": "TASK_189", "revision": 1}],
            "mode": "RESEARCH_CORRECTION", "report_folder": report,
            "files_allowed": [report + "/**", "scripts/task_193_codex_correction_r2/**"],
            "files_forbidden": ["RULES/TASK/**", "RULES/REPORT/TASK_193_REPORT_R1/**",
                                "RESEARCH_WORK/**", "SOURCE/**", ".ai/**", "app/**", "apps/**",
                                "lib-*/**", "Backend/**", "services/**", "packages/**"],
            "max_minutes": 90, "max_cpu": 1, "max_heap": "1G",
            "expected_lease_id": "LEASE-CEO-WORKER-TASK_193-R2", "standard_sha256": STANDARD_SHA,
            "source_libraries": {"libMTFilterKernel.so": {"sha256": SOURCE_SHA,
                                                        "defined_nonzero_export_vas": 2362}},
            "target_manifest_path": MANIFEST.relative_to(ROOT).as_posix(),
            "target_manifest_sha256": file_sha(MANIFEST), "target_candidate_count": 60,
            "correction_of": {"task_revision": 1, "task_sha256": OLD_SHA,
                              "report_folder": "RULES/REPORT/TASK_193_REPORT_R1",
                              "complete_sha256": OLD_SEAL,
                              "worker_verification_sha256": file_sha(R1_REPORT / "WORKER_VERIFICATION.json"),
                              "ceo_review_fingerprint": OLD_FINGERPRINT,
                              "ceo_review_sha256": file_sha(REVIEW)},
            "created_at": stamp, "modified_time": stamp,
            "budget_deadline_utc": DEADLINE,
            "authorization_reference": "Chairman Tony direct Codex SO45 decoding; CEO R1 NEEDS_FIX review"}
    body = f"""# TASK_193 R2 — correct sealed global zero-based labels only

STATUS: ACTIVE
ASSIGNEE: /root/so45_mtfilter_next
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

CEO R1 review `{REVIEW.relative_to(ROOT).as_posix()}` found every one of 60 derived `WORKER_VERIFICATION.json` rows reports `selected_zero_index = index - 1`; the exact target manifest uses **global zero-based** indices 192..255 excluding 201, 211, 216, 235, so `selected_zero_index` must equal `index` for each row. Source index, source assembly, Ghidra rows, VA/body hashes and all 10,383 source/effective p-code positions were independently verified; the CEO fresh replay of 60 original rows, three temporary corrections and three fresh rollback checks passed. This revision fixes the summary join label only.

Fully reread `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` SHA-256 `{STANDARD_SHA}` and AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, config/state/locks/END, then this exact R2 task and manifest. Claim ACTIVE TASK_193 revision2 as `/root/so45_mtfilter_next` via controller with lease `LEASE-CEO-WORKER-TASK_193-R2` before writes. Read R1 report/source/project only; write exclusively `{report}/**` and `scripts/task_193_codex_correction_r2/**`. The original absolute deadline remains **{DEADLINE}**; no budget reset.

Create `WORKER_VERIFICATION_CORRECTED.json` by copying the sealed R1 `WORKER_VERIFICATION.json` and changing only each row's `selected_zero_index` to its exact manifest global index. Verify 60/60 one-field deltas, every other field byte-equivalent after canonical JSON comparison, and preserve original R1 file, task, manifest and seal SHA. Produce `00_AUDIT_INDEX.md` canonical-read path/hash, `01_MASTER_REPORT.md`, `CORRECTION_DELTA.json` listing old/new index for all 60 and source hashes, `PROGRESS.json`, and `COMPLETE.json` SHA-256 manifest of every fixed R2 report/code file. The R2 report must expressly reference immutable R1 evidence and CEO verifier/replay and make only bounded PARTIAL static-research claims. Do **not** rerun Ghidra, edit R1/old code/project/source/P0, count four excluded oversized bodies, infer semantic behavior/product Phase PASS/V4/P7, commit/push or self-review. CEO will independently validate the corrected overlay and the exact stable R2 fingerprint.
"""
    raw = body.encode("utf8")
    with ctl.transaction() as (registry, state):
        lease = ctl.ceo_lease(registry)
        if file_sha(TASK) != OLD_SHA:
            raise RuntimeError("R1 task changed during publication")
        prior = state["tasks"]["TASK_193"].get("verdict", {})
        if (prior.get("disposition"), prior.get("revision"), prior.get("fingerprint")) != (
                "NEEDS_FIX", 1, OLD_FINGERPRINT):
            raise RuntimeError("exact R1 NEEDS_FIX review absent")
        ctl.authorized(lease, ARCHIVE)
        ctl.authorized(lease, TASK)
        atomic_file(ARCHIVE, TASK.read_bytes())
        atomic_file(TASK, raw)
        ctl.event(state, "CODEX_TASK_CORRECTION_REVISION_PUBLISHED", task_id="TASK_193",
                  revision=2, task_sha256=hashlib.sha256(raw).hexdigest(),
                  prior_task_archive=ARCHIVE.relative_to(ROOT).as_posix(),
                  prior_fingerprint=OLD_FINGERPRINT, deadline=DEADLINE,
                  scope="summary selected_zero_index only; immutable R1 raw evidence")
    print(json.dumps({"task_id": "TASK_193", "revision": 2,
                      "task_sha256": file_sha(TASK),
                      "archive_sha256": file_sha(ARCHIVE),
                      "old_seal_sha256": OLD_SEAL, "deadline": DEADLINE}))


if __name__ == "__main__":
    main()
