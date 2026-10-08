# TASK_066 ? V4 readiness, architecture contract and implementation backlog
STATUS: PLANNED
ASSIGNEE: AGY_TEAM
PRIORITY: HIGH
MODIFIED_TIME: 2026-10-08T03:46:59.445217+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_066",
  "revision": 1,
  "status": "PLANNED",
  "assignee": "AGY_TEAM",
  "priority": "HIGH",
  "mode": "RESEARCH",
  "design_impact": "NONE",
  "dependencies": [
    {
      "task_id": "TASK_065",
      "revision": 1
    }
  ],
  "report_folder": "RULES/REPORT/TASK_066_REPORT",
  "files_allowed": [
    "scripts/task066/**",
    ".ai/reconstruction/evidence/TASK_066/**",
    "RULES/REPORT/TASK_066_REPORT/**"
  ],
  "files_forbidden": [
    "app/**",
    "lib-*/**",
    "RULES/TASK/**",
    ".ai/state.json",
    "AGENTS.md"
  ],
  "max_fix_cycles": 3
}
```

PLANNED: do not execute until CEO activates exact revision with accepted dependencies.

At EVERY dispatch/worker/resume read IN FULL `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; expected SHA-256 `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`. Read canonical rules/errors/knowledge and .ai/ceo/SO45_TO_V4_PLAN.md. Record actual read receipt/path/hash/worker/lease in 00_AUDIT_INDEX.md; claim valid lease through controller; no production/P0 changes.

Objective: Independently evaluate SO45 research closure and V4 prerequisites. Map each intended V4 behavior to observed algorithm/contract/evidence, required models/resources, fit to frozen P0 adapter, performance budget and test/device acceptance. Carry TASK_062 NEEDS_FIX and missing libmtImageKit/input blockers honestly; RESEARCH_COMPLETE cannot override product acceptance. Produce READY/BLOCKED per capability and concrete scoped implementation/correction tasks for CEO to activate, with measurable acceptance and no speculative percentages. Overall V4 gate stays BLOCKED until critical evidence, architecture/contracts and unresolved product acceptance are addressed; this task authorizes readiness research only.

Deliver final audited-evidence index, algorithm/interface or readiness spec, reproducible independent checks and raw command logs, per-library/capability unknown/blocker ledger, concrete next task requirements, 00_AUDIT_INDEX.md/01_MASTER_REPORT.md, truthful milestone PROGRESS.json and COMPLETE.json frozen hash mapping + code_files. No invented formulas/defaults/file names/coverage. CEO reviews all critical claims and >=10% routine cited paths, verifies code/output/manifests/approval before owned-branch commit/push. REVIEW_CANDIDATE_AWAITING_CEO is the only worker completion disposition. Return to scanner afterwards; V4 production requires a later explicit ACTIVE implementation task.
