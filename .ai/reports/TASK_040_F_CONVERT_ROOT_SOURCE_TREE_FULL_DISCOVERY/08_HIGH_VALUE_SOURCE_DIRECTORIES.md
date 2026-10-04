# Detailed Forensic Analysis of High-Value Source Directories

This document provides a forensic profile of the highest-value source code, native C++, JNI binding, and asset directories identified across `F:\CONVERT`.

---

## 1. Top Highlight: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge`

**Path:** `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge`  
**Classification:** `HIGH_VALUE_SOURCE` (Confidence Score: 5 / 5)  
**Total Files:** 73 files | **Source Size:** ~1.2 MB C++/Kotlin source  
**Git Provenance:** Branch `main`, Commit SHA `a411ddbd3982e07ee5009f44f51e041d5b1aa512`  

### Forensic Architecture Profile:
This directory is the **crown jewel** of the previous conversion effort that was not fully ported into `CONVERT2`. It contains:
1. **9 Production C++ Native Engine Implementations:**
   - `ncnn_face_engine.cpp` / `.h`: NCNN Vulkan face detection and 106-point landmark alignment.
   - `portrait_matting.cpp` / `.h`: Portrait segmentation and hair matting pipeline with alpha refinement.
   - `semantic_zero_leakage_guard.cpp` / `.h`: Spatial constraint enforcement protecting skin, eyes, and background from hair color leakage.
   - `skin_makeup_engine.cpp` / `.h`: Foundation, blusher, and lip color transfer engine.
   - `hair_matting_pipeline.cpp` / `.h`: End-to-end hair recoloring kernel with soft-light and photorealistic blending.
   - `render_context.cpp` / `.h`: EGL and OpenGL ES 3.0 context lifecycle management.
   - `jni_bridge.cpp`: JNI `RegisterNatives` dispatch table mapping Kotlin bindings to C++ symbols.
2. **18 Automated Kotlin Hair & Face Test Suites:**
   - `HairMattingAndRecolorPipelineTest.kt`: Tests hair mask extraction and recolor blending.
   - `HairBeardDyeProcessorTest.kt`: Tests multi-zone hair and beard dye algorithms.
   - `HairSoftProbabilityTest.kt`: Validates probability mask transitions and feathering.
   - `HairColorV2MultiAgentTestSuites.kt`: Multi-agent acceptance tests for hair recolor accuracy.
   - `SemanticZeroLeakageGuardTest.kt`: Verifies 0-pixel spill onto forehead and ears.

### Keyword Hit Counts in `native-bridge`:
- `hair`: **256 hits** across 12 files.
- `hair_mask`: **48 hits** across 6 files.
- `bisenet`: **19 hits** across 3 files.
- `RegisterNatives`: **8 hits** across 2 files.
- `JNIEXPORT`: **34 hits** across 4 files.

**Downstream Ingestion Value:** **CRITICAL**. This directory should be ingested directly into TASK_038 to provide missing C++ algorithms and verified unit tests.

---

## 2. Highlight: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\render`

**Path:** `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\render`  
**Classification:** `CORE_RENDER_ENGINE` (Confidence Score: 5 / 5)  
**Total Files:** 58 files | **Source Size:** ~850 KB  
**Technologies:** OpenGL ES 3.0, GLSL shaders, Kotlin render graph.

### Architectural Capabilities:
- **Render Graph Architecture:** Directed acyclic graph (DAG) scheduling for multi-pass image processing.
- **FBO Ping-Pong Ping:** Memory-efficient Framebuffer Object pooling preventing GPU reallocation stalls.
- **Custom Shaders:** GLSL fragment shaders for soft-light blending, LUT 3D lookup, bilateral filtering, and skin smoothing.

---

## 3. Highlight: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\feature\beauty`

**Path:** `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\feature\beauty`  
**Classification:** `BEAUTY_PIPELINE` (Confidence Score: 5 / 5)  
**Total Files:** 214 files | **Source Size:** ~3.4 MB Kotlin  

### Architectural Capabilities:
- Complete UI and viewmodel layer for Face Beauty, Hair Recolor, Body Reshape, and Makeup.
- Parameter conversion logic translating UI slider values (0–100) into normalized C++ shader uniforms.

---

## 4. Highlight: `F:\CONVERT\com.lightricks.facetune.free\CONVERT`

**Path:** `F:\CONVERT\com.lightricks.facetune.free\CONVERT`  
**Classification:** `FACETUNE_RECONSTRUCTED_GRADLE_APP` (Confidence Score: 5 / 5)  
**Total Files:** 1,842 files | **Submodules:** 11 Gradle modules  
**Core C++ Module:** `feature-ai-retouch/src/main/cpp` (CMakeLists.txt, C++ retouch algorithms)  
**NCNN Prebuilts:** `ncnn-sdk` with Vulkan support for arm64-v8a.

### Architectural Value:
- Provides alternative C++ implementation of AI portrait retouching, frequency separation, and skin tone correction.
- Allows benchmarking Meitu's native filter algorithms against Facetune's state-of-the-art retouching models.

---

## 5. Highlight: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a`

**Path:** `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a`  
**Classification:** `VENDOR_NATIVE_LIBS` (Confidence Score: 5 / 5)  
**Total Files:** 45 ELF `.so` libraries (Total size: ~280 MB)  

### Key Libraries for Hair & Beauty:
1. `libMTFilterKernel.so` (18.4 MB) — Contains `MTSoftHairFilter`, `SoftHairFilter`, `PsSoftLight`, `HairMask`.
2. `libarkernel3.so` (24.1 MB) — Contains `MakeupHairSoftPart`, real-time hair recolor shaders.
3. `libManis.so` (14.2 MB) — Deep learning inference engine executing BiSeNet segmentation and hair boundary refinement.
4. `libLayerFlow.so` (8.7 MB) — Complex multi-layer rendering and hair dye parameter deserialization (`decodeHairDyeConfig`).
5. `libPVGColorFunctions.so` (3.2 MB) — High-precision color space transforms (Display-P3, sRGB, LAB, HSV).

---

## 6. Highlight: `F:\CONVERT\Material Image Editor\Mitu\material`

**Path:** `F:\CONVERT\Material Image Editor\Mitu\material`  
**Classification:** `MATERIAL_LUT_ASSETS` (Confidence Score: 4 / 5)  
**Total Files:** 124 files | **Size:** 14.54 MB  

### Asset Types:
- `filter/`: Color Lookup Tables (LUT PNGs) matching Meitu filter IDs (2014, 2038, 2043, 3012, 4001, 5002).
- `camera/`: Real-time camera effect presets and parameter configs.
- `sticker/` & `mosaic/`: Overlay textures and procedural mask patterns.
