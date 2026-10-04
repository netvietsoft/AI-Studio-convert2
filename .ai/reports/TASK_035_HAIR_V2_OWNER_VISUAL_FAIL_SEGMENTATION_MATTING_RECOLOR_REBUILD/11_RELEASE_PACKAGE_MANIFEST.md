# 11. RELEASE PACKAGE MANIFEST
**Task ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_SEGMENTATION_MATTING_NATURAL_RECOLOR_REBUILD_ACTIVE`  
**Command ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_REBUILD_20261004T090300+0700`  
**Execution Lane:** `hair-v2-owner-fail-rebuild`  
**Target Release Gate:** `TECHNICAL_PASS_AWAITING_OWNER_VISUAL` (Awaiting Chairman Tony's Visual Inspection)

---

## 1. File Modification Manifest

| File Path | Component | Description of Modification |
|---|---|---|
| `lib-core-graphics/src/main/cpp/include/hair/hair_pipeline_v2.h` | Native C++ Core Engine | Added `Version` enum (`V1`, `V2_BASELINE`, `V3_REBUILD`), `setExecutionVersion`, and `executePipelineV3_Rebuild` signature. |
| `lib-core-graphics/src/main/cpp/src/hair/hair_pipeline_v2.cpp` | Native C++ Core Engine | Implemented complete Hair V3 pipeline: cranial crown seed extraction, multi-zone protected gating, OKLab salon dye, 7x7 illumination decomposition, 100% micro-strand re-injection, and sheer clothing rejection. |
| `lib-core-graphics/src/main/cpp/include/ai/bisenet_face_parser.h` | BiSeNet Parser Header | Added optional `outFullHairProb` parameter to `parseFace19Adaptive`. |
| `lib-core-graphics/src/main/cpp/src/ai/bisenet_face_parser.cpp` | BiSeNet Parser Implementation | Populated full-resolution hair probability map aligned with original image dimensions. |
| `lib-core-graphics/src/main/cpp/src/jni_bridge.cpp` | JNI Native Bridge | Added JNI export methods `nativeSetHairPipelineVersion` and `nativeGetHairPipelineVersion`. |
| `lib-core-graphics/src/main/kotlin/com/meitu/core/nativeengine/MeituNativeEngine.kt` | Kotlin Bridge | Exposed `setHairPipelineVersion` and `getHairPipelineVersion` methods. |
| `scripts/run_task_035_dual_device_acceptance.py` | Physical Device Test Suite | Dual-device automated test runner across 40 physical hardware test cases. |

---

## 2. Release Binary Artifacts
- **Target APK:** `app/build/outputs/apk/debug/app-debug.apk`
- **Native Shared Object:** `lib-core-graphics/build/intermediates/cxx/Debug/b2j6m3g6/obj/arm64-v8a/libmeitu_reborn_native.so`
- **Architecture:** `arm64-v8a` (Primary target for SM-A075F and SM-A507FN)
