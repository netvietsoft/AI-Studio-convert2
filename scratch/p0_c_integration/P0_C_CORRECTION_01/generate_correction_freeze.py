#!/usr/bin/env python3
"""
Generate P0-C Correction 01 Manifest, SHA-256 Freeze, and Freeze Record.
"""
import os
import hashlib
import csv

def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest()

def main():
    base_dir = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2"
    corr_dir = os.path.join(base_dir, r"scratch\p0_c_integration\P0_C_CORRECTION_01")
    
    artifacts = [
        # Documentation & Evidence Artifacts
        ("CORRECTION_MASTER_REPORT", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_CORRECTION_MASTER_REPORT.md"),
        ("C1_THRESHOLD_TRACE", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_C1_ASPECT_THRESHOLD_TRACE.md"),
        ("ALGORITHM_PARAMETER_PARITY", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_ALGORITHM_PARAMETER_PARITY.csv"),
        ("BENCHMARK_COMPARABILITY_MATRIX", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_BENCHMARK_COMPARABILITY_MATRIX.md"),
        ("DEVICE_BENCHMARK_960x1280", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_DEVICE_BENCHMARK_960x1280.csv"),
        ("JNI_SURFACE_INVENTORY", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_JNI_SURFACE_INVENTORY.csv"),
        ("JNI_API_AUDIT", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_JNI_API_AUDIT.md"),
        ("ROLLBACK_EXECUTION_EVIDENCE", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_ROLLBACK_EXECUTION_EVIDENCE.md"),
        ("PARITY_RAW_EVIDENCE", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_PARITY_RAW_EVIDENCE.csv"),
        ("TOOLCHAIN_SOURCE_OF_TRUTH", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_TOOLCHAIN_SOURCE_OF_TRUTH.md"),
        ("EAR_RESOLVER_TIMING_AUDIT", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_EAR_RESOLVER_TIMING_AUDIT.csv"),
        ("CLAIM_CORRECTION_LOG", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_CLAIM_CORRECTION_LOG.md"),
        ("PRODUCTION_REGRESSION_METRICS", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_PRODUCTION_REGRESSION_METRICS.csv"),
        ("CORRECTION_CSV_VALIDATION_REPORT", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_CORRECTION_CSV_VALIDATION_REPORT.md"),
        ("TESTER_REPORT", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_TEST_REPORT.md"),
        ("REVIEWER_REPORT", r"scratch\p0_c_integration\P0_C_CORRECTION_01\P0_C_REVIEW_REPORT.md"),
        
        # Production Source Code Files
        ("PRODUCTION_CPP_HEADER", r"lib-core-graphics\src\main\cpp\include\hair_matting_engine.h"),
        ("PRODUCTION_CPP_SOURCE", r"lib-core-graphics\src\main\cpp\src\hair_matting_engine.cpp"),
        ("PRODUCTION_AI_HEADER", r"lib-core-graphics\src\main\cpp\include\ai\bisenet_face_parser.h"),
        ("PRODUCTION_AI_SOURCE", r"lib-core-graphics\src\main\cpp\src\ai\bisenet_face_parser.cpp"),
        ("PRODUCTION_JNI_BRIDGE", r"lib-core-graphics\src\main\cpp\src\jni_bridge.cpp"),
        ("PRODUCTION_KOTLIN_ENGINE", r"lib-core-graphics\src\main\kotlin\com\meitu\core\nativeengine\MeituNativeEngine.kt"),
    ]
    
    manifest_rows = [["category", "relative_path", "size_bytes", "sha256"]]
    sha256_lines = []
    record_rows = []
    
    for cat, rel_p in artifacts:
        full_p = os.path.join(base_dir, rel_p)
        assert os.path.exists(full_p), f"Artifact missing: {full_p}"
        size = os.path.getsize(full_p)
        h = sha256_file(full_p)
        
        # Normalize relative path with forward slashes for cross-platform checksumming
        norm_p = rel_p.replace("\\", "/")
        manifest_rows.append([cat, norm_p, str(size), h])
        sha256_lines.append(f"{h}  {norm_p}")
        record_rows.append(f"| **{cat}** | `{norm_p}` | {size:,} | `{h}` |")
        
    manifest_path = os.path.join(corr_dir, "P0_C_CORRECTION_MANIFEST.csv")
    with open(manifest_path, "w", encoding="utf-8", newline="") as f:
        writer = csv.writer(f)
        writer.writerows(manifest_rows)
    print(f"Saved: {manifest_path}")
    
    freeze_path = os.path.join(corr_dir, "P0_C_CORRECTION_FREEZE.sha256")
    with open(freeze_path, "w", encoding="utf-8") as f:
        f.write("\n".join(sha256_lines) + "\n")
    print(f"Saved: {freeze_path}")
    
    record_content = f"""# PHASE P0-C CORRECTION 01 — CRYPTOGRAPHIC FREEZE RECORD
**Phase:** P0-C Correction 01 — Final Audit Correction, Drift Remediation & Revalidation  
**Authority:** Agent 0 — CEO / ORCHESTRATOR  
**Date:** 2026-10-02T09:48:00+07:00  
**Status:** **`CRYPTOGRAPHICALLY_FROZEN`**  
**Final Decision:** **`P0_FINAL_PASS_RECONFIRMED`**  

---

## 1. Cryptographic Inventory & Integrity Table
All {len(artifacts)} artifacts comprising the corrected Phase P0-C package have been verified and sealed:

| Category | Relative File Path | Size (Bytes) | SHA-256 Checksum |
| :--- | :--- | :---: | :--- |
""" + "\n".join(record_rows) + """

---

## 2. Integrity Verification Instructions
To independently verify the integrity of the frozen package:

```bash
# Verify entire freeze checksum
sha256sum -c scratch/p0_c_integration/P0_C_CORRECTION_01/P0_C_CORRECTION_FREEZE.sha256
```

---

## 3. Freeze Sign-Off
- **All 7 Audit Issues Remediated:** Issues C1 through C7 verified resolved.
- **Production Drift Remediated:** $\\tau_{\\text{aspect}} = 1.80$ active in production source.
- **62/62 Canonical Regression:** 100% PASS with Level A parity.
- **Physical Device Benchmark:** 71.96 ms P50 at 960x1280 (Gate $\\le 85.00$ ms).
- **Phase P1–P6:** **STRICTLY BLOCKED**.

$$\\mathbf{VERDICT:\\;FREEZE\\_COMPLETE\\_P0\\_FINAL\\_PASS\\_RECONFIRMED}$$
"""
    record_path = os.path.join(corr_dir, "P0_C_CORRECTION_FREEZE_RECORD.md")
    with open(record_path, "w", encoding="utf-8") as f:
        f.write(record_content)
    print(f"Saved: {record_path}")

if __name__ == "__main__":
    main()
