# 05. DUPLICATE VS UNIQUE SOURCE ANALYSIS

**Authority**: Chủ tịch Tony  
**Task ID**: `TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY_CLASSIFICATION_ACTIVE`  
**Command ID**: `TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY_20261004T103500+0700`  
**Authoritative Scan Root**: `F:\CONVERT`  

---

## 1. Executive Summary

A cryptographic SHA-256 hash comparison and relative path crosswalk were executed between the active repository `CONVERT2` and the candidate source trees across `F:\CONVERT`.

### Key Conclusions:
1. **`CONVERT\apps\android\core\native-bridge\src\main\cpp` vs `CONVERT2\lib-core-graphics\src\main\cpp`**:
   - Total V1 C++ source files: **50**
   - **Identical Files (Exact SHA-256 match)**: **15 files (30%)**
   - **Diverged / Evolved Files**: **14 files (28%)**
   - **Completely Unique / Missing in CONVERT2**: **21 files (42%)**
2. **`CONVERT\apps\android\feature` vs `CONVERT2`**:
   - `CONVERT\apps\android` contains **19 feature modules**.
   - CONVERT2 is streamlined for Hair & Core Graphics, meaning modules like `feature:community`, `feature:idphoto`, `feature:puzzle`, `feature:drafts`, `feature:poster` are **100% unique to V1** and do not exist in CONVERT2.
3. **`_stray_backup_w9`**:
   - Proved cryptographically to be a **stale duplicate backup** of `CONVERT\apps\android\feature\community` created in Week 9 (September 22, 2026).
   - Contains 23 Kotlin files, 14 of which have byte-identical SHA-256 matches with `CONVERT\apps\android\feature\community`.
   - **Recommendation**: DO NOT import into CONVERT2. Maintain only in historical backup state.

---

## 2. Detailed C++ File Crosswalk & Hash Verification

### Group A: Identical Files (15 Files — 100% Bit-for-Bit Matches)
These files were copied directly from V1 into CONVERT2 during initial repository setup and remain unchanged:
1. `adaptive_temporal_stabilizer.cpp`
2. `advanced_tone_engine.cpp`
3. `beard_dye_engine.cpp`
4. `body_hair_engine.cpp`
5. `camera_shutter_pipeline.cpp`
6. `color_lut.cpp`
7. `eye_retouch_engine.cpp`
8. `face_mesh_3d.cpp`
9. `face_relight.cpp`
10. `face_reshape_3dmm.cpp`
11. `face_retouch_detail.cpp`
12. `hair_daub.cpp`
13. `landmark_fusion.cpp`
14. `nose_mouth_engine.cpp`
15. `teeth_ear_engine.cpp`

### Group B: Diverged / Modified Files (14 Files)
These files originated in V1 but were refactored or hardened in CONVERT2 for Vulkan P6 compute support, memory coherency, or updated architecture:
1. `bisenet_face_parser.cpp` (Moved to `src/ai/bisenet_face_parser.cpp` in CONVERT2)
2. `dense_facemesh_478.cpp` (Upgraded NDK buffer handling)
3. `face_tracking.cpp` (Optimized latency)
4. `hair_engine.cpp` (Refactored to delegate to `hair_color_pipeline.cpp`)
5. `hair_matting_engine.cpp` (Refactored for Vulkan Host-Coherent memory)
6. `hair_orientation_engine.cpp` (Moved to `src/hair/hair_orientation_engine.cpp`)
7. `hair_strand_dye.cpp` (Adapted for Vulkan / CPU A/B parity)
8. `id_photo_collage_engine.cpp` (Standalone layout fixes)
9. `jni_bridge.cpp` (Expanded JNI registrations in CONVERT2)
10. `liquify_warp.cpp` (Freeform liquify warp hardening)
11. `ncnn_face_engine.cpp` (NCNN Vulkan GPU pipeline binding)
12. `portrait_matting.cpp` (Trimap optimization)
13. `yuv_converter.cpp` (SIMD NEON acceleration)
14. `beauty/beauty_video_connector.cpp` (Video timeline adapter)

