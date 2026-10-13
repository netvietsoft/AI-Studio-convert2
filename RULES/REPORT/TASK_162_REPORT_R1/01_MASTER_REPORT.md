# TASK_162 R1 — static export recovery candidate

Status: **COMPLETE_CANDIDATE**. Independent CEO review pending.

| Original SO | Pinned export VAs | Ghidra memory matched | C-like bodies | Chunk outputs |
|---|---:|---:|---:|---:|
| `libhiai_ir.so` | 1002 | 1002 | 1002 | 8/8 |
| `libkoom-strip-dump.so` | 668 | 668 | 668 | 6/6 |

All 1670 original ELF/PT_LOAD bodies were rehashed; 168 evenly spread source-assembly samples were independently regenerated.

These are static Ghidra C-like export bodies, not a count of all internal functions. No runtime behavior, product Phase PASS, V4 or P7 has been validated.

Raw source bytes/assembly, original-to-Ghidra body hashes, commands, logs and results are retained per library and chunk. See `unresolved.json` for any missing C-like output.
