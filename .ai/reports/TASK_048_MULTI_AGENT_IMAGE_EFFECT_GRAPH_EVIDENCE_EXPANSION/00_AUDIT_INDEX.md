# TASK_048 — AUDIT INDEX & COMPREHENSIVE DELIVERABLE MANIFEST
**Authority:** Chủ tịch Tony  
**Task ID:** TASK_048_MULTI_AGENT_IMAGE_EFFECT_GRAPH_EVIDENCE_EXPANSION_ACTIVE  
**Predecessor Task:** TASK_047_IMAGE_EFFECT_GRAPH_DEEP_MAPPING_ACTIVE (Audit Verdict: NEEDS_FIX)  
**Execution Date:** 2026-10-04T16:00:00+07:00  
**Status:** COMPLETE / EVIDENCE EXPANDED  
**Hard Gate:** HAIR V4 IMPLEMENTATION = BLOCKED (Zero changes to production Hair V2/V3; No Hair V4 code)  
**V4 Readiness Status:** V4_READINESS_CANDIDATE (Authority reserved for Chủ tịch Tony & ChatGPT audit)  

---

## 1. MỤC TIÊU & TỔNG QUAN THỰC HIỆN
Triển khai mở rộng Đồ thị Hiệu ứng Hình ảnh (Image Effect Graph) sạch, độc lập, không xâm lấn, tuân thủ nghiêm ngặt nguyên tắc phòng sạch (Clean-Room Reverse Engineering).  
Task hoàn thành tái cấu trúc toàn diện 6 phân hệ lớn:
1. **Khắc phục toàn bộ các nhận định chưa được kiểm chứng của TASK_047:** Loại bỏ hoàn toàn 7 tên mô hình suy đoán/chuẩn hóa không có thật trên đĩa (`facetune_hair_seg_v4.tflite`, `faceapp_hair_color_neural.onnx`, `faceapp_relight_sh.onnx`, `remini_face_enhancer_v3.bin`, `lama_inpaint_fp16.tflite`, `beautyplus_face_landmark_106.bin`, `bytenn_skin_mask_v2.model`), hạ cấp mức độ tin cậy từ PROVEN về STRONG_INFERENCE hoặc thay thế bằng mô hình thật đã trích xuất hash SHA256 chính xác từ APK.
2. **Triển khai Multi-Agent / Multi-Lane thực thụ:** Phân bổ tối thiểu 6 lane độc lập với worker identity, timestamp, scope, bằng chứng và deliverable riêng biệt (LANE A, B, C, D, E, F).
3. **Đào sâu chuỗi Tóc P0/P1:** Xác lập chi tiết 8 giai đoạn từ UI (`DENSE_HAIR_OPT_TYPE_HAIR_DYE = 2305`, `MaterialData`) qua DEX (`HairViewModel`, `MTIKHairFilter`, `LFEffectDenseHairData`), JNI (`RegisterNatives` trong `libLayerFlow.so`), hàm C++ native (`MTSoftHairFilter::grayFilterToFBO`, `hairMaskFilterToFBO`, `softHairFilterToFBO`), shader GLSL thực tế (9x9 Unsharp Mask Clarity 0.4, 21-tap LIC, SoftLight Pegtop), tác động pixel và khóa bảo vệ vùng da/nền.
4. **Khai thác toàn diện 14 ứng dụng tại `F:\App\Image`:** Khảo sát đầy đủ thông tin package, version, DEX count, SO inventory, AI model inventory thật, shader inventory, kiến trúc engine và ma trận tính năng chéo (Cross-App Feature Matrix).
5. **Cập nhật Cơ sở Tri thức Kỹ thuật Đảo ngược Bền vững:** Cập nhật `REVERSE_ENGINEERING_KNOWLEDGE_INDEX.md` và `.ai/reverse_engineering/` với các hồ sơ hiệu ứng chuyên sâu.

---

## 2. DANH MỤC TÀI LIỆU NGHIỆM THU (DELIVERABLE MANIFEST)
| STT | Mã Tài Liệu | Tên Tệp / Đường Dẫn | Mô Tả Trọng Tâm |
| :--- | :--- | :--- | :--- |
| 1 | DOC-00 | `00_AUDIT_INDEX.md` | Chỉ mục nghiệm thu tổng thể & tuyên bố tuân thủ cổng Hard Gate |
| 2 | DOC-01 | `01_MASTER_REPORT.md` | Báo cáo chủ đạo cho Chủ tịch Tony & Ban Giám Sát |
| 3 | DOC-02 | `02_MULTI_AGENT_LANE_PROVENANCE.md` | Bằng chứng thực thi đa luồng 6 lane độc lập (Worker ID, Timeline, Scope) |
| 4 | DOC-03 | `03_IMAGE_EFFECT_GRAPH_MASTER.md` | Đồ thị Hiệu ứng Hình ảnh Toàn cảnh (UI -> DEX -> JNI -> C++ -> GPU -> Pixel) |
| 5 | DOC-04 | `04_HAIR_IMAGE_EFFECT_GRAPH_DEEP.md` | Đồ thị Hiệu ứng Tóc Chuyên Sâu 8 Giai Đoạn (Chi tiết từng bước, tác động pixel) |
| 6 | REG-05 | `05_NODE_EVIDENCE_REGISTRY.csv` | Sổ đăng ký bằng chứng từng Node (App, Artifact, SHA256, Symbol, Confidence) |
| 7 | REG-06 | `06_DEX_JNI_NATIVE_XREF_GRAPH.csv` | Đồ thị tham chiếu chéo DEX -> JNI -> Native C++ Symbol & Address |
| 8 | REG-07 | `07_SHADER_MODEL_EVIDENCE_REGISTRY.csv` | Sổ đăng ký Shaders, AI Models, Tensor Shapes và SHA256 thật trên đĩa |
| 9 | REG-08 | `08_F_APP_IMAGE_14_APP_DEEP_INVENTORY.csv` | Bảng khảo sát chuyên sâu 14 ứng dụng F:\App\Image (DEX, SO, Model, Runtime) |
| 10 | REG-09 | `09_CROSS_APP_FEATURE_MATRIX.csv` | Ma trận tính năng chéo giữa 14 ứng dụng và kiến trúc ưu tú theo từng domain |
| 11 | DOC-10 | `10_FEATURE_ALGORITHM_BANK.md` | Ngân hàng thuật toán & tính năng giá trị cao cho CONVERT2 |
| 12 | DOC-11 | `11_UNSUPPORTED_CLAIMS_CORRECTION.md` | Báo cáo sửa chữa & thu hồi toàn bộ 7+ nhận định thiếu căn cứ của TASK_047 |
| 13 | DOC-12 | `12_UNKNOWN_GAPS_AND_NEXT_PROBES.md` | Danh mục các điểm chưa rõ (Unknowns) & kế hoạch thăm dò thực nghiệm |
| 14 | REG-13 | `13_REIMPLEMENTABILITY_MATRIX.csv` | Ma trận mức độ khả thi tái dựng Clean-Room (Maturity Levels & Pass/Fail) |
| 15 | DOC-14 | `14_V4_READINESS_GATE.md` | Hồ sơ ứng viên V4 (V4_READINESS_CANDIDATE) trình Chủ tịch & ChatGPT duyệt |
| 16 | DOC-15 | `15_REPORT_DRIVE_MIRROR.md` | Báo cáo đồng bộ Google Drive Report Drive (Minh bạch trạng thái Mirror) |
