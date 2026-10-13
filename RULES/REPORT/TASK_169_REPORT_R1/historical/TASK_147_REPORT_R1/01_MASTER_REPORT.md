# TASK_147 R1 - CLFDenseHairProcessor::applyLayer C-like recovery

Status: **bounded research candidate awaiting independent review**. Tony assigned Codex CEO directly; no AGY. This resolves the TASK_146 15-second *C output timeout* for the one selected function. It does not prove semantic equivalence, shader math, output pixel parity, product Phase PASS, V4, or P7.

## Observed

- Original `libLayerFlow.so` SHA-256 `ef8d1581038778b72abca3ca8fd5046e49fd44e0465871b023647fe42a582262` has the defined `applyLayer` symbol at ELF VA `0x3f94fc` with 12,980 bytes. PT_LOAD mapping, source body SHA-256 `ab9fb919f6ba063263dcd29d8eaa157e0eb3615d3adb6741769aa89f1618c5e9`, and the copied Ghidra program's memory SHA-256 match exactly.
- One Ghidra 12.1.4 `-process` on a hash-verified copy of the TASK_146 project used `-noanalysis -readOnly -max-cpu 1`, 1 GiB heap, and a 180-second per-function decompile limit. Process exit was 0 after 20.734 seconds. The decompiler returned 146,989 C-like characters in 7216.1024 ms with no decompile error. The raw output and standalone C text are hashed in the manifest.
- Independently, Capstone decoded all 3,245 AArch64 source instructions (381 direct `bl`, 30 indirect `blr`). Ghidra listed 2,842/3,245 instruction addresses and 363 call sites; all listed addresses align to the original source instruction stream. 285 ordinary instruction records (10.0%) were rechecked against source bytes, and every listed call site was checked as a source branch opcode.
- Ghidra emits `Type propagation algorithm not settling` at the start of C text. Its instruction listing is partial. The read-only run changed/removed 2 project housekeeping files inside TASK_147 scratch; the source and copied-program body hashes still match.

## Inferred

- The C-like text provides a navigable control-flow and call skeleton for this exported function. Any particular branch condition, type, color equation, or image coordinate interpretation requires separate corroboration.

## Unknown / blocked input

- The `libmtImageKit.so` implementation imported by this SO is absent from the SO45 directory, and runtime/model data are unavailable. The recovered output cannot establish the final hair-color algorithm or protected-region behavior. Partial Ghidra instruction coverage and its type-propagation warning further limit semantic conclusions.
- TASK_146 remains a sealed PARTIAL candidate awaiting independent review; this correction does not alter its report. TASK_063 remains BLOCKED and TASK_064A-G/065/066 remain PLANNED. No product gate is opened.

Raw files and command receipts in this report allow an independent reviewer to check these bounded claims. The CEO has not self-approved ACCEPTED or committed/pushed this research candidate.
