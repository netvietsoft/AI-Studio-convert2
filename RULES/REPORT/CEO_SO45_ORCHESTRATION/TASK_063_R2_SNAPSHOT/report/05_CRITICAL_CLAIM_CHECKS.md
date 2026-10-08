# 05_CRITICAL_CLAIM_CHECKS.md — Revision 2 Audit of Critical Historical Claims
**Standard Reference:** `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` (SHA-256: `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`)  
**Task ID:** `TASK_063` (Revision 2)  
**Worker Identity:** `AGY_LEAD` (`ace29908-a2b0-4777-a070-6bd100509738`)  
**Fencing Token:** `1010` (Lease: `LEASE-CEO-WORKER-TASK_063-R2`)  
**Reviewer Advisory Addressed:** `.ai/ceo/reviews/TASK_063_R1_417dbf52_NEEDS_FIX.md`  

---

## Executive Summary Matrix

| Claim ID | Subject Matter | Concrete Binary / Asset Anchor | Verified Ground Truth | Corrected Classification |
|---|---|---|---|---|
| **C1** | Mask Exclusion Channel & Output Alpha | `SOURCE/com.mt.mtxx.mtxx.apk` `assets/ARKernelBuiltin/Shaders/MTFilter_HairMaskMix.fs` (raw SHA: `bd7cf000fd26fea40b623da5d3763405d62b0e75225496abfe912da35c6ee8aa`), decoded via XOR key `7c34b93a` (decoded SHA: `614435debd422b0211e8f8540f7a41a84d44c254ac72888d897e3ddc2c86353b`) | Reads `texturesrc.r` and `textureblack.r`. Outputs `gl_FragColor = vec4(val, val, val, val)`. Output alpha strictly equals clamped mask intensity. Producer of `textureblack` is UNKNOWN at shader level. | **OBSERVED (Shader logic) / UNKNOWN (Producer semantics)** |
| **C2** | SoftLight Blending Formula | `assets/ARKernelBuiltin/Shaders/HairSoft/MTFilter_PsSoftLightr.fs` (raw SHA: `eab66ebfde124a796a09ddd40d6b359db7b364fb4f5800709aeb4f09eb8ff5e2`), decoded via XOR key `7c34b93a` (decoded SHA: `69eb6db94958c599c01f432208dd47d5fd64a397e47b8b6c7ea0163fd1855d14`) | Literal piecewise quadratic/sqrt formula with alpha=1.0. **Mathematical counterexample proves it is NOT W3C SoftLight**: for $A=0.0625, B=0.75$, Meitu shader gives $0.15625$ while W3C gives $0.134765625$. It is a simplified Pegtop variant. Decoded byte equality does not prove shader compilability or device PASS. | **OBSERVED (Literal piecewise) / REJECTED (Universal W3C equivalence)** |
| **C3** | Gaussian Blur Sampling Offsets & Weights | `libMTFilterKernel.so` `.rodata` tables: H offsets (`0x8fd28`), Weights (`0x8fd3c`), V offsets (`0x8fd50`). Ghidra VA convention: imagebase `0x100000` + file offset (`0x0018fd28`, `0x0018fd3c`, `0x0018fd50`). | Five single-precision IEEE-754 weights: `[0.159676, 0.263348, 0.122118, 0.030573, 0.004122]`. Loaded into `Weights` and `Offsets` uniforms in `CMTFilterSoftHair::BlurHFilterToFBO` (VA `0x00234a90`) and `BlurVFilterToFBO` (VA `0x00234c10`). Separate Aurora SPIR-V kernel (`hairmask_blur.fs.spirv`) uses distinct offsets `[0, +/-1.18242502, +/-3.0293119]` and weights `[0.398943007, 0.295962989, 0.00456599984]`. | **OBSERVED (Exact floats & offsets) / SEPARATE (SoftHair vs Aurora)** |
| **C4** | Native SoftHair Pipeline Execution Ordering | `libMTFilterKernel.so` `CMTFilterSoftHair::FilterToFBO` (VA `0x00234724`, decompiled lines 23558-23616) | Native sequence: `GrayFilterToFBO` -> `HairMaskFilterToFBO` -> `BlurHFilterToFBO` -> `BlurVFilterToFBO` -> `SoftHairFilterToFBO`. Reads configuration string keys `'gain'` (`0x6e696167`) and `'threshold'` (`0x6c6f687365726874`). **This is strictly a SoftHair rendering stage sequence**, NOT proof of complete dye-material configuration or hair color application. | **OBSERVED (SoftHair stage order) / UNKNOWN (Upstream dye-material config)** |
| **C5** | AI Segmentation Model & Confidence Source | 45-binary symbol keyword scan across all 45 `.so` libraries | String `bisenet` occurs **exactly 0 times** across all 45 native binaries. `libManis.so` contains 294 `manis` symbols; `libaidetectionplugin.so` exports `hair_seg` and `segmentation`. Proprietary models in APK: `assets/vlaimodel/libmtface/models/mtface_parsing*.bin` and `NE.manis`. **Confidence source and model-loader execution graph remain UNKNOWN**. BiSeNet was an external P0 heuristic adapter (`tau_aspect = 1.80`, frozen). | **CORRECTED PROXY (BiSeNet is external P0) / UNKNOWN (Confidence source)** |
| **C6** | Physical Container Completeness & Absent Binaries | `SOURCE/Meitu_12.17.8_APKPure.xapk` (size = `349,175,808` B) vs 45 extracted SOs | Container was interrupted at byte `349,175,808`. `libmfxkit.so` on-disk size `773,652` B matches container prefix (bytes 348402156..349175808), but declared size is `1,354,736` B. Deficit: `581,084` B missing (42.89% data loss). `libmtImageKit.so`, `MTAiInterface`, `vlai` are absent from observed inputs; tail of container is UNKNOWN. `app-debug.apk` contains 47 SOs (45 vendor + 2 rebuilt reborn libs) and is NOT an upstream vendor package. | **OBSERVED (libmfxkit prefix & deficit) / PARTIAL_CONTAINER** |

