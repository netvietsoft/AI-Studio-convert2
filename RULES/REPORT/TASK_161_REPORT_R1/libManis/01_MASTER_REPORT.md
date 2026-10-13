# TASK_161 R1 - libManis.so exported-function recovery

Status: **BOUNDED_RESEARCH_CANDIDATE awaiting independent CEO review**. Tony assigned a real Codex subagent; no AGY. This pass is export-complete only if every selected C-like body was recovered; it does not include all static/internal code or prove product Phase PASS/V4/P7.

## Observed

- Original `libManis.so` SHA-256 `19daf9b4b1718c843169d68391e99a27d10bd3cece52226c887c3ab9b93dddc2` has 287 defined nonzero-size `.dynsym` names at 266 unique VAs. All 266 original PT_LOAD body hashes were rechecked. One fresh Ghidra project was imported in this source's TASK_161 scratch.
- 2/2 sequential 1-CPU/1-GiB read-only Ghidra chunks produced parseable output; 266/266 nonempty C-like bodies were recovered. 0 selected VAs remain without recovered C. Raw commands/logs and each body are in chunk folders.
- Capstone decoded 24,733 original AArch64 instructions; 266/266 symbol bodies decoded through full size. Ghidra listed 24,733 source-aligned instruction addresses and fully listed 266/266 bodies. Source-verified Ghidra flow transfers: 1521 `bl`, 55 `blr`, 69 tail `b`, 0 `br`. Ghidra C text emitted warnings in 108 bodies. 27 spread-out ordinary records (10.2%) received a second source hash comparison.

## Inferred

- The C-like bodies are a static research map for this source. Export names or decompiler output alone cannot establish behavior, parameter range, or device output.

## Unknown / blocked input

- Non-exported code, imported providers, model data, indirect dispatch and physical-device execution require separate work. Any failed C bodies and partial Ghidra instruction listings remain explicit in `worker_source_verification.json`.
- TASK_063 remains BLOCKED and TASK_064A-G/065/066 remain PLANNED. No CEO self-ack ACCEPTED or unreviewed commit/push.
