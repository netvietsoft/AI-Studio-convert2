# TASK_247 R1 - bounded libPVGImageCodec.so ordinary continuation

STATUS: ACTIVE
ASSIGNEE: /root/audit_157_158
PRIORITY: P1
MODIFIED_TIME: 2026-10-15T10:54:39.336121+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_247",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/audit_157_158",
  "agent_id": "/root/audit_157_158",
  "priority": "P1",
  "mode": "RESEARCH",
  "dependencies": [
    {
      "task_id": "TASK_211",
      "revision": 1
    }
  ],
  "report_folder": "RULES/REPORT/TASK_247_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_247_REPORT_R1/**",
    "scripts/task_247_codex_internal/**",
    "RESEARCH_WORK/TASK_247_R1/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_247-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGImageCodec.so": {
      "sha256": "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b"
    }
  },
  "target_candidate_count": 1,
  "authorization_reference": "Chairman Tony direct SO45 decoding continuation without AGY; bounded research only",
  "created_at": "2026-10-15T10:54:39.336121+00:00",
  "modified_time": "2026-10-15T10:54:39.336121+00:00",
  "budget_deadline_utc": "2026-10-15T12:54:39.336121+00:00",
  "target_manifest_path": ".ai/ceo/reviews/TASK_247_internal_targets.json",
  "target_manifest_sha256": "5b40330b74fe878983f40bd46060e1c0af9b99231a7b971c935fd1ae74308dac"
}
```

Research only exact manifest targets (1 selected from indices 465..465). Reverify original ELF/PT_LOAD/FDE body bytes and every ARM64 word. Use a private bounded Ghidra project (one CPU, 1 GiB heap, <=15 seconds per decompile). Capture exact membership, listing/p-code, raw C-like or failure, command/log/project hashes, and independently recheck >=10% spread ordinary provenance. This is the exact TASK_211 R1 index-465 correction: original Ghidra and a fresh retry both failed with a varnode unique-hash error, yielding zero C-like text. Try a distinct bounded analysis path or CFG/IR repair, preserve each raw attempt, tie any recovered text to original source bytes and identify uncovered ranges. Do not re-count TASK_211's failed row or call a fragment whole-function recovery. C-like output is static research, not source or behavioral proof. Seal PARTIAL if any target or boundary remains unresolved.

Before any write fully read canonical Standard at F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt (SHA-256 10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f), AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task/manifest and config/state/locks/END. Claim exact ACTIVE TASK_247 R1 as /root/audit_157_158 using LEASE-CEO-WORKER-TASK_247-R1 before writing. Write only files_allowed; original SO and prior reports are read-only. Report canonical path and SHA in 00_AUDIT_INDEX.md. No AGY, child agents, self-review, commit/push before CEO review. P0/product/V4/P7 remain frozen. Stop at absolute task deadline.
