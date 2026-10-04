# tetrahedral_3d_lut_color_grading.md — THUẬT TOÁN NỘI SUY TỨ DIỆN BẢNG TRA MÀU 3D (33x33x33 3D LUT)
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Phân hệ:** Core C++ Native Image Engine / Color Grading  
**Thư viện tham chiếu:** `libPVGColorFunctions.so` (0x0000e000 - 0x00015000), `libMTFilterKernel.so`  
**Trạng thái Pháp lý:** **RULE 11 CLEAN-ROOM SPECIFICATION**  

---

## 1. BỐI CẢNH VÀ NGUYÊN LÝ VẬN HÀNH
Trong quy trình nhuộm tóc chuyên nghiệp (đặc biệt các tông màu sáng, bạch kim, pastel, khói), việc sử dụng phép nội suy tam tuyến tính (Trilinear Interpolation) thông thường trên lưới 3D LUT 33x33x33 gây ra hiện tượng đường biên chuyển sắc không liên tục (diagonal banding và color contouring) tại các góc khối lập phương.

Để khắc phục triệt để, hệ thống sử dụng thuật toán **Nội suy Tứ Diện (Tetrahedral Interpolation)**:
Mỗi ô lập phương đơn vị được chia thành đúng **6 khối tứ diện (tetrahedra)** dựa trên quan hệ so sánh tương đối giữa ba thành phần độ lệch nội suy $(\Delta r, \Delta g, \Delta b)$:

1. **Khối 1** ($\Delta r \ge \Delta g \ge \Delta b$): Điểm nằm trong tứ diện nối đỉnh $(0,0,0) \to (1,0,0) \to (1,1,0) \to (1,1,1)$.
2. **Khối 2** ($\Delta r \ge \Delta b > \Delta g$): Điểm nằm trong tứ diện nối đỉnh $(0,0,0) \to (1,0,0) \to (1,0,1) \to (1,1,1)$.
3. **Khối 3** ($\Delta g > \Delta r \ge \Delta b$): Điểm nằm trong tứ diện nối đỉnh $(0,0,0) \to (0,1,0) \to (1,1,0) \to (1,1,1)$.
4. **Khối 4** ($\Delta g \ge \Delta b > \Delta r$): Điểm nằm trong tứ diện nối đỉnh $(0,0,0) \to (0,1,0) \to (0,1,1) \to (1,1,1)$.
5. **Khối 5** ($\Delta b > \Delta r \ge \Delta g$): Điểm nằm trong tứ diện nối đỉnh $(0,0,0) \to (0,0,1) \to (1,0,1) \to (1,1,1)$.
6. **Khối 6** ($\Delta b > \Delta g > \Delta r$): Điểm nằm trong tứ diện nối đỉnh $(0,0,0) \to (0,0,1) \to (0,1,1) \to (1,1,1)$.

---

## 2. CÔNG THỨC TOÁN HỌC NỘI SUY TỨ DIỆN
Cho điểm màu đầu vào chuẩn hóa $\mathbf{C} = [r, g, b]^T \in [0, 1]^3$, tọa độ chỉ số thực trên lưới kích thước $N = 33$:
$$x = r \cdot (N - 1), \quad y = g \cdot (N - 1), \quad z = b \cdot (N - 1)$$
Chỉ số nguyên góc đáy:
$$i = \lfloor x \rfloor, \quad j = \lfloor y \rfloor, \quad k = \lfloor z \rfloor$$
Độ lệch phần phân số:
$$\Delta r = x - i, \quad \Delta g = y - j, \quad \Delta b = z - k$$

Với trường hợp Khối 1 ($\Delta r \ge \Delta g \ge \Delta b$), giá trị màu kết xuất $\mathbf{C}_{out}$ là tổ hợp tuyến tính của 4 đỉnh tứ diện:
$$\mathbf{C}_{out} = (1 - \Delta r) \cdot L(i, j, k) + (\Delta r - \Delta g) \cdot L(i+1, j, k) + (\Delta g - \Delta b) \cdot L(i+1, j+1, k) + \Delta b \cdot L(i+1, j+1, k+1)$$

Trong đó $L(u, v, w)$ là hàm lấy mẫu màu tại nút lưới 3D LUT tương ứng.

---

## 3. LỢI ÍCH KỸ THUẬT ĐỐI VỚI LÕI NHUỘM TÓC
1. **Triệt tiêu Banding:** Các đường đẳng mức màu (isophotes) chuyển động mượt mà, không bị gãy góc ở ranh giới các block 3D.
2. **Bảo tồn sắc độ tối (Dark Hair Preservation):** Giữ vững các chi tiết bóng tối của tóc đen châu Á khi nhuộm phủ màu khói lạnh.
3. **Hiệu năng GPU:** Khối lượng tính toán chỉ gồm 4 lần lấy mẫu kết hợp các lệnh nhân cộng (FMA - Fused Multiply Add), tối ưu hóa hoàn hảo trên GPU Adreno và Mali ARM64.
