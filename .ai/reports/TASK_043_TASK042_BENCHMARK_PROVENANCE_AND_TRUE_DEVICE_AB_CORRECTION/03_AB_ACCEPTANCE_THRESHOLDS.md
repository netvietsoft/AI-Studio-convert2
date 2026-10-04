# 03. A/B ACCEPTANCE THRESHOLDS & PRE-ESTABLISHED PASS/FAIL GATES

**Task**: `TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION_ACTIVE`  
**Governing Standard**: `Yeucau_Test_anh.txt` & Development Workspace Standard V2.1  
**Principle**: All acceptance criteria must be declared *prior* to evaluation. No post-hoc threshold adjustment is permitted.

---

## 1. Quantitative Benchmark Acceptance Thresholds

| Metric | Target Value | Hard Regression Boundary (FAIL) | Rationale |
|---|---|---|---|
| **Texture Retention ($T_{ret}$)** | $\ge 80.0\%$ | $T_{gain} < -5.0\%$ on any portrait | Preserves hair fiber ridge sharpness; hair must not look smudged or airbrushed. |
| **Monk Bald Negative Control** | `diff_max == 0` | `diff_max > 0` (even 1 pixel) | Absolute zero tolerance for false positive hair dye on bald subjects. |
| **Forehead Skin Leakage** | $\le 0.20\%$ | $> 0.50\%$ LSB shift | Prevents dye bleeding onto face contours. |
| **Clothing / Torso Spill** | $\le 0.50\%$ | $> 1.00\%$ LSB shift | Protects collars, shirts, and background elements. |
| **Highlight Clipping ($C_{high}$)** | $C_{B} \le C_{A}$ | $C_{B} > C_{A}$ (increased blowouts) | Candidate color compression must not create additional blown pixels. |
| **Color Fidelity (CIEDE2000 $\Delta E$)** | $\Delta E \le 2.0$ | $\Delta E > 3.5$ (perceptible hue shift) | Candidate processing must preserve intended salon dye hue (Rose Gold). |
| **Execution Latency Budget** | $\le 300\text{ms}$ on device | $> 450\text{ms}$ on Helio G99 / Exynos 9611 | Must maintain smooth interactive frame rendering on mid-range Android devices. |

---

## 2. Gate Decision Rules

1. **PASS_TEXTURE_IMPROVED**: $T_{gain} \ge 0.0\%$ with zero leakage and `diff_max == 0`.
2. **PASS_WITHIN_TOLERANCE**: $-5.0\% \le T_{gain} < 0.0\%$ with zero leakage and `diff_max == 0`.
3. **REGRESSION_HARD_FAIL**: $T_{gain} < -5.0\%$ on any canonical portrait. The candidate module must be **rejected** or **content-gated**.
4. **FAIL_NEGATIVE_CONTROL**: Any modification to `portrait_monk_bald_neg` triggers immediate disqualification.
