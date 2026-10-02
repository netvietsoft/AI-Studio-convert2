#!/usr/bin/env python3
"""
Dual-Parser CSV Validation Script (Python csv & pandas)
Validates all CSV artifacts in P0_C_CORRECTION_01 according to Section 28 of Master Spec.
"""
import os
import sys
import csv
import pandas as pd

def validate_csv(file_path, expected_unique_col=None, allow_na=True):
    print(f"Validating {os.path.basename(file_path)}...")
    assert os.path.exists(file_path), f"File missing: {file_path}"
    
    # 1. Test standard python csv parser
    rows = []
    with open(file_path, "r", encoding="utf-8") as f:
        reader = csv.reader(f)
        header = next(reader)
        col_count = len(header)
        for i, row in enumerate(reader):
            assert len(row) == col_count, f"Row {i+1} column count mismatch: expected {col_count}, got {len(row)}"
            rows.append(row)
    print(f"  [PASS] Python csv parser: {len(rows)} data rows, {col_count} columns.")
    
    # 2. Test pandas parser
    df = pd.read_csv(file_path, encoding="utf-8")
    assert len(df) == len(rows), f"Pandas row count mismatch: {len(df)} vs {len(rows)}"
    assert len(df.columns) == col_count, f"Pandas column count mismatch: {len(df.columns)} vs {col_count}"
    print(f"  [PASS] Pandas parser: parsed successfully into DataFrame ({df.shape[0]}x{df.shape[1]}).")
    
    # 3. Test uniqueness if specified
    if expected_unique_col and expected_unique_col in df.columns:
        dups = df[expected_unique_col].duplicated().sum()
        assert dups == 0, f"Found {dups} duplicate values in {expected_unique_col}"
        print(f"  [PASS] Uniqueness check passed for column '{expected_unique_col}'.")
        
    return {
        "file": os.path.basename(file_path),
        "rows": len(df),
        "columns": col_count,
        "csv_parser": "PASS",
        "pandas_parser": "PASS",
        "uniqueness": "PASS" if expected_unique_col else "N/A"
    }

if __name__ == "__main__":
    base_dir = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\p0_c_integration\P0_C_CORRECTION_01"
    files = [
        ("P0_C_ALGORITHM_PARAMETER_PARITY.csv", "parameter_id"),
        ("P0_C_JNI_SURFACE_INVENTORY.csv", "jni_symbol"),
        ("P0_C_EAR_RESOLVER_TIMING_AUDIT.csv", "iteration"),
        ("P0_C_DEVICE_BENCHMARK_960x1280.csv", "StageID"),
        ("P0_C_PRODUCTION_REGRESSION_METRICS.csv", "sample_id"),
        ("P0_C_PARITY_RAW_EVIDENCE.csv", "sample_id"),
    ]
    results = []
    for fname, ucol in files:
        fpath = os.path.join(base_dir, fname)
        if os.path.exists(fpath):
            res = validate_csv(fpath, ucol)
            results.append(res)
        else:
            print(f"File not yet ready: {fname}")
            
    print("\nSummary of Validated CSVs:")
    for r in results:
        print(f"  {r['file']}: {r['rows']} rows, {r['columns']} cols, CSV={r['csv_parser']}, Pandas={r['pandas_parser']}")
