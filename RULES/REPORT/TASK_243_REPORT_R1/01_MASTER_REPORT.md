# TASK_243 R1 — libPVGImageCodec internal FDE research

Status: **BOUNDED_PARTIAL_RESEARCH_CANDIDATE**, awaiting independent CEO review.

The pinned original `.so` SHA-256 `7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b` has 9,981 unwind FDE starts and 3,326 distinct nonzero defined `.dynsym` function export VAs. This task selected all 512 ordinary global indices 5633-6144 of 6,655 FDE starts absent from those exports; **there are no oversized skips in this slice**. Earlier unresolved or separately reviewed oversized cases retain the dispositions in their own tasks. This selection does not overlap TASK_234 through TASK_242. Each selected executable PT_LOAD span and SHA-256 was rechecked against the original file. Capstone decoded 156,576 original bytes / 39,144 AArch64 instruction slots.

One read-only Ghidra process from a private byte-verified copy of the accepted TASK_216 project completed in 23.865 seconds. Each decompile was capped at 15 seconds; raw command/logs and 512 individual outputs are under `ghidra/`. The accepted original project hashes remain unchanged.

The Ghidra run matched original memory for 512/512 selected spans and emitted 512/512 nonempty C-like texts. It listed 39,144/39,144 source-aligned instruction starts; 39,043 slots had p-code (119,409 p-code ops). Full function-body membership versus the FDE span was **exact for 506** and **boundary-limited for 6**, missing 348 FDE bytes from those Ghidra bodies. 187 C-like texts contain Ghidra `WARNING:` output. A second original-byte/hash/decode check covered 53/512 spread records (10.4%). Boundary-limited candidate indices: 6117, 6122, 6133, 6135, 6143, 6144.

An unwind FDE is a candidate range, not proof of an entire source function. Nonempty C-like output, even with all original instructions listed, is not validated algorithm behavior. Boundary-limited texts require special care; neither this task nor accepted TASK_216 proves internal-function completeness, codec behavior, product Phase PASS, device parity or V4 readiness. No source, P0 or product file was edited; no commit/push or self-review was performed.
