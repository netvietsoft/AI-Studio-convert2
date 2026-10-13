# TASK_177 R1 — eleven-SO export gap revalidation

**Result: PARTIAL static C-like research.** The eleven pinned original SOs contain 229 unique defined nonzero-size `.dynsym` STT_FUNC export VAs. Every original PT_LOAD body and every copied analyzed Ghidra memory body matched the source hash. Unaccepted TASK_149/153 historical C-like text was independently revalidated for 227/229 exports. No fresh Ghidra import or decompilation was done.

The two unresolved C-like exports are `libMTGif.so` index 32, ELF VA `0xa1f0` (`get_nearest_index`), and index 49, ELF VA `0xaf70` (see precise symbol in `libMTGif.so/independent_verification.json`). TASK_153 returned `Unable to find unique hash for varnode`; TASK_154 made a bounded read-only `normalize` attempt and still returned empty C-like bodies. Its raw command, logs, results and source assembly are copied into this report with hashes. Reimporting unchanged source would duplicate prior extraction without a corrective mechanism.

Independent ARM64 decoding cross-checked 14463 historical instruction PCs, 1195 direct branch/call targets, and 269 indirect call sites against the original bytes. The deterministic spread sample contains 34/229 (14.85%) exports, with per-row receipts in each `independent_verification.json`. The copied Ghidra program database bytes remained unchanged; only ephemeral project index/journal metadata changed during read-only sessions, recorded per library.

Source-byte coverage is 229/229; static assembly address coverage is 229/229; Ghidra C-like coverage is 227/229; verified behavior coverage is 0/229. This does not prove all internal functions, functional equivalence, product integration, Phase PASS or V4 readiness. Independent CEO review remains required.
