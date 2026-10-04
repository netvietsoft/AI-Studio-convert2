# 12_KNOWLEDGE_BASE_DELTA.md — BÁO CÁO CẬP NHẬT CƠ SỞ TRI THỨC KỸ THUẬT ĐẢO NGƯỢC
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Mã Nhiệm vụ:** `TASK_051_P0_45_SO_MAX_DEPTH_CONTINUOUS_RECONSTRUCTION_ACTIVE`  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  

---

## 1. TỔNG HỢP CÁC TÀI LIỆU & MÃ NGUỒN MỚI ĐƯỢC TÍCH HỢP

Tuân thủ quy định bất di bất dịch "PERSISTENCE — NO KNOWLEDGE LOSS" của TASK_051:
Toàn bộ tri thức kỹ thuật đảo ngược đã được hợp nhất bền vững vào cây thư mục `.ai/reverse_engineering/` và chỉ mục `REVERSE_ENGINEERING_KNOWLEDGE_INDEX.md`:

### 1.1. Thư mục `.ai/reverse_engineering/functions/`
- `mt_soft_hair_filter.md`: Đặc tả chi tiết hàm điều phối 5 pass FBO `MTSoftHairFilter::renderToTextureWithVerticesAndTextureCoordinates` (offset `0x000f3f58`), kích thước khung kết xuất `962.0f x 1280.0f`.
- `hair_mask_filter.md`: Phân tích pass lọc mặt nạ tóc `hairMaskFilterToFBO` (offset `0x000f4400`), làm mềm biên và triệt tiêu lem viền.
- `blur_horizontal_vertical.md`: Phân tích 2 pass Gauss tách biệt 1D ngang/dọc với bảng 5 trọng số tĩnh `[0.159676, 0.263348, 0.122118, 0.030573, 0.004122]`.
- `structure_tensor_orientation.md`: Thuật toán tính trường góc ten-xơ góc kép $\theta = 0.5 \operatorname{atan2}(2J_{xy}, J_{xx} - J_{yy})$.
- `directional_21_tap_lic.md`: Tích phân đường cong 21 điểm lấy mẫu dọc theo dòng tiếp tuyến sợi tóc.
- `layerflow_dense_hair.md`: Đặc tả JNI bridge và bộ điều khiển `EffectDenseHairDataJNI`.
- `manis_neural_engine.md`: Kiến trúc nạp và thực thi mô hình Class 17 Hair Segmentation.
- `pvg_color_transfer.md`: Bộ đổ bóng chuyển đổi màu `gGLESColorTransferFragData` (offset `0x11170`).
- `arkernel_face_body_mesh.md`: Lưới biến dạng 106 điểm khuôn mặt và 24 điểm cơ thể.

### 1.2. Thư mục `.ai/reverse_engineering/algorithms/`
- `hair_matting_dye_algorithm.md`: Giải thuật nhuộm tóc thực tế kết hợp giữa mặt nạ nơ-ron, làm mờ Gauss tần số thấp, làm sắc nét Unsharp Mask và công thức Pegtop SoftLight.
- `skin_smoothing_whitening.md`: Thuật toán làm mịn da song phương (Bilateral filter) bảo tồn lỗ chân lông và làm trắng tham số.
- `body_protected_warp.md`: Thuật toán Moving Least Squares có bảo vệ vùng da/nền với trọng số khoảng cách phân rã $w_i = 1 / |p_i - v|^{2\alpha}$.
- `color_lut_tone_mapping.md`: Kỹ thuật nội suy màu khối 3D LUT và bù trừ không gian màu sRGB/Display-P3.

### 1.3. Thư mục `.ai/reverse_engineering/shaders/`
- `glsl_9x9_unsharp_mask_clarity.glsl`: Mã nguồn GLSL trích xuất nguyên văn tại offset `0x77afa` (lưới 9x9, bước nhảy 2.3, hệ số bù sáng 1.8, độ trong trẻo 0.4).
- `glsl_soft_light_pegtop.glsl`: Hàm toán học Pegtop SoftLight trích xuất tại offset `0x82369`.
- `glsl_pvg_color_transfer.glsl`: Shader ánh xạ 3D LUT tại offset `0x11170`.
- `glsl_21_tap_lic.glsl`: Bộ đổ bóng tích phân đường cong 21 điểm dọc hướng tiếp tuyến.
- `shader_registry.md`: Sổ đăng ký các shader trích xuất được từ nhị phân.

### 1.4. Thư mục `.ai/reverse_engineering/pseudocode/`
- `mt_soft_hair_filter_pseudocode.cpp`: Mã giả C++ phòng sạch tái dựng 100% logic của `MTSoftHairFilter`.
- `structure_tensor_lic_pseudocode.cpp`: Mã giả C++ tính toán ten-xơ cấu trúc và tích phân LIC.
- `layerflow_dense_hair_pseudocode.cpp`: Mã giả C++ ghép nối JNI và bộ nhớ đệm LayerFlow.
- `pvg_color_transfer_pseudocode.cpp`: Mã giả C++ nạp ICC profile và nội suy 3D LUT.

### 1.5. Thư mục `.ai/reverse_engineering/callgraphs/`
- `hair_dye_callgraph.md`: Đồ thị gọi hàm hoàn chỉnh cho phân hệ nhuộm tóc.
- `face_body_beauty_callgraph.md`: Đồ thị gọi hàm cho phân hệ làm đẹp khuôn mặt và cơ thể.

### 1.6. Thư mục `.ai/reverse_engineering/evidence/`
- `45_so_evidence_index.md`: Bảng chỉ mục xuất xứ và đường dẫn bằng chứng cho toàn bộ 45 thư viện .SO.
