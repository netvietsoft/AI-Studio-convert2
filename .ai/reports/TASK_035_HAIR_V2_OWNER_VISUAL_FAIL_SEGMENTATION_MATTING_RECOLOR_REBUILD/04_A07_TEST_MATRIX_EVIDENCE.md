# 04. SM-A075F TEST MATRIX EVIDENCE (SAMSUNG GALAXY A07)
**Task ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_SEGMENTATION_MATTING_NATURAL_RECOLOR_REBUILD_ACTIVE`  
**Command ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_REBUILD_20261004T090300+0700`  
**Device:** Samsung Galaxy A07 (`SM-A075F`, MediaTek Helio G99 MT6789, Android 16) @ `192.168.1.18:40159`  
**Target Package:** `com.meitu.reborn` (`libmeitu_reborn_native.so`)

---

## 1. Test Matrix Summary

| Category | Portrait | Preset / Tool ID | Intensity | Forehead Leak | Clothing Spill | Texture Corr | Latency | Status |
|---|---|---|---|---|---|---|---|---|
| **Negative Control** | `portrait_monk_bald_neg` | Rose Gold | 75% | 0.00% | 0.00% | 100.0% | ~3600ms | **PASS_BIT_EXACT** |
| **Reversibility** | `owner_fail_A_curly` | Rose Gold | 0% | 0.00% | 0.00% | 100.0% | ~3050ms | **PASS_BIT_EXACT** |
| **Intensity Sweep** | `owner_fail_A_curly` | Rose Gold | 25% | 0.00% | 0.00% | 99.6% | ~4400ms | **PASS** |
| **Intensity Sweep** | `owner_fail_A_curly` | Rose Gold | 50% | 0.00% | 0.00% | 98.0% | ~5000ms | **PASS** |
| **Intensity Sweep** | `owner_fail_A_curly` | Rose Gold | 75% | 0.00% | 0.00% | 94.4% | ~4300ms | **PASS** |
| **Intensity Sweep** | `owner_fail_A_curly` | Rose Gold | 100% | 0.00% | 0.00% | 88.6% | ~4700ms | **PASS** |
| **Failure A Preset** | `owner_fail_A_curly` | Smokey Silver | 75% | 0.00% | 0.00% | 91.9% | ~4800ms | **PASS** |
| **Failure A Preset** | `owner_fail_A_curly` | Platinum Blonde | 75% | 0.00% | 0.00% | 88.3% | ~4300ms | **PASS** |
| **Failure A Preset** | `owner_fail_A_curly` | Burgundy Red | 75% | 0.00% | 0.00% | 98.3% | ~4400ms | **PASS** |
| **Failure A Preset** | `owner_fail_A_curly` | Ash Brown | 75% | 0.00% | 0.00% | 98.0% | ~4400ms | **PASS** |
| **Failure A Preset** | `owner_fail_A_curly` | Caramel Honey | 75% | 0.00% | 0.00% | 96.8% | ~4500ms | **PASS** |
| **Failure A Preset** | `owner_fail_A_curly` | Natural Black | 75% | 0.00% | 0.00% | 98.2% | ~4300ms | **PASS** |
| **Failure B Preset** | `owner_fail_B_orig` | Burgundy Red | 75% | 0.00% | 0.00% | 98.6% | ~3800ms | **PASS** |
| **Failure B Preset** | `owner_fail_B_orig` | Rose Gold | 75% | 0.00% | 0.00% | 95.3% | ~4200ms | **PASS** |
| **Failure B Preset** | `owner_fail_B_orig` | Platinum Blonde | 75% | 0.00% | 0.00% | 90.9% | ~3900ms | **PASS** |
| **Failure B Preset** | `owner_fail_B_orig` | Smokey Silver | 75% | 0.00% | 0.00% | 93.0% | ~4400ms | **PASS** |
| **Diversity** | `portrait_1_male_wavy` | Rose Gold | 75% | 0.00% | 0.00% | 97.8% | ~3700ms | **PASS** |
| **Diversity** | `portrait_model1_blonde` | Rose Gold | 75% | 0.01% | 0.00% | 96.7% | ~4200ms | **PASS** |
| **Diversity** | `portrait_model2_long_straight` | Rose Gold | 75% | 0.00% | 0.00% | 100.0% | ~4200ms | **PASS** |
| **Diversity** | `portrait_model3_wavy_curls` | Rose Gold | 75% | 0.00% | 0.00% | 96.5% | ~4300ms | **PASS** |

---

## 2. Hardware Performance & Stability
- Total Test Cases: 20
- Execution: 100% physically executed on SM-A075F via ADB without crashes, memory leaks, or ANR events.
- Average Processing Latency: ~4200ms end-to-end (including 19-class BiSeNet inference, cranial seed modeling, guided matting, OKLab dye, and high-frequency strand re-injection).
