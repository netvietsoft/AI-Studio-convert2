# TASK_245 R2 — static candidate closeout

**Outcome: COMPLETE_PARTIAL.** The immutable R1 package has 23 nonempty, error-free, balanced Ghidra C-like outputs. All 23 spans independently map to the pinned SO bytes and ARM64 source instructions. However, every raw result says `EXACT_GHIDRA_FUNCTION_START_FDE_BOUNDARY_UNPROVEN`. The task requires uncertain source boundaries to remain unverified, so **accepted newly counted C-like bodies: 0**. Do not add this task to the existing accepted baseline of 43,396 results across 45 SO files.

Independent parse verified 9,981 `.eh_frame` FDEs, 3,326 unique defined nonzero `.dynsym` `STT_FUNC` VAs and 6,655 nonexport FDE candidates. All 23 match one exact FDE, have no other-FDE/export-body overlap, map to exactly one executable file-backed PT_LOAD at the manifest file offset, and hash to the manifest body SHA. Independent Capstone decoded 47,066 4-byte instruction slots; each saved source word/address matched bytes, and Ghidra instruction/p-code rows cover the corresponding sequential address slots after its `+0x100000` database image-base bias.

For every raw result, Ghidra's memory hash matches source bytes and its reported function/body/membership cover exactly the FDE candidate bytes. That establishes output coverage for the span, not that the FDE represents one complete source function. The C-like text is static decompiler output, not proof of algorithm semantics or runtime behavior.

| FDE index (0-based) | Source VA | Bytes | Body SHA-256 | Capstone slots | Ghidra rows | C-like bytes | Boundary |
|---:|---:|---:|---|---:|---:|---:|---|
| 3867 | `0x39373c` | 4748 | `39cb66c3d6e4913a…` | 1187 | 1187 | 18546 | UNVERIFIED |
| 3877 | `0x397ad0` | 8316 | `24610d9e759c1b93…` | 2079 | 2079 | 24079 | UNVERIFIED |
| 4025 | `0x3aedcc` | 7256 | `5df97c29433a1664…` | 1814 | 1814 | 27371 | UNVERIFIED |
| 4051 | `0x3b3408` | 15856 | `1c6a50ed56f3de9d…` | 3964 | 3964 | 70536 | UNVERIFIED |
| 4052 | `0x3b71f8` | 11912 | `c34d987b7b1f8b9c…` | 2978 | 2978 | 48219 | UNVERIFIED |
| 4066 | `0x3bb324` | 5756 | `93c9e8d8a8a4e023…` | 1439 | 1439 | 19853 | UNVERIFIED |
| 4105 | `0x3be638` | 7108 | `8914959ef4f6a4da…` | 1777 | 1777 | 34793 | UNVERIFIED |
| 4110 | `0x3c1320` | 20184 | `c269e54c8f2018cf…` | 5046 | 5046 | 111843 | UNVERIFIED |
| 4231 | `0x3d331c` | 11976 | `1b332a913dba8d32…` | 2994 | 2994 | 51965 | UNVERIFIED |
| 4235 | `0x3d6458` | 5400 | `9cd185889130a549…` | 1350 | 1350 | 20682 | UNVERIFIED |
| 4243 | `0x3d8d80` | 7344 | `a78abe79a0321249…` | 1836 | 1836 | 24449 | UNVERIFIED |
| 4249 | `0x3daf54` | 18432 | `8341f1d34dfb769f…` | 4608 | 4608 | 65488 | UNVERIFIED |
| 4266 | `0x3e1ba4` | 8952 | `304d8ac220a52e0b…` | 2238 | 2238 | 43684 | UNVERIFIED |
| 4269 | `0x3e4514` | 4984 | `1ca7732bcc8f15c4…` | 1246 | 1246 | 16636 | UNVERIFIED |
| 4470 | `0x3fe2b0` | 4472 | `63b2355634efaa81…` | 1118 | 1118 | 18671 | UNVERIFIED |
| 4523 | `0x407cd4` | 5184 | `e431aae1c5360e2e…` | 1296 | 1296 | 16491 | UNVERIFIED |
| 5144 | `0x442538` | 5720 | `c4141c29a43d4aec…` | 1430 | 1430 | 39807 | UNVERIFIED |
| 5145 | `0x443b90` | 5720 | `fe3f5db703441f37…` | 1430 | 1430 | 37599 | UNVERIFIED |
| 5146 | `0x4451e8` | 5616 | `083192933b8ff475…` | 1404 | 1404 | 41518 | UNVERIFIED |
| 5147 | `0x4467d8` | 5616 | `15fb24a3b3cec8ed…` | 1404 | 1404 | 43174 | UNVERIFIED |
| 5148 | `0x447dc8` | 5720 | `31a87c044ece8fa1…` | 1430 | 1430 | 39282 | UNVERIFIED |
| 5149 | `0x449420` | 5976 | `017b35da81b2b7d4…` | 1494 | 1494 | 39319 | UNVERIFIED |
| 5150 | `0x44ab78` | 6016 | `d48f170b77045fda…` | 1504 | 1504 | 37730 | UNVERIFIED |

See `02_TARGET_EVIDENCE.csv` for every target, `03_INPUT_HASH_INVENTORY.csv` for full R1/control-input hashes, and `04_EVIDENCE_LEDGER.csv` for each claim disposition. Before counting any body, a separately bounded step must establish reliable source-function boundaries beyond the unwind FDE/Ghidra function declaration. No Ghidra rerun, semantic inference, source/product edit, or V4/P7 gate was performed.
