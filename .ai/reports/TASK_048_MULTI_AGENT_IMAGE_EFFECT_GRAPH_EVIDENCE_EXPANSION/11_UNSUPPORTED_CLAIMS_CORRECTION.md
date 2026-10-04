# TASK_048 — RETRACTION & CORRECTION OF UNSUPPORTED TASK_047 CLAIMS
**Authority:** Chủ tịch Tony  
**Task ID:** TASK_048_MULTI_AGENT_IMAGE_EFFECT_GRAPH_EVIDENCE_EXPANSION_ACTIVE  
**Execution Lane:** LANE F (Worker Identity: `WORKER-LANE-F-AUDIT-PROVENANCE`)  
**Audit Finding on TASK_047:** NEEDS_FIX  
**Guiding Principle:** Bằng chứng thực tế trên đĩa là Chân lý Duy nhất (Ground-Truth Only). Cấm dựng tên, cấm báo cáo láo.  

---

## 1. DANH MỤC 7 NHẬN ĐỊNH SAI LỆCH CỦA TASK_047 ĐÃ ĐƯỢC ĐÍNH CHÍNH

### 1. Yêu cầu sửa: `facetune_hair_seg_v4.tflite`
- **Khẳng định sai trong TASK_047:** Báo cáo TASK_047 tuyên bố Facetune sở hữu mô hình `facetune_hair_seg_v4.tflite` với độ tin cậy PROVEN.
- **Thực tế kiểm tra đĩa tại TASK_048:** Kiểm tra nhị phân bên trong `Facetune+Hair,+Photo+Editor_2.60.0.1-free_APKPure.xapk` xác định **KHÔNG TỒN TẠI** tệp tin nào có tên `facetune_hair_seg_v4.tflite`.
- **Hiện vật thật trên đĩa:** Tệp mô hình phân đoạn người thật trong Facetune là `assets/selfiesegmentation_mlkit-256x256-2021_01_19-v1215.f16.tflite` (249,024 bytes, SHA256: `8d13b7fae74af625fbe374f6e1f0e21a41e97ae2b1e7798c558c42cf0a1c1d9f`).
- **Hành động khắc phục:** Thu hồi hoàn toàn tên `facetune_hair_seg_v4.tflite`. Cập nhật sổ đăng ký bằng tệp MediaPipe TFLite thật. Hạ mức độ tin cậy của thuật toán tóc riêng của Facetune xuống HYPOTHESIS/UNSUPPORTED.

### 2. Yêu cầu sửa: `faceapp_hair_color_neural.onnx`
- **Khẳng định sai trong TASK_047:** TASK_047 ghi nhận FaceApp có mô hình ONNX nội bộ `faceapp_hair_color_neural.onnx` chạy trên thiết bị (PROVEN).
- **Thực tế kiểm tra đĩa tại TASK_048:** Kiểm tra `FaceApp+Perfect+Face+Editor_12.9.6_APKPure.apk` (46.9 MB) xác định **HOÀN TOÀN KHÔNG CÓ** tệp ONNX nào. APK FaceApp thậm chí không chứa bất kỳ tệp `.so` nào trong thư mục `lib/`.
- **Hiện vật thật trên đĩa:** FaceApp chỉ chứa các mô hình TFLite nhẹ (`assets/gender.tflite`, `assets/retouch_int8.tflite`, `assets/retouch_v2.bin`) để phục vụ căn chỉnh khuôn mặt trên máy khách. Toàn bộ xử lý mạng nơ-ron biến đổi tóc và lão hóa diễn ra trên máy chủ đám mây (Cloud REST API).
- **Hành động khắc phục:** Thu hồi toàn bộ claim về mô hình ONNX nhuộm tóc cục bộ của FaceApp. Hạ mức độ tin cậy từ PROVEN xuống CLOUD_API_OBSERVED.

### 3. Yêu cầu sửa: `faceapp_relight_sh.onnx`
- **Khẳng định sai trong TASK_047:** Khẳng định FaceApp có mô hình chiếu sáng hình cầu Spherical Harmonics 9 hệ số `faceapp_relight_sh.onnx` trên thiết bị.
- **Thực tế kiểm tra đĩa tại TASK_048:** Tệp này không tồn tại trong APK.
- **Hành động khắc phục:** Thu hồi tên tệp. Xóa khỏi danh mục PROVEN.

### 4. Yêu cầu sửa: `remini_face_enhancer_v3.bin`
- **Khẳng định sai trong TASK_047:** Ghi nhận Remini chạy mô hình NCNN `remini_face_enhancer_v3.bin` (24.8 MB) và `remini_face_enhancer_v3.param`.
- **Thực tế kiểm tra đĩa tại TASK_048:** Kiểm tra `Remini_3.7.1447.202524746.apks` và các tệp split xác định Remini sử dụng `libonnxruntime.so` (14 SOs trong split arm64), nhưng mô hình siêu phân giải chân dung **KHÔNG BUNDLE NỘI BỘ TRONG APK**. Tệp ONNX duy nhất có trong APK là `assets/ad_abandonment_android_enhance_xgb.onnx` (mô hình dự đoán bỏ dở quảng cáo). Tính năng phục hồi ảnh cũ được thực thi 100% qua Cloud Server.
- **Hành động khắc phục:** Thu hồi tên `remini_face_enhancer_v3.bin` và `libncnn.so`. Đính chính Remini là Cloud AI Super-Resolution, chỉ có client ONNX runtime.

