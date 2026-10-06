# 00_AUDIT_INDEX — TASK_061 AUDIT MANIFEST & EVIDENCE PROVENANCE

**Task ID:** `TASK_061_MEITU_HAIR_COLOR_ALGORITHM_RECOVERY_SO_L5_ACTIVE`  
**Assignee:** CEO Agent 0 (Antigravity)  
**Authority:** Chairman Tony / Directive 2026-10-06 13:38  
**Mode:** RESEARCH + DIAGNOSTIC (Clean-room clean spec; ZERO production code modification)  
**Report Destination:** `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\RULES\REPORT\TASK_061_REPORT`  
**Status:** `TECHNICAL_RESEARCH_COMPLETE_AWAITING_CEO_AUDIT`

---

## 1. MANDATORY CONSTITUTIONAL STANDARD VERIFICATION

Per Project Hiến Pháp (`AGENTS.md`, `GEMINI.md`) and TASK_061 Section 0:
- **Canonical Standard Document:**  
  `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt`
- **Expected SHA-256:** `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`
- **Measured SHA-256:** `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`
- **Byte Size:** `118,621` bytes
- **Verification Status:** **100% MATCH — PASS**

### Related Constitutional & Audit Context Reviewed:
1. `AGENTS.md` (Constitutional standards, Phase 0 Frozen rules, Gated Integration).
2. `GEMINI.md` (Native C++ core, zero-leakage, bit-pixel accuracy, 8-criteria image testing requirements).
3. `PROJECT_ERROR.md`:
   - `[ERR-010]`: Retraction of fabricated competitor model names in TASK_046.
   - `[ERR-013]`: Decommissioning of failing GitHub Actions runner loop.
   - `[ERR-014]`: Fabricated synthetic shader evidence in TASK_059 & hardcoded coordinate fallback in BiSeNet parser.
4. `ACQUIREMENTS.md` (ACQ-007 SoftHair recipe, ACQ-008 shared engine, ACQ-009 Hair V4 Blocked).
5. `CONVERSION/AGY_011.md` & `CONVERSION/AGY_012.md` (CEO Forensic Audit of SO decompilation & Salon % reality).
6. Prior Research Inputs:
   - `RULES/REPORT/REQ_AGY004_COMPETITOR_HAIR/REQ_B_native_assets_hair.md`
   - `RULES/REPORT/REQ_AGY004_COMPETITOR_HAIR/REQ_C_crossapp_and_current_diag.md`

---

## 2. TOOLCHAIN INVENTORY & DEPENDENCY COMPLIANCE (Policy §17)

All tools utilized for static disassembly, decompilation, and bytecode recovery are verified open-source/NDK components installed outside the source tree:

| Tool | Version / Build | License | Location / Installation Path | Installer SHA-256 |
|---|---|---|---|---|
| **Ghidra** | 12.1.4_build (PUBLIC 20260921) | Apache-2.0 | `F:\TOOLS\ghidra_12.1.4_PUBLIC` | `ddac49f903da9d5bac833e5cc79395098b9c33cfd3279be5f31bd00387d2d4db` |
| **OpenJDK** | 21.0.12.1+1 LTS (Temurin Hotspot) | GPLv2 + CE | `F:\TOOLS\jdk-21.0.12.1+1` | `f9d6e191ab098c0d416e7d588a24420a8621cd2f4720dab2459b8b7b2d2d8b4e` |
| **llvm-objdump** | Android NDK r28 (28.2.13676358) LLVM 19.0.0 | Apache-2.0 w/ LLVM Exception | `C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\28.2.13676358\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-objdump.exe` | Verified NDK binary |
| **llvm-nm** | Android NDK r28 (28.2.13676358) | Apache-2.0 | `...\bin\llvm-nm.exe` | Verified NDK binary |
| **llvm-readelf** | Android NDK r28 (28.2.13676358) | Apache-2.0 | `...\bin\llvm-readelf.exe` | Verified NDK binary |
| **spirv-dis** | Khronos SPIRV-Tools v2024.3 (NDK r28 shader-tools) | Apache-2.0 | `...\shader-tools\windows-x86_64\spirv-dis.exe` | Verified NDK binary |
| **Capstone** | 5.0.9 (Python 3.14 x64) | BSD-3-Clause | System Python Package | Verified pip |
| **Pyelftools** | 0.33 (Python 3.14 x64) | Public Domain | System Python Package | Verified pip |
| **OpenCV** | 5.0.0.93 (Python 3.14 x64) | Apache-2.0 | System Python Package | Verified pip |
| **NumPy** | 2.5.1 (Python 3.14 x64) | BSD-3-Clause | System Python Package | Verified pip |

---

## 3. PHYSICAL INPUT EVIDENCE MANIFEST

Every binary, shader asset, and test image analyzed in this report exists physically on disk with verified byte counts and cryptographic hashes:

