# REVERSE_ENGINEERING_KNOWLEDGE_INDEX.md — CHỈ MỤC TRI THỨC KỸ THUẬT ĐẢO NGƯỢC TOÀN CẢNH
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Phiên bản Chỉ mục:** 2.1 (Cập nhật toàn diện sau TASK_054 — Bổ sung trọn bộ Priority Algorithms)  
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
│   ├── hair_mask_filter.md            # Pass cắt lọc và làm mềm biên mặt nạ tóc (0x000e8210)
│   ├── gray_filter.md                 # Triệt sắc nền & trung hòa sắc tố tự nhiên (0x0008ebd4)
│   ├── blur_horizontal_vertical.md    # Bảng 5 trọng số Gauss tĩnh (0x0008edd8)
│   ├── structure_tensor_orientation.md# Ten-xơ cấu trúc góc kép của dòng sợi tóc (0x00094120)
│   ├── directional_21_tap_lic.md      # Tích phân đường cong 21-tap LIC hướng sợi (0x00097480)
│   ├── soft_hair_filter_ps_softlight.md # Công thức Pegtop Soft Light (0x0009c310)
│   ├── makeup_hair_soft_part.md       # Phối trộn mềm chân tóc tiếp giáp da mặt (0x000a12e0)
│   ├── lf_dense_hair_modular.md       # Động cơ LayerFlow dòng tóc đa tầng (0x00083a20)
│   ├── decode_hair_dye_config.md      # Phân giải cấu hình JSON màu nhuộm (0x00067340)
│   ├── n_set_tradition_hair_dye_intensity_and_shine.md # Cầu nối JNI điều khiển (0x00051e80)
│   ├── layerflow_dense_hair.md        # Cầu nối JNI EffectDenseHairDataJNI
│   ├── manis_neural_engine.md         # Nhân suy luận nơ-ron phân đoạn Class 17
│   ├── pvg_color_transfer.md          # Bộ đổ bóng chuyển màu 3D LUT (0x11170)
│   └── arkernel_face_body_mesh.md     # Lưới biến dạng 106 điểm mặt & 24 điểm cơ thể
├── algorithms/                        # Hồ sơ giải thuật toán học phòng sạch
│   ├── hair_dye_multistage_pipeline.md# Chuỗi giải thuật 8 giai đoạn nhuộm tóc
│   ├── hair_matting_dye_algorithm.md  # Chuỗi giải thuật nhuộm tóc độ phân giải cao
│   ├── skin_smoothing_whitening.md    # Lọc song phương bảo tồn lỗ chân lông
│   ├── body_protected_warp.md         # Moving Least Squares có khóa bảo vệ nền
│   └── color_lut_tone_mapping.md      # Nội suy 3D LUT và quản lý không gian màu
├── shaders/                           # Mã nguồn GLSL shader nhúng trích xuất từ nhị phân
│   ├── glsl_gray_filter.glsl          # Shader triệt sắc nền tự nhiên
│   ├── glsl_hair_dye_softlight_pegtop.glsl # Shader Pegtop Soft Light hoàn chỉnh
│   ├── glsl_hair_specular_highlight.glsl # Shader ánh kim lọn tóc Kajiya-Kay
│   ├── glsl_makeup_hair_soft_part.glsl# Shader hòa trộn chân tóc tiếp giáp da
│   ├── glsl_9x9_unsharp_mask_clarity.glsl # Shader làm sắc nét sợi tóc (0x77afa)
│   ├── glsl_soft_light_pegtop.glsl    # Công thức toán học Pegtop SoftLight (0x82369)
│   ├── glsl_21_tap_lic.glsl           # Shader tích phân đường cong 21 điểm
│   ├── glsl_pvg_color_transfer.glsl   # Shader ánh xạ 3D LUT (0x11170)
│   └── shader_registry.md             # Sổ danh mục shader toàn hệ thống
├── pseudocode/                        # Mã giả C++ phòng sạch độc lập, sẵn sàng tái dựng
│   ├── gray_filter_pseudocode.cpp     # Triển khai triệt sắc nền ITU-R BT.601
│   ├── soft_hair_filter_ps_softlight_pseudocode.cpp # Triển khai Pegtop SoftLight
│   ├── decode_load_hair_dye_config_pseudocode.cpp # Triển khai giải mã JSON
│   ├── n_set_tradition_hair_dye_intensity_and_shine_pseudocode.cpp # Cầu nối JNI
│   ├── mt_soft_hair_filter_pseudocode.cpp # Triển khai C++ hoàn chỉnh 5 pass FBO
│   ├── structure_tensor_lic_pseudocode.cpp
│   ├── layerflow_dense_hair_pseudocode.cpp
│   └── pvg_color_transfer_pseudocode.cpp
├── callgraphs/                        # Đồ thị gọi hàm và liên kết gọi ngoài (XREFs)
│   ├── hair_dye_complete_caller_callee.md # Đồ thị gọi hàm hoàn chỉnh toàn chuỗi
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
