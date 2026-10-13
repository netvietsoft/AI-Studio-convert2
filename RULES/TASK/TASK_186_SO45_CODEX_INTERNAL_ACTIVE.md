# TASK_186 R2 - correct PVGColorFunctions verification and boundary report

STATUS: ACTIVE
ASSIGNEE: /root/so45_dexvmp_correction
PRIORITY: P1
MODIFIED_TIME: 2026-10-13T10:55:36.135839Z

```json
{
  "schema_version": "2.1.2",
  "task_id": "TASK_186",
  "revision": 2,
  "status": "ACTIVE",
  "assignee": "/root/so45_dexvmp_correction",
  "agent_id": "/root/so45_dexvmp_correction",
  "priority": "P1",
  "dependencies": [
    {
      "task_id": "TASK_185",
      "revision": 1
    }
  ],
  "mode": "RESEARCH",
  "report_folder": "RULES/REPORT/TASK_186_REPORT_R2",
  "files_allowed": [
    "RULES/REPORT/TASK_186_REPORT_R2/**",
    "scripts/task_186_codex_correction_r2/**",
    "RESEARCH_WORK/TASK_186_R2/**"
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
  "max_minutes": 35,
  "max_cpu": 1,
  "max_heap": "1G",
  "max_report_bytes": 134217728,
  "expected_lease_id": "LEASE-CEO-WORKER-TASK_186-R2",
  "standard_sha256": "10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f",
  "source_libraries": {
    "libPVGColorFunctions.so": {
      "sha256": "3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6",
      "defined_nonzero_export_vas": 81
    }
  },
  "target_manifest_path": ".ai/ceo/reviews/TASK_186_internal_targets.json",
  "target_manifest_sha256": "55ca7de32dc6a55aab0ce8605360f5350924192500ff33de0e814060ce0b6865",
  "target_candidate_count": 128,
  "authorization_reference": "Chairman Tony explicitly directs direct SO45 decoding without AGY and real Codex subagents in parallel lanes",
  "created_at": "2026-10-13T10:55:36.135839Z",
  "budget_deadline_utc": "2026-10-13T11:30:36.135839+00:00",
  "correction_of": {
    "revision": 1,
    "fingerprint": "183e5c90186b686653e445b13f6fc090afbf0d08f07644e2b5be40718f899a22",
    "review_file": ".ai/ceo/reviews/TASK_186-183e5c90186b686653e445b13f6fc090afbf0d08f07644e2b5be40718f899a22.md",
    "r1_task_sha256": "8983063634e66107295dee5c697e488d4173dc8d339abbd6928d197217aaee35",
    "r1_task_archive": ".ai/ceo/reviews/TASK_186_R1_TASK_SNAPSHOT.md",
    "r1_seal_sha256": "1e9d937903327bef0e9532c83efdee8cb246f18c2be5b2b237afcf24bbe77c30"
  }
}
```

This is the exact report-only correction of R1 fingerprint `183e5c90186b686653e445b13f6fc090afbf0d08f07644e2b5be40718f899a22` and CEO NEEDS_FIX review `.ai/ceo/reviews/TASK_186-183e5c90186b686653e445b13f6fc090afbf0d08f07644e2b5be40718f899a22.md`. Preserve all R1 report, raw logs, code and copied Ghidra project byte-for-byte. The 128 pinned `libPVGColorFunctions.so` nonexport FDE candidates at sorted indices 128..255 remain the entire scope. Original source SHA-256 `3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6`, manifest SHA-256 `55ca7de32dc6a55aab0ce8605360f5350924192500ff33de0e814060ce0b6865`.

Independently recheck all 128 original FDE/PT_LOAD body hashes, Ghidra raw memory hashes, C-like hashes and every-byte body-membership accounting. The R1 raw rows and candidate index classify **128/128 exact FDE-body matches**, zero missing and zero extra bytes. Correct the R1 master-report sentence that calls these C-like outputs boundary-limited; retain the caveat that an FDE is only a candidate range and does not prove complete unique source semantics. R1's worker verification sampled only 36/790 instruction slots. R2 must decode and record **at least 79 distinct spread ordinary instruction slots** against original source bytes, source assembly and Ghidra listing, with exact VA/word/mnemonic evidence and a deterministic selection rule. A fresh read-only Ghidra replay is optional only if necessary; no new import, no semantic overclaim. Keep the failed serializer attempt and corrected retry clearly labeled through immutable R1 references and SHA-256 inventory. Seal only a truthful corrected R2 report.

Before any write, fully re-read `F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` and verify SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`. Read AGENTS.md, Docs/rules.md, `.ai/ceo/SO45_TO_V4_PLAN.md`, PROJECT_ERROR.md, ACQUIREMENTS.md, this exact R2 task, source manifest, config/state/locks/END and git status. Claim TASK_186 revision 2 as `/root/so45_dexvmp_correction` using lease `LEASE-CEO-WORKER-TASK_186-R2` before any write. Only write `RULES/REPORT/TASK_186_REPORT_R2/**`, `scripts/task_186_codex_correction_r2/**`, `RESEARCH_WORK/TASK_186_R2/**`. R1 and source SO are read-only. Create 00_AUDIT_INDEX.md canonical read receipt, 01_MASTER_REPORT.md, R1 reference inventory, independent instruction evidence, PROGRESS and sealed COMPLETE.json with all R2 hashes. No AGY, P0/product edits, self-review, commit/push, behavior/pixel parity, product Phase PASS, V4/P7 or all-45-SO claim. Stop by 2026-10-13T11:30:36.135839+00:00.
