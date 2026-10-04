# 05. V1 NATIVE C++ CANDIDATE GIT & PROVENANCE AUDIT

## 1. Directory Under Audit
`F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp`

## 2. Quantitative Census
- **Total Files**: 303
- **Subdirectories**: `include/`, `src/`, `BeautyCore/` (with `beauty/`, `geometry/`, `landmark/`, `segmentation/`, `tracking/`)
- **File Extensions**:
  - `.cpp`: 119 files
  - `.h` / `.hpp`: 183 files
  - `CMakeLists.txt`: 1 file

## 3. Git Provenance Investigation

A forensic inspection of the Git working tree at `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT` reveals:

```
$ git -C F:\CONVERT\com.mt.mtxx.mtxx\CONVERT status --porcelain
?? apps/android/core/native-bridge/
```

### Critical Findings:
1. **The entire directory `apps/android/core/native-bridge` is UNTRACKED in the V1 Git repository.**
2. The Git history of V1 (`git log -n 5`) shows 5 commits terminating at commit `a411ddb` on 2026-09-24:
   - `a411ddb` feat(prototype,nextai,extension): interactive prototype simulator
   - `96a5e47` [QA][ui-parity] ghi duong vao hub 8 cong cu video
   - `8fb0b6d` [QA][ui-parity] W9 lan 2-3: tab AI Studio
3. The file timestamps in `apps/android/core/native-bridge/src/main/cpp` range from **2026-09-24** to **2026-10-02**:
   - `hair_v2_*.cpp` files were created on **2026-10-02 between 10:21 AM and 11:33 AM**.
   - `jni_bridge.cpp` in V1 was updated on **2026-10-01 at 22:52 PM**.
4. The local execution logs in `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\.ai\tasks\done` document the tasks that created these files:
   - `TASK-HAIR-COLOR-V2-02-TO-V2-07-MULTI-AGENT-EXECUTION-0001.result.yaml` (Executed 2026-10-02)
   - `TASK-SKIN-RETOUCH-BIT-PIXEL-0001.result.yaml`
   - `TASK-CORE-CPP-MATERIAL-AWARE-BODY-0001.result.yaml`

## 4. Linguistic and Code Forensic Evidence
1. **Vietnamese Language Comments**:
   - `hair_v2_pipeline.cpp`: `// 0. Neu enableV2 = false hoac mode = V1, tra ve de caller xu ly theo baseline V1`
   - `hair_v2_pipeline.cpp`: `// Cap phat bo dem nho 64-byte aligned cho SIMD`
   - `hair_v2_pipeline.cpp`: `// 1. Preprocess: Chuyen doi toan bo anh nguon sRGB sang Linear RGB`
   - `hair_v2_pipeline.cpp`: `// 2. V2-02 Alpha Matting`
2. **Project Namespace**:
   - All files declare `namespace meitu::reborn::hair_v2` or `namespace meitu_native`.
   - The string `reborn` is the internal codename of the CONVERT reconstruction project.
3. **No Vendor Provenance**:
   - Original Meitu APK binary libraries (`libLayerFlow.so`, `libarkernel3.so`) are compiled from internal proprietary Meitu C++ repositories developed in China, containing Chinese logging and MT-prefixed symbol tables (`MTFilterKernel`, `LFEffectDenseHairData`).

## 5. Canonical Provenance Ruling
Per Chairman Tony's mandatory standard, the V1 C++ candidate tree is formally classified as:

$$\mathbf{CLASSIFICATION:} \quad \text{PROJECT\_RECONSTRUCTED\_SOURCE}$$

**It is STRICTLY FORBIDDEN to designate this tree as ORIGINAL_VENDOR_SOURCE.**
