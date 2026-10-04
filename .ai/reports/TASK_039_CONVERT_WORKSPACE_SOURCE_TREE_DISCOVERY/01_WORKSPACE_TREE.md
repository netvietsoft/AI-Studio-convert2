# 01. WORKSPACE TREE — F:\CONVERT AUTHORITATIVE ENUMERATION

**Authority**: Chủ tịch Tony  
**Task ID**: `TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY_CLASSIFICATION_ACTIVE`  
**Command ID**: `TASK_039_CONVERT_WORKSPACE_SOURCE_TREE_DISCOVERY_20261004T103500+0700`  
**Scan Root**: `F:\CONVERT` (Entire Storage Volume / Workspace)  
**Execution Lane**: `workspace-source-discovery`  
**Runner Identity**: `GITHUB_ACTIONS_37182624093` / Physical Runner  

---

## 1. Top-Level Physical Census of `F:\CONVERT`

The authoritative scan root `F:\CONVERT` contains **4 primary directory hierarchies** and **14 root governing documents, specifications, and scripts**:

```
F:\CONVERT\
├── 1.txt                                                          [Charter / Facetune SOURCE Reference, 1.4 KB]
├── 2.txt                                                          [Distillation Architecture & Libraries Spec, 18.0 KB]
├── 3.txt                                                          [Skin & Detail Retouch Specification, 2.4 KB]
├── 4.txt                                                          [Slider Dynamic Range & Color Calibration, 2.9 KB]
├── 5.txt                                                          [Facial Beauty & Landmark Geometric Spec, 2.8 KB]
├── beauty_engine_architecture_insightface_ncnn_cpp.txt            [NCNN C++ InsightFace Architecture Spec, 14.6 KB]
├── Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt [Constitutional Development Standard, 115.8 KB]
├── GEMINI.md                                                      [Operational Constitution & Guidelines, 3.5 KB]
├── _ftvapp_files.txt                                              [Facetune App File Manifest, 1.6 KB]
├── _kotlinc_ftvapp.log                                            [Facetune Kotlin Compilation Log, 540.2 KB]
├── _verify_ftvapp.py                                              [Facetune Verification Test Script, 5.1 KB]
│
├── com.mt.mtxx.mtxx/                                              [Meitu Reborn Primary Project Workspace]
├── com.lightricks.facetune.free/                                  [Facetune Reborn Project Workspace]
├── Material Image Editor/                                         [External Filter & Sticker Asset Repository]
└── tools/                                                         [Infrastructure & Virtualization Tooling]
```

---

## 2. Detailed Hierarchy 1: `F:\CONVERT\com.mt.mtxx.mtxx\` (Meitu Ecosystem)

This directory hosts the primary subject of CONVERT2 engineering, decompiled APK artifacts, historical V1 reconstructions, and golden test assets:

