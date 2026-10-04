# 06. JNI BRIDGE PROVENANCE & SYMBOL MAPPING

This document examines the JNI architecture of `jni_bridge.cpp` across V1 and CONVERT2 and proves its relationship to Java/Kotlin declarations and vendor shared libraries.

---

### 1. JNI ENTRYPOINT QUANTITATIVE COMPARISON

| Metric | V1 `jni_bridge.cpp` | CONVERT2 `jni_bridge.cpp` | Common | Discrepancy Notes |
| :--- | :--- | :--- | :--- | :--- |
| **File Size** | 159,018 bytes | 169,051 bytes | N/A | CONVERT2 +10,033 bytes |
| **Total Lines** | 4,385 lines | 4,538 lines | N/A | CONVERT2 +153 lines |
| **JNI Export Methods** | **165 methods** | **192 methods** | **128 methods** | 37 V1 only, 64 CONVERT2 only |
| **Header Inclusions** | 20 headers | 43 headers | 18 headers | CONVERT2 adds Vulkan, AI models, Body Beauty |
| **Target Shared Library** | `libmeitu_reborn_native.so` | `libmeitu_reborn_native.so` | Identical | Target name preserved across phases |

---

### 2. JNI METHOD CATEGORY BREAKDOWN

| Category | V1 Count | CONVERT2 Count | Common | Evolutionary Trend |
| :--- | :--- | :--- | :--- | :--- |
| **Hair Color & Dye** | 21 | 24 | 16 | Refactored from procedural calls to `HairPipelineV2` & `HairGpuBackend` |
| **3D Face Mesh & Relight** | 18 | 19 | 18 | Stable across V1 and CONVERT2 |
| **Facial Retouch (Eyes, Skin, Nose)**| 42 | 44 | 42 | Full 104-feature face beauty support |
| **Body Beauty & Anatomy** | 36 | 45 | 28 | CONVERT2 added background protection & rigid accessory shields |
| **AI Segmentation & Pose** | 12 | 18 | 10 | CONVERT2 added MoveNet & Selfie Human Parsing |
| **Video Editor & Timeline** | 16 | 22 | 8 | CONVERT2 added `MTMVTimeLine` and `MTMVGroup` native bindings |
| **Vulkan & Hardware Diagnostics** | 0 | 6 | 0 | CONVERT2 exclusive (Vulkan trace, device info, GPU benchmarks) |
| **General Utilities & Filters** | 20 | 14 | 6 | Consolidated into core modules |
| **Total** | **165** | **192** | **128** | **Net +27 methods in CONVERT2** |

---

### 3. KOTLIN/JAVA BINDING PROVENANCE

In both V1 and CONVERT2, 100% of the `native*` methods in `jni_bridge.cpp` bind to:
```kotlin
package com.meitu.core.nativeengine

class MeituNativeEngine { ... }
```

**Forensic Decompilation Cross-Check**:
- An automated text search across all 16 decompiled `.dex` files in `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src` yielded **zero occurrences** of `MeituNativeEngine`.
- Original Meitu APK used individual library JNI bindings:
  - `com.meitu.core.MTFilterKernelConfigJNI` (bound to `libMTFilterKernel.so`)
  - `com.meitu.mtlab.arkernel3.arkernel3JNI` (bound to `libarkernel3_android.so`)
  - `com.meitu.mtaimodelsdk.utils.AIModelKitJni` (bound to `libAIModelKit.so`)
- In CONVERT2, the native methods of `com.meitu.media.mtmvcore.MTMVTimeLine` and `MTMVGroup` were routed through `jni_bridge.cpp` to provide a cleanroom C++ implementation of Meitu's video timeline engine.

---

### 4. GOVERNANCE RULE: SEPARATION OF JNI EVIDENCE

> **MANDATORY INVARIANT FOR TASK_038 & FUTURE ENGINEERING**:
> `jni_bridge.cpp` represents the **cleanroom API bridge** engineered for `libmeitu_reborn_native.so`.
> **DO NOT** treat method names in `jni_bridge.cpp` (such as `nativeApplyHairDye` or `nativeProcessHairEngine`) as evidence of how functions were named inside original vendor libraries (`libMTFilterKernel.so`, `libarkernel3.so`, etc.).
> Original vendor symbols must only be verified through ELF dynamic symbol tables (`.dynsym`) as cataloged in TASK_036 (`04_JNI_EXPORT_MAP.csv`).
