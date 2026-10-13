# TASK_164 R1 - libaicodec exported-function recovery

Status: **BOUNDED_RESEARCH_CANDIDATE awaiting independent CEO review**. Tony assigned a real Codex subagent; no AGY. This pass is export-complete only if every selected C-like body was recovered; it does not include all static/internal code or prove product Phase PASS/V4/P7.

## Observed

- Original `libaicodec.so` SHA-256 `f957a5b290991053f65943356816e837ae5a9d996fa0b2809fc89f680fc8a3cc` has 2,401 defined nonzero-size `.dynsym` names at 2,178 unique VAs. All 2,178 original PT_LOAD body hashes were rechecked. One fresh Ghidra project was imported in TASK_164 scratch.
- 9/9 sequential 1-CPU/1-GiB read-only Ghidra chunks produced parseable output; 2178/2,178 nonempty C-like bodies were recovered. 0 selected VAs remain without recovered C. Raw commands/logs and each body are in chunk folders.
- Capstone decoded 177,039 original AArch64 instructions; 2178/2,178 symbol bodies decoded through full size. Ghidra listed 170,662 source-aligned instruction addresses and fully listed 1784/2,178 bodies. Source-verified Ghidra flow transfers: 11396 `bl`, 1487 `blr`, 477 tail `b`, 0 `br`. Ghidra C text emitted warnings in 425 bodies. 218 spread-out ordinary records (10.0%) received a second source hash comparison.

## Inferred

- The C-like bodies are a static research map for the aicodec library. Export names or decompiler output alone cannot establish runtime codec behavior, parameter range, or device output.

## Unknown / blocked input

- Non-exported code, imported providers, model data, indirect dispatch and physical-device execution require separate work. Any failed C bodies and partial Ghidra instruction listings remain explicit in `worker_source_verification.json`.
- TASK_063 remains BLOCKED and TASK_064A-G/065/066 remain PLANNED. No CEO self-ack ACCEPTED or unreviewed commit/push.
