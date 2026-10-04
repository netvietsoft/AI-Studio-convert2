# TASK_045 — UNRESOLVED LIMITATIONS & PROTECTED SCOPES

### 1. Stripped Binary Analysis Boundaries
All 45 vendor `.so` libraries in the distribution are stripped of non-dynamic debugging symbols (`.symtab` and `.strtab` stripped; `.dynsym` and `.dynstr` retained).
- **Consequence:** Non-exported static functions within `.text` are designated by raw hex virtual addresses (e.g., `0x0f42fc`) rather than original compiler source identifiers.
- **Mitigation:** Control flow graphs (CFGs), relocation cross-references (`.rela.dyn`), virtual method tables (`.data.rel.ro`), and runtime log strings have been used to identify and map the complete execution topology.

### 2. Strictly Protected Exclusions (Mandatory Rule 11)
In accordance with Task 045 Mandatory Rule 11 and the Hiến pháp Hiến định CONVERT2, the following 8 libraries have been classified as **`BLOCKED/EXCLUDED`** to safeguard security boundaries, digital rights management, and proprietary protection schemes:
1. `libdexvmp.so`: Dex VMP Bytecode Obfuscator & Anti-Tamper Core
2. `libCtaApiLib.so`: Security, CTA API, Licensing & Access Control
3. `libMtlabSign.so`: Cryptographic Signing & Signature Verification
4. `libbuffer_pgl.so`: PGL Anti-Tamper Memory Protection Buffer
5. `libfile_lock_pgl.so`: PGL File Integrity & Locking
6. `libbytehook.so`: Dynamic Process Memory Hooking Engine
7. `libkoom-strip-dump.so`: Process Memory Heap Dumper
8. `libfntvcrash.so`: Crash Diagnostics & Callstack Interceptor

These libraries were disassembled and cataloged for ELF metadata and section headers only; their internal anti-tamper and signing routines are explicitly **NOT RECONSTRUCTED OR BYPASSED**.

### 3. Third-Party Open Source Components
Libraries containing third-party open-source implementations (`libc++_shared.so`, `libffmpeg.so`, `libffavc.so`, `libfftw3.so`, `libglide-webp.so`) are governed by their respective licenses (LGPL/GPL/BSD/MIT) and are decoupled from proprietary algorithm claims.
