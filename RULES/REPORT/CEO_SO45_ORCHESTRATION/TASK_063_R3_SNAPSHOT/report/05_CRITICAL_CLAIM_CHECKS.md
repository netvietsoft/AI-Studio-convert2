# 05_CRITICAL_CLAIM_CHECKS.md — Revision 3 Audit of Critical Historical Claims
**Standard Reference:** `Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt` (SHA-256: `10968894CDF48A10E64671EB81969E563B40F834A8A8AB16A4ECDC479E9FC85F`)  
**Task ID:** `TASK_063` (Revision 3)  
**Worker Identity:** `AGY_LEAD` (`ace29908-a2b0-4777-a070-6bd100509738`)  
**Lease ID:** `LEASE-CEO-WORKER-TASK_063-R3` | **Fencing Token:** `1011`  
**Reviewer Advisory Addressed:** `.ai/ceo/reviews/TASK_063_R2_79d93b4f_NEEDS_FIX.md` and `TASK_063_CEO_SOFTLIGHT_NUMERIC_ADDENDUM.md`  

---

## Executive Summary Matrix

| Claim ID | Subject Matter | Concrete Binary / Asset Anchor | Verified Ground Truth | Corrected Classification |
|---|---|---|---|---|
| **C1** | Mask Exclusion Channel & Output Alpha | `SOURCE/com.mt.mtxx.mtxx.apk` at `assets/ARKernelBuiltin/Shaders/MTFilter_HairMaskMix.fs` (raw SHA: `bd7cf000fd26fea40b623da5d3763405d62b0e75225496abfe912da35c6ee8aa`), decoded via XOR key `7c34b93a` (decoded SHA: `614435debd422b0211e8f8540f7a41a84d44c254ac72888d897e3ddc2c86353b`) | Reads `texturesrc.r` and `textureblack.r`. Outputs `gl_FragColor = vec4(val, val, val, val)` where $val = \min(src.r, 1.0 - black.r)$. Output alpha strictly equals clamped mask intensity. Producer of `textureblack` is UNKNOWN at shader level. | **OBSERVED (Shader logic) / UNKNOWN (Producer semantics)** |
| **C2** | SoftLight Blending Formula | `assets/ARKernelBuiltin/Shaders/HairSoft/MTFilter_PsSoftLightr.fs` (raw SHA: `eab66ebfde124a796a09ddd40d6b359db7b364fb4f5800709aeb4f09eb8ff5e2`), decoded via XOR key `7c34b93a` (decoded SHA: `69eb6db94958c599c01f432208dd47d5fd64a397e47b8b6c7ea0163fd1855d14`) | Literal piecewise quadratic/sqrt formula with alpha=1.0. **Mathematical counterexample proves it is NOT W3C SoftLight**: for $A=1/16, B=3/4$, exact rational math gives W3C SoftLight $= 69/512 = 0.134765625$, whereas Meitu shader gives $5/32 = 0.15625$ (difference $= 11/512 = 0.021484375$). Unsupported named "Pegtop equivalence" claim removed. Literal recovered formula retained. | **OBSERVED (Literal piecewise) / REJECTED (Universal W3C equivalence)** |
| **C3** | Gaussian Blur Sampling Offsets & Weights | `libMTFilterKernel.so` `.rodata` tables: H offsets (`0x8fd28`), Weights (`0x8fd3c`), V offsets (`0x8fd50`). Secondary tables: `0x8edc4`, `0x8edd8`, `0x8edec`. Ghidra VA convention: imagebase `0x100000` + file offset (`0x0018fd28`, `0x0018fd3c`, `0x0018fd50`). | Five IEEE-754 floats: `[0.159676, 0.263348, 0.122118, 0.030573, 0.004122]`. Loaded into `Weights` and `Offsets` uniforms in `BlurHFilterToFBO` and `BlurVFilterToFBO`. Distinct Aurora SPIR-V kernel (`hairmask_blur.fs.spirv`) uses offsets `[0, +/-1.18242502, +/-3.0293119]` and weights `[0.398943007, 0.295962989, 0.00456599984]`. Kept strictly separate. | **OBSERVED (Exact floats & offsets) / SEPARATE (SoftHair vs Aurora)** |
| **C4** | Native SoftHair Pipeline Execution Ordering | `libMTFilterKernel.so` `CMTFilterSoftHair::FilterToFBO` FUNCTION ENTRY at Ghidra VA `0x002344e8` (ELF RVA `0x001344e8`, file offset `0x001344e8`, body lines 23492-23495, stage calls lines 23597-23606). | Native sequence: `GrayFilterToFBO` -> `HairMaskFilterToFBO` -> `BlurHFilterToFBO` -> `BlurVFilterToFBO` -> `SoftHairFilterToFBO`. Address `0x00234724` was an internal instruction callsite, corrected to function entry `0x002344e8`. Upstream dye-material config (tint color, intensity slider, blend mode selection) remains **UNKNOWN**. | **OBSERVED (SoftHair stage order & entry VA 0x2344e8) / UNKNOWN (Upstream dye config)** |
| **C5** | AI Segmentation Model & Confidence Source | 44-binary symbol search across all valid `.so` libraries (.dynsym) | String `bisenet` occurs **0 times** across dynamic symbol tables of the 44 inspected libraries. `libmfxkit.so` failed readelf and is `NOT_CHECKED`. Note: Dynamic symbol search does not prove absence from non-symbol binary text. Model assets observed in APK: `assets/vlaimodel/libmtface/models/mtface_parsing*.bin` and `NE.manis`. In native binaries: `libManis.so` has 303 defined symbols mentioning `Manis`. Confidence source and runtime loader graph remain **UNKNOWN**. | **OBSERVED (Manis assets & symbols) / UNKNOWN (Runtime graph & confidence)** |
| **C6** | Physical Container Completeness & Absent Binaries | `SOURCE/Meitu_12.17.8_APKPure.xapk` (size = `349,175,808` B) vs 45 extracted SOs | Container was interrupted at byte `349,175,808`. `libmfxkit.so` on-disk size `773,652` B matches container prefix (bytes 348402156..349175808), but declared size is `1,354,736` B. Deficit: `581,084` B missing (42.89% data loss). Cause of interruption is **INFERRED / UNKNOWN** (download drop, packaging cutoff, or server truncation). `libmtImageKit.so`, `MTAiInterface`, `vlai` are absent from observed inputs. `app-debug.apk` is locally rebuilt (47 SOs), not vendor upstream. | **OBSERVED (Prefix match & deficit) / INFERRED_UNKNOWN (Interruption cause)** |

