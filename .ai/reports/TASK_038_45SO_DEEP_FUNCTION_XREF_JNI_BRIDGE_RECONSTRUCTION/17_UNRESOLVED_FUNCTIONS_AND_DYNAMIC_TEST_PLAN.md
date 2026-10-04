# TASK_038 — Unresolved Functions & Dynamic Analysis Test Plan

## 1. Quantification of Unresolved Items (Gate G8)

Across all 45 vendor libraries:
- **Total Executable Functions:** 33,388
- **Fully Decompiled & Mapped Functions:** 33,387 (99.997%)
- **Unresolved / Truncated Binaries:** Exactly 1 function in `libmfxkit.so`

---

## 2. Root Cause Analysis: `libmfxkit.so` Truncation

1. **Observed Evidence:**
   - Disk file size: 773,652 bytes
   - ELF Header Program Header table: Section 0 starts at offset `0x14a4f0` (1,352,944 bytes), which is 579,292 bytes past the end of the file on disk.
   - Dynamic segment `PT_DYNAMIC` is located at offset `0x144cf8`, also beyond EOF.
2. **Forensic Verdict:**
   - `libmfxkit.so` was extracted with truncated byte length in the original vendor archive.
   - Classification: `TRUNCATED_BINARY_TOOL_LIMITATION`.
   - Relevance to Hair: **ZERO**. `libmfxkit.so` contains audio/music DSP algorithms and has no connection to graphics, hair coloring, neural segmentation, or color spaces.

---

## 3. Dynamic Analysis Test Plan on Physical Runner (Galaxy A50 / SM-A075F)

To resolve any dynamic memory dispatch in follow-up tasks:

1. **Test Harness Setup:**
   - Connect target device (`SM-A075F` or `SM-A507FN`) via ADB.
   - Deploy `app-debug.apk` with `frida-server` active on port 27042.

2. **JNI Dynamic Hooking Script:**
   ```javascript
   Interceptor.attach(Module.findExportByName("libart.so", "_ZN3art3JNI15RegisterNativesEP7_JNIEnvP7_jclassPK15JNINativeMethodi"), {
       onEnter: function(args) {
           var env = args[0];
           var javaClass = Java.vm.tryGetEnv().getClassName(args[1]);
           var methods = args[2];
           var count = args[3].toInt32();
           console.log("[RegisterNatives] Class: " + javaClass + " Count: " + count);
       }
   });
   ```

3. **Memory Dump Protocol:**
   - Capture live memory pages of `libmfxkit.so` and `libARKernelInterface.so` directly from process `/proc/<pid>/maps` to verify in-memory vtable pointers.