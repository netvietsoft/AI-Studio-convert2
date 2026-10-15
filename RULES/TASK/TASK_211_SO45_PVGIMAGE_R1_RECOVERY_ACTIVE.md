# TASK_211 R1 - bounded libPVGImageCodec.so continuation

STATUS: ACTIVE
ASSIGNEE: /root/audit_208
PRIORITY: P1
MODIFIED_TIME: 2026-10-15T08:24:41.697319+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_211",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/audit_208",
  "agent_id": "/root/audit_208",
  "priority": "P1",
  "mode": "RESEARCH",
  "dependencies": [
    {
      "task_id": "TASK_205",
      "revision": 2
    }
  ],
  "report_folder": "RULES/REPORT/TASK_211_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_211_REPORT_R1/**",
    "scripts/task_211_codex_internal/**",
    "RESEARCH_WORK/TASK_211_R1/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_211-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGImageCodec.so": {
      "sha256": "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b"
    }
  },
  "target_candidate_count": 126,
  "authorization_reference": "Chairman Tony direct instruction to finish remaining SO45 decoding without AGY; bounded research only",
  "created_at": "2026-10-15T08:24:41.697319+00:00",
  "modified_time": "2026-10-15T08:24:41.697319+00:00",
  "budget_deadline_utc": "2026-10-15T10:24:41.697319+00:00",
  "target_manifest_path": ".ai/ceo/reviews/TASK_208_internal_targets.json",
  "target_manifest_sha256": "db877766e2100738fdeab4f388ca67760b31702a9c92e5a237358a0d556a7dbc"
}
```

Fresh bounded recovery of expired, unsealed TASK_208 R1 evidence; TASK_208 files are read-only. Rehash its exact 126 pinned source bodies, 18,502 ARM64 words, Ghidra raw outputs, logs and project; independently recheck >=10% spread ordinary provenance. Investigate/retry only index 465 within budget. Classify the 125 C-like outputs and any unresolved failure truthfully, including FDE boundary limits and exclusions 450/499. Produce a new standalone 00_AUDIT_INDEX.md, 01_MASTER_REPORT.md, per-candidate evidence and SHA-256 sealed COMPLETE.json in TASK_211_REPORT_R1. Do not mutate or seal TASK_208 R1 retroactively. Verify fresh-session rollback if any Ghidra metadata is changed.

Before any write fully read the canonical Standard SHA-256 10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f, AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task and manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_211 R1 as /root/audit_208 via LEASE-CEO-WORKER-TASK_211-R1 before writing. Write only files_allowed; source, prior reports, P0 and product are read-only. Report canonical path and SHA in 00_AUDIT_INDEX.md. No AGY, child agents, self-review, commit or push before independent CEO review. Stop at the absolute deadline.
