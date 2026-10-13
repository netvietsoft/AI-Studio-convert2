# TASK_191 R1 — bounded PVGColorFunctions nonexport FDE research

The exact zero-based VA-sorted nonexport FDE candidate slice **384..447** contains 64 ranges and 6,962 AArch64 instruction positions in the pinned original `libPVGColorFunctions.so`. The ELF has 753 FDE ranges, 81 defined nonzero-size function export starts and 672 nonexport FDE candidates. This slice leaves 224 later candidates outside its scope. FDE ranges are unwind metadata, not proof of unique complete source functions.

All 64 original FDE ranges, PT_LOAD translations and body SHA-256 values match the manifest; Capstone decoded 6,962/6,962 positions. The accepted TASK_190 analyzed Ghidra project was copied byte-for-byte to private scratch and all nine project file hashes matched before and after four sequential read-only headless runs. The runs used `-max-cpu 1`, a configured 1 GiB heap, no fresh import, a 20-minute cap per process and 10 seconds per decompile. Raw command, log and candidate outputs are retained.

Ghidra memory SHA matches 64/64 original bodies. Listing coverage is **6,836/6,962** positions; p-code appears on **6,817/6,962** positions, with 29,304 operations. C-like text exists for 64/64 original Ghidra function objects; **55/64** have whole-byte Ghidra function-body membership exactly equal to the corresponding FDE range. **9** rows have missing FDE body bytes and **0** have extra Ghidra body bytes. Boundary classifications: `{'GHIDRA_BODY_EQUALS_FDE_RANGE': 55, 'FDE_HAS_INTERNAL_GAPS_IN_GHIDRA_BODY': 9}`. The nine gap rows are:

- Row 3 `0x2da50`: 36 missing body bytes at `0x2db0c..0x2db2f`
- Row 5 `0x2dbbc`: 36 missing body bytes at `0x2dd04..0x2dd27`
- Row 6 `0x2dd4c`: 36 missing body bytes at `0x2de0c..0x2de2f`
- Row 8 `0x2deec`: 36 missing body bytes at `0x2e040..0x2e063`
- Row 9 `0x2e088`: 36 missing body bytes at `0x2e140..0x2e163`
- Row 11 `0x2e210`: 36 missing body bytes at `0x2e358..0x2e37b`
- Row 13 `0x2e3a8`: 96 missing body bytes at `0x2e52c..0x2e58b`
- Row 17 `0x2e688`: 96 missing body bytes at `0x2e820..0x2e87f`
- Row 19 `0x2e904`: 96 missing body bytes at `0x2ea88..0x2eae7`

The gaps total 504 bytes, or 126 four-byte positions. They remain PARTIAL: the FDE may cover data or code that Ghidra did not put in the function body. No other function metadata was removed, and no transient function correction was attempted. Full per-byte membership bitmaps, body/missing/extra ranges, instruction and p-code text, C-like text/hash, calls and failures are preserved per row in the raw NDJSON.

The task verifier independently reparsed the original ELF and rechecked all 64 FDE/PT_LOAD/body hashes, all 6,962 source Capstone positions, all 64 Ghidra memory hashes and per-byte body membership claims, 6,962 Ghidra slot records and 64 C-like hashes. Its 989 distinct spread source-word checks cover 14.21% of instruction positions; each sampled source word is recorded. This is an internal consistency check of the preserved Ghidra output; the CEO has not yet independently replayed Ghidra.

Research disposition: **PARTIAL_STATIC_FDE_BOUNDARY** for this exact FDE candidate slice. Dynamic behavior, call semantics, pixel/device parity, product Phase PASS, V4/P7 and completion of all 45 SOs are unestablished. `PROJECT_ERROR.md` and `ACQUIREMENTS.md` were consulted but this lease does not permit edits to them. No AGY, self-review, commit or push occurred.
