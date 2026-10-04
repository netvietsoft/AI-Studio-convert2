# 08. HIGH-VALUE SOURCE DIRECTORIES ANALYSIS

This document profiles the high-value directories across `F:\CONVERT` that contain actionable source code, decompiled references, and native reverse-engineering artifacts.

---

> [!CAUTION]
> **ERRATUM / CORRECTION (TASK_041 — 2026-10-04)**:
> 1. In Section 1: The V1 C++ native tree at `apps/android/core/native-bridge/src/main/cpp` is **`PROJECT_RECONSTRUCTED_SOURCE`** (cleanroom reconstructed by the autonomous agent fleet in Sep-Oct 2026), **NOT** `ORIGINAL_SOURCE_PROJECT`.
> 2. In Section 2: The claim that `extracted_native_libs/lib/arm64-v8a` contains `libmeitu_reborn_native.so`, `libbisenet.so`, `libncnn.so`, `libface_mesh.so` is **FACTUALLY ERRONEOUS**. None of these four exist in vendor extracts. `libmeitu_reborn_native.so` is the compiled target of this project; `libbisenet.so` and `libface_mesh.so` are neural models run inside `libManis.so` / `libarkernel3.so`; `libncnn.so` is a third-party framework used in cleanroom rebuilding. The 45 vendor libraries are the exact closed-source Meitu binaries verified in TASK_036.

## 1. `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT` (Ancestor Full Android Project)
- **Relative Path**: `com.mt.mtxx.mtxx/CONVERT`
- **Classification**: **`PROJECT_RECONSTRUCTED_SOURCE`** *(Cleanroom re-implementation, Sep-Oct 2026)*
- **Git Repository**: Yes (Local Git repo with branch `main`, 103 recorded commits; `apps/android/core/native-bridge/` untracked local source).
- **Core Assets Found**:
  - `apps/android/core/native-bridge/src/main/cpp`: Contains **128 native C/C++ project files** (58 in `src`, 57 in `include`, 12 in `BeautyCore`, `CMakeLists.txt`) plus 175 prebuilt third-party Tencent NCNN SDK files.
    - Full Hair V2 pipeline: `hair_v2_pipeline.cpp`, `hair_v2_flow.cpp`, `hair_v2_flow_regularizer.cpp`, `hair_v2_color.cpp`, `hair_v2_matting.cpp`, `hair_v2_texture.cpp`, `hair_v2_specular.cpp`, `hair_v2_trimap.cpp`, `hair_v2_barrier.cpp`, `hair_v2_base_tone.cpp`, `hair_v2_dye.cpp`, `hair_v2_directional_filter.cpp`, `hair_v2_relighting.cpp`, `hair_v2_lab.cpp`, `hair_v2_oklab.cpp`, `hair_v2_lift_curve.cpp`.
    - Classical Hair Engines: `hair_engine.cpp` (33KB), `hair_matting_engine.cpp` (30KB), `hair_strand_dye.cpp` (14KB), `hair_orientation_engine.cpp` (5KB), `hair_daub.cpp` (4KB).
    - JNI Bridge: `jni_bridge.cpp` (**159 KB**, 165 JNI registrations binding to `com.meitu.core.nativeengine.MeituNativeEngine`).
    - Beauty Engines: `skin_makeup_engine.cpp` (113 KB), `full_body_beauty_engine.cpp` (41 KB), `eye_retouch_engine.cpp` (42 KB), `teeth_ear_engine.cpp` (37 KB), `head_cranial_engine.cpp` (30KB).
    - Video & Cloth Modules: `pbd_cloth_simulator.cpp`, `virtual_tryon_engine.cpp`, `ndk_video_decoder.cpp`, `video_timeline_compositor.cpp`.
  - `HAIR_COLOR_IMPLEMENTATION_PLAN.md`: A 1,671-line master execution specification detailing all AS-IS and SHOULD-BE hair color pipelines.
  - `apps/android/feature`: Complete feature modules for `beauty`, `camera`, `editor`, `nextai`, `videoedit`, `tools`, `aiphoto`, `album`, `idphoto`, `livephoto`, `poster`, `puzzle`, `vip`.

---

## 2. `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE` (Meitu Decompiled Tree)
- **Relative Path**: `com.mt.mtxx.mtxx/SOURCE`
- **Classification**: **`C (DECOMPILED_JAVA_KOTLIN_SOURCE)` / `E (NATIVE_BINARY_EXTRACT)`**
- **Key Subcomponents**:
  - `extracted_native_libs/lib/arm64-v8a`: **45 vendor .so shared libraries** (including `libMTFilterKernel.so`, `libarkernel3.so`, `libManis.so`, `libLayerFlow.so`, `libPVGColorFunctions.so`). This directly feeds `TASK_038` under the verified intake manifest.
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
