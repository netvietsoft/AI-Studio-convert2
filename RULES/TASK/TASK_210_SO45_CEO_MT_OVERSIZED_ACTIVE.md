# TASK_210 R1 - CEO direct continuation of seven oversized MTFilter FDE candidates

STATUS: ACTIVE
ASSIGNEE: Codex_CEO
PRIORITY: P1
MODIFIED_TIME: 2026-10-15T07:50:03.981980+00:00

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_210",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "Codex_CEO",
  "agent_id": "Codex_CEO",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_204",
      "revision": 2
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_210_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_210_REPORT_R1/**",
    "scripts/task_210_ceo_mt_oversized/**",
    "RESEARCH_WORK/TASK_210_R1/**"
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
  "max_minutes": 90,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_per_decompile_seconds": 20,
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_210-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libMTFilterKernel.so": {
      "sha256": "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4",
      "defined_nonzero_export_vas": 2362
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_209_internal_targets.json",
  "target_manifest_sha256": "df650a1801177d429fa60948e023deae985579cd29319fb76b93d7a0561f3a01",
  "target_candidate_count": 7,
  "authorization_reference": "Chairman Tony direct Codex continuation without AGY, reaffirmed 2026-10-15; TASK_209 R1 worker hit usage limit and original deadline expired",
  "created_at": "2026-10-15T07:50:03.981980+00:00",
  "modified_time": "2026-10-15T07:50:03.981980+00:00",
  "budget_deadline_utc": "2026-10-15T09:20:03.981980+00:00"
}
```

Only exact seven indices 211,216,235,293,304,349,362 from the pinned TASK_209 manifest. TASK_209 R1 is an expired incomplete prior attempt; its scripts are untrusted read-only references. Revalidate original ELF/FDE/PT_LOAD bytes and AArch64 instructions directly. Capture branch/call sites, then use a distinct private headless Ghidra project, one CPU and 1 GiB heap, with per-target timeouts. Record full function-body membership, listing/p-code positions, raw C-like or failure, commands/logs, and project hashes. Mark ambiguous or unsupported behavior PARTIAL. No invented bodies, source reconstruction claim, product PASS, V4 or P7. Preserve source, prior reports, P0, and unrelated workspace edits. Read full canonical Standard, AGENTS.md, Docs/rules.md, SO45 plan, PROJECT_ERROR.md, ACQUIREMENTS.md, config/state/locks/END and this task before work. Claim exact ACTIVE TASK_210 R1 as Codex_CEO; write only its files_allowed. Report canonical path and SHA in 00_AUDIT_INDEX.md; seal final manifest truthfully. No self-acceptance or commit before independent review. Stop at the absolute deadline.
