# TASK_173 R1 — two FFmpeg NEON correction attempts

**Disposition:** PARTIAL_STATIC_RESEARCH_CANDIDATE. CEO review pending. No product Phase PASS or V4 claim.

Pinned original libffmpeg.so SHA-256 `d8df8c5cb7a6b5a7eb771782d74a38e0b8d3cfacd1fbef1ae67a96171e3325c9`; accepted TASK_170 report SHA-256 `03c9e94b2363ca7108d9c78ea5f1d602a6e1c7dbe5ba2aa335443cf651772e20`. Both original PT_LOAD bodies and all 242 AArch64 instructions were independently decoded and matched to the copied Ghidra program's full instruction ranges and raw p-code PCs. The 9-file analyzed project copy remained byte-identical to the prior project.

One read-only, no-analysis Ghidra `normalize` attempt ran per target, with one CPU and 1 GiB heap. Both decompiles completed and produced raw plus normalized p-code but no C-like body. There were no retries, reimports, or full-library scans.

| Index | Original VA | Original body | Raw p-code ops | Normalized ops | Attempt wall time | Result |
|---:|---|---|---:|---:|---:|---|
| 2283 | 0x658fe8 | `94017dc1deb91f10d8a4fd18f131f5d7741d0512c73c533de6d9845fbe095cee` | 2350 | 3028 | 14.546s | manual register-level fallback only |
| 2330 | 0x65aea8 | `0b7e289d57ad0368923c5a802869b755b47eb70e43ff290fcd1096388ca46439` | 995 | 1377 | 12.402s | manual register-level fallback only |

`manual_register_pseudocode.md` contains the separately labeled fallback, with exact instruction-address references. `source_assembly_*.txt`, `instruction_verification_*.json`, `alternative_*_raw.json`, command receipts, stdout and stderr are the primary provenance. The manual interpretation is static and has not been compiled or tested against native behavior. The two targets therefore remain unresolved for C-like recovery and product purposes.
