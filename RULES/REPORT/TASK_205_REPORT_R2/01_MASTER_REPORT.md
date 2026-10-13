# TASK_205 R2 — corrected p-code coverage

**PARTIAL static research.** Across 126 pinned ImageCodec nonexport FDE candidates, source evidence contains **6,246 AArch64 instruction words**. The effective Ghidra arrays contain **6,246 instruction listings**, of which **6,240 contain at least one p-code operation**. Six listed NOPs have `pcode_ops: []`; the total **25,604 p-code operations** is unchanged.

Affected candidates are one-based 380, 381 and 384. `CORRECTED_COVERAGE.json` gives the source word and database/source address of each empty NOP; `R1_TO_R2_DELTA.json` names the R1 fields and prose superseded by this correction. The 126 C-like outputs and original static 192 call and 1,087 branch sites are unchanged. We independently replayed every effective source/listing position from the immutable R1 raw files and rehashed the R1 seal inventory.

Boundary limits remain: unwind FDEs need not be unique source functions; two candidates required transient full-FDE metadata for complete listings, and R1's separate fresh-session read was used to verify original metadata and memory after rollback. This is not a behavior proof, product Phase PASS, or V4 readiness claim.
