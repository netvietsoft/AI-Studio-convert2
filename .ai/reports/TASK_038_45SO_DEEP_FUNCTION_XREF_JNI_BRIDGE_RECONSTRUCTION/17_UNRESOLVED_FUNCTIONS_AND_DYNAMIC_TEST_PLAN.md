# 17 — UNRESOLVED FUNCTIONS & DYNAMIC TEST PLAN

**Task ID:** TASK_038_45_SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION_ACTIVE  

---

## 1. UNRESOLVED BINARIES & FUNCTIONS ACCOUNTING

Across all 45 vendor ARM64 shared libraries:
- **44 Libraries:** 100% resolved via standard ELF section headers, `.dynsym`, `.rela.dyn`, and `.text` disassembly.
- **Exactly 1 Library (`libmfxkit.so`, 773,652 bytes):**
  - **Issue:** Section header offset `e_shoff = 0x14a4f0` points past EOF (file was packed/unpadded).
  - **Static Recovery:** Program headers (`PT_LOAD`) and dynamic tags (`PT_DYNAMIC`) remain valid. We recovered 29 GLSL shader blocks and program header code segments directly from memory load mapping.
  - **Classification:** Tool Limitation / Third-Party Commercial Packer.

---

## 2. DYNAMIC TEST PLAN ON PHYSICAL DEVICES

For any dynamic runtime hooks or packed logic in `libmfxkit.so`:
1. **Target Hardware:** Samsung Galaxy A07 (SM-A075F, MediaTek Helio G99, Android 16) and Samsung Galaxy A50s (SM-A507FN, Exynos 9611, Android 11).
2. **Instrumentation Hook:** Inject Frida / Simpleperf / ByteHook hook into `dlopen("libmfxkit.so")` and capture memory dump after runtime unpacking.
3. **Tracepoints:** Monitor `JNI_OnLoad` execution and capture `RegisterNatives` calls dynamically.