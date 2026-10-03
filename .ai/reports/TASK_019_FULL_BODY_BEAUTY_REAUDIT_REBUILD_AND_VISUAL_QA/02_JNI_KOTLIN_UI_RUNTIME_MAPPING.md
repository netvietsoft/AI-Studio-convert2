# 02. JNI, KOTLIN & UI RUNTIME MAPPING
**Project:** CONVERT2 — Full Body Beauty Engine  
**Task ID:** TASK_019_FULL_BODY_BEAUTY_REAUDIT_REBUILD_AND_VISUAL_QA  
**Authority:** Chủ tịch Tony  
**Date:** 2026-10-03  

---

## 1. Executive Architecture Summary
This document establishes the verified source-of-truth runtime mapping connecting Android Kotlin UI components (`PhotoEditorActivity.kt`), Kotlin Native Wrappers (`MeituNativeEngine.kt`), JNI Bridge bindings (`jni_bridge.cpp`), and Native C++ Core Graphics Engines (`libmeitu_reborn_native.so`).

All legacy unverified fallbacks (such as fixed 896x1200 coordinates in `BodyHairEngine::applyBodyReshape`) have been disconnected from production UI routing.

---

## 2. Complete Runtime Mapping Table

| UI Tool ID | Feature / Module | Kotlin Native Method | JNI Export Symbol | Native C++ Engine & Method | Parameter Index / Mapping |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `tool_body_slim` | Full Body Slim | `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyBodyBeauty` | `meitu_native::BodyBeautyEngine::applyWaistAndBodySlim` | `params[0]` (-100..100) |
| `tool_body_waist` | Waist Slim | `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyBodyBeauty` | `meitu_native::BodyBeautyEngine::applyWaistAndBodySlim` | `params[1]` (-100..100) |
| `tool_body_shoulder` | Shoulder Width/Slim | `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyBodyBeauty` | `meitu_native::BodyBeautyEngine::applyShoulderReshape` | `params[2]` (-100..100) |
| `tool_body_arm` / `tool_arm_slim` | Upper Arm Slim | `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyBodyBeauty` | `meitu_native::BodyBeautyEngine::applyArmSlim` | `params[3]` (0..100) |
| `tool_body_legs` | Leg Slim | `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyBodyBeauty` | `meitu_native::BodyBeautyEngine::applyLegSlim` | `params[4]` (-100..100) |
| `tool_long_legs` / `tool_leg_length` | Long Legs | `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyBodyBeauty` | `meitu_native::BodyBeautyEngine::applyLongLegs` | `params[4]` (0..100) |
| `tool_body_height` / `tool_height` | Body Height | `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyBodyBeauty` | `meitu_native::BodyBeautyEngine::applyBodyHeight` | `params[5]` (-100..100) |
| `tool_body_chest` | Anatomical Chest Reshape | `nativeApplyChestReshape` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyChestReshape` | `meitu_native::BodyBeautyEngine::applyChestReshape` | Intensity (-100..100) via Clavicle Anchors |
| `tool_body_hip` / `tool_hip_enhance` | Hip Reshape | `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyBodyBeauty` | `meitu_native::BodyBeautyEngine::applyHipReshape` | `params[6]` (-100..100) |
| `tool_body_skin_smooth` | Body Skin Smooth | `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyBodyBeauty` | `meitu_native::BodyBeautyEngine::applySkinBeautification` | `params[7]` (0..100) |
| `tool_body_skin_whiten` | Body Skin Whiten | `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyBodyBeauty` | `meitu_native::BodyBeautyEngine::applySkinBeautification` | `params[8]` (0..100) |
| `tool_body_neck` / `tool_neck_slim` | Neck Slim | `nativeApplyNeckClavicle` / `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyNeckClavicle` | `meitu_native::NeckClavicleEngine::applyNeckSlim` | `params[10]` (-100..100) |
| `tool_neck_length` / `tool_swan_neck` | Swan Neck Length | `nativeApplyNeckClavicle` / `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyNeckClavicle` | `meitu_native::NeckClavicleEngine::applySwanNeck` | `params[11]` (0..100) |
| `tool_clavicle_enhance` | Clavicle Sculpt | `nativeApplyClavicleShoulderEdit` / `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyClavicleShoulderEdit` | `meitu_native::ClavicleShoulderEngine::applyClavicleEnhance` | `params[12]` (0..100) |
| `tool_face_neck_tone` | Face-Neck Tone Match | `nativeApplyNeckClavicle` / `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyNeckClavicle` | `meitu_native::NeckClavicleEngine::matchFaceNeckTone` | `params[13]` (0..100) |
| `tool_body_abdomen` | Abdomen Slim | `nativeApplyBodyBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyBodyBeauty` | `meitu_native::BodyBeautyEngine::applyWaistAndBodySlim` | `params[15]` (0..100) |
| `tool_body_preflight` | Tool Applicability Preflight | `nativeCheckBodyToolApplicability` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeCheckBodyToolApplicability` | `meitu_native::BodySemanticEngine::checkToolApplicability` | Returns 1 (APPLICABLE), 0 (NOT_APPLICABLE), -1 (INVALID) |
| `MASTER_PIPELINE` | Full Human Beauty Master | `nativeApplyFullHumanBeauty` | `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyFullHumanBeauty` | `meitu_native::FullHumanBeautyController::executePipeline` | Master Composite Config |

