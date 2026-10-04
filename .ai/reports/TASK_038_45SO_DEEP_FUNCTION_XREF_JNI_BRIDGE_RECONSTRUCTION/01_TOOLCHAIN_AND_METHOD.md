# TASK_038 — FORENSIC TOOLCHAIN & METHODOLOGY SPECIFICATION

- **LLVM Toolchain:** Android NDK r28 Clang/LLVM 19.0.1 (`llvm-objdump`, `llvm-readelf`, `llvm-nm`, `llvm-cxxfilt`)
- **Disassembly Engine:** Capstone Engine 5.0.7 (ARM64 AArch64)
- **ELF Parser:** pyelftools (64-bit ELF, Little-Endian, Dynamic Relocation Processor)
- **Source Search Engine:** BurntSushi Ripgrep 15.2.0
- **Methodology:** Static relocation application, contiguous 24-byte JNINativeMethod array extraction, ARM64 ADRP/ADD/LDR string XREF resolution, call graph construction.
