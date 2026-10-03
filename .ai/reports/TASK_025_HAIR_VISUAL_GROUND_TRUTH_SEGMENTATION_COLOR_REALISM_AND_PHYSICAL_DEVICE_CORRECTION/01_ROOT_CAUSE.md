# TASK_025 — ROOT CAUSE AUDIT & TECHNICAL POST-MORTEM
**Project:** CONVERT2 — Hair Color Engine V2 Physical Correction  
**Authority:** Tony (Chairman) | **Status:** ACTIVE  
**Auditor:** Agent 0 (CEO / Lead Architect)  
**Scope:** Forensic Root Cause Analysis of Predecessor TASK_022 Visual Rejection & V2 Architectural Remediation  

---

## 1. Executive Summary & Context of Rejection

In TASK_022, while automated unit benchmarks achieved passing numerical scores on mock pipelines, real physical verification on Samsung Galaxy A07 (SM-A075F, Android 16) and Samsung Galaxy A50s (SM-A507FN, Android 11) revealed severe perceptual visual defects.

Owner Tony rejected the visual output as **NEEDS_FIX** with the following definitive critique:
> *"The hair color output resembles a synthetic flat paint overlay or MS Paint bucket fill. Hairline boundaries exhibit harsh stepping and muddy halos, color leaks noticeably into forehead skin pores and ears, and natural strand depth/specular highlights are completely destroyed."*

