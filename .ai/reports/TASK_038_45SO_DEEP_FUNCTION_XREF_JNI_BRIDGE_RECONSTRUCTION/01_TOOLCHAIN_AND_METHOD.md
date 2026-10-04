# 01 — FORENSIC TOOLCHAIN & ANALYSIS METHODOLOGY

### Installed Local Tools on Physical Runner:
- **Python 3.14** (`C:\Python314\python.exe`)
- **LLVM Android NDK r27 Toolchain** (`D:\SetupC\android-ndk-r27\toolchains\llvm\prebuilt\windows-x86_64\bin\`):
  - `llvm-cxxfilt.exe` (Demangling Itanium ABI C++ symbols)
  - `llvm-readelf.exe` (ELF parsing and header validation)
  - `llvm-objdump.exe` (Instruction verification)
  - `llvm-strings.exe` (String extraction)
- **Python Libraries**:
  - `pyelftools` v0.33 (ELF structure, segments, dynamic tags, relocations)
  - `capstone` v5.0.9 (ARM64 linear sweep and detailed disassembly)
  - `ripgrep` v15.2.0 (High-performance source code indexing)

### Methodology:
1. **Strict Read-Only Guarantee:** Zero modifications to vendor binaries in `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE`.
2. **Safe Handling of Corrupt/Truncated Headers:** In-memory zeroing of out-of-bounds `e_shoff` for `libmfxkit.so` without touching disk bytes.
3. **Static RegisterNatives Discovery:** Scanning `R_AARCH64_RELATIVE` relocation triplets matching `(name, sig, fnPtr)` tuples.
4. **Exact Mathematical Extraction:** Decompiling machine instructions and extracting verbatim GLSL shader code bodies.