```
F:\CONVERT\com.mt.mtxx.mtxx\
│
├── CONVERT2/                                                      [PRIMARY ACTIVE WORKSPACE — Gated V2]
│   ├── .ai/                                                       [Audit Reports, State Machine, Task Buses]
│   ├── .git/                                                      [Git Repo: netvietsoft/AI-Studio-convert2]
│   ├── .github/workflows/                                         [CI / GitHub Actions Workflows]
│   ├── app/                                                       [Android Application Wrapper Module]
│   │   ├── src/main/java/com/mtxx/reborn/                         [App Entrypoint, Navigation, UI Shell]
│   │   └── build.gradle.kts                                       [Application Gradle Script]
│   ├── lib-ai-engine/                                             [AI Model Runtime (BiSeNet, FaceParsing)]
│   ├── lib-billing/                                               [VIP & In-App Purchase Subsystem]
│   ├── lib-common-ui/                                             [Design System Components & Shaders]
│   ├── lib-core-graphics/                                         [CORE C++ GRAPHICS & VULKAN ENGINE]
│   │   ├── src/main/cpp/                                          [Hair Color Engine, Vulkan P6 Hardening]
│   │   │   ├── include/hair/                                      [Hair Engine V2 Header Contracts]
│   │   │   ├── src/hair/                                          [Hair Appearance, Specular, Pipeline V2]
│   │   │   │   └── shaders/hair_composite_blend.comp              [Vulkan Compute Shader for Hair Dye]
│   │   │   └── CMakeLists.txt                                     [Native Build System]
│   │   └── build.gradle.kts                                       [Core Graphics Gradle Module]
│   ├── lib-photo-editor/                                          [Photo Editing UI, Tool Controllers]
│   ├── lib-roboneo/                                               [RoboNeo Rendering Framework]
│   ├── lib-video-engine/                                          [Video Playback & Composition Subsystem]
│   ├── build.gradle.kts                                           [Root Gradle Build Script]
│   ├── settings.gradle.kts                                        [Multi-Module Gradle Settings]
│   └── gradle/wrapper/                                            [Gradle Wrapper Binaries]
│
├── CONVERT/                                                       [ANCESTRAL V1 RECONSTRUCTED WORKSPACE]
│   ├── .git/                                                      [Local Git Repo (Branch: main, 5 commits)]
│   ├── apps/android/                                              [V1 ANDROID MULTI-MODULE ROOT]
│   │   ├── build.gradle.kts                                       [Root Gradle Build Script]
│   │   ├── settings.gradle.kts                                    [Defines 19 Feature Modules + 6 Core]
│   │   ├── app/                                                   [V1 App Module]
│   │   ├── core/                                                  [6 Core Submodules]
│   │   │   ├── common/                                            [Shared Utilities & Contracts]
│   │   │   ├── data/                                              [Local Database & Repository Layer]
│   │   │   ├── designsystem/                                      [Compose UI Theme & Components]
│   │   │   ├── native-bridge/                                     [V1 C++ NATIVE ENGINE ROOT]
│   │   │   │   ├── src/main/cpp/                                  [50+ C++ Native Engine Files]
│   │   │   │   │   ├── CMakeLists.txt                             [Native Build Script]
│   │   │   │   │   ├── src/hair_v2_pipeline.cpp                   [V1 Modular Hair Pipeline]
│   │   │   │   │   ├── src/hair_v2_*.cpp (15 modules)             [Flow, Specular, Lab, Dye, Matting]
│   │   │   │   │   ├── src/jni_bridge.cpp (159 KB)                [MeituNativeEngine JNI Binding Table]
│   │   │   │   │   ├── src/media/cloth/pbd_cloth_simulator.cpp    [PBD Cloth Simulation Engine]
│   │   │   │   │   ├── src/media/cloth/virtual_tryon_engine.cpp   [Virtual Try-On Engine]
│   │   │   │   │   ├── src/media/video/video_timeline_compositor.cpp [Video Timeline Compositor]
│   │   │   │   │   └── src/vision/tracking/optical_flow_tracker.cpp [Optical Flow Tracker]
│   │   │   │   └── build.gradle.kts                               [Native Bridge Gradle Script]
│   │   │   ├── network/                                           [Ktor HTTP Client & API Adapters]
│   │   │   └── render/                                            [OpenGL / SurfaceView Render Canvas]
│   │   └── feature/                                               [19 FEATURE MODULES]
│   │       ├── aiphoto/                                           [AI Portrait Generation Feature]
│   │       ├── album/                                             [Gallery & Media Picker Feature]
│   │       ├── beauty/                                            [Retouch, Makeup, Reshape Feature]
│   │       ├── camera/                                            [Live Camera Capture Feature]
│   │       ├── community/                                         [Social Feed, Topics, Ktor Client]
│   │       ├── drafts/                                            [Project Drafts Management]
│   │       ├── editor/                                            [Photo Editor Canvas Feature]
│   │       ├── home/                                              [App Home Dashboard]
│   │       ├── idphoto/                                           [ID Photo Studio Feature]
│   │       ├── livephoto/                                         [Live Photo Player Feature]
│   │       ├── nextai/                                            [Next-Gen AI Retouch Workflows]
│   │       ├── poster/                                            [Poster & Collage Creator]
│   │       ├── profile/                                           [User Profile Feature]
│   │       ├── puzzle/                                            [Photo Grid Puzzle Feature]
│   │       ├── settings/                                          [App Settings Feature]
│   │       ├── templates/                                         [Design Templates Feature]
│   │       ├── tools/                                             [Utility Tool Suite]
│   │       ├── videoedit/                                         [Video Editing Feature]
│   │       └── vip/                                               [Subscription & VIP Feature]
│   ├── BACKEND/                                                   [Backend API Services, Feature Contracts]
│   ├── prototype/                                                 [Interactive Web Prototype (JS/HTML/CSS)]
│   ├── reconstruction-input/                                      [Extracted Manifests & Assets]
│   └── scripts/                                                   [Build & Automation Scripts]
│
├── SOURCE/                                                        [MEITU REVERSE ROOT & EXTRACTIONS]
│   ├── jadx_src/                                                  [Decompiled Java Source (106,466 files)]
│   │   └── com/meitu/                                             [Official Vendor Java Packages]
│   │       ├── core/processor/MTSoftHairFilter.java               [Official Hair Filter JNI Class]
│   │       ├── hair/HairMaskFilterToFBO.java                      [Official Hair Mask FBO Filter]
│   │       └── makeup/hair/MakeupHairSoftPart.java                [Official Hair Makeup Segment]
│   ├── apktool_out/                                               [Apktool Disassembly (9,263 files)]
│   │   ├── AndroidManifest.xml                                    [Vendor Official Manifest]
│   │   ├── apktool.yml                                            [Apktool Metadata]
│   │   └── res/                                                   [6,400+ Raw XML Layouts & Values]
│   ├── extracted_native_libs/                                     [45 Vendor ARM64 Shared Libraries]
│   │   ├── libhair_segment.so                                     [Hair Segmentation Vendor Binary]
│   │   ├── libmatting.so                                          [Matting Core Vendor Binary]
│   │   ├── libface_parsing.so                                     [Face Parsing Vendor Binary]
│   │   └── ... (42 additional vendor .so files)                   [Ground Truth for TASK_038 / TASK_044]
│   ├── extracted_assets/                                          [4,656 Vendor Assets, Shaders, Models]
│   ├── dex_files/                                                 [20 Dalvik Executables (classes1-16.dex)]
│   ├── mitu/                                                      [1,535 UI Screenshots & Reverse Notes]
│   └── Redesign/                                                  [15 UI Prototypes & Patch Scripts]
│
├── Yeucau/                                                        [REQUIREMENT GOLDEN GROUND TRUTH]
│   ├── 0.jpg                                                      [Customer 0 Golden Test Portrait]
│   ├── 1.jpg                                                      [Customer 1 Golden Test Portrait]
│   ├── flawless_rose_gold_dyed.png                                [Ground Truth Dyed Visual]
│   ├── flawless_rose_gold_dyed_mask.png                           [Ground Truth Binary Hair Mask]
│   └── HAIR_COLOR_PHASE00_BASELINE.md                             [Constitutional Baseline Protocol]
│
├── _stray_backup_w9/                                              [STALE DUPLICATE BACKUP]
│   └── apps/android/feature/community/                            [25 Stale Kotlin Files from Week 9]
├── beard_assets_10_png/                                           [10 PNG Beard Texture Overlays]
└── ẢNH/                                                           [Reference Portraits (Monk, Test 1)]
```

