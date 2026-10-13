# TASK_159 R1 - libdexvmp exported-function correction

Status: **PARTIAL_RESEARCH_CANDIDATE awaiting independent CEO review**. This Codex worker corrected a TASK_156 exporter bound; AGY was not used. Static exported-function evidence does not prove the binary's runtime behavior.

## Observed

- Original `libdexvmp.so` SHA-256 `b4a46520ec989fef5346833db8f9a1bd6a6690902731414ed26f65cc529cc06e` contains 284 defined nonzero-size `.dynsym` function VAs. All 284 PT_LOAD body hashes were checked against original bytes. TASK_156's Ghidra import succeeded but its autoanalysis timed out at 480 seconds; its exporter then failed because VA 0x29cd4 is 224,440 bytes, above its 65,536-byte target guard.
- A 10-file hash-verified project copy was processed in four sequential read-only passes (100/100/83/1 VAs), with zero new imports. 4/4 passes yielded parseable output. 284/284 Ghidra-memory bodies matched original source hashes; 283/284 yielded nonempty C-like text. Isolated oversized target index232: memory match=True, C-like recovered=False, error=`Exception while decompiling 00129cd4: process: timeout
`.
- Full original source bytes were retained by hash and disassembled word-by-word: 86,585 AArch64 words decoded and 193 undecoded words explicitly marked. Ghidra listed 29,848 source-aligned instruction addresses and 1,030 source-opcode-verified flow transfers. 29/284 spread function records (10.2%) received a separate source-body rehash. C output contains Ghidra warnings in 118 recovered bodies.

## Inferred

- These results are a bounded static export map. Obfuscated names, partial prior autoanalysis and decompiler warnings limit semantic use. The source assembly file is complete as bytes and address labels, while undecoded words are not asserted to be instructions.

## Unknown / blocked input

- Internal non-exported functions, dynamic dispatch, imported implementations, runtime behavior and pixel formulas are not established. Missing C bodies and partial Ghidra listings are itemized in `independent_verification.json`.
- TASK_063 remains BLOCKED; TASK_064A-G/065/066 remain PLANNED. No product Phase PASS, V4/P7 production, self-review, or unreviewed commit/push is claimed.
