# TASK_169 R1 - libLayerFlow.so export map

Status: BOUNDED_RESEARCH_CANDIDATE; awaiting independent CEO review. This is static export research, not full internal-function recovery, semantic equivalence, device proof or product Phase PASS/V4/P7 authorization.

## Observed

- Original libLayerFlow.so SHA-256 ef8d1581038778b72abca3ca8fd5046e49fd44e0465871b023647fe42a582262: 5,341 defined nonzero-size .dynsym names, 5,082 unique export VAs; 5,082 source PT_LOAD body hashes rechecked.
- Reused 15 byte-verified historical successful C-like outputs from TASK_146 (14) and TASK_147 (1); 5,067 new Ghidra memory bodies from 20/20 sequential read-only chunks. The analyzed TASK_147 project database was copied and rehashed. No new import occurred.
- 5,082/5,082 nonempty C-like bodies; 0 still missing or failed. 2,018 C bodies have decompiler warnings. Capstone decoded 336,380 source instructions; Ghidra listed 308,373 instruction addresses, with 3,512/5,082 full symbol-body listings and 0 listing/flow alignment discrepancies.
- Source-verified Ghidra transfers: 25234 bl, 2871 blr, 1346 tail b, 0 br. 509 spread ordinary records (10.0%) were rechecked against source bytes again.

## Provenance and limits

- Historical TASK_147 applyLayer at VA 0x3f94fc used an isolated 180s decompile timeout. It is copied as historical evidence; current TASK_169 processes cap decompilation at 15s per new function. Original TASK_146 import elapsed 786.897s; this revision reused its analyzed project and did not repeat that import.
- C-like text and aligned assembly are static evidence. Warnings, partial listings, non-exported functions, linked providers, indirect dispatch, model/material data and physical device behavior remain open in worker_source_verification.json.
- TASK_063 remains BLOCKED and TASK_064A-G/065/066 remain PLANNED. No self-review, commit/push or product gate change.
