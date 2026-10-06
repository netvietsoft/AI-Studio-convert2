# GAP ANALYSIS: RECOVERED MEITU PIPELINE VS CURRENT CONVERT2
# Document ID: GAP_ANALYSIS_MEITU_VS_CONVERT2_V1.0
# Authority: TASK_061 / CEO Agent 0 / Antigravity L5 Decompilation Engine
# Target Source Under Audit: lib-core-graphics/src/main/cpp/src/hair/hair_pipeline_v2.cpp
# Date: 2026-10-06
# Status: CANONICAL TECHNICAL AUDIT

---

## 1. AUDIT SUMMARY

This document provides a line-by-line mathematical and architectural comparison between Meitu's reverse-engineered production hair coloring engine (recovered from native binaries `libMTFilterKernel.so`, `libARKernelInterface.so`, `libLayerFlow.so`, and 211 decoded shaders) and CONVERT2's current implementation in `lib-core-graphics/src/main/cpp/src/hair/hair_pipeline_v2.cpp`.

### Key Root-Cause Findings:
1. **Severe Forehead & Clothing Leakage in CONVERT2:** Caused by hand-crafted geometric oval equations and YCrCb heuristics (lines 870–887) instead of Meitu's verbatim exclusion clamping rule $\min(M_{\text{hair}}, 1.0 - M_{\text{excl}})$.
2. **Flat / Painted "Chalky" Hair Look:** Caused by linear chroma replacement in Oklab space (lines 1171–1176) instead of Meitu's Photoshop Pegtop SoftLight kernel.
3. **Muddy Colors on Dark Hair:** Caused by lack of a dedicated Pre-Whitening (Bleach) stage before color application.
4. **Jagged / Halos along Hairline:** Caused by box filter downsampling instead of Meitu's 7-tap separable min/max morphology and 5-tap Gaussian feathering with sub-pixel sampling offsets.

---

## 2. COMPREHENSIVE COMPONENT COMPARISON MATRIX

| Pipeline Stage | Current CONVERT2 Implementation (`hair_pipeline_v2.cpp`) | Recovered Meitu Production Pipeline | Failure Consequence in CONVERT2 |
|---|---|---|---|
| **Mask Exclusion** | Lines 870–887: Geometric face oval `(dx^2 + dy^2 <= 1.0)` + YCrCb skin check `cr in [122, 180]` | `MTFilter_HairMaskMix.fs`: `min(hair_mask, 1.0 - excl_mask)` where `excl` is semantic skin + ears + cloth | Fails on tilted heads, ears, necklaces, and all clothing; causes dye bleeding |
| **Mask Morphology** | Lines 980–1040: Basic box blur and custom dilation | `hairmask_erode/dilation.fs.spirv`: 7-tap separable min/max ($R=3$) | Hairline wisps get erased or haloed |
| **Edge Feathering** | Box filter or CPU Gaussian | `hairmask_blur.fs.spirv`: 5-tap Gaussian ($w_0=0.398943, w_1=0.295963, w_2=0.004566$) | Rough edge transitions, visible borders |
| **Pre-Whitening** | None. Attempts to lift $L^*$ directly in Oklab | Rec.601 luminance lerp: $C_{\text{desat}} = (1-\beta)C + \beta Y$, gain $=0.5$, thresh $=0.005$ | Pastel and light dyes turn brown or muddy olive |
| **Color Blending** | Lines 1171–1180: Linear interpolation of Oklab $a, b$ chroma coordinates | `MTFilter_PsSoftLightr.fs`: Photoshop Pegtop SoftLight $2AB + A^2(1-2B)$ / $2A(1-B) + \sqrt{A}(2B-1)$ | Hair loses strand texture, looks like flat wall paint |
| **Cuticle Detail** | Lines 1159–1169: Ad-hoc strand ratio $(oL + 0.02)/(bL + 0.02)$ | High-pass detail re-injection ($C_{\text{softlight}} + 0.25 \cdot D_{\text{cuticle}}$) | Highlights blow out, shadow crevices turn gray |
| **Alpha Composite** | Lines 1190–1200: CPU per-pixel lerp | Shader composite with clamped alpha | High CPU overhead compared to GPU fragment pipeline |

---

## 3. LINE-BY-LINE DEFECT ANALYSIS IN `hair_pipeline_v2.cpp`

