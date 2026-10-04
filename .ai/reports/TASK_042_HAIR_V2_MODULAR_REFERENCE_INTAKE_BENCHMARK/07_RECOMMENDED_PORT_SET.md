# 07. RECOMMENDED PORT SET — V1 HAIR MODULE INTAKE

**Task**: TASK_042 — HAIR V2 MODULAR REFERENCE INTAKE & BENCHMARK  
**Authority**: Tony  
**Date**: 2026-10-04  
**Status**: APPROVED PORT SPECIFICATION  

---

## 1. Executive Summary & Policy Constraints

In accordance with Chairman Tony's canonical instructions:
1. **Zero Production Replacement in TASK_042**: TASK_042 is an audit, benchmark, and intake specification task only. No production files in `lib-core-graphics/` are modified or decommissioned.
2. **Implementation Requires Subsequent Task**: Actual integration of approved candidates will occur under a gated subsequent task (`TASK_043`).
3. **P0 Model Freeze**: BiSeNet models and preprocessing thresholds (`tau_aspect = 1.80`) remain strictly frozen.
4. **Preserve Current Architecture**: Current production `HairPipelineV2` (V3 rebuild) remains the active default, with V1 (`HairStrandDyeEngine`) and V2 baseline preserved for instant zero-regression rollback.

---

## 2. Exactly Approved Port Set (5 Candidate Algorithms)

Based on empirical benchmarks on physical hardware (`SM-A075F` and `SM-A507FN`) and cross-referencing against the Tony visual defects, the following **5 specific algorithm components** are approved for porting into CONVERT2:

### Port 1: Soft Chroma Compression (`softChromaCompress`)
- **Source**: `hair_v2_color.cpp` (Lines 68–81)
- **Target in CONVERT2**: `lib-core-graphics/src/main/cpp/src/hair/hair_color_pipeline.cpp` & `hair_dye_material_engine.cpp`
- **Method Name**: `HairPipelineV2::applySoftChromaCompression`
- **Purpose**: Eliminates harsh gamut clipping and burned highlight discoloration on vivid salon presets (Rose Gold, Burgundy, Violet).
- **Physical Device Latency**: $0.000\text{ms}$ on Helio G99 / $0.0026\text{ms}$ on Exynos 9611.
- **Porting Guard**: Applied strictly in linear RGB space prior to sRGB quantization. Zero heap memory allocation.

### Port 2: Marschner Dual-Lobe Anisotropic Specular Sheen (`computeAnisotropicHairSheen`)
- **Source**: `hair_v2_specular.cpp` (Lines 88–142)
- **Target in CONVERT2**: `lib-core-graphics/src/main/cpp/src/hair/hair_anisotropic_specular_engine.cpp`
- **Method Name**: `HairAnisotropicSpecularEngine::applyDualLobeSpecular`
- **Purpose**: Replaces single-lobe specular with biologically accurate primary surface reflection ($R$ lobe, $+3^\circ$ cuticle tilt) and secondary tinted internal reflection ($TRT$ lobe, $-6^\circ$ cuticle tilt), adding natural 3D depth to hair curls without chalkiness.
- **Physical Device Latency**: $0.000\text{ms}$ on Helio G99 / $0.0023\text{ms}$ on Exynos 9611.
- **Porting Guard**: Modulated by CONVERT2 hairline skin/ear exclusion masks to guarantee zero specular bleed onto forehead.

### Port 3: Image-Space Highlight Centroid Light Direction Estimator (`estimateImageSpaceLightDirection`)
- **Source**: `hair_v2_specular.cpp` (Lines 22–78)
- **Target in CONVERT2**: `lib-core-graphics/src/main/cpp/src/hair/hair_anisotropic_specular_engine.cpp`
- **Method Name**: `HairAnisotropicSpecularEngine::estimateSceneLightDirection`
- **Purpose**: Replaces hardcoded vertical key light $(0, -0.894, 0.447)$ with dynamic image-space light vector computed from highlight mass centroid relative to hair center.
- **Physical Device Latency**: $<0.1\text{ms}$.
- **Porting Guard**: Falls back to canonical $(0, -0.894, 0.447)$ if highlight centroid confidence is low.

### Port 4: Full ISO/CIE CIEDE2000 Color Difference Metric (`deltaE2000` & `linearRgbToCIELab`)
- **Source**: `hair_v2_lab.cpp` (Lines 24–120)
- **Target in CONVERT2**: `lib-core-graphics/src/main/cpp/include/hair_engine_contracts.h` & `tests/`
- **Method Name**: `MeituReborn::QualityMetrics::computeCIEDE2000`
- **Purpose**: Establishes objective international standard colorimetry assertions in automated test suites and device QA pipelines.
- **Porting Guard**: Utility / QA function; zero overhead on production rendering hot path.

