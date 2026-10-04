# 05. DUPLICATE VS UNIQUE SOURCE ANALYSIS: F:\CONVERT

**Authoritative Scan Root**: `F:\CONVERT`  
**Baseline Repository**: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2`  
**Execution Lane**: `workspace-source-discovery`  

---

## 1. Summary of Overlap and Unique Code

A comprehensive cryptographic and structural comparison was performed between `CONVERT2` and the candidate source directories across `F:\CONVERT`.

### High-Level Findings:
1. **Zero New Files Uploaded to Git:** In compliance with rule `DISCOVERY_ONLY_NO_SOURCE_MODIFICATION_OR_UPLOAD`, this audit was strictly read-only.
2. **Exact Duplicate Mirrors Identified:**
   - `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\reconstruction-input\java\sources` is a 100% duplicate mirror of `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src\sources` (106,466 identical files).
   - `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\reconstruction-input\native-libs` is a 100% duplicate mirror of `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs` (45 identical `.so` binaries, verified in TASK_036).
3. **C++ Native Engine Lineage (CONVERT V1 vs CONVERT2):**
   - **15 Exact Matches:** Unmodified foundational files shared between V1 and CONVERT2 (`ncnn_face_engine.cpp`, `face_mesh_3d.cpp`, `face_relight.cpp`, `yuv_converter.cpp`, etc.).
   - **16 Evolved Files:** Files substantially rewritten, hardened, and modernized in CONVERT2 (`hair_engine.cpp`, `hair_matting_engine.cpp`, `full_body_beauty_engine.cpp`, `bisenet_face_parser.cpp`, etc.).
   - **33 New Files in CONVERT2:** Vulkan compute pipelines, GPU memory barriers, persistent staging buffers, and headless unit test harnesses created during Phases P1–P6.
   - **32 Unique Files in CONVERT V1:** Valuable legacy files present ONLY in V1 (`hair_v2_barrier.cpp`, `HairBeardDyeEngine.cpp`, `pbd_cloth_simulator.cpp`, `virtual_tryon_engine.cpp`, `ndk_video_decoder.cpp`, `video_timeline_compositor.cpp`, `optical_flow_tracker.cpp`, 159 KB `jni_bridge.cpp`).
4. **Android Kotlin Features (CONVERT V1 vs CONVERT2):**
   - CONVERT2 has 8 focused modules with 143 Kotlin files.
   - CONVERT V1 has 26 modules with 884 Kotlin files, representing **741 unique Kotlin source files** across 15 unported modules (`videoedit`, `idphoto`, `poster`, `puzzle`, `livephoto`, `community`, `album`, `drafts`, `aiphoto`, etc.).
5. **Facetune Unique Source:**
   - `com.lightricks.facetune.free\CONVERT` contains **1,377 unique Kotlin files** implementing Facetune's retouch and video editing architecture.

---

## 2. C++ Native Engine Comparison Matrix

| File Name | Status | In CONVERT V1 | In CONVERT2 | Notes |
|---|---|---|---|---|
| `hair_v2_barrier.cpp` | UNIQUE_TO_CONVERT1 | YES (3.9 KB) | NO | Legacy memory barrier implementation |
| `hair_v2_base_tone.cpp` | UNIQUE_TO_CONVERT1 | YES (2.6 KB) | NO | Base hair tone adjustment filter |
| `hair_v2_color.cpp` | UNIQUE_TO_CONVERT1 | YES (2.7 KB) | NO | Color blending kernels |
| `hair_v2_directional_filter.cpp` | UNIQUE_TO_CONVERT1 | YES (3.1 KB) | NO | Directional strand filter |
| `hair_v2_flow.cpp` | UNIQUE_TO_CONVERT1 | YES (5.4 KB) | NO | Flow field computation |
| `hair_v2_flow_regularizer.cpp` | UNIQUE_TO_CONVERT1 | YES (7.4 KB) | NO | Regularization pass |
| `hair_v2_lab.cpp` | UNIQUE_TO_CONVERT1 | YES (4.1 KB) | NO | CIELAB color converter |
| `hair_v2_lift_curve.cpp` | UNIQUE_TO_CONVERT1 | YES (1.8 KB) | NO | Lift curve polynomial |
| `hair_v2_oklab.cpp` | UNIQUE_TO_CONVERT1 | YES (1.5 KB) | NO | Oklab color space transform |
| `hair_v2_relighting.cpp` | UNIQUE_TO_CONVERT1 | YES (1.6 KB) | NO | Hair highlight relighting pass |
| `hair_v2_specular.cpp` | UNIQUE_TO_CONVERT1 | YES (5.3 KB) | NO | Specular sheen generator |
| `hair_v2_texture.cpp` | UNIQUE_TO_CONVERT1 | YES (4.6 KB) | NO | High-frequency hair texture preserver |
| `hair_v2_trimap.cpp` | UNIQUE_TO_CONVERT1 | YES (3.4 KB) | NO | Trimap morphological generation |
| `pbd_cloth_simulator.cpp` | UNIQUE_TO_CONVERT1 | YES (8.2 KB) | NO | Position Based Dynamics for cloth per `2.txt` |
| `virtual_tryon_engine.cpp` | UNIQUE_TO_CONVERT1 | YES (8.5 KB) | NO | Virtual Try-on pipeline per `2.txt` |
| `ndk_video_decoder.cpp` | UNIQUE_TO_CONVERT1 | YES (8.8 KB) | NO | Android NDK MediaCodec decoder |
| `video_timeline_compositor.cpp` | UNIQUE_TO_CONVERT1 | YES (11.6 KB) | NO | Multi-track timeline compositor |
| `optical_flow_tracker.cpp` | UNIQUE_TO_CONVERT1 | YES (7.3 KB) | NO | Lucas-Kanade optical flow tracking |
| `beauty_video_connector.cpp` | UNIQUE_TO_CONVERT1 | YES (3.1 KB) | NO | Real-time video frame connector |
| `jni_bridge.cpp` | UNIQUE_TO_CONVERT1 | YES (159.0 KB) | NO | Comprehensive 377 JNI registration table |
| `ncnn_face_engine.cpp` | EXACT_MATCH | YES (17.8 KB) | YES (17.8 KB) | Byte-for-byte identical NCNN face detector |
| `face_mesh_3d.cpp` | EXACT_MATCH | YES (5.7 KB) | YES (5.7 KB) | Byte-for-byte identical 3D face mesh builder |
| `yuv_converter.cpp` | EXACT_MATCH | YES (2.3 KB) | YES (2.3 KB) | Byte-for-byte identical YUV420 to RGB |
| `hair_engine.cpp` | EVOLVED_IN_CONVERT2 | YES (33.5 KB) | YES (44.2 KB) | Modernized in P1-P6 with Vulkan compute |
| `hair_matting_engine.cpp` | EVOLVED_IN_CONVERT2 | YES (30.7 KB) | YES (39.8 KB) | Enhanced with guided filter & matting |
| `bisenet_face_parser.cpp` | EVOLVED_IN_CONVERT2 | YES (20.2 KB) | YES (28.4 KB) | Upgraded with P0 frozen contract |
| `full_body_beauty_engine.cpp`| EVOLVED_IN_CONVERT2 | YES (41.5 KB) | YES (48.1 KB) | Enhanced in TASK_019 with MoveNet |

---

## 3. Duplicate Protection Statement
- No candidate tree was copied or pushed into Git during this task.
- All candidate trees remain strictly intact on disk without modification.
