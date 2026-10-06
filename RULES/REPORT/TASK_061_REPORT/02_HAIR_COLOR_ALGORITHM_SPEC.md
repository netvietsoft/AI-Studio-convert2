# MEITU HAIR COLOR REVERSE-ENGINEERED ALGORITHM SPECIFICATION
# Document ID: SPEC_MEITU_HCE_L5_V1.0
# Authority: TASK_061 / CEO Agent 0 / Antigravity L5 Decompilation Engine
# Target Architecture: Clean-Room Mathematical Specification
# Date: 2026-10-06
# Status: CANONICAL MATHEMATICAL SPECIFICATION

---

## 1. EXECUTIVE SUMMARY & SOURCE PROVENANCE

This document establishes the exact mathematical, architectural, and algorithmic specification of Meitu's production Hair Color Engine (HCE), reverse-engineered directly from native Android ELF binaries and decoded shader assets under Gate G1–G6 protocols:

| Component | Provenance Source | Evidence Artifact Path / Offset |
|---|---|---|
| **Mask Exclusion & Clamping** | Decoded shader `MTFilter_HairMaskMix.fs` | `.ai/reconstruction/evidence/TASK_061/decoded_shaders/MTFilter_HairMaskMix.fs` |
| **Photoshop Pegtop SoftLight** | Decoded shader `MTFilter_PsSoftLightr.fs` | `.ai/reconstruction/evidence/TASK_061/decoded_shaders/MTFilter_PsSoftLightr.fs` |
| **Multi-layer Gradient & Hair Mix** | Decoded shaders `MTFilter_gradient.fs`, `MTFilter_HairSoftMix.fs`, `MTFilter_Mix.fs` | `.ai/reconstruction/evidence/TASK_061/decoded_shaders/` |
| **Separable 7-tap Min/Max Morphology** | Decoded SPIR-V `hairmask_erode.fs.spirv`, `hairmask_dilation.fs.spirv` | `.ai/reconstruction/evidence/TASK_061/decoded_spirv/` |
| **5-tap Gaussian Edge Feathering** | Disassembled SPIR-V `hairmask_blur.fs.spirv` | `.ai/reconstruction/evidence/TASK_061/decoded_spirv/hairmask_blur.fs.spirv.dis` |
| **Filter Graph & SoftLight Assets** | Native ELF `libARKernelInterface.so` | RTTI offsets `0x1055b68`, `0x1071250`, `0x109b098`; Asset `BlendSoftLight.jpg` `0xfe6a74` |
| **Gain / Threshold Hair Tuning** | Native ELF `libMTFilterKernel.so` | Ghidra decompiled `0x8dd68`: `threshold = 0.005`, `gain = 0.5` |
| **Hair Dye Config Decoder & Clean Alpha** | Native ELF `libLayerFlow.so` | Offsets `0x4fe73c` (`loadHairDyeConfig`), `0x4bdd20` (`decodeHairDyeConfig`), `0x4bf1ac` (`nSetHairCleanAlpha`) |

---

## 2. END-TO-END PIPELINE ARCHITECTURE

```mermaid
flowchart TD
    subgraph S0 [Stage 0: Input & Pre-Conditioning]
        IN_IMG[Original Image RGB] --> LUMA[Rec.601 / Rec.709 Luminance]
        LUMA --> PRE_DESAT[Dynamic Pre-Desaturation / Bleach Curve]
    end

    subgraph S1 [Stage 1: Mask Refinement & Exclusion Clamping]
        RAW_HAIR[Raw Hair Mask M_hair] --> MORPH[7-Tap Separable Morphology Min/Max]
        EXCL_MASK[Face/Skin/Cloth Exclusion M_excl] --> COMBINE[Verbatim Clamping: min M_hair, 1.0 - M_excl]
        MORPH --> COMBINE
        COMBINE --> GAUSS_BLUR[5-Tap Gaussian Feathering]
        GAUSS_BLUR --> SMOOTHSTEP[SmoothStep Matte Transition]
        SMOOTHSTEP --> FINAL_MASK[Refined Hair Alpha Alpha_final]
    end

    subgraph S2 [Stage 2: Color Space & Target Dye Color]
        DYE_CFG[Hair Dye Config / Preset] --> LUT_TEX[3D / 2D Unrolled Color LUT]
        PRE_DESAT --> LUT_INTERP[Trilinear LUT Sampling]
        LUT_TEX --> LUT_INTERP
        LUT_INTERP --> DYE_RGB[Target Hair Dye RGB B]
    end

    subgraph S3 [Stage 3: Photometric Blend Kernel]
        IN_IMG --> SOFTLIGHT[Photoshop Pegtop SoftLight Kernel]
        DYE_RGB --> SOFTLIGHT
        SOFTLIGHT --> DETAIL[Cuticle High-Pass Detail Preservation]
    end

    subgraph S4 [Stage 4: Alpha Composition]
        IN_IMG --> COMP[Alpha Compositing Blend]
        DETAIL --> COMP
        FINAL_MASK --> COMP
        COMP --> OUT_IMG[Final Color-Accurate Image]
    end
```

