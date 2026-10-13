# TASK_166 R1 - libhiai.so exported-function recovery

Status: **BOUNDED_RESEARCH_CANDIDATE awaiting independent CEO review**. Tony assigned a real Codex subagent; no AGY. This pass is export-complete only if every selected C-like body was recovered; it does not include all static/internal code or prove product Phase PASS/V4/P7.

## Observed

- Original `libhiai.so` SHA-256 `30a096c17346403d98a32a1a4d0762fa8e220f6c40e65aec9460cdfd6c7418ee` has 366 defined nonzero-size `.dynsym` names at 343 unique VAs. All 343 original PT_LOAD body hashes were rechecked. One fresh Ghidra project was imported in this source's TASK_166 scratch.
- 2/2 sequential 1-CPU/1-GiB read-only Ghidra chunks produced parseable output; 343/343 nonempty C-like bodies were recovered. 0 selected VAs remain without recovered C. Raw commands/logs and each body are in chunk folders.
- Capstone decoded 10,724 original AArch64 instructions; 343/343 symbol bodies decoded through full size. Ghidra listed 10,724 source-aligned instruction addresses and fully listed 343/343 bodies. Source-verified Ghidra flow transfers: 1053 `bl`, 35 `blr`, 135 tail `b`, 0 `br`. Ghidra C text emitted warnings in 184 bodies. 35 spread-out ordinary records (10.2%) received a second source hash comparison.

## Inferred

- The C-like bodies are a static research map for this source. Export names or decompiler output alone cannot establish behavior, parameter range, or device output.

## Unknown / blocked input

- Non-exported code, imported providers, model data, indirect dispatch and physical-device execution require separate work. Any failed C bodies and partial Ghidra instruction listings remain explicit in `worker_source_verification.json`.
- TASK_063 remains BLOCKED and TASK_064A-G/065/066 remain PLANNED. No CEO self-ack ACCEPTED or unreviewed commit/push.
