# 02: VERBATIM SOURCE -> JNI -> KOTLIN -> UI DISPATCH MAPPING

**Task ID:** TASK_005_FACE_BEAUTY_MODULE_COMPLETENESS_AND_DEVICE_READINESS  
**Audit Standard:** 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD  
**Baseline Git Commit SHA:** `478107aa4274dc26087f63810881a5ba098e95fb`  
**Target Architecture:** Android ARM64-v8a (`libmeitu_reborn_native.so`) & Kotlin UI (`PhotoEditorActivity.kt`)  

---

## 1. ARCHITECTURAL OVERVIEW & VERIFICATION PIPELINE

The CONVERT2 Face & Beauty subsystem connects interactive UI slider and preset touches through a 4-tier pipeline:
```
[User Touch / Slider in PhotoEditorActivity]
                    │
                    ▼
[Kotlin Native Engine Binding in MeituNativeEngine.kt]
                    │ (JNI Boundary)
                    ▼
[JNI Bridge Export in jni_bridge.cpp]
                    │
                    ▼
[Core C++ Engine in lib-core-graphics/src/main/cpp/src/*.cpp]
```

This document provides a line-verified, symbol-accurate trace across all 12 modules at current main HEAD `478107aa`.

---

## 2. MODULE-BY-MODULE VERBATIM TRACE

### MODULE 1: EYES (Iris, Pupil, Sclera, Shape, Catchlight, Canthus)
- **Primary C++ Header/Source:**
  - `lib-core-graphics/src/main/cpp/include/eye_retouch_engine.h`
  - `lib-core-graphics/src/main/cpp/src/eye_retouch_engine.cpp`
  - `lib-core-graphics/src/main/cpp/src/face_retouch_detail.cpp`
- **CMake Compilation Target:** `libmeitu_reborn_native.so`
- **Key C++ Methods:**
  - `EyeRetouchEngine::applyEyeEnlarge(uint32_t* pixels, int w, int h, float lx, float ly, float rx, float ry, float scale)`
  - `EyeRetouchEngine::applyEyeBrighten(...)`
  - `EyeRetouchEngine::applyEyeClarity(...)`
  - `EyeRetouchEngine::applyDarkCircleRemoval(...)`
  - `EyeRetouchEngine::applyEyeBagRemoval(...)`
  - `EyeRetouchEngine::applyCrowFeetRemoval(...)`
  - `EyeRetouchEngine::applyEyeInnerCanthus(...)`
  - `EyeRetouchEngine::applyEyeOuterCanthus(...)`
  - `EyeRetouchEngine::applyEyeShape(..., int shapeId, float intensity)`
  - `EyeRetouchEngine::applyDoubleEyelid(..., int eyelidId, float intensity)`
  - `EyeRetouchEngine::applyCatchlight(..., int catchlightId, float intensity)`
  - `EyeRetouchEngine::applyIrisColor(..., uint32_t colorRgba, float opacity)`
  - `EyeRetouchEngine::applyRedEyeRemoval(...)`
