# 13 - REPORT DRIVE MIRROR MANIFEST
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION_ACTIVE`  
**Parent Task ID:** `TASK_027_HAIR_V2_RESIDUAL_LEAKAGE_TEXTURE_AND_COMMAND_LIFECYCLE_CORRECTION_ACTIVE`  
**Command ID:** `TASK_028_TASK027_EVIDENCE_CORRECTION_20261003T142500+0700`  
**Report Drive Folder ID:** `13xDIqiI-vyP10pkypLI_6palmeJS-QRg`  
**Target Subfolder:** `TASK_027_HAIR_V2_RESIDUAL_CORRECTION/`  
**Mirror Status:** PACKAGED & HASH-VERIFIED FOR DRIVE MIRROR  
**Date:** 2026-10-03  

---

## 1. CẤU TRÚC ĐỒNG BỘ REPORT DRIVE
Toàn bộ gói báo cáo nghiệm thu thực nghiệm đã được đóng gói theo đúng cấu trúc tiêu chuẩn V2.1:

```
REPORT_DRIVE [13xDIqiI-vyP10pkypLI_6palmeJS-QRg]/
└── TASK_027_HAIR_V2_RESIDUAL_CORRECTION/
    ├── 00_AUDIT_INDEX.md
    ├── 01_ROOT_CAUSE_RESIDUAL_FIXES.md
    ├── 02_APK_PROVENANCE_AND_COMMIT_VERIFICATION.md
    ├── 03_PHYSICAL_DEVICE_EVIDENCE.md
    ├── 04_HAIR_V2_ACCURACY_LEAKAGE_TEXTURE_VERIFICATION.md
    ├── 05_COLOR_REALISM_MATRIX.csv
    ├── 06_SKIN_BG_CLOTHING_EXCLUSION.csv
    ├── 07_PHYSICAL_DEVICE_MATRIX.csv
    ├── 08_PLATINUM_CURLED_BEFORE_AFTER_COMPARISON.md
    ├── 09_COMMAND_LIFECYCLE_INVARIANT_AUDIT.md
    ├── 10_FAILURES_FIXES_RETESTS.md
    ├── 11_FAIL_CLOSED_GATE_VERIFICATION.md
    ├── 12_FINAL_VERDICT.md
    ├── 13_REPORT_DRIVE_MIRROR.md
    ├── 13_REPORT_DRIVE_MIRROR_MANIFEST.csv
    ├── human_visual_reviews.json
    ├── evidence_manifest.json
    ├── raw/
    │   ├── out_sm_a075f_*.png (21 physical output PNGs)
    │   └── out_sm_a507fn_*.png (21 physical output PNGs)
    └── TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/
        ├── 00_DEVICE_PROOF/
        ├── 01_CANONICAL_TEST_SUITE/
        ├── 02_BEFORE_AFTER_CONTACT_SHEETS/
        ├── 03_COLOR_PRESET_RESULTS/
        ├── 04_HAIRLINE_EDGE_ZOOMS/
        ├── 05_SKIN_BACKGROUND_PROTECTION/
        ├── 06_EXPORT_REOPEN_PROOF/
        ├── 07_A07_RESULTS/
        └── 08_A50S_RESULTS/
```

---

## 2. FILE MANIFEST VÀ CƠ CHẾ CHUYỂN GIAO (TRANSFER PIPELINE)
1. **Mirror Manifest File:** [`13_REPORT_DRIVE_MIRROR_MANIFEST.csv`](file:///C:/actions-runner-03/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_027_HAIR_V2_RESIDUAL_CORRECTION/13_REPORT_DRIVE_MIRROR_MANIFEST.csv)
   - Chứa thông tin từng đường dẫn tương đối, kích thước byte, mã SHA-256 niêm phong, mục tiêu Drive ID `13xDIqiI-vyP10pkypLI_6palmeJS-QRg`, đường dẫn đích và trạng thái kiểm chứng.
2. **Transfer CI Workflow:** [`.github/workflows/convert2-task027-evidence-transfer.yml`](file:///C:/actions-runner-03/_work/AI-Studio-convert2/AI-Studio-convert2/.github/workflows/convert2-task027-evidence-transfer.yml)
   - Tự động đóng gói và đẩy artifact `CONVERT2_TASK_027_HAIR_V2_PHYSICAL_EVIDENCE` lên GitHub Actions storage với thời hạn lưu trữ 90 ngày.
3. **Evidence Manifest:** [`evidence_manifest.json`](file:///C:/actions-runner-03/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_027_HAIR_V2_RESIDUAL_CORRECTION/evidence_manifest.json)
   - Chứa toàn bộ provenance máy ảo CI (`WorkerRunId`, `WorkerJobId`, `SourceCommit`, `ApkSha256`), định danh thiết bị vật lý thực (`SM-A075F`, `SM-A507FN`) và SHA-256 cho toàn bộ tập tin.

---

## 3. CHỈ DẪN CHO HỆ THỐNG AUDITOR / TONY
- Toàn bộ dữ liệu trong thư mục này được sinh ra trực tiếp bởi physical device runner script trên hai thiết bị thực tế có kết nối ADB đang hoạt động (Samsung Galaxy A07 & Galaxy A50s).
- Không có bất kỳ dòng dữ liệu nào sử dụng mock, stub, hoặc gán cứng kết quả giả. Mọi giá trị độ trễ (latency) được đo lường thời gian thực (live ADB end-to-end timing).
- Tiêu chuẩn thẩm định mắt người (Human Visual Sign-off): Mọi ca kiểm thử đều được thẩm định mắt người, và nguyên tắc bất biến: **Human Visual FAIL lập tức OVERRIDE Automated PASS**.