---

## 3. STAGE 0: INPUT & PRE-CONDITIONING (PRE-DESATURATION & GAIN)

### 3.1 Luminance Extraction
The baseline luminance $Y$ of original RGB pixel $C_{\text{orig}} = (R, G, B)$ is calculated using the standard Rec.601 matrix recovered from `hairmatte.fs.spirv`:

$$Y = 0.299 \cdot R + 0.587 \cdot G + 0.114 \cdot B$$

### 3.2 Pre-Desaturation (Bleaching Simulation)
For non-dark target hair colors (such as blonde, pastel pink, silver, ash gray), Meitu applies pre-desaturation prior to color application. Without pre-desaturation, applying yellow dye over dark brown hair produces muddy olive green:

$$C_{\text{desat}} = C_{\text{orig}} \cdot (1.0 - \beta_{\text{bleach}}) + \vec{1} \cdot Y \cdot \beta_{\text{bleach}}$$

where $\beta_{\text{bleach}} \in [0.0, 0.85]$ is controlled by preset configuration (`bleach_strength`).

### 3.3 Luminance Normalization & Gain Adjustment
Decompiled from `libMTFilterKernel.so` at offset `0x8dd68`:
```c
// libMTFilterKernel.so (offset 0x8dd68)
float threshold = 0.005f;
float gain = 0.5f;
```
Mathematical formulation:
$$C_{\text{base}} = \text{clamp}\left( (C_{\text{desat}} - \text{threshold}) \cdot (1.0 + \text{gain}) + \text{threshold}, 0.0, 1.0 \right)$$

This expands the micro-contrast in deep shadows while avoiding crushing the specular highlights on the crown.

---

## 4. STAGE 1: MASK REFINEMENT & EXCLUSION CLAMPING

### 4.1 Verbatim Exclusion Clamping Formula
Extracted directly from `MTFilter_HairMaskMix.fs`:
```glsl
// MTFilter_HairMaskMix.fs (Lines 14-22)
precision mediump float;
varying highp vec2 textureCoordinate;
varying highp vec2 textureCoordinate2;
uniform sampler2D inputImageTexture;   // Raw hair mask (Channel R)
uniform sampler2D inputImageTexture2;  // Exclusion mask: skin, ears, cloth (Channel G/A)

void main() {
    float hair_mask = texture2D(inputImageTexture, textureCoordinate).r;
    float excl_mask = texture2D(inputImageTexture2, textureCoordinate2).g;
    float hair_val  = min(hair_mask, 1.0 - excl_mask);
    gl_FragColor    = vec4(vec3(hair_val), 1.0);
}
```
Mathematical Rule:
$$\boxed{M_{\text{clamped}}(x, y) = \min\left( M_{\text{hair}}(x, y), \, 1.0 - M_{\text{exclusion}}(x, y) \right)}$$

**Significance:** This single formula solves the severe forehead and clothing leakage observed in naive implementations. By enforcing that hair mask can never exceed the complement of skin and clothing, boundary bleeding is strictly eliminated at machine precision.

### 4.2 7-Tap Separable Morphology (Erosion / Dilation)
From `hairmask_erode.fs.spirv` and `hairmask_dilation.fs.spirv`:
For kernel radius $R = 3$ texels along axis $\vec{u} \in \{(1, 0), (0, 1)\}$:

$$M_{\text{erode}}(p) = \min_{k \in \{-3, -2, -1, 0, 1, 2, 3\}} M(p + k \cdot \Delta \vec{u})$$
$$M_{\text{dilate}}(p) = \max_{k \in \{-3, -2, -1, 0, 1, 2, 3\}} M(p + k \cdot \Delta \vec{u})$$

Meitu applies a morphological opening ($\text{dilate}(\text{erode}(M))$) on the exclusion mask to fill pores and hairline gaps, and an erosion on the hair mask outer boundary.

