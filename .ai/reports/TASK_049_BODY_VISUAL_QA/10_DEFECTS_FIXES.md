# CONVERT2 - Defects & Fixes Audit Log
## Phase: TASK_049_BODY_VISUAL_QA
**Authority:** Tony | **Protocol:** CONVERT2_COMMAND_V2 | **Standard:** 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD

### Summary of Resolved Root Cause Defects
Prior to physical device validation, comprehensive code review and automated run harness testing identified 7 distinct defects across the native C++ engine and Android Kotlin orchestration layer. All 7 defects were rectified, compiled, and verified clean on physical hardware.

---

### Defect 1: Uninitialized Struct Fields in `head_semantic_model.h`
- **Location:** `lib-core-graphics/src/main/cpp/include/head_semantic_model.h`
- **Root Cause:** `Point2DF` and `BoundingBox2D` structures lacked default member initializers (`float x; float y;`), resulting in arbitrary floating-point NaN/infinity values during model construction.
- **Resolution:** Added explicit default initializers:
  ```cpp
  struct Point2DF { float x = 0.0f; float y = 0.0f; };
  struct BoundingBox2D { float x1 = 0.0f, y1 = 0.0f, x2 = 0.0f, y2 = 0.0f; };
  ```

---

### Defect 2: Premature Null Pixel Guard in `head_semantic_model.cpp`
- **Location:** `lib-core-graphics/src/main/cpp/src/head_semantic_model.cpp:30`
- **Root Cause:** `buildHeadSemanticModel` immediately exited with `isValid = false` if `pixels == nullptr`, preventing geometric anatomical modeling when working from landmark vectors alone.
- **Resolution:** Removed the premature null check on line 30, and conditionally guarded only skin tone sampling with `if (pixels != nullptr)`.

---

### Defect 3: Rigid Parsing Validation in `body_semantic_model.h`
- **Location:** `lib-core-graphics/src/main/cpp/include/body_semantic_model.h` & `body_semantic_model.cpp`
- **Root Cause:** `checkToolApplicability` strictly required `frame.parsingValid && frame.parsingConfidence >= 0.40f` for all body tools, blocking UI preflight checks when pose estimation alone was sufficient.
- **Resolution:** Added `bool parsingAttempted{false};` to `HumanFrameResult`. In `checkToolApplicability`, only enforce parsing validity if parsing was actually attempted.

---

### Defect 4: SIGSEGV Crash in `neck_clavicle_engine.cpp`
- **Location:** `lib-core-graphics/src/main/cpp/src/neck_clavicle_engine.cpp`
- **Root Cause:** Native methods (`applyNeckSlimming`, `applyNeckLength`, `applyNeckWrinkleSmoothing`, `applyClavicleEnhancement`, `applyFaceNeckToneMatching`) did not guard against missing head detection and had unconstrained ROI integer conversions, resulting in heap out-of-bounds segmentation faults (SIGSEGV) when tested with intent extras.
- **Resolution:** Hardened every method with:
  ```cpp
  if (!head.isFaceDetected && !head.isValid) return true;
  ```
  Added `std::isnan` checks, and wrapped all ROI coordinates with `std::clamp` against bitmap dimensions `[0, width - 1]` and `[0, height - 1]`.

---

### Defect 5: Null Pixel Pointer Passed in `jni_bridge.cpp`
- **Location:** `lib-core-graphics/src/main/cpp/src/jni_bridge.cpp`
- **Root Cause:** `nativeApplyHeadSkull`, `nativeApplyNeckClavicle`, `nativeApplyEyebrowLash`, and `nativeApplyScalpReconstruction` passed `nullptr` instead of casting `pixelAddr`.
- **Resolution:** Updated all four native JNI wrappers to pass `static_cast<const uint32_t*>(pixelAddr)` so image pixel buffers are correctly mapped.

---

### Defect 6: Missing 15 Body Tools in `PhotoEditorActivity.kt`
- **Location:** `app/src/main/kotlin/com/mt/mtxx/mtxx/editor/PhotoEditorActivity.kt`
- **Root Cause:** `cat_body` category list was missing the 15 specification tools, causing automated intents to be silently ignored.
- **Resolution:** Added all 15 body tools to `cat_body` and added a fallback matcher in `handleIntent` so automated intent testing directly activates the requested tool.

---

### Defect 7: Auto-Save Path Directory Stripping in `PhotoEditorActivity.kt`
- **Location:** `app/src/main/kotlin/com/mt/mtxx/mtxx/editor/PhotoEditorActivity.kt`
- **Root Cause:** When `auto_save_path` was specified as `/sdcard/Download/qa_outputs/name.png`, the activity stripped the directory and wrote to internal storage.
- **Resolution:** Added handling for absolute paths and default relative routing directly to `/sdcard/Download/qa_outputs/`.
