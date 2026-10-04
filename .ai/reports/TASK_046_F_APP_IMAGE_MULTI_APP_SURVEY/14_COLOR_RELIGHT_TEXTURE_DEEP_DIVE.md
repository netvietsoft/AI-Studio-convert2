# 14 — NGHIÊN CỨU CHUYÊN SÂU KHOA HỌC MÀU SẮC, CHIẾU SÁNG & BẢO TOÀN VÂN BỀ MẶT
# TÀI LIỆU KHẢO SÁT MÀU SẮC & KẾT CẤU 14 ỨNG DỤNG (F:\APP\IMAGE)

---

## 1. NỘI SUY KHỐI TỨ DIỆN 3D LUT (TETRAHEDRAL INTERPOLATION) — VSCO & ADOBE

### 1.1 Khiếm khuyết của Nội suy Trilinear (Trilinear Interpolation)
Nội suy trilinear phổ biến lấy mẫu 8 đỉnh của hình lập phương bao quanh điểm tọa độ màu $(r, g, b)$. Tuy nhiên, phép nội suy này tạo ra các sai số phi tuyến trên đường chéo chính của khối màu, dẫn đến hiện tượng vỡ màu hoặc các vệt bậc thang (contouring artifacts) khi chuyển từ vùng da sáng sang vùng tối.

### 1.2 Giải pháp Nội suy Tứ diện (Tetrahedral Interpolation)
Thuật toán chia khối lập phương đơn vị thành 6 khối tứ diện không giao nhau dựa trên thứ tự độ lớn của phần dư $(\Delta r, \Delta g, \Delta b)$:
- Nếu $\Delta r > \Delta g > \Delta b$: Điểm nằm trong Tứ diện 1.
- Điểm màu được tính bằng tổ hợp tuyến tính của chỉ 4 đỉnh của tứ diện tương ứng.
- **Lợi ích:** Đảm bảo tính liên tục $C^0$, bảo toàn gradient màu siêu mịn trên tóc và da.

---

## 2. CHIẾU SÁNG CHÂN DUNG 9 HỆ SỐ HÌNH CẦU (SPHERICAL HARMONICS) — FACEAPP

Phương pháp Spherical Harmonics (Basri & Jacobs) cho phép tái tạo nguồn sáng môi trường phức tạp chỉ bằng 9 hệ số thực:
$$L(\vec{n}) = c_0 Y_0^0 + c_1 Y_1^{-1} + c_2 Y_1^0 + c_3 Y_1^1 + c_4 Y_2^{-2} + c_5 Y_2^{-1} + c_6 Y_2^0 + c_7 Y_2^1 + c_8 Y_2^2$$
Trong đó $\vec{n} = (n_x, n_y, n_z)$ là vector pháp tuyến bề mặt khuôn mặt được nội suy từ 106 điểm landmarks.
Ánh sáng mới được nhân với bản đồ phản xạ Albedo để tạo nên hiệu ứng chiếu sáng 3D sống động.
