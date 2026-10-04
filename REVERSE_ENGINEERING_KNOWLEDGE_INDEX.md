# REVERSE_ENGINEERING_KNOWLEDGE_INDEX.md — CHỈ MỤC TRI THỨC KỸ THUẬT ĐẢO NGƯỢC TOÀN CẢNH
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Phiên bản Chỉ mục:** 2.3 (Cập nhật toàn diện sau TASK_056 — Bổ sung Tetrahedral 3D LUT, Dual-Lobe Specular, và Optical Flow Temporal Hair Stabilizer)  
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
│   ├── anisotropic_hair_specular.md   # Phản chiếu bất đẳng hướng Kajiya-Kay lọn tóc (0x0009d180)
│   ├── hairline_soft_feathering.md    # Làm mềm biên tiếp giáp da - tóc Zero Leakage (0x000a2410)
│   ├── tetrahedral_3d_lut_sample.md   # Lấy mẫu nội suy tứ diện 3D LUT (0x00011400)
│   ├── dual_lobe_hair_specular.md     # Đánh giá thùy kép R và TRT dọc sợi tóc (0x0007b420)
│   ├── temporal_consistency_blend.md  # Hòa trộn ổn định thời gian video (0x00098200)
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
│   ├── anisotropic_kajiya_kay_specular.md # Mô hình tán xạ ánh sáng Kajiya-Kay trên sợi tóc
│   ├── dual_lobe_strand_specular_lighting.md # Mô hình phản xạ hai thùy R và TRT dọc trục sợi tóc
│   ├── hairline_guided_feathering.md  # Khóa bảo vệ vùng không can thiệp & lọc cạnh dẫn đường
│   ├── skin_texture_pore_preservation.md # Phân tách tần số bảo tồn vi lỗ chân lông >= 75%
│   ├── tetrahedral_3d_lut_color_grading.md # Thuật toán nội suy tứ diện 6 khối cho 3D LUT 33x33x33
│   ├── optical_flow_temporal_hair_stabilizer.md # Ổn định màu nhuộm video qua Lucas-Kanade/Farneback
│   ├── skin_smoothing_whitening.md    # Lọc song phương bảo tồn lỗ chân lông
│   ├── body_protected_warp.md         # Moving Least Squares có khóa bảo vệ nền
│   └── color_lut_tone_mapping.md      # Nội suy 3D LUT và quản lý không gian màu
├── shaders/                           # Mã nguồn GLSL shader nhúng trích xuất từ nhị phân
│   ├── glsl_gray_filter.glsl          # Shader triệt sắc nền tự nhiên
│   ├── glsl_hair_dye_softlight_pegtop.glsl # Shader Pegtop Soft Light hoàn chỉnh
│   ├── glsl_hair_specular_highlight.glsl # Shader ánh kim lọn tóc Kajiya-Kay
│   ├── glsl_anisotropic_kajiya_kay.glsl # Shader phản xạ bất đẳng hướng đa thùy R và TRT
│   ├── glsl_dual_lobe_strand_specular.glsl # Shader tính thùy kép R và TRT kèm góc lệch biểu bì
│   ├── glsl_hairline_guided_feather.glsl # Shader làm mềm biên chuyển tiếp chân tóc
│   ├── glsl_tetrahedral_3d_lut.glsl   # Shader nội suy tứ diện 3D LUT 33x33x33
│   ├── glsl_temporal_hair_coherence.glsl # Shader hòa trộn tích lũy khung hình theo dòng quang học
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
│   ├── anisotropic_kajiya_kay_pseudocode.cpp # Triển khai C++ Kajiya-Kay Specular Pass
│   ├── dual_lobe_hair_specular_pseudocode.cpp # Triển khai C++ Dual-Lobe Specular Highlight
│   ├── hairline_feathering_pseudocode.cpp # Triển khai C++ Hairline Feathering Pass
│   ├── tetrahedral_3d_lut_pseudocode.cpp # Triển khai C++ Tetrahedral 3D LUT Interpolation
│   ├── temporal_hair_stabilizer_pseudocode.cpp # Triển khai C++ Video Temporal Frame Stabilizer
│   ├── structure_tensor_lic_pseudocode.cpp
│   ├── layerflow_dense_hair_pseudocode.cpp
│   └── pvg_color_transfer_pseudocode.cpp
├── callgraphs/                        # Đồ thị gọi hàm và liên kết gọi ngoài (XREFs)
│   ├── hair_dye_complete_caller_callee.md # Đồ thị gọi hàm hoàn chỉnh toàn chuỗi
│   ├── hair_specular_feathering_callgraph.md # Đồ thị gọi hàm ánh kim & làm mềm chân tóc
│   ├── tetrahedral_lut_and_temporal_callgraph.md # Đồ thị gọi hàm 3D LUT tứ diện & ổn định video
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
