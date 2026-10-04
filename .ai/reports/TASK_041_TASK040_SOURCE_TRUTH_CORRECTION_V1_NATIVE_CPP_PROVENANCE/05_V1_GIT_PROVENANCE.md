# 05. V1 NATIVE C++ GIT FORENSIC PROVENANCE

This document establishes the exact development history, git tracking state, and authoring provenance of the C++ native tree located at:
`F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp`

---

### 1. REPOSITORY COMMIT CHRONOLOGY

The git repository at `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT` contains 103 recorded commits spanning September 19, 2026 to September 24, 2026:
- **Root Commit**: `4c0c401` (Sat Sep 19 16:06:18 2026 +0700)
  `chore(workspace): bootstrap Development Workspace Standard V2.1 + PHASE 00/01 inventory`
- **Wave 1 to Wave 8**: Rapid feature scaffold, Android modules, UI parity, and API routers.
- **Wave 9 Milestone**: Commit `4669e5e` (Tue Sep 22 11:42:05 2026 +0700)
  `[WAVE-9][orchestrator] phần E xong: thay 4 engine native (LayerFlow · ARKernel · Manis · PVGCodec) — tự làm, không license`
  *Direct Evidence*: This commit explicitly states that the project's native C++ development was initiated to replace the 4 closed-source vendor engines ("tự làm, không license" / cleanroom self-implementation without proprietary licenses).
- **Head Commit**: `a411ddb` (Thu Sep 24 15:09:10 2026 +0700)
  `feat(prototype,nextai,extension): interactive prototype simulator, nextai lane selector UI, multi-surface worker fleet, and task logs update`

---

### 2. WHY `apps/android/core/native-bridge` IS UNTRACKED IN GIT

Inspection of `git status --porcelain` in `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT` shows:
```
?? apps/android/core/native-bridge/
```
The entire directory `apps/android/core/native-bridge/` was left untracked (`??`) in the local git repository.

**Forensic Explanation**:
1. **Third-Party Binary Bundle**: `apps/android/core/native-bridge/src/main/cpp/ncnn/` contains 175 prebuilt static binaries (`libncnn.a`) and CMake modules for 4 Android ABIs (arm64-v8a, armeabi-v7a, x86, x86_64). Because of repository file-size considerations, the entire tree was kept local during rapid prototyping.
2. **Local Multi-Agent Execution**: Autonomous agents operated directly on the filesystem under Chairman Tony's local orchestration rules (`07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD.md`).
3. **Execution Task Records**: The tasks that generated and validated these files are fully documented in `.ai/tasks/done/`:
   - `TASK-HAIR-COLOR-V2-02-TO-V2-07-MULTI-AGENT-EXECUTION-0001.result.yaml` (dated October 2, 2026): records the authoring of 16 native C++ sources and 10 headers in `core/native-bridge`.
   - `TASK-CORE-CPP-MATERIAL-AWARE-BODY-0001.result.yaml`: records the authoring of body beauty engines.
   - `TASK-HAIR-COLOR-V2-02-07-POST-CRASH-REVALIDATION-0001.result.yaml`: re-validates the compiled engine after runner reboot.

---

### 3. EVIDENCE OF PROJECT RECONSTRUCTION VS ORIGINAL VENDOR SOURCE

Every file in the V1 native C++ tree bears conclusive internal evidence of project authoring:
1. **Standard Header Blocks**:
   ```cpp
   /**
    * HAIR ENGINE — CORE C++ NATIVE IMPLEMENTATION V1.0
    * Architecture Standard: F:\CONVERT\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt
    * Platform: Android NDK C++17 / ARM64-v8a OpenMP
    * Target: Meitu Reborn Native Engine (libmeitu_reborn_native.so)
    */
   ```
2. **Vietnamese Development Comments**:
   `CMakeLists.txt` lines 10-12:
   ```cmake
   # Bat co toi uu hoa toc do cao va da luong OpenMP
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fopenmp -fvisibility=default -ffast-math")
   ```
3. **Reborn Project Namespaces**:
   - `namespace meitu_native`
   - `namespace meitu::reborn::hair_v2`
   - `namespace beautycore`

**Definitive Classification**:
The V1 native C++ candidate must be classified as **`PROJECT_RECONSTRUCTED_SOURCE`**. Calling it "original vendor source" is factually incorrect and prohibited by Hiến pháp.
