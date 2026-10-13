"""Reassign unsealed TASK_187 evidence to a real Codex continuation lane."""
import copy
import datetime as dt
import hashlib
import json
import os
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller, file_sha  # noqa: E402

STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
TASK = ROOT / "RULES/TASK/TASK_187_SO45_CODEX_INTERNAL_ACTIVE.md"
ARCHIVE = ROOT / ".ai/ceo/reviews/TASK_187_R1_TASK_SNAPSHOT.md"
ASSIGNEE = "/root/so45_ai_model_search"


def atomic_file(path, data):
    temp = path.with_name(path.name + ".tmp")
    with temp.open("xb") as stream:
        stream.write(data)
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temp, path)


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    r1_raw = TASK.read_bytes()
    r1_text = r1_raw.decode("utf8")
    r1 = json.loads(r1_text.split("```json\n", 1)[1].split("\n```", 1)[0])
    if r1["task_id"] != "TASK_187" or r1["revision"] != 1 or r1["assignee"] != "/root/so45_pvg_renderer":
        raise RuntimeError("unexpected R1 task")
    report1 = ROOT / "RULES/REPORT/TASK_187_REPORT_R1"
    if (report1 / "COMPLETE.json").exists() or ARCHIVE.exists():
        raise RuntimeError("R1 sealed or already archived")
    progress = json.loads((report1 / "PROGRESS.json").read_text(encoding="utf8"))
    if progress["first_pass_candidates_output"] != 128 or progress["correction_output"] != 6:
        raise RuntimeError("R1 progress changed")
    now = dt.datetime.now(dt.timezone.utc)
    stamp = now.isoformat(timespec="microseconds").replace("+00:00", "Z")
    deadline = min(now + dt.timedelta(minutes=40), dt.datetime.fromisoformat(r1["budget_deadline_utc"]))
    deadline_iso = deadline.isoformat()
    r1_sha = hashlib.sha256(r1_raw).hexdigest()
    meta = {**r1,
            "revision": 2, "assignee": ASSIGNEE, "agent_id": ASSIGNEE,
            "report_folder": "RULES/REPORT/TASK_187_REPORT_R2",
            "files_allowed": ["RULES/REPORT/TASK_187_REPORT_R2/**",
                              "scripts/task_187_codex_continuation_r2/**",
                              "RESEARCH_WORK/TASK_187_R2/**"],
            "expected_lease_id": "LEASE-CEO-WORKER-TASK_187-R2",
            "max_minutes": 40, "created_at": stamp, "budget_deadline_utc": deadline_iso,
            "continuation_of": {"revision": 1, "task_sha256": r1_sha,
                                 "task_archive": ARCHIVE.relative_to(ROOT).as_posix(),
                                 "reason": "Original Codex worker hit usage limit before sealing; R1 evidence remains unsealed and immutable"}}
    body = f"""# TASK_187 R2 - seal interrupted MTFilterKernel static candidate batch

STATUS: ACTIVE
ASSIGNEE: {ASSIGNEE}
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

The R1 Codex worker hit a usage limit after producing 128 first-pass Ghidra records, six transient full-FDE metadata corrections and original source assembly. R1 has no `COMPLETE.json` and remains **unsealed**. Preserve all R1 files byte-for-byte. Do not impersonate the original worker or use its R1 fencing token. This R2 authorizes only independent verification and sealing of the exact 128 source-pinned `libMTFilterKernel.so` FDE candidates in `{meta['target_manifest_path']}` (manifest SHA-256 `{meta['target_manifest_sha256']}`, source ELF SHA-256 `{meta['source_libraries']['libMTFilterKernel.so']['sha256']}`).

Read R1 `source_project_index.json`, all 128 first-pass candidate JSON records, six correction JSON records, original source assembly, copied-project hashes, all three raw command/log pairs and the original `scripts/task_187_codex_internal/verify_and_seal.py` **read-only**. Verify every original ELF/FDE/PT_LOAD body and SHA, exact candidate ordering/nonexport criterion, 128 Ghidra memory and C-like hashes, full function-body byte membership, 122 original full-FDE rows and six transient corrected rows, and >=10% spread ordinary instruction slots against original bytes independently. Verify no surviving task-owned Ghidra process and no fresh import is needed; do not relaunch Ghidra. The six transient corrections are source-backed static metadata, not proof of exact source semantics. Preserve any failure or discrepancy and seal a truthful bounded PARTIAL if needed.

Before any write, fully re-read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `{STANDARD_SHA}`. Read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact R2 task, target manifest, config/state/locks/END flag and git status. Claim exact ACTIVE TASK_187 revision 2 as `{ASSIGNEE}`, expected lease `{meta['expected_lease_id']}`, before any write. Only write `{meta['report_folder']}/**`, `scripts/task_187_codex_continuation_r2/**`, and `RESEARCH_WORK/TASK_187_R2/**`; R1 and original SO are read-only. Produce 00_AUDIT_INDEX.md canonical read receipt, 01_MASTER_REPORT.md, a SHA-256 inventory of all referenced R1 raw/code/project evidence, independent verification output including sample addresses, PROGRESS and sealed COMPLETE.json with complete R2 file manifest. No AGY, product/P0 edits, self-review, Phase PASS, V4/P7 or all-45-SO claim. Do not commit/push until CEO independent review. Stop by {deadline_iso}.
"""
    raw = body.encode("utf8")
    with ctl.transaction() as (registry, state):
        ceo = ctl.ceo_lease(registry)
        for path in (TASK, ARCHIVE, ROOT / ".ai/locks.json"):
            ctl.authorized(ceo, path)
        if file_sha(TASK) != r1_sha or (report1 / "COMPLETE.json").exists():
            raise RuntimeError("R1 changed before handoff")
        update = copy.deepcopy(registry)
        for task_id in ("TASK_187", "TASK_186"):
            lease_id = f"LEASE-CEO-WORKER-{task_id}-R1"
            matches = [x for x in update["active_locks"] if x["lease_id"] == lease_id]
            if len(matches) != 1 or matches[0]["status"] != "ACTIVE":
                raise RuntimeError("worker lease not uniquely active: " + lease_id)
            matches[0].update(status="REVOKED", closed_at=stamp,
                              close_reason="R1 worker finished or unavailable; bounded R2 handoff")
            claim = state["claims"].get(f"{task_id}:r1")
            if not claim:
                raise RuntimeError("missing worker claim: " + task_id)
            claim.update(status="REVOKED", expiry=now.timestamp(), closed_at=stamp)
        update["revision"] = registry["revision"] + 1
        update["updated_at"] = stamp
        ctl.replace_json(ctl.registry, update, registry)
        registry.clear()
        registry.update(update)
        atomic_file(ARCHIVE, r1_raw)
        atomic_file(TASK, raw)
        ctl.event(state, "CODEX_TASK187_R2_INTERRUPTED_WORKER_HANDOFF",
                  task_id="TASK_187", assignee=ASSIGNEE,
                  original_task_sha256=r1_sha, task_sha256=hashlib.sha256(raw).hexdigest(),
                  deadline=deadline_iso, r1_unsealed=True)
    print(json.dumps({"task": "TASK_187", "revision": 2, "assignee": ASSIGNEE,
                      "task_sha256": file_sha(TASK), "r1_archive_sha256": file_sha(ARCHIVE),
                      "deadline": deadline_iso}))


if __name__ == "__main__":
    main()
