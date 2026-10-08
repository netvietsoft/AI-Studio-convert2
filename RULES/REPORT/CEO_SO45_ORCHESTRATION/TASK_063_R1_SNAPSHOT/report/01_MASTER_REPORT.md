# 01_MASTER_REPORT.md — SO45 Input Truth, Forensic Evidence & Research Baseline
**Task ID:** `TASK_063`  
**Assignee:** `AGY_LEAD` (`ace29908-a2b0-4777-a070-6bd100509738`)  
**Standard Reference:** `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` (SHA-256: `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`)  
**Status:** `REVIEW_CANDIDATE_AWAITING_CEO`  
**Date:** 2026-10-08  

---

## Executive Summary

TASK_063 establishes the authoritative, empirical ground truth for all 45 native arm64 `.so` libraries in Meitu v12.17.8. Prior task reports (TASK_059..062) contained valuable initial reconnaissance but suffered from several unverified assumptions: speculative completion percentages, conflation of external P0 heuristics (such as BiSeNet) with native code, and unverified assumptions regarding binary integrity.

This report independently verifies every binary down to the exact byte, program/section header boundaries, and container declared sizes. We provide forensic proof of the truncation of `libmfxkit.so`, verify the absence of phantom binaries, confirm the exact mathematical formulas for mask exclusion, SoftLight blending, and Gaussian blur weights, and dispatch the 45 libraries into 7 non-overlapping research lanes (`TASK_064A..G`).

---

## 1. SO45 Input Truth & Binary Completeness

### 1.1 Physical Inventory vs Container Declaration
- **On Disk Directory:** `F:\\CONVERT\\com.mt.mtxx.mtxx\\SOURCE\\extracted_native_libs\\lib\\arm64-v8a\\`
- **Total arm64 `.so` Files:** Exactly 45 libraries.
- **Reference Container:** `SOURCE/Meitu_12.17.8_APKPure.xapk`
  - Scanning local ZIP headers (`PK\x03\x04`) reveals exactly 45 arm64 `.so` entries under `lib/arm64-v8a/`.
  - Compression method for all 45 entries: `0` (`STORED` / uncompressed).
  - 44 of the 45 libraries match the container uncompressed size down to the exact byte (difference = 0).
  - Exactly 1 library exhibits a catastrophic size mismatch: `libmfxkit.so`.

### 1.2 Forensic Analysis of `libmfxkit.so` Truncation
- **Size on disk:** `773,652` bytes.
- **SHA-256 on disk:** `78923a90997d34c5dd51215a6cd2bc26c9731806fd9037e4aa71fd3873d3bb4f`.
- **Declared size in container:** `1,354,736` bytes (`0x14ABF0`).
- **Declared CRC32 in container:** `0x4302C04C`.
- **Missing Deficit:** Exactly `581,084` bytes missing (42.89% data loss).
- **ELF Structural Failure:**
  1. The ELF section header table begins at offset `e_shoff = 1,352,944` and extends to `1,354,736`. This entire table lies beyond the physical file boundary of `773,652` bytes.
  2. The primary code segment (`PT_LOAD` index 0) specifies `p_filesz = 1,307,184` bytes, which also truncates at EOF.
  3. Root cause: The download of `Meitu_12.17.8_APKPure.xapk` was interrupted at byte `349,175,808` (`libmfxkit.so` local header starts at byte `348,392,052`), preventing the remaining 581 KB of `libmfxkit.so` and the ZIP Central Directory from being written.
- **Action for Lane G (`TASK_064G`):** `libmfxkit.so` must be treated as a truncated artifact. Decompilation of functions beyond offset `773,652` is impossible until a complete binary is sourced.

### 1.3 Verification of Imaginary / Absent Binaries
- `libmtImageKit.so`: **Absent**. Does not exist in the extracted libraries, APK, or XAPK container. Historical mentions were erroneous extrapolations from legacy iOS Meitu frameworks.
- `MTAiInterface`: **Not a Native Binary**. This is an Android Java/Kotlin class interface (`com.meitu.library.arcore.ar.MTAiInterface`).
- `vlai`: **Not a Native Binary**. This is the root directory path for proprietary asset models (`assets/vlaimodel/`).

---

## 2. Audit & Correction of Critical Historical Claims

### 2.1 Mask Exclusion Channel & Output Alpha (Claim 1)
- **Finding:** Verified directly in GLSL shader `ARKernelBuiltin_Shaders_MTFilter_HairMaskMix.fs`.
- **Logic:**
  ```glsl
  float blackvalue = 1.0 - black.r;
  float val = src.r;
  if(black.r > 0.0) {
      if(src.r > blackvalue) val = blackvalue;
  }
  gl_FragColor = vec4(val, val, val, val);
  ```
- **Conclusion:** Both source and exclusion masks are sampled exclusively from the **Red channel**. The output writes the clamped intensity across all RGBA channels, producing a monochrome mask where alpha equals intensity.

### 2.2 SoftLight Color Blending Formula (Claim 2)
- **Finding:** Verified directly in GLSL shader `ARKernelBuiltin_Shaders_HairSoft_MTFilter_PsSoftLightr.fs`.
- **Formula:**
  $$\text{For } B \le 0.5: \quad C = 2AB + A^2(1 - 2B)$$
  $$\text{For } B > 0.5: \quad C = 2A(1 - B) + \sqrt{A}(2B - 1)$$
  $$\text{Output: } \quad \text{mix}(src, res, \alpha)$$
- **Conclusion:** Matches the classic W3C SVG / Photoshop SoftLight blending formula implemented in GPU hardware.

