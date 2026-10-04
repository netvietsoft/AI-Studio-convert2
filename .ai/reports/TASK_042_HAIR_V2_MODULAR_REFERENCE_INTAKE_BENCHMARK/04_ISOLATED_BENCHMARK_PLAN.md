# 04. ISOLATED BENCHMARK PLAN — HAIR V2 MODULAR REFERENCE INTAKE

**Task**: TASK_042 — HAIR V2 MODULAR REFERENCE INTAKE & BENCHMARK  
**Authority**: Tony  
**Date**: 2026-10-04  
**Status**: ACTIVE AUDIT & BENCHMARK  

---

## 1. Objective & Governing Policy

The objective of this isolated benchmark is to quantitatively and visually measure candidate algorithms from the 16 V1 `hair_v2_*.cpp` reference files against the current CONVERT2 `HairPipelineV2` implementation.

### Governing Invariants:
1. **Isolated Harness Only**: Benchmarks are executed strictly in a standalone evaluation harness (`scratch/task042/benchmark_harness.py` and `scratch/task042/native_benchmark.cpp`). No production files in `lib-core-graphics/` are modified or replaced during TASK_042.
2. **P0 Model Freeze**: BiSeNet neural networks and preprocessing parameters (`tau_aspect = 1.80`) remain 100% frozen.
3. **Dual Physical Hardware Validation**: All runtime latency and device execution measurements are executed directly on physical Samsung test devices via ADB (`SM-A075F` and `SM-A507FN`).
4. **Human Visual Ground Truth**: Automated metrics are strictly subordinate to owner visual criteria. Any algorithm causing chalky paint (Owner Failure A) or clothing spill (Owner Failure B) is disqualified.

---

## 2. Test Asset Matrix (Canonical Portraits)

The benchmark is conducted across the 9 canonical test portraits established in TASK_031 and TASK_035:

| ID | Portrait Asset | Dimensions | Hair Type / Scene Challenge | Key Gate Evaluated |
|---|---|---|---|---|
| P01 | `owner_fail_A_curly.png` | $960 \times 1280$ | Dark curly hair, high curl depth, hairline skin | Owner Failure A (Chalkiness & Forehead Leak) |
| P02 | `owner_fail_B_orig.png` | $768 \times 1152$ | Blonde hair, sheer black lace sleeve & back | Owner Failure B (Sheer Cloth Spill) |
| P03 | `portrait_1_male_wavy.png` | $576 \times 1280$ | Short wavy male hair, sideburns & neck boundary | Edge Sharpness & Neck Zero-Leakage |
| P04 | `portrait_model1_blonde.png` | $800 \times 1000$ | Long golden blonde hair, fine flyaway strands | Flyaway Strand Fidelity & Bleach Response |
| P05 | `portrait_model2_long_straight.png` | $800 \times 1200$ | Brunette long straight hair, specular highlights | Specular Highlight Sheen & Continuity |
| P06 | `portrait_model3_wavy_curls.png` | $800 \times 1200$ | Auburn wavy hair, intricate shadow crevices | Shadow Crevice Preservation |
| P07 | `portrait_model4_messy_curls.png` | $800 \times 1200$ | Textured messy curls, volume & depth | Texture Laplacian Correlation |
| P08 | `portrait_model6_fringe_bangs.png` | $800 \times 1200$ | Straight bangs across forehead, temple fringe | Forehead Hairline Barrier Gating |
| P09 | `portrait_monk_bald_neg.png` | $500 \times 333$ | Shaved head Buddhist monk (Negative Control) | Bit-Exact Negative Control ($\Delta = 0$) |

---

## 3. Physical Test Hardware Profile

| Specification | Device 1 (Target Runner 1) | Device 2 (Target Runner 2) |
|---|---|---|
| **Model** | Samsung Galaxy A07 (`SM-A075F`) | Samsung Galaxy A50s (`SM-A507FN`) |
| **SoC** | MediaTek Helio G99 (`MT6789`) | Samsung Exynos 9611 |
| **CPU Architecture** | Octa-Core ($2\times$ Cortex-A76 @ 2.2GHz + $6\times$ Cortex-A55 @ 2.0GHz) | Octa-Core ($4\times$ Cortex-A73 @ 2.3GHz + $4\times$ Cortex-A53 @ 1.7GHz) |
| **GPU Architecture** | Mali-G57 MC2 | Mali-G72 MP3 |
| **OS Version** | Android 16 (SDK 36) | Android 11 (SDK 30) |
| **Connection** | ADB over WiFi @ `192.168.1.18:40159` | ADB over WiFi @ `192.168.1.2:41775` |
| **Role in Benchmark** | Modern mid-tier performance reference | Legacy mid-tier thermal/memory baseline |

---

## 4. Evaluated Algorithms & Test Protocols

### Protocol A: Flow Regularization (Axial Double-Angle vs Naive Smoothing)
- **Baseline**: CONVERT2 `HairOrientationEngine` direct orientation smoothing.
- **Candidate**: V1 `regularizeHairFlow` with $(u, v) = (\cos 2\theta, \sin 2\theta)$ coherence weighting.
- **Metric**: Coherence-weighted gradient smoothness:
  $$S = \frac{1}{|M|} \sum_{i \in M} \left( \left|\frac{\partial u}{\partial x}\right| + \left|\frac{\partial v}{\partial y}\right| \right)$$
- **Acceptance Threshold**: Improvement $\ge 30\%$ without angle flipping artifacts.

### Protocol B: Gamut Clipping & Color Fidelity (Soft Chroma Compress vs Hard Clamp)
- **Baseline**: CONVERT2 hard RGB clamping `std::clamp(val, 0.0f, 1.0f)`.
- **Candidate**: V1 `softChromaCompress` with $\tanh$ knee-curve compression above $0.75 \times C_{\max}$.
- **Metric**: CIEDE2000 color difference ($\Delta E_{00}$) between intended salon color and displayed color in highlight zones ($L > 0.70$).
- **Acceptance Threshold**: Reduction in $\Delta E_{00} \ge 15\%$ on high-saturation presets.

### Protocol C: Specular Sheen Realism (Marschner Dual-Lobe vs Single-Lobe)
- **Baseline**: CONVERT2 single-lobe fixed key light model.
- **Candidate**: V1 `computeAnisotropicHairSheen` (dual-lobe primary $R$ + secondary $TRT$ with centroid light estimation).
- **Metric**: Visual sheen naturalness and execution latency on physical hardware.
- **Acceptance Threshold**: Latency overhead $\le 0.05\text{ms}$ on A07/A50s; zero chalkiness.

### Protocol D: Reversibility & Negative Control
- **Condition 1**: `portrait_monk_bald_neg.png` processed through candidate algorithms. Must output bit-exact identical image ($\text{diff}_{\max} = 0$, 0 modified pixels).
- **Condition 2**: Intensity 0% on `owner_fail_A_curly.png`. Must output bit-exact identical image ($\text{diff}_{\max} = 0$, 0 modified pixels).