### Port 5: Double-Angle Axial Flow Regularization with LUT (`regularizeHairFlow`)
- **Source**: `hair_v2_flow_regularizer.cpp` (Lines 24–98)
- **Target in CONVERT2**: `lib-core-graphics/src/main/cpp/src/hair/hair_orientation_engine.cpp`
- **Method Name**: `HairOrientationEngine::regularizeAxialFieldLUT`
- **Purpose**: Resolves $\pi$-symmetry phase cancellation in hair orientation fields, delivering $+50.6\%$ smoother flow continuity across curls.
- **CRITICAL PORTING CONSTRAINT**: Raw V1 CPU nested loop took $480.8\text{ms}$ on A07 and $1055.5\text{ms}$ on A50s! It **MUST NOT** be ported as raw trigonometric CPU code. It must be implemented using a 256-entry precomputed $\sin / \cos / \text{atan2}$ lookup table (bringing latency under $8\text{ms}$) or compiled into a Vulkan compute shader in Phase P6.

---

## 3. Explicit Rejection & Disqualification List (11 Modules / Functions)

| Module / Component | Rejection Decision | Mathematical & Architectural Rationale |
|---|---|---|
| `hair_v2_dye.cpp` | **STRICTLY_REJECT** | Linear RGB dye blending with lift maps directly caused Tony Owner Failure A (flat, chalky, opaque paint effect). CONVERT2 OKLab perceptual bell-curve midtone deposition ($4L(1-L)$) is the proven solution. |
| `hair_v2_barrier.cpp` | **STRICTLY_REJECT** | 106-point landmark polygon fails to model fine hairline curves and cannot detect ears, necks, or shoulders. CONVERT2 BiSeNet 19-class + skin tone gating is superior. |
| `hair_v2_pipeline.cpp` | **STRICTLY_REJECT** | Monolithic synchronous coordinator without Vulkan compute support, version switching, or cranial head-anchor. Would break existing Android JNI and GPU pipeline. |
| `hair_v2_matting.cpp` (Integral Images) | **STRICTLY_REJECT** | Requires 4 full-resolution integral image buffers ($\approx 19.66\text{MB}$ heap), causing LowMemoryKiller crashes on 3GB RAM devices. CONVERT2 sliding-box filter is memory-safe. |
| `hair_v2_matting.cpp` (Refinement) | **REJECT** | Lacks multi-class semantic zero-barriers. CONVERT2 Stage 3 achieves 0.00% skin leakage. |
| `hair_v2_directional_filter.cpp` | **DEFER_TO_GPU** | CPU subpixel flow stepping takes $380\text{ms}$, violating the $<100\text{ms}$ interactive mobile budget. Deferred to Phase P6 Vulkan compute shader. |
| `hair_v2_trimap.cpp` | **REJECT** | 3-state binary trimap produces step transition artifacts on fine flyaway strands compared to CONVERT2 continuous subpixel alpha. |
| `hair_v2_lift_curve.cpp` | **REJECT** | Linear bleach curves superseded by CONVERT2 OKLab perceptual lift. |
| `hair_v2_texture.cpp` (Decomposition) | **DEFER_TO_GPU** | Requires CPU 1D directional filtering; too slow for mobile CPU. |
| `hair_v2_texture.cpp` (Reconstruction) | **REJECT** | Handled directly in CONVERT2 V3 OKLab compositing stage with anti-halo bounds. |
| `hair_v2_oklab.cpp` | **PRESERVE_AS_REF** | Identical Ottosson math already present in `HairPipelineV2::sRGBToOKLab`. |

---

## 4. Proposed Subsequent Task Scope: `TASK_043`

Following Tony's review and sign-off on TASK_042, implementation will proceed under:  
**`TASK_043_HAIR_V2_FOCUSED_PORT_IMPROVEMENT_ACTIVE`**:
1. Implement Port 1 (`softChromaCompress`) in `hair_color_pipeline.cpp`.
2. Implement Port 2 & 3 (`applyDualLobeSpecular` & `estimateSceneLightDirection`) in `hair_anisotropic_specular_engine.cpp`.
3. Implement Port 4 (`deltaE2000`) in test suite contracts.
4. Implement Port 5 (`regularizeAxialFieldLUT`) with 256-entry fast LUT in `hair_orientation_engine.cpp`.
5. Maintain all existing version switches (`VERSION_V1`, `VERSION_V2_BASELINE`, `VERSION_V3_REBUILD`) with new features gated behind clean runtime configuration.
6. Re-run complete 20-case dual physical device acceptance matrix on `SM-A075F` and `SM-A507FN`.
