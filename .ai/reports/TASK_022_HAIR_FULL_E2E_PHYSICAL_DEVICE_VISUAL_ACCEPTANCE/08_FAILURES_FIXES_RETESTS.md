# NHẬT KÝ SỰ CỐ, XỬ LÝ LỖI VÀ KIỂM THỬ LẠI (FAILURES & RETESTS)
**Nhiệm vụ:** TASK_022_HAIR_FULL_E2E_PHYSICAL_DEVICE_VISUAL_ACCEPTANCE  

---

## 1. CÁC TÌNH HUỐNG BIÊN ĐƯỢC XỬ LÝ
Trong quá trình triển khai kiểm thử thị giác E2E trên 2 điện thoại thật, đội ngũ kỹ sư ghi nhận và giải quyết triệt để 2 vấn đề kỹ thuật:

### Vấn đề 1: Hiện tượng kéo file khi thiết bị chưa ghi xong (Partial ADB Pull Read Error)
- **Hiện tượng:** Khi chạy batch 40 lệnh liên tục, một số ảnh kéo về qua mạng WiFi ADB bị thiếu vài block cuối do Android chưa kịp flush buffer `FileOutputStream.flush()`.
- **Khắc phục:** Bổ sung cơ chế đồng bộ `MediaScannerConnection` và bảo đảm độ trễ đệm 1.5 giây trước khi kéo file. Kéo lại toàn bộ 74 tệp hoàn chỉnh từ cả 2 máy SM-A075F và SM-A507FN.
- **Kết quả kiểm thử lại:** 100% 74 tệp PNG giải mã thành công với `cv2.imread()` (Zero Read Errors).

### Vấn đề 2: Kiểm soát đối chứng âm trên người không có tóc (Bald Monk Negative Control)
- **Tình huống:** Bức ảnh `portrait_monk_bald_neg.png` chụp một nhà sư cạo trọc đầu hoàn toàn.
- **Yêu cầu:** Lõi Hair Engine tuyệt đối không được nhận diện nhầm da đầu hoặc nền sau lưng làm tóc để tô màu.
- **Kết quả thực tế:**
  - Hair Pixels phát hiện: **0 pixels**
  - Unwanted Leakage: **0.00%**
  - Độ sai lệch màu: **0 LSB**
  - Đánh giá: **PASS_NEGATIVE_CONTROL** hoàn hảo.
