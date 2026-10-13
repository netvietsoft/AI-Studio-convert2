# TASK_171 R1 — five original SO export maps

Status: **BOUNDED_EXPORT_CANDIDATE; independent CEO review pending**.

| Original source | Export VAs | Ghidra memory matched | C-like bodies | Provenance |
|---|---:|---:|---:|---|
| `libARSPM.so` | 56 | 56 | 56 | hash-verified historical TASK_155 raw run |
| `libPVGLive.so` | 20 | 20 | 20 | hash-verified historical TASK_149 raw run |
| `libCtaApiLib.so` | 146 | 146 | 146 | hash-verified historical TASK_153 raw run |
| `libKKMusicFX.so` | 57 | 57 | 57 | hash-verified historical TASK_153 raw run |
| `libffavc.so` | 2 | 2 | 2 | hash-verified historical TASK_149 raw run |

All 281 original ELF/PT_LOAD bodies were independently rehashed. 31 evenly spread ordinary records (>=10% per source) had their source assembly regenerated and Ghidra memory SHA rechecked. The raw commands, logs, output JSON and source index are preserved per library.

90 C-like bodies contain Ghidra `WARNING:` text; 9 sampled records have partial Ghidra instruction listings. 0 export VAs remain without verified C-like output; see `unresolved.json`.

All five Ghidra outputs came from TASK_149/153/155 and were verified against original bytes, then archived unchanged. TASK_171 ran no new Ghidra import. These are static export-level C-like bodies, not all internal functions or validated runtime behavior. No product Phase PASS, V4, P7, self-review, commit or push is claimed.
