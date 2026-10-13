# TASK_162 R2 - report manifest correction only

STATUS: ACTIVE
ASSIGNEE: /root/so45_dexvmp_correction
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T07:09:18.205185Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_162",
  "revision": 2,
  "status": "ACTIVE",
  "assignee": "/root/so45_dexvmp_correction",
  "agent_id": "/root/so45_dexvmp_correction",
  "priority": "P1",
  "dependencies": [],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_162_REPORT_R2",
  "files_allowed": [
    "RULES/REPORT/TASK_162_REPORT_R2/**"
  ],
  "files_forbidden": [
    "RULES/TASK/**",
    "SOURCE/**",
    ".ai/**",
    "app/**",
    "apps/**",
    "lib-*/**",
    "Backend/**",
    "services/**",
    "packages/**",
    "RULES/REPORT/TASK_162_REPORT_R1/**",
    "scripts/task_162_codex_exports/**",
    "RESEARCH_WORK/TASK_162_R1/**"
  ],
  "max_minutes": 120,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 4194304,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_162-R2",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libhiai_ir.so": {
      "sha256": "c96af03947bde73255f4b77e3c253ae63130fdfed8b259196d24bbf3ba84a7d1",
      "expected_unique_export_vas": 1002
    },
    "libkoom-strip-dump.so": {
      "sha256": "db0db1bdef5f51386ea2036682c0129b842aa5e3445a26d60ea6c5d29113faa3",
      "expected_unique_export_vas": 668
    }
  },
  "authorization_reference": "Chairman direct Codex multi-lane continuation; CEO R1 diagnostic manifest correction only",
  "created_at": "2026-10-13T07:09:18.205185Z",
  "budget_deadline_utc": "2026-10-13T08:40:36.662647+00:00",
  "prior_task_sha256": "22e38e8081d202d558704a99fb1d5cc6ea9e30a1a8267f44467ab15320e52942",
  "prior_seal_sha256": "eecb9f3bcb4e1d14449ab4416b3cb597a55b53cc75cc30c8593f765b24ab2d18",
  "prior_review_fingerprint": "e8a76d0e023915577fe217c714f1017c20d7ad15598491946ace637e1e445ba8"
}
```

R1 raw research is independently checked but has a controller-invalid final manifest. Preserve every R1 report and generator code byte. Rehash and reference all 87 R1 report files, the R1 seal, the archived exact R1 task, and all five R1 generator code files. Publish only a compact R2 report in the private R2 scope, including 00_AUDIT_INDEX.md, 01_MASTER_REPORT.md, provenance receipt, and COMPLETE.json with schema_version 2.1.2, task_id TASK_162, revision 2, status COMPLETE, canonical standard SHA, exact files map for every nonvolatile R2 report file, and code_files map/list of frozen R1 generators. Use the original absolute deadline above. No new Ghidra import, decompilation, source edit, product work, budget increase, clock reset or report rewrite in R1. Preserve the 87 partial listings and 704 warning-bearing C-like bodies as explicit limits. Research text does not prove behavior, all internal functions, Phase PASS or V4 readiness.

Before any write, fully read F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt and verify SHA-256 10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f; read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task, config/state, locks, END flag and git status. Claim exact ACTIVE revision 2 as the assigned agent under expected lease; write only files_allowed, AGY reports go RULES/REPORT and CEO writes task here. No self-review or commit/push before independent CEO review; no AGY or further subagents.
