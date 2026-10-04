# 04. BUILD MARKERS AND PROJECT DEFINITIONS: F:\CONVERT

**Authoritative Scan Root**: `F:\CONVERT`  
**Execution Lane**: `workspace-source-discovery`  
**Scan Timestamp**: `2026-10-04T11:51:19+07:00`  

---

## 1. Overview of Detected Build Systems

Across `F:\CONVERT`, the physical runner detected four major build paradigms:
1. **Gradle Multi-Module Projects (Android):** 3 independent repositories.
2. **CMake Native C++ Build Systems:** 2 production C++ engine modules.
3. **Node.js / NPM TypeScript Services:** 1 full backend API service.
4. **Apktool Disassemblies:** 2 complete decompiled APK trees.

---

## 2. Detailed Project Definitions

### 2.1 Project 1: CONVERT2 (meitu-convert) — Active Production Project
- **Root Path:** `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2`
- **Build System:** Gradle (Kotlin DSL: `settings.gradle.kts`, `build.gradle.kts`, `gradlew.bat`)
- **Root Project Name:** `meitu-convert`
- **Architecture:** 8 Modules
  - `:app` — Test harness and UI gallery runner.
  - `:lib-core-graphics` — C++ native engine (`libmeitu_reborn_native.so`), Vulkan compute shaders, JNI bridge, CPU fallback.
  - `:lib-image-processing` — Image loading, decoding, format conversion.
  - `:lib-makeup-engine` — Blush, lipstick, eyebrow, eye shadow rendering.
  - `:lib-face-beautify` — Facial smoothing, whitening, 3DMM reshape.
  - `:lib-body-reshape` — Pose detection, skeleton protection, background inpainting.
  - `:lib-color-grading` — 3D LUT filter engine, tone curve adjustment.
  - `:lib-ai-segmentation` — BiSeNet parsing, selfie segmentation.
- **Native Build System:** CMake (`lib-core-graphics/src/main/cpp/CMakeLists.txt`)
  - Target: `libmeitu_reborn_native.so`
  - Features: Vulkan 1.1 compute pipelines, CPU fallback kernels, JNI bridge methods.

### 2.2 Project 2: CONVERT apps/android (mtxx-reborn) — Predecessor Project
- **Root Path:** `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android`
- **Build System:** Gradle (Kotlin DSL: `settings.gradle.kts`, `build.gradle.kts`, `gradlew.bat`)
- **Root Project Name:** `mtxx-reborn`
- **Architecture:** 26 Modules (7 Core + 19 Feature Modules)
  - `:app` — Main mobile application shell.
  - **Core Modules (6):**
    - `:core:common` — Base utilities, extensions, coroutine dispatchers.
    - `:core:designsystem` — Compose design tokens, themes, widgets.
    - `:core:network` — Retrofit, OkHttp, remote API client.
    - `:core:data` — Repositories, local database, preferences.
    - `:core:render` — OpenGL ES surface rendering, texture blitting.
    - `:core:native-bridge` — Native JNI layer and C++ engine.
  - **Feature Modules (19):**
    - `:feature:home` — Feed, hero cards, recommendations.
    - `:feature:templates` — Template catalog and downloader.
    - `:feature:profile` — User profile, settings, account.
    - `:feature:camera` — Real-time camera viewfinder, shutter pipeline.
    - `:feature:editor` — Photo retouching tools canvas.
    - `:feature:beauty` — Face, skin, and makeup retouching.
    - `:feature:nextai` — AI avatar, AI generation tools.
    - `:feature:vip` — Subscription checkout and premium feature locks.
    - `:feature:videoedit` — Timeline multi-track video editor.
    - `:feature:tools` — Auxiliary utilities, format converter.
    - `:feature:poster` — Collage and poster generator.
    - `:feature:album` — Custom image picker and album manager.
    - `:feature:idphoto` — Formal ID photo generator and background replacer.
    - `:feature:community` — User feed, posts, social comments.
    - `:feature:livephoto` — Motion photos and animated frames.
    - `:feature:puzzle` — Multi-photo grid puzzle assembler.
    - `:feature:settings` — App configuration and legal notices.
    - `:feature:aiphoto` — AI portraits and style transfer.
    - `:feature:drafts` — Local project draft manager and serialization.
- **Native Build System:** CMake (`core/native-bridge/src/main/cpp/CMakeLists.txt`)
  - Compiles **50 native C++ files** into `libmeitu_reborn_native.so`.

### 2.3 Project 3: Facetune CONVERT (facetune-convert) — Sibling Project
- **Root Path:** `F:\CONVERT\com.lightricks.facetune.free\CONVERT`
- **Build System:** Gradle (Kotlin DSL: `settings.gradle.kts`, `build.gradle.kts`)
- **Root Project Name:** `facetune-convert`
- **Architecture:** 11 Modules
  - **Foundation Libraries (7):**
    - `:lib-filters` — Presets and color transform filters.
    - `:lib-video-engine` — Video playback and frame rendering.
    - `:lib-image-editing` — Bitmap manipulations and blenders.
    - `:lib-ui-toolkit` — Custom views and slider widgets.
    - `:lib-billing` — In-app billing management.
    - `:lib-logging` — Diagnostic loggers.
    - `:lib-storage-db` — Persistent cache.
  - **Feature Modules (3):**
    - `:feature-cloud-ai` — Cloud-based portrait enhancers.
    - `:feature-ai-retouch` — Facial feature retouching.
    - `:feature-story-maker` — Story creation pipeline.
  - `:app` — Executable application.

### 2.4 Project 4: CONVERT services/api — Backend Web API
- **Root Path:** `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\services\api`
- **Build System:** Node.js / TypeScript (`package.json`, `tsconfig.json`)
- **Stack:** Fastify, Prisma ORM, MQTT broker client, Server-Sent Events (SSE).
- **Files:** 1,851 source files.

### 2.5 Apktool Disassembly Projects
- `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\apktool_out`:
  - Contains `apktool.yml`, decoded `AndroidManifest.xml`, and 9 smali class folders (`smali` through `smali_classes9`).
- `F:\CONVERT\com.lightricks.facetune.free\SOURCE\apktool_out`:
  - Contains `apktool.yml` and decompiled Facetune resources.
