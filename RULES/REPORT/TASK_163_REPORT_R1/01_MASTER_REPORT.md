# TASK_163 R1 - arkernel3 exported-function recovery

Status: **BOUNDED_RESEARCH_CANDIDATE awaiting independent CEO review**. This is static research from pinned original SOs; it does not establish runtime behavior or product readiness.

| Library | Unique defined nonzero export VAs | Nonempty C-like bodies | Ready chunks |
|---|---:|---:|---:|
| libarkernel3.so | 1541 | 1541 | 7/7 |

## Observed

- The original AArch64 SO file matches pinned SHA-256. All 1,541 export VAs and PT_LOAD offsets/body hashes were independently enumerated and rechecked. Capstone decoded 12,823 source instructions; 1541/1,541 declared symbol ranges decoded fully.
- Exactly one fresh Ghidra import was run for this SO; subsequent chunks used read-only processing. Every process command, raw stdout/stderr, exit code and raw JSON is in the per-source/chunk folders. Each process was bounded to 1 CPU/1 GiB, <=900s, and each decompilation to <=15s.
- Ghidra memory matched the source body for 1541/1,541 VAs and produced 1541/1,541 nonempty C-like exported bodies. Its 12,414 listed instruction addresses were aligned to Capstone-decoded original source addresses; 1493/1,541 listings covered their fully decoded declared body range. 156 spread ordinary records (10.1%) received separate index consistency checks.

## Inferred and limits

- The C-like output supports static call/control-flow research only. Symbol names do not prove the library's effect or exact UI-to-native binding. Internal nonexported functions, indirect calls, live data, device behavior and pixel parity remain unverified.
- No P0/product edits, Phase PASS, V4/P7 authorization, self-review, commit or push. Source/body verification and a decompiler result do not prove a hair-color algorithm or full 45-SO recovery.
