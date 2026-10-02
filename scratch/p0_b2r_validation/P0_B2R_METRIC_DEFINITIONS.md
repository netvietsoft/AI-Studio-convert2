# P0-B.2R METRIC DEFINITIONS & SPECIFICATION

**Phase:** P0-B.2R — Final Evidence Correction & Freeze  
**Document:** `P0_B2R_METRIC_DEFINITIONS.md`  
**Purpose:** Formally specify definitions, equations, Regions of Interest (ROI), denominators, numerators, null policies, and pipeline stages for all metrics in the P0-B.2R validation package.

---

## 1. Pipeline Stages & Metric Categorization

In Phase P0-B.2R, metrics are measured at two distinct stages in the execution graph:

```
[RAW IMAGE]
     │
     ▼
[STAGE 1: GEOMETRY EXPERIMENT STAGE]
  • Evaluated in: `scratch/run_p0_b2r_geometry_ab.py`
  • Pipeline: BiSeNet (Mode A/B/C) ➔ Fast Guided Filter ➔ Local Color Affinity
  • Measures direct impact of letterboxing/aspect preservation in isolating Class 18 false positives.
  • Metric: `GEOMETRY_STAGE_BACKGROUND_LEAKAGE`
     │
     ▼
[STAGE 2: FINAL PIPELINE STAGE]
  • Evaluated in: `scratch/run_p0_b2r_full_suite.py`
  • Pipeline: BiSeNet (Mode B) ➔ LowContrastHairResolver (P3) ➔ SubjectGraph 
              ➔ ImageContentGuard ➔ Semantic Trimap ➔ Fast Guided Filter 
              ➔ Local Color Affinity ➔ Strict Semantic & UI Protection ➔ Hairline Refinement
  • Measures authoritative final alpha matte delivered to downstream rendering.
  • Metric: `FINAL_PIPELINE_BACKGROUND_LEAKAGE`
```

---

## 2. Formal Metric Schema

Every metric in the validation package adheres to the following formal schema:

```
MetricRecord {
    metric_name: String,
    sample_id: String,
    pipeline_stage: Enum [GEOMETRY_EXPERIMENT_STAGE, FINAL_PIPELINE_STAGE, BENCHMARK_STAGE],
    algorithm_variant: String,
    numerator_pixels: Integer / Float,
    denominator_pixels: Integer,
    value_raw: Float,
    value_percent: Float,
    roi_definition: String,
    mask_definition: String,
    null_policy: String,
    source_file: String,
    source_function: String,
    artifact_version: String
}
```

---

## 3. Comprehensive Metric Definitions

### 3.1 GEOMETRY_STAGE_BACKGROUND_LEAKAGE
- **Symbol:** $\Lambda_{\text{bg}}^{\text{geom}}$
- **Pipeline Stage:** `GEOMETRY_EXPERIMENT_STAGE`
- **Definition:** The mean alpha value across pixels categorized as background ($L_{\text{semantic}} = 0$) directly after Guided Filtering and Color Affinity, before UI Chrome Guard and Semantic Protection.
- **Formula:**
  $$\Lambda_{\text{bg}}^{\text{geom}} = \frac{1}{|\mathcal{R}_{\text{bg}}^{\text{geom}}|} \sum_{i \in \mathcal{R}_{\text{bg}}^{\text{geom}}} \alpha_i \times 100\%$$
- **Numerator:** $\sum_{i \in \mathcal{R}_{\text{bg}}^{\text{geom}}} \alpha_i$ (cumulative alpha energy on background).
- **Denominator:** $|\mathcal{R}_{\text{bg}}^{\text{geom}}| = \sum [L_{\text{full}} == 0]$ (total pixel count where full-resolution semantic label is background Class 0).
- **ROI Definition:** Pixels where BiSeNet semantic label is 0 (Background) under the specific geometry mode (A, B, or C).
- **Source File:** `scratch/run_p0_b2r_geometry_ab.py`
- **Source Function:** `process_geometry_ab()` (lines 167-170)
- **Primary Use:** Evaluating the raw geometric efficacy of Mode B letterbox vs Mode A squish and Mode C ROI.

---

### 3.2 FINAL_PIPELINE_BACKGROUND_LEAKAGE
- **Symbol:** $\Lambda_{\text{bg}}^{\text{final}}$
- **Pipeline Stage:** `FINAL_PIPELINE_STAGE`
- **Definition:** The mean alpha value across background pixels ($L_{\text{semantic}} = 0$) of the final alpha matte $\alpha_{\text{final}}$, after SubjectGraph topological filtering, ImageContentGuard UI chrome rejection, and strict semantic zeroing.
- **Formula:**
  $$\Lambda_{\text{bg}}^{\text{final}} = \frac{1}{|\mathcal{R}_{\text{bg}}^{\text{final}}|} \sum_{i \in \mathcal{R}_{\text{bg}}^{\text{final}}} \alpha_{\text{final}, i} \times 100\%$$