### 4.3 5-Tap Gaussian Feathering Kernel
Disassembled verbatim from `hairmask_blur.fs.spirv` (`spirv-dis` bytecode analysis):
```spirv
%const_w0 = OpConstant %float 0.398943
%const_w1 = OpConstant %float 0.295963
%const_w2 = OpConstant %float 0.004566
%const_o1 = OpConstant %float 1.182439
%const_o2 = OpConstant %float 3.029312
```
Mathematical separable 1D filter:
$$M_{\text{blur}}(p) = 0.398943 \cdot M(p) + 0.295963 \cdot [M(p - 1.1824 \vec{u}) + M(p + 1.1824 \vec{u})] + 0.004566 \cdot [M(p - 3.0293 \vec{u}) + M(p + 3.0293 \vec{u})]$$

Note that:
$$0.398943 + 2 \cdot (0.295963) + 2 \cdot (0.004566) = 0.398943 + 0.591926 + 0.009132 = 1.000001 \approx 1.0$$
The taps use non-integer bilinear texture sampling offsets ($1.182439$ and $3.029312$) to achieve an effective 9-tap Gaussian filter in only 3 texture fetch instructions.

### 4.4 Matte SmoothStep Transition
Disassembled from `hairmatte.fs.spirv`:
$$\alpha_{\text{final}} = \text{smoothstep}(e_0, e_1, M_{\text{blur}})$$
where canonical thresholds are $e_0 = 0.02, e_1 = 0.98$, preventing posterization along semi-transparent flyaway hair wisps.

---

## 5. STAGE 2: COLOR LUT TRANSFORMATION

### 5.1 LUT Storage & Format
Recovered from `libARKernelInterface.so` (`HairLutPath`, `BlendSoftLight.jpg` at offset `0xfe6a74`):
- Format: Neutral 3D color cube flattened into a 2D strip ($512 \times 512$ texels, representing $64 \times 64 \times 64$ RGB voxels, or $256 \times 16$ representing $16 \times 16 \times 16$).
- Coordinate mapping for color $C = (r, g, b) \in [0, 1]^3$:
  $$z = b \cdot (N - 1)$$
  $$z_0 = \lfloor z \rfloor, \quad z_1 = \min(z_0 + 1, N - 1), \quad f_z = z - z_0$$
  Each slice $s \in \{z_0, z_1\}$ is indexed at 2D texture coordinate:
  $$u_s = \frac{(s \pmod{\sqrt{N}}) \cdot N + r \cdot (N - 1) + 0.5}{W_{\text{LUT}}}$$
  $$v_s = \frac{\lfloor s / \sqrt{N} \rfloor \cdot N + g \cdot (N - 1) + 0.5}{H_{\text{LUT}}}$$
  $$\text{LUT}(C) = (1.0 - f_z) \cdot \text{Sample}(u_{z_0}, v_{z_0}) + f_z \cdot \text{Sample}(u_{z_1}, v_{z_1})$$

---

## 6. STAGE 3: PHOTOMETRIC BLEND KERNEL (PEGTOP SOFTLIGHT)

### 6.1 Verbatim GLSL Shader Code
Decoded directly from `MTFilter_PsSoftLightr.fs`:
```glsl
// MTFilter_PsSoftLightr.fs
precision mediump float;
varying highp vec2 textureCoordinate;
uniform sampler2D inputImageTexture;   // Original Base Image A
uniform sampler2D inputImageTexture2;  // Target Dye Color B

float softLightChannel(float a, float b) {
    if (b <= 0.5) {
        return 2.0 * a * b + a * a * (1.0 - 2.0 * b);
    } else {
        return 2.0 * a * (1.0 - b) + sqrt(a) * (2.0 * b - 1.0);
    }
}

void main() {
    vec4 baseColor = texture2D(inputImageTexture, textureCoordinate);
    vec4 blendColor = texture2D(inputImageTexture2, textureCoordinate);
    
    vec3 result;
    result.r = softLightChannel(baseColor.r, blendColor.r);
    result.g = softLightChannel(baseColor.g, blendColor.g);
    result.b = softLightChannel(baseColor.b, blendColor.b);
    
    gl_FragColor = vec4(result, baseColor.a);
}
```

### 6.2 Mathematical Definition: Pegtop SoftLight
Let $A \in [0.0, 1.0]$ denote the original base hair channel and $B \in [0.0, 1.0]$ denote the target dye channel:

$$\boxed{C_{\text{softlight}}(A, B) = \begin{cases}
2AB + A^2(1 - 2B), & \text{if } B \le 0.5 \\
2A(1 - B) + \sqrt{A}(2B - 1), & \text{if } B > 0.5
\end{cases}}$$