---

## 3. Parameter Array Specification (`FloatArray(17)`)
In `PhotoEditorActivity.kt`, the parameter array passed to `nativeApplyBodyBeauty` is explicitly dimensioned to 17 elements:
- `params[0]`: `bodySlim` (-100.0f .. 100.0f)
- `params[1]`: `waistSlim` (-100.0f .. 100.0f)
- `params[2]`: `shoulderWidth` (-100.0f .. 100.0f)
- `params[3]`: `armSlim` (0.0f .. 100.0f)
- `params[4]`: `legLength` / `legSlim` (0.0f .. 100.0f)
- `params[5]`: `bodyHeight` (-100.0f .. 100.0f)
- `params[6]`: `hipEnhance` (-100.0f .. 100.0f)
- `params[7]`: `skinSmooth` (0.0f .. 100.0f)
- `params[8]`: `skinWhiten` (0.0f .. 100.0f)
- `params[9]`: `headBodyRatio` (0.0f .. 100.0f)
- `params[10]`: `neckSlim` (-100.0f .. 100.0f)
- `params[11]`: `swanNeck` (0.0f .. 100.0f)
- `params[12]`: `clavicleEnhance` (0.0f .. 100.0f)
- `params[13]`: `faceNeckTone` (0.0f .. 100.0f)
- `params[14]`: `waistCurve` (0.0f .. 100.0f)
- `params[15]`: `abdomenSlim` (0.0f .. 100.0f)
- `params[16]`: `chestEnhance` (-100.0f .. 100.0f)

---

## 4. Elimination of Legacy Hardcoded Fallbacks
Prior to TASK_019, `PhotoEditorActivity.kt` dispatched calls to `nativeApplyBodyReshape` with magic tool IDs `3001..3011` when `posePoints == null`. That path in `BodyHairEngine::applyBodyReshape` executed fixed coordinate warps based on an arbitrary 896x1200 canvas (e.g. waist at 1040, chest at 880, legs at 1000). On bust portraits or non-conforming dimensions, this caused severe unnatural stretching.

**Resolution:**
1. All legacy calls `nativeApplyBodyReshape(..., 3001..3011)` were eliminated from `PhotoEditorActivity.kt`.
2. `tool_body_chest` was mapped to `nativeApplyChestReshape`, executing true anatomical chest enhancement anchored to detected clavicle and shoulder coordinates.
3. All limb operations execute through `nativeApplyBodyBeauty` with joint visibility guards and applicability preflight.
