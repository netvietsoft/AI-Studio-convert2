# 07. HAIR SOURCE PROVENANCE & DETAILED AUDIT

## 1. Deep Audit of the 22 Hair Priority Files

| File Name | V1 Size | V1 Lines | C2 Size | C2 Lines | Status | Detailed Comparison & Recommendation |
|---|---|---|---|---|---|---|
| `hair_v2_pipeline.cpp` | 9,346 | 234 | N/A | N/A | **V1_ONLY** | Complete V2 pipeline coordinator (SIMD allocation, sRGB->Linear, matte, flow, dye, relighting). High value for Phase P1-P6 architecture. |
| `hair_v2_flow.cpp` | 5,389 | 158 | N/A | N/A | **V1_ONLY** | Flow vector field generation, gradient tensor structure, bilateral smoothing. |
| `hair_v2_flow_regularizer.cpp` | 7,369 | 204 | N/A | N/A | **V1_ONLY** | Variational flow regularization with divergence minimization. |
| `hair_v2_color.cpp` | 2,689 | 94 | N/A | N/A | **V1_ONLY** | Color blend modes, lift curves, and salon color space conversions. |
| `hair_v2_matting.cpp` | 6,145 | 185 | N/A | N/A | **V1_ONLY** | Alpha matte refinement, guided filter matting, trimap generation. |
| `hair_v2_texture.cpp` | 4,626 | 136 | N/A | N/A | **V1_ONLY** | Hair fiber micro-texture synthesis and high-frequency preservation. |
| `hair_v2_specular.cpp` | 5,250 | 148 | N/A | N/A | **V1_ONLY** | Marschner/Kajiya-Kay anisotropic specular reflection models. |
| `hair_v2_trimap.cpp` | 3,385 | 112 | N/A | N/A | **V1_ONLY** | Dynamic morphological trimap expansion with confidence weights. |
| `hair_v2_barrier.cpp` | 3,911 | 120 | N/A | N/A | **V1_ONLY** | Zero-leakage facial, ear, neck, and clothing boundary barrier enforcement. |
| `hair_v2_base_tone.cpp` | 2,579 | 82 | N/A | N/A | **V1_ONLY** | Natural melanin base neutralization and bleach simulation. |
| `hair_v2_dye.cpp` | 3,404 | 108 | N/A | N/A | **V1_ONLY** | Multi-layer dye transfer with cuticle absorption models. |
| `hair_v2_directional_filter.cpp` | 3,080 | 96 | N/A | N/A | **V1_ONLY** | Steerable Gabor and directional line filters along hair flow. |
| `hair_v2_relighting.cpp` | 1,600 | 54 | N/A | N/A | **V1_ONLY** | Ambient spherical harmonic relighting based on face lighting. |
| `hair_v2_lab.cpp` | 4,132 | 128 | N/A | N/A | **V1_ONLY** | CIE L*a*b* conversion and Delta E color difference calculations. |
| `hair_v2_oklab.cpp` | 1,492 | 52 | N/A | N/A | **V1_ONLY** | Oklab color space transform for perceptually uniform dye blending. |
| `hair_v2_lift_curve.cpp` | 1,818 | 66 | N/A | N/A | **V1_ONLY** | Spline-based tone lift curves for dark Asian hair lightening. |
| `hair_engine.cpp` | 33,482 | 876 | 39,905 | 1,024 | **DIFFERENT** | CONVERT2 version (+6.4KB, +148L) contains newer Vulkan compute shaders and multi-threading hardening. **Keep CONVERT2 active version**. |
| `hair_matting_engine.cpp` | 30,748 | 812 | 39,805 | 1,018 | **DIFFERENT** | CONVERT2 version (+9.0KB, +206L) contains P0 frozen boundary guards and BiSeNet adapter integration. **Keep CONVERT2 active version**. |
| `hair_strand_dye.cpp` | 14,326 | 392 | 11,570 | 318 | **DIFFERENT** | V1 has experimental fiber rendering; CONVERT2 is refactored for cache locality. |
| `hair_orientation_engine.cpp` | 4,905 | 142 | 8,685 | 246 | **DIFFERENT** | CONVERT2 version (+3.7KB, +104L) moved to `hair/` package with enhanced coherence metrics. |
| `hair_daub.cpp` | 4,150 | 128 | 3,956 | 120 | **DIFFERENT** | Virtually equivalent (~95% overlap), minor formatting differences. |
| `jni_bridge.cpp` | 159,018 | 4,212 | 169,051 | 4,539 | **DIFFERENT** | CONVERT2 version (+10.0KB, +327L) includes additional bindings for full human beauty, Vulkan sync, and pose tracking. **Keep CONVERT2 active version**. |

---

## 2. Key Synthesis & Insights

1. **The 16 `hair_v2_*.cpp` files in V1 represent an unintegrated algorithmic asset**:
   They were developed in V1 under `TASK-HAIR-COLOR-V2-02-TO-V2-07` as modular components of the Hair V2 pipeline, but were never imported into CONVERT2 when `lib-core-graphics` was created.
2. **They are NOT vendor code, but high-quality reconstructed C++**:
   They implement state-of-the-art computer graphics algorithms (Oklab blending, directional filtering, Marschner specular, guided filter matting, variational flow).
3. **Safe Intake Recommendation**:
   When downstream Hair engineering occurs, these modular files can be ingested as **reference algorithms** into CONVERT2, provided they do NOT touch frozen P0 models (`tau_aspect = 1.80` and BiSeNet preprocessing).
