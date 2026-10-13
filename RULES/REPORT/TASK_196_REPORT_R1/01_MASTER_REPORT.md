# TASK_196 R1 — bounded PVGColorFunctions nonexport FDE research

The exact zero-based VA-sorted nonexport FDE candidate slice **512..575 excluding index 556** contains 63 ranges, 17,621 AArch64 instruction positions and 70,484 original bytes in the pinned `libPVGColorFunctions.so`. Oversized index 556 (VA `0x4cee4`, 7,068 bytes/1,767 slots) is reserved for a separate task and is not analyzed here. Earlier index 505 remains unanalysed, and 506 remains PARTIAL in TASK_194. The ELF has 753 FDE ranges, 81 defined nonzero-size function export starts and 672 nonexport FDE candidates. This slice leaves 96 later candidates outside its scope. FDE ranges are unwind metadata, not proof of unique complete source functions; one-instruction indices 512, 562, 565, 566, 570, 573 and 574 are possible stubs/thunks.

All 63 original FDE ranges, PT_LOAD translations and body SHA-256 values match the manifest; Capstone decoded 17,621/17,621 positions. The accepted TASK_194 analyzed Ghidra project was copied byte-for-byte to private scratch and all nine project file hashes matched before and after four sequential read-only headless runs. The runs used `-max-cpu 1`, a configured 1 GiB heap, no fresh import, a 20-minute cap per process and 10 seconds per decompile. Raw command, log and candidate outputs are retained.

Ghidra memory SHA matches 63/63 original bodies. Listing coverage is **17,516/17,621** positions; p-code appears on **17,481/17,621** positions, with 114,976 operations. C-like text exists for 63/63 original Ghidra function objects; **58/63** have whole-byte Ghidra function-body membership exactly equal to the corresponding FDE range. **5** rows have missing FDE body bytes and **0** have extra Ghidra body bytes. Boundary classifications: `{'GHIDRA_BODY_EQUALS_FDE_RANGE': 58, 'FDE_HAS_INTERNAL_GAPS_IN_GHIDRA_BODY': 3, 'GHIDRA_BODY_PREFIX_OF_FDE_RANGE': 2}`. Gap rows, if any:

- Row 39 `0x4c54c`: 112 missing body bytes at `0x4cb38..0x4cba7`
- Row 42 `0x4cd3c`: 4 missing body bytes at `0x4cd74..0x4cd77`
- Row 43 `0x4cd78`: 4 missing body bytes at `0x4cdb8..0x4cdbb`
- Row 45 `0x4ea80`: 152 missing body bytes at `0x4ec98..0x4ed2f`
- Row 46 `0x4ed34`: 152 missing body bytes at `0x4ef5c..0x4eff3`

The gaps total 424 bytes, or 106 four-byte positions. They remain PARTIAL: the FDE may cover data or code that Ghidra did not put in the function body. No other function metadata was removed, and no transient function correction was attempted. Full per-byte membership bitmaps, body/missing/extra ranges, instruction and p-code text, C-like text/hash, calls and failures are preserved per row in the raw NDJSON.

The task verifier independently reparsed the original ELF and rechecked all 63 FDE/PT_LOAD/body hashes, all 17,621 source Capstone positions, all 63 Ghidra memory hashes and per-byte body membership claims, 17,621 Ghidra slot records and 63 C-like hashes. Its 2,303 distinct spread source-word checks cover 13.07% of instruction positions; each sampled source word is recorded. This is an internal consistency check of the preserved Ghidra output; the CEO has not yet independently replayed Ghidra.

Research disposition: **PARTIAL_STATIC_FDE_BOUNDARY** for this exact FDE candidate slice. Dynamic behavior, call semantics, pixel/device parity, product Phase PASS, V4/P7 and completion of all 45 SOs are unestablished. `PROJECT_ERROR.md` and `ACQUIREMENTS.md` were consulted but this lease does not permit edits to them. No AGY, self-review, commit or push occurred.