---

## Detailed Technical Evidence Receipts

### 1. Claim C1: Mask Exclusion Channel & Output Alpha
- **Asset Provenance:**
  - APK Path: `SOURCE/com.mt.mtxx.mtxx.apk` at entry `assets/ARKernelBuiltin/Shaders/MTFilter_HairMaskMix.fs`.
  - Raw Encrypted Size: 559 bytes, SHA-256: `bd7cf000fd26fea40b623da5d3763405d62b0e75225496abfe912da35c6ee8aa`.
  - XOR Decryption Key: `7c 34 b9 3a`.
  - Decoded Output File: `.ai/reconstruction/evidence/TASK_061/decoded_shaders/ARKernelBuiltin_Shaders_MTFilter_HairMaskMix.fs`.
  - Decoded Size: 559 bytes, SHA-256: `614435debd422b0211e8f8540f7a41a84d44c254ac72888d897e3ddc2c86353b`.
- **Verbatim Source Lines (lines 10-18):**
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
- **Observations:**
  1. Both `texturesrc` and `textureblack` are sampled via the Red channel (`src.r`, `black.r`).
  2. Math clamps: $val = \min(src.r, 1.0 - black.r)$ when $black.r > 0$.
  3. Output fragment writes $val$ to all four channels (`vec4(val, val, val, val)`), meaning output alpha equals the clamped intensity.
- **Boundaries & Unknowns:**
  - Upstream semantic producer of `textureblack` (whether it represents face, ears, clothing, or background) cannot be determined from the shader alone and remains **UNKNOWN** until host C++ texture bindings in `libarkernel3.so` / `libLayerFlow.so` are traced.

---

### 2. Claim C2: SoftLight Blending Formula & Mathematical Analysis
- **Asset Provenance:**
  - APK Path: `assets/ARKernelBuiltin/Shaders/HairSoft/MTFilter_PsSoftLightr.fs`.
  - Raw Encrypted Size: 812 bytes, SHA-256: `eab66ebfde124a796a09ddd40d6b359db7b364fb4f5800709aeb4f09eb8ff5e2`.
  - XOR Decryption Key: `7c 34 b9 3a`.
  - Decoded Output File: `.ai/reconstruction/evidence/TASK_061/decoded_shaders/ARKernelBuiltin_Shaders_HairSoft_MTFilter_PsSoftLightr.fs`.
  - Decoded Size: 812 bytes, SHA-256: `69eb6db94958c599c01f432208dd47d5fd64a397e47b8b6c7ea0163fd1855d14`.