### Defect 1: Forehead Oval Heuristic vs Exclusion Clamping
- **Location:** `hair_pipeline_v2.cpp`, Lines 870–888
- **Current Code:**
```cpp
// Lines 870-888:
// C. Dynamic Face & Forehead Oval Skin Protection (Zero leakage onto forehead!)
float dx = (static_cast<float>(x) - face_cx) / (face_w * 0.68f + 1.0f);
float dy = (ny - face_cy) / (face_h * 0.72f + 1.0f);
bool inFaceOval = (dx * dx + dy * dy <= 1.0f) && (ny >= forehead_y - 0.10f * face_h) && (ny <= chin_y + 0.10f * face_h);
if (inFaceOval && isSkin) {
    protectedMask[idx] = 1;
    continue;
}
// Forehead hairline region: strictly protect any skin or near-skin
if (ny >= forehead_y - 0.05f * face_h && ny <= forehead_y + 0.40f * face_h && std::abs(static_cast<float>(x) - face_cx) <= face_w * 0.60f) {
    float yVal = 0.299f * r + 0.587f * g + 0.114f * b;
    float cr = (r - yVal) * 0.713f + 128.0f;
    if ((cr >= 122.0f && cr <= 180.0f && r > b) || isSkin) {
        protectedMask[idx] = 1;
        continue;
    }
}
```
- **Why It Fails:**
  - An ellipse `(dx^2 + dy^2 <= 1.0)` cannot fit the human face when rotated or tilted.
  - The skin color test `cr >= 122.0f && cr <= 180.0f` produces false negatives in dim lighting and shadows, allowing hair dye to tint the skin purple/red.
  - No protection is provided for shoulders, collars, or clothing, which is why clothing absorbs hair dye.
- **Meitu Solution:**
  Use the multi-class semantic segmentation mask directly:
  $$M_{\text{exclusion}} = M_{\text{skin}} \cup M_{\text{ears}} \cup M_{\text{neck}} \cup M_{\text{cloth}} \cup M_{\text{background}}$$
  $$M_{\text{hair\_final}} = \min(M_{\text{hair\_raw}}, \, 1.0 - M_{\text{exclusion}})$$

---

### Defect 2: Linear Oklab Chroma Deposition vs Pegtop SoftLight
- **Location:** `hair_pipeline_v2.cpp`, Lines 1168–1180
- **Current Code:**
```cpp
// Lines 1168-1180:
// Reconstructed physical strand luminance
float finalL = std::clamp(liftedBaseL * strandRatio + strandDetail * 0.35f, 0.02f, 0.98f);

// Salon Chroma Toner Deposition (bell-curve midtone weighting)
float midtone = 4.0f * finalL * (1.0f - finalL);
float dyeStrength = std::clamp(0.45f + 0.55f * midtone, 0.0f, 1.0f) * intensity;
float finalA = origA[i] * (1.0f - dyeStrength) + targetA * dyeStrength;
float finalB = origB[i] * (1.0f - dyeStrength) + targetBCoord * dyeStrength;
```
- **Why It Fails:**
  - Directly overwriting $a^*$ and $b^*$ destroys the multi-spectral reflectance of real hair. Real hair is anisotropic with translucent cuticles; its color is modulated through light transmission and internal scattering.
  - Linear chroma interpolation makes the hair look like a solid flat layer of paint pasted onto the head.
- **Meitu Solution:**
  Use Photoshop Pegtop SoftLight per RGB channel (`MTFilter_PsSoftLightr.fs`):
  $$C(A, B) = \begin{cases} 2AB + A^2(1 - 2B), & B \le 0.5 \\ 2A(1 - B) + \sqrt{A}(2B - 1), & B > 0.5 \end{cases}$$
  This automatically modulates the target dye color by the natural luminance and specular highlights of the original hair strands.

---

### Defect 3: Lack of Pre-Whitening (Bleach) Stage
- **Location:** `hair_pipeline_v2.cpp`, Lines 1163–1167
- **Current Code:**
```cpp
// Lines 1163-1167:
float liftAmount = targetL - bL;
float melaninCurve = (bL > 0.0f) ? (0.40f + 0.60f * std::sqrt(std::clamp(bL, 0.0f, 1.0f))) : 0.40f;
float liftedBaseL = bL + liftAmount * materialParams.bleachPower * melaninCurve * intensity;
```
- **Why It Fails:**
  - Lifting luminance without desaturating natural melanin pigments creates severe hue shift (e.g. black/brown hair plus blonde dye produces dirty greenish brown).
- **Meitu Solution:**
  Apply pre-desaturation prior to color application:
  $$Y = 0.299 R + 0.587 G + 0.114 B$$
  $$C_{\text{bleached}} = \text{lerp}(C_{\text{orig}}, \, \vec{Y}, \, \beta_{\text{bleach}})$$
  $$C_{\text{base}} = \text{clamp}((C_{\text{bleached}} - 0.005) \cdot 1.5 + 0.005, \, 0.0, \, 1.0)$$

---

## 4. REQUIRED REFACTORING PLAN FOR CONVERT2

When implementing Phase 2 (Production Code Update), the following changes are required in `hair_pipeline_v2.cpp`:

1. **Replace lines 836–889:**
   Delete the ellipse `inFaceOval` and `YCrCb` checks.
   Implement verbatim `min(hair_mask[i], 1.0f - exclusion_mask[i])`.
2. **Add Separable Gaussian 5-tap Feathering:**
   Replace the crude boundary smoothing with Meitu's weights ($0.398943, 0.295963, 0.004566$).
3. **Replace lines 1163–1185:**
   Implement `pegtopSoftLight(float a, float b)` per RGB channel.
   Add `preWhiteningDesaturate(origR, origG, origB, bleachFactor)`.
   Apply high-pass detail preserving filter.

---
**AUTHOR SIGN-OFF:**
- Engine Architect: Antigravity L5 Decompilation Engine
- Status: CANONICAL TECHNICAL AUDIT
- Approved for Phase 2 Implementation Planning
