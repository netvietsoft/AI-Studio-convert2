# 01. WORKSPACE DIRECTORY TREE: F:\CONVERT

**Authoritative Scan Root**: `F:\CONVERT`  
**Scan Timestamp**: `2026-10-04T11:51:19+07:00`  
**Physical Runner**: `CONVERT2-WINDOWS-02` / `CONVERT2-WINDOWS-03`  

---

## 1. Top-Level Directory Tree of F:\CONVERT

```
F:\CONVERT\
├── com.mt.mtxx.mtxx/                     [Meitu Reborn Primary Workspace]
│   ├── CONVERT2/                         [Active Git Workspace - 8 modules, Vulkan C++ Core]
│   ├── CONVERT/                          [Predecessor Workspace - 26 modules, C++ native-bridge]
│   ├── SOURCE/                           [Reverse Engineering Root - jadx, apktool, 45 .so libs]
│   ├── Yeucau/                           [Requirements & Ground Truth Masks/Portraits]
│   ├── beard_assets_10_png/              [10 PNG beard assets]
│   ├── _stray_backup_w9/                 [Orphaned Wave 9 backup]
│   └── ẢNH/                              [Reference test portraits]
├── com.lightricks.facetune.free/         [Facetune Workspace - Designated in 1.txt]
│   ├── CONVERT/                          [Reconstructed Android App - 11 modules]
│   ├── SOURCE/                           [Decompiled Facetune Root - jadx_out, apktool_out]
│   ├── Report/                           [Functional mapping & audit reports]
│   └── report 2/                         [Secondary audit reports]
├── Material Image Editor/                [Shared Resource Repository]
│   └── Mitu/material/                    [Apple camera filters, 12 online material categories]
├── tools/                                [Infrastructure & DevOps Tools]
│   ├── docker/                           [Docker Desktop installer]
│   ├── minio/                            [MinIO local S3 storage]
│   └── wsl_update_x64.msi                [WSL setup and update utilities]
└── [11 Root Documents & Scripts]
    ├── 1.txt                             [CEO Operating Charter & Facetune SOURCE mandate]
    ├── 2.txt                             [Architecture Distillation Reference Standard]
    ├── 3.txt                             [Skin & Retouch specifications]
    ├── 4.txt                             [Slider dynamic range requirements]
    ├── 5.txt                             [Tone mapping & color science requirements]
    ├── beauty_engine_architecture...txt  [InsightFace & NCNN C++ architecture specification]
    ├── Development_Workspace_Standard... [Workspace Standard V2.1 Design Gated]
    ├── GEMINI.md                         [CONVERT Operational Constitution]
    ├── _ftvapp_files.txt                 [Facetune file inventory]
    ├── _kotlinc_ftvapp.log               [Facetune Kotlin compilation log]
    └── _verify_ftvapp.py                 [Facetune compilation verification script]
```

---

## 2. Detailed Structure: com.mt.mtxx.mtxx

### 2.1 CONVERT2 (Active Production Workspace)
- `app/`: Android application harness.
- `lib-core-graphics/`: Native C++ engine (`libmeitu_reborn_native.so`), Vulkan compute shaders, JNI bridge, CPU fallback.
- `lib-image-processing/`: Image decoding, bitmap buffers, color space conversions.
- `lib-makeup-engine/`: Makeup layers, blush, lipstick, eye shadow.
- `lib-face-beautify/`: Face retouching, smoothing, whitening, 3DMM reshaping.
- `lib-body-reshape/`: Full body beauty, skeleton pose detection, background protection.
- `lib-color-grading/`: 3D LUT filters, tone curves, display-P3/sRGB transcoding.
- `lib-ai-segmentation/`: BiSeNet face/hair parsing, MoveNet skeleton tracking.

### 2.2 CONVERT (Ancestor Reconstructed Workspace)
- `apps/android/`: 26-module Android project (`mtxx-reborn`).
  - `core/native-bridge/`: Complete C++ engine with 50+ files in `src/main/cpp`.
  - `feature/`: 19 feature modules (`beauty`, `camera`, `editor`, `videoedit`, `idphoto`, `poster`, `puzzle`, `livephoto`, etc.).
- `services/api/`: TypeScript backend service (1,851 files).
- `reconstruction-input/`: Mirror of JADX decompiled sources and 45 native `.so` libraries.
- `datasets/hair-color-v2/`: Hair color testing dataset with 250 annotated assets.
- `tools/hair_v2/`: Hair benchmark recalculation tools.

### 2.3 SOURCE (Reverse Engineering Root)
- `jadx_src/sources/`: 106,466 decompiled Java source files from Meitu APK.
- `apktool_out/`: Smali bytecode disassembly across 9 dex partitions, AndroidManifest.xml, res/.
- `extracted_native_libs/`: 45 ELF `.so` libraries for `arm64-v8a`.
- `extracted_assets/`: 4,656 raw APK assets (models, shaders, LUTs).
- `dex_files/`: 20 raw `.dex` partitions.
- `mitu/`: Reverse engineering models, lua scripts, shaders, poprock UI.
- `Redesign/`: HTML/XML redesign specifications and tokens.

---

## 3. Detailed Structure: com.lightricks.facetune.free

### 3.1 CONVERT (Facetune Reconstructed Android Workspace)
- Root settings: `settings.gradle.kts` (`facetune-convert`).
- Foundation Libraries (7 modules):
  - `lib-filters`: Preset filter engine.
  - `lib-video-engine`: Timeline, video playback, and frame extraction.
  - `lib-image-editing`: Core image manipulation.
  - `lib-ui-toolkit`: Shared UI components.
  - `lib-billing`: Store billing and subscriptions.
  - `lib-logging`: Diagnostics and analytics.
  - `lib-storage-db`: Room database and cache.
- Feature Modules (3 modules):
  - `feature-cloud-ai`: Remote AI processing.
  - `feature-ai-retouch`: Portrait retouching pipeline.
  - `feature-story-maker`: Story creation flows.
- Executable: `app/`.

### 3.2 SOURCE (Facetune Reverse Engineering Root)
- `jadx_out/`: 26,020 decompiled Java files.
- `apktool_out/`: Disassembled smali and decoded resources.
- `extracted_xapk/`: Extracted APK partitions and native libraries.
- `Report/`: Functional mapping analysis and API reviews.