- **Verbatim Source Lines (lines 13-26):**
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
- **Mathematical Analysis vs W3C SoftLight Specification:**
  - Primary Reference: W3C Compositing & Blending Level 1 (`https://www.w3.org/TR/compositing-1/#blendingsoftlight`).
  - W3C Standard defines:
    $$\text{For } B > 0.5: \quad D(A) = \begin{cases} ((16A - 12)A + 4)A & \text{if } A \le 0.25 \\ \sqrt{A} & \text{if } A > 0.25 \end{cases}$$
    $$C_{\text{W3C}} = A + (2B - 1)(D(A) - A)$$
  - **Counterexample ($A = 0.0625$, $B = 0.75$):**
    - Meitu Shader Formula:
      $$C_{\text{Meitu}} = 2(0.0625)(1.0 - 0.75) + \sqrt{0.0625}(2 \times 0.75 - 1)$$
      $$C_{\text{Meitu}} = 2(0.0625)(0.25) + 0.25(0.5) = 0.03125 + 0.125 = \mathbf{0.15625}$$
    - W3C Standard Formula:
      Since $A = 0.0625 \le 0.25$, $D(A) = ((16 \times 0.0625 - 12)0.0625 + 4)0.0625 = 0.20703125$.
      $$C_{\text{W3C}} = 0.0625 + (1.5 - 1)(0.20703125 - 0.0625) = 0.0625 + 0.5(0.14453125) = \mathbf{0.134765625}$$
    - Numerical Difference: $|C_{\text{Meitu}} - C_{\text{W3C}}| = 0.021484375$ (~5.5 levels in 8-bit color depth).
- **Conclusion:** Meitu's SoftLight is a simplified classic Pegtop piecewise quadratic/square-root blend, **NOT** the full W3C cubic piecewise function. Decoded byte equality does not prove shader compilability, production runtime binding, or device PASS.

---

### 3. Claim C3: Blur Sampling Offsets & Weights
- **Binary:** `libMTFilterKernel.so` (SHA-256: `f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4`).
- **Memory Addressing Convention:** Ghidra Virtual Address = File Offset + `0x100000` (Image Base: `0x100000`).
- **Table 1: CMTFilterSoftHair Blur Kernel (File Offset `0x8fd28` .. `0x8fd64`):**
  - **Horizontal Offsets Array (File Offset `0x8fd28`, VA `0x0018fd28`):**
    - `0x8fd28`: `0.0f` (`00 00 00 00`)
    - `0x8fd2c`: `0.002250f` (`bc 74 13 3b`)
    - `0x8fd30`: `0.005256f` (`86 3a ac 3b`)
    - `0x8fd34`: `0.008271f` (`17 83 07 3c`)
    - `0x8fd38`: `0.011299f` (`71 1f 39 3c`)
  - **Blur Weights Array (File Offset `0x8fd3c`, VA `0x0018fd3c`):**
    - `0x8fd3c`: `0.159676f` (`1b 82 23 3e`)
    - `0x8fd40`: `0.263348f` (`8d d5 86 3e`)
    - `0x8fd44`: `0.122118f` (`01 19 fa 3d`)
    - `0x8fd48`: `0.030573f` (`3a 74 fa 3c`)
    - `0x8fd4c`: `0.004122f` (`d8 11 87 3b`)
  - **Vertical Offsets Array (File Offset `0x8fd50`, VA `0x0018fd50`):**
    - `0x8fd50`: `0.0f` (`00 00 00 00`)
    - `0x8fd54`: `0.002994f` (`fc 36 44 3b`)
    - `0x8fd58`: `0.006993f` (`89 25 e5 3b`)
    - `0x8fd5c`: `0.011005f` (`51 4e 34 3c`)
    - `0x8fd60`: `0.015034f` (`2b 51 76 3c`)
  - **Callers:**
    - `CMTFilterSoftHair::BlurHFilterToFBO` (VA `0x00234a90`): Passes H offsets (`0x0018fd28`) and Weights (`0x0018fd3c`) to shader uniform `Offsets` and `Weights`.
    - `CMTFilterSoftHair::BlurVFilterToFBO` (VA `0x00234c10`): Passes V offsets (`0x0018fd50`) and Weights (`0x0018fd3c`) to shader uniform `Offsets` and `Weights`.
- **Table 2: MTSoftHairFilter Kernel (File Offset `0x8edc4` .. `0x8ee00`):**
  - Identical float arrays at file offsets: H offsets (`0x8edc4`, VA `0x0018edc4`), Weights (`0x8edd8`, VA `0x0018edd8`), V offsets (`0x8edec`, VA `0x0018edec`).
  - Callers: `MTSoftHairFilter::blurHFilterToFBO` (VA `0x001f4528`) and `blurVFilterToFBO` (VA `0x001f46d0`).
