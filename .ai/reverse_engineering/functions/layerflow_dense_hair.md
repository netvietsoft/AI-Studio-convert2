# EffectDenseHairDataJNI & LFDenseHairModular
**Thư viện:** `libLayerFlow.so`  
**Cầu nối JNI:** `com.meitu.core.layerflow.EffectDenseHairDataJNI`  
**Địa chỉ offset:** `0x00021b40`  

### 1. Danh mục hàm JNI tĩnh
- `nativeCreate()` -> Khởi tạo `LFDenseHairModular`
- `nativeSetHairMask(long, Bitmap)` -> Gán mặt nạ tóc
- `nativeSetAlpha(long, float)` -> Cường độ nhuộm
- `nativeSetHighLights(long, float)` -> Cường độ bóng sợi tóc
- `nativeSetMaterialId(long, int)` -> Mã vật liệu màu tóc (2305 = Rose Gold)
