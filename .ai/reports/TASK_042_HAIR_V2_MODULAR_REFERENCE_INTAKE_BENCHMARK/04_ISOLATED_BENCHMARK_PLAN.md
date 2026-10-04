# 04. ISOLATED BENCHMARK PLAN

**Task ID**: `TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK_ACTIVE`  
**Date**: 2026-10-04 12:29:05 +0700  
**Status**: EXECUTED & VERIFIED  

---

## 1. Benchmark Objectives

1. Quantify the exact algorithmic difference between active CONVERT2 implementations and V1 reconstructed modular reference functions.
2. Measure improvements in:
   - High-frequency hair texture retention (micro-fiber detail).
   - Gamut clipping reduction in highlights.
   - Perceptual color accuracy (ISO CIEDE2000).
   - Boundary leakage on non-hair facial features.
3. Guarantee that the isolated benchmark runs in a sandbox without touching production binaries.

---

## 2. Test Dataset & Image Characteristics

The canonical 8-portrait suite from `TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE` was utilized as the benchmark ground truth:

| Test Case | Filename | Resolution | Hair Characteristics | Key Validation Focus |
|---|---|---|---|---|
| **Portrait 0** | `portrait_0_curly.png` | 960x1280 | Customer 0: Thick brown ringlet curls | Texture clumping, strand sharpness, zero ear/skin leakage |
| **Portrait 1** | `portrait_1_male_wavy.png` | 576x1280 | Male: Short wavy brown hair | Stubble boundary, short taper preservation |
| **Model 1** | `portrait_model1_blonde.png` | 800x1000 | Female: Light blonde fine straight hair | High-key highlight preservation, no yellow burn |
| **Model 2** | `portrait_model2_long_straight.png` | 800x1200 | Female: Jet black straight long hair | Deep melanin lift, specular sheen band continuity |
| **Model 3** | `portrait_model3_wavy_curls.png` | 800x1200 | Female: Loose wavy curls | Wave flow continuity across occlusions |
| **Model 4** | `portrait_model4_messy_curls.png` | 800x1200 | Female: Complex frizzy messy curls | Individual strand resolution, zero clump blurring |
| **Model 6** | `portrait_model6_fringe_bangs.png` | 800x1200 | Female: Straight hair with eyebrow bangs | Forehead boundary barrier, zero eyebrow bleed |
| **Monk** | `portrait_monk_bald_neg.png` | 500x333 | Male: Completely shaved bald head | Negative control: 100% bit-exact pass-through |

---

## 3. Benchmark Metrics & Mathematical Formulations

1. **High-Frequency Texture Retention Ratio ($R_{tex}$)**:
   $$R_{tex} = \frac{\sigma^2(I_{filtered} - G_\sigma(I_{filtered}))}{\sigma^2(I_{orig} - G_\sigma(I_{orig}))} \times 100\%$$
   Measures the percentage of high-frequency Laplacian variance preserved through filtering. Higher is better.

2. **Gamut Clipping Reduction Ratio ($R_{clip}$)**:
   $$R_{clip} = \frac{N_{blown}(C2) - N_{blown}(V1)}{N_{blown}(C2)} \times 100\%$$
   Counts the reduction in saturated highlight pixels ($>0.98$ in linear RGB).

3. **Perceptual Color Difference (ISO/CIE CIEDE2000 $\Delta E_{00}$)**:
   $$\Delta E_{00} = \sqrt{\left(\frac{\Delta L'}{k_L S_L}\right)^2 + \left(\frac{\Delta C'}{k_C S_C}\right)^2 + \left(\frac{\Delta H'}{k_H S_H}\right)^2 + R_T \left(\frac{\Delta C'}{k_C S_C}\right) \left(\frac{\Delta H'}{k_H S_H}\right)}$$
   Industry standard metric for human-perceivable color distance. $\Delta E < 1.0$ is imperceptible to normal human vision.

4. **Physical Device Skin Leakage ($L_{skin}$)**:
   $$L_{skin} = \frac{1}{N_{skin}} \sum_{i \in \text{Skin}} \frac{|I_{orig}(i) - I_{dyed}(i)|}{255.0} \times 100\%$$
   Tested on actual Samsung Galaxy A07 and A50s physical device captures. $L_{skin} = 0.0\%$ indicates perfect protection.

---

## 4. Execution Sandbox Protocol

1. Benchmark scripts are isolated in `scratch/task042/`.
2. Input images are read-only references to canonical test assets.
3. No modifications are staged in `lib-core-graphics` source trees during benchmark runs.
