# P0-B.2R CSV STRUCTURAL INTEGRITY & VALIDATION REPORT

**Task:** Phase P0-B.2R — Final Evidence Correction & Freeze  
**Document:** `P0_B2R_CSV_VALIDATION_REPORT.md`  
**Target File:** `scratch/p0_b2r_validation/P0_B2R_METRICS.csv`  
**Validation Date:** 2026-10-02  
**Parsers Used:**
1. Python Standard Library `csv.reader` (RFC 4180 compliant)
2. Python `pandas.read_csv` (v2.2.2 / C Parser Engine)

---

## 1. Executive Summary & Audit Verdict
- **Pre-Repair Defect:** 
  1. `Notes` field on lines 34, 38, 48, 49, 52, 53, and 54 contained unquoted commas (e.g. `UI Leak=0.000%, BG Leak=0.00%`), causing standard CSV parsers to split into 22 columns instead of 21 and triggering pandas tokenize crash.
  2. Denominator-zero slices in cropped facial regions and occluded ears produced unformatted `nan%` values in `FaceLeak` and `EarLeak`.
- **Repair Applied:**
  1. Serialized all rows using RFC 4180 quotation rules (`csv.writer` with `QUOTE_MINIMAL`), correctly quoting text fields with commas.
  2. Applied canonical schema Null Policy: replaced undefined `nan%` with standardized `NA` (indicating absent evaluation ROI).
- **Post-Repair Status:** **100% VALID & CLEAN**. Both parsers successfully ingested all 62 rows without errors, warnings, or field count discrepancies.

---

## 2. Independent 12-Point Structural Verification Matrix

| Check ID | Verification Item | Target Standard | Observed Result | Status |
| :---: | :--- | :--- | :--- | :---: |
| **V01** | File Encoding | UTF-8 Without BOM | UTF-8 clean | **PASS** |
| **V02** | Header Integrity | Exactly 21 standardized column names | Exactly 21 matching columns | **PASS** |
| **V03** | Column Count Uniformity | 21 fields across every single data row | 21/21 fields on all 62 rows | **PASS** |
| **V04** | Total Data Row Count | Exactly 62 rows (excluding header) | 62 data rows | **PASS** |
| **V05** | Sample ID Uniqueness | 62 unique sample names (no duplicates) | 62 unique `SampleName` entries | **PASS** |
| **V06** | Required Fields | No missing delimiters, no blank keys | 100% populated | **PASS** |
| **V07** | Numeric Parseability | All numeric fields parseable as int/float | All metrics cleanly convertible | **PASS** |
| **V08** | Null Policy Consistency | Absent ROIs serialized as `NA` | 15 `FaceLeak` NA, 1 `EarLeak` NA | **PASS** |
| **V09** | Enum Policy | Role $\in$ {REGRESSION, EXISTING_HOLDOUT, EDGE_HOLDOUT, ROBUSTNESS_HOLDOUT} | Strictly conforms to defined enum | **PASS** |
| **V10** | Duplicate Row Check | Zero duplicated sample entries | Zero duplicate rows | **PASS** |
| **V11** | Percentage Value Range | $0.000\% \le x \le 100.0\%$ for all percentages | All percentages within $[0.0, 100.0]$ | **PASS** |
| **V12** | Gate Consistency | Status derived strictly from row metrics | All 62 samples verify `PASS` | **PASS** |

---

## 3. Dataset Count & Role Matrix (Section 15 Verification)

| Dataset Role | Expected Sample Count | Verified Sample Count | Unique Sample IDs | Gate Pass Count | Fail Count | Pass Rate |
| :--- | :---: | :---: | :--- | :---: | :---: | :---: |
| **REGRESSION** | 30 | 30 | `sample_01` .. `sample_30` | 30 | 0 | 100.0% |
| **EXISTING_HOLDOUT** | 12 | 12 | `holdout_01` .. `holdout_12` | 12 | 0 | 100.0% |
| **EDGE_HOLDOUT** | 8 | 8 | `edge_01` .. `edge_08` | 8 | 0 | 100.0% |
| **ROBUSTNESS_HOLDOUT**| 12 | 12 | `robustness_01` .. `robustness_12` | 12 | 0 | 100.0% |
| **TOTAL** | **62** | **62** | **62 Unique Samples** | **62** | **0** | **100.0%** |

---

## 4. Null & Absent ROI Breakdown
- `FaceLeak` = `NA` (15 samples):
  - `sample_05`, `sample_08`, `sample_20`, `sample_21`, `sample_22`, `sample_23`, `holdout_01`, `holdout_03`, `holdout_09`, `holdout_10`, `edge_07`, `robustness_04`, `robustness_05`, `robustness_06`, `robustness_12`.
  - **Reason:** Samples are close-up hair crops, side profiles, back of head, monk scalp, or facial features (eyes, nose, upper lip) are outside the crop/field of view ($|\mathcal{R}_{\text{face}}| = 0$).
- `EarLeak` = `NA` (1 sample):
  - `sample_12` (Auburn Wavy Long).
  - **Reason:** All ear semantic pixels are completely occluded by thick cascading hair strands ($\mathcal{R}_{\text{ear}} \setminus \mathcal{R}_{\text{hair\_over\_ear}} = \emptyset$).

---

## 5. Dual-Parser Ingestion Proof

### Parser 1: Python Standard `csv`
```python
with open("P0_B2R_METRICS.csv", "r", encoding="utf-8") as f:
    reader = csv.reader(f)
    header = next(reader)
    rows = list(reader)
# Result: 62 rows, 21 columns, 0 exceptions
```

### Parser 2: Python `pandas`
```python
df = pd.read_csv("P0_B2R_METRICS.csv")
# Result: DataFrame shape (62, 21), dtypes verified, 0 tokenization errors
```

**Conclusion:** `P0_B2R_METRICS.csv` is fully compliant with RFC 4180 and certified for freeze.
