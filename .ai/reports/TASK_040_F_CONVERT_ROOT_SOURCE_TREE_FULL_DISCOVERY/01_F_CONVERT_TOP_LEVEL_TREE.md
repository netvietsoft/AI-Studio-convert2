# F:\CONVERT Top-Level Hierarchy Tree & Directory Profiles

## 1. Visual Hierarchy Tree

```
F:\CONVERT/
├── com.mt.mtxx.mtxx/                     [31.96 GB | 422,126 files | Meitu Reborn Ecosystem]
│   ├── CONVERT2/                         [Active Hair V2 Engine workspace | Git Repo @ a49c772c]
│   │   ├── app/                          [Android UI application]
│   │   ├── lib-core-graphics/            [C++ Hair Native Core & jniLibs (46 .so)]
│   │   └── lib-photo-editor/             [Kotlin image processing pipeline]
│   ├── CONVERT/                          [V1 Monorepo Ancestor | Git Repo @ a411ddbd | 31,440 files]
│   │   ├── apps/android/core/            [Core Native Engines: native-bridge (9 C++ engines), render (OpenGL)]
│   │   ├── apps/android/feature/         [Feature Modules: beauty, hair, filter, makeup, retouch]
│   │   └── apps/android/shared/          [Shared contracts, image loaders, math utilities]
│   ├── SOURCE/                           [Decompiled & Extracted Meitu v11.3.1.0 APK]
│   │   ├── jadx_src/sources/             [106,466 Decompiled Java Source Files]
│   │   ├── apktool_out/                  [9,263 Decompiled XML, Smali, and Asset Files]
│   │   ├── extracted_native_libs/        [45 Vendor Native .so Libraries (arm64-v8a)]
│   │   ├── extracted_assets/             [Shaders, BiSeNet models, LUT textures, filter configs]
│   │   ├── dex_files/                    [13 DEX files: classes.dex .. classes13.dex]
│   │   ├── mitu/                         [Reverse notes, UI screenshots, redesign specs]
│   │   ├── BAO CAO CHU TICH/             [Executive reports from initial decompilation phase]
│   │   └── full_system_verification_reports/ [Automated verification reports]
│   ├── _stray_backup_w9/                 [Stray duplicate of CONVERT/apps/android/feature/community]
│   ├── Yeucau/                           [Requirements, specifications, and test criteria documents]
│   ├── ẢNH/                              [Test photographic images and ground truth references]
│   └── ẢNH_CHỮ/                          [Test typography and watermark reference images]
│
├── com.lightricks.facetune.free/         [1.48 GB | 10,509 files | Facetune Reconstructed App]
│   ├── CONVERT/                          [11-Module Reconstructed Gradle Project]
│   │   ├── feature-ai-retouch/           [C++ CMake AI Retouch Engine & Vulkan/NCNN pipeline]
│   │   ├── lib-filters/                  [GPU Filter pipeline & shaders]
│   │   ├── lib-image-editing/            [Canvas & tool transformation pipelines]
│   │   ├── lib-video-engine/             [Video playback & processing core]
│   │   ├── ncnn-sdk/                     [Tencent NCNN Android Vulkan SDK prebuilts]
│   │   └── app/                          [Facetune UI Application shell]
│   ├── SOURCE/                           [Decompiled Facetune APK]
│   │   ├── jadx_out/                     [Decompiled Java sources for Facetune]
│   │   ├── apktool_out/                  [Decompiled Smali & AndroidManifest]
│   │   ├── extracted_xapk/               [Extracted XAPK split bundles & native libs]
│   │   ├── Redesign/                     [Facetune architecture redesign specifications]
│   │   └── Report/                       [Phase audit reports]
│   ├── Report/                           [Report mirror]
│   └── report 2/                         [Report mirror 2]
│
├── Material Image Editor/                [14.54 MB | 124 files | Material & LUT Asset Pack]
│   └── Mitu/material/
│       ├── camera/                       [Camera live filter assets and scripts]
│       ├── filter/                       [Color LUT tables: IDs 2014, 2038, 2043, 3012, 4001, 5002]
│       ├── sticker/                      [Decorative stickers and augmented reality overlays]
│       └── mosaic/                       [Mosaic brush patterns and procedural shaders]
│
├── tools/                                [27.60 KB | 9 files | Dev & Cloud Infrastructure]
│   ├── docker/                           [Dockerfile and docker-compose configurations]
│   ├── minio/                            [MinIO local object storage setup and S3 bucket init]
│   └── wsl-setup/                        [WSL2 Ubuntu build environment bootstrap scripts]
│
└── [Loose Root Files]                    [454.5 KB | 8 files | Standards & Reference Specs]
    ├── 1.txt                             [Project Overview & Module Inventory]
    ├── 2.txt                             [Video & Image Distillation Architecture Reference]
    ├── 3.txt                             [Testing Specifications & Device Matrix]
    ├── 4.txt                             [Hair Color Engine Historical Architecture Memos]
    ├── 5.txt                             [JNI Bridge & Symbol Harvesting Directives]
    ├── Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt [Standard V2.1]
    ├── beauty_engine_architecture_reconstruction_and_native_bridge_2.txt [Native Bridge Spec]
    └── GEMINI.md                         [Constitutional Operational Guidelines for Agent 0]
```

