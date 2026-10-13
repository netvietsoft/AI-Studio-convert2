# TASK_192 R1 - bounded libPVGImageCodec.so nonexport FDE candidates

STATUS: ACTIVE
ASSIGNEE: /root/so45_imagecodec_internal
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T11:34:34.131421Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_192",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_imagecodec_internal",
  "agent_id": "/root/so45_imagecodec_internal",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_160",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_192_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_192_REPORT_R1/**",
    "scripts/task_192_codex_internal/**",
    "RESEARCH_WORK/TASK_192_R1/**"
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
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_192-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGImageCodec.so": {
      "sha256": "7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b",
      "defined_nonzero_export_vas": 3326
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_192_internal_targets.json",
  "target_manifest_sha256": "2c1842f80abc1a74f9e2fffe9de3ef86eb07102df660b3c5149eb21f3146f15b",
  "target_candidate_count": 64,
  "authorization_reference": "Chairman Tony directs direct SO45 decoding with real Codex subagents, without AGY",
  "created_at": "2026-10-13T11:34:34.131421Z",
  "budget_deadline_utc": "2026-10-13T13:04:34.131421+00:00"
}
```

Process only exact sorted nonexport FDE candidate indices 0..63 in `.ai/ceo/reviews/TASK_192_internal_targets.json` SHA-256 `2c1842f80abc1a74f9e2fffe9de3ef86eb07102df660b3c5149eb21f3146f15b` from original `libPVGImageCodec.so` SHA-256 `7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b`. The accepted TASK_160 research covers exports only; it does not establish nonexport FDE coverage. Do not re-run its export slice. The prior analyzed project `RESEARCH_WORK/TASK_160_R1/libPVGImageCodec.so/ghidra_project` is read-only input; verify source and copied-project hashes before reuse. An unwind FDE is a candidate range, not proof of complete or unique source-function boundaries. Check all original FDE/PT_LOAD body hashes and all source instruction positions. On a private byte-verified project copy, collect one Ghidra result per candidate: memory SHA, every-byte function-body membership, missing/extra ranges, instruction/p-code coverage, C-like text/hash or failure, and raw command/log receipts. Mark overlaps and ambiguous boundaries PARTIAL; never remove metadata of another function. Transient correction is permitted only on nonoverlapping gaps, in a read-only project session with rollback and before/after memory proof. Use one CPU, 1 GiB heap, sequential <=20-minute headless processes and <=10 seconds per decompile. Independently recheck all critical body/output claims and >=10% spread ordinary source instruction slots; seal a truthful bounded report even if incomplete. Do not infer all internal functions, behavior/pixel parity, product Phase PASS, V4/P7, or all-45-SO completion.

Before any write fully read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`. Also read AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact task/manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_192 revision 1 as `/root/so45_imagecodec_internal` using expected lease `LEASE-CEO-WORKER-TASK_192-R1` before any write. Write only `RULES/REPORT/TASK_192_REPORT_R1/**`, `scripts/task_192_codex_internal/**`, `RESEARCH_WORK/TASK_192_R1/**`; source SO, prior research, other lanes and P0 are read-only. Create 00_AUDIT_INDEX.md canonical read receipt, 01_MASTER_REPORT.md, raw per-candidate and command/log evidence, PROGRESS and COMPLETE.json SHA-256 manifest. No AGY, further subagents, self-review or commit/push before CEO independent review. Stop by 2026-10-13T13:04:34.131421+00:00.
