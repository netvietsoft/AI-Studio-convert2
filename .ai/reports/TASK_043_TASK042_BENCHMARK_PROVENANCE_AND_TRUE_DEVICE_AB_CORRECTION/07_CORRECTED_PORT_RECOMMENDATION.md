# 07. CORRECTED PORT RECOMMENDATIONS & ARCHITECTURAL GATING

**Task**: `TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION_ACTIVE`  
**Governing Standard**: Hiến pháp CONVERT2 — P0 Frozen & Evidence-Based Architecture  

---

## 1. Revised Candidate Module Disposition Matrix

| Candidate V1 Component | Source File | TASK_042 Initial Claim | TASK_043 Empirical Device Finding | Corrected Recommendation |
|---|---|---|---|---|
| **Directional Flow Filter** | `hair_v2_directional_filter.cpp` | Approved (claims +13% to +38% texture) | **REJECTED (FAILED)**: Degrades texture across all cases; severe loss on `male_wavy` (-183.7% vs ridge baseline); +35% to +50% slower. | **STRICTLY REJECT UNGATED PORT**. If revisited, must require content length gating (>5cm) and high coherence ($\kappa \ge 0.45$). |
| **Soft-Knee Tanh Chroma** | `hair_v2_color.cpp` | Approved | **APPROVED**: Eliminates highlight clipping without color distortion (CIEDE2000 $\Delta E < 0.20$); zero runtime overhead. | **STAGE FOR FUTURE PORT** into Vulkan compute shader `hair_composite_blend.comp`. |
| **Secondary Landmark Barrier** | `hair_v2_barrier.cpp` | Approved | **APPROVED**: Provides redundant polygon safety check around forehead and ears without affecting hair region. | **STAGE AS SECONDARY FALLBACK GUARD**. |
| **Nematic Flow Relaxation & BFS** | `hair_v2_flow_regularizer.cpp` | Approved | **DEFERRED**: High CPU overhead (4 iterations + BFS queue); unsuitable for real-time preview unless ported to Vulkan compute. | **DEFERRED TO GPU ONLY**. |
| **Marschner Dual-Lobe Sheen** | `hair_v2_specular.cpp` | Approved | **APPROVED IN PRINCIPLE**: Already partially present in CONVERT2 `HairAnisotropicSpecularEngine`. | **KEEP EXISTING CONVERT2 IMPLEMENTATION**. |

---

## 2. Production Rollback and Non-Regression Guarantee

1. **Production Code Left 100% Untouched in TASK_043**:
   - `lib-core-graphics/src/main/cpp/src/hair/hair_pipeline_v2.cpp` remains exactly at baseline commit `c31b9a4d87e893f5b7d2d3367eb040de81fe935d`.
   - `tau_aspect = 1.80` remains strictly frozen and immutable.
   - P0 BiSeNet preprocessing and segmentation heuristics are 100% intact.
2. **Zero Risk to Physical Production APK**:
   - No experimental or unverified algorithms have breached the production engine boundary.
