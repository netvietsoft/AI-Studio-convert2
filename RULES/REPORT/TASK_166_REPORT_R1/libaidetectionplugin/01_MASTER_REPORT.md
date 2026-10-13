# TASK_166 R1 - libaidetectionplugin.so exported-function recovery

Status: **BOUNDED_RESEARCH_CANDIDATE awaiting independent CEO review**. Tony assigned a real Codex subagent; no AGY. This pass is export-complete only if every selected C-like body was recovered; it does not include all static/internal code or prove product Phase PASS/V4/P7.

## Observed

- Original `libaidetectionplugin.so` SHA-256 `910ef898f457cac694080829b8f7b219ae6cc696f5adebe90beca9a70c0deda8` has 477 defined nonzero-size `.dynsym` names at 436 unique VAs. All 436 original PT_LOAD body hashes were rechecked. One fresh Ghidra project was imported in this source's TASK_166 scratch.
- 2/2 sequential 1-CPU/1-GiB read-only Ghidra chunks produced parseable output; 436/436 nonempty C-like bodies were recovered. 0 selected VAs remain without recovered C. Raw commands/logs and each body are in chunk folders.
- Capstone decoded 50,270 original AArch64 instructions; 436/436 symbol bodies decoded through full size. Ghidra listed 47,362 source-aligned instruction addresses and fully listed 318/436 bodies. Source-verified Ghidra flow transfers: 4633 `bl`, 159 `blr`, 160 tail `b`, 0 `br`. Ghidra C text emitted warnings in 196 bodies. 44 spread-out ordinary records (10.1%) received a second source hash comparison.

## Inferred

- The C-like bodies are a static research map for this source. Export names or decompiler output alone cannot establish behavior, parameter range, or device output.

## Unknown / blocked input

- Non-exported code, imported providers, model data, indirect dispatch and physical-device execution require separate work. Any failed C bodies and partial Ghidra instruction listings remain explicit in `worker_source_verification.json`.
- TASK_063 remains BLOCKED and TASK_064A-G/065/066 remain PLANNED. No CEO self-ack ACCEPTED or unreviewed commit/push.
