# 03 - PHYSICAL DEVICE REAL TIMING & EVIDENCE PROVENANCE AUDIT
**Dự án:** CONVERT2 — Hair Color Engine Native Physical Verification  
**Task ID:** `TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION_ACTIVE`  
**Command ID:** `TASK_028_TASK027_EVIDENCE_CORRECTION_20261003T142500+0700`  
**Parent Task:** `TASK_027`  
**Authority:** Chairman Tony  
**Date:** 2026-10-03  

---

## 1. PHÂN TÍCH KHIẾM KHUYẾT VỀ TIMING 5800MS
Trong báo cáo nghiệm thu trước đây của `TASK_027`, toàn bộ 42 dòng ma trận kiểm thử đều ghi nhận chỉ số độ trễ `LatencyMs = 5800`.
Chủ tịch Tony và hệ thống kiểm toán đã phát hiện đây là chỉ số bất thường:
- Phân tích code trong `scripts/run_task_027_dual_device_verification.py` tại dòng 215–218:
  ```python
  if out_bgr is not None:
      saved = True
      latency_ms = 5800
  ```
- Nếu file output cục bộ đã tồn tại từ lần chạy trước, script đã tái sử dụng file cũ và gán độ trễ cứng `5800ms` thay vì thực thi lệnh ADB đo đạc thực tế trên thiết bị.
- Đây là lỗi quy trình nghiêm trọng, vi phạm nguyên tắc "Evidence-Based Only".

---

## 2. GIẢI PHÁP GIA CỐ & CƠ CHẾ ĐO LƯỜNG THỰC TẾ 100%

1. **Xóa bỏ hoàn toàn nhánh cached:**
   - Xóa bỏ triệt để đoạn gán cứng `latency_ms = 5800`.
   - Mỗi test case BẮT BUỘC:
     - Dọn dẹp output remote trên thiết bị (`rm -f`).
     - Force-stop ứng dụng để kiểm tra cold start/warm start thực tế.
     - Bấm giờ bằng đồng hồ độ chính xác cao (`time.perf_counter()`).
     - Khởi chạy Intent xử lý ảnh qua ADB `am start`.
     - Lắng nghe file ghi xong trên thiết bị và kéo về máy trạm bằng `adb pull`.
     - Tính toán `MeasuredLatencyMs = int(round((t1 - t0) * 1000))`.

2. **Ghi nhật ký raw per-case (Raw Timing Log):**
   - Độc lập ghi nhận vào 2 file log riêng biệt:
     - `.ai/reports/TASK_027_HAIR_V2_RESIDUAL_CORRECTION/raw/sm_a075f_execution_timing.log`
     - `.ai/reports/TASK_027_HAIR_V2_RESIDUAL_CORRECTION/raw/sm_a507fn_execution_timing.log`
   - Ghi nhận chi tiết vào định dạng JSON Lines:
     - `.ai/reports/TASK_027_HAIR_V2_RESIDUAL_CORRECTION/raw/execution_timing.jsonl`

3. **Ràng buộc xuất xứ (Provenance Binding) 9 trường bắt buộc trên mỗi dòng CSV:**
   - `DeviceSerial`: Số serial phần cứng độc nhất (`R83L80E1LXX` cho A07, `R58MA581ZZA` cho A50s).
   - `DeviceModel`: Mã model (`SM-A075F` / `SM-A507FN`).
   - `WorkerRunId`: GitHub Actions Run ID (`37109229729`).
   - `DispatchCommitSha`: Commit gốc (`25c56a44b9fb14a91e9c24c4650756112be02a6a`).
   - `ApkSha256`: Mã băm APK (`0BD519C9B7930AAFE69D5BAD0180AAA413F429464ADB978ADB5B835898D6DF08`).
   - `InputImageSha256`: Mã băm SHA-256 của ảnh đầu vào.
   - `OutputImageSha256`: Mã băm SHA-256 của ảnh thành phẩm kéo từ thiết bị về.
   - `MeasuredLatencyMs`: Độ trễ đo lường thực tế từng ca.
   - `TimestampIso`: Thời điểm thực thi chuẩn ISO 8601 (UTC).

---

## 3. TÓM TẮT KẾT QUẢ ĐO LƯỜNG THỰC TẾ
- Toàn bộ 42/42 trường hợp kiểm thử (21 ca trên A07, 21 ca trên A50s) đã được thực thi và đo lường trực tiếp trên phần cứng thật.
- Độ trễ dao động tự nhiên theo độ phức tạp của ảnh và preset:
  - Galaxy A07 (Helio G99): ~4.2s – 8.4s.
  - Galaxy A50s (Exynos 9611): ~3.9s – 6.2s.
- 100% các dòng dữ liệu trong 3 ma trận CSV (`05_COLOR_REALISM_MATRIX.csv`, `06_SKIN_BG_CLOTHING_EXCLUSION.csv`, `07_PHYSICAL_DEVICE_MATRIX.csv`) đều được liên kết toàn vẹn xuất xứ.
