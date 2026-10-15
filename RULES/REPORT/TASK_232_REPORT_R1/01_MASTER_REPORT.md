# TASK_232 R1 — libAIModelSearchKit internal FDE research

Status: **BOUNDED_PARTIAL_RESEARCH_CANDIDATE**, awaiting independent CEO review.

The pinned original `.so` SHA-256 `20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899` has 2,129 unwind FDE starts and 1,231 distinct nonzero defined `.dynsym` function export VAs. This task selected the two previously deferred oversized FDE candidates: global index 493 (`0xd239c`, 4,996 bytes) and 549 (`0xd75e8`, 5,136 bytes). They do not overlap prior ordinary batches. Each selected PT_LOAD span and SHA-256 was rechecked against the original file. Capstone decoded 10,132 original bytes / 2,533 AArch64 instruction slots. All 898 nonexport FDE candidates now have a bounded static research attempt; this does not establish complete source-function recovery.

One read-only Ghidra process from a private byte-verified copy of the accepted TASK_157 project completed in 14.565 seconds. Each decompile was capped at 15 seconds; raw command/logs and two individual outputs are under `ghidra/`. The accepted original project hashes remain unchanged.

The Ghidra run matched original memory for 2/2 selected spans and emitted 2/2 nonempty C-like texts. It listed 2,533/2,533 source-aligned instruction starts; 2,444 slots had p-code (8,048 p-code ops). Full function-body membership versus the FDE span was **exact for 2** and **boundary-limited for 0**, missing 0 FDE bytes from those Ghidra bodies. 2 C-like texts contain Ghidra `WARNING:` output. A second original-byte/hash/decode check covered both records (100%).

An unwind FDE is a candidate range, not proof of an entire source function. Nonempty C-like output, even with all original instructions listed, is not validated algorithm behavior. The boundary-limited texts require special care; neither this task nor accepted TASK_157 proves internal-function completeness, model behavior, product Phase PASS, device parity or V4 readiness. No source, P0 or product file was edited; no commit/push or self-review was performed.
