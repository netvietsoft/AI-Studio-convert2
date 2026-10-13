"""Issue a report-only corrective R2 after the exact R1 NEEDS_FIX review."""
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

TASK = ROOT / "RULES/TASK/TASK_184_SO45_CODEX_INTERNAL_ACTIVE.md"
ARCHIVE = ROOT / ".ai/ceo/reviews/TASK_184_R1_TASK_SNAPSHOT.md"
REVIEW = ROOT / ".ai/ceo/reviews/TASK_184-59b10f33044972ea28b2442f8f5bbf4033401675b14ee2cc6d89e88f2527be43.md"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"
R1_SHA = "1fbab2b3072b94c02d7684246d5c5280ab6fbc560b4a5c8cf98d062a2e808042"
FINGERPRINT = "59b10f33044972ea28b2442f8f5bbf4033401675b14ee2cc6d89e88f2527be43"


def atomic_file(path, raw):
    temp = path.with_name(path.name + ".tmp")
    with temp.open("xb") as stream:
        stream.write(raw)
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temp, path)


def main():
    ctl = Controller(ROOT)
    if ctl.end_requested() or file_sha(ROOT / "Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt") != STANDARD_SHA:
        raise RuntimeError("END requested or canonical standard changed")
    if file_sha(TASK) != R1_SHA or ARCHIVE.exists():
        raise RuntimeError("R1 task changed or already archived")
    old_raw = TASK.read_bytes()
    old_text = old_raw.decode("utf-8")
    old_meta = json.loads(old_text.split("```json\n", 1)[1].split("\n```", 1)[0])
    now = dt.datetime.now(dt.timezone.utc)
    stamp = now.isoformat(timespec="microseconds").replace("+00:00", "Z")
    deadline = (now + dt.timedelta(minutes=45)).isoformat()
    new_meta = {**old_meta,
                "revision": 2,
                "status": "ACTIVE",
                "report_folder": "RULES/REPORT/TASK_184_REPORT_R2",
                "files_allowed": ["RULES/REPORT/TASK_184_REPORT_R2/**",
                                  "scripts/task_184_codex_correction_r2/**",
                                  "RESEARCH_WORK/TASK_184_R2/**"],
                "expected_lease_id": "LEASE-CEO-WORKER-TASK_184-R2",
                "max_minutes": 45,
                "budget_deadline_utc": deadline,
                "created_at": stamp,
                "correction_of": {"revision": 1, "fingerprint": FINGERPRINT,
                                  "review_file": REVIEW.relative_to(ROOT).as_posix(),
                                  "original_task_sha256": R1_SHA,
                                  "original_task_archive": ARCHIVE.relative_to(ROOT).as_posix()},
                }
    body = f"""# TASK_184 R2 - correct VERenderer body coverage classification

STATUS: ACTIVE
ASSIGNEE: /root/so45_dexvmp_correction
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(new_meta, ensure_ascii=False, indent=2)}
```

This is the exact report-only correction of R1 fingerprint `{FINGERPRINT}` after CEO NEEDS_FIX review `{REVIEW.relative_to(ROOT).as_posix()}`. Preserve all R1 files byte-for-byte. The 141 source-pinned rows in `.ai/ceo/reviews/TASK_184_internal_targets.json` and their raw C-like outputs remain useful static evidence; do not redo unrelated SOs or claim behavior.

Independent CEO Ghidra body-membership evidence in `.ai/ceo/reviews/TASK_184_CEO_REPLAY/body_ranges.ndjson` found 135 exact and six nonexact Ghidra function bodies, indices 8,14,17,46,95,96. Index 96, ELF VA `0x5d6e4`, has full FDE size 436 but Ghidra function body only 392 address bytes despite matching min/max endpoints. Recheck this directly on a byte-verified owned Ghidra-project copy, enumerate the 11 missing AArch64 instruction addresses and hashes, and correct the extractor to compare complete body membership, not just endpoints. Explicitly classify candidate 96's existing C-like as boundary-limited; correct all coverage totals, report statements and any output indexes that imply 136 exact / five ambiguous. If fresh read-only extraction is necessary, stay within one CPU, 1 GiB and 10s decompile per candidate. Do not edit the R1 report, source SO, P0 or product code.

Before any write, fully re-read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `{STANDARD_SHA}`. Read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact R2 task, target manifest, config/state, locks, END flag and git status. Claim TASK_184 revision 2 using `/root/so45_dexvmp_correction`, expected lease `LEASE-CEO-WORKER-TASK_184-R2`, before any write. Only write the R2 files_allowed. Put 00_AUDIT_INDEX.md, 01_MASTER_REPORT.md, raw command/log/body-membership evidence, PROGRESS, independently checked source/body and >=10% ordinary provenance, and sealed COMPLETE.json with a complete SHA-256 manifest in `RULES/REPORT/TASK_184_REPORT_R2`. State exact limitations, no behavior/pixel parity, Phase PASS, V4/P7 or all-45-SO claim. Stop by the absolute deadline and await independent CEO review; no commit/push or AGY.
"""
    raw = body.encode("utf-8")
    with ctl.transaction() as (registry, state):
        ceo = ctl.ceo_lease(registry)
        for path in (TASK, ARCHIVE, REVIEW, ROOT / ".ai/locks.json"):
            ctl.authorized(ceo, path)
        verdict = state["tasks"]["TASK_184"]["verdict"]
        if verdict["disposition"] != "NEEDS_FIX" or verdict["revision"] != 1 or verdict["fingerprint"] != FINGERPRINT:
            raise RuntimeError("R1 rejection changed")
        if file_sha(REVIEW) != verdict["review_sha256"]:
            raise RuntimeError("R1 review changed")
        update = copy.deepcopy(registry)
        for number in (183, 184, 185):
            lease_id = f"LEASE-CEO-WORKER-TASK_{number}-R1"
            matches = [x for x in update["active_locks"] if x["lease_id"] == lease_id]
            if len(matches) != 1 or matches[0]["status"] != "ACTIVE":
                raise RuntimeError("R1 worker lease not uniquely active: " + lease_id)
            matches[0].update(status="REVOKED", closed_at=stamp,
                              close_reason="R1 independently reviewed; correction or next disjoint lane")
            key = f"TASK_{number}:r1"
            if key not in state["claims"]:
                raise RuntimeError("missing worker claim: " + key)
            state["claims"][key].update(status="REVOKED", expiry=now.timestamp(), closed_at=stamp)
        update["revision"] = registry["revision"] + 1
        update["updated_at"] = stamp
        ctl.replace_json(ctl.registry, update, registry)
        registry.clear()
        registry.update(update)
        atomic_file(ARCHIVE, old_raw)
        atomic_file(TASK, raw)
        ctl.event(state, "CODEX_TASK184_R2_CORRECTION_PUBLISHED", task_id="TASK_184",
                  assignee=new_meta["assignee"], prior_fingerprint=FINGERPRINT,
                  task_sha256=hashlib.sha256(raw).hexdigest(), budget_deadline_utc=deadline)
    print(json.dumps({"task": "TASK_184", "revision": 2,
                      "task_sha256": file_sha(TASK), "r1_archive_sha256": file_sha(ARCHIVE),
                      "assignee": new_meta["assignee"], "report_folder": new_meta["report_folder"],
                      "deadline": deadline}))


if __name__ == "__main__":
    main()
