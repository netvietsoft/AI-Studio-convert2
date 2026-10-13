# TASK_176 R1 — static export evidence revalidation

The pinned original `libbmpKit.so` and `libfftw3.so` contain 316 and 367 unique, defined, nonzero-size `.dynsym` STT_FUNC export VAs respectively. All 683 original PT_LOAD function bodies, historical TASK_156 C-like bodies and fresh Ghidra memory bodies were cross-checked against the original bytes. This is **revalidated historical research**, with zero fresh imports and zero fresh decompilations. TASK_156's earlier report was not treated as approved.

Independent ARM64 decoding checked 23900 historical instruction addresses, 1813 direct call/tail-branch targets and 60 indirect call sites against pinned original bytes. A deterministic index-spread sample of 83/683 exports (12.15%) received per-row C-like hashes and instruction/call receipts, in addition to the complete 683-row critical checks. The copied Ghidra program database bytes were unchanged after read-only inspection; Ghidra altered only ephemeral project index/journal metadata, recorded in each independent verification file.

The recovered material is static, Ghidra-generated C-like pseudocode for these exported VAs. It does not establish behavioral equivalence, all internal-function coverage, product integration, Phase PASS, or V4 readiness. Independent CEO review remains required.