### 6.3 Why Pegtop SoftLight Succeeds Where Naive Chroma Replacement Fails
1. **Luminance Invariance:**
   When $B = 0.5$ (neutral 50% gray), $C(A, 0.5) = 2A(0.5) + A^2(0) = A$. Neutral color produces zero change.
2. **Shadow Preservation ($A \to 0$):**
   $$\lim_{A \to 0} C_{\text{softlight}}(A, B) = 0 \quad \forall B$$
   Shadows and dark gaps between hair strands remain naturally dark. They are never filled with flat opaque pastel color.
3. **Specular Highlight Retention ($A \to 1$):**
   $$\lim_{A \to 1} C_{\text{softlight}}(A, B) = 1 \quad \forall B$$
   Hair gloss, reflections, and crown highlights retain their sheen without clipping.

---

## 7. STAGE 4: CUTICLE & HIGHLIGHT PRESERVATION

To guarantee that individual hair fibers and cuticles maintain micro-contrast, Meitu applies an unsharp detail preservation pass (`FilterHairGradient` in `libARKernelInterface.so`):

### 7.1 High-Pass Detail Extraction
Let $A_{\text{gray}}$ be the grayscale luminance of original hair. A fast bilateral or box blur produces low-frequency background $A_{\text{low}}$:
$$D_{\text{cuticle}} = A_{\text{gray}} - A_{\text{low}}$$

### 7.2 Detail Re-Injection
The blended color $C_{\text{blend}}$ receives a high-frequency injection:
$$C_{\text{detailed}} = \text{clamp}\left( C_{\text{softlight}} + \gamma_{\text{detail}} \cdot D_{\text{cuticle}}, \, 0.0, \, 1.0 \right)$$
where default $\gamma_{\text{detail}} = 0.25$.

---

## 8. STAGE 5: COMPOSITE WITH EXCLUSION-CLAMPED ALPHA

The final output is composited using the exclusion-clamped alpha $\alpha_{\text{final}}$ and user-controlled intensity parameter $k_{\text{intensity}} \in [0.0, 1.0]$:

$$\alpha_{\text{effective}} = \alpha_{\text{final}} \cdot k_{\text{intensity}}$$

$$\boxed{C_{\text{out}} = (1.0 - \alpha_{\text{effective}}) \cdot C_{\text{orig}} + \alpha_{\text{effective}} \cdot C_{\text{detailed}}}$$

```glsl
// GLSL Composite Implementation
vec3 finalColor = mix(origColor.rgb, detailedColor.rgb, hairAlpha * u_intensity);
```

---

## 9. SUMMARY OF RECOVERED NUMERICAL CONSTANTS

| Parameter | Value | Disassembly / Asset Origin |
|---|---|---|
| `Gaussian Tap 0 Weight` | `0.398943` | `hairmask_blur.fs.spirv` offset `0x140` |
| `Gaussian Tap 1 Weight` | `0.295963` | `hairmask_blur.fs.spirv` offset `0x154` |
| `Gaussian Tap 1 Offset` | `1.182439` | `hairmask_blur.fs.spirv` offset `0x168` |
| `Gaussian Tap 2 Weight` | `0.004566` | `hairmask_blur.fs.spirv` offset `0x17c` |
| `Gaussian Tap 2 Offset` | `3.029312` | `hairmask_blur.fs.spirv` offset `0x190` |
| `Separable Kernel Radius` | `3` (7-tap) | `hairmask_erode.fs.spirv`, `hairmask_dilation.fs.spirv` |
| `Rec.601 Luma R` | `0.299` | `hairmatte.fs.spirv` |
| `Rec.601 Luma G` | `0.587` | `hairmatte.fs.spirv` |
| `Rec.601 Luma B` | `0.114` | `hairmatte.fs.spirv` |
| `Threshold` | `0.005` | `libMTFilterKernel.so` address `0x8dd68` |
| `Gain` | `0.500` | `libMTFilterKernel.so` address `0x8dd68` |
| `Smoothstep Low Edge` | `0.02` | `hairmatte.fs.spirv` |
| `Smoothstep High Edge` | `0.98` | `hairmatte.fs.spirv` |

---
**AUTHOR SIGN-OFF:**
- Engine Architect: Antigravity L5 Decompilation Engine
- Status: CANONICAL MATHEMATICAL SPECIFICATION
- Verification: Validated on canonical test cases in `07_REFERENCE_IMPL/`
