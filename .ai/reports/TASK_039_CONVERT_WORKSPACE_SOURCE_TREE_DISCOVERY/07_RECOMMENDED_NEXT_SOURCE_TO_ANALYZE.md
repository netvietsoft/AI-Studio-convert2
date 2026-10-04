# 07. RECOMMENDED NEXT SOURCE DIRECTORIES TO ANALYZE

**Authoritative Scan Root**: `F:\CONVERT`  
**Execution Lane**: `workspace-source-discovery`  
**Context**: Technical Roadmap for TASK_038 and Follow-up Engineering Tasks  

---

## 1. Prioritized Analysis Sequence

Based on physical evidence, completeness, and algorithmic value, the following sequence is recommended for subsequent tasks:

```
[Phase 1: TASK_038 Vendor Hair Engine Deep Dive]
   ├── Step 1: MTIKABHairFilter.java in SOURCE jadx_src
   ├── Step 2: libMTFilterKernel.so & libarkernel3.so in SOURCE extracted_native_libs
   └── Step 3: jni_bridge.cpp (159 KB) in CONVERT apps/android core/native-bridge

[Phase 2: Video & Advanced Media Feature Expansion]
   ├── Step 4: video_timeline_compositor.cpp & ndk_video_decoder.cpp in CONVERT
   └── Step 5: feature:videoedit in CONVERT apps/android

[Phase 3: AI Virtual Try-on & Simulation Expansion]
   ├── Step 6: virtual_tryon_engine.cpp & pbd_cloth_simulator.cpp in CONVERT
   └── Step 7: Material Image Editor/Mitu/material (12 categories)

[Phase 4: Sibling Facetune Retouch Integration]
   └── Step 8: com.lightricks.facetune.free/CONVERT (feature-ai-retouch)
```

---

## 2. Detailed Directory Roadmap

### Priority 1: TASK_038 Hair Recolor JNI & Kernel Decompilation
- **Target 1A (Java JNI Contract):**
  - Path: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src\sources\com\meitu\mtimagekit\filters\specialFilters\abHairFilter\MTIKABHairFilter.java`
  - Goal: Extract full native signature, parameters, color space requirements, and filter chain order.
- **Target 1B (Native Binaries):**
  - Path: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\`
  - Key Binaries: `libMTFilterKernel.so`, `libarkernel3.so`, `libManis.so`.
  - Goal: Disassemble `MTSoftHairFilter::render` and `nSetTraditionHairDyeIntensityAndShine` to extract exact mathematical formulas for PsSoftLight, shine reflection, and opacity curve.
- **Target 1C (JNI Registration Blueprint):**
  - Path: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp\jni_bridge.cpp`
  - Goal: Audit the 377 JNI bindings to verify exact parameter matching between Android Java/Kotlin and native C++.

### Priority 2: Video Editing Subsystem (VideoCore per 2.txt)
- **Path:** `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp\src\media\video\`
- **Files:** `ndk_video_decoder.cpp`, `video_timeline_compositor.cpp`, `frame_pool.cpp`.
- **Goal:** Port the timeline compositing engine into CONVERT2 to support real-time video hair recoloring and facial retouching.

### Priority 3: Virtual Try-On & PBD Cloth Simulation (per 2.txt)
- **Path:** `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp\src\media\cloth\`
- **Files:** `pbd_cloth_simulator.cpp`, `virtual_tryon_engine.cpp`.
- **Goal:** Leverage the Position Based Dynamics engine to implement cloth physics and virtual garment fitting as required by the foundational reference standard `2.txt`.

### Priority 4: Sibling Facetune Engine Cross-Pollination
- **Path:** `F:\CONVERT\com.lightricks.facetune.free\CONVERT\`
- **Modules:** `feature-ai-retouch`, `lib-filters`, `lib-ui-toolkit`.
- **Goal:** Compare Meitu's facial retouching algorithms with Facetune's clean Kotlin architecture to adopt industry-standard UI slider mechanics.
