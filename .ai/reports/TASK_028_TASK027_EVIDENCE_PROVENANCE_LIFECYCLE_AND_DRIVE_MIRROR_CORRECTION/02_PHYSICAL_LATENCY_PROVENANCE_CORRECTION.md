# 02 — BÁO CÁO LOẠI BỎ ĐỘ TRỄ GIẢ VÀ RÀNG BUỘC PROVENANCE VẬT LÝ THỰC (PHYSICAL LATENCY PROVENANCE CORRECTION)

**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION_ACTIVE`  
**Command ID:** `TASK_028_TASK027_EVIDENCE_CORRECTION_20261003T142500+0700`  
**Thẩm quyền ban hành:** Chủ tịch Tony & Agent 0  
**Ngày:** 2026-10-03  

---

## 1. NGUYÊN NHÂN GỐC RỄ: KHẢO SÁT ĐOẠN MÃ ĐỘ TRỄ GÁN CỨNG (5800MS SHORTCUT)

Trong đợt audit trước, Chủ tịch Tony và hệ thống Audit phát hiện toàn bộ 42 ca kiểm thử trên cả hai thiết bị vật lý `SM-A075F` và `SM-A507FN` đều ghi nhận giá trị độ trễ đồng nhất `5800ms`.
Kiểm tra mã nguồn `scripts/run_task_027_dual_device_verification.py` phát hiện lỗi:
```python
# LỖI CŨ TẠI DÒNG 211-218 CỦA SCRIPT CŨ:
out_bgr = None
if os.path.exists(local_out) and os.path.getsize(local_out) > 1000:
    out_bgr = cv2.imread(local_out)

if out_bgr is not None:
    saved = True
    latency_ms = 5800  # <--- GÁN CỨNG ĐỘ TRỄ GIẢ NẾU FILE ĐÃ TỒN TẠI!
```
Hành vi này hoàn toàn vi phạm Hiến pháp Vận hành CONVERT2 (Evidence-Based Only, Tuyệt đối cấm báo cáo sai sự thật).

---

## 2. GIẢI PHÁP ĐIỀU CHỈNH TRIỆT ĐỂ: LIVE ADB PHYSICAL TIMING

Đoạn code shortcut trên đã bị **XÓA BỎ HOÀN TOÀN**. Thay vào đó, toàn bộ 42 lượt kiểm thử bắt buộc phải thực thi trực tiếp, tươi mới trên thiết bị vật lý qua ADB:
1. **Xóa sạch bộ nhớ đệm và file xuất trước mỗi lượt chạy:**
   - Xóa file output cục bộ: `os.remove(local_out)`
   - Đánh thức màn hình: `svc power stayon true; input keyevent KEYCODE_WAKEUP`
   - Dừng bắt buộc tiến trình app: `am force-stop com.mt.mtxx.mtxx.convert`
   - Xóa file trên thiết bị: `rm -f /sdcard/Android/data/com.mt.mtxx.mtxx.convert/files/{out_base}`
2. **Đo thời gian thực độ phân giải cao (`time.perf_counter()`):**
   - Bắt đầu bấm giờ `t0 = time.perf_counter()` ngay trước khi gửi lệnh `am start`.
   - Bắn Intent `PhotoEditorActivity` với các cờ `image_path`, `tool_id`, `intensity`, `auto_save_path`.
   - Thăm dò liên tục trạng thái ghi file: theo dõi sự xuất hiện của file và kích thước ổn định (đảm bảo `FileOutputStream.flush()` và `close()` hoàn tất 100%).
   - Ghi nhận `t1 = time.perf_counter()`, tính toán độ trễ chính xác:
     `latency_ms = int(round((time.perf_counter() - t0) * 1000.0))`
3. **Kéo file và kiểm tra mã băm:**
   - Kéo file thực tế từ thiết bị về bằng `adb pull`.
   - Tính mã băm SHA-256 đầu vào: `InputSha256 = sha256_file(in_local)`
   - Tính mã băm SHA-256 đầu ra: `OutputSha256 = sha256_file(local_out)`

---

## 3. RÀNG BUỘC DỮ LIỆU NGUỒN GỐC TOÀN DIỆN (PROVENANCE METADATA BINDING)

Mỗi hàng dữ liệu trong tất cả các bảng CSV (`05_COLOR_REALISM_MATRIX.csv`, `06_SKIN_BG_CLOTHING_EXCLUSION.csv`, `07_PHYSICAL_DEVICE_MATRIX.csv`) đều được liên kết chặt chẽ với bộ định danh hệ thống:
- **`DeviceSerial`**: Địa chỉ kết nối phần cứng thực (VD: `192.168.1.18:40159` cho A07, `192.168.1.2:41775` cho A50s).
- **`WorkerRunId`**: GitHub Actions Workflow Run ID (`37106538676`).
- **`WorkerJobId`**: Định danh job thực thi của Worker (`job-37106538676`).
- **`SourceCommit`**: Commit SHA tại thời điểm thực thi.
- **`ApkSha256`**: Mã băm SHA-256 của file APK thực tế đã cài đặt trên máy (`7C60B9F7305BA1B10A055F483215A81C5F11D3AD115CAE0465769F89CA694F64`).
- **`InputSha256`**: Mã băm SHA-256 của ảnh chân dung đầu vào.
- **`OutputSha256`**: Mã băm SHA-256 của ảnh kết quả sinh ra bởi Native C++ Engine trên máy vật lý.
- **`Timestamp`**: Thời điểm ISO 8601 chính xác khi ca kiểm thử hoàn thành.
- **`HumanVisualVerdict`**: Trạng thái đánh giá cảm quan thị giác con người (bảo vệ chống visual failure).
- **`Verdict`**: Phán quyết tổng thể của ca kiểm thử.
