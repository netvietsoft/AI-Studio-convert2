# 04. DUPLICATE & DEAD PATH ANALYSIS
**Project:** CONVERT2 — Full Body Beauty Engine  
**Task ID:** TASK_019_FULL_BODY_BEAUTY_REAUDIT_REBUILD_AND_VISUAL_QA  
**Authority:** Chủ tịch Tony  
**Date:** 2026-10-03  

---

## 1. Audit of Compiled Native Body Modules
The repository CMake script (`lib-core-graphics/CMakeLists.txt`) compiles multiple body-related source files into `libmeitu_reborn_native.so`:

1. `body_beauty_engine.cpp` (CANONICAL PRODUCTION PIPELINE)
2. `body_semantic_model.cpp` (CANONICAL SKELETON / MASK EXTRACTOR)
3. `neck_clavicle_engine.cpp` (CANONICAL NECK/CLAVICLE PIPELINE)
4. `clavicle_shoulder_engine.cpp` (CANONICAL CLAVICLE / SHOULDER EDITOR)
5. `full_human_beauty_controller.cpp` (CANONICAL MASTER AGGREGATOR)
6. `dense_body_mesh.cpp` (BOUND IN JNI: `nativeAnalyzeBodyContour`)
7. `body_contour_engine.cpp` (BOUND IN JNI: `nativeAnalyzeBodyContour`)
8. `long_legs_body_slim_engine.cpp` (DEAD / UNREFERENCED)
9. `body_limb_hand_engine.cpp` (DEAD / UNREFERENCED)
10. `body_hair_engine.cpp` (LEGACY FIXED-COORDINATE FALLBACK)

---

## 2. In-Depth Path Assessment

### 2.1 `meitu::body::LongLegsBodySlimEngine` (DEAD / DUPLICATE)
- **Status:** Compiled in CMake, but zero references exist in `jni_bridge.cpp` or Kotlin.
- **Analysis:** This file represents an early experimental implementation of long-leg and waist slimming. It duplicates algorithms already implemented with higher quality in `meitu_native::BodyBeautyEngine` (which incorporates `BackgroundProtectionEngine` and `ClothingAwareEngine`).
- **Decision:** Classified as `DEAD_DUPLICATE`. Not wired to JNI to prevent fragmented maintenance. Production pipeline uses `BodyBeautyEngine`.

### 2.2 `meitu::body::BodyLimbHandEngine` (DEAD / DUPLICATE)
- **Status:** Compiled in CMake, but zero references exist in `jni_bridge.cpp`.
- **Analysis:** Contains standalone `beautifyHands` and `beautifyAnkles`. In production, hand and foot protection is handled directly by `BodyBeautyEngine`'s spatial displacement decay and vertical warp boundary clamping.
- **Decision:** Classified as `COMPILED_PROTECTED`. Preserved in CMake for reference; core protection enforced in `BodyBeautyEngine`.

### 2.3 `BodyHairEngine::applyBodyReshape` (ELIMINATED FROM PRODUCTION ROUTING)
- **Status:** Previously called from `PhotoEditorActivity.kt` using tool IDs 3001, 3002, 3004, 3007, 3008, 3010, 3011.
- **Defect:** Applied fixed pixel coordinates normalized to an 896x1200 canvas (e.g. waist at 1040, chest at 880, legs at 1000). On images with different framing (e.g. bust portraits), it caused grotesque distortions.
- **Resolution:** Completely decoupled and removed from `PhotoEditorActivity.kt`. Replaced by:
  - `nativeApplyChestReshape` for chest enhancement.
  - `nativeApplyBodyBeauty` with joint visibility guards for all other body tools.

---

## 3. Canonical Pipeline Selection Matrix

| Subsystem | Legacy/Duplicate Path | Canonical Production Path | Rationale |
| :--- | :--- | :--- | :--- |
| **Chest Reshape** | `BodyHairEngine::applyBodyReshape` (fixed 880px) | `BodyBeautyEngine::applyChestReshape` | Anchored to detected clavicle & shoulders; bicubic subpixel interpolation with background protection. |
| **Long Legs** | `LongLegsBodySlimEngine` & fixed 1000px | `BodyBeautyEngine::applyLongLegs` | Guarded by `hasLegsVisible`; multi-zone non-linear stretch along leg bones. |
| **Waist Slim** | `LongLegsBodySlimEngine` & fixed 1040px | `BodyBeautyEngine::applyWaistAndBodySlim` | Edge-gradient displacement with boundary leakage attenuation. |
| **Neck / Clavicle** | Legacy coordinate stretch | `NeckClavicleEngine` & `ClavicleShoulderEngine` | Micro-contrast enhancement and bilateral neck contraction. |
| **Body Skin** | Global blur | `BodyBeautyEngine::applySkinBeautification` | Bilateral guided filter with micro-pore texture retention $\ge 85\%$. |
