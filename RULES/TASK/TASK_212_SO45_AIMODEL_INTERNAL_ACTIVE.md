# TASK_212 R1 - bounded libAIModelSearchKit.so continuation

STATUS: ACTIVE
ASSIGNEE: /root/audit_157_158
PRIORITY: P1
MODIFIED_TIME: 2026-10-15T08:24:41.697319+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_212",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/audit_157_158",
  "agent_id": "/root/audit_157_158",
  "priority": "P1",
  "mode": "RESEARCH",
  "dependencies": [
    {
      "task_id": "TASK_157",
      "revision": 1
    }
  ],
  "report_folder": "RULES/REPORT/TASK_212_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_212_REPORT_R1/**",
    "scripts/task_212_codex_internal/**",
    "RESEARCH_WORK/TASK_212_R1/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_212-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libAIModelSearchKit.so": {
      "sha256": "20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899"
    }
  },
  "target_candidate_count": 128,
  "authorization_reference": "Chairman Tony direct instruction to finish remaining SO45 decoding without AGY; bounded research only",
  "created_at": "2026-10-15T08:24:41.697319+00:00",
  "modified_time": "2026-10-15T08:24:41.697319+00:00",
  "budget_deadline_utc": "2026-10-15T10:24:41.697319+00:00",
  "target_manifest_path": ".ai/ceo/reviews/TASK_212_internal_targets.json",
  "target_manifest_sha256": "971241cda90e9e8fe13f09e92f83c460bf3349a14a5de33e9f4cfc439e8b4759"
}
```

Research only the exact 128 selected nonexport FDE candidates in the pinned CEO manifest. Independently reverify original ELF/PT_LOAD/FDE bytes and ARM64 instruction slots. Use a private bounded Ghidra headless project (one CPU, 1 GiB heap, <=15 seconds per decompile), capture full body membership, listing/p-code coverage, raw C-like or failure and logs/project hashes; recheck >=10% spread provenance. Do not infer source-function boundaries or semantics from FDEs. Seal a truthful PARTIAL research report if any target remains unresolved.

Before any write fully read the canonical Standard SHA-256 10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f, AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task and manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_212 R1 as /root/audit_157_158 via LEASE-CEO-WORKER-TASK_212-R1 before writing. Write only files_allowed; source, prior reports, P0 and product are read-only. Report canonical path and SHA in 00_AUDIT_INDEX.md. No AGY, child agents, self-review, commit or push before independent CEO review. Stop at the absolute deadline.
