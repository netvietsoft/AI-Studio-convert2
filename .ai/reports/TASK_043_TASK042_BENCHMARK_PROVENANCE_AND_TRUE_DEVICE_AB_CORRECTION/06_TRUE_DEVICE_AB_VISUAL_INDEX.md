# 06. TRUE PHYSICAL-DEVICE A/B VISUAL INDEX & PROOF GALLERY

**Task**: `TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION_ACTIVE`  
**Hardware Platforms**: Samsung Galaxy A07 (`SM-A075F`) & Samsung Galaxy A50s (`SM-A507FN`)  
**Standard**: Real Compiled ARM64 Native Output Images (Zero Reused Production Images)  

---

## 1. Samsung Galaxy A07 (SM-A075F) Physical Device Runs

| Test Case | Baseline A Image | Candidate B Image | Amplified Diff (5x) | 400% Hairline Zoom | Latency A / B | Verdict |
|---|---|---|---|---|---|---|
| **Customer 0 (Curly)** | `sm_a075f_portrait_0_curly_A_baseline.png` | `sm_a075f_portrait_0_curly_B_candidate.png` | `sm_a075f_portrait_0_curly_diff_abs.png` | `sm_a075f_portrait_0_curly_zoom_400.png` | 115.2ms / 171.9ms | **REGRESSION_HARD_FAIL** |
| **Male Wavy** | `sm_a075f_portrait_1_male_wavy_A_baseline.png` | `sm_a075f_portrait_1_male_wavy_B_candidate.png` | `sm_a075f_portrait_1_male_wavy_diff_abs.png` | `sm_a075f_portrait_1_male_wavy_zoom_400.png` | 55.4ms / 86.8ms | **REGRESSION_HARD_FAIL** |
| **Model 1 (Blonde)** | `sm_a075f_portrait_model1_blonde_A_baseline.png` | `sm_a075f_portrait_model1_blonde_B_candidate.png` | `sm_a075f_portrait_model1_blonde_diff_abs.png` | `sm_a075f_portrait_model1_blonde_zoom_400.png` | 66.3ms / 92.6ms | **REGRESSION_HARD_FAIL** |
| **Model 2 (Straight)** | `sm_a075f_portrait_model2_long_straight_A_baseline.png` | `sm_a075f_portrait_model2_long_straight_B_candidate.png` | `sm_a075f_portrait_model2_long_straight_diff_abs.png` | `sm_a075f_portrait_model2_long_straight_zoom_400.png` | 106.6ms / 136.6ms | **REGRESSION_HARD_FAIL** |
| **Model 3 (Wavy)** | `sm_a075f_portrait_model3_wavy_curls_A_baseline.png` | `sm_a075f_portrait_model3_wavy_curls_B_candidate.png` | `sm_a075f_portrait_model3_wavy_curls_diff_abs.png` | `sm_a075f_portrait_model3_wavy_curls_zoom_400.png` | 75.0ms / 123.9ms | **REGRESSION_HARD_FAIL** |
| **Model 4 (Messy)** | `sm_a075f_portrait_model4_messy_curls_A_baseline.png` | `sm_a075f_portrait_model4_messy_curls_B_candidate.png` | `sm_a075f_portrait_model4_messy_curls_diff_abs.png` | `sm_a075f_portrait_model4_messy_curls_zoom_400.png` | 70.5ms / 125.4ms | **REGRESSION_HARD_FAIL** |
| **Model 6 (Bangs)** | `sm_a075f_portrait_model6_fringe_bangs_A_baseline.png` | `sm_a075f_portrait_model6_fringe_bangs_B_candidate.png` | `sm_a075f_portrait_model6_fringe_bangs_diff_abs.png` | `sm_a075f_portrait_model6_fringe_bangs_zoom_400.png` | 78.8ms / 107.2ms | **REGRESSION_HARD_FAIL** |
| **Monk (Bald Neg)** | `sm_a075f_portrait_monk_bald_neg_A_baseline.png` | `sm_a075f_portrait_monk_bald_neg_B_candidate.png` | `sm_a075f_portrait_monk_bald_neg_diff_abs.png` | `sm_a075f_portrait_monk_bald_neg_zoom_400.png` | 0.2ms / 0.2ms | **PASS_BIT_EXACT** (`diff=0`) |

---

