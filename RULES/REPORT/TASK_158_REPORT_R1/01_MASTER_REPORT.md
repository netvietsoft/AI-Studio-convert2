# TASK_158 R1 - PVGCodec and VERenderer exported-function recovery

Status: **BOUNDED_RESEARCH_CANDIDATE awaiting independent CEO review**. This is static research from pinned original SOs; it does not establish runtime behavior or product readiness.

| Library | Unique defined nonzero export VAs | Nonempty C-like bodies | Ready chunks |
|---|---:|---:|---:|
| libPVGCodec.so | 417 | 417 | 4/4 |
| libVERenderer.so | 886 | 886 | 7/7 |

## Observed

- Both original AArch64 SO files match pinned SHA-256. All 1,303 export VAs and PT_LOAD offsets/body hashes were independently enumerated and rechecked. Capstone decoded 132,185 source instructions; 1303/1,303 declared symbol ranges decoded fully.
- Exactly two fresh Ghidra imports were allowed, one per SO; subsequent chunks used read-only processing. Every process command, raw stdout/stderr, exit code and raw JSON is in the per-source/chunk folders. Each process was bounded to 1 CPU/1 GiB, <=900s, and each decompilation to <=15s.
- Ghidra memory matched the source body for 1303/1,303 VAs and produced 1303/1,303 nonempty C-like exported bodies. Its 125,610 listed instruction addresses were aligned to Capstone-decoded original source addresses; 951/1,303 listings covered their fully decoded declared body range. 132 spread ordinary records (10.1%) received separate index consistency checks.

## Inferred and limits

- The C-like output supports static call/control-flow research only. Symbol names do not prove the library's effect or exact UI-to-native binding. Internal nonexported functions, indirect calls, live data, device behavior and pixel parity remain unverified.
- No P0/product edits, Phase PASS, V4/P7 authorization, self-review, commit or push. Source/body verification and a decompiler result do not prove a hair-color algorithm or full 45-SO recovery.
