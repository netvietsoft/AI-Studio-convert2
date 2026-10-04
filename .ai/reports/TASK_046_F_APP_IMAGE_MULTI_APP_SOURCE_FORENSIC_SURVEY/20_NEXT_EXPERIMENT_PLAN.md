# BÁO CÁO 20: KẾ HOẠCH THỰC NGHIỆM TIẾP THEO (NEXT EXPERIMENT PLAN)
## DỰ ÁN: CONVERT2 — TECHNICAL BENCHMARK & RECONSTRUCTION STUDY

---

## 1. MỤC TIÊU THỰC NGHIỆM TRỌNG TÂM

Hiện thực hóa các phát hiện từ cuộc khảo sát pháp y TASK_046 vào môi trường thực tế của CONVERT2 thông qua 4 chiến dịch thực nghiệm R&D có kiểm soát:

### Thực Nghiệm 01: Tích Hợp Guided Filter Cho Mặt Nạ Tóc BiSeNet
- **Mục tiêu:** Xóa bỏ hoàn toàn khuyết tật răng cưa và viền lem màu khi nhuộm tóc.
- **Phương pháp:** Viết Vulkan Compute Shader thực thi thuật toán Guided Filter lấy ảnh xám độ chói (Luma) của ảnh gốc làm ảnh hướng dẫn cho mặt nạ BiSeNet đầu ra.
- **Tiêu chí PASS:**
  - Không còn sợi tóc tơ nào bị đứt đoạn.
  - Tỷ lệ lem màu sang da mặt $\le 0.5\%$.
  - Thời gian chạy trên Galaxy A50 $\le 3.5\text{ ms}$.

### Thực Nghiệm 02: Tái Bơm Vi Lỗ Chân Lông Bằng High-Pass Filter
- **Mục tiêu:** Nâng tỷ lệ bảo tồn kết cấu da micro-pores từ mức hiện tại lên $\ge 85\%$.
- **Phương pháp:** Triển khai shader tách tần số cao và tái bơm hạt da có kiểm soát trọng số `uPoreRetentionWeight`.
- **Tiêu chí PASS:** Đạt điểm Naturalness $\ge 92/100$ và Texture Detail $\ge 90/100$ theo tiêu chuẩn kiểm định `YEUCAU_TEST_ANH.TXT`.

### Thực Nghiệm 03: Chuyển Đổi Tra Màu 3D Sang `VkSampler3D`
- **Mục tiêu:** Tăng tốc độ render LUT thời gian thực.
- **Phương pháp:** Thay thế kết cấu 2D atlas $512 \times 512$ bằng kết cấu 3 chiều thực thụ $33 \times 33 \times 33$ hoặc $64 \times 64 \times 64$ trên Vulkan.
- **Tiêu chí PASS:** Thời gian render khung hình preview $\le 1.8\text{ ms}$.

### Thực Nghiệm 04: Thử Nghiệm Lưới Kép TPS Cho Nắn Dáng Toàn Thân
- **Mục tiêu:** Khẳng định khả năng bóp dáng mà không làm biến dạng nền tường.
- **Phương pháp:** Tích hợp bộ giải ma trận TPS với các điểm neo biên cố định trên lưới nền.
- **Tiêu chí PASS:** Đo đạc độ lệch pixel của đường thẳng nền phía sau cơ thể $\Delta \le 0.5\text{ pixel}$.
