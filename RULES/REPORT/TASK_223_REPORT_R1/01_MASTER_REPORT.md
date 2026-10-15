# TASK_223 R1 — libAIModelSearchKit internal FDE research

Status: **BOUNDED_PARTIAL_RESEARCH_CANDIDATE**, awaiting independent CEO review.

The pinned original `.so` SHA-256 `20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899` has 2,129 unwind FDE starts and 1,231 distinct nonzero defined `.dynsym` function export VAs. This task selected 128 global indices 513-641 of 898 FDE starts absent from those exports, excluding oversized global index 549 (`0xd75e8`, 5,136 bytes), which remains pending. Earlier oversized index 493 (`0xd239c`, 4,996 bytes) also remains pending. After index 641, another 256 are unselected; 258 total remain pending including both oversized spans. The selected VAs do not overlap TASK_220. Each selected PT_LOAD span and SHA-256 was rechecked against the original file. Capstone decoded 39,260 original bytes / 9,815 AArch64 instruction slots.

One read-only Ghidra process from a private byte-verified copy of the accepted TASK_157 project completed in 24.546 seconds. Raw command/logs and 128 individual outputs are under `ghidra/`. The accepted original project hashes remain unchanged.

The Ghidra run matched original memory for 128/128 selected spans and emitted 128/128 nonempty C-like texts. It listed 9,815/9,815 source-aligned instruction starts; 9,516 slots had p-code (33,700 p-code ops). Full function-body membership versus the FDE span was **exact for 115** and **boundary-limited for 13**, missing 392 FDE bytes from those Ghidra bodies. 86 C-like texts contain Ghidra `WARNING:` output. A second original-byte/hash/decode check covered 13/128 spread records (10.2%).

An unwind FDE is a candidate range, not proof of an entire source function. Nonempty C-like output, even with all original instructions listed, is not validated algorithm behavior. The boundary-limited texts require special care; neither this task nor accepted TASK_157 proves internal-function completeness, model behavior, product Phase PASS, device parity or V4 readiness. No source, P0 or product file was edited; no commit/push or self-review was performed.
