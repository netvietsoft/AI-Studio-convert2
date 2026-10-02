# PHASE P0-C — PRODUCTION DIFF MAPPING SPECIFICATION

**Phase:** P0-C — Production Integration & Final P0 Acceptance  
**Authority:** Agent 0 — CEO / ORCHESTRATOR  
**Date:** 2026-10-02  
**Target Module:** `lib-core-graphics` (C++ Native Graphics Engine)  
**Governing Document:** `P0_C_PRODUCTION_INTEGRATION_FINAL_P0_ACCEPTANCE_MASTER_AGENT_SPEC.txt` (§5)  

---

## 1. Component Mapping Matrix (Scratch/Candidate ➔ Production)

| Candidate Component (P0-B.2R) | Candidate Prototype Location | Production Target File & Class | Function / Symbol in Production | Architectural Change Type |
| :--- | :--- | :--- | :--- | :--- |
| **Adaptive Aspect-Preserving Letterbox (R2)** | `scratch/run_p0_b2r_geometry_ab.py` (`run_mode_b`) | `lib-core-graphics/.../ai/bisenet_face_parser.cpp` | `BiSeNetFaceParser::parseFace19Adaptive` | Preprocessing Geometry Enhancement |
| **Adaptive Hair Appearance Seed** | `scratch/p0_b2r_device_bench.cpp` (lines 228-250) | `lib-core-graphics/.../hair_matting_engine.cpp` | `HairMattingEngine::computeAppearanceSeed` | Color Normalization & Seed Map |
| **Hair / Hat Disambiguation (Class 18)** | `scratch/p0_b2r_device_bench.cpp` (lines 252-263) | `lib-core-graphics/.../hair_matting_engine.cpp` | `HairMattingEngine::resolveHairHatDisambiguation` | Semantic Label Disambiguation |
| **LowContrastHairResolver (R3 Variant P3)** | `scratch/p0_b2r_device_bench.cpp` (lines 336-370) | `lib-core-graphics/.../hair_matting_engine.cpp` | `HairMattingEngine::resolveLowContrastROIHalfRes` | High-Speed Texture Variance ($O(N/4)$) |
| **SubjectGraph Topological Anchor** | `scratch/run_p0_b2r_full_suite.py` | `lib-core-graphics/.../hair_matting_engine.cpp` | `HairMattingEngine::applySubjectGraph` | Connectivity & Multi-Subject Anchor |
| **ImageContentGuard UI Chrome Guard** | `scratch/run_p0_b2r_full_suite.py` | `lib-core-graphics/.../hair_matting_engine.cpp` | `HairMattingEngine::applyImageContentGuard` | Screen Boundary Reject Mask |
| **Semantic Trimap Generator** | `scratch/p0_b2r_device_bench.cpp` (lines 407-414) | `lib-core-graphics/.../hair_matting_engine.cpp` | `HairMattingEngine::generateSemanticTrimap` | 3-State Trimap ($0.0, 0.5, 1.0$) |
| **Fast Guided Filter ($r=12, s=2$)** | `scratch/p0_b2r_device_bench.cpp` (lines 416-463) | `lib-core-graphics/.../hair_matting_engine.cpp` | `HairMattingEngine::fastGuidedFilter` | Native Multi-Scale Edge-Preserving Filter |
| **Local Color Affinity Matte Refinement** | `scratch/p0_b2r_device_bench.cpp` (lines 465-473) | `lib-core-graphics/.../hair_matting_engine.cpp` | `HairMattingEngine::applyLocalColorAffinity` | Local Palette Matte Regularization |
| **Strict Semantic & UI Protection Masking**| `scratch/p0_b2r_device_bench.cpp` (lines 475-488) | `lib-core-graphics/.../hair_matting_engine.cpp` | `HairMattingEngine::applyStrictProtection` | Hard Class Clamping ($0.0$ on non-hair) |
| **Ear Occlusion Resolver (Conditional)** | `scratch/run_p0_b2_full_suite.py` | `lib-core-graphics/.../hair_matting_engine.cpp` | `HairMattingEngine::resolveEarOcclusion` | Conditional Ear Strand Protection |
| **Texture-Aware Hairline Softening (R1)** | `scratch/run_p0_b2r_exposure_diag.py` | `lib-core-graphics/.../hair_matting_engine.cpp` | `HairMattingEngine::applyTextureAwareHairline` | High-Exposure Hairline Recovery |
| **Full-Resolution Matte Extraction API** | `scratch/p0_b2r_device_bench.cpp` | `lib-core-graphics/.../hair_matting_engine.cpp` | `HairMattingEngine::extractFullSizeMatte` | Master Entry Point for Downstream Engine |

