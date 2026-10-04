# 01. TASK_040 INCONSISTENCY & EVIDENCE AUDIT MATRIX

## Executive Audit Summary

While **TASK_040** succeeded in its physical enumeration of the entire `F:\CONVERT` root disk hierarchy, its report narrative contained critical evidentiary errors that cannot be accepted into the canonical engineering record. This matrix details each defect, the physical evidence disproving it, and the mandatory correction.

---

## Inconsistency Matrix

| ID | Location | Erroneous Claim in TASK_040 | Physical Reality (Ground Truth) | Root Cause Analysis | Corrective Action & Status |
|---|---|---|---|---|---|
| **INC-01** | `08_HIGH_VALUE_SOURCE_DIRECTORIES.md` (Line 27) | `extracted_native_libs/lib/arm64-v8a`: 45 vendor .so shared libraries including `libmeitu_reborn_native.so`, `libbisenet.so`, `libncnn.so`, `libface_mesh.so`. | None of those 4 libraries exist in `extracted_native_libs/lib/arm64-v8a`. The folder contains exactly 45 vendor libraries (`libAIModelKit.so`, `libLayerFlow.so`, `libManis.so`, `libMTFilterKernel.so`, etc.). | The author conflated project build targets (`meitu_reborn_native`) and conceptual open-source AI frameworks with the actual vendor APK arm64 binaries. | **CORRECTED**: `08_HIGH_VALUE_SOURCE_DIRECTORIES.md` updated to remove hallucinated names and list the authentic 45 SO vendor libraries. |
| **INC-02** | `08_HIGH_VALUE_SOURCE_DIRECTORIES.md` (Line 9) & `00_AUDIT_INDEX.md` | Classified `com.mt.mtxx.mtxx/CONVERT` as `A (ORIGINAL_SOURCE_PROJECT)`. | The C++ code in `apps/android/core/native-bridge/src/main/cpp` is **reconstructed source code** written in September–October 2026. Contains Vietnamese comments, `meitu::reborn` namespaces, and project-specific wrappers. | Vendor APKs do not ship C++ source. All C++ code in `CONVERT` was authored by project engineers/agents during the reconstruction phase. | **CORRECTED**: Classification strictly fixed to `PROJECT_RECONSTRUCTED_SOURCE`. Prohibited from ever being labeled `ORIGINAL_VENDOR_SOURCE`. |
| **INC-03** | `09_RECOMMENDED_ANALYSIS_ORDER.md` (Lines 1012-1014) | Recommended blindly porting `hair_v2_*.cpp` and `jni_bridge.cpp` into CONVERT2 without provenance audit. | `jni_bridge.cpp` binds to `com.meitu.core.nativeengine.MeituNativeEngine`, which is a project-invented facade that never existed in vendor Meitu APK. Blindly porting without checking vendor exports risks building on non-canonical abstractions. | Presumed V1 code was vendor truth rather than earlier project iteration. | **CORRECTED**: Created `08_TASK038_VERIFIED_INTAKE_MANIFEST.md` separating vendor binary truth from project reconstructed code. |
| **INC-04** | Overall TASK_040 Verdict | Declared unconditional **PASS**. | Per Development Workspace Standard V2.1 and Chairman Tony's directives, any report containing unverified vendor library claims must be marked **NEEDS_FIX** until reconciled. | premature signoff prior to forensic cross-check with TASK_036. | **CORRECTED**: TASK_040 verdict adjusted to **NEEDS_FIX (DISCOVERY USEFUL, EVIDENCE CORRECTED BY TASK_041)**. |

---

## Forensic Comparison of Claimed vs Actual Vendor Libraries

```
Claimed by TASK_040 Report 08                Actual Vendor ARM64 SO Status
--------------------------------------       ----------------------------------------------------
libmeitu_reborn_native.so                    ABSENT (Project CMake output target, not vendor binary)
libbisenet.so                                ABSENT (Open-source model; Meitu used Manis/HIAI npu)
libncnn.so                                   ABSENT (Third-party framework; not in Meitu APK)
libface_mesh.so                              ABSENT (Third-party MediaPipe model; not in Meitu APK)
```