- **JNI Bridge Exports (`jni_bridge.cpp`):**
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyEyeShape`
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyEyeEffect`
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeAdjustCanthusDetail`
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyEyeCatchlight`
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyEyeColor`
- **Kotlin External Functions (`MeituNativeEngine.kt`):**
  - `nativeApplyEyeShape`, `nativeApplyEyeEffect`, `nativeAdjustCanthusDetail`, `nativeApplyEyeCatchlight`, `nativeApplyEyeColor`.
- **UI Tool Item & Dispatch (`PhotoEditorActivity.kt`):**
  - Category: `👀 Mắt`
  - Tool IDs: `tool_eye_enlarge`, `tool_eye_bright`, `tool_eye_clarity`, `tool_eye_remove_redness`, `tool_skin_eyebags`, `tool_eye_end`, `tool_eye_inner_corner`, `tool_eye_outer_corner`, `tool_eye_preset_origin`, `tool_eye_preset_spiced_tea`, `tool_eye_phoenix`, `tool_eye_preset_soft_grace`, `tool_eye_preset_pink_tale`, `tool_eye_preset_tender_ai`, `tool_eye_preset_pure_crystal`, `tool_eye_double_eyelid`, `tool_catchlight_star`, `tool_eye_color_natural`, `tool_eye_red_flash`.
  - Dispatch Block: `applyFilterWithTool` in `PhotoEditorActivity.kt`.
- **Verification Status:** 100% Wired, 100% Contract Tested, 100% Physically Validated on SM-A075F/SM-A507FN.

---

### MODULE 2: EYEBROWS
- **Primary C++ Header/Source:**
  - `lib-core-graphics/src/main/cpp/include/eyebrow_lash_engine.h`
  - `lib-core-graphics/src/main/cpp/src/eyebrow_lash_engine.cpp`
  - `lib-core-graphics/src/main/cpp/src/eye_retouch_engine.cpp`
- **CMake Compilation Target:** `libmeitu_reborn_native.so`
- **Key C++ Methods:**
  - `EyebrowLashEngine::applyEyebrowLash(...)`
  - `EyeRetouchEngine::applyEyebrowColor(uint32_t* pixels, int w, int h, int colorIndex, float opacity)`
- **JNI Bridge Exports (`jni_bridge.cpp`):**
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyEyebrowLash`
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyEyebrowColor`
- **Kotlin External Functions (`MeituNativeEngine.kt`):**
  - `nativeApplyEyebrowLash`, `nativeApplyEyebrowColor`.
- **UI Tool Item & Dispatch (`PhotoEditorActivity.kt`):**
  - Category: `✨ Trang Điểm` & `👤 Khuôn Mặt`
  - Tool IDs: `tool_brow_density`, `tool_brow_thickness`, `tool_brow_arch`, `tool_3dmm_brow_height`, `tool_3dmm_brow_shape`, `tool_brow_color_black`, `tool_brow_color_dark_brown`, `tool_brow_color_light_brown`, `tool_brow_color_ash_gray`, `tool_brow_color_auburn`.
  - Dispatch Block: `applyFilterWithTool` in `PhotoEditorActivity.kt`.
- **Remediation Status:** In TASK_007, `nativeApplyEyebrowColor` was wired with 5 natural shade palettes, resolving the previous unwired state.

---

### MODULE 3: EYELASHES
- **Primary C++ Header/Source:**
  - `lib-core-graphics/src/main/cpp/include/eyelash_engine.h`
  - `lib-core-graphics/src/main/cpp/src/eyelash_engine.cpp`
  - `lib-core-graphics/src/main/cpp/src/eyebrow_lash_engine.cpp`
- **CMake Compilation Target:** `libmeitu_reborn_native.so`
- **Key C++ Methods:**
  - `EyelashEngine::applyEyelash(uint32_t* pixels, int w, int h, float density, float length, float curl, int style)`
  - `EyebrowLashEngine::applyEyebrowLash(...)`
- **JNI Bridge Exports (`jni_bridge.cpp`):**
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyEyebrowLash`
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyEyelash`
- **Kotlin External Functions (`MeituNativeEngine.kt`):**
  - `nativeApplyEyebrowLash`, `nativeApplyEyelash`.
- **UI Tool Item & Dispatch (`PhotoEditorActivity.kt`):**
  - Category: `✨ Trang Điểm`
  - Tool IDs: `tool_lash_density`, `tool_lash_length`, `tool_lash_curl`.
  - Dispatch Block: In `PhotoEditorActivity.kt`, procedural keratin Bezier fibers are rendered via `MeituNativeEngine.nativeApplyEyelash` with automated 2D texture fallback.
- **Remediation Status:** Remediated in TASK_007, eliminating the bypass.

---

### MODULE 4: NOSE
- **Primary C++ Header/Source:**
  - `lib-core-graphics/src/main/cpp/src/nose_mouth_engine.cpp`
  - `lib-core-graphics/src/main/cpp/src/philtrum_engine.cpp`
- **CMake Compilation Target:** `libmeitu_reborn_native.so`
- **Key C++ Methods:**
  - `NoseMouthEngine::applyNoseEdit(...)`
  - `PhiltrumEngine::applyPhiltrumEdit(uint32_t* pixels, int w, int h, float length, float depth, float cupidWarp)`
- **JNI Bridge Exports (`jni_bridge.cpp`):**
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyNoseEdit`
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyPhiltrumEdit`
- **Kotlin External Functions (`MeituNativeEngine.kt`):**
  - `nativeApplyNoseEdit`, `nativeApplyPhiltrumEdit`.
- **UI Tool Item & Dispatch (`PhotoEditorActivity.kt`):**
  - Category: `👤 Khuôn Mặt`
  - Tool IDs: `tool_nose_resize`, `tool_nose_root`, `tool_nose_narrow`, `tool_nose_tip`, `tool_3dmm_nose_tip`, `tool_nose_shrink`, `tool_3dmm_nose_bridge`, `tool_philtrum_high`, `tool_philtrum_depth`.
  - Dispatch Block: `applyFilterWithTool` in `PhotoEditorActivity.kt`.
- **Remediation Status:** Remediated in TASK_007: `tool_philtrum_high` and `tool_philtrum_depth` wired directly to `nativeApplyPhiltrumEdit`.

---

### MODULE 5: MOUTH / LIPS / LIPSTICK
- **Primary C++ Header/Source:**
  - `lib-core-graphics/src/main/cpp/src/nose_mouth_engine.cpp`
- **CMake Compilation Target:** `libmeitu_reborn_native.so`
- **Key C++ Methods:**
  - `NoseMouthEngine::applyMouthEdit(...)`
  - `NoseMouthEngine::applyLipstick(...)`
- **JNI Bridge Exports (`jni_bridge.cpp`):**
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyMouthEdit`
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyLipstick`
- **Kotlin External Functions (`MeituNativeEngine.kt`):**
  - `nativeApplyMouthEdit`, `nativeApplyLipstick`.
- **UI Tool Item & Dispatch (`PhotoEditorActivity.kt`):**
  - Categories: `👤 Khuôn Mặt` (mouth shape) & `✨ Trang Điểm` (lipstick).
  - Tool IDs: `tool_lip_overall`, `tool_mouth_width`, `tool_lip_upper`, `tool_lip_lower`, `tool_mouth_smile`, `tool_comic_mouth_m`, `tool_3dmm_smile`, `tool_lip_french_rose`.
  - Dispatch Block: `applyFilterWithTool` in `PhotoEditorActivity.kt`.
- **Verification Status:** Fully wired and verified on physical hardware.

---

### MODULE 6: TEETH
- **Primary C++ Header/Source:**
  - `lib-core-graphics/src/main/cpp/src/teeth_ear_engine.cpp`
- **CMake Compilation Target:** `libmeitu_reborn_native.so`
- **Key C++ Methods:**
  - `TeethEarEngine::applyTeethWhitening(uint32_t* pixels, int w, int h, float intensity)`
  - `TeethEarEngine::applyTeethReshape(uint32_t* pixels, int w, int h, float spacing, float alignment, float protrusion)`
- **JNI Bridge Exports (`jni_bridge.cpp`):**
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyTeethWhitening`
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyTeethReshape`
- **Kotlin External Functions (`MeituNativeEngine.kt`):**
  - `nativeApplyTeethWhitening`, `nativeApplyTeethReshape`.
- **UI Tool Item & Dispatch (`PhotoEditorActivity.kt`):**
  - Category: `✨ Trang Điểm`
  - Tool IDs: `tool_teeth_whiten`, `tool_teeth_align`, `tool_teeth_protrusion`.
  - Dispatch Block: In `PhotoEditorActivity.kt`, lines 2380–2388 dispatch to `nativeApplyTeethWhitening` and `nativeApplyTeethReshape(workingBitmap, spacing, alignment, protrusion)`.
- **Remediation Status:** Remediated in TASK_007: generic liquify pinch completely replaced with dedicated `nativeApplyTeethReshape`.

---

### MODULE 7: EARS
- **Primary C++ Header/Source:**
  - `lib-core-graphics/src/main/cpp/src/teeth_ear_engine.cpp`
- **CMake Compilation Target:** `libmeitu_reborn_native.so`
- **Key C++ Methods:**
  - `TeethEarEngine::applyEarStyle(uint32_t* pixels, int w, int h, int earStyle, float intensity)`
- **JNI Bridge Exports (`jni_bridge.cpp`):**
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyEarStyle`
- **Kotlin External Functions (`MeituNativeEngine.kt`):**
  - `nativeApplyEarStyle`.
