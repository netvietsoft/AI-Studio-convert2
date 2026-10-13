# TASK_186 R2 corrected research report

This report corrects R1's boundary sentence and instruction-provenance sample while preserving every R1 byte. The failed serializer attempt is retained as immutable `chunk_00`; the valid corrected retry is `chunk_00_retry1`, followed by `chunk_01` through `chunk_03`. Their hashes are in `r1_reference_inventory.json`.

Independent R2 parsing of the pinned original ELF found 81 defined nonzero-size `.dynsym` STT_FUNC export VAs, 753 unwind FDEs and 672 nonexport FDE candidates. The exact 128 targets are sorted nonexport FDE indices 128..255. All 128 original FDE/PT_LOAD body SHA-256 values match the target manifest, R1 source index and R1 raw Ghidra memory digests. Every C-like text SHA matches its raw content.

The R1 Ghidra raw rows classify **128/128** function bodies as `GHIDRA_BODY_EQUALS_FDE_RANGE`: for each pinned FDE, reported member bytes equal its size, missing bytes and extra body bytes are both zero, missing intervals are empty, and function-body address count equals FDE size. Thus **all 128 C-like texts correspond to exact pinned FDE bodies according to the R1 per-byte membership capture**. There are **zero boundary-limited exceptional rows** in this batch. This says nothing about whether an unwind FDE denotes a unique complete source function, and does not establish behavioral or pixel equivalence. R2 checks immutable Ghidra raw evidence and does not replay Ghidra.

R2 independently re-decoded **790/790** AArch64 source slots, matching original words, Capstone source assembly and Ghidra listing addresses/mnemonics. It records **79/790** distinct, deterministically spread instruction words (**10.00%**) across **57** candidates, from `0x2bbf8` through `0x2c84c`. The selection formula and each VA/word/mnemonic/operands/listing are in `instruction_verification.json`. R1's 36/790-word sample is not reused as sufficient evidence.

These are bounded static research findings. They do not authorize product Phase PASS, V4/P7, all-45-SO completion, commit or push. The CEO must independently review this R2 fingerprint.
