# 08. TASK_038 VERIFIED INTAKE MANIFEST

## Purpose & Scope
This manifest defines the strict, verified intake criteria for **TASK_038** (45 SO Deep Function/XREF/JNI Bridge Reconstruction). It establishes a rigid firewall between **Vendor Binary Evidence** and **Project Reconstructed Source**.

---

## Partition A: Authoritative Vendor Binary Evidence (Ground Truth)
- **Files**: Exactly 45 `.so` shared libraries in `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\`
- **Integrity**: 100% SHA-256 matched with `TASK_036` and `02_VENDOR_SO_RECONCILIATION.csv`.
- **Policy for TASK_038**:
  - Treat all 45 `.so` files as immutable, read-only binary truth.
  - Perform function census, direct JNI export enumeration, and `RegisterNatives` disassembly strictly on these 45 binaries.
  - Do NOT seek `libmeitu_reborn_native.so`, `libbisenet.so`, `libncnn.so`, or `libface_mesh.so`.

### Key Vendor Binaries for Hair & Graphics:
1. `libLayerFlow.so` (5,544,776 bytes) — Contains dense hair effect data and makeup layer pipeline.
2. `libMTFilterKernel.so` (1,858,440 bytes) — Contains core image filter kernels, FBO passes, and face data structures.
3. `libManis.so` (9,928,576 bytes) — Deep neural network inference engine (Meitu's proprietary runtime).
4. `libarkernel3.so` (17,786,488 bytes) & `libARKernelInterface.so` (17,829,224 bytes) — 3D mesh and AR face deformation.
5. `libmfxkit.so` (773,652 bytes) — Imitation makeup and facial feature tracking.

---

## Partition B: Vendor Bytecode Declarations (JNI Interface Ground Truth)
- **Path**: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src\`
- **Policy for TASK_038**:
  - Cross-check vendor JNI exports against actual decompiled Java native method declarations in `sources/com/layer/flow/`, `sources/com/meitu/core/`, `sources/com/meitu/mfxkit/`.
  - Use `RegisterNatives` array recovery from `.so` files to map non-exported native function pointers to Java method names.

---

## Partition C: Project Reconstructed C++ Code (Reference Implementation Only)
- **Paths**:
  - `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\lib-core-graphics\src\main\cpp` (CONVERT2 active)
  - `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp` (V1 candidate)
- **Policy for TASK_038**:
  - **NEVER treat project C++ code as vendor source.**
  - Treat `jni_bridge.cpp` and `MeituNativeEngine.kt` as project-level adapter targets, not vendor reverse-engineering subjects.
  - Use project Hair V2 modules (`hair_v2_*.cpp`) as algorithmic reference for how reconstructed features operate, not as proof of what vendor binaries do.

---

## Firewall Checklist for TASK_038 Execution
- [x] Vendor `.so` count verified: Exactly 45.
- [x] Hallucinated libraries excluded: `libmeitu_reborn_native.so`, `libbisenet.so`, `libncnn.so`, `libface_mesh.so`.
- [x] Provenance tags assigned: `ORIGINAL_VENDOR_BINARY` vs `PROJECT_RECONSTRUCTED_SOURCE`.
- [x] Cross-reference boundary established: Vendor JNI maps to `jadx_src`, Project JNI maps to `CONVERT2`.
