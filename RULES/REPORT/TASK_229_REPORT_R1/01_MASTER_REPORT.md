# TASK_229 R1 — libAIModelSearchKit internal FDE research

Status: **BOUNDED_PARTIAL_RESEARCH_CANDIDATE**, awaiting independent CEO review.

The pinned original `.so` SHA-256 `20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899` has 2,129 unwind FDE starts and 1,231 distinct nonzero defined `.dynsym` function export VAs. This task selected 128 global indices 770-897 of 898 FDE starts absent from those exports; no candidate was skipped in this slice and no ordinary candidate remains after index 897. Earlier oversized indices 493 (`0xd239c`, 4,996 bytes) and 549 (`0xd75e8`, 5,136 bytes) remain pending, so this is not complete nonexport-function research. The selected VAs do not overlap TASK_226. Each selected PT_LOAD span and SHA-256 was rechecked against the original file. Capstone decoded 32,128 original bytes / 8,032 AArch64 instruction slots.

One read-only Ghidra process from a private byte-verified copy of the accepted TASK_157 project completed in 18.973 seconds. Raw command/logs and 128 individual outputs are under `ghidra/`. The accepted original project hashes remain unchanged.

The Ghidra run matched original memory for 128/128 selected spans and emitted 128/128 nonempty C-like texts. It listed 8,032/8,032 source-aligned instruction starts; 7,650 slots had p-code (26,338 p-code ops). Full function-body membership versus the FDE span was **exact for 121** and **boundary-limited for 7**, missing 96 FDE bytes from those Ghidra bodies. 59 C-like texts contain Ghidra `WARNING:` output. A second original-byte/hash/decode check covered 13/128 spread records (10.2%).

An unwind FDE is a candidate range, not proof of an entire source function. Nonempty C-like output, even with all original instructions listed, is not validated algorithm behavior. The boundary-limited texts require special care; neither this task nor accepted TASK_157 proves internal-function completeness, model behavior, product Phase PASS, device parity or V4 readiness. No source, P0 or product file was edited; no commit/push or self-review was performed.