- **UI Tool Item & Dispatch (`PhotoEditorActivity.kt`):**
  - Category: `👂 Tai`
  - Tool IDs: `tool_ear_buddha`, `tool_ear_mouse`, `tool_ear_pig`, `tool_ear_elf`, `tool_ear_press`, `tool_ear_protrude`, `tool_ear_thickness`, `tool_ear_rosy`.
  - Dispatch Block: `applyFilterWithTool` in `PhotoEditorActivity.kt`.
- **Verification Status:** All 8 tools executed and passed in physical device suite on SM-A075F and SM-A507FN.

---

### MODULE 8: BEARD / MUSTACHE / GRAY-AWAY
- **Primary C++ Header/Source:**
  - `lib-core-graphics/src/main/cpp/src/beard_dye_engine.cpp`
- **CMake Compilation Target:** `libmeitu_reborn_native.so`
- **Key C++ Methods:**
  - `BeardDyeEngine::applyBeardEdit(...)`
- **JNI Bridge Exports (`jni_bridge.cpp`):**
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyBeardEdit`
- **Kotlin External Functions (`MeituNativeEngine.kt`):**
  - `nativeApplyBeardEdit`.
- **UI Tool Item & Dispatch (`PhotoEditorActivity.kt`):**
  - Category: `🧔 Râu`
  - Tool IDs: `tool_beard_density`, `tool_beard_color`, `tool_beard_mustache`, `tool_beard_goatee`, `tool_beard_full`, `tool_beard_stubble`, `tool_beard_gray_away`.
  - Dispatch Block: `applyFilterWithTool` in `PhotoEditorActivity.kt`.
- **Verification Status:** Fully wired and verified on physical hardware.

---

### MODULE 9: CHEEKS / CHEEKBONE / BLUSH
- **Primary C++ Header/Source:**
  - `lib-core-graphics/src/main/cpp/src/face_reshape_3dmm.cpp`
  - `lib-core-graphics/src/main/cpp/src/skin_makeup_engine.cpp`
- **CMake Compilation Target:** `libmeitu_reborn_native.so`
- **Key C++ Methods:**
  - `FaceReshape3DMMEngine::applyCheekboneEdit(...)`
  - `SkinMakeupEngine::applyBlush(...)`
- **JNI Bridge Exports (`jni_bridge.cpp`):**
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyFaceReshape`
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyBlush`
- **Kotlin External Functions (`MeituNativeEngine.kt`):**
  - `nativeApplyFaceReshape`, `nativeApplyBlush`.
- **UI Tool Item & Dispatch (`PhotoEditorActivity.kt`):**
  - Categories: `👤 Khuôn Mặt` (cheekbone) & `✨ Trang Điểm` (blush).
  - Tool IDs: `tool_cheekbone_reduce`, `tool_cheekbone_lift`, `tool_cheekbone_width`, `tool_blush_matte`, `tool_blush_dewy`, `tool_blush_contour`.
  - Dispatch Block: `applyFilterWithTool` in `PhotoEditorActivity.kt`.
- **Verification Status:** Fully wired and verified on physical hardware.

---

### MODULE 10: SKIN (Smoothing, Whitening, Acne, Pores, Oil, Types)
- **Primary C++ Header/Source:**
  - `lib-core-graphics/src/main/cpp/src/face_retouch_detail.cpp`
- **CMake Compilation Target:** `libmeitu_reborn_native.so`
- **Key C++ Methods:**
  - `FaceRetouchDetail::applySkinSmooth(...)`
  - `FaceRetouchDetail::applySkinWhiten(...)`
  - `FaceRetouchDetail::applySkinTone(...)`
  - `FaceRetouchDetail::applyAcneRemoval(...)`
  - `FaceRetouchDetail::applyPoreMinimizer(...)`
  - `FaceRetouchDetail::applyOilControl(...)`
  - `FaceRetouchDetail::applyTexturePreserve(...)`
  - `FaceRetouchDetail::applyWrinkleRemoval(...)`
- **JNI Bridge Exports (`jni_bridge.cpp`):**
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplySkinSmooth`, `nativeApplySkinWhiten`, `nativeApplySkinTone`, `nativeApplyAcneRemoval`, `nativeApplyAcneManual`, `nativeApplyPoreMinimizer`, `nativeApplyOilControl`, `nativeApplyTexturePreserve`, `nativeApplyWrinkleRemoval`.
- **Kotlin External Functions (`MeituNativeEngine.kt`):**
  - Declared and mapped 1-to-1.
