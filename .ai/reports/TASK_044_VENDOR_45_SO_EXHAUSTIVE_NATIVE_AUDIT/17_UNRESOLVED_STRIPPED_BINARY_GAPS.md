# 17. UNRESOLVED STRIPPED BINARY LIMITATIONS & GAP DISCLOSURE

**Status**: FULL DISCLOSURE & RIGOROUS EVIDENCE

In compliance with the Hiến Pháp Vận Hành and TASK_044 directive, all technical limitations of stripped binaries are explicitly cataloged below:

### GAP-01: ELF `.symtab` Stripped Across All 45 Libraries
- **Condition**: All 45 vendor `.so` files have their local symbol tables (`.symtab` / `.strtab`) stripped for release.
- **Impact**: Internal static function names and file boundaries are not directly recoverable from symbol tables.
- **Mitigation**: Recovered function boundaries through function prologue scanning (`stp x29, x30, [sp, #-N]!`), dynamic symbol export tables (`.dynsym`), and string xrefs.

### GAP-02: `libmfxkit.so` Corrupted/Truncated Section Header Table
- **Condition**: `libmfxkit.so` (773,652 bytes) has `e_shoff = 0x14a4f0` (1,352,944 bytes), pointing past the end of the physical file.
- **Diagnosis**: Intentionally stripped or truncated section headers table used as an Android anti-reverse engineering packer technique. The Android linker `linker64` loads this file successfully because it relies strictly on Program Headers (`PT_LOAD`, `PT_DYNAMIC`), not Section Headers.
- **Mitigation**: Bypassed standard section headers; analyzed via raw Program Headers and byte offsets.

### GAP-03: Dynamic JNI Registration via `RegisterNatives`
- **Condition**: In libraries like `libMTFilterKernel.so`, `libLayerFlow.so`, and `libaicodec.so`, JNI methods are registered dynamically inside `JNI_OnLoad` rather than exported as static `Java_*` symbols.
- **Mitigation**: Cross-referenced string constants (`Lcom/meitu/...`) and decompiled `jadx_src` native method signatures.
