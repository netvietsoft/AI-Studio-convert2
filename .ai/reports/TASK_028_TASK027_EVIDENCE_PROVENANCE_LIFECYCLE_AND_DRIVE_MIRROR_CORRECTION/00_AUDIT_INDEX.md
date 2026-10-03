# 00 - AUDIT INDEX & EXECUTIVE SUMMARY
# TASK_028: TASK_027 EVIDENCE PROVENANCE, COMMAND LIFECYCLE & DRIVE MIRROR CORRECTION
**Authority:** Chairman Tony  
**Protocol:** CONVERT2_COMMAND_V2  
**Task ID:** `TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION_ACTIVE`  
**Command ID:** `TASK_028_TASK027_EVIDENCE_CORRECTION_20261003T142500+0700`  
**Parent Task ID:** `TASK_027_HAIR_V2_RESIDUAL_LEAKAGE_TEXTURE_AND_COMMAND_LIFECYCLE_CORRECTION_ACTIVE`  
**Dispatch Commit SHA:** `25c56a44b9fb14a91e9c24c4650756112be02a6a`  
**Target Hardware:**
- Samsung Galaxy A07 (`SM-A075F`, MediaTek Helio G99, Android 16, Serial: `R83L80E1LXX`) @ `192.168.1.18:40159`
- Samsung Galaxy A50s (`SM-A507FN`, Exynos 9611, Android 11, Serial: `R58MA581ZZA`) @ `192.168.1.2:41775`  
**APK SHA-256:** `0BD519C9B7930AAFE69D5BAD0180AAA413F429464ADB978ADB5B835898D6DF08`  
**Execution Lane:** `infra-hair-evidence-lifecycle-correction`  
**Date:** 2026-10-03  

---

## 1. TỔNG QUAN NỘI DUNG NHIỆM VỤ & CHỈ THỊ CỦA CHỦ TỊCH TONY
Nhiệm vụ `TASK_028` được ban hành nhằm kiểm toán, truy vết và khắc phục triệt để 5 khiếm khuyết trong báo cáo nghiệm thu của `TASK_027`:

1. **Khắc phục tình trạng trùng lặp file lệnh giữa các thư mục lifecycle:**
   - Bảo đảm bất biến tuyệt đối: Mỗi Command ID chỉ tồn tại ở duy nhất 1 thư mục trạng thái (`pending`, `reserved`, `claimed`, `running`, `completed`, `failed`).
   - Xử lý race condition trong complete/fail/recover/integrator để không bao giờ tái diễn file trùng lặp.
2. **Thiết lập CI Invariants trên mọi workflow:**
   - Thêm bước kiểm tra chốt chặn `assert-lifecycle-uniqueness` trên `convert2-integrator.yml`, `convert2-dispatcher.yml`, `convert2-worker.yml`, và `run_agent_from_github_command.ps1`.
   - Nếu phát hiện trùng lặp, workflow lập tức fail (fail-closed).
3. **Loại bỏ hoàn toàn chỉ số độ trễ gán cứng 5800ms:**
   - Thực thi đo lường trực tiếp trên 2 thiết bị vật lý thật (`SM-A075F` và `SM-A507FN`) cho toàn bộ 42 trường hợp kiểm thử.
   - Ghi nhật ký timing raw chi tiết theo từng ca vào `raw/sm_a075f_execution_timing.log`, `raw/sm_a507fn_execution_timing.log`, và `raw/execution_timing.jsonl`.
4. **Ràng buộc xuất xứ (Provenance Binding) trên từng dòng CSV:**
   - Mọi dòng trong `05_COLOR_REALISM_MATRIX.csv`, `06_SKIN_BG_CLOTHING_EXCLUSION.csv`, và `07_PHYSICAL_DEVICE_MATRIX.csv` đều được gắn chặt với: `DeviceSerial`, `DeviceModel`, `WorkerRunId`, `DispatchCommitSha`, `ApkSha256`, `InputImageSha256`, `OutputImageSha256`, `MeasuredLatencyMs`, và `TimestampIso`.
5. **Minh bạch hóa việc mirror Report Drive:**
   - Báo cáo chính xác tình trạng thiếu hụt write credentials của runner đối với thư mục Google Drive của Chủ tịch.
   - Đóng gói toàn bộ chứng cứ vào GitHub Actions Transfer Workflow (`convert2-task027-gallery-transfer.yml`) và niêm phong manifest SHA-256 đối soát.

---

## 2. CHỈ MỤC CÁC TÀI LIỆU KIỂM TOÁN CHI TIẾT
- [`01_COMMAND_LIFECYCLE_DUPLICATES_RECONCILIATION.md`](file:///C:/actions-runner-03/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION/01_COMMAND_LIFECYCLE_DUPLICATES_RECONCILIATION.md): Phân tích nguyên nhân gốc rễ và cơ chế dọn dẹp, hòa giải bất biến vòng đời lệnh.
- [`02_CI_LIFECYCLE_INVARIANTS.md`](file:///C:/actions-runner-03/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION/02_CI_LIFECYCLE_INVARIANTS.md): Chi tiết tích hợp các cổng chặn CI tự động hóa.
- [`03_PHYSICAL_DEVICE_REAL_TIMING_AND_PROVENANCE.md`](file:///C:/actions-runner-03/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION/03_PHYSICAL_DEVICE_REAL_TIMING_AND_PROVENANCE.md): Dữ liệu đo lường độ trễ thực nghiệm và bảng xuất xứ từng test case.
- [`04_PROVENANCE_GUARDS_VERIFICATION.md`](file:///C:/actions-runner-03/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION/04_PROVENANCE_GUARDS_VERIFICATION.md): Kết quả kiểm tra script gác cổng `verify_evidence_provenance_guards.py`.
- [`05_REPORT_DRIVE_CREDENTIALS_AND_MIRROR_MANIFEST.md`](file:///C:/actions-runner-03/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION/05_REPORT_DRIVE_CREDENTIALS_AND_MIRROR_MANIFEST.md): Phân tích trạng thái kết nối Report Drive và kênh truyền dẫn GitHub Artifacts thay thế.
- [`06_FINAL_VERDICT_AND_STATE_HANDOFF.md`](file:///C:/actions-runner-03/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION/06_FINAL_VERDICT_AND_STATE_HANDOFF.md): Kết luận tổng tài và bàn giao trạng thái vòng lặp.
