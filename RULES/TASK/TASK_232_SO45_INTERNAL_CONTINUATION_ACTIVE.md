# TASK_232 R1 - bounded libAIModelSearchKit.so oversized continuation

STATUS: ACTIVE
ASSIGNEE: /root/audit_157_158
PRIORITY: P1
MODIFIED_TIME: 2026-10-15T09:52:50.852817+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_232",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/audit_157_158",
  "agent_id": "/root/audit_157_158",
  "priority": "P1",
  "mode": "RESEARCH",
  "dependencies": [
    {
      "task_id": "TASK_229",
      "revision": 1
    }
  ],
  "report_folder": "RULES/REPORT/TASK_232_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_232_REPORT_R1/**",
    "scripts/task_232_codex_internal/**",
    "RESEARCH_WORK/TASK_232_R1/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_232-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libAIModelSearchKit.so": {
      "sha256": "20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899"
    }
  },
  "target_candidate_count": 2,
  "authorization_reference": "Chairman Tony direct SO45 decoding continuation without AGY; bounded research only",
  "created_at": "2026-10-15T09:52:50.852817+00:00",
  "modified_time": "2026-10-15T09:52:50.852817+00:00",
  "budget_deadline_utc": "2026-10-15T11:52:50.852817+00:00",
  "target_manifest_path": ".ai/ceo/reviews/TASK_232_internal_targets.json",
  "target_manifest_sha256": "b2236ab21269d92f45ca50c631a45e9d33a818a1c0bf7c93a40bae82bb6e273e"
}
```

Research only exact manifest targets (2 selected from indices 493..549). Reverify original ELF/PT_LOAD/FDE body bytes and every ARM64 word. Use a private bounded Ghidra project (one CPU, 1 GiB heap, <=15 seconds per decompile). Capture exact membership, listing/p-code, raw C-like or failure, command/log/project hashes, and independently recheck >=10% spread ordinary provenance. These oversized FDE candidates were deliberately deferred by prior <=4096-byte ordinary batches. Analyze each with bounded per-function memory/time, splitting read-only batches or sealing a truthful failure when a bound is hit. Do not omit a target silently or call an incomplete C-like body complete. C-like output is static research, not source or behavioral proof. Seal PARTIAL if any target or boundary remains unresolved.

Before any write fully read canonical Standard at F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt (SHA-256 10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f), AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task/manifest and config/state/locks/END. Claim exact ACTIVE TASK_232 R1 as /root/audit_157_158 using LEASE-CEO-WORKER-TASK_232-R1 before writing. Write only files_allowed; original SO and prior reports are read-only. Report canonical path and SHA in 00_AUDIT_INDEX.md. No AGY, child agents, self-review, commit/push before CEO review. P0/product/V4/P7 remain frozen. Stop at absolute task deadline.
