# TASK_195 R1 - bounded next libPVGImageCodec.so nonexport FDE candidates

STATUS: ACTIVE
ASSIGNEE: /root/so45_imagecodec_internal
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T12:05:53.072408Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_195",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_imagecodec_internal",
  "agent_id": "/root/so45_imagecodec_internal",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_192",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_195_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_195_REPORT_R1/**",
    "scripts/task_195_codex_internal/**",
    "RESEARCH_WORK/TASK_195_R1/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_195-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGImageCodec.so": {
      "sha256": "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b",
      "defined_nonzero_export_vas": 3326
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_195_internal_targets.json",
  "target_manifest_sha256": "d2c6de5a699068c60e4a081a87349234f8878952c7a4a9a9248d2b3ae02c0901",
  "target_candidate_count": 64,
  "authorization_reference": "Chairman Tony directs direct SO45 decoding with real Codex subagents, without AGY",
  "created_at": "2026-10-13T12:05:53.072408Z",
  "modified_time": "2026-10-13T12:05:53.072408Z",
  "budget_deadline_utc": "2026-10-13T13:35:53.072408+00:00"
}
```

Process only the 64 exact global zero-based VA-sorted nonexport FDE indices in `.ai/ceo/reviews/TASK_195_internal_targets.json` SHA-256 `d2c6de5a699068c60e4a081a87349234f8878952c7a4a9a9248d2b3ae02c0901` from original `libPVGImageCodec.so` SHA-256 `7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b`. The selected range is 64..127; [] is excluded. The targets total 25,396 bytes and 6,349 AArch64 source instruction positions. Previous ImageCodec indices 0..63 belong to accepted TASK_192. Do not count excluded, earlier or partial rows as solved. Accepted TASK_192 is the prior disjoint slice; its project `RESEARCH_WORK/TASK_192_R1/ghidra_project` is read-only input. Verify all prior project hashes from that task's sealed receipt before using a private byte-verified copy.

An unwind FDE is only a candidate range, not proof of a complete unique source function. Verify original ELF FDE/dynsym/PT_LOAD/body hashes, every source instruction position, and nonoverlap. On a private Ghidra project copy collect one raw result per target: memory hash, exact every-byte function-body membership, missing/extra ranges, instruction/p-code coverage, C-like text/hash or failure, calls, command/log receipts, and before/after project hashes. Mark ambiguous boundaries PARTIAL. Transient correction is allowed only on nonoverlapping gaps with fresh-session rollback and memory proof; never erase other function metadata. Use one CPU, 1 GiB heap, sequential <=20-minute headless jobs, <=10 seconds per decompile and the original absolute deadline. Independently recheck every critical claim and >=10% spread ordinary source positions; seal truthful partial results if incomplete. No behavior/pixel parity, product Phase PASS, V4/P7 or all-45-SO completion inference.

Before any write fully read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`. Also read AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task and manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_195 R1 as `/root/so45_imagecodec_internal` using `LEASE-CEO-WORKER-TASK_195-R1` before writes. Write only `RULES/REPORT/TASK_195_REPORT_R1/**`, `scripts/task_195_codex_internal/**`, `RESEARCH_WORK/TASK_195_R1/**`; SO, prior research, other lanes and P0 are read-only. Create `00_AUDIT_INDEX.md` canonical-read receipt, `01_MASTER_REPORT.md`, raw per-candidate and command/log evidence, `PROGRESS.json`, and SHA-256 sealed `COMPLETE.json`. No AGY, further subagents, self-review, commit or push before CEO independent review. Stop by 2026-10-13T13:35:53.072408+00:00.
