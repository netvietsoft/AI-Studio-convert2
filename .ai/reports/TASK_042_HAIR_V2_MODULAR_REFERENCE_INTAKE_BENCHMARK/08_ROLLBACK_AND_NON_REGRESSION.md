# 08. ROLLBACK & NON-REGRESSION SPECIFICATION

**Task**: TASK_042 — HAIR V2 MODULAR REFERENCE INTAKE & BENCHMARK  
**Authority**: Tony  
**Date**: 2026-10-04  
**Status**: ZERO-REGRESSION PROVENANCE VERIFIED  

---

## 1. Zero Production Modification Guarantee in TASK_042

TASK_042 adheres strictly to the mandate:
> "No production Hair source replacement in TASK_042; implementation of accepted candidates requires a subsequent task."

### Git Production Tree Audit:
```bash
git diff --name-only lib-core-graphics/
# Returns: EMPTY (0 files modified)
```
- No files in `lib-core-graphics/src/main/cpp/` were modified.
- No files in `app/` were modified.
- All benchmark code, scripts, and logs were strictly isolated to `scratch/task042/` and `.ai/reports/TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK/`.

---

## 2. Multi-Tier Rollback Architecture

CONVERT2 maintains a tri-version runtime switch inside `HairPipelineV2`, ensuring that any future port can be instantly rolled back at runtime without recompilation:

```cpp
enum class Version : int {
    VERSION_V1 = 1,          // Legacy Hair V1 (HairStrandDyeEngine)
    VERSION_V2_BASELINE = 2, // Original Hair V2 Baseline (Preserved)
    VERSION_V3_REBUILD = 3   // Rebuilt Hair V3 (Active Production Default)
};
```

### Rollback Switch Guarantees:
1. **Dynamic Version Selection**:
   - `HairPipelineV2::setExecutionVersion(1)`: Instantly falls back to Hair V1 (`HairStrandDyeEngine`).
   - `HairPipelineV2::setExecutionVersion(2)`: Instantly falls back to pristine Hair V2 Baseline.
   - `HairPipelineV2::setExecutionVersion(3)`: Executes current rebuilt Hair V3 pipeline.
2. **Master Enable Toggle**:
   - `HairPipelineV2::setEnabled(false)`: Immediately bypasses all V2/V3 code paths and delegates 100% of processing to legacy C++ native engine.
3. **P0 Frozen Boundary**:
   - BiSeNet preprocessing, neural network tensors, and `tau_aspect = 1.80` remain untouched and isolated behind the `MeituReborn::FusedFaceGeometry` adapter.

---

## 3. Preservation of Tony Owner Visual Defect Fixes

Any downstream port of the 5 approved candidates in `TASK_043` is gated by the following strict non-regression tests:

| Defect Test Case | Baseline Vulnerability | Rebuilt V3 Protection | Non-Regression Test Gate in TASK_043 |
|---|---|---|---|
| **Owner Case A** (`owner_fail_A_curly.png`) | Flat opaque paint, loss of curl depth, pigment on forehead skin | OKLab midtone bell-curve ($4L(1-L)$), high-frequency fiber injection, Cr/Cb skin barrier | **Forehead skin leakage must be 0.00%**. Laplacian texture correlation $\ge 90.0\%$. Zero chalkiness. |
| **Owner Case B** (`owner_fail_B_orig.png`) | Sheer black sleeve/torso misclassified as hair, red dye spill | Cranial crown seed anchor ($y \le \min(f_y) + 0.08h$), OKLab appearance clustering, BFS reachability | **Cloth spill below torso ($Y \ge 834$) must be 0 modified pixels**. Scalp hair color distance $\Delta E \le 2.80$. |
| **Monk Negative Control** (`portrait_monk_bald_neg.png`) | False positive hair detection on bald scalp | Zero alpha gate if hair area ratio $< 0.005$ | **Bit-exact identity required**: $\text{diff}_{\max} = 0$, 0 modified pixels. |
| **Intensity Sweep 0%** (`owner_fail_A_curly.png`) | Alpha compositing rounding drift | Direct pointer bypass when intensity $= 0.0$ | **Bit-exact identity required**: $\text{diff}_{\max} = 0$, 0 modified pixels. |

---

## 4. Verification & Validation Protocol for Subsequent Tasks

Prior to any commit in `TASK_043`:
1. Compile APK with `--no-daemon`.
2. Deploy to both Samsung test devices (`SM-A075F` and `SM-A507FN`).
3. Run automated 20-case test matrix (`run_task_035_dual_device_acceptance.py`).
4. Pull 400% zoom crops of hairline skin and sheer lace sleeve.
5. Compute numerical diffs against TASK_035 baseline outputs.
6. Verify that no regression occurs on any metric.
