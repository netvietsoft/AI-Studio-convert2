# 16 — PHÂN TÍCH CÂY PHẢ HỆ CÔNG NGHỆ & MỐI QUAN HỆ ĐA ỨNG DỤNG
# BẢN ĐỒ XUẤT XỨ CÔNG NGHỆ 14 ỨNG DỤNG TẠI F:\APP\IMAGE

---

## 1. CÁC CỤM PHẢ HỆ CÔNG NGHỆ CHÍNH

### Cụm 1: Hệ Sinh Thái Meitu (Meitu Core Lineage)
- **Ứng dụng thành viên:** `com.mt.mtxx.mtxx` (Meitu Reborn), `com.commsource.beautyplus` (BeautyPlus), `com.meitu.wink` (Wink).
- **Mã nguồn lõi chung:** Sử dụng chung thư viện `libMTFilterKernel.so`, `libMTBeautyEngine.so`, `libManis.so`.
- **Đặc trưng:** Cùng bảng trọng số Gauss 5-tap `[0.159676, 0.263348, ...]`, cùng chuỗi shader làm đẹp và cùng cấu trúc dữ liệu JNI `EffectDenseHairDataJNI`.

### Cụm 2: Hệ Sinh Thái Lightricks (Israel Flagship)
- **Ứng dụng thành viên:** `com.lightricks.facetune.free` (Facetune).
- **Đặc trưng:** Phát triển độc lập hoàn toàn bằng C++ hiện đại, tập trung vào thuật toán phân tách tần số (Frequency Separation) và bảo lưu vi lỗ chân lông.

### Cụm 3: Hệ Sinh Thái ByteDance / Asian Beauty
- **Ứng dụng thành viên:** `com.gorgeous.lite` (Ulike), `com.linecorp.b612.android` (B612).
- **Đặc trưng:** Tích hợp bộ SDK làm đẹp thương mại hàng đầu châu Á (ByteDance EffectSDK và SenseTime STMobile SDK), tối ưu hóa cực đoan cho camera thời gian thực 60 FPS.

### Cụm 4: Chuẩn Mực Màu Sắc Chuyên Nghiệp (Western Color Engines)
- **Ứng dụng thành viên:** `com.adobe.lrmobile` (Lightroom), `com.vsco.cam` (VSCO).
- **Đặc trưng:** Pipeline màu 32-bit float, đường cong Spline tham số, mô phỏng hạt phim nhũ tương và nội suy khối tứ diện 3D LUT.