Under the Hiến Pháp CONVERT (`07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & `AGENTS.md` Rule 2: Evidence-Based Only), no synthetic green test reports are tolerated. A complete forensic audit was conducted on the native C++ codebase (`lib-core-graphics/src/main/cpp/src/hair/`) to isolate the root mechanical and mathematical failures.

---

## 2. Forensic Failure Analysis (Legacy Pipeline V1)

```
[Legacy V1 Pipeline Flow — Critical Failure Nodes]
Input Bitmap
   │
   ├── BiSeNet Parsing (256x256) ──> Bilinear Upsample ──> Muddy boundary / Staircasing
   │                                                             │
   ├── Boundary Clamp: alpha = std::max(alpha, 0.85f) ───────────┴──> [FAILURE 1: Hairline Step Artifact]
   │
   ├── No Skin Exclusion ───────────────────────────────────────────> [FAILURE 2: Forehead & Ear Leakage]
   │
   ├── Constant Melanin Lift: L += (1-L) * bleach * lift ───────────> [FAILURE 3: Flattened Hair Volume]
   │
   └── Double-Intensity Blending: (Chroma * p) then Blend(p*alpha) ─> [FAILURE 4: Muddy Dull Paint Look]
```

### 2.1 Failure 1: Hairline Step Artifact & Halo Boundary
- **Source Location:** `lib-core-graphics/src/main/cpp/src/hair/hair_matting_engine.cpp` (Lines 88–104).
- **Mechanism:** To artificially inflate the apparent hair coverage in synthetic benchmark tests, a hard clamp was introduced:
  ```cpp
  // LEGACY CODE ERROR
  if (dist_to_skin < 3 && alpha > 0.3f) {
      alpha = std::max(alpha, 0.85f); // Forcing 85% opacity creates a razor-sharp unnatural shelf
  }
  ```
- **Visual Consequence:** Along the forehead edge, fine baby hairs and transition wisps were quantized into an 85% opacity plateau. When combined with bilinear upsampling from a 256x256 segmentation map, this produced an unsightly "sawtooth staircasing" and halo around the subject's face.

### 2.2 Failure 2: Forehead, Ear, Neck & Background Leakage
- **Source Location:** `lib-core-graphics/src/main/cpp/src/hair/hair_color_pipeline.cpp` (Lines 142–158).
- **Mechanism:** The legacy pipeline lacked an explicit exclusion gate for facial skin, ears, and clothing. Because BiSeNet segmentation outputs soft probabilities at edges, pixels on the forehead pores, upper ear helix, and collar received low non-zero alpha values ($\alpha \in [0.08, 0.22]$). The shader applied color transformations indiscriminately to any pixel where $\alpha > 0$.
- **Visual Consequence:** Subjects developed pink/golden halos on their foreheads, tinted ear cartilage, and dyed shirt collars.

### 2.3 Failure 3: Constant Melanin Lift & Loss of Strand Depth
- **Source Location:** `lib-core-graphics/src/main/cpp/src/hair/hair_dye_palette.cpp` (Lines 64–79).
- **Mechanism:** The legacy bleach/lift formula applied a linear offset to dark pixels:
  ```cpp
  // LEGACY CODE ERROR
  float lift = (1.0f - L) * bleachAmount * 0.45f;
  L = L + lift;
  ```
- **Visual Consequence:** In real human hair, curl recesses and deep underlayers receive little ambient light ($L \approx 0.05 - 0.15$). Adding a linear boost to all low-luminance pixels indiscriminately raised shadow valleys to midtone gray ($L \approx 0.40$). This completely destroyed the natural shadow occlusion and 3D clumping of curly and wavy hair (Portraits 0, 3, 4), collapsing rich hair volume into a flat 2D sticker.

### 2.4 Failure 4: Double-Intensity Blending & Specular Glint Destruction
- **Source Location:** `lib-core-graphics/src/main/cpp/src/hair/hair_color_pipeline.cpp` (Lines 210–235).
- **Mechanism:** The dye algorithm applied intensity twice:
  1. Inside OKLab space: $a_{dye} = a_{base} + (a_{target} - a_{base}) \times p$.
  2. In sRGB compositing: $RGB_{final} = RGB_{orig} \times (1 - p \cdot \alpha) + RGB_{dye} \times (p \cdot \alpha)$.
  Furthermore, natural specular highlights on glossy hair strands were dyed with 100% saturation.
- **Visual Consequence:** The double multiplication created severe color shifts (muddiness at $p=50\%$, oversaturation at $p=100\%$). Overwriting specular glints transformed shiny, healthy hair into matte, chalky craft paint.

---

## 3. The V2 Architectural Remediation Plan

To permanently solve all four failure modes, `HAIR_PIPELINE_V2` was designed with 10 strictly decoupled stages:

| Stage | Subsystem | Mathematical Solution | Defect Solved |
|---|---|---|---|
| **01** | Input Normalization | Clamp aspect ratio, color profile, zero out-of-bounds | Buffer stability |
| **02** | Hair Segmentation Mask | Multi-class parsing (BiSeNet/Selfie) with P0 contract frozen | Base detection |
| **03** | Edge & Hairline Refinement | Guided Filter ($r=4, \epsilon=0.01$) guided by full-res luma | Step artifact & halo |
| **04** | Exclusion & Protection | Strict suppression: $M_{clean} = M \cdot (1 - M_{skin}) \cdot (1 - M_{bg})$ | Forehead/ear bleed |
| **05** | Strand & Texture Guidance | Laplacian high-pass decomposition ($\ge 95\%$ correlation) | Chalky flat surface |
| **06** | Shadow & Specular Map | Specular preservation mask: $S_{spec} = \text{clamp}((L - 0.75)/0.25, 0, 1)$ | Loss of natural shine |
| **07** | Melanin Lift & Bleach | Non-linear exponential lift modulated by shadow depth | Volume collapse |
| **08** | Salon Dye OKLab Transform | Parabolic chroma curve: $C(L) = C_{dye} \cdot 4 L (1 - L)$ | Paint bucket look |
| **09** | Highlight Preservation | Specular neutrality protection: $Color = (1 - S_{spec}) \cdot Dye + S_{spec} \cdot White$ | Monochromatic helmet |
| **10** | Alpha Composite & Clamp | Energy-conserving sRGB composite with gamut clamp | Double blending |

---

## 4. Verification Gate Criteria
- **Forehead Leakage:** Exactly $0.00\%$ change in facial skin control box.
- **Background / Collar Leakage:** Exactly $0.00\%$ change in image corners.
- **Negative Control (Monk Bald Portrait):** Exactly $0$ modified pixels.
- **Hair Strand Texture Preservation:** Laplacian correlation $\ge 95.0\%$.
- **0% Intensity Identity:** Exactly $0$ modified pixels when slider is set to 0.
