# TASK_181 R1 — bounded FFmpeg NEON fragment correction

**Disposition:** PARTIAL static research candidate. One original-byte, synthetic-entry fragment of target 2283 produced Ghidra C-like; both whole-original exported functions still lack C-like.

The pinned original `libffmpeg.so` is byte-identical to the task hash. Direct `.dynsym`/PT_LOAD checks found 2,461 unique defined function-export VAs and both exact body hashes. Independent Capstone replay matched all 242 original instruction rows. The copied analyzed Ghidra project matched all nine historical file hashes before execution and still matched after two read-only processes.

| Index | Export / ELF VA | Original bytes | Isolated fragment | Result |
|---:|---|---:|---|---|
| 2283 | `x264_8_deblock_h_luma_intra_neon` / `0x658fe8` | 736 | `0x659200..0x6592c4`, 200 bytes/50 instructions | Ghidra `decompile` C-like for the fragment only; synthetic entry registers lack original preceding context. |
| 2330 | `x264_8_frame_init_lowres_core_neon` / `0x65aea8` | 232 | `0x65af24..0x65af8c`, 108 bytes/27 instructions | Original-byte fragment verified; decompiler returned `Unable to find unique hash for varnode`, no C-like. |

The historical TASK_173 `normalize` pass was not repeated. Each target had one new isolated-fragment `decompile` process with `-noanalysis -readOnly -max-cpu 1`, `GHIDRA_HEADLESS_MAXMEM=1G`, and a 180-second decompiler cap. Actual process wall times are in command receipts. `fragment_2283_synthetic.c` is Ghidra output, not a standalone implementation or proof of the original full function. It begins at a synthetic entry with input vector registers that were initialized by omitted instructions. Target 2330 retains exact source assembly and the historical raw/normalized p-code under TASK_173; this task also records the attempted fragment's raw p-code.

Critical SHA/source/lease/project/process claims and 27 spread ordinary instruction provenance rows were independently checked in `verification.json` (27/242 = 11.16%). No pixel/behavior equivalence test, physical-device validation, product build, Phase PASS, V4 or P7 authorization is implied. The unresolved whole-body gap remains 2/2.