---

## 3. Detailed Hierarchy 2: `F:\CONVERT\com.lightricks.facetune.free\` (Facetune Sibling Workspace)

```
F:\CONVERT\com.lightricks.facetune.free\
│
├── CONVERT/                                                       [RECONSTRUCTED FACETUNE WORKSPACE]
│   ├── app/                                                       [Facetune Android App Module]
│   ├── feature-ai-retouch/                                        [Facetune AI Retouch Feature]
│   ├── feature-cloud-ai/                                          [Facetune Cloud AI Feature]
│   ├── feature-story-maker/                                       [Story Maker Module]
│   ├── lib-billing/                                               [Facetune Billing Subsystem]
│   ├── lib-filters/                                               [Facetune Filter Library]
│   ├── lib-image-editing/                                         [Core Image Editing Engine]
│   ├── lib-video-engine/                                          [Native Video Processing Engine]
│   ├── ncnn-sdk/                                                  [NCNN Android Neural SDK Prebuilt]
│   ├── build.gradle.kts                                           [Root Gradle Script]
│   └── settings.gradle.kts                                        [Module Settings]
│
├── SOURCE/                                                        [FACETUNE REVERSE ROOT (Referenced in 1.txt)]
│   ├── jadx_out/                                                  [Decompiled Java Source (26,020 files)]
│   ├── apktool_out/                                               [Apktool Disassembly (3,597 files)]
│   ├── extracted_xapk/                                            [Extracted Facetune APK & Native Libs]
│   └── Facetune+Hair,+Photo+Editor_2.60.0.1-free_APKPure.xapk     [Raw APK Source Archive]
│
├── Report/                                                        [Facetune Audit & Architecture Docs]
└── report 2/                                                      [Secondary Audit Reports]
```

---

## 4. Detailed Hierarchy 3: `F:\CONVERT\Material Image Editor\` (Asset Pack Library)

```
F:\CONVERT\Material Image Editor\
└── Mitu/
    └── material/                                                  [14,994 Material & Filter Asset Files]
        ├── 2014/, 2130/, 2132/, 2153/, 2155/                      [Online Filter Material Category Packs]
        ├── 4001/, 4002/, 4003/, 4004/, 4005/, 4008/, 5002/        [Effect & Makeup Preset Categories]
        ├── apple_camera_filter/                                   [Apple Camera Simulation LUTs]
        ├── CameraOnlineMaterial/                                  [Live Camera Sticker & Filter Packs]
        ├── mosaic/                                                [Mosaic Brush Texture Packs]
        └── sticker/                                               [Overlay Sticker Packs]
```

---

## 5. Detailed Hierarchy 4: `F:\CONVERT\tools\` (Infrastructure Tooling)

