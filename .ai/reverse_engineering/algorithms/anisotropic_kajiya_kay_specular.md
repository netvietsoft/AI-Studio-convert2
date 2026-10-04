# ALGORITHM SPECIFICATION: Anisotropic Kajiya-Kay Hair Specular Shading
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Rule 11 Clean-Room  
**Lớp Thuật Toán:** Quang học bề mặt sợi tóc bán trong suốt (Hair Strand Optics)  
**Mục tiêu Kỹ thuật:** Tạo ánh kim lọn tóc chuyển động theo góc nhìn, ngăn ngừa bệt màu và duy trì độ bóng sâu tự nhiên.

---

## 1. MÔ HÌNH TOÁN HỌC KAJIYA-KAY CẢI TIẾN
Mô hình tán xạ ánh sáng trên sợi tóc hình trụ một chiều (1D cylinder approximation):
$$I_{spec} = k_s \sum_{i=1}^{2} w_i \cos^n(\theta - \theta_{shift, i})$$

Trong đó:
- $\mathbf{T}$: Vector tiếp tuyến hướng sợi tóc trích xuất từ cấu trúc ten-xơ dòng tóc (`structure_tensor_orientation`).
- $\mathbf{L}$: Vector hướng nguồn sáng chuẩn hóa.
- $\mathbf{V}$: Vector hướng người nhìn (view direction).
- $\sin(\theta_L) = \mathbf{T} \cdot \mathbf{L}$, $\sin(\theta_V) = \mathbf{T} \cdot \mathbf{V}$.
- Tán xạ phản xạ bậc một (R lobe - ánh kim sơ cấp, không đổi màu): $\theta_{shift, 1} = -3^\circ \dots -5^\circ$, độ sắc nét $n_1 = 64.0$.
- Tán xạ phản xạ bậc hai (TRT lobe - ánh kim thứ cấp mang sắc tố nhuộm tóc): $\theta_{shift, 2} = +6^\circ \dots +10^\circ$, độ sắc nét $n_2 = 24.0$.

---

## 2. TÍNH TOÁN DÒNG TIẾP TUYẾN 2D TRÊN MẶT PHẲNG ẢNH
Do đầu vào là ảnh tĩnh 2D chân dung, hướng tiếp tuyến $\mathbf{T}$ tại tọa độ $(x, y)$ được nội suy từ trường hướng vector $\mathbf{v}(x,y) = (\cos \phi, \sin \phi)$:
$$\mathbf{T}_{2D} = \begin{pmatrix} -\sin \phi \\ \cos \phi \end{pmatrix}$$

Độ bóng sáng cục bộ được điều biến bởi hệ số mặt nạ tóc $M_{hair}(x,y) \in [0, 1]$ và tham số cường độ ánh kim `fShineIntensity` do người dùng thiết lập trên thanh trượt UI.

---

## 3. BẢO TỒN ĐỘ ĐẬM NHẠT VÙNG TỐI (SHADOW PRESERVATION)
Để không làm bạc màu các vùng tóc khuất sáng, hệ số phản xạ được nhân với kênh độ chói gốc $Y_{BT601}$:
$$I_{final\_spec} = I_{spec} \cdot \sqrt{Y_{BT601}} \cdot fShineIntensity$$
Kênh này ngăn ngừa hiện tượng lóa bạc ở các lọn tóc tối màu và giữ trọn vẹn chiều sâu ba chiều của mái tóc.
