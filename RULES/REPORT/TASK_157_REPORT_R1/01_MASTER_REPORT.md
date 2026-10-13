# TASK_157 R1 - libAIModelSearchKit exported-function recovery

Status: **BOUNDED_RESEARCH_CANDIDATE awaiting independent CEO review**. Tony assigned a real Codex subagent; no AGY. This pass is export-complete only if every selected C-like body was recovered; it does not include all static/internal code or prove product Phase PASS/V4/P7.

## Observed

- Original `libAIModelSearchKit.so` SHA-256 `20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899` has 1,412 defined nonzero-size `.dynsym` names at 1,231 unique VAs. All 1,231 original PT_LOAD body hashes were rechecked. One fresh Ghidra project was imported in TASK_157 scratch.
- 5/5 sequential 1-CPU/1-GiB read-only Ghidra chunks produced parseable output; 1231/1,231 nonempty C-like bodies were recovered. 0 selected VAs remain without recovered C. Raw commands/logs and each body are in chunk folders.
- Capstone decoded 61,423 original AArch64 instructions; 1231/1,231 symbol bodies decoded through full size. Ghidra listed 56,135 source-aligned instruction addresses and fully listed 911/1,231 bodies. Source-verified Ghidra flow transfers: 3382 `bl`, 678 `blr`, 296 tail `b`, 0 `br`. Ghidra C text emitted warnings in 316 bodies. 124 spread-out ordinary records (10.1%) received a second source hash comparison.

## Inferred

- The C-like bodies are a static research map for AI model search. Export names or decompiler output alone cannot establish model routing behavior, parameter range, or device output.

## Unknown / blocked input

- Non-exported code, imported providers, model data, indirect dispatch and physical-device execution require separate work. Any failed C bodies and partial Ghidra instruction listings remain explicit in `worker_source_verification.json`.
- TASK_063 remains BLOCKED and TASK_064A-G/065/066 remain PLANNED. No CEO self-ack ACCEPTED or unreviewed commit/push.
