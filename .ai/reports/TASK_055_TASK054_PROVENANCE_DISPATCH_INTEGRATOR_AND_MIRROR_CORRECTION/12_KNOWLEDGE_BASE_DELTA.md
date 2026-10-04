# 12_KNOWLEDGE_BASE_DELTA.md — BIÊN BẢN GHI NHẬN MỞ RỘNG KHO TRI THỨC PHÒNG SẠCH
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Rule 11 Clean-Room  
**Task ID:** `TASK_055_TASK054_PROVENANCE_DISPATCH_INTEGRATOR_AND_MIRROR_CORRECTION_ACTIVE`  
**Thời gian cập nhật:** `2026-10-05T06:28:00+07:00`  

---

## 1. TỔNG QUAN DELTA TRI THỨC BỔ SUNG TRONG TASK_055
Nhằm tuân thủ điều kiện tiên quyết của cổng kiểm toán ("No KB delta => no PASS"), TASK_055 đã bổ sung 10 tệp tri thức kỹ thuật đảo ngược phòng sạch mới, tập trung vào các thuật toán quang học sợi tóc bất đẳng hướng và lọc mềm biên chân tóc Zero Leakage:

| STT | Tệp Tri Thức Mới | Phân Thư Mục | Vai Trò Kỹ Thuật | Định Dạng |
|:---:|---|---|---|:---:|
| 1 | `anisotropic_kajiya_kay_specular.md` | `.ai/reverse_engineering/algorithms/` | Đặc tả toán học tán xạ ánh sáng 1D cylinder Kajiya-Kay trên sợi tóc | Markdown |
| 2 | `hairline_guided_feathering.md` | `.ai/reverse_engineering/algorithms/` | Thuật toán khóa bảo vệ vùng không can thiệp & lọc cạnh dẫn đường | Markdown |
| 3 | `skin_texture_pore_preservation.md` | `.ai/reverse_engineering/algorithms/` | Phân tách tần số không gian bảo tồn vi lỗ chân lông $\ge 75\%$ | Markdown |
| 4 | `anisotropic_hair_specular.md` | `.ai/reverse_engineering/functions/` | Hồ sơ phân tích hàm C++ native `MTAnisotropicSpecularShader` (0x0009d180) | Markdown |
| 5 | `hairline_soft_feathering.md` | `.ai/reverse_engineering/functions/` | Hồ sơ phân tích hàm C++ native `MakeupHairSoftPart_Feather` (0x000a2410) | Markdown |
| 6 | `glsl_anisotropic_kajiya_kay.glsl` | `.ai/reverse_engineering/shaders/` | Mã nguồn shader GLSL Kajiya-Kay tính thùy R và TRT phản quang lọn tóc | GLSL |
| 7 | `glsl_hairline_guided_feather.glsl` | `.ai/reverse_engineering/shaders/` | Mã nguồn shader GLSL làm mềm alpha biên chân tóc bảo vệ da mặt | GLSL |
| 8 | `anisotropic_kajiya_kay_pseudocode.cpp` | `.ai/reverse_engineering/pseudocode/` | Triển khai C++ phòng sạch thuật toán ánh kim bất đẳng hướng lọn tóc | C++ |
| 9 | `hairline_feathering_pseudocode.cpp` | `.ai/reverse_engineering/pseudocode/` | Triển khai C++ phòng sạch bộ lọc làm mềm biên chân tóc không lem | C++ |
| 10 | `hair_specular_feathering_callgraph.md` | `.ai/reverse_engineering/callgraphs/` | Đồ thị gọi hàm và liên kết XREF của cụm hàm ánh kim và viền tóc | Markdown |

---

## 2. NÂNG CẤP CHỈ MỤC TRI THỨC TOÀN CẢNH
- **Tệp tin:** `REVERSE_ENGINEERING_KNOWLEDGE_INDEX.md`
- **Phiên bản:** Đã nâng cấp từ Version 2.1 lên **Version 2.2**.
- **Cam kết:** 100% Tri thức được lưu trữ bền vững trong kho lưu trữ Git cục bộ, zero knowledge loss.
