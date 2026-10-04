# Recommended Ingestion and Analysis Order for TASK_038 and Downstream Reconstruction

To maximize code reuse, eliminate redundant reimplementation, and maintain mathematical and pixel-level fidelity, downstream tasks (especially TASK_038 and Phase P2–P5 deep integrations) should ingest resources from `F:\CONVERT` in the following strict priority sequence.

---

## Priority Order Matrix

| Ingestion Phase | Target Source Path | Artifact Type | Downstream Destination in CONVERT2 | Objective / Rationale |
|---|---|---|---|---|
| **Phase 1: Immediate JNI & C++ Harvest** | `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge` | C++ source & JNI headers | `lib-core-graphics/src/main/cpp/` | Harvest `ncnn_face_engine.cpp`, `portrait_matting.cpp`, `semantic_zero_leakage_guard.cpp`, and JNI method tables. Eliminates rewriting existing C++ code. |
| **Phase 2: Hair Test Suites Migration** | `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge/src/test` | Kotlin unit tests | `lib-photo-editor/src/test/` | Port 18 automated test suites (`HairMattingAndRecolorPipelineTest.kt`, etc.) to establish regression test gates. |
| **Phase 3: Render Graph & Shaders** | `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\render` | GLSL shaders & FBO engine | `lib-core-graphics/src/main/cpp/render/` | Integrate multi-pass render graph and ping-pong FBO pipeline for hair recoloring shader passes. |
| **Phase 4: Vendor Symbol Descriptors** | `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src\sources\com\meitu` | Decompiled Java interfaces | `lib-core-graphics/src/main/java/com/meitu/` | Extract exact method signatures and type descriptors for calling into `libMTFilterKernel.so` and `libarkernel3.so`. |
| **Phase 5: Material LUT Ingestion** | `F:\CONVERT\Material Image Editor\Mitu\material\filter` | 3D LUT PNGs & JSON configs | `app/src/main/assets/lut/` | Ingest authentic Meitu hair dye LUT tables (IDs 2014, 2038, 2043, 3012, 4001, 5002) for exact color matching. |
| **Phase 6: Facetune Retouch Cross-Validation** | `F:\CONVERT\com.lightricks.facetune.free\CONVERT\feature-ai-retouch` | C++ retouch & NCNN models | Benchmark reference only | Benchmark frequency separation and hair strand edge filtering against Facetune's native algorithms. |

---

## Gating Criteria for Downstream Tasks

1. **Gate 1 (Zero Header Drift):** When porting JNI bindings from `CONVERT/native-bridge`, verify that native function signatures match both `jadx_src` decompiled classes and `libmeitu_reborn_native.so` symbol tables.
2. **Gate 2 (Automated Test Pass):** All 18 ported test suites must pass on host JVM before device deployment.
3. **Gate 3 (Device Hardware Verification):** All hair dye shaders and native calls must run with $\le 5$ ms latency on Samsung Galaxy A50 (SM-A075F).
