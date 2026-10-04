# TASK_051 — KNOWLEDGE BASE DELTA MERGE RECORD
**Authority:** Chủ tịch Tony  
**Task ID:** TASK_051_P0_45_SO_MAX_DEPTH_CONTINUOUS_RECONSTRUCTION_ACTIVE  
**Standard:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Runner Identity:** CONVERT2-WINDOWS-02 (GITHUB_ACTIONS_37204962051)  
**Commit SHA:** b7ca2dc975472c14bf586c67f93d54b226169971  
**Execution Timestamp:** 2026-10-04T20:25:00+07:00  
**Persistence Gate:** PASS (No Knowledge Lost; Full Directory Hierarchy Populated)  

---

## 1. NGUYÊN TẮC BẢO TOÀN TRI THỨC BỀN VỮNG (PERSISTENCE MANDATE)
Căn cứ Điều lệnh của Chủ tịch Tony tại `task_051.txt`:
> "PERSISTENCE — NO KNOWLEDGE LOSS
> Continuously merge into:
> REVERSE_ENGINEERING_KNOWLEDGE_INDEX.md
> .ai/reverse_engineering/00_SO_MASTER_INVENTORY.md
> .ai/reverse_engineering/functions/
> .ai/reverse_engineering/algorithms/
> .ai/reverse_engineering/shaders/
> .ai/reverse_engineering/pseudocode/
> .ai/reverse_engineering/callgraphs/
> .ai/reverse_engineering/evidence/
> No knowledge delta merged => no PASS."

Toàn bộ các thư mục con chuyên biệt trong `.ai/reverse_engineering/` đã được kiến tạo và tích hợp đồng bộ:

---

## 2. BẢNG DANH MỤC HIỆN VẬT TRI THỨC ĐÃ TÍCH HỢP (KB DELTA MANIFEST)

