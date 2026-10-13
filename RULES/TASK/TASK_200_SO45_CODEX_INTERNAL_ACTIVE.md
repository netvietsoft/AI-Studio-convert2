# TASK_200 R1 - bounded next libPVGColorFunctions.so nonexport FDE candidates

STATUS: ACTIVE
ASSIGNEE: /root/so45_pvg_followon
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T12:38:28.557268Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_200",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_pvg_followon",
  "agent_id": "/root/so45_pvg_followon",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_198",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_200_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_200_REPORT_R1/**",
    "scripts/task_200_codex_internal/**",
    "RESEARCH_WORK/TASK_200_R1/**"
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
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_200-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGColorFunctions.so": {
      "sha256": "3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6",
      "defined_nonzero_export_vas": 81
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_200_internal_targets.json",
  "target_manifest_sha256": "ef0f80c15e13c9d3f20e02090642595b2f68e354b10b7e434a9b75f8544cb75d",
  "target_candidate_count": 32,
  "authorization_reference": "Chairman Tony directs direct SO45 decoding with real Codex subagents, without AGY",
  "created_at": "2026-10-13T12:38:28.557268Z",
  "modified_time": "2026-10-13T12:38:28.557268Z",
  "budget_deadline_utc": "2026-10-13T14:08:28.557268+00:00"
}
```

Process only the 32 exact global zero-based VA-sorted nonexport FDE indices in `.ai/ceo/reviews/TASK_200_internal_targets.json` SHA-256 `ef0f80c15e13c9d3f20e02090642595b2f68e354b10b7e434a9b75f8544cb75d` from original `libPVGColorFunctions.so` SHA-256 `3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6`. This slice is 640..671, excluding []; it contains 14,460 bytes and 3,615 AArch64 instruction positions. No index in this slice exceeds 4,096 bytes. TASK_196 left index 556 unanalysed and five boundary-PARTIAL rows; TASK_198 left indices 620 and 625 PARTIAL. These remain open. Do not count excluded, earlier or partial rows as solved. Accepted TASK_198 R1 is the prior disjoint dependency; verify all hashes of `RESEARCH_WORK/TASK_198_R1/ghidra_project` against its sealed evidence before making a private byte-verified copy.

An unwind FDE is a candidate range, not proof of a complete unique source function. Verify original ELF FDE/dynsym/PT_LOAD/body hashes, every source instruction position, and nonoverlap. On a private Ghidra project copy collect one raw result per target: memory hash, exact every-byte function-body membership, missing/extra ranges, instruction/p-code coverage, C-like text/hash or failure, calls, command/log receipts, and before/after project hashes. Mark ambiguous boundaries PARTIAL. Transient correction is allowed only on nonoverlapping gaps with fresh-session rollback and memory proof; never erase other function metadata. Use one CPU, 1 GiB heap, sequential <=20-minute headless jobs, <=10 seconds per decompile and the original absolute deadline. Independently recheck every critical claim and >=10% spread ordinary source positions; seal truthful partial results if incomplete. No behavior/pixel parity, product Phase PASS, V4/P7 or all-45-SO completion inference.

Before any write fully read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`. Also read AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task and manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_200 R1 as `/root/so45_pvg_followon` using `LEASE-CEO-WORKER-TASK_200-R1` before writes. Write only `RULES/REPORT/TASK_200_REPORT_R1/**`, `scripts/task_200_codex_internal/**`, `RESEARCH_WORK/TASK_200_R1/**`; SO, prior research, other lanes and P0 are read-only. Create `00_AUDIT_INDEX.md` canonical-read receipt, `01_MASTER_REPORT.md`, raw per-candidate and command/log evidence, `PROGRESS.json`, and SHA-256 sealed `COMPLETE.json`. No AGY, further subagents, self-review, commit or push before CEO independent review. Stop by 2026-10-13T14:08:28.557268+00:00.
