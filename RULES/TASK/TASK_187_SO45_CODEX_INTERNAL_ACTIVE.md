# TASK_187 R2 - seal interrupted MTFilterKernel static candidate batch

STATUS: ACTIVE
ASSIGNEE: /root/so45_ai_model_search
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T10:52:24.643651Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_187",
  "revision": 2,
  "status": "ACTIVE",
  "assignee": "/root/so45_ai_model_search",
  "agent_id": "/root/so45_ai_model_search",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_183",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_187_REPORT_R2",
  "files_allowed": [
    "RULES/REPORT/TASK_187_REPORT_R2/**",
    "scripts/task_187_codex_continuation_r2/**",
    "RESEARCH_WORK/TASK_187_R2/**"
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
  "max_minutes": 40,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_187-R2",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libMTFilterKernel.so": {
      "sha256": "f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4",
      "defined_nonzero_export_vas": 2362
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_187_internal_targets.json",
  "target_manifest_sha256": "cdca39d65d7a29d866b3e43264f687d147b549c43945e4f0c694fb8e73d56bf8",
  "target_candidate_count": 128,
  "authorization_reference": "Chairman Tony explicitly directs direct SO45 decoding without AGY and real Codex subagents in parallel lanes",
  "created_at": "2026-10-13T10:52:24.643651Z",
  "budget_deadline_utc": "2026-10-13T11:32:24.643651+00:00",
  "continuation_of": {
    "revision": 1,
    "task_sha256": "6f62d5b04b4681750141b52f99916ad3685ec1871a0a74f28a5829e3322888d3",
    "task_archive": ".ai/ceo/reviews/TASK_187_R1_TASK_SNAPSHOT.md",
    "reason": "Original Codex worker hit usage limit before sealing; R1 evidence remains unsealed and immutable"
  }
}
```

The R1 Codex worker hit a usage limit after producing 128 first-pass Ghidra records, six transient full-FDE metadata corrections and original source assembly. R1 has no `COMPLETE.json` and remains **unsealed**. Preserve all R1 files byte-for-byte. Do not impersonate the original worker or use its R1 fencing token. This R2 authorizes only independent verification and sealing of the exact 128 source-pinned `libMTFilterKernel.so` FDE candidates in `.ai/ceo/reviews/TASK_187_internal_targets.json` (manifest SHA-256 `cdca39d65d7a29d866b3e43264f687d147b549c43945e4f0c694fb8e73d56bf8`, source ELF SHA-256 `f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4`).

Read R1 `source_project_index.json`, all 128 first-pass candidate JSON records, six correction JSON records, original source assembly, copied-project hashes, all three raw command/log pairs and the original `scripts/task_187_codex_internal/verify_and_seal.py` **read-only**. Verify every original ELF/FDE/PT_LOAD body and SHA, exact candidate ordering/nonexport criterion, 128 Ghidra memory and C-like hashes, full function-body byte membership, 122 original full-FDE rows and six transient corrected rows, and >=10% spread ordinary instruction slots against original bytes independently. Verify no surviving task-owned Ghidra process and no fresh import is needed; do not relaunch Ghidra. The six transient corrections are source-backed static metadata, not proof of exact source semantics. Preserve any failure or discrepancy and seal a truthful bounded PARTIAL if needed.

Before any write, fully re-read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`. Read AGENTS.md, Docs/rules.md, .ai/ceo/SO45_TO_V4_PLAN.md, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact R2 task, target manifest, config/state/locks/END flag and git status. Claim exact ACTIVE TASK_187 revision 2 as `/root/so45_ai_model_search`, expected lease `LEASE-CEO-WORKER-TASK_187-R2`, before any write. Only write `RULES/REPORT/TASK_187_REPORT_R2/**`, `scripts/task_187_codex_continuation_r2/**`, and `RESEARCH_WORK/TASK_187_R2/**`; R1 and original SO are read-only. Produce 00_AUDIT_INDEX.md canonical read receipt, 01_MASTER_REPORT.md, a SHA-256 inventory of all referenced R1 raw/code/project evidence, independent verification output including sample addresses, PROGRESS and sealed COMPLETE.json with complete R2 file manifest. No AGY, product/P0 edits, self-review, Phase PASS, V4/P7 or all-45-SO claim. Do not commit/push until CEO independent review. Stop by 2026-10-13T11:32:24.643651+00:00.
