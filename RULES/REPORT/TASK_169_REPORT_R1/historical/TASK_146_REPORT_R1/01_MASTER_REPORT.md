# TASK_146 R1 - LayerFlow Hair/Dye research

Status: **PARTIAL research candidate awaiting independent review**. Codex CEO executed directly without AGY. The large applyLayer C decompile timed out; do not count it as a recovered C body. This is no product Phase PASS, V4 authorization, model reconstruction, or pixel parity.

## Observed

- Pinned `libLayerFlow.so` SHA-256 `ef8d1581038778b72abca3ca8fd5046e49fd44e0465871b023647fe42a582262` has 17 matching defined export symbols at 15 unique VAs. All 15 source bodies mapped through PT_LOAD, passed SHA checks, and were fully Capstone decoded: 3,698 AArch64 instructions, 416 direct `bl` calls, 31 indirect `blr` calls. Two ordinary bodies were rehashed again at seal (13.3%).
- One Ghidra 12.1.4 process produced 15/15 Ghidra-memory hashes matching source bytes and 14/15 C-like decompile outputs. Its instruction listings were 11 FULL and 4 PARTIAL. `CLFDenseHairProcessor::applyLayer` at ELF VA `0x3f94fc` is the sole C timeout (`Exception while decompiling 004f94fc: process: timeout`), with 0 C characters and 2842/3,245 instructions listed by Ghidra. Capstone decoded its complete 12,980-byte body. The source-only result is not a C decompilation.
- The applyLayer body has 411 source calls. Its PLT/GOT/relocation checks resolved 243 call targets; 59 target defined function symbols in this SO; 79 direct targets remain unmapped by that source-only resolver and 30 calls are indirect. Separately, source AArch64 verified 374 direct targets shown in Ghidra call listings; 25 Ghidra indirect targets remain unverified. These denominators differ because Ghidra listed only part of applyLayer.
- The selected hair-clean-alpha JNI get/set bodies are exactly `ldr d0,[x2]; ret` and `str d0,[x2]; ret`; neither two-instruction body clamps or validates a range. `CLFDenseHairProcessor::needFace` is `mov w0,#1; ret`. Caller and provider behavior remain unknown.
- Source-backed PLT/GOT relocations in applyLayer name `CMTIKHairFilter` hair-mask, dye-material, dye-alpha, effect, and AI-request methods plus renderer calls. `libmtImageKit.so` is DT_NEEDED and absent from the current SO45 directory, so these imported implementation bodies are not available here.

## Inferred

- applyLayer appears to orchestrate external hair processing components and renderer operations. This is inferred from its call graph, not a recovered shader, model, or exact pixel formula.

## Unknown / blocked input

- The C-like body for applyLayer remains missing because the per-function 15-second Ghidra timeout elapsed. A separate narrowly scoped correction batch with a longer per-function budget is justified; this task does not silently rerun the importer or claim completion.
- `libmtImageKit.so` and other model/data providers are absent from SO45. Runtime branch execution, parameter ranges, alpha compositing, coordinate/channel semantics, protected regions, shader math, and output pixels are unproved.
- Ghidra GccExceptionAnalyzer logged 15961 disassembly-failure rows at 13774 distinct addresses, none within these 15 selected function intervals. Four selected instruction listings remain PARTIAL, and decompiled C does not prove cold/exception paths.
- The prior TASK_079 R2 report declared zero decompiled bodies and remains BLOCKED; its speculative math dossiers were not used as proof here. TASK_063 remains BLOCKED; TASK_064A-G/065/066 remain PLANNED. No product Phase PASS, V4, or P7 gate is open.

## Provenance

Ghidra ran once with `-max-cpu 1` and heap 1 GiB, exit `0` after 786.897 seconds. Original ELF bytes, PT_LOAD mapping, all 15 body hashes, all source instructions, selected PLT/GOT relocations, and a 13.3% sealing sample were independently rechecked. Raw logs, pseudocode/disassembly, and hash maps are in this report package. The CEO has not self-approved ACCEPTED or committed/pushed this candidate.
