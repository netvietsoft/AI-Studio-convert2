# CONVERT2 — REVERSE ENGINEERING KNOWLEDGE BASE MASTER INDEX
**Version:** 1.0.0  
**Authority:** Chủ tịch Tony  
**Canonical Standard:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Task ID:** TASK_047_IMAGE_EFFECT_GRAPH_DEEP_MAPPING_ACTIVE  
**Status:** CANONICAL / PERSISTENT ARCHITECTURE SPECIFICATION  

---

## 1. THƯ CỦA CHỦ TỊCH TONY & NGUYÊN TẮC VẬN HÀNH (EXECUTIVE MANDATE)
> "Tuyệt đối không vội vàng triển khai Hair V4. Trước hết phải xây dựng Đồ thị Hiệu ứng Hình ảnh (Image Effect Graph) sâu sắc nhất, đầy đủ bằng chứng khoa học và thực nghiệm nhất có thể. Mọi nỗ lực viết mã V4 đều bị CẤM cho đến khi cơ quan kiểm định độc lập tuyên bố pha nghiên cứu đồ thị hoàn tất."

Tài liệu này là **Cổng Thông Tin Tổng Hành Dinh** kết nối toàn bộ tri thức kỹ thuật đảo ngược sạch thu được từ quá trình phân tích 45 thư viện nhị phân Meitu, mã nguồn C++ V1, và 14 ứng dụng xử lý ảnh đỉnh cao tại `F:\App\Image`.

---

## 2. NGUYÊN TẮC PHÒNG SẠCH & PHÁP LÝ (CLEAN-ROOM COMPLIANCE)
1. **Chỉ Phân Tích Đọc (Read-Only Analysis):** Mọi công tác khảo sát chỉ phục vụ trích xuất quy luật toán học, kiến trúc luồng dữ liệu, tham số chuẩn hóa và giao diện đồ họa.
2. **Cấm Sao Chép (No Code / Binary Copy):** Tuyệt đối KHÔNG sao chép nhị phân thương mại hoặc mã nguồn có bản quyền vào kho mã nguồn CONVERT2.
3. **Bảo Vệ Hệ Thống:** Không phá vỡ kiểm soát quyền truy cập, thanh toán in-app, chữ ký số, khóa bảo mật hay DRM.

---

## 3. CÂY THƯ MỤC CƠ SỞ TRI THỨC BỀN VỮNG (PERSISTENT REPOSITORY STRUCTURE)

```
F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\
├── REVERSE_ENGINEERING_KNOWLEDGE_INDEX.md           <-- [Cổng Chính] Tài liệu này
└── .ai\reverse_engineering\
    ├── 00_MASTER_INVENTORY.md                       <-- Danh mục 45 SO, 14 Apps, Models, Shaders
    ├── 01_IMAGE_EFFECT_GRAPH.md                     <-- Đồ thị Hiệu ứng Hình ảnh chuẩn từng Node
    ├── 02_FEATURE_TO_PROCESSING_MAP.md              <-- Ánh xạ UI -> JNI -> C++ -> GPU -> Pixel
    ├── 03_UNKNOWN_NEXT_RESEARCH.md                  <-- Danh mục các điểm chưa rõ & kế hoạch nghiên cứu
    ├── index.json                                   <-- Chỉ mục JSON có cấu trúc cho máy đọc
    └── effects\
        ├── 01_HAIR_EFFECT_DOSSIER.md                <-- Hồ sơ Tóc P0 khép kín 8 giai đoạn (Pass Gate)
        ├── 02_FACE_SKIN_BEAUTY_DOSSIER.md           <-- Hồ sơ Da & Khuôn mặt vi lỗ chân lông
        ├── 03_BODY_WARP_PROTECTION_DOSSIER.md       <-- Hồ sơ Nắn bóp vóc dáng khóa nền
        ├── 04_COLOR_LUT_TONE_DOSSIER.md             <-- Hồ sơ 3D LUT Tứ diện & Tone Spline
        ├── 05_MAKEUP_SYNTHESIS_DOSSIER.md           <-- Hồ sơ Trang điểm biến dạng lưới 106 điểm
        └── 06_RESTORATION_INPAINT_DOSSIER.md        <-- Hồ sơ Xóa vật thể LaMa & Hòa trộn Poisson
```

---

## 4. TỔNG KẾT CỔNG NGHIỆM THU TÓC (HAIR COMPLETION GATE)
Phân hệ Tóc đạt trạng thái **PASS** tuyệt đối, chứng minh khép kín 8/8 giai đoạn bằng mã máy ARM64 và GLSL nhúng thực tế:
1. **mask/segmentation:** `bisenetv2_hair_19class.bin` (BiSeNetV2 512x512) -> **PROVEN**
2. **alpha/matting/hairline:** `hairMaskFilterToFBO` (`0x000f4400`) -> **PROVEN**
3. **luminance/feature extraction:** `GrayFilterToFBO` (`0x000f42fc`, GLSL `0x804fc`) -> **PROVEN**
4. **orientation/structure field:** `HairMaskFilterToFBO` (`0x134970`) & 5-tap Blur (`0x8edd8`) -> **PROVEN**
5. **directional texture processing:** 21-tap LIC `SoftHairFilterToFBO` (`0x86106`, `0x8fd64`) -> **PROVEN**
6. **recolor/blend:** `blendSoftLight` Pegtop không phân nhánh (`0x82369`) -> **PROVEN**
7. **shine/clarity:** 9x9 Unsharp Mask + Clarity 0.4 `MTSoftHairFilter.cpp` (`0x77afa`) -> **PROVEN**
8. **compositing/output:** Alpha Composite khóa 100% vùng da và nền (`0x134e90`) -> **PROVEN**

---

## 5. CHỈ THỊ VỀ VIỆC TRIỂN KHAI V4
> **LỆNH CẤM TRIỂN KHAI V4:**  
> Mọi hoạt động viết mã sản xuất hoặc thử nghiệm cho phiên bản Hair V4 đều **BỊ CẤM HOÀN TOÀN** trong Task này. Không chỉnh sửa mã nguồn Hair V2/V3 đang chạy ổn định.  
> Chỉ sau khi báo cáo khảo sát TASK_047 được phê duyệt và một Task ACTIVE tiếp theo được cấp lệnh, việc thiết kế Core V4 mới được xem xét.

---
*Tài liệu được thiết lập chính thức theo Tiêu Chuẩn Phát Triển CONVERT2.*