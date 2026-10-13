# TASK_178 R1 - oversized libdexvmp export block research

**Disposition: PARTIAL static recovery.** The original 224,440-byte body is fully preserved by SHA-256 and split into 5,821 source-byte-anchored candidate blocks. Whole-function Ghidra C-like output remains absent; behavioral equivalence and runtime path coverage are unknown.

## Observed from original bytes

- Original source SHA-256 `b4a46520ec989fef5346833db8f9a1bd6a6690902731414ed26f65cc529cc06e` and body SHA-256 `ffe6c5558f71b31ead9ce7055ecea778379cccd409978b5502c9cb39ff272654` independently match. An identity-mapped ELF PT_LOAD segment covers the body and both table byte ranges.
- Fixed four-byte AArch64 linear sweep gives 56,097 decodable candidate words and 13 explicit undecoded words across 56,110 words. Decodable does not mean executable or reachable; embedded data may also decode.
- The candidate partition has 5,821 blocks and 10,241 edges including guarded table cases. Independent verifier rechecked all 56,110 source words, 5,821 block hashes, 10,241 edge destinations, all 2,823 table entries, all 1,692 historical Ghidra anchor opcodes, and 583 spread blocks (10.02%).
- At `0x2a844`, `cmp w9,#0x707` / `b.ls` guards a table at `0x6098c` with 1,800 signed relative entries, all aligned and inside this function. At `0x4e0c4`, `sub w9,w8,#0x708` / `cmp w9,#0x3fe` / `b.hi` guards a second table at `0x63574` with 1,023 such entries, likewise inside. The table bytes start beyond the dynamic symbol's declared function end and are copied verbatim; they do not extend claimed function-body coverage.
- Traversing only directly encoded branches from the entry reaches 17 candidate blocks. Including these two byte-proven table target sets reaches 4,156 candidate blocks. This is a static possible-target closure, not evidence that a runtime input visits all those cases.
- Historical TASK_159 Ghidra output read-only shows the same body hash, only 1,692 instruction addresses, and decompiler `process: timeout`. Four Capstone/Ghidra mnemonic differences are syntax aliases (`orr`/`mov`, `bfm`/`bfi`); all 1,692 anchor source words are verified.

## Boundaries and unresolved evidence

There are 388 indirect jump instructions in the candidate sweep. Exactly two have guarded original-byte table targets in this report; 386 others remain unresolved. There are 408 indirect call candidates and 13 undecoded words. Static parsing may include data or decoy code, and target sets do not establish path feasibility. No whole-function C-like, P-code reconstruction, semantic equivalence, runtime behavior, test PASS, product Phase PASS or V4 claim is made. The block and edge files are forensic source maps; `control_flow_skeleton.txt` records control transfers only and is not C-like decompilation.

Only TASK_178 scoped research/report/script files were written. Prior 283 ordinary export bodies and existing Ghidra projects were left untouched. No AGY, fresh import, Ghidra process, product/P0 edit, commit or push occurred. PROJECT_ERROR.md and ACQUIREMENTS.md were reviewed; durable updates require CEO-owned scope or a later task.
