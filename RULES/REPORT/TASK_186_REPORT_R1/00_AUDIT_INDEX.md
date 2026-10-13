# TASK_186 R1 audit index

- Canonical Standard fully read before writes: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`; read/claim acknowledged 2026-10-13T10:09:35.805564+00:00.
- Exact ACTIVE task: `RULES/TASK/TASK_186_SO45_CODEX_INTERNAL_ACTIVE.md`; SHA-256 `8983063634e66107295dee5c697e488d4173dc8d339abbd6928d197217aaee35`.
- Target manifest: `.ai/ceo/reviews/TASK_186_internal_targets.json`; SHA-256 `55ca7de32dc6a55aab0ce8605360f5350924192500ff33de0e814060ce0b6865`; exact next 128 VA-sorted nonexport FDE candidate indices 128..255 only; no TASK_185 overlap.
- Actual agent/lease/fence: `/root/so45_ai_model_search` / `LEASE-CEO-WORKER-TASK_186-R1` / `1217`.
- Original source: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGColorFunctions.so`; SHA-256 `3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6`.
- Raw files: `source_index.json`, `source_assembly.ndjson`, `project_copy_receipt.json`, `project_postrun_receipt.json`, failed `chunk_00/` raw command/log/output, labeled `chunk_00_retry1/` correction reason and valid raw command/log/output, valid `chunk_01/` through `chunk_03/` raw files, `candidate_index.json`, and `independent_verification.json`.
- C-like strings and hashes are in each raw Ghidra NDJSON row; `candidate_index.json` links all 128 addresses and boundary classifications.
- `COMPLETE.json` hashes every nonvolatile report file plus all task-owned scripts; CEO performs independent review. No self-ack or commit/push.
