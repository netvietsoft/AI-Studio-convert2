# TASK_187 R2 — MTFilterKernel static candidate batch continuation

**PARTIAL static research, R2 evidence package complete for independent CEO review.** Original R1 worker exhausted its runtime before sealing; R1 remains byte-for-byte preserved and unsealed. This R2 reverified the exact 128 source-pinned nonexport FDE candidates against the original libMTFilterKernel.so ELF.

Original FDE/PT_LOAD/body hashes agree for 128/128 candidates. 14,865 AArch64 words match source assembly and Ghidra memory records; the effective Ghidra p-code has 14,865 positions and 40,694 operations. All 128 effective C-like texts are nonempty and individually hashed in the R2 index. Original Ghidra function bodies cover every FDE byte in 122/128 rows; six rows (#18, #23, #30, #43, #85, #128) originally missed 66 instruction slots. Their R1 transient metadata corrections show full candidate FDE membership, assembly and p-code, with source memory unchanged after rollback. Those outputs remain boundary assumptions and do not establish exact function semantics.

R2 independently checked 1,846/14,865 (12.42%) spread instruction addresses against original bytes, Capstone, the R1 source record and Ghidra text/p-code positions. All R1 report, code and scratch files were hashed before and after this check and remain unchanged. Three R1 Ghidra command/log/result sets were rehashed; no task-owned process remained and R2 launched none.

The remaining 383 nonexport FDE candidates were outside this task. FDE boundaries do not establish a complete internal-function census. No behavioral equivalence, device/pixel parity, product Phase PASS, all-45-SO completion or V4/P7 readiness is claimed. No commit or push occurred pending CEO review.
