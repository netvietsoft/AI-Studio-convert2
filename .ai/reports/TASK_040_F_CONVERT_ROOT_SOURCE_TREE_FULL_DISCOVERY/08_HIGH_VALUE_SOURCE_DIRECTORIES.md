# 08. HIGH-VALUE SOURCE DIRECTORIES ANALYSIS

This document profiles the high-value directories across `F:\CONVERT` that contain actionable source code, decompiled references, and native reverse-engineering artifacts.

---

## 1. `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT` (Ancestor Full Android Project)
- **Relative Path**: `com.mt.mtxx.mtxx/CONVERT`
- **Classification**: **`B (RECONSTRUCTED_CONVERT2_SOURCE)` / `A (ORIGINAL_SOURCE_PROJECT)`**
- **Git Repository**: Yes (Local Git repo with branch `main`, 5 recorded commits).
- **Core Assets Found**:
  - `apps/android/core/native-bridge/src/main/cpp`: Contains **50 native C++ files**!
    - Full Hair V2 pipeline: `hair_v2_pipeline.cpp`, `hair_v2_flow.cpp`, `hair_v2_flow_regularizer.cpp`, `hair_v2_color.cpp`, `hair_v2_matting.cpp`, `hair_v2_texture.cpp`, `hair_v2_specular.cpp`, `hair_v2_trimap.cpp`, `hair_v2_barrier.cpp`, `hair_v2_base_tone.cpp`, `hair_v2_dye.cpp`, `hair_v2_directional_filter.cpp`, `hair_v2_relighting.cpp`, `hair_v2_lab.cpp`, `hair_v2_oklab.cpp`, `hair_v2_lift_curve.cpp`.
    - Classical Hair Engines: `hair_engine.cpp` (33KB), `hair_matting_engine.cpp` (30KB), `hair_strand_dye.cpp` (14KB), `hair_orientation_engine.cpp` (5KB), `hair_daub.cpp` (4KB).
    - JNI Bridge: `jni_bridge.cpp` (**159 KB** of complete JNI registrations).
    - Beauty Engines: `skin_makeup_engine.cpp` (113 KB), `full_body_beauty_engine.cpp` (41 KB), `eye_retouch_engine.cpp` (42 KB), `teeth_ear_engine.cpp` (37 KB), `head_cranial_engine.cpp` (30KB).
    - Video & Cloth Modules: `pbd_cloth_simulator.cpp`, `virtual_tryon_engine.cpp`, `ndk_video_decoder.cpp`, `video_timeline_compositor.cpp`.
  - `HAIR_COLOR_IMPLEMENTATION_PLAN.md`: A 1,671-line master execution specification detailing all AS-IS and SHOULD-BE hair color pipelines.
  - `apps/android/feature`: Complete feature modules for `beauty`, `camera`, `editor`, `nextai`, `videoedit`, `tools`, `aiphoto`, `album`, `idphoto`, `livephoto`, `poster`, `puzzle`, `vip`.

---

## 2. `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE` (Meitu Decompiled Tree)
- **Relative Path**: `com.mt.mtxx.mtxx/SOURCE`
- **Classification**: **`C (DECOMPILED_JAVA_KOTLIN_SOURCE)` / `E (NATIVE_BINARY_EXTRACT)`**
- **Key Subcomponents**:
  - `extracted_native_libs/lib/arm64-v8a`: **45 vendor .so shared libraries** verified against original Meitu APK (including `libLayerFlow.so`, `libMTFilterKernel.so`, `libManis.so`, `libarkernel3.so`, etc.). Note: `libmeitu_reborn_native.so` is our reconstructed CMake output target, not a vendor APK binary. This verified 45-SO set directly feeds `TASK_038`.
  - `jadx_src`: Decompiled Java source code across 16 dex files (`com/meitu/...`).
  - `extracted_assets`: Models (`.bin`, `.param`, `.onnx`), shaders (`.spv`), color lookup tables (`.png`, `.cube`).
  - `dex_files`: 16 raw `.dex` files for bytecode reverse verification.

---

## 3. `F:\CONVERT\com.lightricks.facetune.free\CONVERT` & `SOURCE`
- **Relative Path**: `com.lightricks.facetune.free/CONVERT` & `com.lightricks.facetune.free/SOURCE`
- **Classification**: **`B (RECONSTRUCTED_CONVERT2_SOURCE)` / `C (DECOMPILED_JAVA_KOTLIN_SOURCE)`**
- **Significance**:
  - Explicitly identified in root document `1.txt` as authoritative source for Facetune AI retouching and video engine.
  - Contains Android Gradle modules `feature-ai-retouch`, `lib-video-engine`, and `ncnn-sdk`.
  - Provides reference algorithms for facial retouching, tone mapping, and selfie segmentation.

---

## 4. `F:\CONVERT\Material Image Editor\Mitu\material`
- **Relative Path**: `Material Image Editor/Mitu/material`
- **Classification**: **`G (ASSET_RESOURCE_EXTRACT)`**
- **Significance**:
  - Contains 12 material category folders (`2014`, `2130`, `2132`, `2153`, `2155`, `4001`, `4002`, `4003`, `4004`, `4005`, `4008`, `5002`).
  - Contains `apple_camera_filter`, `CameraOnlineMaterial`, `mosaic`, and `sticker`.
  - High value for LUT and filter resource feeds.
