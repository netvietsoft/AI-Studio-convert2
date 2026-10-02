# 04: ARCHITECTURAL GAPS, DUPLICATE PATHS, AND REMEDIATION AUDIT

**Task ID:** TASK_005_FACE_BEAUTY_MODULE_COMPLETENESS_AND_DEVICE_READINESS  
**Audit Standard:** 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD  
**Baseline Git Commit SHA:** `478107aa4274dc26087f63810881a5ba098e95fb`  
**Target Repository:** `netvietsoft/AI-Studio-convert2`  

---

## 1. EXECUTIVE OVERVIEW

Following the remediation cycle (`TASK_006` through `TASK_010`), the CONVERT2 Face & Beauty subsystem has achieved **100% C++ compilation**, **100% JNI/Kotlin export**, **100% UI wiring**, and **100% physical hardware execution** across all 104 features on Samsung Galaxy A07 (`SM-A075F`) and Samsung Galaxy A50s (`SM-A507FN`).

However, deep architectural audit of the current codebase reveals **three remaining architectural gaps and structural characteristics** that must guide future engineering phases:
1. **Divergent Dual-Path Deformations:** Competing 2D localized TPS/MLS morphing vs. 3DMM parametric mesh fitting operate on separate state machines without unified deformation caching.
2. **Truncated Master Beauty Pipeline:** `BeautyParameterController` and `FullHumanBeautyController` execute only a restricted subset (Skull, Ears, Neck/Clavicle, Eyebrow/Lash density, Teeth whitening, Rigid accessories), omitting Eyes, Nose, Lips/Lipstick, Beard, Skin Retouch, and Cheeks/Blush.
3. **Visual QA Quantitative Evaluation Gap (Gate 7):** While 104 features execute without crashes on physical hardware, reference-based 8-dimension quantitative visual quality evaluation remains pending before commercial release.

---

## 2. DETAILED ARCHITECTURAL ANALYSIS

### 2.1. DIVERGENT DUAL-PATH MORPHING: 2D TPS vs. 3DMM
In CONVERT2, facial reshaping exists in two completely separate, non-communicating implementations:
- **Path A (2D Localized Morphing):**
  - Used in Category `👀 Mắt` (`tool_eye_round` through `tool_eye_deep`) and Category `👤 Khuôn Mặt` (`tool_face_vline`, `tool_face_mandible`, etc.).
  - Implemented in `EyeRetouchEngine::applyEyeShape` and `FaceReshapeEngine::applyFaceReshape`.
  - Driven by localized landmark coordinates `(lxEye, lyEye, rxEye, ryEye)` and Thin-Plate Spline (TPS) / Moving Least Squares (MLS) 2D pixel warping.
- **Path B (3D Morphable Model Mesh Fitting):**
  - Used in Category `👤 Khuôn Mặt` -> `3DMM` (`tool_3dmm_mesh_fit`, `tool_3dmm_param_adjust`, `tool_3dmm_chin`, `tool_3dmm_jaw`).
  - Implemented in `FaceReshape3DMMEngine::fit3DMM` and `FaceReshape3DMMEngine::apply3DMMParam`.
  - Reconstructs a 3D facial mesh from 106 landmarks and projects 3D vertices back to 2D screen coordinates.
- **The Architectural Hazard:**
  - If a user first adjusts an eye shape slider via Path A, the bitmap pixels are warped.
  - If the user subsequently adjusts a 3DMM parameter via Path B, `FaceReshape3DMMEngine` evaluates the canonical landmarks on the already distorted bitmap or assumes unmodified canonical landmarks.
  - This can cause non-linear compound distortion, double-warping artifacts, and irreversible pixel blurring.
- **Recommended Architectural Remediation:**
  - Unify the deformation field into a single GPU/CPU Vector Displacement Map (VDM) where 2D and 3DMM deltas are accumulated into a shared displacement texture before a single-pass bicubic sampling resample.

---

### 2.2. AUDIT OF RESOLVED UI WIRING GAPS (REMEDIATED IN TASK_007)

Prior to TASK_007, four significant UI wiring defects existed. All four were empirically remediated and verified:
1. **Teeth Reshape (`TeethEarEngine::applyTeethReshape`):**
   - *Previous Defect:* `tool_teeth_align` and `tool_teeth_protrusion` bypassed `nativeApplyTeethReshape` and executed a generic 2D liquify pinch (`WARP_MODE_PINCH`).
   - *Remediation:* Replaced with direct calls to `MeituNativeEngine.nativeApplyTeethReshape(workingBitmap, spacing, alignment, protrusion)` with normalized parameters in `[-1.0, 1.0]`.
