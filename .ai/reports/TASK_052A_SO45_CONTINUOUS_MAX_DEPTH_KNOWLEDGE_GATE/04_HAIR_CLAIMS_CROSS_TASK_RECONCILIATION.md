# 04_HAIR_CLAIMS_CROSS_TASK_RECONCILIATION.md — ĐỐI SOÁT & ĐÍNH CHÍNH TUYỆT ĐỐI CÁC TUYÊN BỐ VỀ TÓC (HAIR CLAIMS RECONCILIATION)

**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Mã Nhiệm vụ:** `TASK_052A_SO45_CONTINUOUS_MAX_DEPTH_KNOWLEDGE_GATE_ACTIVE`  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Mục tiêu:** Đối chiếu, phân xử và chuẩn hóa toàn bộ các tuyên bố kỹ thuật về phân hệ Tóc (Hair) qua chuỗi nhiệm vụ `TASK_038`, `TASK_045`, `TASK_047`, `TASK_048`, và `TASK_051`.

---

## 1. BẢNG TỔNG HỢP SO SÁNH & XÁC NHẬN CHÂN LÝ TỪNG TUYÊN BỐ

| Hạng Mục Đối Soát | TASK_038 (RVA & Shaders) | TASK_047 (Deep Mapping) | TASK_048 (Evidence Expansion) | TASK_051 (Max-Depth) | Chân Lý Xác Thực Kỹ Thuật (Ground Truth at TASK_052A) |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Số Lượng Pass Xử Lý** | 5 FBO passes trong native `CMTFilterSoftHair` | 8 giai đoạn toàn trình từ UI | 8 giai đoạn khép kín (UI -> Mask -> Matting -> Orientation -> LIC -> Blend) | 5 FBO passes trong `MTSoftHairFilter` | **CẢ HAI ĐỀU ĐÚNG Ở HAI TẦNG KHÁC NHAU:**<br>- **Tầng Hệ Thống (End-to-End):** 8 giai đoạn (BiSeNet/MediaPipe Mask -> Feather Matting -> Luminance -> Tensor Field -> Blur -> Anisotropic -> LUT -> Composite).<br>- **Tầng Lõi Core C++ (`libMTFilterKernel.so`):** Chính xác 5 FBO passes của `CMTFilterSoftHair`. |
| **Bản Chất Pass 1** | Grayscale Luminance (`0x13488c`), BT.601 weights `[0.2989, 0.5866, 0.1145]` | Trích xuất độ sáng ảnh gốc | Luminance Map (BT.601) | Luminance Map (`0x000f42fc`), luma weights `[0.299, 0.587, 0.114]` | **PROVEN (ĐỒNG NHẤT 100%):** Chuyển đổi RGB sang Luminance bằng trọng số chuẩn ITU-R BT.601 để chuẩn bị dữ liệu đầu vào cho toán học ten-xơ. |
| **Bản Chất Pass 2** | 2D Structure Tensor & Double-Angle Orientation (`HairMaskFilterToFBO` RVA `0x134970`) | Alpha matting | Alpha matting & Hairline feathering | Mask Boundary Filtering & Thresholding (`0x000f4400`, threshold 0.05, feather 0.15) | **ĐÍNH CHÍNH QUAN TRỌNG:** Tên hàm trong vendor binary là `HairMaskFilterToFBO`, nhưng nguyên văn mã GLSL tại `0x89635` thực hiện tính gradient Sobel 2D và mã hóa góc kép (Double-Angle tensor: $ec{g} = (g_x^2 - g_y^2, 2 g_x g_y) / |
abla I|^2$). Threshold 0.05 và Feathering 0.15 được áp dụng trên CPU/Java trước khi nạp texture vào FBO này. |
| **Bản Chất Pass 3 & 4** | 5-Tap Separable Gaussian Blur (Weights tại `0x8edd8`) | Làm mờ trường hướng | Horizontal & Vertical Gaussian Blur (5 taps) | 5-Tap Gaussian Blur (`0x000f4528` & `0x000f46d0`) | **PROVEN (ĐỒNG NHẤT 100%):** Làm mờ trường ten-xơ hướng bằng 2 pass tích chập Gaussian 1D khả tách (separable 5-tap kernel: `[0.159676, 0.263348, 0.122118, 0.030573, 0.004122]`). |
| **Bản Chất Pass 5** | 10-Tap Directional Anisotropic Convolution (`0x134c48`) | 21-tap Line Integral Convolution (LIC) | 21-tap LIC Tangent Filter (Ghi nhận UNKNOWN-02 về tap table) | 9x9 Unsharp Mask, Clarity Boost & Pegtop SoftLight (`0x000f4878`) | **ĐÍNH CHÍNH & HỢP NHẤT:**<br>- Thuật toán lõi thực thi lấy mẫu tích phân đường cong có hướng (LIC) dọc theo vector tiếp tuyến của trường hướng.<br>- Biểu thức trộn màu là toán học **Pegtop SoftLight:** $f(a,b) = (1.0 - 2.0b)a^2 + 2.0ba$.<br>- Độ nét vi sợi tóc được tăng cường bằng Unsharp Mask factor $0.4 \times 1.8$. |
| **Mô Hình AI Tóc (AI Hair Models)** | BiSeNet (19 classes) | `facetune_hair_seg_v4.tflite` (PROVEN) & `faceapp_hair_color_neural.onnx` | Thu hồi tên giả lập `facetune_hair_seg_v4.tflite`, xác định tệp thật `tt_hair_v11.0.model` (81 KB) | MediaPipe Hair / BiSeNet P0 | **ĐÃ THU HỒI TÊN GIẢ LẬP:** Xác nhận không có `facetune_hair_seg_v4.tflite` hay `faceapp_hair_color_neural.onnx`. Mô hình thật là BiSeNet P0 (`tau_aspect = 1.80`), MediaPipe hair segmenter và `tt_hair_v11.0.model`. |
| **Mã Băm libMTFilterKernel.so** | N/A (Address tracing) | N/A | `f938fe73095f...` | `4b54e7d7ff6b2bc2fa8f21919865ffb528b1767b4478d38e78beabdc7ad1fba9` (Copy-paste error) | **THU HỒI & KHÓA CHẶT:** Thu hồi hoàn toàn mã băm `4b54e7...`. Khóa cứng danh tính nhị phân duy nhất: SHA-256 `f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4`, Build-ID `05d25f33b47237df48aab961ae026386d69fa8eb`. |

---

## 2. KẾT LUẬN ĐỒNG THUẬN KỸ THUẬT VỀ ĐỒ THỊ NHUỘM TÓC
1. Không còn mâu thuẫn giữa 5 passes và 8 stages: 5 passes là lõi render shader trong C++, 8 stages là đường ống đồ họa toàn trình tích hợp Java -> JNI -> Shaders -> LUT Swatches.
2. Không còn tên mô hình suy đoán: Mọi tệp mô hình đều có SHA-256 thực tế trên đĩa cứng.
3. Không còn bất đồng mã băm nhị phân: Khóa cứng `libMTFilterKernel.so` tại SHA-256 `f938fe73...`.
