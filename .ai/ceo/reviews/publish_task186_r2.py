"""Publish a disjoint report-only TASK_186 correction after R1 NEEDS_FIX."""
import datetime as dt
import hashlib
import json
import os
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / ".ai/ceo"))
from controller import Controller, file_sha  # noqa: E402

TASK = ROOT / "RULES/TASK/TASK_186_SO45_CODEX_INTERNAL_ACTIVE.md"
ARCHIVE = ROOT / ".ai/ceo/reviews/TASK_186_R1_TASK_SNAPSHOT.md"
REVIEW = ROOT / ".ai/ceo/reviews/TASK_186-183e5c90186b686653e445b13f6fc090afbf0d08f07644e2b5be40718f899a22.md"
FINGERPRINT = "183e5c90186b686653e445b13f6fc090afbf0d08f07644e2b5be40718f899a22"
ASSIGNEE = "/root/so45_dexvmp_correction"
STANDARD_SHA = "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f"


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
    old_raw = TASK.read_bytes()
    old_meta = json.loads(old_raw.decode("utf8").split("```json\n", 1)[1].split("\n```", 1)[0])
    if old_meta["task_id"] != "TASK_186" or old_meta["revision"] != 1 or ARCHIVE.exists():
        raise RuntimeError("R1 task not current")
    seal_path = ROOT / "RULES/REPORT/TASK_186_REPORT_R1/COMPLETE.json"
    seal = json.loads(seal_path.read_text(encoding="utf8"))
    if seal["task_sha256"] != hashlib.sha256(old_raw).hexdigest() or seal["status"] != "COMPLETE":
        raise RuntimeError("R1 seal does not bind task")
    now = dt.datetime.now(dt.timezone.utc)
    stamp = now.isoformat(timespec="microseconds").replace("+00:00", "Z")
    deadline = min(now + dt.timedelta(minutes=35), dt.datetime.fromisoformat(old_meta["budget_deadline_utc"]))
    meta = {**old_meta,
            "revision": 2, "assignee": ASSIGNEE, "agent_id": ASSIGNEE,
            "report_folder": "RULES/REPORT/TASK_186_REPORT_R2",
            "files_allowed": ["RULES/REPORT/TASK_186_REPORT_R2/**",
                              "scripts/task_186_codex_correction_r2/**",
                              "RESEARCH_WORK/TASK_186_R2/**"],
            "expected_lease_id": "LEASE-CEO-WORKER-TASK_186-R2",
            "max_minutes": 35, "created_at": stamp, "budget_deadline_utc": deadline.isoformat(),
            "correction_of": {"revision": 1, "fingerprint": FINGERPRINT,
                              "review_file": REVIEW.relative_to(ROOT).as_posix(),
                              "r1_task_sha256": hashlib.sha256(old_raw).hexdigest(),
                              "r1_task_archive": ARCHIVE.relative_to(ROOT).as_posix(),
                              "r1_seal_sha256": file_sha(seal_path)}}
    body = f"""# TASK_186 R2 - correct PVGColorFunctions verification and boundary report

STATUS: ACTIVE
ASSIGNEE: {ASSIGNEE}
PRIORITY: P1
MODIFIED_TIME: {stamp}

```json
{json.dumps(meta, ensure_ascii=False, indent=2)}
```

This is the exact report-only correction of R1 fingerprint `{FINGERPRINT}` and CEO NEEDS_FIX review `{REVIEW.relative_to(ROOT).as_posix()}`. Preserve all R1 report, raw logs, code and copied Ghidra project byte-for-byte. The 128 pinned `libPVGColorFunctions.so` nonexport FDE candidates at sorted indices 128..255 remain the entire scope. Original source SHA-256 `{meta['source_libraries']['libPVGColorFunctions.so']['sha256']}`, manifest SHA-256 `{meta['target_manifest_sha256']}`.

Independently recheck all 128 original FDE/PT_LOAD body hashes, Ghidra raw memory hashes, C-like hashes and every-byte body-membership accounting. The R1 raw rows and candidate index classify **128/128 exact FDE-body matches**, zero missing and zero extra bytes. Correct the R1 master-report sentence that calls these C-like outputs boundary-limited; retain the caveat that an FDE is only a candidate range and does not prove complete unique source semantics. R1's worker verification sampled only 36/790 instruction slots. R2 must decode and record **at least 79 distinct spread ordinary instruction slots** against original source bytes, source assembly and Ghidra listing, with exact VA/word/mnemonic evidence and a deterministic selection rule. A fresh read-only Ghidra replay is optional only if necessary; no new import, no semantic overclaim. Keep the failed serializer attempt and corrected retry clearly labeled through immutable R1 references and SHA-256 inventory. Seal only a truthful corrected R2 report.

Before any write, fully re-read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `{STANDARD_SHA}`. Read AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact R2 task, source manifest, config/state/locks/END and git status. Claim TASK_186 revision 2 as `{ASSIGNEE}` using lease `LEASE-CEO-WORKER-TASK_186-R2` before any write. Only write `{meta['report_folder']}/**`, `scripts/task_186_codex_correction_r2/**`, `RESEARCH_WORK/TASK_186_R2/**`. R1 and source SO are read-only. Create 00_AUDIT_INDEX.md canonical read receipt, 01_MASTER_REPORT.md, R1 reference inventory, independent instruction evidence, PROGRESS and sealed COMPLETE.json with all R2 hashes. No AGY, P0/product edits, self-review, commit/push, behavior/pixel parity, product Phase PASS, V4/P7 or all-45-SO claim. Stop by {deadline.isoformat()}.
"""
    raw = body.encode("utf8")
    with ctl.transaction() as (registry, state):
        ceo = ctl.ceo_lease(registry)
        for path in (TASK, ARCHIVE, REVIEW):
            ctl.authorized(ceo, path)
        verdict = state["tasks"]["TASK_186"]["verdict"]
        if (verdict["disposition"] != "NEEDS_FIX" or verdict["revision"] != 1 or
                verdict["fingerprint"] != FINGERPRINT or file_sha(REVIEW) != verdict["review_sha256"]):
            raise RuntimeError("R1 rejection changed")
        if file_sha(TASK) != hashlib.sha256(old_raw).hexdigest():
            raise RuntimeError("R1 task changed")
        atomic_file(ARCHIVE, old_raw)
        atomic_file(TASK, raw)
        ctl.event(state, "CODEX_TASK186_R2_CORRECTION_PUBLISHED", task_id="TASK_186",
                  assignee=ASSIGNEE, prior_fingerprint=FINGERPRINT,
                  task_sha256=hashlib.sha256(raw).hexdigest(), deadline=deadline.isoformat())
    print(json.dumps({"task": "TASK_186", "revision": 2, "assignee": ASSIGNEE,
                      "task_sha256": file_sha(TASK), "r1_archive_sha256": file_sha(ARCHIVE),
                      "deadline": deadline.isoformat()}))


if __name__ == "__main__":
    main()