- **Numerator:** $\sum_{i \in \mathcal{R}_{\text{bg}}^{\text{final}}} \alpha_{\text{final}, i}$.
- **Denominator:** $|\mathcal{R}_{\text{bg}}^{\text{final}}| = \sum [L_{\text{full}} == 0]$.
- **ROI Definition:** All pixels labeled Class 0 in the master full-resolution label map.
- **Source File:** `scratch/run_p0_b2r_full_suite.py`
- **Source Function:** `main()` (line 1058)
- **Primary Use:** Authoritative gate decision for P0-B.2R Master Suite (`P0_B2R_METRICS.csv`).

---

### 3.3 UI_LEAKAGE (FINAL_PIPELINE_UI_LEAKAGE)
- **Symbol:** $\Lambda_{\text{ui}}$
- **Pipeline Stage:** `FINAL_PIPELINE_STAGE`
- **Definition:** The mean alpha value within the peripheral UI Chrome Reject mask ($M_{\text{ui\_reject}}$).
- **Formula:**
  $$\Lambda_{\text{ui}} = \begin{cases} \frac{1}{|\mathcal{M}_{\text{ui}}|} \sum_{i \in \mathcal{M}_{\text{ui}}} \alpha_{\text{final}, i} \times 100\%, & \text{if } |\mathcal{M}_{\text{ui}}| > 0 \\ 0.000\%, & \text{if } |\mathcal{M}_{\text{ui}}| = 0 \end{cases}$$
- **Numerator:** Cumulative alpha in UI region.
- **Denominator:** $|\mathcal{M}_{\text{ui}}|$ (total pixels flagged as top/bottom screen UI chrome by `ImageContentGuard`).
- **Gate:** $\Lambda_{\text{ui}} \le 1.0\%$.

---

### 3.4 HAIR_CORE_PRESERVATION (P0B2R_CorePres)
- **Symbol:** $\Pi_{\text{core}}$
- **Pipeline Stage:** `FINAL_PIPELINE_STAGE`
- **Definition:** The percentage of pixels in the hair core reference mask ($\mathcal{M}_{\text{core\_ref}}$) where the final alpha matte exceeds the core threshold ($\alpha_{\text{final}} \ge 0.50$).
- **Formula:**
  $$\Pi_{\text{core}} = \frac{\sum_{i \in \mathcal{M}_{\text{core\_ref}}} [\alpha_{\text{final}, i} \ge 0.50]}{|\mathcal{M}_{\text{core\_ref}}|} \times 100\%$$
- **Gate:** $\Pi_{\text{core}} \ge 75.0\%$ for standard and high-exposure samples (e.g. `sample_05`, `sample_26`).

---

### 3.5 FACE_LEAKAGE
- **Symbol:** $\Lambda_{\text{face}}$
- **Pipeline Stage:** `FINAL_PIPELINE_STAGE`
- **Definition:** Mean alpha value within facial organ semantic classes (Labels 4, 5: Eyes; Label 10: Nose; Label 11: Upper Lip).
- **Null Policy:** If no pixels belong to the specified facial organ classes (e.g. cropped hair textures, back-of-head shots, bald scalp close-ups), the denominator is 0. Under the canonical null policy, this is reported as `NA` (Not Applicable).
- **Gate:** $\Lambda_{\text{face}} \le 0.100\%$.

---

### 3.6 EAR_LEAKAGE
- **Symbol:** $\Lambda_{\text{ear}}$
- **Pipeline Stage:** `FINAL_PIPELINE_STAGE`
- **Definition:** Mean alpha value within ear semantic classes (Labels 7, 8: Left/Right Ear) excluding verified Hair-Over-Ear pixels.
- **Null Policy:** If ear pixels are absent from the image or 100% occluded by hair strands, denominator is 0. Reported as `NA`.
- **Gate:** $\Lambda_{\text{ear}} \le 0.100\%$.

---

## 4. Null & Missing Value Policy
1. **Definition of NA:** A metric field takes the value `NA` if and only if the physical semantic class or region of interest defining its denominator contains 0 pixels in that specific image.
2. **Disallowed Representations:** `nan%`, `#DIV/0!`, `null`, and `-1.0%` are strictly invalid.
3. **Data Integrity Guarantee:** Transforming `nan%` $\rightarrow$ `NA` is a serialization normalization; it does not modify underlying pixel values or gate verdicts.
