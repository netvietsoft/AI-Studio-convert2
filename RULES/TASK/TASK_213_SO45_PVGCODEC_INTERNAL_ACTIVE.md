# TASK_213 R1 - bounded libPVGCodec.so continuation

STATUS: ACTIVE
ASSIGNEE: /root/audit_210
PRIORITY: P1
MODIFIED_TIME: 2026-10-15T08:24:41.697319+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_213",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/audit_210",
  "agent_id": "/root/audit_210",
  "priority": "P1",
  "mode": "RESEARCH",
  "dependencies": [
    {
      "task_id": "TASK_158",
      "revision": 1
    }
  ],
  "report_folder": "RULES/REPORT/TASK_213_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_213_REPORT_R1/**",
    "scripts/task_213_codex_internal/**",
    "RESEARCH_WORK/TASK_213_R1/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_213-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGCodec.so": {
      "sha256": "4fa5f275c8ddecf7caa960c812108ec9e801365bfe5bc9cf38598233bc449ffc"
    }
  },
  "target_candidate_count": 128,
  "authorization_reference": "Chairman Tony direct instruction to finish remaining SO45 decoding without AGY; bounded research only",
  "created_at": "2026-10-15T08:24:41.697319+00:00",
  "modified_time": "2026-10-15T08:24:41.697319+00:00",
  "budget_deadline_utc": "2026-10-15T10:24:41.697319+00:00",
  "target_manifest_path": ".ai/ceo/reviews/TASK_213_internal_targets.json",
  "target_manifest_sha256": "df5b6894af660954be508cfea9aa15c9066abc54bb12f43119c0a2b149c55263"
}
```

Research only the exact 128 selected nonexport FDE candidates in the pinned CEO manifest. Independently reverify original ELF/PT_LOAD/FDE bytes and ARM64 instruction slots. Use a private bounded Ghidra headless project (one CPU, 1 GiB heap, <=15 seconds per decompile), capture full body membership, listing/p-code coverage, raw C-like or failure and logs/project hashes; recheck >=10% spread provenance. Do not infer source-function boundaries or semantics from FDEs. Seal a truthful PARTIAL research report if any target remains unresolved.

Before any write fully read the canonical Standard SHA-256 10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f, AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task and manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_213 R1 as /root/audit_210 via LEASE-CEO-WORKER-TASK_213-R1 before writing. Write only files_allowed; source, prior reports, P0 and product are read-only. Report canonical path and SHA in 00_AUDIT_INDEX.md. No AGY, child agents, self-review, commit or push before independent CEO review. Stop at the absolute deadline.
