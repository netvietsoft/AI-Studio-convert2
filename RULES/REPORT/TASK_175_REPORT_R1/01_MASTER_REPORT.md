# TASK_175 R1 - fantasy/glide historical recovery revalidation

Status: **PARTIAL_RESEARCH_CANDIDATE awaiting independent CEO review**.

| Original SO | Defined nonzero `.dynsym` names | Unique export VAs | Historical TASK_155 C-like | New TASK_175 C-like |
|---|---:|---:|---:|---:|
| `libfantasy.so` | 197 | 197 | 197 | 0 |
| `libglide-webp.so` | 244 | 230 | 229 | 0 |

## Observed

- Both pinned original files were SHA-256 checked. All 427 selected function bodies were independently mapped to original PT_LOAD file ranges and rehashed twice. The TASK_155 Ghidra-memory/body digests and raw command/log/result hashes match all 427. A separate spread sample of 43/427 original body records was re-read. The historical raw result files contain the 426 C-like texts.
- Exactly one historical gap remains: `libglide-webp.so` export `WebPConvertRGBA32ToUV_C`, index 144, ELF VA `0x328dc`, 624 bytes, original body SHA-256 `fc4cf89d6b719a3d8d73009a57a1e755ca9ce11dda3bdd03da45c5b869053404`. TASK_155's default decompiler returned `Unable to find unique hash for varnode`.
- One new Ghidra headless process (13.861 s; 1 CPU, 1 GiB; read-only, no analysis, no fresh import) used a byte-identical copy of the existing analyzed glide project and targeted only that VA. The `normalize` simplification style completed in 355.3 ms but emitted no C-like text. It preserved 156 source-aligned AArch64 instruction lines and 1307 source-addressed lifted p-code operations. The historical project source inventory is unchanged; copied-project cache backup changes are recorded in `final_verification.json`.

## Scope and limits

The 426 C-like bodies were recovered earlier under TASK_155 and are only revalidated here. Lifted p-code and disassembly at the remaining VA are useful static evidence but do not constitute a recovered whole-function C-like body. Internal/nonexported functions, runtime behavior, device output, hair-color formulas and product Phase PASS/V4/P7 remain unproven. TASK_063 and downstream 064A-G/065/066 gates are unchanged. No self-review, acceptance, commit or push occurred.
