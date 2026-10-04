# decodeHairDyeConfig & loadHairDyeConfig — Phân Giải & Nạp Cấu Hình Màu Nhuộm
**Thư viện:** `libLayerFlow.so`  
**Địa chỉ RVA:** `0x00067340` & `0x000685b0`  
**Biểu tượng C++:**
- `LayerFlow::CHairConfigDecoder::DecodeConfigJSON(char const*, LayerFlow::HairDyeSetting&)`
- `LayerFlow::CHairConfigLoader::LoadResources(LayerFlow::LFContextData*, LayerFlow::HairDyeSetting const&)`  
**Độ tin cậy:** `PROVEN_RAW_SYMBOLS`  
**Mức độ trưởng thành:** `PSEUDOCODE_RECOVERED`  

---

## 1. Cấu Trúc Dữ Liệu HairDyeSetting
```cpp
struct HairDyeSetting {
    float primary_color[3];    // RGB màu chính (ví dụ Rose Gold: 0.92, 0.65, 0.71)
    float secondary_color[3];  // RGB màu chân tóc (shadow root)
    float gradient_bias;       // Vị trí chuyển tông từ chân tới ngọn tóc [0.0, 1.0]
    float shine_intensity;     // Độ bóng ánh sáng phản xạ [0.0, 1.0]
    float specular_power;      // Bậc phản xạ Blinn-Phong [8.0, 64.0]
    int   palette_lut_index;   // Chỉ số texture LUT 1D
};
```
