# nSetTraditionHairDyeIntensityAndShine — Cầu Nối JNI Điều Khiển Tham Số Nhuộm
**Thư viện:** `libLayerFlow.so`  
**Địa chỉ RVA:** `0x00051e80`  
**Ký hiệu Xuất:** `Java_com_meitu_effect_EffectDenseHairDataJNI_nSetTraditionHairDyeIntensityAndShine`  
**Chữ ký JNI:** `(JFF)V`  
**Độ tin cậy:** `PROVEN_EXPORTED_SYMBOL`  
**Mức độ trưởng thành:** `PSEUDOCODE_RECOVERED`  

---

## 1. Chi Tiết Thực Thi Cầu Nối JNI
```cpp
JNIEXPORT void JNICALL
Java_com_meitu_effect_EffectDenseHairDataJNI_nSetTraditionHairDyeIntensityAndShine(
    JNIEnv* env, jobject thiz, jlong nativeHandle, jfloat intensity, jfloat shine) {
    if (nativeHandle == 0) return;
    auto* pEngine = reinterpret_cast<LayerFlow::CLFDenseHairEngine*>(nativeHandle);
    pEngine->SetParameters(intensity / 100.0f, shine / 100.0f);
}
```
