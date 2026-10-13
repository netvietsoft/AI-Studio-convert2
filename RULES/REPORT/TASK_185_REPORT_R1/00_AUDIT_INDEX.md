# TASK_185 R1 audit index

- Canonical Standard fully read before writes: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`; read/claim acknowledged 2026-10-13T09:43:48.007790+00:00.
- Exact ACTIVE task: `RULES/TASK/TASK_185_SO45_CODEX_INTERNAL_ACTIVE.md`; SHA-256 `1ef18d475ed71efb2e5ff6703afc58da9c767dfb523ebac8213402a6dc0b7cad`.
- Target manifest: `.ai/ceo/reviews/TASK_185_internal_targets.json`; SHA-256 `f55584944df014f2fddca499d33cc7ca727048a9afb2257e4b98b22ad70ad561`; exact first 128 VA-sorted nonexport FDE starts only.
- Actual agent/lease/fence: `/root/so45_ai_model_search` / `LEASE-CEO-WORKER-TASK_185-R1` / `1213`.
- Original source: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGColorFunctions.so`; SHA-256 `3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6`.
- Raw files: `source_index.json`, `source_assembly.ndjson`, `project_copy_receipt.json`, `project_postrun_receipt.json`, four `chunk_XX/targets.tsv`, four `chunk_XX/ghidra_command.json`, four stdout/stderr pairs, four `ghidra_raw.ndjson` files, `candidate_index.json`, and `independent_verification.json`.
- C-like strings and hashes are in each raw Ghidra NDJSON row; `candidate_index.json` links all 128 addresses and boundary classifications.
- `COMPLETE.json` hashes every nonvolatile report file plus all task-owned scripts; CEO performs independent review. No self-ack or commit/push.
