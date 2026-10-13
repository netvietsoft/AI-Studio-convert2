# TASK_182 R1 - WebP SIMD-path corrective research

**Verdict: PARTIAL, awaiting independent CEO review.** The original `WebPConvertRGBA32ToUV_C` SIMD interval `0x3294c..0x32ab4` is source-byte mapped to 90/90 ARM64 instructions and 999/999 historical p-code operations. A single bounded vector-only Ghidra pass in a verified project copy failed with `Unable to find unique hash for varnode`; no vector C-like or whole-original C-like is claimed.

The source-anchored register analysis in `02_SIMD_SOURCE_ANALYSIS.md` identifies two weighted 16-bit-lane sums, signed shift by 18, clamp to 0..255, 32→16→8 narrowing, and eight-byte stores to each destination. It states the entry-state and overlap-gate assumptions. The exact original 624-byte body and 90 instruction records are retained; 23 critical SIMD instruction anchors and 10 spread ordinary source words (11.1%) were checked. The prior scalar-tail pass was not repeated.

Raw Ghidra command, logs and result are preserved, including the negative decompiler result. The source project is unchanged, zero fresh imports occurred, and no AGY, product/P0 edit, self-review, commit or push occurred. Runtime behavior and pixel parity remain unverified. PROJECT_ERROR.md and ACQUIREMENTS.md were reviewed but are outside this task's write scope.
