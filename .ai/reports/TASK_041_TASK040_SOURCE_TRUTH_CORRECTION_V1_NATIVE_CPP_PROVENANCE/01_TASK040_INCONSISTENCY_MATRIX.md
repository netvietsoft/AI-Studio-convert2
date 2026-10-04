# 01. TASK_040 INCONSISTENCY RECONCILIATION MATRIX

This document reconciles all factual and narrative inconsistencies discovered in TASK_040 (`TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY`) against physical evidence and the verified cryptographic baseline of TASK_036.

---

### 1. RECONCILIATION MATRIX

| # | Item / Claim in TASK_040 | TASK_040 Statement | Physical Ground Truth | Severity | Root Cause & Correction |
| :- | :--- | :--- | :--- | :--- | :--- |
| **1** | **`libmeitu_reborn_native.so` in Vendor .so** | Report 08 §2 line 27: claims `extracted_native_libs/lib/arm64-v8a` contains `libmeitu_reborn_native.so`. | **ABSENT**. The file does not exist in `arm64-v8a` or anywhere in `SOURCE`. | **CRITICAL** | `libmeitu_reborn_native.so` is the C++ build target of the Reborn project (`CMakeLists.txt`), not an extracted vendor binary. Claim struck from record. |
| **2** | **`libbisenet.so` in Vendor .so** | Report 08 §2 line 27: claims `extracted_native_libs/lib/arm64-v8a` contains `libbisenet.so`. | **ABSENT**. The file does not exist in `arm64-v8a` or anywhere in `SOURCE`. | **HIGH** | BiSeNet is a neural network model. In the vendor app, face parsing is executed through `libManis.so` (Meitu proprietary neural runtime), not a standalone library named `libbisenet.so`. |
| **3** | **`libncnn.so` in Vendor .so** | Report 08 §2 line 27: claims `extracted_native_libs/lib/arm64-v8a` contains `libncnn.so`. | **ABSENT**. The file does not exist in `arm64-v8a` or anywhere in `SOURCE`. | **HIGH** | Tencent NCNN is a third-party open-source SDK prebuilt in `core/native-bridge/src/main/cpp/ncnn/` for cleanroom re-implementation. It was never a vendor binary. |
| **4** | **`libface_mesh.so` in Vendor .so** | Report 08 §2 line 27: claims `extracted_native_libs/lib/arm64-v8a` contains `libface_mesh.so`. | **ABSENT**. The file does not exist in `arm64-v8a` or anywhere in `SOURCE`. | **HIGH** | Face mesh tracking in the vendor APK is handled by `libarkernel3.so` / `libARKernelInterface.so`, not a standalone library named `libface_mesh.so`. |
| **5** | **V1 Native C++ Tree Classification** | Report 08 §1 line 9: classifies `com.mt.mtxx.mtxx/CONVERT` as `A (ORIGINAL_SOURCE_PROJECT)`. | **PROJECT_RECONSTRUCTED_SOURCE**. Authored by agents in Sep-Oct 2026. | **CRITICAL** | Original Meitu Inc. vendor C++ source code was never available. The V1 C++ tree is project-reconstructed cleanroom code targeting `libmeitu_reborn_native.so`. Classification corrected. |
| **6** | **Downstream Guidance for TASK_038** | Report 08 §2 line 27: suggests using claimed vendor libraries to feed TASK_038. | Must feed TASK_038 only verified vendor binaries and separate them from C++ reconstructions. | **HIGH** | TASK_038 must intake the 5 verified vendor hair libraries (`libMTFilterKernel.so`, `libarkernel3.so`, `libManis.so`, `libLayerFlow.so`, `libPVGColorFunctions.so`) and treat V1 C++ as reference design. |

---

### 2. PHYSICAL VERIFICATION EVIDENCE

A recursive SHA-256 sweep of the entire `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE` directory confirms:
```json
{
  "libmeitu_reborn_native.so": {"in_arm64": false, "in_source_tree": false},
  "libbisenet.so": {"in_arm64": false, "in_source_tree": false},
  "libncnn.so": {"in_arm64": false, "in_source_tree": false},
  "libface_mesh.so": {"in_arm64": false, "in_source_tree": false}
}
```

The 45 vendor `.so` files present in `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a` are 100% identical in SHA-256 to the 45 files analyzed in TASK_036 (`02_SO_HASH_MATCH.csv`). Zero discrepancies exist in the physical binary set.
