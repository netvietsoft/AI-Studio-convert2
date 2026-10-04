# BÁO CÁO 14: KHOA HỌC MÀU SẮC, ÁNH SÁNG VÀ MÔ PHỎNG KẾT CẤU (COLOR & LIGHTING DEEP DIVE)
## DỰ ÁN: CONVERT2 — TECHNICAL BENCHMARK & RECONSTRUCTION STUDY

---

## 1. KHOA HỌC BẢNG TRA MÀU 3 CHIỀU (3D LUT COLOR SCIENCE)

### 1.1. So Sánh Tra Cứu 2D Atlas và 3D Texture Phần Cứng
- **Giải Pháp 2D Atlas (Phổ Biến ở App Nghiệp Dư):** Trải phẳng khối lập phương màu $64 \times 64 \times 64$ thành một lưới ảnh 2D kích thước $512 \times 512$ gồm 64 ô vuông. Trong Fragment Shader, lập trình viên phải tự tính toán chỉ số slice `z_slice1`, `z_slice2` và thực hiện 2 lần nội suy song tuyến (bilinear) cộng với 1 lần nội suy tuyến tính (lerp). Thao tác này tiêu tốn nhiều lệnh ALU và dễ phát sinh sai số viền ô.
- **Giải Pháp 3D Texture Phần Cứng (FaceApp & VSCO):**
  - Khai báo kết cấu 3 chiều thực thụ: `glTexImage3D` (OpenGL ES 3.0) hoặc `VkImageType = VK_IMAGE_TYPE_3D` (Vulkan).
  - Phần cứng GPU (Hardware Sampler Unit) tự động thực hiện phép **Nội suy tam tuyến tính (Trilinear Interpolation)** hoặc **Nội suy tứ diện (Tetrahedral Interpolation)** trong một chu kỳ xung nhịp duy nhất.
  - Mã Shader tối giản tuyệt đối:
    ```glsl
    #version 300 es
    precision highp float;
    uniform sampler3D uLutSampler;
    in vec2 vTexCoord;
    out vec4 fragColor;
    void main() {
        vec4 src = texture(uSrcTex, vTexCoord);
        // Tra cứu 3D LUT tức thì trong 1 lệnh duy nhất
        vec3 graded = texture(uLutSampler, src.rgb).rgb;
        fragColor = vec4(graded, src.a);
    }
    ```
  - **Lợi ích cho CONVERT2:** Độ trễ giảm xuống dưới 1.5ms, giải phóng hoàn toàn băng thông ALU cho các thuật toán hòa trộn tóc phức tạp.

---

## 2. CHIẾU SÁNG CHÂN DUNG 3D BẰNG HÀM CẦU HÒA ÂM (SPHERICAL HARMONICS)

### 2.1. Ước Tính Pháp Tuyến Bề Mặt Từ Lưới Khuôn Mặt
Facetune và Meitu không cần đo chiều sâu bằng cảm biến LiDAR mà tái tạo bản đồ pháp tuyến (Normal Map) trực tiếp từ các điểm mốc khuôn mặt 3D:
- Với mỗi tam giác lưới khuôn mặt gồm 3 đỉnh $P_1, P_2, P_3$, vector pháp tuyến bề mặt $\vec{N}$ được tính:
  $$\vec{N} = \frac{(P_2 - P_1) \times (P_3 - P_1)}{\|(P_2 - P_1) \times (P_3 - P_1)\|}$$
- Sau đó nội suy mượt mà qua các đỉnh lân cận để tạo bản đồ pháp tuyến liên tục trên toàn bộ da mặt.

### 2.2. Chiếu Sáng Bằng 9 Hệ Số Spherical Harmonics ($L_{l,m}$)
Ánh sáng môi trường và đèn studio được nén thành 9 hệ số hàm cầu hòa âm bậc 2:

$$E(\vec{N}) \approx c_1 L_{0,0} + c_2 (L_{1,-1} N_y + L_{1,0} N_z + L_{1,1} N_x) + c_3 L_{2,0} (3N_z^2 - 1) + c_4 (L_{2,-1} N_y N_x + L_{2,1} N_x N_z + L_{2,-2} (N_x^2 - N_y^2))$$

Khi người dùng di chuyển nguồn sáng ảo trên màn hình:
- Hệ thống chỉ cập nhật lại 9 giá trị float của ma trận ánh sáng.
- Shader tính toán lại độ đổ bóng và ánh sáng viền (Rim Light) trên mặt theo thời gian thực mà không làm bẩn da hay lem sang hậu cảnh.

---

## 3. MÔ PHỎNG HẠT PHIM CHÂN THỰC (VSCO FILM GRAIN ENGINE)

Trong ứng dụng VSCO (`com.vsco.cam`), sự nổi tiếng của các bộ lọc film cổ điển bắt nguồn từ công nghệ mô phỏng hạt bạc nhũ tương (Silver Halide Emulation):
- **Không dùng ảnh tĩnh lặp lại:** VSCO không phủ một tấm ảnh hạt cố định (Static Noise Texture) vì sẽ lộ chu kỳ lặp lại rất thô thiển.
- **Tạo hạt theo hàm phân phối ngẫu nhiên động:**
  Hạt được sinh ra bằng thuật toán giả lập nhiễu Simplex/Perlin kết hợp hàm tán xạ phi tuyến phụ thuộc vào độ sáng vùng ảnh:
  - Vùng tối sâu (Deep Shadows): Hạt thưa và to.
  - Vùng trung tính (Midtones): Mật độ hạt dày đặc và sắc nét nhất.
  - Vùng sáng rực (Highlights): Hạt mịn và bị nén lại.
- Cơ chế này tạo nên chiều sâu cảm xúc nghệ thuật cho bức ảnh, là bài học xuất sắc để CONVERT2 nghiên cứu khi xây dựng các bộ lọc màu cao cấp.
