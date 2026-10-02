# Phase P0-C Correction 02 — Deterministic Rollback Procedure Specification
**Document Version:** 1.0.0  
**Phase:** P0-C Correction 02  
**Timestamp:** 2026-10-02T09:48:00+07:00  
**Author:** Agent 0 (CEO / Orchestrator)  
**Status:** APPROVED & BINDING  

---

## 1. Executive Summary & Objective
This procedure specifies the canonical, deterministic rollback protocols for the Phase P0-C Classical Hair Matting integration. It addresses and resolves **Issue A (C4-FINAL)** by providing an immutable, two-level recovery model operating exclusively on the actual P0-C production file set, accompanied by rigorous safety constraints preventing repository corruption or destructive operations on `master`.

---

## 2. Two-Level Rollback Architecture

### Level 1: Runtime Feature Flag Fallback (Operational Bypass)
- **Mechanism:** In-process toggle via `HairMattingEngine::setP0B2REnabled(false)` / `MeituNativeEngine.setP0B2REnabled(false)`.
- **Latency:** Instantaneous ($< 1$ ms), executed at runtime without process restart or APK redeployment.
- **Behavior:**
  - Bypasses the 12-stage P0-B.2R native matting pipeline (`processMatting(...)`).
  - Routes execution directly to the documented legacy fallback matting path (`processLegacyMatting(...)`).
  - Generates valid, continuous alpha buffers preserving system stability.
  - Zero state corruption; flag can be toggled dynamically back to `true`.
- **Scope of Claim:** Runtime fallback toggle completed without process restart in the documented test environment.

### Level 2: Physical Source Rollback & Restoration (Source-Level Reversion)
- **Mechanism:** Deterministic Git-based source tree restoration and file removal semantics.
- **Target File Set:** Exactly the 7 production files comprising the P0-C Classical Hair Matting engine.
- **Safety Policy:**
  - MUST NOT execute destructive commands (`git reset --hard`, `git clean -fdx`) on `master`.
  - MUST NOT use ambiguous references (`HEAD` or `HEAD~1`) which conflate working tree state with commits.
  - MUST execute within an isolated worktree or sandboxed test environment.
  - MUST verify cryptographic SHA-256 hashes across all 3 lifecycle states (State A, State B, State C).

---

## 3. Canonical Rollback File Set & Git Semantics

The 7 production files governing P0-C are classified into two deterministic categories based on their presence in baseline commit `PRE_P0C_SHA = 0cf048740c65b678c0a7e562df28338493a41567`:

| # | Relative File Path | Tracking at PRE_P0C_SHA | Rollback Action | Target State at Rollback | Target State at Restoration |
| :-: | :--- | :---: | :--- | :--- | :--- |
| 1 | `lib-core-graphics/src/main/cpp/CMakeLists.txt` | Tracked (`8353793...`) | `git restore --source=0cf048740c65b678c0a7e562df28338493a41567 -- lib-core-graphics/src/main/cpp/CMakeLists.txt` | Pre-P0C Content (`5185508...`) | Integrated Content (`7331c18...`) |
| 2 | `lib-core-graphics/src/main/cpp/include/hair_matting_engine.h` | Untracked (New) | Remove / Archive file | Absent / Removed | Integrated Header (`66d9f9f...`) |
| 3 | `lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp` | Untracked (New) | Remove / Archive file | Absent / Removed | Integrated Source (`c2d2e49...`) |
| 4 | `lib-core-graphics/src/main/cpp/include/ai/bisenet_face_parser.h` | Untracked (New) | Remove / Archive file | Absent / Removed | Integrated Header (`14a9afa...`) |
| 5 | `lib-core-graphics/src/main/cpp/src/ai/bisenet_face_parser.cpp` | Untracked (New) | Remove / Archive file | Absent / Removed | Integrated Source (`65f1fa7...`) |
| 6 | `lib-core-graphics/src/main/cpp/src/jni_bridge.cpp` | Untracked (New) | Remove / Archive file | Absent / Removed | Integrated Source (`e10d1b4...`) |
| 7 | `lib-core-graphics/src/main/kotlin/com/meitu/core/nativeengine/MeituNativeEngine.kt` | Untracked (New) | Remove / Archive file | Absent / Removed | Integrated Kotlin (`ce40d08...`) |

---

## 4. Step-by-Step Execution Protocol

### Step 1: Pre-Execution State A Audit (Current Integrated State)
1. Verify working tree integrity and record SHA-256 hashes of all 7 production files.
2. Confirm that all 7 hashes strictly match the Correction 01 frozen baseline.
3. Validate compilation of current integrated state:
   ```bash
   ./gradlew :lib-core-graphics:assembleDebug :app:assembleDebug --no-daemon
   ```

### Step 2: Transition to State B (Rollback State)
1. Archive current P0-C production files to an isolated backup directory (`scratch/p0_c_integration/P0_C_CORRECTION_02/archive_state_a/`).
2. Restore pre-P0C configuration for tracked files:
   ```bash
   git restore --source=0cf048740c65b678c0a7e562df28338493a41567 -- lib-core-graphics/src/main/cpp/CMakeLists.txt
   ```
3. Remove the 6 newly added P0-C files from the active source tree to restore exact pre-P0C structure.
4. Verify State B:
   - `CMakeLists.txt` hash equals `5185508769da73ab35523f8bfa41fc446b448036d69e7f92fcec9ce3453c57da`.
   - The 6 new files do not exist in the active compilation paths.
5. Execute clean build of rollback baseline to verify zero link/compile breakage:
   ```bash
   ./gradlew :lib-core-graphics:assembleDebug --no-daemon
   ```

### Step 3: Transition to State C (Restored Integrated State)
1. Restore the 6 P0-C production files from the isolated State A archive.
2. Restore the P0-C integrated `CMakeLists.txt` from the State A archive.
3. Cryptographically re-verify that every file SHA-256 matches the Correction 01 frozen hashes to the bit:
   ```bash
   sha256sum lib-core-graphics/src/main/cpp/CMakeLists.txt \
             lib-core-graphics/src/main/cpp/include/hair_matting_engine.h \
             lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp \
             lib-core-graphics/src/main/cpp/include/ai/bisenet_face_parser.h \
             lib-core-graphics/src/main/cpp/src/ai/bisenet_face_parser.cpp \
             lib-core-graphics/src/main/cpp/src/jni_bridge.cpp \
             lib-core-graphics/src/main/kotlin/com/meitu/core/nativeengine/MeituNativeEngine.kt
   ```
4. Execute clean rebuild of the restored integrated state:
   ```bash
   ./gradlew :lib-core-graphics:assembleDebug :app:assembleDebug --no-daemon
   ```
5. Confirm zero residual diff and 100% operational restoration.

---

## 5. Verification Gate & Sign-off Criteria
A rollback verification passes if and only if:
1. State B hashes match `PRE_P0C_SHA` exactly (100% bit-for-bit).
2. State B build completes with zero errors (`BUILD SUCCESSFUL`).
3. State C hashes match Current Integrated State exactly (100% bit-for-bit).
4. State C build completes with zero errors (`BUILD SUCCESSFUL`).
5. Zero side-effects or untracked debris left in the repository.
