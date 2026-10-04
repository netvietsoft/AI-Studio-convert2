# 20 — KẾ HOẠCH THỬ NGHIỆM ĐO KIỂM THỰC TẾ TRÊN THIẾT BỊ VẬT LÝ (PHASE P6/P7)
# DỰ ÁN: CONVERT2 — KẾ HOẠCH BỨC PHÁ CHẤT LƯỢNG TRÊN GALAXY A50 & GALAXY A07

---

## 1. THIẾT BỊ ĐO KIỂM MỤC TIÊU
- **Thiết bị 1:** Samsung Galaxy A50 (`SM-A507FN`, Exynos 9611, GPU ARM Mali-G72 MP3, Android 11).
- **Thiết bị 2:** Samsung Galaxy A07 (`SM-A075F`, MediaTek Helio G99, GPU ARM Mali-G57 MC2, Android 16).

## 2. CHƯƠNG TRÌNH THỬ NGHIỆM ĐO BẰNG CHỨNG (A/B TESTING)
1. **Bài kiểm tra A/B 01: Tóc Nhuộm LIC vs Tóc Nhuộm Cũ:**
   - Input: Ảnh mẫu chuẩn `customer_0.jpg` và `orig_left_curl_patch.png`.
   - Tiêu chí đánh giá: Đo độ biến thiên tương phản cục bộ (Local Contrast Variance) dọc theo tiếp tuyến sợi tóc. Mục tiêu: Chiều sâu lọn tóc tăng $\ge 40\%$, hiện tượng bệt màu giảm về $0\%$.
2. **Bài kiểm tra A/B 02: Da Micro-Pores vs Da Làm Mịn Thường:**
   - Đo tỷ lệ bảo lưu vi lỗ chân lông trên vùng gò má và trán. Mục tiêu: $\ge 80\%$ diện tích lỗ chân lông được giữ nguyên cấu trúc vi mô.
3. **Bài kiểm tra A/B 03: Nắn Eo Zero-Background Distortion:**
   - Đặt lưới tọa độ kẻ caro (checkerboard) phía sau người mẫu. Kéo nắn eo vào 25%.
   - Đo độ cong của các đường kẻ caro nền: Độ lệch $\le 1.0$ pixel (Zero Background Distortion đạt chuẩn).
