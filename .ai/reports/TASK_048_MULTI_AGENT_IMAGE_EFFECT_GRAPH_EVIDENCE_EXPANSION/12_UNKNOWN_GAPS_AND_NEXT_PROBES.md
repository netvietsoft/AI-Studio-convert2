# TASK_048 — CATALOG OF UNKNOWN GAPS & NEXT EXPERIMENTAL PROBES
**Authority:** Chủ tịch Tony  
**Task ID:** TASK_048_MULTI_AGENT_IMAGE_EFFECT_GRAPH_EVIDENCE_EXPANSION_ACTIVE  
**Execution Lane:** LANE F (Worker Identity: `WORKER-LANE-F-AUDIT-PROVENANCE`)  
**Purpose:** Xác lập danh mục minh bạch các điểm chưa rõ trong nhị phân và lập kế hoạch thăm dò khoa học trước khi bước vào thiết kế Core V4.  

---

## 1. DANH MỤC CÁC ĐIỂM CHƯA RÕ (CATALOG OF UNKNOWNS)

### UNKNOWN-01: Định dạng nhị phân tệp swatch màu tóc thương mại (.cct / .bundle)
- **Mô tả:** Trong Meitu APK, các mẫu màu nhuộm tóc (Rose Gold, Linen Gray, Blue Black) được đóng gói dưới dạng tệp tài nguyên mã hóa.
- **Khoảng trống:** Cần giải mã cấu trúc header của các tệp swatch để trích xuất ma trận màu $3 \times 3$ hoặc 3D LUT PNG 64x64x64 tương ứng.
- **Kế hoạch thăm dò (Probe):** Viết script bóc tách nhị phân `com/layer/flow/datas/LFEffectDenseHairData.java` và phương thức `nGetMaterialPathBy` trong `libLayerFlow.so` để dump buffer giải nén trong bộ nhớ.

### UNKNOWN-02: Bảng trọng số chính xác của 21-tap LIC trong `MTSoftHairFilter`
- **Mô tả:** Đã xác định hàm `softHairFilterToFBO` lấy mẫu 21 taps dọc theo vector tiếp tuyến.
- **Khoảng trống:** Cần dịch ngược đoạn mã máy ARM64 tại offset `0x8fd64` của `libMTFilterKernel.so` để lấy mảng hằng số tĩnh `float Weights[21]`.
- **Kế hoạch thăm dò (Probe):** Sử dụng công cụ phân tích tĩnh hoặc disassembler trích xuất mảng float tĩnh tại phân đoạn `.rodata` của `libMTFilterKernel.so`.

### UNKNOWN-03: Giao thức truyền tham số giữa `libARKernelInterface.so` và GPU Mesh Buffer
- **Mô tả:** Chuỗi trang điểm biến dạng lưới 106 điểm kết nối qua ARKernel.
- **Khoảng trống:** Chưa rõ cấu trúc struct `MTFaceMeshVertex` (tọa độ vị trí x, y, z và tọa độ vân UV u, v).
- **Kế hoạch thăm dò (Probe):** Phân tích hàm `ARKernelInterface::RenderMeshWarp` và đối soát với struct C++ trong `libMT3DFaceJNI.so`.

---

## 2. KẾ HOẠCH THỰC NGHIỆM TIẾP THEO (NEXT PROBES ROADMAP)
1. **Probe A (Hair Swatches Extraction):** Trích xuất toàn bộ 48 tệp swatch màu tóc thương mại từ Meitu assets.
2. **Probe B (Ablation Benchmark Plan):** Xây dựng kế hoạch kiểm thử triệt tiêu (Ablation Study):
   - Tắt Pass 5 (LIC) -> Đo độ rối và hạt nhiễu sợi tóc.
   - Tắt Pass 7 (Unsharp Clarity) -> Đo độ bệt màu và mất độ bóng lọn tóc.
   - So sánh Pegtop SoftLight vs Standard Photoshop SoftLight -> Đo mức độ giữ chi tiết vùng tối.
3. **Probe C (Vulkan Native Compute Pipeline Prototype):** Chuẩn bị bản thiết kế khung làm việc Vulkan Compute shader cho 8 giai đoạn tóc phục vụ clean-room implementation khi có lệnh ACTIVE mở V4.
