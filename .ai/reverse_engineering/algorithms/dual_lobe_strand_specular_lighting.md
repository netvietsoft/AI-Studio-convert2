# dual_lobe_strand_specular_lighting.md — MÔ HÌNH PHẢN XẠ ÁNH SÁNG HAI THÙY DỌC SỢI TÓC (MARSCHNER / DUAL-LOBE SPECULAR)
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Phân hệ:** Core C++ Native Image Engine / Hair Shading  
**Thư viện tham chiếu:** `libLayerFlow.so` (0x00078000 - 0x00085000), `libMTFilterKernel.so`  
**Trạng thái Pháp lý:** **RULE 11 CLEAN-ROOM SPECIFICATION**  

---

## 1. NGUYÊN LÝ QUANG HỌC SỢI TÓC TỰ NHIÊN
Tóc con người không phải là một mặt cầu trơn hay bề mặt Lambertian phẳng, mà là một hình trụ sợi quang có lớp vảy biểu bì (cuticle scales) nghiêng một góc cố định $\alpha \approx 2.5^\circ - 3.5^\circ$ về phía ngọn tóc.

Hiện tượng tán xạ ánh sáng trên sợi tóc được cấu tạo bởi hai thành phần phản xạ chính:
1. **Thùy $R$ (Primary Reflection Lobe):** Tia sáng phản chiếu trực tiếp từ mặt ngoài lớp biểu bì. Do vảy nghiêng, góc phản xạ bị lệch về phía chân tóc một góc $\alpha = +3.0^\circ$. Ánh sáng của thùy $R$ giữ nguyên màu của nguồn sáng (ánh sáng trắng / specular highlight sắc nét).
2. **Thùy $TRT$ (Secondary Internal Reflection Lobe):** Tia sáng khúc xạ đi vào trong lõi sợi tóc (cortex), phản xạ tại mặt sau và khúc xạ thoát ra ngoài. Tia này đi qua thể tích sợi tóc, bị hấp thụ bởi các hạt sắc tố melanin và màu nhuộm hóa học, sau đó thoát ra với góc lệch $\beta = -6.0^\circ$ (lệch về phía ngọn tóc). Ánh sáng của thùy $TRT$ mang màu đậm đà của thuốc nhuộm và tạo nên ánh kim lung linh (colored sheen).

---

## 2. CÔNG THỨC TOÁN HỌC DUAL-LOBE SHADING
Cho vector tiếp tuyến dòng sợi tóc tại điểm ảnh là $\mathbf{T}$, vector pháp tuyến bề mặt đầu là $\mathbf{N}$, vector hướng ánh sáng tới là $\mathbf{L}$, và vector hướng mắt nhìn camera là $\mathbf{V}$.

1. **Góc lệch tiếp tuyến của tia tới và tia nhìn:**
   $$\sin \theta_i = \mathbf{T} \cdot \mathbf{L}, \quad \cos \theta_i = \sqrt{1 - \sin^2 \theta_i}$$
   $$\sin \theta_r = \mathbf{T} \cdot \mathbf{V}, \quad \cos \theta_r = \sqrt{1 - \sin^2 \theta_r}$$
   Góc chênh lệch dọc trục sợi tóc: $\theta_d = (\theta_r - \theta_i) / 2$, $\theta_h = (\theta_r + \theta_i) / 2$.

2. **Cường độ thùy phản xạ bề mặt $S_R$ (Primary Highlight):**
   $$S_R = \exp \left( - \frac{(\theta_h - \alpha_R)^2}{2 \sigma_R^2} \right)$$
   Với góc nghiêng biểu bì $\alpha_R \approx +0.055 \text{ rad} \ (\approx 3.15^\circ)$, độ nhám bề mặt $\sigma_R \approx 0.08$.

3. **Cường độ thùy phản xạ nội vùng $S_{TRT}$ (Secondary Colored Sheen):**
   $$S_{TRT} = \exp \left( - \frac{(\theta_h - \alpha_{TRT})^2}{2 \sigma_{TRT}^2} \right)$$
   Với góc nghiêng $\alpha_{TRT} \approx -0.11 \text{ rad} \ (\approx -6.3^\circ)$, độ mở rộng tán xạ $\sigma_{TRT} \approx 0.16$.

4. **Tổng hợp màu nhuộm bóng tóc:**
   $$\mathbf{C}_{\text{highlight}} = k_R \cdot S_R \cdot \mathbf{C}_{\text{light}} + k_{TRT} \cdot S_{TRT} \cdot \mathbf{C}_{\text{dye\_accent}}$$
   $$\mathbf{C}_{\text{final}} = \mathbf{C}_{\text{base\_dyed}} + \mathbf{C}_{\text{highlight}} \cdot M_{\text{hair\_mask}}$$

---

## 3. Ý NGHĨA ĐỐI VỚI CHỈ TIÊU "KHÔNG BỆT MÀU NHƯ SƠN"
Nhờ thùy $TRT$ mang màu nhuộm lấp lánh kết hợp thùy $R$ trắng bạc tạo điểm nhấn độ sáng, sợi tóc kết xuất có độ sâu quang học 3 chiều lập thể, loại bỏ hoàn toàn cảm giác một mảng màu bệt đồng nhất như sơn tường.
