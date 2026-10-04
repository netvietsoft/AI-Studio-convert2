# 08. ROLLBACK & NON-REGRESSION GUARANTEES

**Task ID**: `TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK_ACTIVE`  
**Date**: 2026-10-04 12:29:05 +0700  
**Governing Standard**: Development Workspace Standard V2.1  

---

## 1. Zero-Mutation Principle of TASK_042

TASK_042 was strictly scoped as an **intake audit and isolated benchmark**. No production code in `lib-core-graphics` or `app` was modified, deleted, or replaced.

```
+--------------------------------------------------------------------------+
|                     CONVERT2 PRODUCTION REPOSITORY                       |
|                                                                          |
|   lib-core-graphics/src/main/cpp/src/hair/hair_pipeline_v2.cpp [UNTOUCHED] |
|   lib-core-graphics/src/main/cpp/src/hair/hair_gpu_backend.cpp [UNTOUCHED] |
|   lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp   [UNTOUCHED] |
|   CMakeLists.txt                                               [UNTOUCHED] |
+--------------------------------------------------------------------------+
                                     |
                                     | (Strict Read-Only Reference)
                                     v
+--------------------------------------------------------------------------+
|                     ISOLATED BENCHMARK ENVIRONMENT                       |
|                                                                          |
|   scratch/task042/run_isolated_benchmarks.py                             |
|   .ai/reports/TASK_042_HAIR_V2_MODULAR_REFERENCE_INTAKE_BENCHMARK/       |
+--------------------------------------------------------------------------+
```

---

## 2. Architectural Rollback Controls for Future Integration

When the recommended candidates from `07_RECOMMENDED_PORT_SET.md` are integrated in subsequent tasks, the following architectural controls guarantee instantaneous rollback:

1. **Pipeline Execution Version Enum**:
   `HairPipelineV2` in CONVERT2 already contains execution version gating:
   ```cpp
   enum class Version {
       VERSION_V1_LEGACY = 1,
       VERSION_V2_BASELINE = 2,
       VERSION_V3_REBUILD = 3,       // Active Production
       VERSION_V4_MODULAR_ENHANCED = 4 // Target for Recommended Ports
   };
   ```
   If `VERSION_V4_MODULAR_ENHANCED` exhibits any regression on device, setting `HairPipelineV2::getInstance().setExecutionVersion(3)` instantly rolls back to the proven V3 Rebuild.

2. **Feature Flag Granularity**:
   Each candidate port will be gated by an atomic boolean flag in `HairV2Config`:
   - `config.enableDirectionalFilter` (Default: false until verified)
   - `config.enableSoftKneeChroma` (Default: false until verified)
   - `config.enableMarschnerSpecular` (Default: false until verified)
   - `config.enableLandmarkBarrier` (Default: false until verified)

---

## 3. P0 Frozen Boundary Protection Guarantee

- **Rule 1**: The threshold `tau_aspect = 1.80` is immutable.
- **Rule 2**: BiSeNet 19-class model weights and input preprocessing ($512\times 512$ normalized tensors) are immutable.
- **Verification**: TASK_042 verified that all recommended candidate ports operate downstream of BiSeNet inference, consuming only the resulting probability maps. P0 integrity is preserved at 100%.
