# TASK_221 R1 - bounded libPVGCodec.so continuation

STATUS: ACTIVE
ASSIGNEE: /root/audit_210
PRIORITY: P1
MODIFIED_TIME: 2026-10-15T09:08:46.455275+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_221",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/audit_210",
  "agent_id": "/root/audit_210",
  "priority": "P1",
  "mode": "RESEARCH",
  "dependencies": [
    {
      "task_id": "TASK_218",
      "revision": 1
    }
  ],
  "report_folder": "RULES/REPORT/TASK_221_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_221_REPORT_R1/**",
    "scripts/task_221_codex_internal/**",
    "RESEARCH_WORK/TASK_221_R1/**"
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
    "packages/**"
  ],
  "max_minutes": 120,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_per_decompile_seconds": 15,
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_221-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGCodec.so": {
      "sha256": "4fa5f275c8ddecf7caa960c812108ec9e801365bfe5bc9cf38598233bc449ffc"
    }
  },
  "target_candidate_count": 128,
  "authorization_reference": "Chairman Tony direct instruction to finish SO45 decoding without AGY; bounded research only",
  "created_at": "2026-10-15T09:08:46.455275+00:00",
  "modified_time": "2026-10-15T09:08:46.455275+00:00",
  "budget_deadline_utc": "2026-10-15T11:08:46.455275+00:00",
  "target_manifest_path": ".ai/ceo/reviews/TASK_221_internal_targets.json",
  "target_manifest_sha256": "8fac01f60612baf7acd105674ec5e31dcbfc9af50adc4c533611b3766c69c962"
}
```

Research only the exact 128 previously unselected nonexport FDE candidates in the CEO manifest after prior global index 390. Reverify original ELF/PT_LOAD/FDE bytes and all ARM64 slots. Use a private bounded Ghidra project (one CPU, 1 GiB heap, <=15 seconds per decompile). Capture byte membership, listing/p-code, raw C-like or failure, logs and unchanged project hashes. Independently recheck >=10% spread ordinary provenance. Keep all skipped oversized candidates explicitly pending. A C-like output is static research, not exact source or behavior proof. Seal truthful PARTIAL results if any target is unresolved.

Before any write fully read the canonical Standard at F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt (SHA-256 10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f), AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task and manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_221 R1 as /root/audit_210 via LEASE-CEO-WORKER-TASK_221-R1 before writing. Write only files_allowed; prior reports and source are read-only. Report canonical path and SHA in 00_AUDIT_INDEX.md. No AGY, child agents, self-review, commit or push before independent CEO review. Stop at absolute deadline.
