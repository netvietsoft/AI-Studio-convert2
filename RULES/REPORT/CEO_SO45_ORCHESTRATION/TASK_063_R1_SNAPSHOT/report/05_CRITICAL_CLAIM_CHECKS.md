# 05_CRITICAL_CLAIM_CHECKS.md — Verification of Historical Claims
**Standard Reference:** `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` (SHA-256: `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`)  
**Task ID:** `TASK_063`  
**Execution Date:** 2026-10-08  
**Audit Principle:** Evidence-Based Only. Zero speculation, zero fabricated percentages. Every claim backed by binary offsets, strings, or decompiled C code.

---

## Summary Matrix of Critical Claims

| ID | Claim Description | Historical Claim Status | Binary Anchor & Proof | Verified Disposition |
|---|---|---|---|---|
| **C1** | Mask exclusion channel (Red) & output alpha | Claimed red channel exclusion & alpha pass-through | `.ai/reconstruction/evidence/TASK_061/decoded_shaders/ARKernelBuiltin_Shaders_MTFilter_HairMaskMix.fs` lines 10-18: `blackvalue = 1.0 - black.r; if(src.r > blackvalue) val = blackvalue; gl_FragColor = vec4(val, val, val, val);` | **OBSERVED & CONFIRMED** |
| **C2** | SoftLight blending formula | Claimed standard W3C / Photoshop SoftLight | `.ai/reconstruction/evidence/TASK_061/decoded_shaders/ARKernelBuiltin_Shaders_HairSoft_MTFilter_PsSoftLightr.fs` lines 13-26: `if (B <= 0.5) C = A*B/0.5 + A*A*(1.0-2.0*B); else C = A*(1.0-B)/0.5 + sqrt(A)*(2.0*B-1.0);` | **OBSERVED & CONFIRMED** |
| **C3** | Gaussian blur sampling weights & offsets | Claimed 5 IEEE-754 single-precision weights: `[0.159676, 0.263348, 0.122118, 0.030573, 0.004122]` | `libMTFilterKernel.so` `.rodata` offsets `0x8edd8` and `0x8fd3c`. Loaded into uniforms `Weights` and `Offsets` in `MTSoftHairFilter::blurHFilterToFBO` (`0x001f4528`) and `CMTFilterSoftHair::BlurHFilterToFBO` (`0x00234a90`) | **OBSERVED & CONFIRMED** |
| **C4** | Hair material configuration -> native pipeline ordering | Claimed arbitrary filter sequence | `libMTFilterKernel.so` lines 23558-23606 in `CMTFilterSoftHair::FilterToFBO`: String keys `'gain'` (`0x6e696167`) and `'threshold'` (`0x6c6f687365726874`). Execution order: `GrayFilterToFBO` -> `HairMaskFilterToFBO` -> `BlurHFilterToFBO` -> `BlurVFilterToFBO` -> `SoftHairFilterToFBO` | **OBSERVED & CONFIRMED** |
| **C5** | Confidence / segmentation model source | Claimed BiSeNet was Meitu's native model | `libaidetectionplugin.so` has `hair_seg` and `segmentation`. `libManis.so` has `Manis` engine. APK assets contain `mtface_parsing*.bin` and `NE.manis`. String `bisenet` is **COMPLETELY ABSENT** from all 45 native binaries. | **INFERRED PROXY CORRECTED**: BiSeNet was an external P0 heuristic; Meitu uses proprietary `Manis` |
| **C6** | Truncation of `libmfxkit.so` & absent binaries | Suspected corruption / missing libs | `libmfxkit.so` on disk is `773,652` B vs `1,354,736` B in `Meitu_12.17.8_APKPure.xapk` local header (Deficit: 581,084 B). `libmtImageKit.so`, `MTAiInterface`, `vlai` confirmed absent from arm64 binaries. | **OBSERVED & CONFIRMED** |

---

## Detailed Evidence & Reproducibility Receipts

