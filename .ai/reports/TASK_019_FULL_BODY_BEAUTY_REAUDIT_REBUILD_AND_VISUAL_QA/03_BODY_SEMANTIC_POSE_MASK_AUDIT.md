# 03. BODY SEMANTIC, POSE & MASK AUDIT
**Project:** CONVERT2 — Full Body Beauty Engine  
**Task ID:** TASK_019_FULL_BODY_BEAUTY_REAUDIT_REBUILD_AND_VISUAL_QA  
**Authority:** Chủ tịch Tony  
**Date:** 2026-10-03  

---

## 1. Investigation of Repository Assets & Model Inventory
A comprehensive scan of the repository tree (`app/src/main/assets/` and native directories) revealed the following NCNN models:
- `bisenet_face_19.bin` / `bisenet_face_19.param` (Face semantic segmentation: 19 classes)
- `facemesh.bin` / `facemesh.param` (Dense 468-point 3D facial mesh)
- `facemesh_3d.bin` / `facemesh_3d.param` (3D facial depth estimation)
- `hair_matting_mobile.bin` / `hair_matting_mobile.param` (Hair matting segmentation)
- `landmark106.bin` / `landmark106.param` (2D facial landmarks)
- `scrfd_500m_kps.bin` / `scrfd_500m_kps.param` (Face detector with 5 keypoints)

**Finding H Verification:**
The repository **lacks a dedicated offline full-body 17-point pose estimation model** (such as MoveNet, BlazePose, or YOLO-Pose) or a full human body parsing model (such as CIHP or ATR).

---

## 2. Root Cause of Previous Quality Defects
Prior to TASK_019, `PhotoEditorActivity.kt` invoked:
```kotlin
MeituNativeEngine.nativeApplyBodyBeauty(..., posePoints = null, headLandmarks = lmk, params)
```
When `posePoints == null`:
1. `BodySemanticEngine::extractHumanModel()` synthesized body pose points purely by extrapolating from head landmarks.
2. Even when processing a close-up or bust portrait where the lower body was off-screen, `HumanFrameResult.isValid` was assigned `true` based on head validity alone, and `overallConfidence` was hardcoded to `0.95f`.
3. Consequently, downstream algorithms (`applyLongLegs`, `applyBodyHeight`) applied heuristic stretching to the bottom half of the image (e.g. stretching between `0.48 * height` and `0.92 * height`), severely warping chest, clothing, or tabletop surfaces on bust portraits.

---

## 3. Production Architecture Correction

### 3.1 Anatomical Framing & Joint Visibility Computation
In `body_semantic_model.cpp`, we implemented anatomical head units:
$$\text{headUnits} = \frac{\text{availableH}}{\text{headH}}$$

- **Bust Portrait ($\text{headUnits} < 2.2$):** Only head, neck, and shoulders are in frame. Hips, knees, and ankles are strictly flagged with `visible = false` and `confidence = 0.0f`.
- **Half-Body Portrait ($2.2 \le \text{headUnits} < 4.2$):** Torso and hips are in frame; knees and ankles are marked `visible = false` and `confidence = 0.0f`.
- **Full-Body Portrait ($\text{headUnits} \ge 4.2$):** Full body is in frame if knee and ankle positions lie within the image bounds ($[0, \text{height}]$).

`hasLegsVisible` and `hasFullBodyVisible` are now computed strictly from genuine knee and ankle visibility:
```cpp
human.hasLegsVisible = (human.leftLeg.knee.visible && human.leftLeg.knee.confidence > 0.3f) ||
                       (human.rightLeg.knee.visible && human.rightLeg.knee.confidence > 0.3f);
human.hasFullBodyVisible = human.hasLegsVisible &&
                           (human.leftLeg.ankle.visible || human.rightLeg.ankle.visible);
```

### 3.2 Evidence-Derived Confidence
`overallConfidence` is no longer a synthetic constant `0.95f`. It is calculated as the weighted average of detected landmarks and joint confidences:
$$\text{overallConfidence} = 0.4 \times c_{\text{head}} + 0.3 \times c_{\text{torso}} + 0.3 \times c_{\text{limbs}}$$
On bust portraits, `overallConfidence` drops appropriately to $\approx 0.45\text{--}0.55$, preventing false upstream assumptions.

### 3.3 Strict Joint Visibility Guards
In `body_beauty_engine.cpp`:
- `applyLongLegs`:
  ```cpp
  if (!human.hasLegsVisible && !human.leftLeg.isVisible && !human.rightLeg.isVisible) {
      return false; // Safe no-op, zero unwanted distortion
  }
  ```
- `applyBodyHeight`:
  ```cpp
  if (hipY <= neckY + 15.0f || !human.hasLegsVisible) {
      return false; // Safe no-op
  }
  ```

### 3.4 Tool Applicability Preflight (`checkToolApplicability`)
Exposed to Kotlin and C++:
- Returns `1` (`APPLICABLE`): Required anatomical joints are present and visible.
- Returns `0` (`NOT_APPLICABLE`): Required anatomical joints are off-screen or occluded.
- Returns `-1` (`INVALID`): Input image or human frame is invalid.

This guarantees that tools will not silently execute blind warps when anatomy is absent.
