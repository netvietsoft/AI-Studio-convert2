# TASK_217 R1 — libAIModelSearchKit internal FDE research

Status: **BOUNDED_PARTIAL_RESEARCH_CANDIDATE**, awaiting independent CEO review.

The pinned original `.so` SHA-256 `20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899` has 2,129 unwind FDE starts and 1,231 distinct nonzero defined `.dynsym` function export VAs. This task selected global indices 256-383, the next 128 of 898 FDE starts absent from those exports; 514 remain unselected. The selected VAs do not overlap TASK_214, and the manifest skipped no oversized candidate in this slice. Each selected PT_LOAD span and SHA-256 was rechecked against the original file. Capstone decoded 36,888 original bytes / 9,222 AArch64 instruction slots.

One read-only Ghidra process from a private byte-verified copy of the accepted TASK_157 project completed in 25.22 seconds. Raw command/logs and 128 individual outputs are under `ghidra/`. The accepted original project hashes remain unchanged.

The Ghidra run matched original memory for 128/128 selected spans and emitted 128/128 nonempty C-like texts. It listed 9,222/9,222 source-aligned instruction starts; 8,928 slots had p-code (29,230 p-code ops). Full function-body membership versus the FDE span was **exact for 69** and **boundary-limited for 59**, missing 3,380 FDE bytes from those Ghidra bodies. 41 C-like texts contain Ghidra `WARNING:` output. A second original-byte/hash/decode check covered 13/128 spread records (10.2%).

An unwind FDE is a candidate range, not proof of an entire source function. Nonempty C-like output, even with all original instructions listed, is not validated algorithm behavior. The boundary-limited texts require special care; neither this task nor accepted TASK_157 proves internal-function completeness, model behavior, product Phase PASS, device parity or V4 readiness. No source, P0 or product file was edited; no commit/push or self-review was performed.
