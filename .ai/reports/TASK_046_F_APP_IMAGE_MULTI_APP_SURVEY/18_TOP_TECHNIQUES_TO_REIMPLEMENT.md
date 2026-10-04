# 18 — LỘ TRÌNH TÁI DỰNG SẠCH TOP 10 KỸ THUẬT TINH HOA CHO CONVERT2
# CHƯƠNG TRÌNH HÀNH ĐỘNG NÂNG CẤP CHẤT LƯỢNG VƯỢT TRỘI SO VỚI ĐỐI THỦ CHÂU Á

---

## GIAI ĐOẠN 1: TRIỆT TIÊU LỖI HÌNH ẢNH TRỌNG YẾU (ƯU TIÊN TUYỆT ĐỐI)
1. **Nâng cấp Shader Tóc lên 21-tap LIC (Directional Line Integral Convolution):**
   - Thay thế shader làm mờ tóc hiện tại bằng 5-pass LIC shader.
   - Thiết lập ngưỡng $threshold = 0.005$ và $gain = 0.5$.
   - Cam kết: Triệt tiêu 100% cảm giác "bệt màu như sơn", bảo toàn chiều sâu lọn tóc.
2. **Tích hợp Tách Biên Mặt Nạ Guided Filter:**
   - Thay thế phép feather Gauss đơn giản bằng Guided Filter sử dụng kênh độ chói Y làm hướng dẫn.
   - Cam kết: Tóc tơ, sợi con ở viền trán và vành tai không bị mất, không lem màu ra nền.
3. **Nâng cấp Nắn Bóp Cơ Thể Bảo Vệ Nền (Zero Background Distortion):**
   - Tích hợp mặt nạ phân đoạn cơ thể vào vertex shader nắn bóp.
   - Cam kết: Nắn eo và bắp tay mà khung cửa, gạch tường thẳng tắp 100%.

## GIAI ĐOẠN 2: NÂNG TẦM ĐỘ TỰ NHIÊN DA & MÀU SẮC (ƯU TIÊN CAO)
4. **Triển khai Phân Tách Tần Số Kép Cho Da (Dual-Pass Frequency Separation):**
   - Tách da thành lớp màu (low-freq) và lớp vân lỗ chân lông (high-freq).
   - Cam kết: Giữ lại $\ge 75\%$ vi lỗ chân lông, da láng mịn nhưng chân thực.
5. **Nội suy Khối Tứ diện 3D LUT (Tetrahedral Interpolation):**
   - Chuyển đổi toàn bộ shader áp LUT sang giải thuật tứ diện.
   - Cam kết: Không còn hiện tượng vỡ dải màu (banding/tearing) trên da.
6. **Mô phỏng Hạt Phim Điều Chế Theo Độ Chói (Luminance Film Grain):**
   - Bổ sung pass tạo hạt analog nhẹ nhàng vào vùng midtones của da.
