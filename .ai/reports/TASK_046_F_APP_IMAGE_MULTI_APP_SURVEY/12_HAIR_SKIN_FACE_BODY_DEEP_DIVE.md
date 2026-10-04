# 12 — NGHIÊN CỨU CHUYÊN SÂU LÕI TÓC, DA, KHUÔN MẶT & VÓC DÁNG
# TÀI LIỆU KHẢO SÁT THUẬT TOÁN ĐẦY ĐỦ CHỨNG CỨ TỪ 14 ỨNG DỤNG (F:\APP\IMAGE)

---

## 1. THUẬT TOÁN TÓC: GIẢI PHÁP TRIỆT TIÊU HIỆN TƯỢNG BỆT MÀU NHƯ SƠN

### 1.1 Nguyên nhân Gốc rễ của Lỗi Tóc Bệt Màu (Muddy / Flat Painted Look)
Trong các phiên bản thử nghiệm trước đây của CONVERT2, việc nhuộm tóc sử dụng bộ lọc làm mờ đẳng hướng (Isotropic Gaussian Blur) kết hợp với hòa trộn màu Soft Light hoặc Multiply.
- **Khiếm khuyết toán học:** Tóc tự nhiên là một cấu trúc dạng sợi có tính dị hướng cao (anisotropic). Khi làm mờ đẳng hướng, màu sắc bị khuếch tán đều theo mọi hướng (cả dọc và ngang sợi tóc), làm triệt tiêu hoàn toàn sự tương phản giữa sợi tóc sáng và sợi tóc tối, biến khối tóc thành một mảng màu bệt phẳng lì như sơn tường.

### 1.2 Giải pháp Tinh hoa từ Meitu `libMTFilterKernel.so` (`MTFilterKernel::CMTFilterSoftHair`)
Bằng chứng dịch ngược lệnh máy ARM64 trong `libMTFilterKernel.so` tại địa chỉ `0x000f3f58` xác nhận quy trình 5-pass tuần tự:
1. **Pass 1 — Bản đồ Độ chói (Luminance Map):** Chuyển ảnh RGB sang kênh Y chuẩn BT.601:
   $$Y = 0.299 R + 0.587 G + 0.114 B$$
2. **Pass 2 — Trường Ten-xơ Cấu trúc Góc Kép (Double-Angle Structure Tensor):**
   Tính gradient Sobel $g_x, g_y$. Để tránh trường hợp hai sợi tóc có gradient ngược hướng nhau triệt tiêu nhau, thuật toán mã hóa góc đôi:
   $$\vec{v} = \left( \frac{g_x^2 - g_y^2}{|g|^2 + \epsilon}, \frac{2 g_x g_y}{|g|^2 + \epsilon} \right)$$
3. **Pass 3 & 4 — Làm mịn Trường Hướng Tách Rời (Separable Gaussian Smoothing):**
   Sử dụng kernel 5-tap tách rời với trọng số chuẩn xác từng bit trích xuất từ rodata `0x0008edd8`:
   $$W = [0.159676, 0.263348, 0.122118, 0.030573, 0.004122]$$
4. **Pass 5 — Tích phân Đường Định hướng 21-tap (21-tap Directional LIC):**
   Thay vì lấy mẫu theo hình tròn, thuật toán di chuyển 10 bước về phía trước và 10 bước về phía sau dọc theo tiếp tuyến sợi tóc $\hat{t} = (-v_y, v_x)$:
   $$I_{\text{lic}}(\vec{p}) = \sum_{k=-10}^{10} w_k \cdot I\left(\vec{p} + k \cdot \Delta s \cdot \hat{t}(\vec{p})\right)$$
   Với bảng trọng số 10-tap:
   $$w = [1.0, 0.9802, 0.9231, 0.8353, 0.7261, 0.6065, 0.4868, 0.3753, 0.2780, 0.1979]$$
   Hệ số tăng ích $gain = 0.5$, ngưỡng nhạy cảm tóc tơ $threshold = 0.005$.
5. **Pass 6 — Tăng cường Độ trong trẻo & Hòa trộn Soft Light (Clarity Boost):**
   Áp dụng unsharp mask 9x9 tại offset `0x77afa` với hệ số độ trong trẻo $clarity = 0.4$, sau đó hòa trộn Soft Light với màu mục tiêu.

---

## 2. THUẬT TOÁN DA: BẢO TỒN VI LỖ CHÂN LÔNG & BẢO VỆ KẾT CẤU TỰ NHIÊN

### 2.1 Kỹ thuật Phân tách Tần số Kép (Dual-Pass Frequency Separation) — Facetune & Ulike
Facetune và Ulike dẫn đầu thế giới về khả năng làm mịn da nhưng vẫn giữ được độ sắc nét của lỗ chân lông.
- **Phương trình phân rã:**
  $$I_{\text{low}} = \text{BilateralFilter}(I, \sigma_s = 5.0, \sigma_r = 0.12)$$
  $$I_{\text{high}} = I - I_{\text{low}} + 0.5$$
- **Điều chế làm mịn:**
  Người dùng chỉ điều chỉnh độ mờ trên lớp $I_{\text{low}}$, làm đều màu da và xóa vết thâm đỏ. Lớp $I_{\text{high}}$ được lọc qua một ngưỡng nhạy cảm để giữ lại vân da lỗ chân lông ($pore \ge 75\%$):
  $$I_{\text{final}} = I_{\text{low, smooth}} + (I_{\text{high}} - 0.5) \cdot \alpha_{\text{texture}}$$

---

## 3. THUẬT TOÁN NẮN CHỈNH VÓC DÁNG: BẢO VỆ NỀN KHÔNG CAN THIỆP (ZERO BACKGROUND DISTORTION)

### 3.1 Vấn đề cốt lõi của nắn bóp Liquify thông thường
Khi kéo nắn eo hoặc bắp tay bằng công cụ Liquify thông thường, bán kính ảnh hưởng $R$ sẽ kéo lệch cả nền tường, khung cửa sổ hoặc hoa văn gạch phía sau cơ thể.

### 3.2 Thuật toán Điều chế Bằng Mặt Nạ Người (Human Parsing Mask Modulation) — Meitu `libMTBeautyEngine.so`
Thuật toán phân tách vector dời hình $\Delta \vec{p}$ qua mặt nạ phân đoạn cơ thể người $M_{\text{body}} \in [0.0, 1.0]$:
$$\Delta \vec{p}_{\text{effective}} = \Delta \vec{p} \cdot \left( 1 - \left( \frac{\|\vec{p} - \vec{c}\|}{R} \right)^2 \right)^3 \cdot M_{\text{body}}(\vec{p})$$
- Tại vùng cơ thể người ($M_{\text{body}} = 1.0$): Lực kéo đạt giá trị tối đa 100%, cơ thể co gọn theo ý muốn.
- Tại vùng nền xung quanh ($M_{\text{body}} = 0.0$): Vector kéo bị triệt tiêu về 0, nền tường và khung cửa đứng yên tuyệt đối, đảm bảo tiêu chuẩn Zero Leakage.
