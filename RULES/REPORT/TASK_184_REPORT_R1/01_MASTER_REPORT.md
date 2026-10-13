# TASK_184 R1 — VERenderer nonexport unwind candidate recovery

Original `libVERenderer.so` SHA-256 `2da896556822804506871c47fadda3fadf8537952e38642e6c496ccbbab8ca46`; 141 exact manifest rows SHA-256 `0b11084f86a80398343bd576843dfdabf7f697b7d8a31aa652ad452c6d071a0b`.
Completed bounded extraction: 141/141 C-like texts, 7661/7661 instruction slots, 7396/7661 slots with p-code, 23977 p-code operations.
All 141 source PT_LOAD bodies and FDE starts were rechecked; all 141 owned-project memory hashes equal original body hashes. Fifteen evenly spread candidates (10.6%) had every original instruction word and Ghidra listing address independently rechecked (674 words).
Three sequential read-only Ghidra processes used the byte-verified copy of prior TASK_158 project, zero new imports, 1 CPU/1 GiB, 10 seconds per candidate decompilation, under 20 minutes per process (45.498s combined). Raw command receipts, stdout/stderr, and 141 per-candidate JSON results remain under `ghidra/`.

## Boundary and confidence limits

These are 141 unwind FDE starts absent from defined nonzero `.dynsym` STT_FUNC export starts. An FDE start/span is a candidate range, not proof of a complete internal-function census or unique function boundary. Ghidra's existing function entry matched all 141 starts. Its function body differed from the pinned FDE span in five rows; their C-like output must be read with that boundary discrepancy.

- Candidate 8 at `0x3ce80`: `GHIDRA_FUNCTION_BODY_DIFFERS_FROM_FDE_RANGE`; see per-candidate JSON for exact Ghidra body and FDE size.
- Candidate 14 at `0x3f08c`: `GHIDRA_FUNCTION_BODY_DIFFERS_FROM_FDE_RANGE`; see per-candidate JSON for exact Ghidra body and FDE size.
- Candidate 17 at `0x3f120`: `GHIDRA_FUNCTION_BODY_DIFFERS_FROM_FDE_RANGE`; see per-candidate JSON for exact Ghidra body and FDE size.
- Candidate 46 at `0x491dc`: `GHIDRA_FUNCTION_BODY_DIFFERS_FROM_FDE_RANGE`; see per-candidate JSON for exact Ghidra body and FDE size.
- Candidate 95 at `0x5d54c`: `GHIDRA_FUNCTION_BODY_DIFFERS_FROM_FDE_RANGE`; see per-candidate JSON for exact Ghidra body and FDE size.

P-code operations are zero for some decoded instructions (e.g. architectural no-ops); therefore 7,396 p-code-covered slots are reported separately from full assembly-slot coverage. C-like text is Ghidra output only: it has not been compiled, tested against original execution, or checked for pixel/behavioral parity. No product Phase PASS, V4, P7, or all-45-SO completion is asserted.

`coverage_index.json`, `source/source_index.json`, `source/assembly.ndjson`, `independent_source_verification.json`, and `ghidra/chunk_*/candidates/candidate_*.json` identify each row. This package awaits independent CEO review; worker verification is not approval.