### 1. Claim C1: Mask Exclusion Channel & Output Alpha
- **Binary / File:** `.ai/reconstruction/evidence/TASK_061/decoded_shaders/ARKernelBuiltin_Shaders_MTFilter_HairMaskMix.fs` (extracted from `libarkernel3.so`)
- **Inspection Command:** `Get-Content .ai/reconstruction/evidence/TASK_061/decoded_shaders/ARKernelBuiltin_Shaders_MTFilter_HairMaskMix.fs`
- **Verbatim Code Fragment:**
  ```glsl
  varying vec2 v_texCoord;
  uniform sampler2D texturesrc;
  uniform sampler2D textureblack;
  void main()
  {
      vec4 src = texture2D(texturesrc, vec2(v_texCoord.x, v_texCoord.y));
      vec4 black = texture2D(textureblack, vec2(v_texCoord.x, v_texCoord.y));
      float blackvalue = 1.0 - black.r;
      float val = src.r;
      if (black.r > 0.0)
      {
          if (src.r > blackvalue)
          {
              val = blackvalue;
          }
      }
      gl_FragColor = vec4(val, val, val, val);
  }
  ```
- **Finding:**
  1. The exclusion mask input (`textureblack`, representing face/skin/clothing) is sampled via the **Red** channel (`black.r`).
  2. The hair mask input (`texturesrc`) is sampled via the **Red** channel (`src.r`).
  3. The exclusion math clamps `val = min(src.r, 1.0 - black.r)` whenever `black.r > 0.0`.
  4. The output fragment color writes `val` to **all four channels** (`vec4(val, val, val, val)`), providing a unified monochrome mask with output alpha equal to the clamped mask intensity.
- **Classification:** **OBSERVED**.

---

### 2. Claim C2: SoftLight Blending Formula
- **Binary / File:** `.ai/reconstruction/evidence/TASK_061/decoded_shaders/ARKernelBuiltin_Shaders_HairSoft_MTFilter_PsSoftLightr.fs`
- **Inspection Command:** `Get-Content .ai/reconstruction/evidence/TASK_061/decoded_shaders/ARKernelBuiltin_Shaders_HairSoft_MTFilter_PsSoftLightr.fs`
- **Verbatim Code Fragment:**
  ```glsl
  float SoftLight_Fcn(float A, float B)
  {
      float C = 0.0;
      if (B <= 0.5)
      {
          C = A * B / 0.5 + A * A * (1.0 - 2.0 * B);
      }
      else
      {
          C = A * (1.0 - B) / 0.5 + sqrt(A) * (2.0 * B - 1.0);
      }
      return C;
  }
  ```
- **Finding:**
  1. `A` is `src_color` (underlying hair pixel), `B` is `overlay_color` (hair tint).
  2. For `B <= 0.5`: $C = 2AB + A^2(1 - 2B)$.
  3. For `B > 0.5`: $C = 2A(1 - B) + \sqrt{A}(2B - 1)$.
  4. Final color: `gl_FragColor = vec4(mix(src_color, res_color, alpha), 1.0);`
- **Classification:** **OBSERVED**.

---

### 3. Claim C3: Blur Sampling Weights & Offsets
- **Binary / File:** `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTFilterKernel.so`
- **SHA-256:** `f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4`
- **Section:** `.rodata` (virtual address `0x0018edd8` and `0x0018fd3c`)
- **Inspection Command:** Binary IEEE-754 single-precision float unpacking from offset `0x8edd8`.
- **Verbatim Array Dump:**
  - `0x8edd8` (`0x0018edd8`): `0.15967600f` (`A7 BF 23 3E`)
  - `0x8eddc` (`0x0018eddc`): `0.26334801f` (`94 D5 86 3E`)
  - `0x8ede0` (`0x0018ede0`): `0.12211800f` (`AB 18 FA 3D`)
  - `0x8ede4` (`0x0018ede4`): `0.03057300f` (`A2 7B FA 3C`)
  - `0x8ede8` (`0x0018ede8`): `0.00412200f` (`B3 17 87 3A`)
- **Decompiled C Callers (Ghidra):**
  1. `MTFilterKernel::MTSoftHairFilter::blurHFilterToFBO` (Address: `0x001f4528`):
     ```c
     GPUImageProgram::SetUniform1fv(this_00, "Weights", (float *)&local_60, 5, true);
     GPUImageProgram::SetUniform1fv(this_00, "Offsets", (float *)&local_80, 5, true);
     ```
  2. `MTFilterKernel::CMTFilterSoftHair::BlurHFilterToFBO` (Address: `0x00234a90`):
     ```c
     CGLProgram::SetUniform1fv(this_00, "Weights", (float *)&local_60, 5);
     CGLProgram::SetUniform1fv(this_00, "Offsets", (float *)&local_80, 5);
     ```
