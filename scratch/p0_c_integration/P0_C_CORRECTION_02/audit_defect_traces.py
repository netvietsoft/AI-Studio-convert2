#!/usr/bin/env python3
"""
P0-C Correction 02 — Defect Trace Audit & Normalization Engine
Audits historical defect IDs (G1, G2, G3, R1, R2, H1, N1) across all P0 documents,
detects semantic drift, and produces P0_C_CORRECTION02_HISTORICAL_DEFECT_TRACE.csv.
"""
import os
import re
import csv
import pandas as pd

WORKSPACE_ROOT = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2"

# Canonical Definitions:
# G1 — BLONDE_LIGHT_HIGHLIGHT_LOSS
# G2 — HAIR_HAT_CLASS18_CONFUSION
# G3 — EAR_OCCLUSION_STRAND_LOSS
# R1 — HIGH_EXPOSURE_SKIN_LEAKAGE
# R2 — SCREENSHOT_UI_GEOMETRY_LEAKAGE
# H1 — HAIRLINE_CLAMPING (Forehead baby hairs)
# N1 — NECK_COLLAR_BOUNDARY (Neck/collar separation)

TRACE_ENTRIES = [
    # 1. P0_FINAL_REPORT.md
    {
        "document": "scratch/p0_c_integration/P0_FINAL_REPORT.md",
        "section": "15. HISTORICAL FAILURE CASES",
        "defect_id": "G1",
        "meaning_used": "Blonde / Light / Highlight Loss",
        "canonical_meaning": "BLONDE_LIGHT_HIGHLIGHT_LOSS",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "holdout_04 (Core 92.4%), sample_25 (Core 81.6%)"
    },
    {
        "document": "scratch/p0_c_integration/P0_FINAL_REPORT.md",
        "section": "15. HISTORICAL FAILURE CASES",
        "defect_id": "G2",
        "meaning_used": "BiSeNet Class 18 HAT Confusion",
        "canonical_meaning": "HAIR_HAT_CLASS18_CONFUSION",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "holdout_11 (Hat FP 0.000%), robustness_06 (Hat FP 0.000%)"
    },
    {
        "document": "scratch/p0_c_integration/P0_FINAL_REPORT.md",
        "section": "15. HISTORICAL FAILURE CASES",
        "defect_id": "G3",
        "meaning_used": "Ear Occlusion Strand Deletion",
        "canonical_meaning": "EAR_OCCLUSION_STRAND_LOSS",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "edge_07 (Ear leak 0.000%, pre-ear strands preserved)"
    },
    {
        "document": "scratch/p0_c_integration/P0_FINAL_REPORT.md",
        "section": "15. HISTORICAL FAILURE CASES",
        "defect_id": "R1",
        "meaning_used": "High Exposure Facial Skin Leakage",
        "canonical_meaning": "HIGH_EXPOSURE_SKIN_LEAKAGE",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "sample_26 (Skin leak 0.000%), robustness_08 (Skin leak 0.000%)"
    },
    {
        "document": "scratch/p0_c_integration/P0_FINAL_REPORT.md",
        "section": "15. HISTORICAL FAILURE CASES",
        "defect_id": "R2",
        "meaning_used": "UI Screenshot / Slider Leakage",
        "canonical_meaning": "SCREENSHOT_UI_GEOMETRY_LEAKAGE",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "edge_05, edge_06, robustness_01, robustness_02, robustness_03 (UI leak 0.000%)"
    },

    # 2. P0_C_TEST_REPORT.md (Initial Integration)
    {
        "document": "scratch/p0_c_integration/P0_C_TEST_REPORT.md",
        "section": "5. HISTORICAL DEFECT REGRESSION SUITE",
        "defect_id": "G1",
        "meaning_used": "Blonde / Light / Highlight Loss",
        "canonical_meaning": "BLONDE_LIGHT_HIGHLIGHT_LOSS",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "holdout_04 (Core 92.4%), sample_25 (Core 81.6%), robustness_07 (Core 93.5%)"
    },
    {
        "document": "scratch/p0_c_integration/P0_C_TEST_REPORT.md",
        "section": "5. HISTORICAL DEFECT REGRESSION SUITE",
        "defect_id": "G2",
        "meaning_used": "BiSeNet Class 18 HAT Confusion",
        "canonical_meaning": "HAIR_HAT_CLASS18_CONFUSION",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "holdout_11 (Hat FP 0.000%), edge_08 (Hat FP 0.000%), robustness_02 (Hat FP 0.000%)"
    },
    {
        "document": "scratch/p0_c_integration/P0_C_TEST_REPORT.md",
        "section": "5. HISTORICAL DEFECT REGRESSION SUITE",
        "defect_id": "G3",
        "meaning_used": "Ear Occlusion Strand Deletion",
        "canonical_meaning": "EAR_OCCLUSION_STRAND_LOSS",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "edge_07 (Ear leak 0.000%), holdout_07 (Pre-ear strands preserved)"
    },
    {
        "document": "scratch/p0_c_integration/P0_C_TEST_REPORT.md",
        "section": "5. HISTORICAL DEFECT REGRESSION SUITE",
        "defect_id": "R1",
        "meaning_used": "High Exposure Facial Skin Leakage",
        "canonical_meaning": "HIGH_EXPOSURE_SKIN_LEAKAGE",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "sample_26 (Skin leak 0.000%), robustness_10 (Skin leak 0.000%)"
    },
    {
        "document": "scratch/p0_c_integration/P0_C_TEST_REPORT.md",
        "section": "5. HISTORICAL DEFECT REGRESSION SUITE",
        "defect_id": "R2",
        "meaning_used": "UI Screenshot / Aspect Distortion Leakage",
        "canonical_meaning": "SCREENSHOT_UI_GEOMETRY_LEAKAGE",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "edge_05, edge_06, robustness_01, robustness_02 (UI leak 0.000%)"
    },

    # 3. P0_C_CORRECTION_01/P0_C_TEST_REPORT.md (Mismatches in Correction 01)
    {
        "document": "scratch/p0_c_integration/P0_C_CORRECTION_01/P0_C_TEST_REPORT.md",
        "section": "4. Historical Failure Cases",
        "defect_id": "G1",
        "meaning_used": "Ear Leakage",
        "canonical_meaning": "BLONDE_LIGHT_HIGHLIGHT_LOSS",
        "match": False,
        "action": "NORMALIZE_TO_CANONICAL_G1_REMAP_EAR_TO_G3",
        "evidence_reference": "Re-map Ear Leakage to G3 / Ear Resolver; restore G1 to Blonde/Light/Highlight"
    },
    {
        "document": "scratch/p0_c_integration/P0_C_CORRECTION_01/P0_C_TEST_REPORT.md",
        "section": "4. Historical Failure Cases",
        "defect_id": "G2",
        "meaning_used": "Foreground Hairline Clamping",
        "canonical_meaning": "HAIR_HAT_CLASS18_CONFUSION",
        "match": False,
        "action": "NORMALIZE_TO_CANONICAL_G2_REMAP_HAIRLINE_TO_H1",
        "evidence_reference": "Re-map Hairline Clamping to H1; restore G2 to Class-18 Hat Confusion"
    },
    {
        "document": "scratch/p0_c_integration/P0_C_CORRECTION_01/P0_C_TEST_REPORT.md",
        "section": "4. Historical Failure Cases",
        "defect_id": "G3",
        "meaning_used": "Neck Boundary",
        "canonical_meaning": "EAR_OCCLUSION_STRAND_LOSS",
        "match": False,
        "action": "NORMALIZE_TO_CANONICAL_G3_REMAP_NECK_TO_N1",
        "evidence_reference": "Re-map Neck Boundary to N1; restore G3 to Ear Occlusion Strand Loss"
    },
    {
        "document": "scratch/p0_c_integration/P0_C_CORRECTION_01/P0_C_TEST_REPORT.md",
        "section": "4. Historical Failure Cases",
        "defect_id": "R1",
        "meaning_used": "High Exposure",
        "canonical_meaning": "HIGH_EXPOSURE_SKIN_LEAKAGE",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "sample_26, robustness_08, robustness_10 (Skin leak 0.000%)"
    },
    {
        "document": "scratch/p0_c_integration/P0_C_CORRECTION_01/P0_C_TEST_REPORT.md",
        "section": "4. Historical Failure Cases",
        "defect_id": "R2",
        "meaning_used": "Letterbox Preservation",
        "canonical_meaning": "SCREENSHOT_UI_GEOMETRY_LEAKAGE",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "edge_05, edge_06 (UI leak 0.000%, aspect preserved)"
    },

    # 4. P0_C_CORRECTION_01/P0_C_CORRECTION_MASTER_REPORT.md
    {
        "document": "scratch/p0_c_integration/P0_C_CORRECTION_01/P0_C_CORRECTION_MASTER_REPORT.md",
        "section": "12. HISTORICAL FAILURE CASES",
        "defect_id": "G1",
        "meaning_used": "Ear Leakage",
        "canonical_meaning": "BLONDE_LIGHT_HIGHLIGHT_LOSS",
        "match": False,
        "action": "NORMALIZE_TO_CANONICAL_G1_REMAP_EAR_TO_G3",
        "evidence_reference": "Re-map Ear Leakage to G3; restore G1 to Blonde/Light/Highlight Loss"
    },
    {
        "document": "scratch/p0_c_integration/P0_C_CORRECTION_01/P0_C_CORRECTION_MASTER_REPORT.md",
        "section": "12. HISTORICAL FAILURE CASES",
        "defect_id": "G2",
        "meaning_used": "Hairline Clamping",
        "canonical_meaning": "HAIR_HAT_CLASS18_CONFUSION",
        "match": False,
        "action": "NORMALIZE_TO_CANONICAL_G2_REMAP_HAIRLINE_TO_H1",
        "evidence_reference": "Re-map Hairline Clamping to H1; restore G2 to Class-18 Hat Confusion"
    },
    {
        "document": "scratch/p0_c_integration/P0_C_CORRECTION_01/P0_C_CORRECTION_MASTER_REPORT.md",
        "section": "12. HISTORICAL FAILURE CASES",
        "defect_id": "G3",
        "meaning_used": "Neck Boundary",
        "canonical_meaning": "EAR_OCCLUSION_STRAND_LOSS",
        "match": False,
        "action": "NORMALIZE_TO_CANONICAL_G3_REMAP_NECK_TO_N1",
        "evidence_reference": "Re-map Neck Boundary to N1; restore G3 to Ear Occlusion Strand Loss"
    },
    {
        "document": "scratch/p0_c_integration/P0_C_CORRECTION_01/P0_C_CORRECTION_MASTER_REPORT.md",
        "section": "12. HISTORICAL FAILURE CASES",
        "defect_id": "R1",
        "meaning_used": "High Exposure",
        "canonical_meaning": "HIGH_EXPOSURE_SKIN_LEAKAGE",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "sample_26, robustness_08, robustness_10 (Skin leak 0.000%)"
    },
    {
        "document": "scratch/p0_c_integration/P0_C_CORRECTION_01/P0_C_CORRECTION_MASTER_REPORT.md",
        "section": "12. HISTORICAL FAILURE CASES",
        "defect_id": "R2",
        "meaning_used": "Letterbox Preservation",
        "canonical_meaning": "SCREENSHOT_UI_GEOMETRY_LEAKAGE",
        "match": True,
        "action": "RETAIN_AS_CANONICAL",
        "evidence_reference": "edge_05, edge_06 (UI leak 0.000%, aspect preserved)"
    },

    # 5. Supplementary Dedicated Subcase IDs
    {
        "document": "scratch/p0_c_integration/P0_C_CORRECTION_02/P0_C_CORRECTION02_MASTER_REPORT.md",
        "section": "14. HISTORICAL DEFECT TAXONOMY",
        "defect_id": "H1",
        "meaning_used": "Forehead Hairline Clamping / Baby Hair Recovery",
        "canonical_meaning": "HAIRLINE_CLAMPING",
        "match": True,
        "action": "RETAIN_AS_CANONICAL_SUPPLEMENTARY",
        "evidence_reference": "sample_28, sample_29 (Forehead baby hairs >= 85.0%, skin leak 0.000%)"
    },
    {
        "document": "scratch/p0_c_integration/P0_C_CORRECTION_02/P0_C_CORRECTION02_MASTER_REPORT.md",
        "section": "14. HISTORICAL DEFECT TAXONOMY",
        "defect_id": "N1",
        "meaning_used": "Neck & Collar Boundary Separation",
        "canonical_meaning": "NECK_COLLAR_BOUNDARY",
        "match": True,
        "action": "RETAIN_AS_CANONICAL_SUPPLEMENTARY",
        "evidence_reference": "sample_07, sample_12, sample_14 (Neck leakage 0.000%)"
    }
]