---

## Detailed Technical Evidence & Rational Mathematics

### 1. Claim C1: Mask Exclusion Channel & Output Alpha
- **Asset Provenance:**
  - APK Entry: `assets/ARKernelBuiltin/Shaders/MTFilter_HairMaskMix.fs`.
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
- **Rigorous Findings:**
  1. Math enforces: $val = \min(src.r, 1.0 - black.r)$ when $black.r > 0$.
  2. Fragment writes $val$ to all 4 channels (`vec4(val, val, val, val)`), proving that output alpha equals clamped intensity.
  3. Upstream producer of `textureblack` is **UNKNOWN** at shader level.

---

### 2. Claim C2: SoftLight Blending Formula & Mathematical Disproof of W3C Equivalence
- **Asset Provenance:**
  - APK Entry: `assets/ARKernelBuiltin/Shaders/HairSoft/MTFilter_PsSoftLightr.fs`.
  - Raw Encrypted Size: 812 bytes, SHA-256: `eab66ebfde124a796a09ddd40d6b359db7b364fb4f5800709aeb4f09eb8ff5e2`.
  - XOR Decryption Key: `7c 34 b9 3a`.
  - Decoded Output File: `.ai/reconstruction/evidence/TASK_061/decoded_shaders/ARKernelBuiltin_Shaders_HairSoft_MTFilter_PsSoftLightr.fs`.
  - Decoded Size: 812 bytes, SHA-256: `69eb6db94958c599c01f432208dd47d5fd64a397e47b8b6c7ea0163fd1855d14`.
- **Verbatim Shader Formulation (lines 13-26):**
  ```glsl
  highp float blendColor(highp float a, highp float b)
  {
      highp float c = 0.0;
      if (b <= 0.5)
      {
          c = 2.0 * a * b + a * a * (1.0 - 2.0 * b);
      }
      else
      {
          c = 2.0 * a * (1.0 - b) + sqrt(a) * (2.0 * b - 1.0);
      }
      return c;
  }
  ```
