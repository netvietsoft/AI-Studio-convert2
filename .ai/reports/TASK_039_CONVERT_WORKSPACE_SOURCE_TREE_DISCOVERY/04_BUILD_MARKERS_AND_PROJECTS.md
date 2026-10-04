# 04. BUILD MARKERS & PROJECT ARCHITECTURES — F:\CONVERT

**Authority**: Chủ tịch Tony  
**Task ID**: `TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY_CLASSIFICATION_ACTIVE`  
**Command ID**: `TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY_20261004T103500+0700`  
**Authoritative Scan Root**: `F:\CONVERT`  

---

## 1. Overview of Detected Build Systems

Across the 20 candidate directories within `F:\CONVERT`, three major categories of build and project systems were identified:
1. **Gradle Multi-Module Android Projects (Kotlin DSL `.kts`)**:
   - `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2` (Active V2 development project)
   - `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android` (Ancestral V1 multi-module project)
   - `F:\CONVERT\com.lightricks.facetune.free\CONVERT` (Facetune sibling multi-module project)
2. **CMake Native C++ Toolchains**:
   - `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\lib-core-graphics\src\main\cpp\CMakeLists.txt`
   - `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp\CMakeLists.txt`
   - `F:\CONVERT\com.lightricks.facetune.free\CONVERT\lib-video-engine\src\main\cpp\CMakeLists.txt`
3. **Apktool / JADX Decompilation Artifact Markers**:
   - `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\apktool_out\apktool.yml`
   - `F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out\apktool.yml`

---

## 2. In-Depth Project Architectural Profiles

### Project 1: CONVERT2 (Active Development Workspace)
- **Root Path**: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2`
- **Build System**: Gradle 8.x + Kotlin DSL (`build.gradle.kts`, `settings.gradle.kts`)
- **Native Toolchain**: CMake 3.22.1 + Android NDK r25c + Vulkan 1.1+ (via `lib-core-graphics`)
- **Application ID / Package**: `com.mtxx.reborn` (Debug APK: `com.mtxx.reborn.debug`)
- **Declared Modules**:
  - `app`: Android application shell, navigation graph, activity hosting.
  - `lib-ai-engine`: BiSeNet 19-class parsing, NCNN neural inference backend.
  - `lib-billing`: Subscription and in-app purchase validation.
  - `lib-common-ui`: Shared Compose components, color palettes, UI controls.
  - `lib-core-graphics`: C++ Native graphics engine, Vulkan compute shader pipeline (`hair_composite_blend.comp`), hair matting, anisotropic specular engine.
  - `lib-photo-editor`: Photo editor viewmodels, state machine, tool interaction.
  - `lib-roboneo`: RoboNeo rendering abstractions.
  - `lib-video-engine`: Video timeline and playback support.
- **Marker Evidence**:
  - `build.gradle.kts`, `settings.gradle.kts`, `gradlew`, `gradlew.bat`
  - `app/src/main/AndroidManifest.xml`
  - `lib-core-graphics/src/main/cpp/CMakeLists.txt`

### Project 2: CONVERT V1 Android Project (`apps/android`)
- **Root Path**: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android`
- **Build System**: Gradle 8.x + Kotlin DSL (`build.gradle.kts`, `settings.gradle.kts`)
- **Native Toolchain**: CMake 3.22.1 + Android NDK (via `core/native-bridge`)
- **Package Prefix**: `com.mtxx.reborn`
- **Declared Modules (25 Modules Total: 1 App + 6 Core + 19 Features)**:
  - **Core Modules (6)**:
    - `core:common`: Shared utilities, logging, math extensions.
    - `core:data`: Local Room database, DataStore preferences, repository abstractions.
    - `core:designsystem`: Jetpack Compose design tokens, typography, theme.
    - `core:native-bridge`: JNI bindings (`MeituNativeEngine`), CMake native engine (50 C++ files).
    - `core:network`: Ktor HTTP client, REST API serialization.
    - `core:render`: SurfaceView / TextureView OpenGL render surface.
  - **Feature Modules (19)**:
    - `feature:aiphoto`, `feature:album`, `feature:beauty`, `feature:camera`, `feature:community`,
    - `feature:drafts`, `feature:editor`, `feature:home`, `feature:idphoto`, `feature:livephoto`,
    - `feature:nextai`, `feature:poster`, `feature:profile`, `feature:puzzle`, `feature:settings`,
    - `feature:templates`, `feature:tools`, `feature:videoedit`, `feature:vip`.