### 5. Yêu cầu sửa: `lama_inpaint_fp16.tflite`
- **Khẳng định sai trong TASK_047:** Khẳng định SnapEdit tích hợp mô hình LaMa Fourier inpainting cục bộ `lama_inpaint_fp16.tflite` (38.9 MB) và `libopencv_java4.so`.
- **Thực tế kiểm tra đĩa tại TASK_048:** Kiểm tra `SnapEdit+-+AI+photo+editor_7.7.7_APKPure.xapk` xác định không có `libopencv_java4.so` và không có `lama_inpaint_fp16.tflite`. SnapEdit sử dụng `libxeno_native.so` (21.6 MB, framework Google MediaPipe Xeno) và `selfiesegmentation_mlkit-256x256-2021_01_19-v1215.f16.tflite`. Xóa vật thể nâng cao được gọi qua Cloud Inpaint API.
- **Hành động khắc phục:** Thu hồi tên tệp `lama_inpaint_fp16.tflite`. Đính chính mô hình client thật là MediaPipe Selfie Segmentation TFLite.

### 6. Yêu cầu sửa: `beautyplus_face_landmark_106.bin`
- **Khẳng định sai trong TASK_047:** Đặt tên mô hình landmark của BeautyPlus là `beautyplus_face_landmark_106.bin`.
- **Thực tế kiểm tra đĩa tại TASK_048:** Kiểm tra `BeautyPlus_7.46.0.apks::split_install_time_asset_pack.apk` xác định tên tệp thật trên đĩa là `assets/MTAiModel/3DFaceModel/Lanmark.bin` (344 bytes, SHA256: `d2edb8332db4334e15da692994e6378e906c27187c3fcb1fc0a56e4fc345ce2b`).
- **Hành động khắc phục:** Đổi tên về đúng nguyên bản trên đĩa `Lanmark.bin`.

### 7. Yêu cầu sửa: `bytenn_skin_mask_v2.model`
- **Khẳng định sai trong TASK_047:** Đặt tên mô hình phân đoạn da của ULike là `bytenn_skin_mask_v2.model`.
- **Thực tế kiểm tra đĩa tại TASK_048:** Kiểm tra `ULike_5.6.2.apks::base.apk` phát hiện thư mục `assets/model/skin_seg/` chứa:
  - `tt_skin_seg_v5.0.model` (260,961 bytes, SHA256: `dcfc109297b1db0651717325514f77c385ef3d91cfaf416d8a264a4b277e9db8`)
  - `tt_skin_seg_fast_v5.0.model` (92,089 bytes)
  - `tt_hair_v11.0.model` (81,044 bytes, SHA256: `018bcb4f59942aa2f7eb21516e838f5f6b28236cb100ea8b4e72ce90479aa5fc`)
  Hoàn toàn không có tệp nào tên `bytenn_skin_mask_v2.model`.
- **Hành động khắc phục:** Thu hồi tên suy đoán, thay thế bằng các tệp có thật `tt_skin_seg_v5.0.model` và `tt_hair_v11.0.model`.

---

## 2. ĐÍNH CHÍNH VỀ CÁC TUYÊN BỐ SỐ LIỆU ĐO ĐẠC (TIMING & ACCURACY CLAIMS)
1. **Timing Samsung A50:** Các số liệu timing nêu trong TASK_047 được xác định là số liệu tham chiếu từ đợt kiểm thử P6 trước đó, không phải kết quả đo trực tiếp trong phiên chạy TASK_047. TASK_048 đính chính hạ cấp trạng thái về REFERENCE_BENCHMARK, không tuyên bố là live run nếu chưa chạy adb benchmark trong phiên hiện tại.
2. **Pore-retention % và Background 100%:** Được ghi nhận là tiêu chuẩn thiết kế mục tiêu (Design Target Standard) và đã được kiểm chứng thuật toán qua công thức giải tích (Zero Falloff ngoài vùng mask), nhưng không được tuyên bố thay cho kết quả đo pixel thực tế trên ảnh output nếu chưa xuất ảnh nghiệm thu trực tiếp.
3. **Hair 8/8 PROVEN:** Cả 8 giai đoạn tóc của Meitu được giữ nguyên mức độ PROVEN vì đã trích xuất được địa chỉ hàm ARM64, symbol C++ demangled và nguyên văn shader GLSL từ `libMTFilterKernel.so` và `libLayerFlow.so` ngay trong phiên này.
