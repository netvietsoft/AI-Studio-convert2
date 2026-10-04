# CONVERT2 — REVERSE ENGINEERING KNOWLEDGE BASE MASTER INDEX
**Version:** 3.0.0 (Post-TASK_051 P0 45 SO Max-Depth Continuous Reconstruction)  
**Authority:** Chủ tịch Tony  
**Canonical Standard:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Active Task ID:** TASK_051_P0_45_SO_MAX_DEPTH_CONTINUOUS_RECONSTRUCTION_ACTIVE  
**Execution Lane:** `so45-max-depth-continuous-reconstruction`  
**Dispatch Commit SHA:** b7ca2dc975472c14bf586c67f93d54b226169971  
**Status:** CANONICAL / PERSISTENT ARCHITECTURE SPECIFICATION  

---

## 1. NGUYÊN TẮC BẤT DI BẤT DỊCH CỦA CHỦ TỊCH TONY (EXECUTIVE MANDATE)
> "45 vendor .so are a project-critical dependency. This lane MUST run continuously and in parallel with Body/Hair/UI/QA. It MUST NOT be paused merely because another feature lane is active. If the meaningful algorithms/functions in these 45 binaries cannot be reconstructed to the maximum technically achievable depth, CONVERT2 is considered at project-failure risk."

Tài liệu này là **Cổng Thông Tin Tổng Hành Dinh** kết nối toàn bộ tri thức kỹ thuật đảo ngược sạch thu được từ quá trình phân tích 45 thư viện nhị phân Meitu, mã nguồn C++ V1, và 14 ứng dụng xử lý ảnh đỉnh cao tại `F:\App\Image`.

---

## 2. NGUYÊN TẮC PHÒNG SẠCH & PHÁP LÝ (CLEAN-ROOM COMPLIANCE)
1. **Chỉ Phân Tích Đọc (Read-Only Analysis):** Mọi công tác khảo sát chỉ phục vụ trích xuất quy luật toán học, kiến trúc luồng dữ liệu, tham số chuẩn hóa và giao diện đồ họa.
2. **Cấm Sao Chép (No Code / Binary Copy):** Tuyệt đối KHÔNG sao chép nhị phân thương mại hoặc mã nguồn có bản quyền vào kho mã nguồn CONVERT2.
3. **Bảo Vệ Hệ Thống:** Không phá vỡ kiểm soát quyền truy cập, thanh toán in-app, chữ ký số, khóa bảo mật hay DRM.
4. **Không Suy Đoán (Zero Speculation):** Mọi hiện vật phải có đường dẫn tệp, kích thước byte và mã băm SHA256 thật trên đĩa. Cấm sử dụng các tên tệp ảo/chuẩn hóa.
5. **Cổng Pháp Lý Tiền Thực Thi:** 100% worker tham gia bắt buộc đọc, xác minh SHA256 và ký nhận `READ_UNDERSTOOD_WILL_COMPLY`.

---

