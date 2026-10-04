# 07. HAIR SOURCE CODE DEEP FORENSIC PROVENANCE

This document analyzes the 21 Hair Priority Files across V1 and CONVERT2, tracing their architectural evolution, algorithm fidelity, and GPU acceleration.

---

### 1. THE 21 HAIR PRIORITY FILES AUDIT TABLE

| # | File Name | V1 Size | V1 Lines | CONVERT2 Counterpart | CONVERT2 Lines | Evolution & Relationship |
| :- | :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | `hair_v2_pipeline.cpp` | 9,346 B | 272 | `src/hair/hair_pipeline_v2.cpp` | 1,489 | Procedural pipeline refactored into 10-stage decoupled OOP engine |
| 2 | `hair_v2_flow.cpp` | 5,389 B | 163 | `src/hair/hair_orientation_engine.cpp` | 237 | Merged into `HairOrientationEngine` + GPU compute `hair_flow_cs.comp` |
| 3 | `hair_v2_flow_regularizer.cpp` | 7,369 B | 224 | `src/hair/hair_orientation_engine.cpp` | 237 | Integrated into vector field regularization & confidence weighting |
| 4 | `hair_v2_directional_filter.cpp` | 3,080 B | 98 | `src/hair/hair_orientation_engine.cpp` | 237 | Integrated into directional flow filtering |
| 5 | `hair_v2_texture.cpp` | 4,626 B | 148 | `src/hair/hair_texture_engine.cpp` | 192 | Refactored into `HairTextureEngine` (high/low frequency decomposition) |
| 6 | `hair_v2_specular.cpp` | 5,250 B | 154 | `src/hair/hair_anisotropic_specular_engine.cpp` | 114 | Refactored into `HairAnisotropicSpecularEngine` + `hair_lighting_cs.comp` |
| 7 | `hair_v2_relighting.cpp` | 1,600 B | 51 | `src/hair/hair_anisotropic_specular_engine.cpp` | 114 | Integrated into anisotropic sheen and specular highlight preservation |
| 8 | `hair_v2_base_tone.cpp` | 2,579 B | 82 | `src/hair/hair_color_pipeline.cpp` | 162 | Integrated into `HairColorPipeline` base tone compensation |
| 9 | `hair_v2_lift_curve.cpp` | 1,818 B | 61 | `src/hair/hair_color_pipeline.cpp` | 162 | Integrated into dye response curve calculations |
| 10 | `hair_v2_color.cpp` | 2,689 B | 88 | `src/hair/hair_color_pipeline.cpp` | 162 | Integrated into sRGB/Linear transcode & chroma compression |
| 11 | `hair_v2_lab.cpp` | 4,132 B | 126 | `src/hair/hair_color_pipeline.cpp` | 162 | CIELAB transcode & Delta E 2000 color distance calculations |
| 12 | `hair_v2_oklab.cpp` | 1,492 B | 49 | `src/hair/hair_dye_material_engine.cpp` | 185 | OKLab color space transcode for perceptual dye uniformity |
| 13 | `hair_v2_dye.cpp` | 3,404 B | 108 | `src/hair/hair_dye_material_engine.cpp` | 185 | Refactored into `HairDyeMaterialEngine` (perceptual dye synthesis) |
| 14 | `hair_v2_barrier.cpp` | 3,911 B | 122 | `src/hair/hair_gpu_backend.cpp` | 985 | Refactored into GPU barrier & anatomical zero-leakage protection |
| 15 | `hair_v2_trimap.cpp` | 3,385 B | 105 | `src/hair/hair_appearance_engine.cpp` | 178 | Refactored into `HairAppearanceEngine` (trimap & crevice estimation) |
| 16 | `hair_v2_matting.cpp` | 6,145 B | 185 | `src/hair/hair_appearance_engine.cpp` | 178 | Alpha refinement and edge transition math in `HairAppearanceEngine` |
| 17 | `hair_engine.cpp` | 33,482 B | 865 | `src/hair_engine.cpp` | 923 | Classical Hair Engine: 89% common code, CONVERT2 added Vulkan dispatch |
| 18 | `hair_matting_engine.cpp` | 30,748 B | 720 | `src/hair_matting_engine.cpp` | 1,027 | Classical Matting Engine: 50% common code, CONVERT2 added BiSeNet guard |
| 19 | `hair_strand_dye.cpp` | 14,326 B | 336 | `src/hair_strand_dye.cpp` | 290 | Strand Dye Engine: 72% common code, optimized memory allocations |
| 20 | `hair_orientation_engine.cpp`| 4,905 B | 156 | `src/hair/hair_orientation_engine.cpp` | 237 | Refactored from flat `src/` to modular `src/hair/` |
| 21 | `hair_daub.cpp` | 4,150 B | 118 | `src/hair_daub.cpp` | 114 | Manual Hair Daub Tool: 97.4% identical across V1 and CONVERT2 |
| -- | `jni_bridge.cpp` | 159,018 B | 4,385 | `src/jni_bridge.cpp` | 4,538 | Unified JNI entrypoint: 64.1% identical, CONVERT2 expanded |

---

### 2. ARCHITECTURAL COMPARISON: V1 VS CONVERT2

```
V1 Hair Architecture (Oct 2, 2026):
  meitu::reborn::hair_v2::processHairPipelineV2()
    ├── hair_v2_trimap & hair_v2_matting (CPU Integral Image)
    ├── hair_v2_flow & regularizer (CPU Gaussian + Vector Field)
    ├── hair_v2_texture (CPU High-Pass / Low-Pass Decomposition)
    ├── hair_v2_base_tone & lift_curve (CPU Tone Response)
    ├── hair_v2_dye & oklab / lab (Perceptual Dye Transfer)
    └── hair_v2_specular & relighting (Anisotropic Sheen & Highlights)

CONVERT2 Hardened Architecture (Oct 3-4, 2026):
  HairPipelineV2::getInstance().executePipelineV2()
    ├── BiSeNetFaceParser & SelfieHumanParser (Dual AI Guidance)
    ├── HairOrientationEngine (Vector field + Tensor regularizer)
    ├── HairTextureEngine (Directional frequency decomposition)
    ├── HairAppearanceEngine (Shadow crevices & Highlight masks)
    ├── HairDyeMaterialEngine (OKLab dye synthesis & Presets)
    ├── HairAnisotropicSpecularEngine (Kajiya-Kay specular sheen)
    └── HairGpuBackend (Vulkan Compute Hardware Acceleration)
          ├── hair_flow_cs.spv (Vulkan Compute Orientation)
          ├── hair_lighting_cs.spv (Vulkan Compute Lighting)
          └── hair_composite_cs.spv (Vulkan Compute Alpha Blend)
```

**Key Takeaways for Future Engineering**:
1. V1's procedural `hair_v2_*.cpp` code served as the reference algorithm baseline.
2. CONVERT2 reorganized this into single-responsibility modular classes and created Vulkan compute shaders (`shaders/*.comp`) to achieve sub-4ms GPU latency on mobile devices (Galaxy A50s / Helio G99).
3. Neither implementation is vendor original code; both are high-value project-reconstructed engineering assets.