### 2.3 Gaussian Blur Sampling Weights (Claim 3)
- **Finding:** Hardcoded IEEE-754 single-precision float constants discovered in `libMTFilterKernel.so` `.rodata` at offsets `0x8edd8` and `0x8fd3c`:
  - `[0.159676f, 0.263348f, 0.122118f, 0.030573f, 0.004122f]`
- **Callers:**
  1. `MTFilterKernel::MTSoftHairFilter::blurHFilterToFBO` (`0x001f4528`)
  2. `MTFilterKernel::CMTFilterSoftHair::BlurHFilterToFBO` (`0x00234a90`)
- **Conclusion:** Separable 9-tap 1D Gaussian kernel hardcoded for hair mask edge feathering.

### 2.4 Native Pipeline Execution Ordering (Claim 4)
- **Finding:** Discovered in `MTFilterKernel::CMTFilterSoftHair::FilterToFBO` (`0x00234724`):
  1. Parameters `'gain'` (`0x6e696167`) and `'threshold'` (`0x6c6f687365726874`) parsed from string configuration.
  2. Execution sequence:
     - `GrayFilterToFBO` -> `HairMaskFilterToFBO` -> `BlurHFilterToFBO` -> `BlurVFilterToFBO` -> `SoftHairFilterToFBO`
- **Conclusion:** This rigid 5-step pipeline is the native core sequence for Meitu's SoftHair feature.

### 2.5 Segmentation & AI Model Source (Claim 5)
- **Correction:** The claim that Meitu natively runs `BiSeNet` is **historically inaccurate**. The symbol `bisenet` is completely absent from all 45 native binaries. Meitu executes proprietary models (`mtface_parsing*.bin`, `NE.manis`) via its proprietary `libManis.so` neural engine. BiSeNet was an external P0 heuristic adapter (`bisenet_face_parser.py`, `tau_aspect = 1.80`) frozen in P0.

---

## 3. Seven Research Lanes (TASK_064A..G) Dispatch

All 45 libraries are assigned to exactly one non-overlapping lane:

1. **Lane A (`TASK_064A`): Hair & AR Kernel Pipeline (6 Libraries)**
   - `libMTFilterKernel.so`, `libARKernelInterface.so`, `libarkernel3.so`, `libarkernel3_android.so`, `libarkernel3_c.so`, `libLayerFlow.so`
   - *Target:* Full GLSL/SPIR-V shader extraction, `MTSoftHairFilter` C++ bodies, layer compositing math.

2. **Lane B (`TASK_064B`): AI & NPU Segmentation (8 Libraries)**
   - `libManis.so`, `libmanis_npu_adapter.so`, `libAIModelKit.so`, `libAIModelSearchKit.so`, `libaidetectionplugin.so`, `libhiai.so`, `libhiai_ir.so`, `libhiai_ir_build.so`
   - *Target:* Tensor layout recovery, NPU HAL bindings, model decryption routines.

3. **Lane C (`TASK_064C`): Color Science & 3D Shaders (6 Libraries)**
   - `libPVGColorFunctions.so`, `libVERenderer.so`, `libfantasy.so`, `libMTARMPM.so`, `libARSPM.so`, `liblabdeviceinfo.so`
   - *Target:* 3D LUT cubic interpolation, color space matrices, particle kinematics.

4. **Lane D (`TASK_064D`): Image Codecs & Low-Level Math (5 Libraries)**
   - `libPVGImageCodec.so`, `libbmpKit.so`, `libglide-webp.so`, `libMTGif.so`, `libfftw3.so`
   - *Target:* Proprietary PVG image decoding tables, FFTW3 plan bindings.

5. **Lane E (`TASK_064E`): Video Pipeline & Audio Codecs (8 Libraries)**
   - `libffmpeg.so`, `libffmpegfilter.so`, `libffavc.so`, `libPVGVideoCodec.so`, `libPVGCodec.so`, `libPVGLive.so`, `libKKMusicFX.so`, `libaicodec.so`
   - *Target:* Frame synchronization, audio biquad filter DSP math, H.264 slice decoding.

6. **Lane F (`TASK_064F`): Runtime, Hooking & Memory (6 Libraries)**
   - `libc++_shared.so`, `libbytehook.so`, `libbuffer_pgl.so`, `libfile_lock_pgl.so`, `libfntvcrash.so`, `libkoom-strip-dump.so`
   - *Target:* PLT/GOT hook maps, shared memory allocation structures, crash handlers.

7. **Lane G (`TASK_064G`): Security, Signatures & Telemetry (6 Libraries)**
   - `libCtaApiLib.so`, `libhttpelf.so`, `libdexvmp.so`, `libMtlabSign.so`, `libMTLReportTool.so`, `libmfxkit.so`
   - *Target:* HMAC signing algorithms, DexVMP opcode dispatch table, `libmfxkit.so` truncation quarantine.

---

## 4. Residual Blockers & Next Gate Readiness

1. **`libmfxkit.so` Truncation:** This binary cannot be fully disassembled in Lane G. The first 773 KB are readable; the remaining 581 KB are absent. Lane G must document the boundary cleanly.
2. **Planned Tasks Remain Gated:** `TASK_064A..G`, `TASK_065`, and `TASK_066` are strictly `PLANNED`. AGY will not self-activate any lane until the CEO reviews and signs off on TASK_063.
3. **P0 Freeze Preserved:** The P0 pipeline and all production code remain untouched.

---
**Disposition:** Research baseline verified. Ready for CEO gate review.
