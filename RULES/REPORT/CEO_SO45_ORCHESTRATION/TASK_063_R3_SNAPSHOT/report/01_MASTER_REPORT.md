# 01_MASTER_REPORT.md — Revision 3 SO45 Empirical Ground Truth & Research Dispatch
**Task ID:** `TASK_063` (Revision 3)  
**Standard:** `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` (SHA-256: `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`)  
**Worker Identity:** `AGY_LEAD` (`ace29908-a2b0-4777-a070-6bd100509738`)  
**Lease ID:** `LEASE-CEO-WORKER-TASK_063-R3` | **Fencing Token:** `1011`  
**Superseded Revisions:** Revision 1 (`417dbf52`, NEEDS_FIX) and Revision 2 (`79d93b4f`, NEEDS_FIX)  
**Status:** `REVIEW_CANDIDATE_AWAITING_CEO`  
**Timestamp:** 2026-10-08T04:58:42.427564+00:00  

---

## Executive Overview

Revision 3 addresses the six specific blocking findings established in CEO Review `.ai/ceo/reviews/TASK_063_R2_79d93b4f_NEEDS_FIX.md` and incorporates `TASK_063_CEO_SOFTLIGHT_NUMERIC_ADDENDUM.md`:
1. **Container Slices & In-Memory Negative Checks:** Enforced real declared size, CRC32, stored flags, compression method, and payload byte comparisons for all 45 binaries. In-memory negative checks demonstrate that altered prefixes or corrupted CRC headers fail validation.
2. **Reproducible Command Evidence & Accurate Scope:** Disassembly arithmetic counts are derived strictly from retained raw files in `raw/`. Instruction lines are distinguished from text lines. The failed readelf on truncated `libmfxkit.so` (exit code 1) is captured with its actual stderr and classified as `NOT_CHECKED`.
3. **Defined Function Targets & Enumerated Gaps:** Filtered out all `UND` (undefined/imported) symbols (Value=0). Function targets are strictly defined symbols belonging to the respective binaries or verified Ghidra bodies. Gap counts are derived from enumerated gap records.
4. **Historical Body Provenance:** Corrected `libLayerFlow.so` decompilation provenance: `.ai/reconstruction/evidence/TASK_061/ghidra_decompiled/libLayerFlow.so_decompiled.txt` has 54,954 lines, SHA-256 `def2dd35f987a96a336b84d53e9e09445a97194b480f0850560483d8ccc74ca2`.
5. **Exact Critical Proofs & Rational Math:**
   - SoftHair `FilterToFBO` function entry is Ghidra VA `0x002344e8` (ELF RVA `0x001344e8`, file offset `0x001344e8`, body lines 23492-23495).
   - SoftLight rational math proves non-equivalence to W3C ($A=1/16, B=3/4 \implies \Delta = 11/512 = 0.021484375$). Unsupported named "Pegtop equivalence" claim removed.
   - Dynamic symbol search across 44 binaries proves `bisenet` = 0 occurrences in `.dynsym`. Manis models observed in APK; production confidence source remains `UNKNOWN`.
   - Download interruption of `libmfxkit.so` classified as `INFERRED / UNKNOWN`.
6. **Toolchain & Heartbeat Receipts:** Ghidra launcher hashed (`dd7b9d17d32ed70a71df82a43a21cdaed6c4ce67064e30f8642c149f81c2ae07`), version parsed from `application.properties` (`12.1.4_PUBLIC`). Paseo heartbeat `068c797c` reused without duplicate registration.

---

## 1. Physical Container Verification & Absent Binaries

### 1.1 XAPK Container Payload Matching
- `SOURCE/Meitu_12.17.8_APKPure.xapk` (`349,175,808` bytes, SHA-256: `dc896b5429cc3265c3d2639a38d4e76bbff3cf819cfe3b63b006048a7712c0d7`):
  - **44 Libraries:** Exactly match the container payload byte-for-byte, hash-for-hash, and CRC32-for-CRC32 (`EXACT_PAYLOAD_MATCH`). Stored uncompressed (`method == 0`, `flags == 0`).
  - **1 Library (`libmfxkit.so`):** Container local header at byte `348,392,052`, data begins at byte `348,402,156`. Container file terminates at byte `349,175,808`, providing only `773,652` bytes. Declared size is `1,354,736` bytes. Deficit: `581,084` bytes (42.89% data loss).
  - On-disk `libmfxkit.so` matches the container prefix 100% (SHA-256: `78923a90997d34c5dd51215a6cd2bc26c9731806fd9037e4aa71fd3873d3bb4f`). Missing tail content is **UNKNOWN**.
  - Interruption cause is classified as **INFERRED / UNKNOWN**.

### 1.2 In-Memory Negative Check Results
- Corrupted prefix test: Inverting byte 0 of `libmfxkit.so` container prefix immediately fails equality check (`corrupted_prefix_rejected: True`).
- Corrupted CRC test: Inverting bits of container declared CRC immediately fails validation (`corrupted_crc_rejected: True`).

