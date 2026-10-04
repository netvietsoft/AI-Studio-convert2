# Thuật Toán Nhuộm Tóc Tự Nhiên & Giữ Chi Tiết Sợi Tóc
**Phân hệ:** P0 Core Hair Color Engine  
**Tiêu chuẩn:** Development Workspace Standard V2.1  

### 1. Chuỗi thuật toán hoàn chỉnh
1. **Trích xuất nền Luminance** từ ảnh gốc RGBA.
2. **Khử lem biên & tạo dải mềm** trên mặt nạ tóc nơ-ron Class 17.
3. **Làm mờ Gauss tần số thấp** 2D tách biệt bằng bảng 5 trọng số `[0.159676, 0.263348, 0.122118, 0.030573, 0.004122]`.
4. **Trích xuất chi tiết tần số cao Unsharp Mask** với độ trong trẻo `0.4` và bù sáng `1.8`.
5. **Hòa trộn màu nhuộm bằng công thức Pegtop SoftLight**:
   $$f(a, b) = (1 - 2b) a^2 + 2ba$$
6. **Ghép bóng sáng đẳng hướng 21-tap LIC** dọc theo hướng ten-xơ sợi tóc.
7. **Bảo vệ tuyệt đối vùng không can thiệp** (Zero leakage).
