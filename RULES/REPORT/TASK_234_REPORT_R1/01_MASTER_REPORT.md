# TASK_234 R1 — libPVGImageCodec internal FDE research

Status: **BOUNDED_PARTIAL_RESEARCH_CANDIDATE**, awaiting independent CEO review.

The pinned original `.so` SHA-256 `7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b` has 9,981 unwind FDE starts and 3,326 distinct nonzero defined `.dynsym` function export VAs. This task selected 511 ordinary global indices 2049-2560 of 6,655 FDE starts absent from those exports, excluding oversized index 2293 (`0x2bed18`, 5,056 bytes). The seven oversized indices deferred in TASK_231 also remain pending. This selection does not overlap TASK_231. Each selected executable PT_LOAD span and SHA-256 was rechecked against the original file. Capstone decoded 124,564 original bytes / 31,141 AArch64 instruction slots.

One read-only Ghidra process from a private byte-verified copy of the accepted TASK_216 project completed in 27.237 seconds. Each decompile was capped at 15 seconds; raw command/logs and 511 individual outputs are under `ghidra/`. The accepted original project hashes remain unchanged.

The Ghidra run matched original memory for 511/511 selected spans and emitted 511/511 nonempty C-like texts. It listed 31,141/31,141 source-aligned instruction starts; 31,133 slots had p-code (109,017 p-code ops). Full function-body membership versus the FDE span was **exact for 309** and **boundary-limited for 202**, missing 12,816 FDE bytes from those Ghidra bodies. 139 C-like texts contain Ghidra `WARNING:` output. A second original-byte/hash/decode check covered 52/511 spread records (10.2%).

An unwind FDE is a candidate range, not proof of an entire source function. Nonempty C-like output, even with all original instructions listed, is not validated algorithm behavior. Boundary-limited texts require special care; neither this task nor accepted TASK_216 proves internal-function completeness, codec behavior, product Phase PASS, device parity or V4 readiness. No source, P0 or product file was edited; no commit/push or self-review was performed.