- **UI Tool Item & Dispatch (`PhotoEditorActivity.kt`):**
  - Category: `🌟 Làn Da`
  - Tool IDs: `tool_skin_smooth`, `tool_skin_whiten`, `tool_skin_tone`, `tool_skin_acne_auto`, `tool_skin_acne_manual`, `tool_skin_pore_minimize`, `tool_skin_matte_oil`, `tool_skin_texture_preserve`, `tool_skin_wrinkle_forehead`, `tool_skin_wrinkle_nasolabial`, `tool_skin_wrinkle_neck`.
  - Dispatch Block: `applyFilterWithTool` in `PhotoEditorActivity.kt`.
- **Verification Status:** Fully wired and verified on physical hardware.

---

### MODULE 11: JAW / CHIN / FACE CONTOUR / 3DMM RESHAPE
- **Primary C++ Header/Source:**
  - `lib-core-graphics/src/main/cpp/src/face_reshape_3dmm.cpp`
  - `lib-core-graphics/src/main/cpp/src/head_skull_engine.cpp`
- **CMake Compilation Target:** `libmeitu_reborn_native.so`
- **Key C++ Methods:**
  - `FaceReshape3DMMEngine::applyFaceReshape(...)`
  - `FaceReshape3DMMEngine::fit3DMM(...)`
  - `FaceReshape3DMMEngine::apply3DMMParam(...)`
  - `HeadSkullEngine::applyHeadScale(...)`
