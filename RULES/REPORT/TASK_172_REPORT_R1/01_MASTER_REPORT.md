# TASK_172 R1 - libc++_shared.so exported-function recovery

Status: **BOUNDED_RESEARCH_CANDIDATE awaiting independent CEO review**. Tony assigned a real Codex subagent; no AGY. This pass is export-complete only if every selected C-like body was recovered; it does not include all static/internal code or prove product Phase PASS/V4/P7.

## Observed

- Original `libc++_shared.so` SHA-256 `4397241b4bd20a8e579bfb41d21107857e12985f6a01ca0c2a5f83380d1270b4` has 1,582 defined nonzero-size `.dynsym` names at 1,376 unique VAs. All 1,376 original PT_LOAD body hashes were rechecked. One fresh Ghidra project was imported in TASK_172 scratch.
- 6/6 sequential 1-CPU/1-GiB read-only Ghidra chunks produced parseable output; 1376/1,376 nonempty C-like bodies were recovered. 0 selected VAs remain without recovered C. Raw commands/logs and each body are in chunk folders.
- Capstone decoded 61,395 original AArch64 instructions; 1376/1,376 symbol bodies decoded through full size. Ghidra listed 56,503 source-aligned instruction addresses and fully listed 1033/1,376 bodies. Source-verified Ghidra flow transfers: 3402 `bl`, 577 `blr`, 350 tail `b`, 0 `br`. Ghidra C text emitted warnings in 317 bodies. 138 spread-out ordinary records (10.0%) received a second source hash comparison.

## Inferred

- The C-like bodies are a static research map for the C++ shared library. Export names or decompiler output alone cannot establish runtime C++ support behavior, parameter range, or device output.

## Unknown / blocked input

- Non-exported code, imported providers, model data, indirect dispatch and physical-device execution require separate work. Any failed C bodies and partial Ghidra instruction listings remain explicit in `worker_source_verification.json`.
- TASK_063 remains BLOCKED and TASK_064A-G/065/066 remain PLANNED. No CEO self-ack ACCEPTED or unreviewed commit/push.
