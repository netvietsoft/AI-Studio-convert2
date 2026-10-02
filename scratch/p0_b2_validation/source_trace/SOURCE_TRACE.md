# P0-B.2 SOURCE TRACEABILITY MATRIX

## 1. Executive Summary & Traceability Protocol
All claims, algorithms, metrics, and benchmarks in Phase P0-B.2 are strictly verified against actual codebase artifacts and hardware executions on the physical Samsung Galaxy SM-A075F reference device.

---

## 2. Source Code Locations & Scope Isolation
| Component | Physical File Path | Role | Verification Status |
| :--- | :--- | :--- | :--- |
| **Production Hair Engine** | `lib-core-graphics/src/main/cpp/src/hair_engine.cpp` | Production Hair Color pipeline | **FROZEN & UNTOUCHED** (No edits permitted in P0) |
| **Production Hair Matting**| `lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp` | Production Matting pipeline | **FROZEN & UNTOUCHED** (No edits permitted in P0) |
| **BiSeNet NCNN Model** | `lib-core-graphics/src/main/assets/models/bisenet_face_19.param` | Semantic Segmentation Anchor | **AS-IS VERIFIED** (Hash locked) |
| **BiSeNet Weights** | `lib-core-graphics/src/main/assets/models/bisenet_face_19.bin` | Float32/FP16 Model weights | **AS-IS VERIFIED** (Hash locked) |
| **P0-B.2 Validation Engine**| `scratch/run_p0_b2_full_suite.py` | Full 50-sample suite driver | **CREATED & EXECUTED** (50/50 samples processed) |
| **P0-B.2 C++ Device Bench** | `scratch/p0_b2_device_bench.cpp` | Standalone C++ device harness | **CROSS-COMPILED & BENCHMARKED** |
| **Device Native Binary** | `/data/local/tmp/p0_b2_device_bench` | Executable on Samsung Galaxy | **EXECUTED ON HARDWARE** (50 iterations) |

---

## 3. Algorithm Specifications
### 3.1 LowContrastHairResolver (F1)
- **File / Class:** `scratch/run_p0_b2_full_suite.py` -> `LowContrastHairResolver` / `scratch/p0_b2_device_bench.cpp` -> Stage 4
- **Purpose:** Disambiguates low-contrast dark hair from smooth dark background gradients using high-frequency Laplacian texture energy and geodesic connectivity.
- **Input:** `img_bgr`, `lab_img`, `gray`, `effective_hair`, `effective_core`, `eff_mean_lab`, `eff_var_lab`.
- **Output:** `p_dark_hair` (Float32 `[0.0, 1.0]`), `core_boost` (BoolMask), `evidence` dictionary.
- **Computational Complexity:** $O(W \times H)$ time, $O(W \times H)$ auxiliary memory.
- **Measured Latency on Device:** P50: 53.49 ms, P95: 81.98 ms, P99: 120.54 ms.
- **Fallback:** If hair texture energy is below noise threshold, falls back to conservative seed-only probability without flood-fill.

### 3.2 SubjectGraph (F2)
- **File / Class:** `scratch/run_p0_b2_full_suite.py` -> `SubjectGraph` / `scratch/p0_b2_device_bench.cpp` -> Stage 5
- **Purpose:** Constructs an anatomical topological tree: `Face Instance -> Head Region -> Semantic Hair -> Matte`. Supports multi-person ($N \ge 2$) and provides explicit fallback.
- **Input:** `labels_full` (BiSeNet semantic map), `img_bgr`.
- **Output:** `face_instances`, `head_regions`, `subject_hair_masks`, `subject_count`.
- **Computational Complexity:** $O(W \times H)$ connected components analysis.
- **Measured Latency on Device:** P50: 1.21 ms, P95: 2.54 ms, P99: 3.09 ms.
- **Fallback:** If `subject_count == 0` (no face detected, e.g. wallpaper or screenshot with no face), explicitly falls back to `alpha = 0.0`.

### 3.3 ImageContentGuard (F2)
- **File / Class:** `scratch/run_p0_b2_full_suite.py` -> `ImageContentGuard` / `scratch/p0_b2_device_bench.cpp` -> Stage 6
- **Purpose:** Identifies UI chrome, solid rectangular toolbars, sliders, and separator lines in screenshot images.
- **Input:** `img_bgr`, `labels_full`, `subject_graph`.
- **Output:** `ui_reject_mask` (BoolMask), `ui_probability` (Float32), `connected_hair` (BoolMask).
- **Critical Exemption:** Real hair touching borders that connects to a valid `SubjectGraph` root is **strictly exempted** from rejection.
- **Computational Complexity:** $O(W \times H)$ local variance and morphological line extraction.
- **Measured Latency on Device:** P50: 0.64 ms, P95: 1.24 ms, P99: 1.58 ms.
- **Fallback:** In the presence of UI ambiguity near the head, subject connectivity overrides UI rejection.

---

## 4. Benchmark Environment & Experimental Conditions
- **Device Model:** Samsung Galaxy SM-A075F (Product: a07xx, Device: a07)
- **SoC / Chipset:** MediaTek Helio G99 (MT6789), 2x Cortex-A76 @ 2.2GHz + 6x Cortex-A55 @ 2.0GHz
- **Operating System:** Android 14 (API Level 34), Build UP1A.231005.007
- **ABI:** ARM64-v8a
- **Cross-Compiler:** Android NDK Clang++ r26d (`26.1.10909125`)
- **Compilation Flags:** `-O3 -fopenmp -static-openmp -static-libstdc++`
- **Execution Target:** Physical device `/data/local/tmp/p0_b2_device_bench`
- **Benchmark Iterations:** 50 iterations (+1 discarded warmup)
- **Working Resolution:** 960 x 1280 (1.23 Megapixels)
- **NCNN Thread Count:** 4 OpenMP threads
