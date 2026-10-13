# TASK_194 R1 - bounded libPVGColorFunctions.so nonexport FDE candidates

STATUS: ACTIVE
ASSIGNEE: /root/so45_pvg_followon
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T11:46:02.552646Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_194",
  "revision": 1,
  "status": "ACTIVE",
  "assignee": "/root/so45_pvg_followon",
  "agent_id": "/root/so45_pvg_followon",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_191",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_194_REPORT_R1",
  "files_allowed": [
    "RULES/REPORT/TASK_194_REPORT_R1/**",
    "scripts/task_194_codex_internal/**",
    "RESEARCH_WORK/TASK_194_R1/**"
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
  "max_minutes": 75,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_194-R1",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGColorFunctions.so": {
      "sha256": "3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6",
      "defined_nonzero_export_vas": 81
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_194_internal_targets.json",
  "target_manifest_sha256": "c332dbf4b85513e49908e654146ff9e34914b4f9047a46579189eb3d86135133",
  "target_candidate_count": 63,
  "authorization_reference": "Chairman Tony directs direct SO45 decoding with real Codex subagents, without AGY",
  "created_at": "2026-10-13T11:46:02.552646Z",
  "budget_deadline_utc": "2026-10-13T13:01:02.552646+00:00"
}
```

Process only the **63** exact VA-sorted nonexport FDE rows in `.ai/ceo/reviews/TASK_194_internal_targets.json` SHA-256 `c332dbf4b85513e49908e654146ff9e34914b4f9047a46579189eb3d86135133` from original `libPVGColorFunctions.so` SHA-256 `3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6`. They are global zero-based indices 448..511 **excluding index505** (VA0x3bc10, 4,500 bytes, 1,125 AArch64 slots) reserved for a separately bounded large-body task. Do not count index505 as analyzed. This lease's 63 targets total 18,568 bytes and 4,642 source instruction positions. Indices507,508,511 may be one-instruction stubs/thunks; do not claim they are complete unique source functions. Prior accepted TASK_191 covers earlier indices384..447. Its analyzed project `RESEARCH_WORK/TASK_191_R1/ghidra_project` is read-only input; verify copied-project hashes against its sealed receipt before reuse.

An unwind FDE is a candidate range, not proof of complete unique source-function boundaries. Verify original ELF FDE/PT_LOAD/body hashes and every source instruction position. On a private byte-verified Ghidra project copy, preserve raw memory hashes, every-byte body membership, missing/extra ranges, instruction/p-code and C-like text/hash or failure, calls, command/log receipts and project before/after hashes. Mark ambiguous boundaries PARTIAL; never remove metadata of another function. Transient correction is permitted only on nonoverlapping gaps, in read-only project sessions with rollback and before/after memory proof. Use one CPU, 1 GiB heap, sequential <=20-minute headless processes and <=10 seconds per decompile. Independently recheck all critical claims plus >=10% spread ordinary source instruction slots and seal a truthful bounded report. No behavior/pixel parity, product Phase PASS, V4/P7, or all-45-SO completion inference.

Before any write fully read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`. Also read AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this task/manifest, config/state/locks/END and git status. Claim exact ACTIVE TASK_194 revision1 as `/root/so45_pvg_followon` via controller with lease `LEASE-CEO-WORKER-TASK_194-R1` before writes. Write only `RULES/REPORT/TASK_194_REPORT_R1/**`, `scripts/task_194_codex_internal/**`, `RESEARCH_WORK/TASK_194_R1/**`; source SO, prior research, other lanes, P0 read-only. Create 00_AUDIT_INDEX.md canonical-read receipt, 01_MASTER_REPORT.md, raw evidence, PROGRESS, COMPLETE.json SHA-256 seal. No AGY, further subagents, self-review, commit or push before CEO independent review. Stop by 2026-10-13T13:01:02.552646+00:00.
