# TASK_248 R1 - bounded libPVGCodec.so oversized continuation

STATUS: ACTIVE
ASSIGNEE: /root/audit_157_158
PRIORITY: P1
MODIFIED_TIME: 2026-10-15T23:43:21.143094+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_248",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/audit_157_158",
  "agent_id": "/root/audit_157_158",
  "priority": "P1",
  "mode": "RESEARCH",
  "dependencies": [
    {
      "task_id": "TASK_233",
      "revision": 1
    }
  ],
  "report_folder": "RULES/REPORT/TASK_248_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_248_REPORT_R1/**",
    "scripts/task_248_codex_internal/**",
    "RESEARCH_WORK/TASK_248_R1/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_248-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGCodec.so": {
      "sha256": "4fa5f275c8ddecf7caa960c812108ec9e801365bfe5bc9cf38598233bc449ffc"
    }
  },
  "target_candidate_count": 1,
  "authorization_reference": "Chairman Tony direct SO45 decoding continuation without AGY; bounded research only",
  "created_at": "2026-10-15T23:43:21.143094+00:00",
  "modified_time": "2026-10-15T23:43:21.143094+00:00",
  "budget_deadline_utc": "2026-10-16T01:43:21.143094+00:00",
  "target_manifest_path": ".ai/ceo/reviews/TASK_248_internal_targets.json",
  "target_manifest_sha256": "f82ab134d8431e825622e31574324679eff9045b1b2660acd87961670a7ab7ee"
}
```

Research only exact manifest targets (1 selected from indices 253..253). Reverify original ELF/PT_LOAD/FDE body bytes and every ARM64 word. Use a private bounded Ghidra project (one CPU, 1 GiB heap, <=15 seconds per decompile). Capture exact membership, listing/p-code, raw C-like or failure, command/log/project hashes, and independently recheck >=10% spread ordinary provenance. This is the exact TASK_233 oversized PVGCodec index-253 corrective case: the 27,524-byte original FDE timed out under the 15-second Ghidra decompile cap and had partial body membership. Use bounded CFG/subregion or another distinct static method, map any recovered text to original instructions, account uncovered ranges, preserve failures and do not call a fragment complete or re-count old output. C-like output is static research, not source or behavioral proof. Seal PARTIAL if any target or boundary remains unresolved.

Before any write fully read canonical Standard at F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt (SHA-256 10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f), AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task/manifest and config/state/locks/END. Claim exact ACTIVE TASK_248 R1 as /root/audit_157_158 using LEASE-CEO-WORKER-TASK_248-R1 before writing. Write only files_allowed; original SO and prior reports are read-only. Report canonical path and SHA in 00_AUDIT_INDEX.md. No AGY, child agents, self-review, commit/push before CEO review. P0/product/V4/P7 remain frozen. Stop at absolute task deadline.
