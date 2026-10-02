# P0-B.2R CONFIGURATION SPECIFICATION & HYPERPARAMETER FREEZE

## 1. Executive Summary & Principles
- **Phase:** P0-B.2R — Robustness & Performance Closure
- **Core Objectives:**
  1. **R1:** High-Exposure Hair Recovery (`sample_26`: Hair Core $\ge 75\%$, Zero skin leakage).
  2. **R2:** Preprocessing Geometry Fix (Aspect-preserving Subject ROI / Letterbox eliminates screenshot Class 18 false positives).
  3. **R3:** Performance Optimization (Variant P3: ROI + Half-Res Laplacian reduces P50 Matting $\le 85$ ms on Samsung Galaxy SM-A075F).
- **Status:** FROZEN & LOCKED.
- **Reference Device:** Samsung Galaxy SM-A075F (Helio G99 / Android 14 / ARM64-v8a).

---

## 2. Geometry Configuration (Task R2)
| Parameter | Symbol | Frozen Value | Physical Meaning / Rationale |
| :--- | :--- | :--- | :--- |
| **Extreme Aspect Ratio Threshold** | $\tau_{\text{aspect}}$ | 1.45 | Triggers aspect-preserving letterbox/ROI for mobile screenshots (2.22:1) |
| **ROI Top Margin Factor** | $M_{\text{top}}$ | 0.90 | Extends ROI above face to cover complete hair crown and flyaways |
| **ROI Side Margin Factor** | $M_{\text{side}}$ | 0.60 | Extends ROI laterally to encompass sideburns and cascading locks |
| **ROI Bottom Margin Factor** | $M_{\text{bottom}}$ | 0.60 | Extends ROI below chin to capture long chest/shoulder hair |
| **Letterbox Pad Value** | `PadVal` | `[0, 0, 0]` | Standard neutral black padding for BiSeNet input |
| **Inverse Transform Rule** | $\mathcal{T}^{-1}$ | Deterministic | Strictly maps ROI/letterbox semantic labels back to exact original pixels |

---

## 3. High-Exposure Recovery Configuration (Task R1)
| Parameter | Symbol | Frozen Value | Physical Meaning / Rationale |
| :--- | :--- | :--- | :--- |
| **Core Reference Mask** | `core_ref` | `(alpha_base > 0.90 & labels != 1) \| (labels == 17)` | Excludes falsely dilated forehead skin from core measurement |
| **Hairline Adaptive Soften** | $\gamma_{\text{hairline}}$ | 0.88 | Gentle transition factor on confirmed hair strands touching forehead |
| **Hair Texture Confidence Gate**| $\tau_{\text{tex\_core}}$ | 0.08 | Retains core status if high-frequency strand energy is detected |
| **Skin Strict Protection** | `strict_skin` | `ENABLED` | Confirmed forehead skin is strictly 0.0 alpha (Zero face leakage) |

---

## 4. Performance Optimization Configuration (Task R3 - Variant P3)
| Parameter | Symbol | Frozen Value | Physical Meaning / Rationale |
| :--- | :--- | :--- | :--- |
| **Texture Linear Scale** | $S_{\text{tex}}$ | 0.50 (1/2 Res) | 4x reduction in pixel count for Laplacian & Box Filter computations |
| **Candidate ROI Margin** | $P_{\text{roi}}$ | 32 px | Bounding box margin around effective hair core and unknown trimap |
| **Laplacian Kernel** | $K_{\text{lap}}$ | 3 x 3 | $K = \begin{bmatrix} 0 & 1 & 0 \\ 1 & -4 & 1 \\ 0 & 1 & 0 \end{bmatrix}$ |
| **Texture Box Radius (Low-Res)**| $r_{\text{low}}$ | 2 px | Equivalent to 5x5 window at native full resolution |
| **Upsample Interpolation** | `Interp` | Bilinear | Smooth interpolation of texture probability map to original resolution |
| **Final Matte Resolution** | `ResMatte` | Native Full-Res | All alpha compositing, guided filtering, and output retain full sub-pixel detail at native resolution |
