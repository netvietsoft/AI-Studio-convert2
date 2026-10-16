# TASK_246 R2 — R1 static evidence closeout

## Result

`COMPLETE_PARTIAL`. The R1 raw package contains two source-matched static-analysis candidates spanning 8,182 ARM64 instruction words. Independent validation found **0 newly accepted C-like function bodies**. Do not add either target to the accepted C-like function total. CFG and p-code are reported as static evidence only.

The two records are FDE-derived ranges, not established function boundaries. In both raw Ghidra candidate records the function body differs from the FDE span, decompilation is false, the pseudocode and pseudocode hash are empty, and the recorded error states the earlier full-FDE decompilation timed out. Both CFG records report source-instruction coverage without gaps, yet each also reports uncovered high-level behavior for its target. This is not complete algorithm recovery.

## Independent checks

- The pinned original `libPVGImageCodec.so` and repository copy have SHA-256 `7745f3a95ec533332c96aff8d8d8c11d18e3011109741562bf3b319d3842fb1b` and are byte-identical.
- Independently parsed ELF64 program headers place both candidate file spans inside the file-backed executable `PT_LOAD` mapping, with file offset equal to virtual address for these spans.
- For candidate 3134 at VA/file offset `0x2f14dc`, 16,036 bytes hash to `c04da7a07597f25f5575904641c22c7945570538b704028f29f6bff0d5dc43ea`; each of its 4,009 four-byte words matches the corresponding source bytes and disassembly slot.
- For candidate 3285 at VA/file offset `0x324d60`, 16,692 bytes hash to `5cf6fbde3b91d51f6520a846b5a3496c4046057789645c3846e6d5b234c279b`; each of its 4,173 four-byte words matches the corresponding source bytes and disassembly slot.
- The candidate instruction and p-code arrays each contain one correctly mapped entry per source slot (8,182 total). CFG blocks partition the same slots exactly once: 948 blocks / 4,009 slots for 3134 and 943 blocks / 4,173 slots for 3285. Both CFGs record zero undecoded slots and no uncovered source-instruction ranges.
- Independently checked all 819 ordinary spread samples against the source-word records and decoded mnemonic/operands.
- Verified R1's Ghidra command, exit code/output receipts, stdout/stderr hashes, Java script hash, both candidate JSON hashes, both CFG JSON receipt hashes, and all nine private-project copy hashes. SHA-256 hashes of all 14 preserved R1 report files are in the evidence ledger.

## Remaining limitations

The function-boundary mismatch means the FDE spans cannot be treated as proven source-function boundaries. There is no C-like pseudocode/body to accept. CFG and p-code do not establish runtime behavior, semantics, device parity, Phase PASS, or V4 readiness. Two target-level high-level behavior entries remain uncovered. No Ghidra rerun was performed.

## Verification command

`python -X utf8 -B RESEARCH_WORK/TASK_246_R2/verify_task246_r2.py`

Result: `VERIFIED`; 8,182/8,182 raw words, disassembly entries, p-code entries, and CFG partition slots; 819/819 spread samples; 0 accepted C-like bodies.