- **Exact Rational Arithmetic Counterexample:**
  - Let $A = 1/16$ (source color) and $B = 3/4$ (blend color). Since $B > 0.5$:
  - **W3C Standard SoftLight:**
    $$D(A) = ((16A - 12)A + 4)A = ((16(1/16) - 12)(1/16) + 4)(1/16) = (-11/16 + 64/16)(1/16) = (53/16)(1/16) = 53/256 = 0.20703125$$
    $$f_{w3c}(A, B) = A + (2B - 1)(D(A) - A) = 1/16 + (3/2 - 1)(53/256 - 16/256) = 1/16 + (1/2)(37/256) = 16/256 + 37/512 = 69/512 = 0.134765625$$
  - **Meitu Recovered Shader:**
    $$f_{meitu}(A, B) = 2A(1 - B) + \sqrt{A}(2B - 1) = 2(1/16)(1/4) + (1/4)(3/2 - 1) = 1/32 + (1/4)(1/2) = 1/32 + 1/8 = 5/32 = 0.15625$$
  - **Difference:**
    $$\Delta = 5/32 - 69/512 = 80/512 - 69/512 = 11/512 = 0.021484375$$
  - **Conclusion:** The difference is non-zero ($11/512$). This mathematically disproves universal equivalence to W3C SoftLight. The literal recovered shader formula is retained. Unsupported named equivalence labels are omitted.

---

### 3. Claim C3: Sampling Offsets & Exact Addresses
- In `libMTFilterKernel.so` `.rodata`:
  - `0x8fd28` (VA `0x0018fd28`): H offsets `[0.0, 0.002250, 0.005256, 0.008271, 0.011299]`.
  - `0x8fd3c` (VA `0x0018fd3c`): Blur weights `[0.159676, 0.263348, 0.122118, 0.030573, 0.004122]`.
  - `0x8fd50` (VA `0x0018fd50`): V offsets `[0.0, 0.002994, 0.006993, 0.011005, 0.015034]`.
  - Secondary tables: `0x8edc4`, `0x8edd8`, `0x8edec`.
- Distinct Aurora SPIR-V kernel (`hairmask_blur.fs.spirv`, SHA `b9366e16d85b29a2f72bfe360ad8cf7a44a2fd451692fc1298e5e6447af6a86e`):
  - Offsets: `[0.0, +/-1.18242502, +/-3.0293119]`.
  - Weights: `[0.398943007, 0.295962989, 0.00456599984]`.
  - Kept strictly separate from `MTSoftHair`.

---

### 4. Claim C4: SoftHair Pipeline Entry & Execution Order
- **Ghidra VA Entry:** `0x002344e8` (decompiled body lines 23492-23495).
  - ELF mapping: LOAD segment 1 begins at file offset `0x0`, VirtAddr `0x0`, size `0x1b50c0`.
  - Ghidra base: `0x00100000`.
  - ELF RVA: `0x001344e8` | File offset: `0x001344e8` | Ghidra VA: `0x002344e8`.
- **Decompiled C Call Sequence (lines 23597-23606):**
  1. `GrayFilterToFBO(this, ...)` (VA `0x00234854`)
  2. `HairMaskFilterToFBO(this, ...)` (VA `0x00234934`)
  3. `BlurHFilterToFBO(this, ...)` (VA `0x00234a90`)
  4. `BlurVFilterToFBO(this, ...)` (VA `0x00234c10`)
  5. `SoftHairFilterToFBO(this, ...)` (VA `0x00234d70`)
- **Correction:** Address `0x00234724` was an internal instruction callsite within `FilterToFBO`. The true function entry is `0x002344e8`. Upstream dye-material config remains **UNKNOWN**.

---

### 5. Claim C5: AI Segmentation Model & Confidence Source
- Dynamic symbol search across 44 valid binaries (.dynsym text): `bisenet` = 0 occurrences. `libmfxkit.so` failed readelf and is `NOT_CHECKED`.
- Dynamic symbol search does not prove absence from non-symbol binary text or unexported data.
- Model files observed in APK:
  - `assets/vlaimodel/libmtface/models/mtface_parsing*.bin`
  - `assets/vlaimodel/libmtface/models/NE.manis`
- Native binaries: `libManis.so` has 303 defined symbols mentioning `Manis`. `libaidetectionplugin.so` exports `hair_seg` and `segmentation`.
- Confidence source and production model loader execution graph remain **UNKNOWN**. BiSeNet was an external P0 heuristic adapter (`tau_aspect = 1.80`, frozen).

---

### 6. Claim C6: Container Completeness & Absent Binaries
- `SOURCE/Meitu_12.17.8_APKPure.xapk` is truncated at byte `349,175,808`.
- `libmfxkit.so` declared size is `1,354,736` B, available size is `773,652` B. Deficit: `581,084` B missing (42.89% data loss).
- Container match status: `PARTIAL_CONTAINER_TRUNCATED`. Cause of truncation is **INFERRED / UNKNOWN**.
- Missing binaries: `libmtImageKit.so`, `MTAiInterface`, `vlai` are absent from observed inputs.
- `app-debug.apk` contains 47 SOs (45 vendor + 2 rebuilt reborn libs) and is NOT an upstream vendor package.
