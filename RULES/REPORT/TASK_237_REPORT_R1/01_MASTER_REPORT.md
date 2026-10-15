# TASK_237 R1 — libPVGImageCodec internal FDE research

Status: **BOUNDED_PARTIAL_RESEARCH_CANDIDATE**, awaiting independent CEO review.

The pinned original `.so` SHA-256 `7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b` has 9,981 unwind FDE starts and 3,326 distinct nonzero defined `.dynsym` function export VAs. This task selected 507 ordinary global indices 3073-3584 of 6,655 FDE starts absent from those exports, excluding oversized indices 3106, 3132, 3134, 3285 and 3523. TASK_234 and TASK_235 also deferred indices 2293, 2775 and 2776; TASK_236 separately researched the seven TASK_231 oversized indices. This selection does not overlap TASK_234/235/236. Each selected executable PT_LOAD span and SHA-256 was rechecked against the original file. Capstone decoded 149,400 original bytes / 37,350 AArch64 instruction slots.

One read-only Ghidra process from a private byte-verified copy of the accepted TASK_216 project completed in 36.184 seconds. Each decompile was capped at 15 seconds; raw command/logs and 507 individual outputs are under `ghidra/`. The accepted original project hashes remain unchanged.

The Ghidra run matched original memory for 507/507 selected spans and emitted 507/507 nonempty C-like texts. It listed 37,350/37,350 source-aligned instruction starts; 37,336 slots had p-code (130,823 p-code ops). Full function-body membership versus the FDE span was **exact for 350** and **boundary-limited for 157**, missing 6,224 FDE bytes from those Ghidra bodies. 159 C-like texts contain Ghidra `WARNING:` output. A second original-byte/hash/decode check covered 51/507 spread records (10.1%).

An unwind FDE is a candidate range, not proof of an entire source function. Nonempty C-like output, even with all original instructions listed, is not validated algorithm behavior. Boundary-limited texts require special care; neither this task nor accepted TASK_216 proves internal-function completeness, codec behavior, product Phase PASS, device parity or V4 readiness. No source, P0 or product file was edited; no commit/push or self-review was performed.