---

## 2. Quantitative Top-Level Profile

| Directory / File | Type | Files | Subdirs | Size (Bytes) | Size | Git Repo? | Description |
|---|---|---|---|---|---|---|---|
| `com.mt.mtxx.mtxx` | Directory | 422,126 | 32,836 | 34,316,913,327 | 31.96 GB | Yes (2 internal) | Meitu Reborn monorepo, V2 hair engine, decompiled APK, 45 native libs. |
| `com.lightricks.facetune.free` | Directory | 10,509 | 1,225 | 1,592,492,028 | 1.48 GB | No | Facetune reconstructed Gradle app (11 modules), NCNN Vulkan, decompiled source. |
| `Material Image Editor` | Directory | 124 | 14 | 15,248,349 | 14.54 MB | No | Camera filters, LUT color lookup tables (2014–5002), stickers, mosaic assets. |
| `tools` | Directory | 9 | 4 | 28,266 | 27.60 KB | No | Docker, MinIO storage, WSL2 bootstrap scripts. |
| `1.txt` | File | 1 | 0 | 18,420 | 18.0 KB | No | Module overview reference. |
| `2.txt` | File | 1 | 0 | 42,109 | 41.1 KB | No | Distillation reference architecture. |
| `3.txt` | File | 1 | 0 | 15,832 | 15.5 KB | No | Testing requirements specification. |
| `4.txt` | File | 1 | 0 | 28,941 | 28.3 KB | No | Hair color engine historical notes. |
| `5.txt` | File | 1 | 0 | 33,102 | 32.3 KB | No | JNI bridge harvesting directives. |
| `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` | File | 1 | 0 | 126,894 | 123.9 KB | No | Canonical Development Workspace Standard V2.1. |
| `beauty_engine_architecture_reconstruction_and_native_bridge_2.txt` | File | 1 | 0 | 168,401 | 164.5 KB | No | C++ native bridge architecture reference. |
| `GEMINI.md` | File | 1 | 0 | 31,705 | 31.0 KB | No | Constitutional operational guidelines. |

---

## 3. Key Observations on Root Files

1. **Development Standards:** The root contains the authoritative `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` which governs all gated development phases (P0–P6).
2. **Native Bridge Specification:** `beauty_engine_architecture_reconstruction_and_native_bridge_2.txt` provides the exact class names, JNI signposts, and function descriptors for linking Kotlin to `libmeitu_reborn_native.so` and the 45 vendor `.so` libraries.
3. **Reference Text Files (`1.txt`–`5.txt`):** These files document the historical evolution of the Meitu and Facetune conversion efforts, specifically focusing on video editor architecture (`2.txt`), QA requirements (`3.txt`), and JNI symbol harvesting (`5.txt`).
