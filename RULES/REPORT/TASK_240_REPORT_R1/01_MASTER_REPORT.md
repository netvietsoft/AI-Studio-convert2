# TASK_240 R1 — libPVGImageCodec internal FDE research

Status: **BOUNDED_PARTIAL_RESEARCH_CANDIDATE**, awaiting independent CEO review.

The pinned original `.so` SHA-256 `7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b` has 9,981 unwind FDE starts and 3,326 distinct nonzero defined `.dynsym` function export VAs. This task selected 502 ordinary global indices 4097-4608 of 6,655 FDE starts absent from those exports, excluding ten oversized indices: 4105, 4110, 4231, 4235, 4243, 4249, 4266, 4269, 4470, 4523. Earlier oversized skips remain unresolved unless separately reviewed. This selection does not overlap TASK_234 through TASK_239. Each selected executable PT_LOAD span and SHA-256 was rechecked against the original file. Capstone decoded 253,020 original bytes / 63,255 AArch64 instruction slots.

One read-only Ghidra process from a private byte-verified copy of the accepted TASK_216 project completed in 32.187 seconds. Each decompile was capped at 15 seconds; raw command/logs and 502 individual outputs are under `ghidra/`. The accepted original project hashes remain unchanged.

The Ghidra run matched original memory for 502/502 selected spans and emitted 502/502 nonempty C-like texts. It listed 63,255/63,255 source-aligned instruction starts; 63,066 slots had p-code (185,652 p-code ops). Full function-body membership versus the FDE span was **exact for 502** and **boundary-limited for 0**, missing 0 FDE bytes from those Ghidra bodies. 185 C-like texts contain Ghidra `WARNING:` output. A second original-byte/hash/decode check covered 51/502 spread records (10.2%).

An unwind FDE is a candidate range, not proof of an entire source function. Nonempty C-like output, even with all original instructions listed, is not validated algorithm behavior. Boundary-limited texts require special care; neither this task nor accepted TASK_216 proves internal-function completeness, codec behavior, product Phase PASS, device parity or V4 readiness. No source, P0 or product file was edited; no commit/push or self-review was performed.
