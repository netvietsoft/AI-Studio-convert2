# 06. HAIR-SPECIFIC & JNI SOURCE HITS ANALYSIS

**Authority**: Chủ tịch Tony  
**Task ID**: `TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY_CLASSIFICATION_ACTIVE`  
**Command ID**: `TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY_20261004T103500+0700`  
**Authoritative Scan Root**: `F:\CONVERT`  

---

## 1. Hair & JNI Keyword Occurrence Matrix Across Workspaces

An exhaustive search for the 16 mandatory hair, matting, segmentation, and JNI symbols was executed across all candidate trees in `F:\CONVERT`. The quantitative results are presented below:

| Keyword / Symbol | CONVERT2 (V2 Active) | CONVERT (V1 Full) | V1 C++ Engine (`native-bridge`) | Meitu SOURCE (`jadx_src` + `.so`) | Facetune CONVERT | Facetune SOURCE | Root Docs (`1.txt`-`5.txt`) |
|---|---|---|---|---|---|---|---|
| `hair` | **4,839** | 1,494 | 298 | 55 (bytecode + names) | 1,081 | 229 | 1,103 |
| `dye` | **363** | 296 | 101 | 8 | 3 | 1 | 4 |
| `matting` | **438** | 100 | 16 | 0 (in names) | 0 | 0 | 2 |
| `segment` | **837** | 633 | 2 | 372 | 91 | 6 | 97 |
| `parsing` | **608** | 78 | 0 | 1 | 71 | 0 | 74 |
| `MTSoftHairFilter` | **21** | 0 | 0 | **PRESENT** (Vendor Java) | 0 | 0 | 0 |
| `HairMaskFilterToFBO` | **7** | 0 | 0 | **PRESENT** (Vendor Java) | 0 | 0 | 0 |
| `MakeupHairSoftPart` | **7** | 0 | 0 | **PRESENT** (Vendor Java) | 0 | 0 | 0 |
| `nSetTraditionHairDyeIntensityAndShine` | **8** | 0 | 0 | **PRESENT** (Vendor Native) | 0 | 0 | 0 |
| `RegisterNatives` | **5** | 0 | 0 | **PRESENT** (Vendor .so) | 0 | 0 | 0 |
| `JNI_OnLoad` | **24** | 0 | 0 | **PRESENT** (Vendor .so) | 1 | 1 | 1 |
| `external fun` | **553** | 449 | 0 | 0 | 197 | 0 | 199 |
| `native ` | **1,335** | 488 | 59 | 1 | 71 | 7 | 75 |
| `CMakeLists` | **93** | 34 | 0 | 0 | 0 | 0 | 0 |
| `HairPipeline` | **186** | 7 | 2 | 0 | 0 | 0 | 0 |
| `FaceParsing` | **63** | 24 | 10 | 0 | 43 | 0 | 47 |

---

## 2. Comparative Deep Analysis: V1 Native Bridge vs SOURCE Ground Truth

### A. The V1 Native Bridge Finding (`CONVERT\apps\android\core\native-bridge`)
- **Strengths**:
  - Implements **50 complete C++ source files**, including 16 modular `hair_v2_*.cpp` files (`hair_v2_pipeline.cpp`, `hair_v2_matting.cpp`, `hair_v2_dye.cpp`, `hair_v2_flow.cpp`, `hair_v2_specular.cpp`, `hair_v2_texture.cpp`, `hair_v2_lab.cpp`, `hair_v2_oklab.cpp`).
  - Contains full mathematical implementations of Gabor flow field estimation, Oklab color blending, and Marschner anisotropic specular highlights.
- **Critical Limitations (As Proved by TASK_041)**:
  - The JNI bridge (`jni_bridge.cpp`) binds exclusively to `com.mtxx.reborn.core.nativebridge.MeituNativeEngine`.
  - It has **0 hits** for official vendor hair classes (`MTSoftHairFilter`, `HairMaskFilterToFBO`, `MakeupHairSoftPart`).
  - It is an **engineer/agent-reconstructed synthetic facade**, NOT the authentic proprietary vendor C++ code from Meitu Inc.

### B. The Meitu SOURCE Finding (`F:\CONVERT\com.mt.mtxx.mtxx\SOURCE`)
- **Decompiled Bytecode Ground Truth (`jadx_src`)**:
  - `com.meitu.core.processor.MTSoftHairFilter`: The authentic vendor class containing native method declaration:
    ```java
    public static native void nSetTraditionHairDyeIntensityAndShine(long handle, float intensity, float shine);
    ```
  - `com.meitu.hair.HairMaskFilterToFBO`: The authentic vendor FBO filter for hair mask rendering.
  - `com.meitu.makeup.hair.MakeupHairSoftPart`: The authentic vendor makeup segment for soft hair blending.
- **Native Binary Ground Truth (`extracted_native_libs`)**:
  - Contains **45 authentic vendor ARM64 shared libraries**, including `libhair_segment.so`, `libmatting.so`, `libface_parsing.so`, and `libbisenet.so`.
  - These contain authentic `JNI_OnLoad` exports, dynamic symbol tables, and internal pipeline graphs analyzed in TASK_038 and TASK_044.

### C. The CONVERT2 Synthesis
- `CONVERT2` bridges both worlds:
  1. It integrates the algorithmic innovations of V1 (flow fields, specular highlights, Oklab blending) hardened into modern Vulkan compute shaders (`hair_composite_blend.comp`).
  2. It implements vendor-compatible contract metadata and adapter layers matching the ground truth signatures found in `SOURCE`.

---

## 3. Priority Classification for Hair Behavior Reconstruction

| Directory Candidate | Priority Level | Rationale |
|---|---|---|
| `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs` | **PRIORITY 1 (CRITICAL)** | Authoritative vendor binary ground truth (45 ARM64 .so). Contains exact vendor algorithms, exported symbols, and native JNI tables. |
| `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src` | **PRIORITY 1 (CRITICAL)** | Authoritative vendor Java/Kotlin bytecode decompile. Exposes official method signatures, parameters, and FBO pipeline control flow. |
| `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp` | **PRIORITY 2 (HIGH REFERENCE)** | Reconstructed V1 C++ source tree. Rich reference for mathematical formulations (Gabor flow, Marschner specular, Oklab space) and non-hair modules. |
| `F:\CONVERT\com.lightricks.facetune.free\CONVERT` | **PRIORITY 3 (SECONDARY REFERENCE)** | Sibling project hair/retouch reference. Useful for cross-app architecture comparison as noted in `F:\CONVERT\1.txt`. |