## 2. Samsung Galaxy A50s (SM-A507FN) Physical Device Runs

| Test Case | Baseline A Image | Candidate B Image | Amplified Diff (5x) | 400% Hairline Zoom | Latency A / B | Verdict |
|---|---|---|---|---|---|---|
| **Customer 0 (Curly)** | `sm_a507fn_portrait_0_curly_A_baseline.png` | `sm_a507fn_portrait_0_curly_B_candidate.png` | `sm_a507fn_portrait_0_curly_diff_abs.png` | `sm_a507fn_portrait_0_curly_zoom_400.png` | 215.8ms / 265.0ms | **REGRESSION_HARD_FAIL** |
| **Male Wavy** | `sm_a507fn_portrait_1_male_wavy_A_baseline.png` | `sm_a507fn_portrait_1_male_wavy_B_candidate.png` | `sm_a507fn_portrait_1_male_wavy_diff_abs.png` | `sm_a507fn_portrait_1_male_wavy_zoom_400.png` | 101.4ms / 119.0ms | **REGRESSION_HARD_FAIL** |
| **Model 1 (Blonde)** | `sm_a507fn_portrait_model1_blonde_A_baseline.png` | `sm_a507fn_portrait_model1_blonde_B_candidate.png` | `sm_a507fn_portrait_model1_blonde_diff_abs.png` | `sm_a507fn_portrait_model1_blonde_zoom_400.png` | 112.6ms / 128.9ms | **REGRESSION_HARD_FAIL** |
| **Model 2 (Straight)** | `sm_a507fn_portrait_model2_long_straight_A_baseline.png` | `sm_a507fn_portrait_model2_long_straight_B_candidate.png` | `sm_a507fn_portrait_model2_long_straight_diff_abs.png` | `sm_a507fn_portrait_model2_long_straight_zoom_400.png` | 128.6ms / 184.0ms | **REGRESSION_HARD_FAIL** |
| **Model 3 (Wavy)** | `sm_a507fn_portrait_model3_wavy_curls_A_baseline.png` | `sm_a507fn_portrait_model3_wavy_curls_B_candidate.png` | `sm_a507fn_portrait_model3_wavy_curls_diff_abs.png` | `sm_a507fn_portrait_model3_wavy_curls_zoom_400.png` | 125.6ms / 168.2ms | **REGRESSION_HARD_FAIL** |
| **Model 4 (Messy)** | `sm_a507fn_portrait_model4_messy_curls_A_baseline.png` | `sm_a507fn_portrait_model4_messy_curls_B_candidate.png` | `sm_a507fn_portrait_model4_messy_curls_diff_abs.png` | `sm_a507fn_portrait_model4_messy_curls_zoom_400.png` | 142.8ms / 150.1ms | **REGRESSION_HARD_FAIL** |
| **Model 6 (Bangs)** | `sm_a507fn_portrait_model6_fringe_bangs_A_baseline.png` | `sm_a507fn_portrait_model6_fringe_bangs_B_candidate.png` | `sm_a507fn_portrait_model6_fringe_bangs_diff_abs.png` | `sm_a507fn_portrait_model6_fringe_bangs_zoom_400.png` | 181.0ms / 156.1ms | **REGRESSION_HARD_FAIL** |
| **Monk (Bald Neg)** | `sm_a507fn_portrait_monk_bald_neg_A_baseline.png` | `sm_a507fn_portrait_monk_bald_neg_B_candidate.png` | `sm_a507fn_portrait_monk_bald_neg_diff_abs.png` | `sm_a507fn_portrait_monk_bald_neg_zoom_400.png` | 0.5ms / 0.6ms | **PASS_BIT_EXACT** (`diff=0`) |

---

## 3. Physical Device Visual Ground Truth Takeaways

1. **True Physical Proof Established**: All 64 PNG files in `raw/images/` represent real, live outputs generated directly on physical devices via `/data/local/tmp/task043_ab/harness_ab_arm64`. No pre-existing images were reused.
2. **Negative Control Robustness**: `portrait_monk_bald_neg` produced 0 modified pixels (`diff_max = 0`) across both devices under both pipelines.
3. **Candidate V1 Directional Filter Flaw Confirmed**: The visual evidence clearly displays softening of wave and curl fibers, validating the formal rejection of ungated directional smoothing.
