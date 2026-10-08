# 01_MASTER_REPORT.md — Revision 2 Comprehensive SO45 Forensic Report
**Task ID:** `TASK_063` (Revision 2)  
**Worker Identity:** `AGY_LEAD` (`ace29908-a2b0-4777-a070-6bd100509738`)  
**Standard Reference:** `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` (SHA-256: `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`)  
**Status:** `REVIEW_CANDIDATE_AWAITING_CEO`  
**Governing Review:** Addressed all 8 findings of `.ai/ceo/reviews/TASK_063_R1_417dbf52_NEEDS_FIX.md`  

---

## Executive Summary

TASK_063 Revision 2 provides the definitive, empirical research baseline for all 45 native arm64 `.so` libraries of Meitu v12.17.8. In response to CEO Review `TASK_063_R1_417dbf52_NEEDS_FIX.md`, this revision completely eliminates hardcoded assumptions, provides byte-level payload hashing against container records, publishes actual dynamic symbol and JNI catalogs via `llvm-readelf -Ws`, proves mathematical counterexamples for the SoftLight blend formula, documents exact Gaussian blur offset and weight arrays across native and Aurora kernels, and completes an exhaustive 45-binary keyword scan that confirms BiSeNet was an external P0 heuristic rather than a native Meitu component.

---

## 1. SO45 Input Truth & Container Completeness (Finding 1)

