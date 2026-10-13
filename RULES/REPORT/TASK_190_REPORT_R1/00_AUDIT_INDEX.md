# TASK_190 R1 audit index

- Canonical Standard fully read before writes: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`; claim receipt 2026-10-13T11:15:04.309394+00:00.
- Exact ACTIVE task: `RULES/TASK/TASK_190_SO45_CODEX_INTERNAL_ACTIVE.md`; SHA-256 `aef3561525843644d52868b8e3472ca9947845af9398cee7f1f523b1ba2211bb`.
- Target manifest: `.ai/ceo/reviews/TASK_190_internal_targets.json`; SHA-256 `e395a01c86a666f9b903f5057f30b9792d006e3763a0f85a090e9df96e150076`; VA-sorted nonexport FDE candidate indices 256..383 only.
- Actual agent/lease/fence: `/root/so45_pvg_next` / `LEASE-CEO-WORKER-TASK_190-R1` / `1222`.
- Original source: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGColorFunctions.so`; SHA-256 `3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6`.
- `source_index.json` and `source_assembly.ndjson` record exact source bodies and all instruction slots. Four `chunk_XX/` folders preserve raw Ghidra output, target TSVs, command receipts and process logs.
- `transient_gap_correction/` records a separately bounded read-only Ghidra transaction for row 128's four-byte tail gap, with other-function ownership check, full-FDE instruction/p-code/C-like output, rollback, unchanged source-memory SHA and project hashes.
- `project_copy_receipt.json` and `project_postrun_receipt.json` verify the read-only prior analyzed project and private copy. `candidate_index.json` and `independent_verification.json` summarize per-candidate boundaries and spread provenance.
- `COMPLETE.json` hashes every nonvolatile report file and code script; CEO independently reviews before any commit/push. No product or V4 acceptance.