### Group C: Unique to V1 / Missing in CONVERT2 (21 Files)
These files represent valuable V1 implementations that were NOT transitioned into CONVERT2:
- **16 Modular Hair Algorithm Files (`hair_v2_*.cpp`)**:
  1. `hair_v2_barrier.cpp`: Edge barrier and zero-leakage boundary enforcement.
  2. `hair_v2_base_tone.cpp`: Base hair melanin and undertone neutralizer.
  3. `hair_v2_color.cpp`: Color space transformations for hair dye.
  4. `hair_v2_directional_filter.cpp`: Gabor directional filtering along hair strands.
  5. `hair_v2_dye.cpp`: Multi-pass hair dye layer compositor.
  6. `hair_v2_flow.cpp`: Hair flow field vector estimation.
  7. `hair_v2_flow_regularizer.cpp`: Smoothness constraint on strand vector fields.
  8. `hair_v2_lab.cpp`: CIELAB perceptual color adjustments.
  9. `hair_v2_lift_curve.cpp`: Bleaching / lifting tone curves.
  10. `hair_v2_matting.cpp`: KNN / Guided filter alpha matte refiner.
  11. `hair_v2_oklab.cpp`: Oklab perceptual color blending routines.
  12. `hair_v2_pipeline.cpp`: Complete multi-stage hair processing orchestrator.
  13. `hair_v2_relighting.cpp`: Ambient and specular relighting on hair volume.
  14. `hair_v2_specular.cpp`: Marschner anisotropic hair specular highlights.
  15. `hair_v2_texture.cpp`: High-frequency hair texture detail preservation.
  16. `hair_v2_trimap.cpp`: Morphological trimap generation from segmentation mask.
- **5 Specialized Beauty & Graphics Engines**:
  17. `full_body_beauty_engine.cpp`: Full-body proportions, leg lengthening, waist narrowing.
  18. `head_cranial_engine.cpp`: Cranial top lift and head shape adjustment.
  19. `insightface_106.cpp`: 106-point landmark model inference.
  20. `semantic_zero_leakage_guard.cpp`: Multi-class semantic boundary protection.
  21. `skin_texture_retouch.cpp`: Frequency separation micro-pore skin retouching.

---

## 3. High-Level Unique Assets & Feature Modules in V1

| Directory / Subsystem | Unique to V1? | File Count | Description & Potential Value for CONVERT2 |
|---|---|---|---|
| `CONVERT/apps/android/feature/community` | **YES** | 24 | Community feed, search, topic publish, Ktor REST client. |
| `CONVERT/apps/android/feature/idphoto` | **YES** | 12 | ID photo background cutout and suit overlay. |
| `CONVERT/apps/android/feature/puzzle` | **YES** | 15 | Photo grid collages and puzzle templates. |
| `CONVERT/apps/android/feature/livephoto` | **YES** | 8 | Motion picture / live photo viewer and editor. |
| `CONVERT/apps/android/feature/videoedit` | **YES** | 18 | Video timeline, multi-track audio, clip trimming. |
| `CONVERT/apps/android/core/native-bridge/src/main/cpp/src/media/cloth` | **YES** | 2 | PBD cloth simulation and virtual try-on engine. |
| `CONVERT/apps/android/core/native-bridge/src/main/cpp/src/media/video` | **YES** | 3 | NDK video decoder, video timeline compositor. |

---

## 4. Policy on Duplicate Trees

1. **No Overwrite**: CONVERT2 active source files MUST NOT be overwritten with V1 code. CONVERT2 contains hardened Vulkan P6 implementations that supersede V1 CPU-only routines.
2. **Selective Extraction Only**: When future tasks (such as P7 or full-body expansion) require features from V1 (e.g., `full_body_beauty_engine.cpp` or `feature:idphoto`), they must be imported via gated, reviewable tasks.
3. **No Duplicate Upload**: Stale duplicate folders like `_stray_backup_w9` must remain ignored and not committed to Git.
