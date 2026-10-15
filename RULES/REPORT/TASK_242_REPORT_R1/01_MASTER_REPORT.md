# TASK_242 R1 — libPVGImageCodec internal FDE research

Status: **BOUNDED_PARTIAL_RESEARCH_CANDIDATE**, awaiting independent CEO review.

The pinned original `.so` SHA-256 `7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b` has 9,981 unwind FDE starts and 3,326 distinct nonzero defined `.dynsym` function export VAs. This task selected 505 ordinary global indices 5121-5632 of 6,655 FDE starts absent from those exports, excluding seven oversized indices: 5144, 5145, 5146, 5147, 5148, 5149, 5150. Earlier oversized skips remain unresolved unless separately reviewed. This selection does not overlap TASK_234 through TASK_241. Each selected executable PT_LOAD span and SHA-256 was rechecked against the original file. Capstone decoded 188,240 original bytes / 47,060 AArch64 instruction slots.

One read-only Ghidra process from a private byte-verified copy of the accepted TASK_216 project completed in 32.123 seconds. Each decompile was capped at 15 seconds; raw command/logs and 505 individual outputs are under `ghidra/`. The accepted original project hashes remain unchanged.

The Ghidra run matched original memory for 505/505 selected spans and emitted 505/505 nonempty C-like texts. It listed 47,060/47,060 source-aligned instruction starts; 46,828 slots had p-code (148,171 p-code ops). Full function-body membership versus the FDE span was **exact for 505** and **boundary-limited for 0**, missing 0 FDE bytes from those Ghidra bodies. 164 C-like texts contain Ghidra `WARNING:` output. A second original-byte/hash/decode check covered 51/505 spread records (10.1%).

An unwind FDE is a candidate range, not proof of an entire source function. Nonempty C-like output, even with all original instructions listed, is not validated algorithm behavior. Boundary-limited texts require special care; neither this task nor accepted TASK_216 proves internal-function completeness, codec behavior, product Phase PASS, device parity or V4 readiness. No source, P0 or product file was edited; no commit/push or self-review was performed.
