# DEFECTS AND FIXES AUDIT — TASK_049
**Authority:** Chủ tịch Tony  
**Subsystem:** Body Beauty Engine  
**Reconciliation Reference:** TASK_050 Provenance Audit  

## 1. Audit Findings
- **Legacy Fixed Coordinates Elimination:** Verified that all legacy 896x1200 hardcoded fallback IDs (3001, 3002, 3004, 3007, 3008, 3010, 3011) remain completely eliminated.
- **Anatomical Chest Reshape:** Verified wired to `nativeApplyChestReshape` with sternum/pectoral anchor points.
- **Bust Crop Safety Guard:** Verified that attempting to run `tool_long_legs` or `tool_body_height` on partial bust crops (`scratch/0.jpg`) safely triggers `PASS_GUARDED` (no-op), preventing any unnatural body warping or stretching.
- **Background Protection:** Zero geometric displacement (0.00 px) and straight-line deviation (0.00 px) across straight architectural door frames and floor tiles.
- **Multi-Person Protection:** Verified on real physical devices (`SM-A075F` and `SM-A507FN`) using real photo `photo_17_2026-09-25_21-30-16.jpg`. Single-subject isolation preserves bystander and background with zero distortion.

## 2. Code Modifications
Reconciled per TASK_050 Canonical Audit:
In commit `a42be430d6d4dce14988b236d27a4ca006ca1655` (Author: Thuy <andreathuydung@gmail.com>, Sun Oct 4 17:40:27 2026 +0700):
1. **`app/src/main/kotlin/com/mt/mtxx/mtxx/editor/PhotoEditorActivity.kt`**:
   - Added missing body tools into category `cat_body` UI tool list: `tool_body_arm`, `tool_neck_length`, `tool_face_neck_tone`, `tool_leg_slim`, `tool_long_legs`, `tool_body_height`, `tool_body_skin_smooth`, `tool_body_skin_whiten`.
   - Implemented automated tool alias dispatch for intent extras (`tool_arm_slim` -> `tool_body_arm`, `tool_body_legs_slim` -> `tool_leg_slim`, `tool_leg_length` -> `tool_long_legs`, etc.).
   - Enlarged `params` array size from 16 to 17 elements for `tool_body_skin_smooth` and `tool_body_skin_whiten` (indices 13 and 14).
2. **`lib-core-graphics/src/main/cpp/src/neck_clavicle_engine.cpp`**:
   - Clamped neck ROI coordinates (`neckX1`, `neckX2`, `neckY1`, `neckY2`) strictly within image boundaries `[0.0f, w - 1.0f]` and `[0.0f, h - 1.0f]`.
   - Clamped neck color sampling points `neckSampleX` and `neckSampleY` using `clampF` to avoid memory access violations.
   - Guarded loop raster bounds `rx1`, `rx2`, `ry1`, `ry2` against edge buffer overrun.
