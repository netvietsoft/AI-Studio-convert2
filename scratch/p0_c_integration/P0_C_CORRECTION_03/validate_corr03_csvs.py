#!/usr/bin/env python3
"""
P0-C Correction 03 — Dual-Parser Validation Suite
Tests all 4 Correction 03 CSV artifacts with Python csv and pandas.read_csv.
"""
import os
import csv
import pandas as pd

WORKSPACE_ROOT = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2"
CORR03_DIR = os.path.join(WORKSPACE_ROOT, "scratch", "p0_c_integration", "P0_C_CORRECTION_03")

CSVS = [
    ("P0_C_CORRECTION03_SAMPLE_IDENTITY_CANONICAL.csv", 13, 62, "sample_id"),
    ("P0_C_CORRECTION03_DEFECT_EVIDENCE_MATRIX.csv", 11, 31, None),
    ("P0_C_CORRECTION03_COMPLETE_PRODUCTION_FILESET.csv", 11, 7, "relative_path"),
    ("P0_C_CORRECTION03_MANIFEST.csv", 4, 17, "relative_path"),
]

def main():
    print("=== [DUAL-PARSER CSV VALIDATION FOR CORRECTION 03] ===")
    all_pass = True
    for fname, exp_cols, exp_rows, unq_key in CSVS:
        fpath = os.path.join(CORR03_DIR, fname)
        print(f"\nValidating: {fname}")
        
        # 1. Python csv
        with open(fpath, "r", encoding="utf-8") as f:
            reader = list(csv.reader(f))
        assert len(reader[0]) == exp_cols, f"Column mismatch in {fname}"
        assert len(reader) == exp_rows + 1, f"Row mismatch in {fname}"
        print(f"  Python csv: OK ({len(reader)} rows, {len(reader[0])} cols)")
        
        # 2. pandas.read_csv
        df = pd.read_csv(fpath)
        assert len(df.columns) == exp_cols
        assert len(df) == exp_rows
        assert df.isnull().sum().sum() == 0, f"NaNs found in {fname}"
        if unq_key:
            assert df[unq_key].duplicated().sum() == 0, f"Duplicates in {unq_key}"
            print(f"  Unique key '{unq_key}': 100% unique")
        print(f"  pandas: OK ({len(df)} rows, {len(df.columns)} cols)")
        print(f"  Result: PASS")
        
    print("\nALL 4 CORRECTION 03 CSVS PASSED DUAL-PARSER VALIDATION.")

if __name__ == "__main__":
    main()
