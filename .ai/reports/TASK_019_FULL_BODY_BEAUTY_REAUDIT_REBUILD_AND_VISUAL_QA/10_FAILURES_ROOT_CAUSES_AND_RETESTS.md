# 10. FAILURES, ROOT CAUSES & RETESTS
**Project:** CONVERT2 — Full Body Beauty Engine  
**Task ID:** TASK_019_FULL_BODY_BEAUTY_REAUDIT_REBUILD_AND_VISUAL_QA  
**Authority:** Chủ tịch Tony  
**Date:** 2026-10-03  

---

## 1. Defect Summary Table

| ID | Defect Classification | Affected Components | Root Cause | Implemented Solution | Retest Verdict |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **DEF_01** | Severe Unnatural Distortion on Bust Portraits | `body_semantic_model.cpp`, `body_beauty_engine.cpp` | Synthetic pose generated off-screen legs; `applyLongLegs` stretched bottom half of bust portraits. | Implemented anatomical headUnits (`availableH / headH`) & joint visibility guards (`hasLegsVisible`). Returns `false` (no-op). | `PASS_GUARDED` (0 px unwanted change) |
| **DEF_02** | Legacy Fixed-Coordinate Fallback on Chest Reshape | `PhotoEditorActivity.kt`, `body_hair_engine.cpp` | `tool_body_chest` called legacy `nativeApplyBodyReshape(..., 3004)` with hardcoded 896x1200 coordinates (chest at 880). | Implemented canonical `applyChestReshape` anchored to clavicle/shoulders with subpixel bicubic warp; wired directly to JNI/Kotlin. | `PHYSICAL_PASS` (16,980 px changed, zero background distortion) |
| **DEF_03** | Dropped / Unconsumed Body Parameters | `jni_bridge.cpp`, `body_beauty_engine.cpp` | JNI parsed `abdomenSlim` and `chestEnhance`, but `processFullBodyBeauty` ignored them in canonical stages. | Actively integrated `chestEnhance` and `abdomenSlim` into `processFullBodyBeauty` execution graph. | `PASS` (Verified in unit test & on device) |
| **DEF_04** | Fabricated `overallConfidence = 0.95f` | `body_semantic_model.cpp` | `overallConfidence` was hardcoded to 0.95 whenever head was valid, even with 0 visible body joints. | Calculated dynamic weighted confidence from detected face, torso, and limb joints. | `PASS` (Confidence appropriately drops to 0.45 on bust portraits) |
| **DEF_05** | Missing Offline Full-Body Pose Model in Repo | `assets/`, `lib-core-graphics` | Repository lacks MoveNet / BlazePose / CIHP body parsing NCNN model assets. | Enforced strict anatomical framing guards and reported honest blocker `FULL_BODY_BLOCKED_POSE_MODEL`. | `BLOCKED_AWAITING_MODEL` |

---

## 2. In-Depth Root Cause & Verification Details

### DEF_01: Bust Crop Blind Stretching
- **Observed Bug:** When opening a close-up portrait (e.g. `scratch/0.jpg`) and activating `tool_long_legs` or `tool_body_height`, the lower portion of the blouse and background were stretched violently.
- **Root Cause:** In `body_semantic_model.cpp`, `extractHumanModel()` estimated legs down to `imageH` regardless of whether they were in frame. Then `applyLongLegs` warped pixels from `0.48 * imageH` to `0.92 * imageH`.
- **Correction:**
  1. Measured `headUnits = availableH / headH`. For bust portraits ($\text{headUnits} < 2.2$), `hasLegsVisible = false`.
  2. In `applyLongLegs` and `applyBodyHeight`, added strict early exit:
     ```cpp
     if (!human.hasLegsVisible) return false;
     ```
- **Retest Evidence:** Tested on `scratch/0.jpg` with intensity 70% and 100%. Measured diff: 0 changed pixels, 0.0 background line deviation, 100% preservation score.

### DEF_02: Chest Tool Fixed Coordinates
- **Observed Bug:** `tool_body_chest` resulted in unnatural pinching/swelling at fixed vertical pixel position 880, completely mismatched for varying head heights.
- **Root Cause:** Legacy path routed to `BodyHairEngine::applyBodyReshape(..., 3004)`.
- **Correction:** Created `BodyBeautyEngine::applyChestReshape(cv::Mat& image, const HumanFrameResult& human, float intensity)`. Radial displacement is centered anatomically below the detected clavicle line between the left and right shoulder vectors, with `attenuateBoundaryLeakage` preserving borders.
- **Retest Evidence:** Tested on `scratch/1.jpg`. Produced smooth natural pectoral/chest definition with 16,980 modified pixels and 0 artifact score.
