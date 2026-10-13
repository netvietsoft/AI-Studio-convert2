# TASK_179 R1 — WebPConvertRGBA32ToUV_C gap recovery

**Verdict: PARTIAL static recovery, awaiting independent CEO review.** The original 624-byte exported function is completely mapped to source bytes and 156 AArch64 instructions, and its 1,307 historical Ghidra p-code operations are address-aligned. A new, different Ghidra route produced C-like text for the **scalar tail only**. The full original function still has no whole-function C-like decompilation because the SIMD path remains a register/block-level reconstruction.

| Layer | Measured result | Boundary |
|---|---|---|
| Original source | Pinned `libglide-webp.so` SHA-256 `2f7f38acc0d294a3333069aa8a3c07e69d4bc0a64f162215578bd55dbe1a4486`; exactly one PT_LOAD mapping of export VA `0x328dc`, 624 bytes; body SHA-256 `fc4cf89d6b719a3d8d73009a57a1e755ca9ce11dda3bdd03da45c5b869053404` | 624/624 original bytes |
| Assembly | 156/156 contiguous 4-byte AArch64 instructions independently decoded; 16 spread source words reread | Complete instruction listing, not C-like |
| Control flow | 8 direct branch/return sites, 11 basic blocks; vector and scalar loops anchored to source addresses | Static CFG, no runtime branch frequencies |
| Lifted p-code | 1,307/1,307 TASK_175 operations checked for original instruction alignment | Historical Ghidra p-code, not newly generated or behavior verified |
| New Ghidra pass | One copied-project, no-analysis, read-only headless process, 14.53 seconds, exit 0, 1 CPU/1 GiB; synthetic scalar-tail function `0x32ab8..0x32b48`, `decompile` style completed in 47.82 ms and emitted C-like | Only scalar tail; original function metadata temporarily replaced in copied project; original source/project unchanged |
| Whole original export | Historical default decompiler error: `Unable to find unique hash for varnode`; TASK_175 normalize pass no C-like; TASK_179 full-function C-like: **unavailable** | Explicit remaining gap |
| Runtime/behavior | No original-binary execution or device/image parity test | Unverified |

The direct ARM64 and p-code evidence supports two weighted 16-bit-lane-to-byte sums, an overlap gate before the eight-lane SIMD loop, and a scalar remainder loop. The register/block pseudocode in `02_SOURCE_ANCHORED_BLOCK_PSEUDOCODE.md` gives coefficients, saturation, pointers, branches and source addresses. It is a static interpretation and must not be presented as recovered whole-function C or as an approved product formula.

TASK_175 had already revalidated the historical TASK_155 export corpus: 197/197 `libfantasy.so` and 229/230 `libglide-webp.so` C-like bodies. This task targeted **only** the missing glide export and did not reprocess the other 229. The preceding normalize attempt was not repeated. The historical default error and normalize result are copied and labeled with their original provenance; the new partial C-like output has its own exact command, logs, project inventories and result hash. The copied Ghidra project was byte-identical to historical TASK_155 before execution, and the historical project stayed unchanged afterward.

No P0/product code was changed. TASK_063 and downstream 064A-G/065/066 research gates, Phase PASS, V4 implementation and P7 remain outside this result. Independent CEO review is required before any acceptance or repository publication.
