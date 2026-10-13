# TASK_161 R1 - libmanis_npu_adapter.so exported-function recovery

Status: **BOUNDED_RESEARCH_CANDIDATE awaiting independent CEO review**. Tony assigned a real Codex subagent; no AGY. This pass is export-complete only if every selected C-like body was recovered; it does not include all static/internal code or prove product Phase PASS/V4/P7.

## Observed

- Original `libmanis_npu_adapter.so` SHA-256 `99a9a4b161b9797d7cf621e93a51a7df408f80c84e652bbc6724eef7e71ca6f3` has 1,003 defined nonzero-size `.dynsym` names at 996 unique VAs. All 996 original PT_LOAD body hashes were rechecked. One fresh Ghidra project was imported in this source's TASK_161 scratch.
- 4/4 sequential 1-CPU/1-GiB read-only Ghidra chunks produced parseable output; 996/996 nonempty C-like bodies were recovered. 0 selected VAs remain without recovered C. Raw commands/logs and each body are in chunk folders.
- Capstone decoded 117,077 original AArch64 instructions; 996/996 symbol bodies decoded through full size. Ghidra listed 106,085 source-aligned instruction addresses and fully listed 541/996 bodies. Source-verified Ghidra flow transfers: 6661 `bl`, 469 `blr`, 439 tail `b`, 0 `br`. Ghidra C text emitted warnings in 546 bodies. 100 spread-out ordinary records (10.0%) received a second source hash comparison.

## Inferred

- The C-like bodies are a static research map for this source. Export names or decompiler output alone cannot establish behavior, parameter range, or device output.

## Unknown / blocked input

- Non-exported code, imported providers, model data, indirect dispatch and physical-device execution require separate work. Any failed C bodies and partial Ghidra instruction listings remain explicit in `worker_source_verification.json`.
- TASK_063 remains BLOCKED and TASK_064A-G/065/066 remain PLANNED. No CEO self-ack ACCEPTED or unreviewed commit/push.