- **JNI Bridge Exports (`jni_bridge.cpp`):**
  - `Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyFaceReshape`, `nativeApplyJawEdit`, `nativeApplyChinEdit`, `nativeApplyTempleEdit`, `nativeApplyForeheadEdit`, `nativeFit3DMM`, `nativeApply3DMMParam`, `nativeApplyHeadScale`.
- **Kotlin External Functions (`MeituNativeEngine.kt`):**
  - Declared and mapped 1-to-1.
- **UI Tool Item & Dispatch (`PhotoEditorActivity.kt`):**
  - Category: `👤 Khuôn Mặt`
  - Tool IDs: `tool_face_vline`, `tool_face_mandible`, `tool_face_chin`, `tool_3dmm_chin`, `tool_face_temple`, `tool_face_forehead`, `tool_3dmm_jaw`, `tool_face_narrow`, `tool_face_small`.
  - Dispatch Block: `applyFilterWithTool` in `PhotoEditorActivity.kt`.
- **Verification Status:** Fully wired and verified on physical hardware.

---

### MODULE 12: SHARED FACE PARSING & MASTER CONTROLLERS
- **Primary C++ Header/Source:**
  - `lib-core-graphics/src/main/cpp/src/ncnn_face_engine.cpp`
  - `lib-core-graphics/src/main/cpp/src/landmark_fusion.cpp`
  - `lib-core-graphics/src/main/cpp/src/accessory_occlusion_engine.cpp`
  - `lib-core-graphics/src/main/cpp/src/beauty_parameter_controller.cpp`
  - `lib-core-graphics/src/main/cpp/src/full_human_beauty_controller.cpp`