```
F:\CONVERT\tools\
├── docker/                                                        [Docker Compose & Container Configs]
├── minio/                                                         [MinIO S3-Compatible Object Storage Tools]
├── wsl-install.log                                                [WSL Environment Installation Log]
├── wsl-setup.log                                                  [WSL Configuration Log]
├── wsl-setup.ps1                                                  [WSL Automation PowerShell Script]
└── wsl_update_x64.msi                                             [Microsoft WSL2 Linux Kernel Package]
```

---

## 6. Summary of Discovered Candidates

| ID | Directory Candidate | Category Code | Category Description | Size (MB) | File Count |
|---|---|---|---|---|---|
| `CANDIDATE_01` | `com.mt.mtxx.mtxx\CONVERT2` | **B** | RECONSTRUCTED_CONVERT2_SOURCE (Active) | 12,051.2 | 106,269 |
| `CANDIDATE_02` | `com.mt.mtxx.mtxx\CONVERT` | **B** | RECONSTRUCTED_SOURCE (V1 Full Workspace) | 6,099.7 | 204,217 |
| `CANDIDATE_03` | `com.mt.mtxx.mtxx\CONVERT\apps\android` | **B** | RECONSTRUCTED_SOURCE (V1 Android Multi-Module) | 3,082.3 | 52,231 |
| `CANDIDATE_04` | `com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp` | **B** | RECONSTRUCTED_SOURCE (V1 C++ Core Engine) | 65.6 | 303 |
| `CANDIDATE_05` | `com.mt.mtxx.mtxx\SOURCE` | **J** | UNKNOWN_NEEDS_REVIEW (Reverse Engineering Root) | 2,252.6 | 137,796 |
| `CANDIDATE_06` | `com.mt.mtxx.mtxx\SOURCE\jadx_src` | **C** | DECOMPILED_JAVA_KOTLIN_SOURCE (Meitu JADX) | 494.2 | 106,466 |
| `CANDIDATE_07` | `com.mt.mtxx.mtxx\SOURCE\apktool_out` | **D** | SMALI_DECOMPILE (Meitu Apktool Disassembly) | 195.4 | 9,263 |
| `CANDIDATE_08` | `com.mt.mtxx.mtxx\SOURCE\extracted_native_libs` | **E** | NATIVE_BINARY_EXTRACT (45 Vendor .so ARM64) | 88.2 | 45 |
| `CANDIDATE_09` | `com.mt.mtxx.mtxx\SOURCE\extracted_assets` | **G** | ASSET_RESOURCE_EXTRACT (Meitu Vendor Assets) | 80.1 | 4,656 |
| `CANDIDATE_10` | `com.mt.mtxx.mtxx\SOURCE\dex_files` | **E** | NATIVE_BINARY_EXTRACT (Vendor Dex Partitions) | 175.6 | 20 |
| `CANDIDATE_11` | `com.mt.mtxx.mtxx\SOURCE\mitu` | **F** | NATIVE_PSEUDOCODE_OR_REVERSE_OUTPUT (Artifacts) | 35.0 | 1,535 |
| `CANDIDATE_12` | `com.mt.mtxx.mtxx\SOURCE\Redesign` | **B** | RECONSTRUCTED_SOURCE (UI Prototypes) | 0.1 | 15 |
| `CANDIDATE_13` | `com.mt.mtxx.mtxx\_stray_backup_w9` | **I** | DUPLICATE_COPY (Stale Week 9 Backup) | 0.2 | 25 |
| `CANDIDATE_14` | `com.lightricks.facetune.free\CONVERT` | **B** | RECONSTRUCTED_SOURCE (Facetune Android Workspace) | 1,115.9 | 12,468 |
| `CANDIDATE_15` | `com.lightricks.facetune.free\SOURCE` | **C** | DECOMPILED_JAVA_KOTLIN_SOURCE (Facetune Root) | 809.0 | 29,890 |
| `CANDIDATE_16` | `Material Image Editor\Mitu\material` | **G** | ASSET_RESOURCE_EXTRACT (12 Material Packs + LUTs) | 202.6 | 14,994 |
| `CANDIDATE_17` | `tools` | **H** | BUILD_OUTPUT_OR_CACHE (Tooling & Infrastructure) | 615.3 | 5 |
| `CANDIDATE_18` | `com.mt.mtxx.mtxx\Yeucau` | **G** | ASSET_RESOURCE_EXTRACT (Requirement Ground Truth) | 9.8 | 17 |
| `CANDIDATE_19` | `com.mt.mtxx.mtxx\beard_assets_10_png` | **G** | ASSET_RESOURCE_EXTRACT (Beard PNG Overlays) | 11.5 | 10 |
| `CANDIDATE_20` | `com.mt.mtxx.mtxx\ẢNH` | **G** | ASSET_RESOURCE_EXTRACT (Reference Portrait Photos) | 0.8 | 3 |
