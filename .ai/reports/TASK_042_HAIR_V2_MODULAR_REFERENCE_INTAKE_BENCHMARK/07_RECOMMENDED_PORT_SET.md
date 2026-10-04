# 07. RECOMMENDED PORT SET SPECIFICATION

**Task ID**: `TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK_ACTIVE`  
**Date**: 2026-10-04 12:29:05 +0700  
**Governing Standard**: 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD & Development Workspace Standard V2.1  
**Execution Policy**: SPECIFICATION ONLY — NO CODE MUTATION IN TASK_042  

---

## 1. Prioritized Recommended Port Candidates

Based on the quantitative benchmark results in `05_BENCHMARK_RESULTS.csv` and the algorithm risk matrix in `03_ALGORITHM_VALUE_RISK_MATRIX.md`, the following **6 modular components** are formally recommended for integration in subsequent engineering tasks:

### Priority 1: Steerable Directional Flow Filtering (P1)
- **Source Module**: `hair_v2_directional_filter.cpp` (`applyDirectionalFlowFilter`)
- **Target Location**: `lib-core-graphics/src/main/cpp/src/hair/hair_texture_engine.cpp`
- **Justification**: Proven **+13.2% to +38.9% texture retention gain** on curly hair (Customer 0: +13.2%, Model 4: +38.9%). Eliminates cross-strand blurring.
- **Porting Scope**: Pure mathematical function; takes input image, flow tangents $(t_x, t_y)$, and kernel length. No external dependencies.

### Priority 2: Soft-Knee Tanh Gamut Compression (P2)
- **Source Module**: `hair_v2_color.cpp` (`softChromaCompress`)
- **Target Location**: `lib-core-graphics/src/main/cpp/src/hair/hair_color_pipeline.cpp`
- **Justification**: Eliminates OLED highlight posterization on high-saturation salon presets (Pastel Pink, Navy Blue, Platinum).
- **Porting Scope**: Single inline utility function; operates directly on linear RGB float triplets.

### Priority 3: Axial Nematic Flow Relaxation & BFS Propagation (P3)
- **Source Module**: `hair_v2_flow_regularizer.cpp` (`regularizeHairFlowField`, `propagateFlowIntoLowConfidence`)
- **Target Location**: `lib-core-graphics/src/main/cpp/src/hair/hair_orientation_engine.cpp`
- **Justification**: Resolves 180-degree vector orientation ambiguity and propagates coherent curl flow into dark underexposed locks.
- **Porting Scope**: 4-iteration relaxation pass; operates on existing `HairFlowField` struct.

### Priority 4: Dynamic Highlight Centroid Light Vector Estimation (P4)
- **Source Module**: `hair_v2_specular.cpp` (`estimateImageSpaceLightDirection`)
- **Target Location**: `lib-core-graphics/src/main/cpp/src/hair/hair_anisotropic_specular_engine.cpp`
- **Justification**: Replaces hardcoded 45-degree overhead light angle with true photo illumination direction inferred from hair highlight centroids.
- **Porting Scope**: Stride-4 luminance moment accumulator. Extremely lightweight ($<1$ ms on CPU).

### Priority 5: Marschner Dual-Lobe Anisotropic Specular Sheen (P5)
- **Source Module**: `hair_v2_specular.cpp` (`computeAnisotropicHairSheen`)
- **Target Location**: `lib-core-graphics/src/main/cpp/src/hair/hair_anisotropic_specular_engine.cpp`
- **Justification**: Adds secondary tinted cuticle reflection lobe with $3^\circ$ longitudinal tilt, enhancing natural glossiness on straight and blonde hair.
- **Porting Scope**: Replaces single-lobe Kajiya-Kay in `HairAnisotropicSpecularEngine`.

### Priority 6: Secondary Landmark Polygon Geometric Barrier (P6)
- **Source Module**: `hair_v2_barrier.cpp` (`pointInPolygon`, `buildHairBarrierMask`)
- **Target Location**: `lib-core-graphics/src/main/cpp/src/hair/hair_pipeline_v2.cpp`
- **Justification**: Provides redundant geometric protection for forehead and ears, guarding against sporadic BiSeNet segmentation jitter.
- **Porting Scope**: Invoked only when 106-point landmark mesh is present.

---

## 2. Explicitly Rejected / Prohibited Components

| Component | Source File | Rejection Rationale |
|---|---|---|
| **Pipeline Coordinator** | `hair_v2_pipeline.cpp` | **STRICTLY REJECTED**: Monolithic CPU-only coordinator lacks Vulkan compute shader dispatch and Android JNI integration. Replacing CONVERT2 `HairPipelineV2` would destroy GPU acceleration. |
| **Dye Transfer & Lift Curves** | `hair_v2_dye.cpp`, `hair_v2_lift_curve.cpp` | **REJECTED**: CONVERT2 V3 Rebuild analytical spline OKLab color transfer is proven superior on physical Samsung Galaxy A50/A07 hardware. |
| **Trimap Generator** | `hair_v2_trimap.cpp` | **REJECTED**: CONVERT2 trimap generator embeds frozen P0 boundary protection logic that must not be disrupted. |
| **Base Melanin Extractor** | `hair_v2_base_tone.cpp` | **REJECTED**: CONVERT2 SIMD base illumination computation is already faster and fully integrated. |
| **4-Band Pyramidal Decomposition** | `hair_v2_texture.cpp` | **DEFERRED**: Requires $2\times$ memory buffers (4 full-frame float planes); CONVERT2 2-band decomposition satisfies performance budgets. |

---

## 3. Implementation Roadmap for Subsequent Task

1. **Step 1**: Implement candidates under feature flags in `lib-core-graphics`.
2. **Step 2**: Add unit tests in `app/src/test/` to verify mathematical equivalence.
3. **Step 3**: Re-run on physical Galaxy A07 and A50s devices to confirm zero regression on the 8 canonical test portraits.
4. **Step 4**: Commit and push with evidence.
