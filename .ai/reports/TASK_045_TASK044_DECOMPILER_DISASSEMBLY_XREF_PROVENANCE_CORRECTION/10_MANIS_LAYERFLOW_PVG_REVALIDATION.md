# TASK_045 — FORENSIC REVALIDATION: MANIS, LAYERFLOW & PVG

**Canonical Authority:** Chủ tịch Tony  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Phạm vi:** Tái thẩm định chuyên sâu 3 thư viện thuật toán còn lại bị nghi vấn tại TASK_044:
1. `libManis.so` (Semantic Segmentation / BiSeNet claim)
2. `libLayerFlow.so` (Dense Hair Parameter claim)
3. `libPVGColorFunctions.so` (Display-P3 Matrix claim)

---

## 1. TÁI THẨM ĐỊNH `libManis.so` (KHIẾM KHUYẾT DEF-05)

### Thực tế Nhị phân:
- Dung lượng: `9,928,576` bytes.
- Mã băm SHA-256: `9B4EE0537AE08C757F1407AEF32CD5982D5C75CAE892DCEE1B008658097CD8E9`.
- Kết quả quét từ khóa: Tìm kiếm `bisenet`, `class17`, `hair_class` trong toàn bộ `.rodata`, `.text`, `.dynsym` cho ra **0 kết quả**.

### Kết luận Khoa học:
- `libManis.so` là lõi thực thi mạng nơ-ron học sâu (Neural Network Inference Engine) đa nền tảng do Meitu phát triển (tương tự như NCNN của Tencent hoặc TNN của Youtu).
- Khẳng định của TASK_044 rằng *"libManis.so thực thi thuật toán BiSeNet 19 lớp và trích xuất lớp 17"* là một phỏng đoán không có cơ sở trong mã máy (unsupported claim).
- **Phân loại lại:** `libManis.so` chỉ cung cấp các toán tử ma trận (Conv2D, DepthwiseConv, ReLU, Softmax, ArgMax). Định nghĩa kiến trúc BiSeNet và ánh xạ nhãn lớp (Class 17 = Hair) được nạp động từ file tệp tin mô hình ngoài APK (`.manis` model weights/config).

---

## 2. TÁI THẨM ĐỊNH `libLayerFlow.so` (KHIẾM KHUYẾT DEF-06)

### Thực tế Nhị phân:
- Dung lượng: `5,544,776` bytes.
- Mã băm SHA-256: `E9C4F8171120CE1F10705F25539BC87FDC7BEE7A6224151744CFECF9732B03CE`.
- Phân tích bảng ký hiệu tại offset `0x53131` xác nhận lớp điều khiển tóc thực sự là:
  `EffectDenseHairDataJNI`

### Bảng Ánh xạ Ký hiệu JNI Thực tế:
```
Offset 0x5317e: EffectDenseHairDataJNI::nGetOptType(JNIEnv*, jclass, jlong)
Offset 0x531ca: EffectDenseHairDataJNI::nSetOptType(JNIEnv*, jclass, jlong, jint)
Offset 0x53217: EffectDenseHairDataJNI::nGetFaceId(JNIEnv*, jclass, jlong)
Offset 0x53262: EffectDenseHairDataJNI::nSetFaceId(JNIEnv*, jclass, jlong, jint)
Offset 0x532ae: EffectDenseHairDataJNI::nGetMaterialId(JNIEnv*, jclass, jlong)
Offset 0x532fd: EffectDenseHairDataJNI::nSetMaterialId(JNIEnv*, jclass, jlong, jlong)
Offset 0x5334d: EffectDenseHairDataJNI::nGetAlpha(JNIEnv*, jclass, jlong) -> jfloat
Offset 0x53396: EffectDenseHairDataJNI::nSetAlpha(JNIEnv*, jclass, jlong, jfloat)
Offset 0x533e0: EffectDenseHairDataJNI::nIsHighLights(JNIEnv*, jclass, jlong) -> jboolean
Offset 0x5342e: EffectDenseHairDataJNI::nSetHighLights(JNIEnv*, jclass, jlong, jboolean)
Offset 0x534ce: EffectDenseHairDataJNI::nIsEnable(JNIEnv*, jclass, jlong) -> jboolean
Offset 0x53517: EffectDenseHairDataJNI::nSetEnable(JNIEnv*, jclass, jlong, jboolean)
Offset 0x53563: EffectDenseHairDataJNI::nGetModular(JNIEnv*, jclass, jlong)
Offset 0x5347e: EffectDenseHairDataJNI::nDestroyModular(JNIEnv*, jclass, jlong)
```

### Kết luận Khoa học:
- Không tồn tại hàm `decodeHairDyeConfig` hay các tham số `Gloss` và `Feather Radius` trong JNI của `libLayerFlow.so`.
- Tham số thực tế điều khiển tóc dày (`DenseHair`) bao gồm: `Alpha` (độ đậm nhạt của màu tóc), `HighLights` (cờ bật/tắt sợi tóc highlight), `MaterialId` (ID chất liệu tóc nhuộm) và `FaceId` (ID khuôn mặt liên kết).

---

## 3. TÁI THẨM ĐỊNH `libPVGColorFunctions.so` (KHIẾM KHUYẾT DEF-04)

### Thực tế Nhị phân:
- Dung lượng: `380,224` bytes.
- Mã băm SHA-256: `B9A608482A0F5A138407BFF415C22774C37BF1570F282563DE9E256C82F2494E`.
- Tìm kiếm nhị phân giá trị float `1.224940` (P3-to-sRGB coefficient) trong toàn bộ file: **0 kết quả**.

### Chứng cứ Chuyển đổi Không gian Màu Thực tế:
- Hàm chuyển đổi: `PVGCOLOR::PVGColorFunctions::transcode` tại địa chỉ `0x00021058`.
- Hồ sơ màu chuẩn được quản lý bằng các bảng profile nhúng:
  - `getSRGBICCProfile()` tại `0x00020f60`
  - `getDisplayP3ICCProfile()` tại `0x00020f70`
  - `getAdobeRGBICCProfile()` tại `0x00020f84`
- Shader fragment nhúng: `gGLESColorTransferFragData` tại địa chỉ `0x00011170` (kích thước `gGLESColorTransferFragSize` tại `0x000176a0`).

### Kết luận Khoa học:
- Thư viện `libPVGColorFunctions.so` sử dụng các đường cong màu ICC Profile và shader OpenGL ES nhúng để chuyển đổi màu chính xác theo tiêu chuẩn ngành, thay vì nhân ma trận 3x3 float thô như TASK_044 đã khẳng định.