| Phân Mục Tri Thức | Đường Dẫn Tệp Mới | Loại Dữ Liệu | Nội Dung Trọng Tâm |
|:---|:---|:---|:---|
| **Root Index** | `REVERSE_ENGINEERING_KNOWLEDGE_INDEX.md` | Markdown Spec | Cập nhật Phiên bản 3.0.0, liên kết 45 SO và các thư mục tri thức mới |
| **Inventory** | `.ai/reverse_engineering/00_SO_MASTER_INVENTORY.md` | Markdown Catalog | Bảng kiểm kê chi tiết 45/45 nhị phân vendor kèm Build-ID và phân vùng |
| **Functions** | `.ai/reverse_engineering/functions/FN_001_MTSoftHairFilter.md` | Function Dossier | Bóc tách chi tiết hàm `renderToTextureWithVerticesAndTextureCoordinates` |
| **Functions** | `.ai/reverse_engineering/functions/FN_002_grayFilterToFBO.md` | Function Dossier | Bóc tách chi tiết hàm trích xuất độ chói Luminance ITU-R BT.601 |
| **Functions** | `.ai/reverse_engineering/functions/FN_003_hairMaskFilterToFBO.md`| Function Dossier | Bóc tách chi tiết hàm chuẩn hóa và cắt lọc mặt nạ tóc |
| **Functions** | `.ai/reverse_engineering/functions/FN_004_blurH_V_FilterToFBO.md`| Function Dossier | Bóc tách chi tiết hàm làm mờ Gauss 5 điểm theo chiều ngang & dọc |
| **Functions** | `.ai/reverse_engineering/functions/FN_005_softHairFilterToFBO.md`| Function Dossier | Bóc tách chi tiết hàm lọc mượt có hướng và tăng cường sợi tóc |
| **Functions** | `.ai/reverse_engineering/functions/FN_006_CMTFilterSoftHair.md` | Function Dossier | Bóc tách chi tiết wrapper C-style điều phối luồng FBO |
| **Functions** | `.ai/reverse_engineering/functions/FN_007_LFDenseHairModular.md` | Function Dossier | Bóc tách chi tiết cơ chế nạp cấu hình JSON tóc trong LayerFlow |
| **Functions** | `.ai/reverse_engineering/functions/FN_008_nSetTraditionHairDye.md`| Function Dossier | Bóc tách chi tiết hàm điều chỉnh cường độ và độ bóng tóc truyền thống |
| **Functions** | `.ai/reverse_engineering/functions/FN_009_PVGCOLOR_convertToLab.md`| Function Dossier | Bóc tách chi tiết chuyển đổi không gian màu sang CIE L*a*b* |
| **Algorithms**| `.ai/reverse_engineering/algorithms/01_STRUCTURE_TENSOR_DOUBLE_ANGLE.md` | Algorithm Spec | Thuật toán vector góc kép (cos 2θ, sin 2θ) cho hướng sợi tóc |
| **Algorithms**| `.ai/reverse_engineering/algorithms/02_21_TAP_LINE_INTEGRAL_CONVOLUTION.md` | Algorithm Spec | Thuật toán tích phân đường 21 taps dọc theo tiếp tuyến dòng chảy tóc |
| **Algorithms**| `.ai/reverse_engineering/algorithms/03_PEGTOP_SOFTLIGHT_BLEND.md` | Algorithm Spec | Thuật toán hòa trộn SoftLight phi phân nhánh Pegtop |
| **Algorithms**| `.ai/reverse_engineering/algorithms/04_UNSHARP_MASK_9X9_CLARITY.md` | Algorithm Spec | Thuật toán mặt nạ không sắc nét lưới hộp 81 điểm ảnh (Clarity 0.4) |
| **Algorithms**| `.ai/reverse_engineering/algorithms/05_GAUSSIAN_5TAP_WEIGHTS_OFFSETS.md` | Algorithm Spec | Bảng trọng số tĩnh và tọa độ UV chuẩn hóa 962x1280px |
| **Shaders**   | `.ai/reverse_engineering/shaders/MTSoftHairFilter_unsharp.glsl` | GLSL Source | Mã nguồn GLSL 9x9 Unsharp Mask nguyên văn từ nhị phân |
| **Shaders**   | `.ai/reverse_engineering/shaders/softLightPegtop.glsl` | GLSL Source | Mã nguồn GLSL Pegtop SoftLight nguyên văn từ nhị phân |
| **Pseudocode**| `.ai/reverse_engineering/pseudocode/MTSoftHairFilter_Pipeline.cpp` | C++ Clean-Room | Mã giả C++ hoàn chỉnh tái dựng 5 pass của MTSoftHairFilter |
| **Pseudocode**| `.ai/reverse_engineering/pseudocode/HairDyeManager_Logic.cpp` | C++ Clean-Room | Mã giả C++ quản lý cường độ màu nhuộm và độ bóng tóc |
| **Pseudocode**| `.ai/reverse_engineering/pseudocode/ColorSpace_ConvertLab.cpp` | C++ Clean-Room | Mã giả C++ chuyển đổi không gian màu chuẩn xác |
| **Callgraphs**| `.ai/reverse_engineering/callgraphs/HAIR_PIPELINE_CALLGRAPH.md` | Mermaid Call Graph | Sơ đồ tuần tự và luồng điều khiển chi tiết của chuỗi tóc P0 |
| **Callgraphs**| `.ai/reverse_engineering/callgraphs/LAYERFLOW_COMPOSITING_CALLGRAPH.md`| Mermaid Call Graph | Sơ đồ luồng hòa trộn đa lớp của LayerFlow Modular Engine |
| **Evidence**  | `.ai/reverse_engineering/evidence/JNI_REGISTER_NATIVES_EVIDENCE.md` | Evidence Log | Bằng chứng thực nghiệm JNI_OnLoad và bảng đăng ký hàm gốc |
| **Evidence**  | `.ai/reverse_engineering/evidence/ELF_SECTION_EVIDENCE.md` | Evidence Log | Bằng chứng phân đoạn ELF .text, .rodata và Build-ID thực tế |
