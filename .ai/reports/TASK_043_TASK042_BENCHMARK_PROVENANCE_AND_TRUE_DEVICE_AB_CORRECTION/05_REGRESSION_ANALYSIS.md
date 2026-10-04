# 05. FORENSIC REGRESSION ANALYSIS: SHORT WAVY HAIR & CANDIDATE DIRECTIONAL FILTER DEGRADATION

**Task**: `TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION_ACTIVE`  
**Investigated Case**: `portrait_1_male_wavy` (Short wavy hair subject)  
**Hardware Platforms**: Samsung Galaxy A07 & Samsung Galaxy A50s  

---

## 1. The Core Scientific Defect in Candidate V1 Filter

In TASK_042, the report claimed:
> *"Steerable directional flow filtering demonstrated a +13.2% to +38.9% gain in high-frequency strand retention on curly/wavy hair."*

When executed on physical hardware using the actual compiled C++ native harness in TASK_043, an entirely different reality emerges:

### Empirical Measurement Table (`portrait_1_male_wavy`):
- **Baseline A Texture Retention**: **240.9%** (CONVERT2 Frequency Decomposition + Normal Ridge Contrast)
- **Candidate B Texture Retention**: **57.2%** (Candidate V1 1D Directional Steerable Smoothing)
- **Relative Difference**: **-183.7%** (Massive High-Frequency Detail Collapse)
- **Execution Latency**: Baseline A = **55.4ms**, Candidate B = **86.8ms** (+56.7% slower on Helio G99)
- **Exynos 9611 Latency**: Baseline A = **101.4ms**, Candidate B = **119.0ms** (+17.4% slower)

---

## 2. Mathematical Explanation of the Failure

### CONVERT2 Baseline Pipeline A (`HairTextureEngine.cpp`):
CONVERT2 decomposes luminance into low-frequency base and high-frequency details:
$$H(\mathbf{p}) = I_{lum}(\mathbf{p}) - I_{low}(\mathbf{p})$$
Then it computes the normal vector across the hair ridge $\mathbf{n} = (-\sin\theta, \cos\theta)$ and enhances ridge sharpness via second-derivative contrast:
$$R(\mathbf{p}) = 2 \cdot H(\mathbf{p}) - [H(\mathbf{p} + 2\mathbf{n}) + H(\mathbf{p} - 2\mathbf{n})]$$
$$I_{out}(\mathbf{p}) = I_{low}(\mathbf{p}) + H(\mathbf{p}) + 0.35 \cdot R(\mathbf{p})$$
This intentionally boosts strand ridge contrast, preserving crisp wave contours.

### Candidate V1 Pipeline B (`hair_v2_directional_filter.cpp`):
Candidate V1 calculates structure tensor eigenvectors and smooths along tangent:
$$I_{out}(\mathbf{p}) = \sum_{s=-3}^{3} w_s \cdot I_{gray}(\mathbf{p} + s \cdot 0.75 \cdot \mathbf{v}_{tangent})$$
While this works on long straight hair with high coherence ($\kappa > 0.70$), on short wavy hair:
1. Wave curls have a radius of curvature $R_{curv} < 10\text{px}$.
2. Integrating along a 7-pixel line with step 0.75px cuts across adjacent opposing wave crests.
3. Instead of sharpening, the 1D Gaussian kernel acts as a low-pass filter, blurring away micro-waves into muddy, plastic-looking patches.

---

## 3. Visual Confirmation on Physical Devices

High-magnification (400%) inspection of `sm_a075f_portrait_1_male_wavy_zoom_400.png` confirms:
- **Baseline A**: Individual short hair waves, temporal stubble, and sideburn textures remain sharp and distinct.
- **Candidate B**: Waves appear smoothed, strand boundaries are softened, and the hair loses organic depth.
- **Diff Map (5x)**: Shows strong residual energy across the entire hair crown, proving substantial high-frequency loss.

---

## 4. Architectural Verdict & Action Plan

1. **REJECT UNGATED PORTING**: `hair_v2_directional_filter.cpp` CANNOT be ported into production CONVERT2 as a general replacement for `HairTextureEngine`.
2. **CONTENT-GATED PROPOSAL**: If directional filtering is revisited in future phases, it MUST be gated by:
   $$\text{Active if } (\text{strand\_length} > 5.0\text{cm}) \land (\kappa \ge 0.45)$$
   For short hair, male wavy styles, and afro curls, directional smoothing must be strictly bypassed.
