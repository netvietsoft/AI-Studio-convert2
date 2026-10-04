# 08. TASK_038 VERIFIED INTAKE MANIFEST & GATED CROSS-REFERENCE

This manifest defines the authoritative, verified inputs that `TASK_038` (Hair Algorithm Intake & Reverse-Engineering Cross-Reference) is permitted to consume.

---

### 1. CATEGORY A: VENDOR BINARY GROUND TRUTH (STRICT READ-ONLY)

Source Location: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a`
Verified Count: Exactly 45 shared libraries (100% byte-match to TASK_036 baseline).

The **5 Authoritative Hair-Related Vendor Libraries** for TASK_038 reverse-engineering:

| Library Name | Size | SHA-256 | Hair Algorithmic Role | Permitted Analysis |
| :--- | :--- | :--- | :--- | :--- |
| **`libMTFilterKernel.so`** | 1,858,440 B | `F938FE73095FCEBA72875D1AB42F8AEB6A9F31F3933831BEC070404C0E7ECAC4` | Contains `MTSoftHairFilter`, `GrayFilter`, `HairMask`, `BlurH/V`, `PsSoftLight` | String extraction, disassembly of soft-light blending math |
| **`libarkernel3.so`** | 17,786,488 B | `E08C1D494EEF98759AA92594CA26420E097DF51965A4407CC639A97BBAF35442` | Contains `MakeupHairSoftPart`, Hair shaders, `requireHairMask` (CPU/GPU) | Shader extraction, uniform parameter mapping |
| **`libManis.so`** | 9,928,576 B | `19DAF9B4B1718C843169D68391E99A27D10BD3CECE52226C887C3AB9B93DDDC2` | Neural inference engine for hair matting and BiSeNet parsing | Model input/output tensor dimensions, normalization params |
| **`libLayerFlow.so`** | 5,544,776 B | `EF8D1581038778B72ABCA3CA8FD5046E49FD44E0465871B023647FE42A582262` | Contains `LFDenseHairModular`, `decodeHairDyeConfig`, `loadHairDyeConfig` | Config JSON schema, dye preset parameter structures |
| **`libPVGColorFunctions.so`**| 380,224 B | `3AAB7535EEFD304FEF426EFD49C1FEE51300261EDC766CDC551355C3EEBB04E6` | Color space transforms, ICC profile evaluation, Display-P3 / sRGB | Color matrix coefficients, gamma curves |

---

### 2. CATEGORY B: VENDOR BYTECODE GROUND TRUTH

Source Location: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src`
Permitted Files:
- `com/meitu/core/MTFilterKernelConfigJNI.java`
- `com/meitu/mtlab/arkernel3/arkernel3JNI.java`
- `com/meitu/media/mtmvcore/MTMVTimeLine.java`
- Decompiled hair color config models and asset loaders in `com/meitu/library/...`

---

### 3. CATEGORY C: PROJECT RECONSTRUCTED C++ REFERENCE ASSETS

Source Locations:
- V1: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp`
- CONVERT2: `lib-core-graphics/src/main/cpp`

Permitted Uses:
- Reference design for algorithm structures, color science math (OKLab, CIELAB Delta E), and Vulkan compute shader organization.
- Verification of test harnesses and benchmark methodology.

---

### 4. GATED INTAKE RULES & PROHIBITIONS

1. **NO CONFLATION OF PROVENANCE**:
   TASK_038 must explicitly distinguish between observations derived from vendor binary decompilation (Category A/B) and project-reconstructed C++ code (Category C).
2. **NO SEARCH FOR PROJECT SYMBOLS IN VENDOR .SO**:
   TASK_038 must never expect `MeituNativeEngine` or project class names to exist in vendor binaries.
3. **DO NOT MODIFY FROZEN SOURCE**:
   P0 BiSeNet preprocessing and frozen scopes must remain strictly read-only.
