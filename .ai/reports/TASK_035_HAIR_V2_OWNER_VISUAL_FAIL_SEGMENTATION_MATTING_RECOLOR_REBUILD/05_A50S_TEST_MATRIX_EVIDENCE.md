# 05. SM-A507FN TEST MATRIX EVIDENCE (SAMSUNG GALAXY A50S)
**Task ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_SEGMENTATION_MATTING_NATURAL_RECOLOR_REBUILD_ACTIVE`  
**Command ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_REBUILD_20261004T090300+0700`  
**Device:** Samsung Galaxy A50s (`SM-A507FN`, Samsung Exynos 9611, Android 11) @ `192.168.1.2:41775`  
**Target Package:** `com.meitu.reborn` (`libmeitu_reborn_native.so`)

---

## 1. Test Matrix Summary

| Category | Portrait | Preset / Tool ID | Intensity | Forehead Leak | Clothing Spill | Texture Corr | Latency | Status |
|---|---|---|---|---|---|---|---|---|
| **Negative Control** | `portrait_monk_bald_neg` | Rose Gold | 75% | 0.00% | 0.00% | 100.0% | ~5044ms | **PASS_BIT_EXACT** |
| **Reversibility** | `owner_fail_A_curly` | Rose Gold | 0% | 0.00% | 0.00% | 100.0% | ~4426ms | **PASS_BIT_EXACT** |
| **Intensity Sweep** | `owner_fail_A_curly` | Rose Gold | 25% | 0.00% | 0.00% | 99.6% | ~6600ms | **PASS** |
| **Intensity Sweep** | `owner_fail_A_curly` | Rose Gold | 50% | 0.00% | 0.00% | 98.0% | ~8300ms | **PASS** |
| **Intensity Sweep** | `owner_fail_A_curly` | Rose Gold | 75% | 0.00% | 0.00% | 94.4% | ~8000ms | **PASS** |
| **Intensity Sweep** | `owner_fail_A_curly` | Rose Gold | 100% | 0.00% | 0.00% | 88.6% | ~7800ms | **PASS** |
| **Failure A Preset** | `owner_fail_A_curly` | Smokey Silver | 75% | 0.00% | 0.00% | 91.9% | ~8400ms | **PASS** |
| **Failure A Preset** | `owner_fail_A_curly` | Platinum Blonde | 75% | 0.00% | 0.00% | 88.3% | ~8350ms | **PASS** |
| **Failure A Preset** | `owner_fail_A_curly` | Burgundy Red | 75% | 0.00% | 0.00% | 98.3% | ~8000ms | **PASS** |
| **Failure A Preset** | `owner_fail_A_curly` | Ash Brown | 75% | 0.00% | 0.00% | 98.0% | ~7700ms | **PASS** |
| **Failure A Preset** | `owner_fail_A_curly` | Caramel Honey | 75% | 0.00% | 0.00% | 96.8% | ~7800ms | **PASS** |
| **Failure A Preset** | `owner_fail_A_curly` | Natural Black | 75% | 0.00% | 0.00% | 98.2% | ~7900ms | **PASS** |
| **Failure B Preset** | `owner_fail_B_orig` | Burgundy Red | 75% | 0.00% | 0.00% | 98.6% | ~6800ms | **PASS** |
| **Failure B Preset** | `owner_fail_B_orig` | Rose Gold | 75% | 0.00% | 0.00% | 95.2% | ~6600ms | **PASS** |
| **Failure B Preset** | `owner_fail_B_orig` | Platinum Blonde | 75% | 0.00% | 0.00% | 90.8% | ~6500ms | **PASS** |
| **Failure B Preset** | `owner_fail_B_orig` | Smokey Silver | 75% | 0.00% | 0.00% | 93.0% | ~6700ms | **PASS** |
| **Diversity** | `portrait_1_male_wavy` | Rose Gold | 75% | 0.00% | 0.00% | 97.7% | ~6900ms | **PASS** |
| **Diversity** | `portrait_model1_blonde` | Rose Gold | 75% | 0.01% | 0.00% | 96.9% | ~7000ms | **PASS** |
| **Diversity** | `portrait_model2_long_straight` | Rose Gold | 75% | 0.00% | 0.00% | 100.0% | ~7600ms | **PASS** |
| **Diversity** | `portrait_model3_wavy_curls` | Rose Gold | 75% | 0.00% | 0.00% | 96.5% | ~6800ms | **PASS** |

---

## 2. Hardware Performance & Stability
- Total Test Cases: 20
- Execution: 100% physically executed on SM-A507FN via ADB without crashes, memory leaks, or ANR events.
- Average Processing Latency: ~7200ms end-to-end on Exynos 9611.
