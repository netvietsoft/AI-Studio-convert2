# PHASE P0-C CORRECTION — ISSUE C1: ASPECT THRESHOLD AUDIT & TRACE RECORD
**Document ID:** `P0_C_C1_ASPECT_THRESHOLD_TRACE.md`  
**Phase:** Phase P0-C Corrective Audit & Remediation  
**Task ID:** TASK-P0C-F02  
**Owner:** Agent 0 — CEO / Orchestrator  
**Date:** 2026-10-02  
**Audit Target:** Discrepancy between Aspect Threshold 1.80 vs 1.45  

---

## 1. SOURCE OF TRUTH INVESTIGATION TABLE

| Artifact / Evidence | File Path | Function / Section | Recorded Value | Classification | Effective at Runtime? | Notes / Analysis |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **P0-B.2R Candidate Implementation** | `scratch/run_p0_b2r_full_suite.py:31-33` | `run_bisenet_adaptive` | `aspect > 1.80` | **CANONICAL CODE (Source of Truth)** | **YES** | The exact Python code that ran all 62 regression samples and achieved gate PASS. |
| **P0-B.2R Master Report** | `scratch/p0_b2r_validation/P0_B2R_REPORT.md:24,152` | Executive Summary (§1.2) & Section 4 | `aspect > 1.80` | **CANONICAL SPECIFICATION** | N/A (Doc) | Explicitly specifies: *"Adaptive Mode B (Aspect-Preserving Letterbox khi \max(H/W, W/H) > 1.80)"* and *"Khi aspect ratio <= 1.80, direct resize là tối ưu nhất"*. |
| **P0-B.2R Configuration Table** | `scratch/p0_b2r_validation/config/P0_B2R_CONFIG.md:17` | Section 2 (Geometry Config) | `tau_aspect = 1.45` | **DOCUMENTATION TYPO** | **NO** | The table erroneously transcribed 1.45 instead of 1.80 from the working Python prototype. |
| **P0-B.2R Source Trace** | `scratch/p0_b2r_validation/source_trace/SOURCE_TRACE.md:13` | BiSeNet Geometry (R2) | `Mode B Letterbox` | **SUPPORTING EVIDENCE** | N/A (Doc) | Refers to `run_bisenet_adaptive` in `run_p0_b2r_geometry_ab.py`. |
| **P0-B.2R Geometry A/B** | `scratch/p0_b2r_validation/geometry_ab/GEOMETRY_AB_METRICS.csv` | Mode B on `edge_05`, `edge_06`, `holdout_07` | Mode B applied | **EXPERIMENTAL EVIDENCE** | N/A (Data) | All tested screenshot samples had aspect ratio 2.22:1 ($> 1.80$). |
| **Initial Production C++ Port** | `lib-core-graphics/src/main/cpp/src/ai/bisenet_face_parser.cpp:173` | `BiSeNetFaceParser::parseFace19Adaptive` | `maxAspect > 1.45f` | **ALGORITHM DRIFT DEFECT** | **YES (Prior)** | Developer transcribed the value from `P0_B2R_CONFIG.md` table (1.45) rather than the canonical code (1.80). |
| **Initial Production Engine Trace** | `lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp:599` | `runP0B2RNativePipeline` | `aspect ratio > 1.45` | **ALGORITHM DRIFT DEFECT** | **YES (Prior)** | Comment and call site reflected the 1.45 threshold. |
| **P0-C Production Diff Map** | `scratch/p0_c_integration/P0_C_PRODUCTION_DIFF_MAP.md:138-142` | Stage 1 Diff Trace | `tau_aspect = 1.80` | **DOCUMENTATION DISCREPANCY** | N/A (Doc) | Correctly cited 1.80 as the algorithm requirement, but the C++ code was at 1.45. |
| **P0-C Initial Review Report** | `scratch/p0_c_integration/P0_C_REVIEW_REPORT.md` | Table in Section 3 | `1.45` | **FALSE-POSITIVE REVIEW AUDIT** | N/A (Doc) | Erroneously accepted 1.45 as matching `P0_B2R_CONFIG.md` without cross-checking the actual candidate code. |

---

## 2. DECISION TREE RESOLUTION

According to Section 5 of `P0_C_FINAL_AUDIT_CORRECTION_DRIFT_REMEDIATION_REVALIDATION_AGENT_SPEC.txt`:

- **Frozen approved value in executable prototype:** `1.80`
- **Initial production C++ source:** `1.45`
- **Audit Classification:** **CASE B — ALGORITHM_DRIFT_CONFIRMED**.
- **Action Required:**
  1. The prior claim of "zero algorithm drift" is declared **INVALID**.
  2. The production source in `lib-core-graphics/src/main/cpp/src/ai/bisenet_face_parser.cpp` must be **RESTORED EXACTLY to 1.80f**.
  3. No additional heuristic tuning is permitted.
  4. Mandatory full rebuild across all ABIs, complete re-regression across all 62 canonical samples, and comparable physical device benchmark rerun must be executed.

---

## 3. PHYSICAL IMPACT ON CANONICAL SAMPLE SET

Aspect ratio distribution analysis across the 62 canonical samples revealed:
- **31 samples** have aspect ratio $> 1.80$ (e.g. mobile screenshots with aspect ratio 2.167–2.222). These correctly trigger Mode B letterboxing under both 1.45 and 1.80.
- **8 samples** have aspect ratio between 1.45 and 1.80 (`sample_05`, `sample_06`, `sample_07`, `sample_08`, `sample_09`, `sample_10`, `sample_17`, `sample_19`). These are standard $3:2$ or $1.452$ portrait studio photographs.
- Under `1.45`, these 8 standard portrait photographs were incorrectly padded with letterboxing, wasting up to $30\%$ of the $512 \times 512$ neural network resolution on blank borders!
- Restoring the threshold to `1.80` ensures standard portraits receive the full native direct resize resolution, exactly matching the approved P0-B.2R candidate design.