## 3. CÂY THƯ MỤC CƠ SỞ TRI THỨC BỀN VỮNG (PERSISTENT REPOSITORY STRUCTURE)
```
C:\actions-runner-02\_work\AI-Studio-convert2\AI-Studio-convert2\
├── REVERSE_ENGINEERING_KNOWLEDGE_INDEX.md           <-- [Cổng Chính] Tài liệu này (Version 3.0.0)
└── .ai\reverse_engineering\
    ├── 00_SO_MASTER_INVENTORY.md                    <-- Danh mục 45 SO đầy đủ kích thước, SHA256, Build-ID
    ├── 01_IMAGE_EFFECT_GRAPH.md                     <-- Đồ thị Hiệu ứng Hình ảnh chuẩn 8 tầng
    ├── 02_FEATURE_TO_PROCESSING_MAP.md              <-- Ánh xạ UI -> JNI -> C++ -> GPU -> Pixel
    ├── 03_UNKNOWN_NEXT_RESEARCH.md                  <-- Danh mục các điểm chưa rõ & kế hoạch thăm dò
    ├── index.json                                   <-- Chỉ mục JSON cấu trúc cho máy đọc
    ├── functions\                                   <-- Hồ sơ bóc tách chi tiết từng hàm nhị phân trọng yếu
    │   ├── FN_001_MTSoftHairFilter.md
    │   ├── FN_002_grayFilterToFBO.md
    │   ├── FN_003_hairMaskFilterToFBO.md
    │   ├── FN_004_blurH_V_FilterToFBO.md
    │   ├── FN_005_softHairFilterToFBO.md
    │   ├── FN_006_CMTFilterSoftHair.md
    │   ├── FN_007_LFDenseHairModular.md
    │   ├── FN_008_nSetTraditionHairDye.md
    │   └── FN_009_PVGCOLOR_convertToLab.md
    ├── algorithms\                                  <-- Quy chuẩn thuật toán toán học phục dựng phòng sạch
    │   ├── 01_STRUCTURE_TENSOR_DOUBLE_ANGLE.md
    │   ├── 02_21_TAP_LINE_INTEGRAL_CONVOLUTION.md
    │   ├── 03_PEGTOP_SOFTLIGHT_BLEND.md
    │   ├── 04_UNSHARP_MASK_9X9_CLARITY.md
    │   └── 05_GAUSSIAN_5TAP_WEIGHTS_OFFSETS.md
    ├── shaders\                                     <-- Mã nguồn Shader GLSL nguyên văn trích xuất từ nhị phân
    │   ├── MTSoftHairFilter_unsharp.glsl
    │   └── softLightPegtop.glsl
    ├── pseudocode\                                  <-- Mã giả C++ phòng sạch (Level 5 Reimplementable)
    │   ├── MTSoftHairFilter_Pipeline.cpp
    │   ├── HairDyeManager_Logic.cpp
    │   └── ColorSpace_ConvertLab.cpp
    ├── callgraphs\                                  <-- Sơ đồ tuần tự và luồng điều khiển caller/callee
    │   ├── HAIR_PIPELINE_CALLGRAPH.md
    │   └── LAYERFLOW_COMPOSITING_CALLGRAPH.md
    ├── evidence\                                    <-- Bằng chứng thực nghiệm JNI, RegisterNatives & ELF
    │   ├── JNI_REGISTER_NATIVES_EVIDENCE.md
    │   └── ELF_SECTION_EVIDENCE.md
    └── effects\                                     <-- Hồ sơ hiệu ứng theo từng phân hệ chân dung
        ├── 01_HAIR_EFFECT_DOSSIER.md
        ├── 02_FACE_SKIN_BEAUTY_DOSSIER.md
        ├── 03_BODY_WARP_PROTECTION_DOSSIER.md
        ├── 04_COLOR_LUT_TONE_DOSSIER.md
        ├── 05_MAKEUP_SYNTHESIS_DOSSIER.md
        └── 06_RESTORATION_INPAINT_DOSSIER.md
```

---

## 4. BẢNG PHÂN BỔ MỨC ĐỘ TRƯỞNG THÀNH 45 SO (MATURITY SUMMARY)
- **LEVEL 5 (REIMPLEMENTABLE):** `libMTFilterKernel.so`, `libLayerFlow.so`, `libPVGColorFunctions.so` (Lõi Tóc, Màu sắc, Compositing).
- **LEVEL 4 (LOGIC_RECOVERED):** `libarkernel3.so`, `libarkernel3_android.so`, `libarkernel3_c.so`, `libARKernelInterface.so`, `libManis.so`, `libmanis_npu_adapter.so`, `libAIModelKit.so`, `libaidetectionplugin.so`, `libAIModelSearchKit.so`.
- **LEVEL 3 (PURPOSE_IDENTIFIED):** 21 thư viện Codec, Video, Animation và UI.
- **LEVEL 2 (PROTECTED_EXCLUSION):** 6 thư viện DRM, Mã hóa chữ ký số và token bảo mật.
- **LEVEL 1 (CLASSIFIED_RUNTIME):** 6 thư viện runtime chuẩn C++/Crash.

---

## 5. CHỈ THỊ HOÀN THÀNH VÀ DUY TRÌ VÒNG LẶP LIÊN TỤC
> **TASK COMPLETE != AGENT COMPLETE:**  
> Hoàn thành nhiệm vụ TASK_051 đánh dấu một cột mốc kiểm định (Review Checkpoint). Toàn bộ hệ thống duy trì trạng thái thường trực, tự động trở về `TASK_SCANNER` để đón nhận các nhiệm vụ tiếp theo từ Chủ tịch Tony.