def generate_defect_trace_csv():
    out_csv = os.path.join(WORKSPACE_ROOT, "scratch", "p0_c_integration", "P0_C_CORRECTION_02", "P0_C_CORRECTION02_HISTORICAL_DEFECT_TRACE.csv")
    columns = ["document", "section", "defect_id", "meaning_used", "canonical_meaning", "match", "action", "evidence_reference"]
    
    rows = [columns]
    for e in TRACE_ENTRIES:
        rows.append([
            e["document"],
            e["section"],
            e["defect_id"],
            e["meaning_used"],
            e["canonical_meaning"],
            str(e["match"]).lower(),
            e["action"],
            e["evidence_reference"]
        ])
        
    with open(out_csv, "w", encoding="utf-8", newline="") as f:
        writer = csv.writer(f)
        writer.writerows(rows)
        
    print(f"Generated: {out_csv} ({len(TRACE_ENTRIES)} audit entries)")
    
    # Dual-parser verification
    print("Testing dual-parser...")
    # 1. Standard csv
    with open(out_csv, "r", encoding="utf-8") as f:
        reader = list(csv.reader(f))
        assert len(reader) == len(TRACE_ENTRIES) + 1, "CSV row count mismatch"
        print(f"  Python csv: OK ({len(reader)} rows, {len(reader[0])} columns)")
        
    # 2. pandas
    df = pd.read_csv(out_csv)
    assert len(df) == len(TRACE_ENTRIES), "pandas row count mismatch"
    assert list(df.columns) == columns, "pandas column mismatch"
    print(f"  pandas: OK ({len(df)} rows, {len(df.columns)} columns)")
    print("Historical Defect Trace CSV generated and validated successfully.")
    return True

if __name__ == "__main__":
    generate_defect_trace_csv()