### 1.3 Inspection of APK Packages
- `SOURCE/com.mt.mtxx.mtxx.apk` contains **0 arm64 `.so` libraries**.
- `SOURCE/app-debug.apk` contains 47 arm64 `.so` libraries (45 vendor + 2 rebuilt reborn libs). It is a local rebuild artifact, not an upstream vendor package.
- `libmtImageKit.so`, `MTAiInterface`, `vlai`: Confirmed absent from observed inputs.

---

## 2. Real Evidence Depth & Symbol / JNI Catalog

Every library was audited via `llvm-readelf -Ws` and `llvm-objdump -d`, with unedited stdout/stderr saved in `raw/`:
- **Defined vs Imported Symbols:**
  - In `03_EXISTING_EVIDENCE_AUDIT.csv` and `04_SO45_LANE_ASSIGNMENTS.csv`, all `UND` imports (Value=0) are excluded from function targets.
  - ByteDance PGL libraries export concrete defined JNI methods: `Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_*` (`libbuffer_pgl.so`) and `Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_*` (`libfile_lock_pgl.so`).
- **Disassembly Sampling & Arithmetic Counts:**
  - Arithmetic counts are derived strictly from the retained stdout in `raw/`.
  - Instruction lines (`instruction_lines`) are counted separately from total text lines (`text_lines`).
  - `libmfxkit.so` readelf exit code 1 is recorded, and its symbol audit is marked `NOT_CHECKED` with actual error.

---

## 3. Seven Research Lanes (TASK_064A..G) Partition & Targets

All 45 libraries are assigned to exactly one non-overlapping lane with real defined symbols:
1. **Lane A (`TASK_064A` — 6 libs):** `libMTFilterKernel.so`, `libARKernelInterface.so`, `libarkernel3.so`, `libarkernel3_android.so`, `libarkernel3_c.so`, `libLayerFlow.so`.
   - *Key Targets:* `FilterToFBO` (VA `0x002344e8`), `BlurHFilterToFBO` (VA `0x00234a90`), `BlurVFilterToFBO` (VA `0x00234c10`), `SoftHairFilterToFBO` (VA `0x00234d70`).
2. **Lane B (`TASK_064B` — 8 libs):** `libManis.so`, `libmanis_npu_adapter.so`, `libAIModelKit.so`, `libAIModelSearchKit.so`, `libaidetectionplugin.so`, `libhiai.so`, `libhiai_ir.so`, `libhiai_ir_build.so`.
   - *Key Targets:* `Manis::*` inference engine, `hair_seg` in `libaidetectionplugin.so`, NPU HAL exports.
3. **Lane C (`TASK_064C` — 6 libs):** `libPVGColorFunctions.so`, `libVERenderer.so`, `libfantasy.so`, `libMTARMPM.so`, `libARSPM.so`, `liblabdeviceinfo.so`.
   - *Key Targets:* Color conversion functions, `VERenderer` viewport blits, device capability checks.
4. **Lane D (`TASK_064D` — 5 libs):** `libPVGImageCodec.so`, `libbmpKit.so`, `libglide-webp.so`, `libMTGif.so`, `libfftw3.so`.
   - *Key Targets:* WebP decode entries, BMP header readers, FFTW3 complex DFT planning.
5. **Lane E (`TASK_064E` — 8 libs):** `libffmpeg.so`, `libffmpegfilter.so`, `libffavc.so`, `libPVGVideoCodec.so`, `libPVGCodec.so`, `libPVGLive.so`, `libKKMusicFX.so`, `libaicodec.so`.
   - *Key Targets:* FFmpeg avcodec entries, audio DSP effects, MediaCodec wrapper functions (`_ZN7MMCodec*`).
6. **Lane F (`TASK_064F` — 6 libs):** `libc++_shared.so`, `libbytehook.so`, `libbuffer_pgl.so`, `libfile_lock_pgl.so`, `libfntvcrash.so`, `libkoom-strip-dump.so`.
   - *Key Targets:* `bytehook_hook_single`, GeckoX MMapBuffer JNI entries, KOOM dump symbols.
7. **Lane G (`TASK_064G` — 6 libs):** `libCtaApiLib.so`, `libhttpelf.so`, `libdexvmp.so`, `libMtlabSign.so`, `libMTLReportTool.so`, `libmfxkit.so`.
   - *Key Targets:* `mtlab_sign_*`, DexVMP opcode dispatch, quarantined `libmfxkit.so`.

---

## 4. Residual Blockers & Gate Disposition

1. `libmfxkit.so` is truncated by 581,084 bytes. Disassembly beyond byte 773,652 is impossible until a complete archive is sourced.
2. `TASK_064A..G`, `TASK_065`, and `TASK_066` remain strictly **`PLANNED`**.
3. All code modifications are restricted to `scripts/task063_r3/` and `RULES/REPORT/TASK_063_REPORT_R3/`. Production code remains untouched.