- **Marker Evidence**:
  - `build.gradle.kts`, `settings.gradle.kts`, `gradlew`, `gradlew.bat`
  - 30 individual module `build.gradle.kts` files
  - `core/native-bridge/src/main/cpp/CMakeLists.txt`
  - `core/native-bridge/src/main/AndroidManifest.xml`

### Project 3: V1 Native C++ Core Engine (`core/native-bridge/src/main/cpp`)
- **Root Path**: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp`
- **Build System**: CMake (`CMakeLists.txt`)
- **Target Output**: `libmeitu_reborn_native.so`
- **Key Source Components**:
  - `src/jni_bridge.cpp`: 159 KB JNI registration mapping Java native methods on `com.mtxx.reborn.core.nativebridge.MeituNativeEngine` to C++ functions.
  - Modular Hair Subsystem: `hair_v2_pipeline.cpp`, `hair_v2_matting.cpp`, `hair_v2_dye.cpp`, `hair_v2_specular.cpp`, `hair_v2_texture.cpp`, `hair_v2_flow.cpp`, `hair_v2_lab.cpp`, `hair_v2_oklab.cpp`.
  - Facial & Body Engines: `dense_facemesh_478.cpp`, `insightface_106.cpp`, `face_reshape_3dmm.cpp`, `skin_makeup_engine.cpp`, `teeth_ear_engine.cpp`, `full_body_beauty_engine.cpp`.
  - Media & Simulation: `media/cloth/pbd_cloth_simulator.cpp`, `media/cloth/virtual_tryon_engine.cpp`, `media/video/video_timeline_compositor.cpp`.

### Project 4: Facetune Reconstructed Project (`com.lightricks.facetune.free/CONVERT`)
- **Root Path**: `F:\CONVERT\com.lightricks.facetune.free\CONVERT`
- **Build System**: Gradle 8.x + Kotlin DSL (`build.gradle.kts`, `settings.gradle.kts`)
- **Native Toolchain**: CMake + NCNN Neural SDK (`ncnn-sdk`)
- **Package Prefix**: `com.lightricks.facetune`
- **Declared Modules**:
  - `app`, `feature-ai-retouch`, `feature-cloud-ai`, `feature-story-maker`, `lib-billing`, `lib-filters`, `lib-image-editing`, `lib-logging`, `lib-storage-db`, `lib-ui-toolkit`, `lib-video-engine`.
- **Marker Evidence**:
  - `settings.gradle.kts`, `gradlew`, `gradlew.bat`
  - 12 module `build.gradle.kts` files
  - `lib-video-engine/src/main/cpp/CMakeLists.txt`

### Project 5: Meitu Reverse Engineering Ground Truth (`SOURCE`)
- **Root Path**: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE`
- **Classification**: Decompiled bytecode & native binary store (Apktool + JADX)
- **Vendor Package ID**: `com.mt.mtxx.mtxx`
- **Vendor Version**: `12.17.8` (APKPure build `Meitu_12.17.8_APKPure.xapk`)
- **Marker Evidence**:
  - `apktool_manifest/AndroidManifest.xml` (Vendor permissions, services, activities)
  - `apktool_manifest/apktool.yml` (Apktool metadata and compression flags)
  - 45 vendor ARM64 shared libraries in `extracted_native_libs/`
  - 106,466 decompiled Java source files in `jadx_src/`

---

## 3. Comparative Build Marker Matrix

| Feature / Metric | CONVERT2 (V2 Active) | CONVERT (V1 Workspace) | Facetune CONVERT | Meitu SOURCE |
|---|---|---|---|---|
| **Root Path** | `.../CONVERT2` | `.../CONVERT/apps/android` | `.../facetune.../CONVERT` | `.../SOURCE` |
| **Build System** | Gradle (Kotlin DSL) | Gradle (Kotlin DSL) | Gradle (Kotlin DSL) | Apktool / JADX |
| **Gradle Version** | 8.x | 8.x | 8.x | N/A |
| **CMake Native Build** | YES (`lib-core-graphics`) | YES (`core:native-bridge`) | YES (`lib-video-engine`) | NO (Prebuilt .so) |
| **Total Modules** | 8 modules | 25 modules | 12 modules | N/A |
| **Package ID** | `com.mtxx.reborn` | `com.mtxx.reborn` | `com.lightricks.facetune` | `com.mt.mtxx.mtxx` |
| **Git Versioned** | YES (Remote GitHub) | YES (Local Git) | NO | NO |
| **Compilation State** | Compiles & Passes | Historical V1 Artifact | Compiles Partial | N/A (Decompiled) |
