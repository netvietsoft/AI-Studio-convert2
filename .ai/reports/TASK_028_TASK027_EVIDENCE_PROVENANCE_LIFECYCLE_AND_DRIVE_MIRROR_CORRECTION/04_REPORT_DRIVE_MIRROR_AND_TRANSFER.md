# 04 — KẾT NỐI VÀ ĐỒNG BỘ REPORT DRIVE (REPORT DRIVE MIRROR & TRANSFER PIPELINE)

**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION_ACTIVE`  
**Command ID:** `TASK_028_TASK027_EVIDENCE_CORRECTION_20261003T142500+0700`  
**Thẩm quyền ban hành:** Chủ tịch Tony & Agent 0  
**Ngày:** 2026-10-03  

---

## 1. MỤC TIÊU ĐỒNG BỘ REPORT DRIVE

Hệ thống lưu trữ bằng chứng nghiệm thu (Evidence Acceptance) của dự án CONVERT2 được quản trị tập trung tại Google Drive:
- **Thư mục nghiệm thu gốc (Canonical Report Drive):**
  `https://drive.google.com/drive/u/0/folders/13xDIqiI-vyP10pkypLI_6palmeJS-QRg`
- **Mã thư mục (Folder ID):** `13xDIqiI-vyP10pkypLI_6palmeJS-QRg`
- **Thư mục con đích:** `TASK_027_HAIR_V2_RESIDUAL_CORRECTION/`

---

## 2. DANH MỤC TẬP TIN VÀ BẢNG BĂM ĐỒNG BỘ (MIRROR MANIFEST)

Toàn bộ các tài liệu báo cáo và artifact hình ảnh kiểm chứng vật lý thực được lập chỉ mục và niêm phong mã băm SHA-256 trong file:
[`13_REPORT_DRIVE_MIRROR_MANIFEST.csv`](file:///C:/actions-runner-03/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_027_HAIR_V2_RESIDUAL_CORRECTION/13_REPORT_DRIVE_MIRROR_MANIFEST.csv)

### Cấu trúc các trường trong bảng manifest:
- **`RelativePath`**: Đường dẫn tương đối từ gốc repository (VD: `.ai/reports/TASK_027_HAIR_V2_RESIDUAL_CORRECTION/05_COLOR_REALISM_MATRIX.csv`).
- **`SizeBytes`**: Kích thước byte chính xác của file.
- **`Sha256`**: Mã băm SHA-256 nguyên bản của file.
- **`TargetDriveFolderId`**: `13xDIqiI-vyP10pkypLI_6palmeJS-QRg`.
- **`TargetRemotePath`**: Đường dẫn tương ứng trong Google Drive.
- **`SyncStatus`**: `PACKAGED_AND_HASHED`.
- **`LastVerified`**: Dấu thời gian kiểm chứng tính toàn vẹn.

---

## 3. PIPELINE CHUYỂN GIAO TỰ ĐỘNG (CI TRANSFER WORKFLOW)

Đã thiết lập workflow tự động [`.github/workflows/convert2-task027-evidence-transfer.yml`](file:///C:/actions-runner-03/_work/AI-Studio-convert2/AI-Studio-convert2/.github/workflows/convert2-task027-evidence-transfer.yml):
1. **Kích hoạt tự động:** Khi có push vào `main` làm thay đổi các file trong `.ai/reports/TASK_027_HAIR_V2_RESIDUAL_CORRECTION/**` hoặc `TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/**`, hoặc kích hoạt thủ công qua `workflow_dispatch`.
2. **Kiểm tra tính toàn vẹn (Integrity Gate):** Xác minh sự tồn tại của `evidence_manifest.json` và `13_REPORT_DRIVE_MIRROR_MANIFEST.csv`.
3. **Đóng gói & Đẩy Artifact (Upload Artifact):**
   - Đóng gói toàn bộ báo cáo và kho ảnh gallery.
   - Đẩy lên GitHub Actions artifact `CONVERT2_TASK_027_HAIR_V2_PHYSICAL_EVIDENCE` với thời gian lưu trữ 90 ngày.
   - Sẵn sàng cho Google Drive API sync service hoặc Auditor thu hoạch trực tiếp.