---

## 2. Architectural Dimensions Analysis (Items A to J)

### A. Candidate Components in Scratch
All 12 modules tested in `run_p0_b2r_full_suite.py` and benchmarked on ARM64 hardware in `p0_b2r_device_bench.cpp`.

### B. Corresponding Production Components
- `meitu::ai::BiSeNetFaceParser` in `lib-core-graphics/src/main/cpp/src/ai/bisenet_face_parser.cpp`.
- `meitu_native::HairMattingEngine` in `lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp`.
- Downstream consumer: `HairEngine::analyzeHair` and `HairStrandDyeEngine::applyStrandDye`.

### C. Functions / Classes to Port
- Add `parseFace19Adaptive` to `BiSeNetFaceParser`.
- Overhaul `HairMattingEngine::extractFullSizeMatte` to implement the full P0-B.2R pipeline at native resolution instead of downsampling to 512 followed by blurry bilinear upsampling.
- Retain `extractHairMatte(..., outAlpha512)` as a backward-compatible wrapper that downsamples `fullAlpha` to 512 for legacy consumers (e.g. `id_photo_collage_engine`).

### D. Config & Hyperparameters to Port
Strictly from `scratch/p0_b2r_validation/config/P0_B2R_CONFIG.md`:
- $\tau_{\text{aspect}} = 1.80$ (Mobile screenshot trigger threshold).
- $M_{\text{top}} = 0.90, M_{\text{side}} = 0.60, M_{\text{bottom}} = 0.60$.
- $\tau_{\text{tex\_core}} = 0.05$ (Laplacian texture variance threshold for real hair strand).
- $\alpha_{\text{min\_strand}} = 0.85$.
- Guided filter radius $r = 12$, sub-scale $s = 2$ ($r_{\text{sub}} = 6$).
- Variant P3 Candidate ROI margin: 32 px; downsampling factor: $0.50$.

### E. API / JNI Signature Changes
- **ZERO SIGNATURE CHANGE:**
  - JNI method: `nativeApplyHairStrandDye(JNIEnv*, jclass, jobject bitmap, jint presetId, jfloat intensity, jfloat gloss)` remains identical.
  - C++ API: `HairMattingEngine::extractFullSizeMatte(const uint32_t* pixels, int width, int height, const FusedFaceGeometry& fused, std::vector<float>& outFullAlpha)` remains identical.
  - C++ API: `HairMattingEngine::extractHairMatte(..., std::vector<float>& outAlpha512)` remains identical.
- Caller compatibility: 100% binary & API compatible.

### F. Memory Ownership
- Input: `pixels` buffer owned by Android Bitmap (`AndroidBitmap_lockPixels`), read-only.
- Output: `outFullAlpha` allocated by caller or resized internally to `width * height * sizeof(float)`.
- Internal temporary buffers: Managed via local `std::vector<float>`, automatically deallocated upon function exit. Peak RAM bounded to $\approx 344\text{ MB}$ as verified on Galaxy A075F.

### G. Threading Model
- OpenMP multi-threading with static chunking (`#pragma omp parallel for schedule(static, 32)`) utilizing 4 threads on big.LITTLE ARM cores, consistent with production standards.

### H. Tensor / Image Format
- Input: RGBA_8888 (32-bit unsigned integer per pixel).
- Native conversion: In-place luminance extraction: $L = (0.299R + 0.587G + 0.114B)/255.0$.
- NCNN tensor format: `ncnn::Mat::PIXEL_RGBA2RGB` with ImageNet normalization ($[123.675, 116.28, 103.53]$, $[1/58.395, 1/57.12, 1/57.375]$).

### I. Coordinate Transforms
- Letterbox forward transform: Scale factor $S = \min(512/W, 512/H)$, padding $(512 - W \cdot S)/2, (512 - H \cdot S)/2$.
- Letterbox inverse transform: Unpad $[pad\_y, pad\_y + nh] \times [pad\_x, pad\_x + nw]$, followed by nearest-neighbor mapping back to original $(W, H)$.

### J. Error & Fallback Behavior
- Feature Flag: `HAIR_MATTING_P0_B2R_ENABLED` (Default: `true`).
- If BiSeNet fails to load or inference errors out: Graceful fallback to Landmark Oval Ellipse approximation with zero crash.
- If image dimensions $\le 0$: Return `false` immediately with clean error log.