2. **Procedural Eyelashes (`EyelashEngine::applyEyelash`):**
   - *Previous Defect:* `tool_lash_density`, `tool_lash_length`, and `tool_lash_curl` called `nativeApplyEyebrowLash`. Dedicated Bezier procedural engine had 0 callers.
   - *Remediation:* Refactored to dispatch to `MeituNativeEngine.nativeApplyEyelash` for procedural anti-aliased keratin Bezier fibers with safe texture fallback.
3. **Eyebrow Color (`EyeRetouchEngine::applyEyebrowColor`):**
   - *Previous Defect:* Exported in JNI/Kotlin, but had 0 UI callers and no tool item.
   - *Remediation:* Added 5 eyebrow color shades (`tool_brow_color_black`..`auburn`) in Category `✨ Trang Điểm`, routing to `nativeApplyEyebrowColor`.
4. **Philtrum Editing (`PhiltrumEngine::applyPhiltrumEdit`):**
   - *Previous Defect:* `tool_philtrum_high` and `tool_philtrum_warp` routed to mouth reshape. `nativeApplyPhiltrumEdit` had 0 callers.
   - *Remediation:* Connected `tool_philtrum_high` (length) and `tool_philtrum_depth` (groove depth) directly to `nativeApplyPhiltrumEdit`.

---

### 2.3. TRUNCATED MASTER BEAUTY PIPELINE
- Direct inspection of `BeautyParameterController::applyBeautyPipeline` (`beauty_parameter_controller.cpp:40-141`) confirms that the unified batch controller covers only:
  1. `mSkullEngine` (head scale, crown, temple, forehead)
  2. `TeethEarEngine::applyEarStyle` (ear morphology)
  3. `mNeckEngine` (neck length/thickness, clavicle)
  4. `mBrowLashEngine` (eyebrow & eyelash density)
  5. `TeethEarEngine::applyTeethWhitening` (dental brightening)
  6. `AccessoryOcclusionEngine` (glasses, earrings, hats protection)
- **Omitted Subsystems:**
  - Module 1 (Eyes: Iris, Pupil, Sclera, Canthus, Catchlight)
  - Module 4 (Nose: Root, bridge, ala, tip, philtrum)
  - Module 5 (Mouth: Lips, smile, lipstick textures)
  - Module 8 (Beard: Mustache, goatee, full beard, gray-away)
  - Module 9 (Cheeks: Cheekbone, blush)
  - Module 10 (Skin: Smoothing, whitening, acne, pores, oil, wrinkles)
- **Impact on Editor Workflow:**
  - `PhotoEditorActivity` cannot use `nativeApplyMasterBeautyPipeline` for one-tap global preset filters ("Pure Natural", "Studio Portrait", "Golden Ratio"). Instead, the editor must execute each slider change independently, requiring multiple pixel read/write passes over the large working bitmap.

---

### 2.4. HOST JVM VS. TARGET HARDWARE EXECUTION DIVERGENCE
- On development host machines (Windows x86_64), Android NDK binaries compiled for ARM64-v8a (`libmeitu_reborn_native.so`) cannot be loaded or executed directly by the Windows JVM.
- `TASK_009` established the canonical **Dual Metrics** policy:
  - **Host JVM Contract & Metadata Coverage:** 100.0% (104 of 104 features tested via reflection, boundary clamping, and production category audits).
  - **Host JVM Real C++ Native Engine Execution:** 0.0% (Honest: no fake green or stubbed JVM DLLs).
  - **Target Device Real C++ Native Engine Execution (Gate 6):** 100.0% (104 of 104 features executed and verified on connected physical Samsung Galaxy devices).

---

### 2.5. VISUAL QA VERIFICATION GAP (GATE 7)
- While Gate 6 (Physical Device Validation) is 100% complete (zero crashes, sub-4ms kernel latencies on physical Samsung hardware), **Gate 7 (Visual QA)** remains at **0.0%**.
- Pursuant to `YEUCAU_TEST_ANH.TXT` and `ACQ-005`, commercial production readiness requires reference-based 8-dimension quantitative evaluations:
  1. Edit Position ($\ge 90$ & Zero Leakage)
  2. Color Accuracy ($\ge 85$ or N/A)
  3. Shape Accuracy ($\ge 85$ or N/A)
  4. User Intent ($\ge 95$, Primary Standard: "Does the image fulfill user request?")
  5. Original Preservation (Unwanted Change $\le 5$)
  6. Artifact Control (Artifact Score $\le 5$)
  7. Technical Quality ($\ge 85$, micro-pores $\ge 75\%$)
  8. Naturalness ($\ge 85$)
- Conducting this quantitative benchmark suite is the primary technical blocker to declaring `PRODUCTION_READY`.
