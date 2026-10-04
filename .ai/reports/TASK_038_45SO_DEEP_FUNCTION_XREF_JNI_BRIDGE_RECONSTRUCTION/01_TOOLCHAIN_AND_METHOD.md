# 01 — TOOLCHAIN AND METHODOLOGY

**Task ID:** TASK_038_45_SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION_ACTIVE  
**Execution Date:** 2026-10-04  

---

## 1. INSTALLED TOOLCHAIN INVENTORY

The following local tools on physical runner `CONVERT2-WINDOWS-02` were inventoried and utilized:

1. **Android NDK LLVM Toolchain (v28.2.13676358):**
   - `llvm-objdump.exe`: Version 19.0.0git (AArch64 disassembler)
   - `llvm-readelf.exe`: ELF header, segment, section, dynamic tag, and relocation dumper
   - `llvm-nm.exe`: Symbol table inspection and demangling
   - Path: `C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\28.2.13676358\toolchains\llvm\prebuilt\windows-x86_64\bin`
2. **Python 3.14 x64 Environment:**
   - `Python`: 3.14.0 (Windows x64)
   - `pyelftools`: Pure Python ELF and DWARF parsing engine
   - `capstone`: v5.0.1 Next-gen disassembly framework (ARM64 mode with detailed instruction operand extraction)
3. **Decompiled App Source (JADX v1.5.0):**
   - 3,279 source directories, containing decompiled Java and Kotlin sources of `com.mt.mtxx.mtxx`.
   - Path: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src\sources`
4. **App Assets Tree:**
   - 69 asset directories containing shaders, 3D LUTs, blend models, and plist configs.
   - Path: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_assets\assets`

---

## 2. REVERSE ENGINEERING METHODOLOGY

### Phase A: Memory Image Construction & Relocation Resolution
1. Virtual address space mapping: Every `PT_LOAD` segment is allocated into a contiguous virtual memory buffer matching ELF load addresses.
2. `R_AARCH64_RELATIVE` relocation application: Relocations of type 1027 (`0x403`) in `.rela.dyn` are resolved by writing `r_addend` to `r_offset`. This step is critical because in modern Android ARM64 shared objects, function pointers in `.data.rel.ro` (including vtables and `JNINativeMethod` arrays) store their addresses in relocation addends.

### Phase B: Dynamic Registration (`JNINativeMethod`) Discovery
1. Linear scan of memory segments for 24-byte aligned triples `(const char* name, const char* signature, void* fnPtr)`.
2. Validation criteria:
   - `name`: Must point to a valid ASCII C-identifier in `.rodata` or `.data`.
   - `signature`: Must point to a valid JVM method signature starting with `(` and containing `)`.
   - `fnPtr`: Must be a valid virtual address strictly within the `.text` segment.
3. This discovered 1,907 dynamic JNI registrations in `libLayerFlow.so` and 42 in `libMTFilterKernel.so`.

### Phase C: Executable Function Census & CFG Construction
1. Entry point recovery:
   - Direct symbols from `.dynsym` (exported, global, weak).
   - Dynamic registration targets from `JNINativeMethod` tables.
   - All `BL` (branch with link) immediate targets across `.text`.
   - Standard ARM64 function prologues: `STP X29, X30, [SP, #-imm]!` and `PACIASP`.
2. Instruction-level analysis using Capstone ARM64:
   - Direct calls (`BL`) mapped to internal callees or `.plt` stubs.
   - Tail calls (`B`) evaluated against known function boundaries.
   - String XREFs: Tracking `ADRP Xn, #page` followed by `ADD Xn, Xn, #offset` to extract exact string literals from `.rodata`.
   - PLT stub resolution: Mapping each 16-byte PLT stub to its `.rela.plt` relocation symbol (`R_AARCH64_JUMP_SLOT`).

### Phase D: Shader & Mathematical Equation Extraction
1. Plaintext GLSL extraction: Scanning `.rodata` for GLSL shader tokens (`precision highp`, `gl_FragColor`, `uniform sampler2D`).
2. Mapping shader uniform names (`shiftingSize`, `threshold`, `gain`, `kernel[10]`, `Weights[5]`) directly back to the calling C++ setup methods in `.text` via instruction-level `ADRP` XREFs.