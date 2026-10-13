# TASK_168 R1 — four original SO export maps

Status: **BOUNDED_EXPORT_CANDIDATE; independent CEO review pending**.

| Original source | Export VAs | Ghidra memory matched | C-like bodies | Provenance |
|---|---:|---:|---:|---|
| `libARKernelInterface.so` | 635 | 635 | 635 | new 1-CPU/1-GiB Ghidra import + bounded chunks |
| `libPVGColorFunctions.so` | 81 | 81 | 81 | new 1-CPU/1-GiB Ghidra import + bounded chunks |
| `libPVGVideoCodec.so` | 160 | 160 | 160 | hash-verified historical TASK_153 raw run |
| `libffmpegfilter.so` | 216 | 216 | 216 | hash-verified historical TASK_155 raw run |

All 1092 original ELF/PT_LOAD bodies were independently rehashed. 111 evenly spread ordinary records (>=10% per source) had their source assembly regenerated and Ghidra memory SHA rechecked. The raw commands, logs, output JSON and source index are preserved per library/chunk.

262 C-like bodies contain Ghidra `WARNING:` text; 4 sampled records have partial Ghidra instruction listings. 0 export VAs remain without verified C-like output; see `unresolved.json`.

Previously recovered PVGVideo/ffmpegfilter outputs were verified against original bytes and archived unchanged, not re-imported or misrepresented as new TASK_168 runs. These are static export-level C-like bodies, not all internal functions or validated runtime behavior. No product Phase PASS, V4, P7, self-review, commit or push is claimed.
