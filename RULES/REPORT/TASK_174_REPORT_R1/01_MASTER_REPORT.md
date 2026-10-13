# TASK_174 R1 — libmfxkit.so original ELF forensics

**Disposition: PARTIAL static recovery.** The original is truncated. Its export census is **UNKNOWN**, not zero, because all 560 declared PT_DYNAMIC bytes and all 1,792 section-table bytes lie beyond EOF. No 45/45 claim, runtime behavior equivalence, product Phase PASS or V4 readiness is established.

| Original structure | Declared | Retained | Finding |
|---|---:|---:|---|
| File | 1,354,736 bytes through section table end | 773,652 bytes | Original SHA-256 `78923a90997d34c5dd51215a6cd2bc26c9731806fd9037e4aa71fd3873d3bb4f` |
| RX PT_LOAD body | 1,307,184 bytes | 773,652 bytes | 533,532 bytes missing |
| PT_DYNAMIC at offset 1,330,424 | 560 bytes | 0 | No DT_SYMTAB/STRTAB/HASH/GNU_HASH pointer can be read |
| Section table at offset 1,352,944 | 1,792 bytes | 0 | `.dynsym` cannot be enumerated |
| PT_GNU_EH_FRAME at offset 237,000 | 12,116 bytes | 12,116 bytes | Complete table of 1,513 unwind FDEs |

The GNU unwind table and FDE/CIE pairs independently resolve 1,513 code ranges. Their starts agree record by record. **1,020 ranges** have complete original RX bytes (447,620 bytes total), **one** has only 2,448 of 5,284 bytes, and **492** have no body bytes in this file. These FDE ranges are not evidence that the functions were exported; the missing dynamic table prevents that classification.

The exact 1,020 complete bodies and Capstone ARM64 disassembly are in `RESEARCH_WORK/TASK_174_R1/complete_fde_bodies.bin`, `complete_fde_index.json`, and `complete_fde_assembly.ndjson`. Every body hash and offset was independently rechecked against the pinned original, with 103 spread assembly rows regenerated (more than 10%). No undecodable `.byte` instructions were emitted by Capstone for the packaged complete ranges.

One scratch-only ELF copy was made. Its missing section-table pointer/count were cleared, the RX segment was clamped to retained EOF, and four wholly unbacked program headers were made inert **only in that copy**. The repaired copy is explicitly unsuitable for runtime or export census. One 1CPU/1GiB Ghidra 12.1.4 import completed; five sequential read-only processes reused the same project. A 20-range spread sample and five disjoint 200-range chunks covered all 1,020 complete FDEs without repeated target processing. All 1,020 Ghidra memory SHA values matched original body SHA values. Ghidra produced **1,010 nonempty C-like bodies**; ten nearby ranges timed out under the 15-second-per-function limit. Total six process time was 357.954 seconds. Raw command receipts, stdout/stderr, per-function errors and C-like output remain under `raw/`.

The Ghidra logs contain 507 decompilation warning lines, including flows to missing memory. C-like text is a static reconstruction of retained bytes, **not** proven algorithmic or semantic parity. The ten timeouts are preserved rather than replaced with guessed pseudocode. Functions in the truncated tail cannot be recovered from this input. A complete same-build original with independently checked provenance would be required for a reliable dynamic export census and those missing bodies.

Validation: reran header/PT_DYNAMIC/unwind parsing, all 1,020 original body hashes, exact scratch metadata delta, all 1,020 Ghidra/source SHA claims, and 103 spread Capstone assembly rows. `raw/verification.json` records the checks. The original source SHA matched before and after. PROJECT_ERROR.md and ACQUIREMENTS.md were read; their update was outside this task's files_allowed, and no resolved root-cause remedy or product change is claimed. Existing dirty workspace files were untouched. CEO review is pending; no self-review, commit or push.