| Input Artifact | Relative Path | Byte Size | SHA-256 Hash |
|---|---|---|---|
| **Meitu Binary (T4)** | `SOURCE/extracted_native_libs/lib/arm64-v8a/libMTFilterKernel.so` | 1,858,440 B | `f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4` |
| **Meitu Binary (T5)** | `SOURCE/extracted_native_libs/lib/arm64-v8a/libLayerFlow.so` | 5,544,776 B | `ef8d1581038778b72abca3ca8fd5046e49fd44e0465871b023647fe42a582262` |
| **Meitu Binary (T2)** | `SOURCE/extracted_native_libs/lib/arm64-v8a/libARKernelInterface.so` | 17,829,224 B | `594c5085475d8bb58baacb20293aec805211aa5ccc53b3542f3149196d354953` |
| **Meitu Binary (T3)** | `SOURCE/extracted_native_libs/lib/arm64-v8a/libarkernel3.so` | 17,786,488 B | `e08c1d494eef98759aa92594ca26420e097df51965a4407cc639a97bbaf35442` |
| **Asset Shader (T6)** | `SOURCE/extracted_assets/assets/ARKernelBuiltin/Shaders/MTFilter_HairMaskMix.fs` | 559 B | `bd7cf000fd26fea40b623da5d3763405d62b0e75225496abfe912da35c6ee8aa` |
| **Asset Shader (T6)** | `SOURCE/extracted_assets/assets/ARKernel3Builtin/Shaders/HairSoft/MTFilter_PsSoftLightr.fs` | 863 B | `e5b2c2ea4a28f954d1798b0456319eee6d2c593eb088ab092717830b2eaafb15` |
| **Asset Shader (T6)** | `SOURCE/extracted_assets/assets/ARKernel3Builtin/Shaders/HairSoft/MTFilter_HairSoftMix.fs` | 1,988 B | `e021945fa2e59487a92b5809cf1c97278ca48c9a5b6ab3858aa6e56c795fe276` |
| **Asset Shader (T6)** | `SOURCE/extracted_assets/assets/ARKernel3Builtin/Shaders/HairSoft/MTFilter_gradient.fs` | 1,143 B | `11d73a7267ebca227361a684b067f5cf990e663a0ef68f029bfa8fb6f59dfbd0` |
| **Asset Shader (T6)** | `SOURCE/extracted_assets/assets/ARKernel3Builtin/Shaders/HairSoft/MTFilter_Mix.fs` | 547 B | `9be11ef5b84ae79d67eb16c87e85c2c77f0a6d1a938c11e74a87a7187c3905cf` |
| **Aurora SPIR-V (T7)**| `SOURCE/extracted_assets/assets/MTAurora.bundle/Shaders/hairmask_blur.fs.spirv` | 1,488 B | `b9366e16d85b29a2f72bfe360ad8cf7a44a2fd451692fc1298e5e6447af6a86e` |
| **Aurora SPIR-V (T7)**| `SOURCE/extracted_assets/assets/MTAurora.bundle/Shaders/hairmask_dialtion.fs.spirv` | 1,724 B | `3c81e7d0f391fe78479e0ea34e12c1b82e3c0f4f9f21226b9a8cfef779fa7590` |
| **Aurora SPIR-V (T7)**| `SOURCE/extracted_assets/assets/MTAurora.bundle/Shaders/hairmask_erode.fs.spirv` | 1,724 B | `25bc418a0ca4bf833116d4fead8ee5e839e931ca8ceca13b86027fe0f823a072` |
| **Aurora SPIR-V (T7)**| `SOURCE/extracted_assets/assets/MTAurora.bundle/Shaders/hairmatte.fs.spirv` | 5,180 B | `357dbb9e271e978310dc7d5ae0e3146f565fad544d052a45c1cb55b3f5034456` |
| **Test Image (Owner A)**| `test_assets/task_035/owner_fail_A_curly.png` | 1,867,780 B | `ba84225bcc3c5f20f78cbad3e8192dcdf5dc26a0d30e7bc5af5a6f5aab296fe2` |
| **Test Image (Owner B)**| `test_assets/task_035/owner_fail_B_orig.png` | 595,900 B | `0776ca0bc1382c87955f368b73c6dc4bef7bd7efe74738f2eded58ffe6838625` |

---

## 4. PHASE 0 INPUT INTEGRITY STATUS
- **Target Folder Checked:** `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\input_full\`
- **Status:** **NOT PRESENT** (`PHASE0_BLOCKED_INPUT`).
- **Target T1 (`libmtImageKit.so`):** Strictly marked **BLOCKED**. Zero synthetic symbols or placeholder functions were invented for `libmtImageKit.so`. All analysis proceeds on available targets T2 through T7 per task specification Section 2.2.