### 1.1 Physical Inventory vs Container Payload Verification
- **Target Folder:** `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\` (45 `.so` files).
- **Container Source:** `SOURCE/Meitu_12.17.8_APKPure.xapk` (Total Size: `349,175,808` bytes).
- **Methodology:** Rather than assuming exact matches from filenames or uncompressed sizes, each Local File Header (`PK\x03\x04`) was parsed, bounded payload byte streams were extracted, and payload SHA-256 and CRC32 were computed directly:
  - **44 Libraries:** Exactly match the container payload byte-for-byte and hash-for-hash (`container_match_status = EXACT_PAYLOAD_MATCH`).
  - **1 Library (`libmfxkit.so`):** The container local header begins at byte `348,392,052` (data starts at `348,402,156`), but the container file terminates at byte `349,175,808`. Only `773,652` bytes are physically present in the container before EOF.
  - The extracted on-disk file `libmfxkit.so` (`773,652` bytes) matches the available container prefix 100% (SHA-256: `78923a90997d34c5dd51215a6cd2bc26c9731806fd9037e4aa71fd3873d3bb4f`), but suffers from an unrecovered deficit of **`581,084` bytes** (42.89% missing).
  - The container status is classified as **`PARTIAL_CONTAINER`**. The content of the missing tail remains **UNKNOWN**.

### 1.2 Verification of APK Packages & Absent Binaries
- `SOURCE/com.mt.mtxx.mtxx.apk` (Size: `256,244,763` bytes, 19,157 entries) contains **0 arm64 `.so` libraries**.
- `SOURCE/app-debug.apk` contains 47 arm64 `.so` libraries. Forensic comparison reveals that 45 libraries match the extracted directory, while 2 extra libraries (`libomp.so` and `libmeitu_reborn_native.so`) are locally rebuilt reborn runtime artifacts. It is not an upstream vendor package.
- `libmtImageKit.so`, `MTAiInterface`, `vlai`: Confirmed absent from observed inputs.

---

## 2. Real Evidence Depth & Symbol / JNI Catalog (Finding 2)

- Rather than asserting generic quality scores or completeness percentages, every library was audited via `llvm-readelf -Ws` and `llvm-objdump -d`, with raw logs preserved in `raw/`:
  - Total dynamic symbols and JNI exported functions (`Java_*`, `JNI_OnLoad`, `JNI_OnUnload`) were extracted and cataloged in `03_EXISTING_EVIDENCE_AUDIT.csv`.
  - ByteDance PGL libraries (`libbuffer_pgl.so`, `libfile_lock_pgl.so`) were found to export real JNI methods: `Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_*` and `Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_*`.
  - Disassembly sampling recorded actual arithmetic instructions (`fadd`, `fsub`, `fmul`, `fdiv`, `fmla`, `fmls`, `scvtf`, `fcvtzs`, `madd`, `msub`) and lines sampled. Libraries without sampled arithmetic in the inspection window are labeled `UNSAMPLED_IN_FIRST_N` or `NOT_CHECKED` rather than falsely labeled non-arithmetic.

---

## 3. Seven Research Lanes (TASK_064A..G) Real Target Mapping (Finding 3)

All 45 libraries are assigned to exactly one non-overlapping lane with real observed symbols:
1. **Lane A (`TASK_064A` — 6 libs):** `libMTFilterKernel.so`, `libARKernelInterface.so`, `libarkernel3.so`, `libarkernel3_android.so`, `libarkernel3_c.so`, `libLayerFlow.so`.
   - *Observed Targets:* `MTSoftHairFilter::*`, `CMTFilterSoftHair::*`, `ARKernelInterface_*`, LayerFlow compositor methods.
2. **Lane B (`TASK_064B` — 8 libs):** `libManis.so`, `libmanis_npu_adapter.so`, `libAIModelKit.so`, `libAIModelSearchKit.so`, `libaidetectionplugin.so`, `libhiai.so`, `libhiai_ir.so`, `libhiai_ir_build.so`.
   - *Observed Targets:* `Manis::*`, NPU HAL exports, `hair_seg` exports in `libaidetectionplugin.so`.
3. **Lane C (`TASK_064C` — 6 libs):** `libPVGColorFunctions.so`, `libVERenderer.so`, `libfantasy.so`, `libMTARMPM.so`, `libARSPM.so`, `liblabdeviceinfo.so`.
   - *Observed Targets:* Color conversion functions, `VERenderer` viewport methods, device capability checks.
4. **Lane D (`TASK_064D` — 5 libs):** `libPVGImageCodec.so`, `libbmpKit.so`, `libglide-webp.so`, `libMTGif.so`, `libfftw3.so`.
   - *Observed Targets:* WebP decode entries, BMP header readers, FFTW3 complex DFT planning.
5. **Lane E (`TASK_064E` — 8 libs):** `libffmpeg.so`, `libffmpegfilter.so`, `libffavc.so`, `libPVGVideoCodec.so`, `libPVGCodec.so`, `libPVGLive.so`, `libKKMusicFX.so`, `libaicodec.so`.
   - *Observed Targets:* FFmpeg avcodec entries, audio DSP effects, MediaCodec wrapper functions.
6. **Lane F (`TASK_064F` — 6 libs):** `libc++_shared.so`, `libbytehook.so`, `libbuffer_pgl.so`, `libfile_lock_pgl.so`, `libfntvcrash.so`, `libkoom-strip-dump.so`.
   - *Observed Targets:* `bytehook_hook_single`, GeckoX MMapBuffer JNI entries, KOOM dump symbols.
7. **Lane G (`TASK_064G` — 6 libs):** `libCtaApiLib.so`, `libhttpelf.so`, `libdexvmp.so`, `libMtlabSign.so`, `libMTLReportTool.so`, `libmfxkit.so`.
   - *Observed Targets:* `mtlab_sign_*`, `http_send_*`, DexVMP opcode dispatch, quarantined `libmfxkit.so`.

---

## 4. Rigorous Corrections to Critical Claims (Findings 4–7)

### 4.1 Claim C1: Mask Exclusion & Output Alpha
- Shader `MTFilter_HairMaskMix.fs` was decoded from APK assets using XOR key `7c34b93a`.
- Reads `black.r` and `src.r`, outputs `vec4(val, val, val, val)`. Output alpha equals clamped mask intensity.
- Upstream semantic producer of `textureblack` is **UNKNOWN** at shader level.

### 4.2 Claim C2: SoftLight Mathematical Disproof of W3C Equivalence
- The Meitu shader uses:
  $$C = \begin{cases} 2AB + A^2(1 - 2B) & \text{if } B \le 0.5 \\ 2A(1 - B) + \sqrt{A}(2B - 1) & \text{if } B > 0.5 \end{cases}$$
- For $A = 0.0625$, $B = 0.75$: Meitu shader produces $0.15625$, whereas W3C SoftLight produces $0.134765625$.
- This disproves universal W3C / Photoshop equivalence; it is a simplified Pegtop formula.

### 4.3 Claim C3: Sampling Offsets & Exact Addresses
- In `libMTFilterKernel.so` `.rodata`:
  - `0x8fd28` (VA `0x0018fd28`): H offsets `[0.0, 0.002250, 0.005256, 0.008271, 0.011299]`.
  - `0x8fd3c` (VA `0x0018fd3c`): Blur weights `[0.159676, 0.263348, 0.122118, 0.030573, 0.004122]`.
  - `0x8fd50` (VA `0x0018fd50`): V offsets `[0.0, 0.002994, 0.006993, 0.011005, 0.015034]`.
- Distinct Aurora SPIR-V kernel (`hairmask_blur.fs.spirv`) uses offsets `[0, +/-1.18242502, +/-3.0293119]` and weights `[0.398943007, 0.295962989, 0.00456599984]`. These kernels are documented separately.

### 4.4 Claim C4 & C5: SoftHair Stage Order & AI Truth
- Native SoftHair pipeline executes: `Gray` -> `HairMask` -> `BlurH` -> `BlurV` -> `SoftHair`. Upstream dye-material configuration remains **UNKNOWN**.
- Complete 45-library scan proves `bisenet` = 0 occurrences. Meitu uses proprietary `Manis` models (`mtface_parsing*.bin`, `NE.manis`). Confidence source remains **UNKNOWN**.

---

## 5. Residual Blockers & Gate Disposition

1. `libmfxkit.so` is truncated by 581,084 bytes. Disassembly beyond byte 773,652 is impossible until a complete archive is sourced.
2. `TASK_064A..G`, `TASK_065`, and `TASK_066` remain strictly **`PLANNED`**.
3. All code modifications are restricted to `scripts/task063_r2/` and `RULES/REPORT/TASK_063_REPORT_R2/`. Production code remains untouched.