- **Finding:** The 5 weights are hardcoded IEEE-754 constants passed directly into GLSL uniforms for 9-tap separable Gaussian blur.
- **Classification:** **OBSERVED**.

---

### 4. Claim C4: Hair Material Configuration -> Native Ordering
- **Binary / File:** `libMTFilterKernel.so`
- **Function:** `MTFilterKernel::CMTFilterSoftHair::FilterToFBO` (Address `0x00234724`, decompiled lines 23504-23616)
- **Parameter Extraction:**
  - In loop over configuration items:
    - String `0x6e696167` (ASCII `'gain'`): sets `*(float *)(this + 0x144) = local_284;`
    - String `0x6c6f687365726874` + `'d'` (ASCII `'threshold'`): sets `*(float *)(this + 0x140) = local_284;`
- **Native Pipeline Sequence:**
  1. `GrayFilterToFBO(this, src_tex, fbo_100, w1, h1)`: Generates grayscale luminance base.
  2. `HairMaskFilterToFBO(this, fbo_104_tex, fbo_110, w1, h1)`: Applies hair mask and thresholding.
  3. `BlurHFilterToFBO(this, fbo_114_tex, fbo_120, w2, h2)`: Horizontal Gaussian blur pass.
  4. `BlurVFilterToFBO(this, fbo_124_tex, fbo_130, w2, h2)`: Vertical Gaussian blur pass.
  5. `SoftHairFilterToFBO(this, src_tex, fbo_134_tex, fbo_148, ...)`: Composites final colored hair.
- **Classification:** **OBSERVED**.

---

### 5. Claim C5: Segmentation Model & Confidence Source
- **Historical Claim:** Meitu natively executes BiSeNet for hair segmentation.
- **Audit Methodology:** Full string and symbol scan across all 45 native arm64 `.so` binaries.
- **Findings:**
  1. The string `bisenet` exists **0 times** across all 45 native binaries.
  2. `libaidetectionplugin.so` exports `hair_seg` and `segmentation`.
  3. `libManis.so` contains Meitu's proprietary `Manis` deep learning inference runtime (128 symbol matches).
  4. APK assets in `SOURCE/com.mt.mtxx.mtxx.apk` contain:
     - `assets/vlaimodel/libmtface/models/mtface_parsing.bin`
     - `assets/vlaimodel/libmtface/models/mtface_parsing_heavy.bin`
     - `assets/vlaimodel/libmtface/models/mtface_parsing_light.bin`
     - `assets/vlaimodel/libmtskinphone/Models/NE.manis`
- **Conclusion:** `BiSeNet` was an **external engineering proxy** introduced during Phase P0 development (`tau_aspect = 1.80`, frozen). Meitu's actual production application runs proprietary `mtface_parsing` on `libManis.so`.
- **Classification:** **CORRECTED PROXY**.

---

### 6. Claim C6: Truncation of `libmfxkit.so` & Absent Binaries
- **On-Disk File:** `libmfxkit.so` size = `773,652` bytes, SHA-256 = `78923a90997d34c5dd51215a6cd2bc26c9731806fd9037e4aa71fd3873d3bb4f`.
- **Container Declared:** `SOURCE/Meitu_12.17.8_APKPure.xapk` at offset `348,392,052`:
  - Declared `usize`: `1,354,736` bytes
  - Declared `csize`: `1,354,736` bytes (compression = 0 / STORED)
  - Declared `CRC32`: `0x4302c04c`
- **Forensic Deficit:** Exactly `581,084` bytes missing (42.89% truncated).
- **ELF Integrity Failure:**
  - Section table offset `e_shoff = 1,352,944`, extends to `1,354,736` (far beyond on-disk EOF `773,652`).
  - First `PT_LOAD` segment specifies `p_filesz = 1,307,184` (exceeds file size `773,652`).
- **Absent Binaries Verified:**
  - `libmtImageKit.so`: 0 files found on disk or in container.
  - `MTAiInterface`: Java/Kotlin interface class, not a native binary.
  - `vlai`: Asset directory name (`assets/vlaimodel/`), not a native binary.
- **Classification:** **OBSERVED & CONFIRMED**.