- **Table 3: Distinct Aurora SPIR-V Kernel (`hairmask_blur.fs.spirv`):**
  - Path: `MTAurora.bundle/Shaders/hairmask_blur.fs.spirv` (SHA-256: `b9366e16d85b29a2f72bfe360ad8cf7a44a2fd451692fc1298e5e6447af6a86e`).
  - Disassembled via `spirv-dis`:
    - Offsets: `0.0`, `+/- 1.18242502`, `+/- 3.0293119`.
    - Weights: `0.398943007` (center), `0.295962989` (taps +/- 1), `0.00456599984` (taps +/- 2).
  - **Strictly documented as a distinct, separate kernel**; not interchangeable with SoftHair native blur.

---

### 4. Claim C4: SoftHair Pipeline Execution Ordering & Parameters
- **Decompiled C Body:** `MTFilterKernel::CMTFilterSoftHair::FilterToFBO` (VA `0x00234724`, lines 23558-23616):
  ```c
  // Parsing parameters from config list:
  if (((int)*plVar3 == 0x6e696167) && (*(float *)(this + 0x144) != local_284)) {
      *(float *)(this + 0x144) = local_284; // String 'gain'
  }
  else if ((*plVar3 == 0x6c6f687365726874 && (char)plVar3[1] == 'd') && (*(float *)(this + 0x140) != local_284)) {
      *(float *)(this + 0x140) = local_284; // String 'threshold'
  }
  
  // Pipeline stages:
  GrayFilterToFBO(this, src_tex, fbo_100, w1, h1);
  HairMaskFilterToFBO(this, fbo_104_tex, fbo_110, w1, h1);
  BlurHFilterToFBO(this, fbo_114_tex, fbo_120, w2, h2);
  BlurVFilterToFBO(this, fbo_124_tex, fbo_130, w2, h2);
  SoftHairFilterToFBO(this, src_tex, fbo_134_tex, fbo_148, ...);
  ```
- **Scope Limit & Unknowns:**
  - This 5-step sequence is strictly the **rendering stage order** for the SoftHair shader pass.
  - Upstream dye-material configuration, color selection dictionaries, and user-facing intensity mapping remain **UNKNOWN** at this level and require full JNI/config layer tracing in Lane A.

---

### 5. Claim C5: AI Segmentation Model & Confidence Source
- **Exhaustive 45-Binary Scan (Results in `RAW_DIR/so45_symbol_keyword_counts.json`):**
  - `bisenet`: Exactly **0 occurrences** across all 45 native libraries.
  - `manis`: 294 in `libManis.so`, 22 in `libARKernelInterface.so`, 3 in `libAIModelKit.so`.
  - `hair`: 577 in `libLayerFlow.so`, 41 in `libMTFilterKernel.so`, 22 in `libaidetectionplugin.so`, 12 in `libarkernel3_android.so`.
  - `seg`: 204 in `libarkernel3.so`, 162 in `libaidetectionplugin.so`, 45 in `libMTFilterKernel.so`.
  - `npu`: 1340 in `libmanis_npu_adapter.so`, 409 in `libMTFilterKernel.so`, 129 in `libhiai_ir.so`, 21 in `libhiai.so`.
- **Proprietary Model Assets in APK:**
  - `assets/vlaimodel/libmtface/models/mtface_parsing.bin`
  - `assets/vlaimodel/libmtface/models/mtface_parsing_heavy.bin`
  - `assets/vlaimodel/libmtface/models/mtface_parsing_light.bin`
  - `assets/vlaimodel/libmtskinphone/Models/NE.manis`
- **Findings & Unknowns:**
  - `BiSeNet` was an external P0 engineering proxy (`tau_aspect = 1.80`, frozen).
  - Production Meitu runs proprietary models via `libManis.so` and `libaidetectionplugin.so`.
  - Confidence source and complete tensor graph remain **UNKNOWN** in this baseline.

---

### 6. Claim C6: Physical Container Completeness & Absent Binaries
- **Container Analysis (`SOURCE/Meitu_12.17.8_APKPure.xapk`):**
  - File Size: `349,175,808` bytes.
  - Container status: `PARTIAL_CONTAINER` (interrupted download before writing Central Directory).
  - 44 libraries: Exact payload match (bytes, SHA-256, CRC32).
  - 1 library (`libmfxkit.so`): Available prefix `773,652` bytes matches on-disk file 100%, but declared size is `1,354,736` bytes. Deficit: `581,084` bytes missing (42.89% data loss).
- **Absent Binaries:**
  - `libmtImageKit.so`, `MTAiInterface`, `vlai` are confirmed absent from observed inputs. Incomplete container tail content remains UNKNOWN.
  - `app-debug.apk` contains 47 SOs (45 vendor + 2 rebuilt reborn libs) and is NOT an upstream vendor package.
