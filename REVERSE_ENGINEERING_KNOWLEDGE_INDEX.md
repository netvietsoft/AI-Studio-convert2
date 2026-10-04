# REVERSE_ENGINEERING_KNOWLEDGE_INDEX.md — CHỈ MỤC TRI THỨC KỸ THUẬT ĐẢO NGƯỢC TOÀN CẢNH
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Phiên bản Chỉ mục:** 2.0 (Cập nhật toàn diện sau TASK_051)  
**Trạng thái Tri thức:** **`PERSISTENT — ZERO KNOWLEDGE LOSS`**  

---

## 1. CẤU TRÚC KHO TRI THỨC PHÒNG SẠCH (`.ai/reverse_engineering/`)

```
.ai/reverse_engineering/
├── 00_MASTER_INVENTORY.md             # Tổng mục 45 thư viện SO và phân loại vai trò
├── 01_IMAGE_EFFECT_GRAPH.md           # Đồ thị hiệu ứng hình ảnh 8 giai đoạn toàn diện
├── 02_FEATURE_TO_PROCESSING_MAP.md    # Ánh xạ từ tính năng sản phẩm sang nhân xử lý C++
├── 03_UNKNOWN_NEXT_RESEARCH.md        # Danh mục vùng chưa sáng tỏ & phương án thăm dò
├── 00_SO_MASTER_INVENTORY.md          # Sổ tay chi tiết 45 thư viện, Build-ID, SHA-256
├── functions/                         # Hồ sơ phân tích hàm C++ native trọng yếu
│   ├── mt_soft_hair_filter.md         # Phân rã 5-pass FBO của MTSoftHairFilter (0x000f3f58)
│   ├── hair_mask_filter.md            # Pass cắt lọc và làm mềm biên mặt nạ tóc
│   ├── blur_horizontal_vertical.md    # Bảng 5 trọng số Gauss tĩnh (0x0008edd8)
│   ├── structure_tensor_orientation.md# Ten-xơ cấu trúc góc kép của dòng sợi tóc
│   ├── directional_21_tap_lic.md      # Tích phân đường cong 21-tap LIC hướng sợi
│   ├── layerflow_dense_hair.md        # Cầu nối JNI EffectDenseHairDataJNI
│   ├── manis_neural_engine.md         # Nhân suy luận nơ-ron phân đoạn Class 17
│   ├── pvg_color_transfer.md          # Bộ đổ bóng chuyển màu 3D LUT (0x11170)
│   └── arkernel_face_body_mesh.md     # Lưới biến dạng 106 điểm mặt & 24 điểm cơ thể
├── algorithms/                        # Hồ sơ giải thuật toán học phòng sạch
│   ├── hair_matting_dye_algorithm.md  # Chuỗi giải thuật nhuộm tóc độ phân giải cao
│   ├── skin_smoothing_whitening.md    # Lọc song phương bảo tồn lỗ chân lông
│   ├── body_protected_warp.md         # Moving Least Squares có khóa bảo vệ nền
│   └── color_lut_tone_mapping.md      # Nội suy 3D LUT và quản lý không gian màu
├── shaders/                           # Mã nguồn GLSL shader nhúng trích xuất từ nhị phân
│   ├── glsl_9x9_unsharp_mask_clarity.glsl # Shader làm sắc nét sợi tóc (0x77afa)
│   ├── glsl_soft_light_pegtop.glsl    # Công thức toán học Pegtop SoftLight (0x82369)
│   ├── glsl_21_tap_lic.glsl           # Shader tích phân đường cong 21 điểm
│   ├── glsl_pvg_color_transfer.glsl   # Shader ánh xạ 3D LUT (0x11170)
│   └── shader_registry.md             # Sổ danh mục shader toàn hệ thống
├── pseudocode/                        # Mã giả C++ phòng sạch độc lập, sẵn sàng tái dựng
│   ├── mt_soft_hair_filter_pseudocode.cpp # Triển khai C++ hoàn chỉnh 5 pass FBO
│   ├── structure_tensor_lic_pseudocode.cpp
│   ├── layerflow_dense_hair_pseudocode.cpp
│   └── pvg_color_transfer_pseudocode.cpp
├── callgraphs/                        # Đồ thị gọi hàm và liên kết gọi ngoài (XREFs)
│   ├── hair_dye_callgraph.md          # Đồ thị gọi hàm chuỗi nhuộm tóc
│   └── face_body_beauty_callgraph.md  # Đồ thị gọi hàm làm đẹp khuôn mặt & cơ thể
└── evidence/                          # Bằng chứng xuất xứ và liên kết nhị phân
    └── 45_so_evidence_index.md        # Bảng chỉ mục liên kết 45 tệp disassembly
```

---

## 2. NGUYÊN TẮC BẢO VỆ PHÁP LÝ & CLEAN-ROOM (RULE 11 COMPLIANCE)
- 100% Thuật toán tái dựng đều dựa trên phân tích hình học, toán học giải tích và quang học thị giác máy tính.
- Tuyệt đối không sao chép nguyên văn mã nguồn độc quyền có bảo vệ bản quyền.
- 6 Thư viện bảo mật/DRM được đóng băng và giữ nguyên trạng thái loại trừ pháp lý.
