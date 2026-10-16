# TASK_249 R1 — Audit index

- Task: `TASK_249`, revision 1, ACTIVE, assignee `/root/pvg_gap_decode`.
- Canonical standard fully reread: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`, SHA-256 `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`.
- Task SHA-256: `4f5ec07747c381257116461979fa5fced279911b19a0f2f3aa0e5348e339ae0e`.
- Target-manifest `.ai/ceo/reviews/TASK_249_internal_targets.json` SHA-256: `29890e85a5c7677cabf51a20dcbc3fe34b9531fc12ceadb1e25476d9b81c1f27`.
- Lease `LEASE-CEO-WORKER-TASK_249-R1`, fencing token **1289**; canonical-read acknowledgment recorded by controller.
- Source `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGCodec.so`, SHA-256 `4fa5f275c8ddecf7caa960c812108ec9e801365bfe5bc9cf38598233bc449ffc`.
- Exact gap: VA/file offset `[0xaf040,0xaf688)`, 1,608 bytes, 402 4-byte ARM64 words; gap SHA-256 `f825653da2ed819fd5334f4103037f4466fcf8655080e5ec84c56a684569c54b`.

This report independently rehashes and decodes the target span, performs a bounded Ghidra read-only listing/body-membership query against the existing TASK_248 project, retains the candidate FDE's LSDA call-site evidence, and records the branch ledger. It reports **zero new C-like function bodies**. FDE membership is not treated as proof of source-function boundaries. No runtime behavior, product phase, V4, P0, or P7 claim is made. No source/project write, commit, or push was performed.

Report entry points:

- `01_MASTER_REPORT.md` — findings, limitations, and next bounded method.
- `ghidra/gap_listing.json`, `ghidra/stdout.log`, `ghidra/stderr.log`, `ghidra/exit_code.txt`, `ghidra/command.json` — raw narrow Ghidra listing result and invocation. `stderr.log` includes PowerShell stream formatting; native launcher exit code is separately captured as 0.
- `source/word_edge_ledger.json`, `source/capstone_disassembly.txt`, `source/incoming_fde_edges.json` — complete target-span coverage and edges.
- `source/lsda_callsite_evidence.json`, `source/eh_lsda_summary.json` — raw LSDA bytes and decoded rows.
- `source/pcode_gap.json`, `source/c_like_gap.json` — explicit absence, not functions.
- `scripts/task_249_codex_internal/GapListing249.java`, `scripts/task_249_codex_internal/verify_gap.py` — bounded listing and source/coverage verifier.

Disposition: `PARTIAL`; review state `REVIEW_CANDIDATE_AWAITING_CEO` after the report snapshot is sealed. No self-review or commit/push.