- **CMake Compilation Target:** `libmeitu_reborn_native.so`
- **Key C++ Methods:**
  - `NcnnFaceEngine::detect106(...)`
  - `NcnnFaceEngine::detect478(...)`
  - `NcnnFaceEngine::segmentFaceBisenet(...)`
  - `AccessoryOcclusionEngine::protectRigidAccessories(...)`
  - `BeautyParameterController::applyBeautyPipeline(...)`
  - `FullHumanBeautyController::applyFullHumanPipeline(...)`
- **JNI Bridge Exports (`jni_bridge.cpp`):**
  - `nativeDetect106Ncnn`, `nativeDetectDenseMesh478`, `nativeParseFace19`, `nativeProtectRigidAccessories`, `nativeApplyMasterBeautyPipeline`, `nativeApplyFullHumanBeauty`.
- **Kotlin External Functions (`MeituNativeEngine.kt`):**
  - Declared and mapped 1-to-1.
- **UI Dispatch Status:**
  - Face parsing, landmarks, and accessory protection execute during image load / preflight in `PhotoEditorActivity.kt`.
  - Master pipeline controllers (`nativeApplyMasterBeautyPipeline`, `nativeApplyFullHumanBeauty`) remain internal orchestrators (UI tools dispatch individually).

---

## 3. SUMMARY OF RESOLVED WIRING REMEDIATIONS (TASK_007)

| Module | Feature / Symbol | Prior Baseline Status (`d7814b5`) | Current Status (`478107a`) | Technical Resolution Evidence |
|---|---|---|---|---|
| **Eyebrows** | `EyeRetouchEngine::applyEyebrowColor` | UNWIRED (0 callers) | **WIRED & VERIFIED** | 5 shades exposed in `PhotoEditorActivity.kt` (`tool_brow_color_black`..`auburn`), dispatching to `nativeApplyEyebrowColor`. |
| **Eyelashes** | `EyelashEngine::applyEyelash` | BYPASSED (called EyebrowLash) | **WIRED & VERIFIED** | Sliders `tool_lash_density/length/curl` dispatch to procedural `nativeApplyEyelash` with 2D texture fallback. |
| **Nose** | `PhiltrumEngine::applyPhiltrumEdit` | BYPASSED (called mouth reshape) | **WIRED & VERIFIED** | Tools `tool_philtrum_high` and `tool_philtrum_depth` wired to `nativeApplyPhiltrumEdit`. |
| **Teeth** | `TeethEarEngine::applyTeethReshape` | BYPASSED (generic liquify pinch) | **WIRED & VERIFIED** | Generic 2D liquify pinch eliminated. Tools `tool_teeth_align` and `tool_teeth_protrusion` call dedicated `nativeApplyTeethReshape`. |
| **Body/Shoulder** | `ClavicleShoulderEngine::applyClavicle` | UNWIRED (0 callers) | **WIRED & VERIFIED** | Tools `tool_body_shoulder` and `tool_clavicle_enhance` wired to `nativeApplyClavicleShoulder`. |
| **Surface Normal** | `SurfaceNormalEngine::applyContour` | UNWIRED (0 callers) | **WIRED & VERIFIED** | Tool `tool_contour_nose` wired to `nativeApplySurfaceNormalContour`. |
