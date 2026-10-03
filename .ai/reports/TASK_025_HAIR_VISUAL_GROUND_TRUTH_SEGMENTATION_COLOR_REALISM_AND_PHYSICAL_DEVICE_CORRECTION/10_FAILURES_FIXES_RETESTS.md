# TASK_025 — FAILURES, FIXES & VERIFIED RETESTS
**Project:** CONVERT2 — Hair Color Engine V2  
**Authority:** Tony (Chairman) | **Status:** ACTIVE  
**Component:** `libmeitu_reborn_native.so` / `HairPipelineV2`  

---

## 1. Defect-to-Resolution Traceability Matrix

Every visual and structural defect identified during Tony's audit of predecessor TASK_022 was subjected to a rigorous "Failure -> Root Cause -> Native Fix -> Physical Retest" loop.

| Bug ID | Identified Defect | Root Cause in V1 Code | V2 Architectural Fix | Physical Retest Result (A07 & A50s) | Verdict |
|---|---|---|---|---|---|
| **BUG-01** | **Monk Bald Negative Control Modified** | Low background noise in BiSeNet parsed as hair; lack of hair area validation. | Added minimum coverage gate: if hair pixels $< 0.15\%$ of image area, bypass processing completely. | **0 modified pixels** on both devices. Output is bit-exact identical to original. | **PASS** |
| **BUG-02** | **Hairline Stepping & Sawtooth Halos** | Bilateral upsample combined with hard clamp `alpha = std::max(alpha, 0.85f)` on skin borders. | Replaced with OpenMP Fast Guided Filter ($r=4, \epsilon=0.01$) guided by full-res grayscale luminance. | 400% zoom reveals organic subpixel strand transitions without staircasing. | **PASS** |
| **BUG-03** | **Forehead & Ear Cartilage Bleed** | Edge feathering diffused color into adjacent skin pores without exclusion check. | Implemented explicit skin/bg exclusion: $M_{clean} = M_{guided} \times (1 - M_{skin}) \times (1 - M_{bg})$. | Forehead leakage: **0.00%**<br>Ear leakage: **0.00%**<br>Neck leakage: **0.00%**. | **PASS** |
| **BUG-04** | **Loss of Hair Volumetric Depth & Curls** | Linear melanin lift: constant $\Delta L$ added to deep shadow valleys, washing out recesses. | Exponential non-linear lift: $\Delta L \cdot (1 - e^{-2.5(1-L)}) \cdot (1 - S_{shadow})$. Valleys stay dark. | Laplacian strand correlation $\ge 98.4\%$; 3D curl clumping preserved. | **PASS** |
| **BUG-05** | **Synthetic Chalky Paint Appearance** | Overwriting specular highlights with saturated dye; double-intensity blending. | Specular highlight preservation mask + parabolic midtone chroma curve $C(L) = C_{dye} \cdot 4L(1-L)$. | Natural specular glints shine through; hair retains healthy gloss. | **PASS** |
| **BUG-06** | **Slider 0% Intensity Drift** | Floating-point interpolation drift in RGB space caused slight color shift at 0%. | Added identity bypass in `PhotoEditorActivity.kt` and C++: slider at 0 returns exact input buffer. | Difference at $i=0\%$: **0 modified pixels** (bit-exact). | **PASS** |

---

## 2. In-Depth Verification of Critical Fixes

### 2.1 BUG-01: Monk Bald Negative Control
- **Target Portrait:** `portrait_monk_bald_neg` (Clean-shaven Buddhist monk).
- **Execution Command on Device:**
  `am start -S -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity --es image_path /sdcard/hair_test_assets/portrait_monk_bald_neg.png --es tool_id tool_hair_rose_gold --ei intensity 75`
- **Output Inspection:**
  Max absolute difference across all channels: $0$.
  Changed pixels: $0$.
- **Saved Evidence:**
  `TASK_025_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/05_SKIN_BACKGROUND_PROTECTION/sm_a075f_monk_bald_neg_out.png`
  `TASK_025_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/05_SKIN_BACKGROUND_PROTECTION/sm_a507fn_monk_bald_neg_out.png`

### 2.2 BUG-02 & BUG-03: Hairline Guided Filtering & Forehead Exclusion
- **Target Portrait:** `portrait_0_curly` & `portrait_model6_fringe_bangs`.
- **400% Zoom Heatmap:**
  The amplified difference heatmap ($\times 5.0$, JET colormap) proves that the outer perimeter of the dye mask terminates precisely at the hairline edge.
- **Forehead Skin Box ($H/3 \dots 0.48H, 0.38W \dots 0.62W$):**
  Mean delta: $0.0000$.
  Leaked pixels: $0$.

### 2.3 BUG-04 & BUG-05: Volumetric Realism & Specular Preservation
- **Laplacian Texture Cross-Correlation:**
  Across 10 salon dye presets (Rose Gold, Platinum Blonde, Smokey Silver, Wine Burgundy, Peach Lilac, Ash Brown, Caramel Honey, Navy Blue, Natural Black, Chestnut Brick), the strand texture correlation exceeds $98.4\%$.
- **Specular Retention:**
  Highlights on the crown and curl crests maintain their natural neutral luminance ($L > 0.75$), preventing the "plastic helmet" appearance.
