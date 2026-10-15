# TASK_212 R1 — libAIModelSearchKit internal FDE research

Status: **BOUNDED_PARTIAL_RESEARCH_CANDIDATE**, awaiting independent CEO review.

The pinned original `.so` SHA-256 `20233f05b4b010280d16e728103a0995ca2580697b5f9c708fa333e9ff8d1899` has 2,129 unwind FDE starts and 1,231 distinct nonzero defined `.dynsym` function export VAs. This task selected the first 128 of 898 FDE starts absent from those exports; 770 remain unselected. Each selected PT_LOAD span and SHA-256 was rechecked against the original file. Capstone decoded 25,340 original bytes / 6,335 AArch64 instruction slots.

The first read-only Ghidra attempt exited 0 yet produced **zero** candidate records because its task-owned Java script had a UTF-8 BOM; the raw compile error and command are retained under `ghidra/`. After removing that BOM, one corrected read-only process from a private byte-verified copy of the accepted TASK_157 project completed in 17.625 seconds. Raw command/logs and 128 individual outputs are under `ghidra_retry01/`. The accepted original project hashes remain unchanged.

The corrected Ghidra run matched original memory for 128/128 selected spans and emitted 128/128 nonempty C-like texts. It listed 6,335/6,335 source-aligned instruction starts; 6,173 slots had p-code (19,863 p-code ops). Full function-body membership versus the FDE span was **exact for 85** and **boundary-limited for 43**, missing 3,760 FDE bytes from those Ghidra bodies. 45 C-like texts contain Ghidra `WARNING:` output. A second original-byte/hash/decode check covered 13/128 spread records (10.2%).

An unwind FDE is a candidate range, not proof of an entire source function. Nonempty C-like output, even with all original instructions listed, is not validated algorithm behavior. The 43 boundary-limited texts require special care; neither this task nor accepted TASK_157 proves internal-function completeness, model behavior, product Phase PASS, device parity or V4 readiness. No source, P0 or product file was edited; no commit/push or self-review was performed.
