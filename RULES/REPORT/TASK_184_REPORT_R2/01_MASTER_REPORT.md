# TASK_184 R2 — corrected VERenderer body coverage

The R1 extraction remains static evidence for 141 pinned FDE candidates, but its full-body coverage count was wrong. R2 checks the entire Ghidra function address set, including interior gaps, and corrects the result to **135 exact / 6 nonexact**. The sixth case is candidate 96 at ELF VA `0x5d6e4`: its 436-byte FDE has only 392 bytes in the Ghidra function body, with 44 interior bytes / 11 words missing despite matching min/max endpoints.

Original SO SHA-256 `2da896556822804506871c47fadda3fadf8537952e38642e6c496ccbbab8ca46`; target manifest SHA-256 `0b11084f86a80398343bd576843dfdabf7f697b7d8a31aa652ad452c6d071a0b`; immutable R1 seal SHA-256 `20cfdf5ee2cdde243e05eab839b2df4f15e5e1199f85a402be2c4cc3dd35fa27`. The R2 read-only Ghidra body-membership pass used a byte-verified project copy, zero imports, 1 CPU/1 GiB, and completed in 15.814s. Raw command, logs, 141 membership rows and each omitted word's original bytes/SHA-256 are retained.

## Corrected coverage

The 141 original FDE spans total 30,644 bytes / 7,661 AArch64 instruction slots. Ghidra function body membership includes 30,408 of those bytes / 7,602 slots; 236 bytes / 59 slots are outside the six function bodies. The R1 listing still has 7,661 decoded instruction slots, 7,396 p-code-bearing slots and 141 nonempty C-like texts, but only 135 of those C-like texts correspond to Ghidra bodies that include their entire pinned FDE span. The six remaining C-like texts are explicitly **boundary-limited**.

- Candidate 8 `0x3ce80`: 40 FDE bytes / 10 AArch64 words absent from Ghidra function body; missing word VA extent `0x3cf7c`–`0x3cfa0`.
- Candidate 14 `0x3f08c`: 20 FDE bytes / 5 AArch64 words absent from Ghidra function body; missing word VA extent `0x3f0c8`–`0x3f0d8`.
- Candidate 17 `0x3f120`: 20 FDE bytes / 5 AArch64 words absent from Ghidra function body; missing word VA extent `0x3f15c`–`0x3f16c`.
- Candidate 46 `0x491dc`: 4 FDE bytes / 1 AArch64 words absent from Ghidra function body; missing word VA extent `0x49340`–`0x49340`.
- Candidate 95 `0x5d54c`: 108 FDE bytes / 27 AArch64 words absent from Ghidra function body; missing word VA extent `0x5d674`–`0x5d6e0`.
- Candidate 96 `0x5d6e4`: 44 FDE bytes / 11 AArch64 words absent from Ghidra function body; missing word VA extent `0x5d868`–`0x5d890`.

Candidate 96's 11 missing word starts are `0x5d868, 0x5d86c, 0x5d870, 0x5d874, 0x5d878, 0x5d87c, 0x5d880, 0x5d884, 0x5d888, 0x5d88c, 0x5d890`. `missing_instruction_evidence.json` records each word's original file offset, 4 source bytes, SHA-256 and independent AArch64 decode. `candidate_096_corrected.json` retains its exact R1 C-like text while overriding the mistaken empty boundary classification in R2.

All 141 original PT_LOAD body hashes, FDE header starts and R2 owned-project memory hashes were cross-checked. Twenty evenly spread candidates (14.2%) had every source instruction word re-decoded (997 words). R2 membership agrees with the CEO's independent replay for all 141 entries. Immutable R1 report files and both Ghidra projects were unchanged.

An unwind FDE is a candidate range, not a guaranteed complete internal function boundary. Ghidra's C-like output is not verified source equivalence, runtime behavior or pixel parity. This correction does not assert product Phase PASS, V4/P7, or completion of all 45 SOs. Awaiting independent CEO review; worker verification is not approval.
