# 00_SO_MASTER_INVENTORY.md — DANH MỤC TỔNG THỂ 45 THƯ VIỆN NHỊ PHÂN .SO NHÀ CUNG CẤP
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Cập nhật:** TASK_051 (2026-10-04T20:31:00+07:00)  

---

## 1. TỔNG QUAN PHÂN BỔ 45 THƯ VIỆN THEO MIỀN CHỨC NĂNG

1. **Phân hệ Lõi Thuật toán & Nhuộm tóc P0 (3 SO):**
   - `libMTFilterKernel.so`: 5 FBO passes của `MTSoftHairFilter`, 9x9 Unsharp Mask, Pegtop SoftLight, Gaussian blur 5 điểm.
   - `libLayerFlow.so`: Cấu trúc ten-xơ góc kép, 21-tap LIC, JNI `EffectDenseHairDataJNI`, biến dạng Moving Least Squares.
   - `libPVGColorFunctions.so`: Chuyển đổi không gian màu, 3D LUT texture, shader `gGLESColorTransferFragData`.

2. **Phân hệ Lõi AI & Thị giác Máy tính P1 (6 SO):**
   - `libManis.so`: Generic neural network inference runtime (Class 17 hair segmentation, portrait matting).
   - `libaidetectionplugin.so`: Phân tích landmark khuôn mặt và phân tách ngữ nghĩa.
   - `libAIModelKit.so`: Quản lý nạp và bộ nhớ ten-xơ mô hình AI.
   - `libarkernel3.so`: Khớp lưới tam giác 3D khuôn mặt 106 điểm và nhận diện 24 điểm cơ thể.
   - `libVERenderer.so`: Đồ thị kết xuất khung hình đồ họa GPU đa luồng.
   - `libmfxkit.so`: Bộ đổ bóng và hiệu ứng đồ họa chuyên sâu.

3. **Phân hệ Mã hóa & Đa phương tiện P2 (5 SO):**
   - `libffmpeg.so`, `libPVGCodec.so`, `libffavc.so`, `libPVGVideoCodec.so`, `libPVGImageCodec.so`.

4. **Phân hệ Tiện ích, Hệ thống & Bảo mật P3 (31 SO):**
   - 6 Thư viện bảo mật/DRM được bảo vệ loại trừ pháp lý Clean-Room (Rule 11): `libdexvmp.so`, `libMtlabSign.so`, `libhttpelf.so`, `libCtaApiLib.so`, `libfile_lock_pgl.so`, `libbuffer_pgl.so`.
   - 25 Thư viện tiện ích hệ thống: `libbytehook.so`, `libglide-webp.so`, `libbmpKit.so`, `libkoom-strip-dump.so`, v.v.

---

## 2. MA TRẬN TRƯỞNG THÀNH 45 THƯ VIỆN NHỊ PHÂN
*(Dữ liệu đồng bộ trực tiếp từ `02_45_SO_MASTER_MATURITY_MATRIX.csv`)*
