# TASK_214 R1 — libAIModelSearchKit internal FDE research

Status: **BOUNDED_PARTIAL_RESEARCH_CANDIDATE**, awaiting independent CEO review.

The pinned original `.so` SHA-256 `20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899` has 2,129 unwind FDE starts and 1,231 distinct nonzero defined `.dynsym` function export VAs. This task selected global indices 128-255, the next 128 of 898 FDE starts absent from those exports; 642 remain unselected. The selected VAs do not overlap TASK_212, and the manifest skipped no oversized candidate in this prefix. Each selected PT_LOAD span and SHA-256 was rechecked against the original file. Capstone decoded 66,020 original bytes / 16,505 AArch64 instruction slots.

One read-only Ghidra process from a private byte-verified copy of the accepted TASK_157 project completed in 16.414 seconds. Raw command/logs and 128 individual outputs are under `ghidra/`. The accepted original project hashes remain unchanged.

The Ghidra run matched original memory for 128/128 selected spans and emitted 128/128 nonempty C-like texts. It listed 16,505/16,505 source-aligned instruction starts; 16,165 slots had p-code (54,510 p-code ops). Full function-body membership versus the FDE span was **exact for 52** and **boundary-limited for 76**, missing 4,980 FDE bytes from those Ghidra bodies. 10 C-like texts contain Ghidra `WARNING:` output. A second original-byte/hash/decode check covered 13/128 spread records (10.2%).

An unwind FDE is a candidate range, not proof of an entire source function. Nonempty C-like output, even with all original instructions listed, is not validated algorithm behavior. The boundary-limited texts require special care; neither this task nor accepted TASK_157 proves internal-function completeness, model behavior, product Phase PASS, device parity or V4 readiness. No source, P0 or product file was edited; no commit/push or self-review was performed.
