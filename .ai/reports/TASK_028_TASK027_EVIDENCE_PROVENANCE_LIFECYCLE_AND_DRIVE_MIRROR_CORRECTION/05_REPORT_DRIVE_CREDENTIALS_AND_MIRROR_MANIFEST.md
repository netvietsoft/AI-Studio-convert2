# 05 - REPORT DRIVE CREDENTIALS DEFECT & MIRROR MANIFEST
**Dự án:** CONVERT2 — Report Drive Mirroring & Evidence Integrity  
**Task ID:** `TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION_ACTIVE`  
**Command ID:** `TASK_028_TASK027_EVIDENCE_CORRECTION_20261003T142500+0700`  
**Parent Task:** `TASK_027`  
**Authority:** Chairman Tony  
**Report Drive Folder:** `13xDIqiI-vyP10pkypLI_6palmeJS-QRg`  
**Date:** 2026-10-03  

---

## 1. YÊU CẦU CỦA CHỦ TỊCH TONY
Yêu cầu số 8 của TASK_028:
> *"Mirror full TASK_027 corrected package to Report Drive folder 13xDIqiI-vyP10pkypLI_6palmeJS-QRg (or document exact credentials defect without false claims)."*

Theo Hiến pháp Điều 1 & Điều 2 (Evidence-Based Only):
- Tuyệt đối cấm báo cáo sai sự thật.
- Tuyệt đối cấm bịa đặt Google Drive File ID khi chưa thực hiện upload thực tế.
- Chốt chặn `test_guard_report_drive_mirror` trong `scripts/verify_evidence_provenance_guards.py` sẽ lập tức đánh trượt nếu một file được đánh dấu `MIRRORED` hoặc `PASS` mà không có mã định danh Google Drive ID thực tế (tối thiểu 25 ký tự).

---

## 2. BÁO CÁO KỸ THUẬT VỀ THIẾU HỤT CREDENTIALS (CREDENTIALS DEFECT)

1. **Khảo sát tự động bằng Headless Browser (Playwright):**
   - Đã thực hiện gửi request và inspect URL `https://drive.google.com/drive/u/0/folders/13xDIqiI-vyP10pkypLI_6palmeJS-QRg`.
   - Kết quả phản hồi: Thư mục mang tiêu đề `REPORT - Google Drive`.
   - Giao diện yêu cầu đăng nhập tài khoản Google (`Đăng nhập`), là thư mục chia sẻ dạng view/read hoặc restricted access, không mở anonymous HTTP REST write API.

2. **Môi trường Runner Host (`CONVERT2-WINDOWS-03`):**
   - Runner chạy dưới quyền dịch vụ nền Windows (Session 1), không có phiên desktop tương tác.
   - Trên runner host không lưu trữ file cấu hình Google Drive API Service Account JSON, không có rclone token hoặc gdrive CLI credentials được cấu hình.
   - Trong biến môi trường runner không có token xác thực quyền ghi trực tiếp vào Google Drive của Chủ tịch.

3. **Kết luận về trạng thái Mirror:**
   - Trạng thái kỹ thuật trung thực: `BLOCKED_AWAITING_WRITE_CREDENTIALS`.
   - Toàn bộ gói dữ liệu đã được bảo lưu nguyên vẹn 100% trên Git repository và GitHub Actions Artifacts, sẵn sàng để đồng bộ ngay khi tài khoản có quyền ghi hoặc bot harvester của Chủ tịch kích hoạt.

---

## 3. CƠ CHẾ BẢO ĐẢM DỮ LIỆU THAY THẾ (ALTERNATIVE TRANSFER PATH)

Để Chủ tịch và hệ thống kiểm toán có thể trích xuất toàn bộ dữ liệu kiểm chứng vật lý thực tế ngay lập tức, đội ngũ đã thiết lập 2 kênh truyền dẫn chuẩn mực:

1. **GitHub Actions Transfer Workflow:**
   - File: `.github/workflows/convert2-task027-gallery-transfer.yml`
   - Đóng gói toàn bộ:
     - `TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/` (ảnh thiết bị thật, contact sheet side-by-side, zoom chân tóc, kết quả 10 preset màu).
     - `.ai/reports/TASK_027_HAIR_V2_RESIDUAL_CORRECTION/` (raw outputs, log timing từng test case, CSV matrices, device proofs).
   - Tự động publish thành 2 GitHub Artifacts với thời gian lưu trữ 90 ngày:
     - `CONVERT2_TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY`
     - `CONVERT2_TASK_027_REPORTS`

2. **Niêm phong mã băm (Cryptographic Manifest):**
   - Bảng manifest chi tiết `14_REPORT_DRIVE_MIRROR_MANIFEST.csv` và `evidence_manifest.json` ghi nhận mã SHA-256 của từng file vật lý.
   - Cho phép đối soát từng bit, pixel giữa máy trạm, repository và thư mục lưu trữ của Chủ tịch.
