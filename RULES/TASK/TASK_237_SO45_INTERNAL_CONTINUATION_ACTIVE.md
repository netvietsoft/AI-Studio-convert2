# TASK_237 R1 - bounded libPVGImageCodec.so ordinary continuation

STATUS: ACTIVE
ASSIGNEE: /root/audit_157_158
PRIORITY: P1
MODIFIED_TIME: 2026-10-15T10:16:30.016249+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_237",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/audit_157_158",
  "agent_id": "/root/audit_157_158",
  "priority": "P1",
  "mode": "RESEARCH",
  "dependencies": [
    {
      "task_id": "TASK_234",
      "revision": 1
    }
  ],
  "report_folder": "RULES/REPORT/TASK_237_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_237_REPORT_R1/**",
    "scripts/task_237_codex_internal/**",
    "RESEARCH_WORK/TASK_237_R1/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_237-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGImageCodec.so": {
      "sha256": "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b"
    }
  },
  "target_candidate_count": 507,
  "authorization_reference": "Chairman Tony direct SO45 decoding continuation without AGY; bounded research only",
  "created_at": "2026-10-15T10:16:30.016249+00:00",
  "modified_time": "2026-10-15T10:16:30.016249+00:00",
  "budget_deadline_utc": "2026-10-15T12:16:30.016249+00:00",
  "target_manifest_path": ".ai/ceo/reviews/TASK_237_internal_targets.json",
  "target_manifest_sha256": "ea7262a4d1a0f3553fc9314f784ffc6fa2406f9669f901653c7e38730efebdb2"
}
```

Research only exact manifest targets (507 selected from indices 3073..3584). Reverify original ELF/PT_LOAD/FDE body bytes and every ARM64 word. Use a private bounded Ghidra project (one CPU, 1 GiB heap, <=15 seconds per decompile). Capture exact membership, listing/p-code, raw C-like or failure, command/log/project hashes, and independently recheck >=10% spread ordinary provenance. This next image slice may contain oversized candidates; record every skipped index explicitly and continue only within bounded 1 GiB/15-second per-decompile limits. Preserve all earlier unresolved image indices. C-like output is static research, not source or behavioral proof. Seal PARTIAL if any target or boundary remains unresolved.

Before any write fully read canonical Standard at F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt (SHA-256 10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f), AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task/manifest and config/state/locks/END. Claim exact ACTIVE TASK_237 R1 as /root/audit_157_158 using LEASE-CEO-WORKER-TASK_237-R1 before writing. Write only files_allowed; original SO and prior reports are read-only. Report canonical path and SHA in 00_AUDIT_INDEX.md. No AGY, child agents, self-review, commit/push before CEO review. P0/product/V4/P7 remain frozen. Stop at absolute task deadline.
