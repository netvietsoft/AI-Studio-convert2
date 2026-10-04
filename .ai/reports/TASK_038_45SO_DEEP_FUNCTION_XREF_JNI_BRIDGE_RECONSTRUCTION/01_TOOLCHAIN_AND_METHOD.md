# TASK_038 — Toolchain Inventory & Forensic Methodology

## 1. Physical Runner Environment
- **Host OS:** Windows 10 Pro (x64)
- **Hostname / Runner ID:** `CONVERT2-WINDOWS-02` / `GITHUB_ACTIONS_37176437976`
- **Execution Workspace:** `C:\actions-runner\convert2\AI-Studio-convert2\AI-Studio-convert2`
- **Sibling Source Root:** `F:\CONVERT\com.mt.mtxx.mtxx`

---

## 2. Toolchain Inventory

| Tool / Component | Version / Build | Path / Provider | Verification Status |
|---|---|---|---|
| **Python** | 3.14.3 (64-bit) | `C:\Python314\python.exe` | ACTIVE / OPERATIONAL |
| **pyelftools** | 0.33 | Python library | ACTIVE / OPERATIONAL |
| **capstone** | 5.0.7 (ARM64) | Python C-extension | ACTIVE / OPERATIONAL |
| **llvm-readelf** | 18.0.1 (optimized) | `D:\SetupC\android-ndk-r27\...\bin\llvm-readelf.exe` | ACTIVE / OPERATIONAL |
| **llvm-objdump** | 18.0.1 (optimized) | `D:\SetupC\android-ndk-r27\...\bin\llvm-objdump.exe` | ACTIVE / OPERATIONAL |
| **llvm-nm** | 18.0.1 (optimized) | `D:\SetupC\android-ndk-r27\...\bin\llvm-nm.exe` | ACTIVE / OPERATIONAL |
| **llvm-cxxfilt** | 18.0.1 (optimized) | `D:\SetupC\android-ndk-r27\...\bin\llvm-cxxfilt.exe` | ACTIVE / OPERATIONAL |
| **llvm-strings** | 18.0.1 (optimized) | `D:\SetupC\android-ndk-r27\...\bin\llvm-strings.exe` | ACTIVE / OPERATIONAL |
| **Ghidra Headless** | Not installed | N/A | NOT AVAILABLE ON RUNNER |
| **IDA Pro / Hex-Rays**| Not installed | N/A | NOT AVAILABLE ON RUNNER |
| **Binary Ninja** | Not installed | N/A | NOT AVAILABLE ON RUNNER |
| **radare2 / Cutter** | Not installed | N/A | NOT AVAILABLE ON RUNNER |

---

## 3. Forensic Methodology & Heuristics

1. **Deterministic Local Execution:**
   - In strict compliance with TASK_038 instructions, **no binaries or code were uploaded to public web decompilers**. All analysis was conducted locally on the physical runner.

2. **Pointer Relocation Triple Scanning for `RegisterNatives`:**
   - In ARM64 ELF dynamic libraries, `JNINativeMethod` arrays reside in `.data.rel.ro` or `.data` and are relocated at load time via `R_AARCH64_RELATIVE` relocations.
   - Each entry consists of three 64-bit pointers:
     1. `name`: Pointer to ASCII C-identifier in `.rodata`
     2. `signature`: Pointer to JVM method signature string matching `^\([a-zA-Z0-9_/$;\[]*\)[a-zA-Z0-9_/$;\[]+$` in `.rodata`
     3. `fnPtr`: Function pointer to machine code within `.text`
   - By scanning `.rela.dyn` for contiguous sequences of these triples, we systematically uncovered dynamic `RegisterNatives` tables across all 45 binaries without relying on symbol table exports.

3. **String XREF Recovery via ARM64 Page Relocation (`ADRP` + `ADD`/`LDR`):**
   - ARM64 PC-relative addressing pairs `adrp xN, #page` with `add xN, xN, #offset` or `ldr xN, [xN, #offset]`.
   - The disassembly engine tracks register state across basic blocks to calculate the absolute virtual address in `.rodata` or `.data` and extracts the referenced string literal or data structure.

4. **Multi-Evidence False-Positive Control:**
   - Conclusions are assigned confidence levels based on multiple independent sources:
     - **FACT:** Confirmed by both static export/relocation and matching Java/Kotlin declaration in decompiled sources.
     - **HIGH_CONFIDENCE:** Confirmed by string XREF + machine call graph + register state.
     - **HYPOTHESIS:** Single uncorroborated heuristic evidence.
     - **UNKNOWN:** Stripped function without identifiable semantic anchors.