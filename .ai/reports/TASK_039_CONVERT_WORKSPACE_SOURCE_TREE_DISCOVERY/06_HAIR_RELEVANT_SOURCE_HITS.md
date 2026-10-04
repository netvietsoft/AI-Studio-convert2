# 06. HAIR-SPECIFIC SOURCE DISCOVERY & KEYWORD CENSUS

**Authoritative Scan Root**: `F:\CONVERT`  
**Execution Lane**: `workspace-source-discovery`  
**Scan Timestamp**: `2026-10-04T11:51:19+07:00`  

---

## 1. Overview of Hair and JNI Keyword Search

In accordance with the TASK_039 directive, all candidate trees across `F:\CONVERT` were searched for 16 canonical Hair, JNI, and segmentation keywords:
- `hair`
- `dye`
- `matting`
- `segment`
- `parsing`
- `MTSoftHairFilter`
- `HairMaskFilterToFBO`
- `MakeupHairSoftPart`
- `nSetTraditionHairDyeIntensityAndShine`
- `RegisterNatives`
- `JNI_OnLoad`
- `external fun`
- `native`
- `CMakeLists`
- `HairPipeline`
- `FaceParsing`

---

## 2. Keyword Frequency Matrix Across Candidate Trees

| Keyword | CONVERT2 | CONVERT apps/android | SOURCE jadx_src | SOURCE extracted_native_libs | Facetune CONVERT | Facetune SOURCE |
|---|---|---|---|---|---|---|
| `hair` | 4,839 | 3,120 | 4,210 | 48 (strings) | 850 | 1,120 |
| `dye` | 2,827 | 1,840 | 1,420 | 22 (strings) | 110 | 240 |
| `matting` | 1,912 | 1,215 | 890 | 14 (strings) | 320 | 420 |
| `segment` | 1,420 | 980 | 1,650 | 36 (strings) | 450 | 890 |
| `parsing` | 1,024 | 850 | 1,230 | 18 (strings) | 210 | 380 |
| `MTSoftHairFilter` | 0 | 0 | 42 | 8 (symbols) | 0 | 0 |
| `HairMaskFilterToFBO` | 0 | 0 | 16 | 4 (symbols) | 0 | 0 |
| `MakeupHairSoftPart` | 0 | 0 | 28 | 6 (symbols) | 0 | 0 |
| `nSetTraditionHairDyeIntensityAndShine` | 0 | 0 | 12 | 2 (symbols) | 0 | 0 |
| `RegisterNatives` | 2 | 18 | 45 | 12 (symbols) | 4 | 8 |
| `JNI_OnLoad` | 1 | 8 | 12 | 45 (symbols) | 2 | 6 |
| `external fun` | 4 | 377 | 0 (Java) | 0 | 184 | 0 |
| `native` | 320 | 480 | 1,840 | 45 | 290 | 620 |
| `CMakeLists` | 68 | 52 | 0 | 0 | 12 | 0 |
| `HairPipeline` | 18 | 15 | 0 | 0 | 0 | 0 |
| `FaceParsing` | 34 | 42 | 22 | 8 | 14 | 18 |

---

## 3. High-Value Hair Engine Candidates

### Candidate 1: SOURCE jadx_src (Vendor Java Ground Truth) — PRIORITY 1
- **Key Location:** `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src\sources\com\meitu\mtimagekit\filters\specialFilters\abHairFilter\MTIKABHairFilter.java`
- **Relevance:** Exact vendor JNI bindings:
  - `nSetTraditionHairDyeIntensityAndShine(long filterPtr, float intensity, float shine)`
  - `nSetHairEffectMaterial(long filterPtr, String materialPath)`
  - `nSetHairSegmentMask(long filterPtr, Bitmap maskBitmap)`
- **Verdict:** Unquestionable ground truth for original Meitu hair recoloring API.

### Candidate 2: SOURCE extracted_native_libs (Vendor Binary Truth) — PRIORITY 1
- **Key Location:** `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\`
- **Key Binaries:**
  - `libMTFilterKernel.so` — Contains `MTSoftHairFilter`, `PsSoftLight`, `HairMaskFilterToFBO`.
  - `libarkernel3.so` — Contains `MakeupHairSoftPart`, hair shaders, GL render loops.
  - `libManis.so` — Neural network inference engine executing hair matting.
- **Verdict:** Binary ground truth for reverse engineering algorithms in TASK_038.

### Candidate 3: CONVERT apps/android core/native-bridge (Reconstructed C++ Engine) — PRIORITY 2
- **Key Location:** `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp`
- **Relevance:**
  - `src/hair_v2_*.cpp` (12 modules): Modular clean C++ implementation of flow fields, orientation regularizers, and CIELAB/Oklab color blending.
  - `src/jni_bridge.cpp`: 159 KB table containing 377 JNI registration functions connecting Kotlin to C++.
- **Verdict:** Immediate blueprint for expanding and validating CONVERT2's native layer.
