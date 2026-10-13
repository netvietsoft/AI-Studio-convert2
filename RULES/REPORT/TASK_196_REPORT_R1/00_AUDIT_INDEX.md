# TASK_196 R1 audit index

- Canonical Standard fully read before writes: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`; SHA-256 `10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f`; controller claim standard-read ACK `2026-10-13T12:06:57.533653+00:00`.
- Exact ACTIVE task: `RULES/TASK/TASK_196_SO45_CODEX_INTERNAL_ACTIVE.md`; SHA-256 `221139ef3ddc9427114f4a357c8eb4ad23df4abd81ba05d45b9d58c7ee85ece3`.
- Target manifest: `.ai/ceo/reviews/TASK_196_internal_targets.json`; SHA-256 `724d27502c716d274ab6bc48e7dd8497f7e72c2ec98cbc5a119d24126b041cbe`; exact VA-sorted nonexport FDE candidate indices 512..575 excluding oversized index 556.
- Actual agent/lease/fence: `/root/so45_pvg_followon` / `LEASE-CEO-WORKER-TASK_196-R1` / `1228`.
- Original source: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGColorFunctions.so`; SHA-256 `3aab7535eefd304fef426efd49c1fee51300261edc766cdc551355c3eebb04e6`. Accepted prior TASK_194 project: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\RESEARCH_WORK\TASK_194_R1\ghidra_project`; nine file hashes matched its sealed postrun receipt and COMPLETE seal before copying.
- `source_index.json` and `source_assembly.ndjson` record every source FDE/PT_LOAD body and instruction position. Four `chunk_XX/` folders preserve per-candidate raw Ghidra output, target TSV, command receipts, stdout and stderr.
- `project_copy_receipt.json` and `project_postrun_receipt.json` prove byte-identical private project copy and unchanged read-only files. `candidate_index.json` and `independent_verification.json` give boundary/accounting and spread checks.
- `COMPLETE.json` hashes every fixed report file and code script; CEO independent review remains pending. No source/product/V4/45-SO acceptance is claimed.
