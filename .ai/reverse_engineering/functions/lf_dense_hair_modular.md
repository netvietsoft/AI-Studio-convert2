# LFDenseHairModular — Bộ Điều Phối Dòng Lớp Tóc Đa Tầng
**Thư viện:** `libLayerFlow.so`  
**Địa chỉ RVA:** `0x00083a20`  
**Biểu tượng C++:** `LayerFlow::CLFDenseHairEngine::RenderDenseFlow(LayerFlow::LFContextData*, LayerFlow::LFRenderTarget*)`  
**Độ tin cậy:** `PROVEN_RAW_DISASM`  
**Mức độ trưởng thành:** `PSEUDOCODE_RECOVERED`  

---

## 1. Kiến Trúc Modular LayerFlow
`libLayerFlow.so` đóng vai trò là động cơ quản lý các lớp đồ họa động (Layer Graph).
Với module tóc dày (`LFDenseHairModular`):
- Quản lý 3 lớp đồ họa con:
  1. `BaseHairLayer`: Chứa cấu trúc sợi tóc cơ bản và độ chói gốc.
  2. `DyePigmentLayer`: Chứa bản đồ màu nhuộm đa sắc (gradient root-to-tip).
  3. `SpecularSheenLayer`: Chứa bản đồ phản xạ ánh sáng kim tuyến (tangent-space sheen).
- Tự động biên dịch đồ thị hiệu ứng thành chuỗi lệnh OpenGL ES / Vulkan FBO tương ứng.
