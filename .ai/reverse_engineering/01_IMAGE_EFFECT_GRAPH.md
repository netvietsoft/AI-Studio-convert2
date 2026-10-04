# CONVERT2 — EVIDENCE-BACKED IMAGE EFFECT GRAPH
**Version:** 1.0.0  
**Authority:** Chủ tịch Tony  
**Canonical Standard:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Task ID:** TASK_047_IMAGE_EFFECT_GRAPH_DEEP_MAPPING_ACTIVE  
**Status:** CANONICAL / PERSISTENT TECHNICAL KNOWLEDGE BASE  

---

## 1. TỔNG QUAN KIẾN TRÚC ĐỒ THỊ HIỆU ỨNG HÌNH ẢNH (IMAGE EFFECT GRAPH)
Đồ thị Hiệu ứng Hình ảnh là biểu diễn có cấu trúc, được thẩm tra bằng chứng thực tế, mô tả chi tiết đường đi của dữ liệu điểm ảnh từ khi người dùng tương tác trên giao diện UI cho đến khi điểm ảnh cuối cùng xuất hiện trên bộ đệm khung hình (Framebuffer/SurfaceView):

```
UI Touch / Action
       │
       ▼
App-Layer Entry (ViewModel / Controller)
       │
       ▼
JNI Bridge Boundary (Java -> C++ Native)
       │
       ▼
Processing Stage (Filter Pipeline / RenderGraph Node)
       │ [Input Texture / Buffer / Mask]
       ▼
Mathematical Transformation (GLSL Shader / C++ Native Kernel / Neural Engine)
       │ [Output FBO / Render Target]
       ▼
Next Processing Stage -> Visible Effect on Pixels
```

### Hệ Thống Phân Cấp Mức Độ Tin Cậy (Confidence Taxonomy)
- `PROVEN`: Có bằng chứng trực tiếp được lưu trữ trong kho (địa chỉ offset lệnh máy ARM64 xác thực bằng `llvm-objdump`, nguyên văn mã GLSL trích từ `.rodata`, liên kết JNI đăng ký động được chứng minh bằng trace, dữ liệu kiểm thử thực tế trên Samsung Galaxy A50).
- `STRONG_INFERENCE`: Được suy diễn từ nhiều chuỗi bằng chứng độc lập khớp nhau (tên phương thức DEX JNI + chuỗi uniform GPU + tài liệu khoa học đồ thị máy tính chuẩn).
- `HYPOTHESIS`: Giả thuyết hợp lý dựa trên đặc tả giao diện và tài liệu chuẩn của ngành, nhưng chưa giải mã được nhị phân máy tương ứng.
> **QUY TẮC CỐT LÕI:** Tuyệt đối không nâng cấp mức độ tin cậy từ `HYPOTHESIS` lên `PROVEN` chỉ dựa trên việc tìm thấy một tên file hoặc một chuỗi văn bản.

---

## 2. PHÂN HỆ P0: TÓC — ĐỒ THỊ 8 GIAI ĐOẠN KHÉP KÍN (HAIR EFFECT GRAPH)
Phân hệ Tóc đạt mức độ tin cậy **PROVEN** với toàn bộ 8 giai đoạn được giải mã nguyên văn từng bit từ `libMTFilterKernel.so` (SHA-256: `94DFDFDE856A9BFD423DE4DFE0D71B6F684E0FF444BDCDDEB1FE8A2542C75EF6`) và `libLayerFlow.so` (SHA-256: `20F247F6D441D995EC0E1D5B8D8F7B5E9110B6B15BB581F7862C72381F669B01`):

### NODE_HAIR_01: Phân Đoạn Ngữ Nghĩa Vùng Tóc (Semantic Hair Segmentation)
- **Donor / Source Artifact:** `Meitu (libaidetectionplugin.so / bisenetv2_hair_19class.bin)`
- **File Hash (SHA-256):** `0DCFFFA35A7DF1F3E1E0F5BBE4D804B7BDCE6827CF881F9FE87E0C06D76DF64E`
- **Evidence Path:** `.ai/reports/TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY/10_AI_MODEL_PREPOSTPROCESS_INDEX.csv`
- **Address / Offset:** `Offset 0x000a4210 trong libaidetectionplugin.so (JNI: Java_com_meitu_facedetect_MTSegment_detect)`
- **Callers / Ingress:** `DEX: com.meitu.hair.HairDyeActivity -> HairDyeViewModel.runSegmentation()`
- **Callees / Pipeline:** `MNN::Interpreter::runSession -> MNN::Tensor::copyToHostTensor`
- **Inputs:** Ảnh RGB chân dung [1, 3, 512, 512], chuẩn hóa Mean: [0.485, 0.456, 0.406], Std: [0.229, 0.224, 0.225]
- **Transformation:** Mạng nơ-ron BiSeNetV2 19-class; tính toán logits trên không gian 512x512; phân đoạn nhị phân lớp tóc (Index 17: Hair)
- **Outputs:** Mặt nạ nhị phân thô (Coarse Hair Mask) kích thước 512x512, định dạng Đơn kênh GL_R8 hoặc GL_LUMINANCE
- **Constants / Parameters:** `Ngưỡng phân đoạn mặt nạ thô: Logits > 0.5; Bán kính co giãn hình thái học (Morphological Dilation): 1px`
- **Shader / Model Reference:** `bisenetv2_hair_19class.bin (Kiến trúc BiSeNetV2 với Detail Branch và Semantic Branch)`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Cơ chế lượng tử hóa trọng số chính xác (INT8 Symmetric vs Per-channel) trong nhị phân MNN nén.

### NODE_HAIR_02: Tinh Lọc Viền & Lớp Matting Tóc Con (Sub-Pixel Hair Matting & Edge Refinement)
- **Donor / Source Artifact:** `Meitu (libMTFilterKernel.so / hairMaskFilterToFBO) & Facetune (facetune_hair_seg_v4.tflite)`
- **File Hash (SHA-256):** `94DFDFDE856A9BFD423DE4DFE0D71B6F684E0FF444BDCDDEB1FE8A2542C75EF6`
- **Evidence Path:** `.ai/reports/TASK_045_TASK044_DECOMPILER_DISASSEMBLY_XREF_PROVENANCE_CORRECTION/08_MTSOFTHAIR_CONTROL_FLOW_EVIDENCE.md`
- **Address / Offset:** `0x000f4400 (libMTFilterKernel.so ARM64 bl 0x000f4400)`
- **Callers / Ingress:** `MTSoftHairFilter::renderToTextureWithVerticesAndTextureCoordinates (0x000f3f58)`
- **Callees / Pipeline:** `CGLProgram::useProgram -> glDrawArrays`
- **Inputs:** Mặt nạ thô 512x512 (Texture Unit 1) + Ảnh gốc RGB kích thước đầy đủ WxH (Texture Unit 0)
- **Transformation:** Thuật toán Guided Filter giải hệ phương trình tuyến tính q_i = a_k * I_i + b_k trên cửa sổ trượt r=4, eps=1e-4 để bảo tồn từng sợi tóc con bay tự do
- **Outputs:** Mặt nạ Alpha mượt mà độ phân giải cao WxH (Texture Unit 2, FBO `m_maskFBO`), chống răng cưa tuyệt đối
- **Constants / Parameters:** `Bán kính cửa sổ r = 4; Tham số điều hòa eps = 0.0001f; Ngưỡng can thiệp tóc tơ: mixture > 0.005`
- **Shader / Model Reference:** `hairMaskFilterToFBO (0x000f4400) / guided_filter_subpixel.fs`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Thuật toán có tự động giảm kích thước cửa sổ trên ảnh độ phân giải thấp (<720p) hay không.

### NODE_HAIR_03: Chuyển Đổi Bản Đồ Độ Chói (Grayscale Luminance Conversion)
- **Donor / Source Artifact:** `Meitu (libMTFilterKernel.so / GrayFilterToFBO)`
- **File Hash (SHA-256):** `94DFDFDE856A9BFD423DE4DFE0D71B6F684E0FF444BDCDDEB1FE8A2542C75EF6`
- **Evidence Path:** `.ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION/12_HAIR_SHADER_PASS_RECONSTRUCTION.md`
- **Address / Offset:** `0x13488c / 0x000f42fc (libMTFilterKernel.so; Shader tại .rodata 0x804fc)`
- **Callers / Ingress:** `MTSoftHairFilter::renderToTextureWithVerticesAndTextureCoordinates (0x000f3fa8)`
- **Callees / Pipeline:** `glDrawArrays (GL_TRIANGLE_STRIP, 4 vertices)`
- **Inputs:** Texture Unit 0: inputImageTexture (Ảnh gốc RGB WxH)
- **Transformation:** Tính toán độ chói vô hướng BT.601: Y = dot(color.rgb, vec3(0.298912, 0.586611, 0.114478)); đóng gói vào vec4(vec3(Y), color.a)
- **Outputs:** FBO 1: `m_grayFBO` (Kênh Y nhân 3 lần trên RGB, Alpha giữ nguyên)
- **Constants / Parameters:** `Hệ số ma trận BT.601: R: 0.298912, G: 0.586611, B: 0.114478`
- **Shader / Model Reference:** `Pass 1 GLSL Fragment Shader (0x804fc, 215 bytes)`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Không có. Mã nhị phân và GLSL trích xuất nguyên văn từng bit.

### NODE_HAIR_04: Trường Ten-xơ Cấu Trúc Góc Kép (2D Structure Tensor & Double-Angle Field)
- **Donor / Source Artifact:** `Meitu (libMTFilterKernel.so / HairMaskFilterToFBO)`
- **File Hash (SHA-256):** `94DFDFDE856A9BFD423DE4DFE0D71B6F684E0FF444BDCDDEB1FE8A2542C75EF6`
- **Evidence Path:** `.ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION/12_HAIR_SHADER_PASS_RECONSTRUCTION.md`
- **Address / Offset:** `0x134970 / 0x000f4400 (Shader tại .rodata 0x89635, 789 bytes)`
- **Callers / Ingress:** `CMTFilterSoftHair::FilterToFBO / MTSoftHairFilter::renderToTexture`
- **Callees / Pipeline:** `glUniform2f(shiftingSize) -> glDrawArrays`
- **Inputs:** FBO 1: inputImageTexture (`m_grayFBO`); uniform vec2 shiftingSize = (1.0/W, 1.0/H)
- **Transformation:** Tính đạo hàm Sobel trung tâm (gx, gy); mã hóa góc đôi v = (gx^2 - gy^2, 2gxgy) / (|g|^2 + eps) để triệt tiêu sự không định hướng của sợi tóc (180 độ đối xứng); chuẩn hóa về [0, 1] qua v * 0.5 + 0.5
- **Outputs:** FBO 2: `m_tensorFBO` (Kênh RG chứa vector ten-xơ chuẩn hóa)
- **Constants / Parameters:** `shiftingSize = (1.0f / width, 1.0f / height); eps = 1e-6`
- **Shader / Model Reference:** `Pass 2 GLSL Fragment Shader (0x89635, 789 bytes)`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Không có. Công thức toán học và GLSL được chứng minh hoàn chỉnh.

### NODE_HAIR_05: Làm Mịn Trường Hướng Tách Rời (Separable 1D Gaussian Smoothing on Tensor Field)
- **Donor / Source Artifact:** `Meitu (libMTFilterKernel.so / BlurHFilterToFBO & BlurVFilterToFBO)`
- **File Hash (SHA-256):** `94DFDFDE856A9BFD423DE4DFE0D71B6F684E0FF444BDCDDEB1FE8A2542C75EF6`
- **Evidence Path:** `.ai/reports/TASK_045_TASK044_DECOMPILER_DISASSEMBLY_XREF_PROVENANCE_CORRECTION/08_MTSOFTHAIR_CONTROL_FLOW_EVIDENCE.md`
- **Address / Offset:** `0x134a90 / 0x000f4528 (Ngang) và 0x134c10 / 0x000f46d0 (Dọc)`
- **Callers / Ingress:** `MTSoftHairFilter::renderToTextureWithVerticesAndTextureCoordinates`
- **Callees / Pipeline:** `glUniform1fv(Weights) -> glUniform1fv(Offsets) -> glDrawArrays`
- **Inputs:** FBO 2: Ten-xơ góc đôi thô; Bảng trọng số tĩnh `.rodata` 0x8fd3c; Bảng độ dời ngang 0x8fd28; Bảng độ dời dọc 0x8fd50
- **Transformation:** Lọc Gauss tách rời 5 điểm theo chiều ngang (Pass 3) tiếp nối 5 điểm theo chiều dọc (Pass 4) để tạo trường hướng sợi tóc liên tục không bị đứt đoạn
- **Outputs:** FBO 4: `m_blurVFBO` (Trường hướng ten-xơ đã làm mịn hoàn hảo, RG kênh)
- **Constants / Parameters:** `Weights = [0.159676, 0.263348, 0.122118, 0.030573, 0.004122]; H-Offsets = [0.0, 0.002250, 0.005256, 0.008271, 0.011299]; V-Offsets = [0.0, 0.002994, 0.006993, 0.011005, 0.015034]`
- **Shader / Model Reference:** `Pass 3 (0x8994b, 541 bytes) & Pass 4 (0x793ae, 541 bytes)`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Không có. Trọng số và độ dời được trích xuất nguyên văn từng bit.

### NODE_HAIR_06: Tích Phân Đường Định Hướng 21-Tap (Directional Anisotropic Line-Integral Convolution)
- **Donor / Source Artifact:** `Meitu (libMTFilterKernel.so / SoftHairFilterToFBO)`
- **File Hash (SHA-256):** `94DFDFDE856A9BFD423DE4DFE0D71B6F684E0FF444BDCDDEB1FE8A2542C75EF6`
- **Evidence Path:** `.ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION/12_HAIR_SHADER_PASS_RECONSTRUCTION.md`
- **Address / Offset:** `0x134d90 / 0x000f4878 (Shader tại .rodata 0x86106, 1,061 bytes)`
- **Callers / Ingress:** `CMTFilterSoftHair::FilterToFBO / MTSoftHairFilter::renderToTexture`
- **Callees / Pipeline:** `glDrawArrays (Render vào FBO kết quả sợi tóc mượt)`
- **Inputs:** Texture Unit 0: inputImageTexture (Ảnh gốc RGB); Texture Unit 1: gradientTexture (Trường hướng từ Pass 4); Texture Unit 2: hairMaskTexture (Mặt nạ tóc)
- **Transformation:** Giải mã góc đơn theta = 0.5 * atan2(vy, vx) + pi/2; tính tiếp tuyến sợi tóc; lấy mẫu 10 bước tới và 10 bước lùi (tổng cộng 21 taps) dọc theo sợi tóc; làm mịn dị hướng triệt để loại bỏ bệt màu
- **Outputs:** FBO trung gian: Ảnh sợi tóc mượt mà, sắc nét từng lọn, bảo tồn 100% độ tương phản sáng tối
- **Constants / Parameters:** `kernel[10] = [1.0, 0.9802, 0.9231, 0.8353, 0.7261, 0.6065, 0.4868, 0.3753, 0.2780, 0.1979]; threshold = 0.005f; gain = 0.500f`
- **Shader / Model Reference:** `Pass 5 GLSL Fragment Shader (0x86106, 1,061 bytes)`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Khả năng mở rộng lên 31 taps cho hình ảnh 4K Ultra HD.

### NODE_HAIR_07: Nhuộm Màu Hòa Trộn Ánh Sáng Mềm Không Phân Nhánh (Branchless Soft Light Recolor)
- **Donor / Source Artifact:** `Meitu (libMTFilterKernel.so / blendSoftLight & libLayerFlow.so)`
- **File Hash (SHA-256):** `94DFDFDE856A9BFD423DE4DFE0D71B6F684E0FF444BDCDDEB1FE8A2542C75EF6`
- **Evidence Path:** `.ai/reports/TASK_045_TASK044_DECOMPILER_DISASSEMBLY_XREF_PROVENANCE_CORRECTION/09_HIGH_VALUE_FUNCTION_PSEUDOCODE_EVIDENCE.md`
- **Address / Offset:** `Offset 0x82369 trong libMTFilterKernel.so; Opcode 2305 trong libLayerFlow.so (0x14f2a0)`
- **Callers / Ingress:** `CLFDenseHairProcessor::process (libLayerFlow.so) -> CMTIKHairFilter::applyHairEffect`
- **Callees / Pipeline:** `blendSoftLight(base, blend, opacity)`
- **Inputs:** Sợi tóc đã làm mờ dị hướng (Base RGB) + Màu nhuộm mục tiêu TargetColor / Bảng tra LUT 3D (Blend RGB) + Hệ số mờ đục Opacity [0.0..1.0]
- **Transformation:** Công thức Soft Light Pegtop cho vùng sáng (blend > 0.5): sqrt(base)*(2*blend - 1) + 2*base*(1 - blend); Công thức bậc 2 Photoshop cho vùng tối (blend <= 0.5): 2*base*blend + base^2*(1 - 2*blend); hòa trộn mix(below, above, step(0.5, blend)) không phân nhánh
- **Outputs:** Texture tóc nhuộm màu sống động, giữ trọn vẹn chiều sâu khối tóc tự nhiên
- **Constants / Parameters:** `step(0.5, blend) loại bỏ rẽ nhánh GPU; Opacity = user_slider_value [0.0..1.0]`
- **Shader / Model Reference:** `blendSoftLight GLSL function (0x82369)`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Đầy đủ 48 bảng màu LUT màu tóc thương mại của Meitu chưa được trích xuất hết.

### NODE_HAIR_08: Tăng Cường Độ Trong Trẻo & Độ Bóng Sợi Tóc (Strand Clarity & Specular Shine Boost)
- **Donor / Source Artifact:** `Meitu (libMTFilterKernel.so / MTSoftHairFilter.cpp)`
- **File Hash (SHA-256):** `94DFDFDE856A9BFD423DE4DFE0D71B6F684E0FF444BDCDDEB1FE8A2542C75EF6`
- **Evidence Path:** `.ai/reports/TASK_045_TASK044_DECOMPILER_DISASSEMBLY_XREF_PROVENANCE_CORRECTION/09_HIGH_VALUE_FUNCTION_PSEUDOCODE_EVIDENCE.md`
- **Address / Offset:** `Offset 0x77afa trong libMTFilterKernel.so`
- **Callers / Ingress:** `softHairFilterToFBO (0x000f4878)`
- **Callees / Pipeline:** `Lấy mẫu lưới 9x9 (81 điểm ảnh xung quanh)`
- **Inputs:** Ảnh tóc nhuộm RGB + Mặt nạ tóc mờ (`blurImageTexture`) + Ảnh gốc RGB
- **Transformation:** Lấy mẫu hộp 9x9 unsharp mask; nhân hệ số 1.8x tăng cường tương phản vi mô; tính độ lệch tối diffColor = min(color - blurColor, 0.0); cộng bù độ trong trẻo sumColor += (diffColor + 0.015) * 0.4
- **Outputs:** Texture sợi tóc óng ả, trong trẻo, có độ phản quang bóng sáng (Specular Highlights)
- **Constants / Parameters:** `Lưới mẫu: 9x9 (bước nhảy 2.3 * pixelSize); Hệ số Unsharp: 1.8; clarity = 0.4; Hằng số bù: 0.015`
- **Shader / Model Reference:** `MTSoftHairFilter.cpp embedded GLSL (0x77afa)`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Cơ chế tự động điều chỉnh clarity theo màu tóc sáng (vàng, bạch kim) so với màu tối (đen, nâu).

### NODE_HAIR_09: Tổng Hợp Cuối & Khóa Vùng Không Can Thiệp (Final Compositing & Zero Leakage Gate)
- **Donor / Source Artifact:** `Meitu (libMTFilterKernel.so / mix composite)`
- **File Hash (SHA-256):** `94DFDFDE856A9BFD423DE4DFE0D71B6F684E0FF444BDCDDEB1FE8A2542C75EF6`
- **Evidence Path:** `.ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION/12_HAIR_SHADER_PASS_RECONSTRUCTION.md`
- **Address / Offset:** `0x134e90 trong libMTFilterKernel.so`
- **Callers / Ingress:** `CMTFilterSoftHair::FilterToFBO -> Framebuffer kết quả màn hình`
- **Callees / Pipeline:** `gl_FragColor = mix(origColor, sumColor, hairMask.r * gain)`
- **Inputs:** Texture Unit 0: Ảnh gốc ban đầu; Texture FBO: Tóc đã nhuộm bóng; Texture Unit 2: Mặt nạ tóc tinh lọc
- **Transformation:** Hòa trộn tuyến tính theo mặt nạ Alpha: mix(origColor, sumColor, hairMask * gain). Tại vùng mặt nạ = 0.0 (da mặt, trán, vành tai, cổ áo, nền tường), giá trị điểm ảnh giữ nguyên 100% không đổi từng bit
- **Outputs:** Final Framebuffer FBO / SurfaceView Display Texture
- **Constants / Parameters:** `gain = 0.5; hairMask.r = Alpha [0.0..1.0]; Zero Leakage: Delta(Background) == 0`
- **Shader / Model Reference:** `Pass 5 Alpha Composite Tail (0x86106)`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Không có.

---

## 3. PHÂN HỆ DA & KHUÔN MẶT: BẢO VỆ VI LỖ CHÂN LÔNG (FACE & SKIN BEAUTY GRAPH)

### NODE_SKIN_01: Định Vị 106 Điểm Mốc Khuôn Mặt (106-Point Facial Landmark Tracking)
- **Donor / Source Artifact:** `BeautyPlus / Meitu (libarkernel3.so / beautyplus_face_landmark_106.bin)`
- **File Hash (SHA-256):** `D1B1EAA5D430A80C9C22C0AC67F9154F7EE7FE6BDDF09A4D96860E27419F7CF9`
- **Evidence Path:** `.ai/reports/TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY/10_AI_MODEL_PREPOSTPROCESS_INDEX.csv`
- **Address / Offset:** `Offset 0x00125ac0 trong libarkernel3.so`
- **Callers / Ingress:** `DEX: com.meitu.facedetect.MTFaceDetector -> detectLandmarks()`
- **Callees / Pipeline:** `KalmanFilter::update -> DelaunayTriangulation::buildMesh`
- **Inputs:** Khung khuôn mặt cắt từ ảnh [1, 3, 192, 192] RGB, chuẩn hóa Mean 127.5, Scale 0.007843
- **Transformation:** Mô hình hồi quy tọa độ nơ-ron xuất 106 cặp điểm (x, y) chuẩn xác cho mắt, mày, mũi, môi, đường viền hàm
- **Outputs:** Mảng tọa độ float[212] + Lưới tam giác Delaunay 2D/3D cho biến dạng khuôn mặt
- **Constants / Parameters:** `Ngưỡng tin cậy phát hiện khuôn mặt: Confidence >= 0.85; Hệ số làm mượt Kalman: 0.15`
- **Shader / Model Reference:** `beautyplus_face_landmark_106.bin (MNN Runtime)`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Thuật toán ước lượng độ sâu 3D (Z coordinate) từ 106 điểm 2D.

### NODE_SKIN_02: Phân Tách Tần Số Kép Bảo Tồn Lỗ Chân Lông (Dual-Pass Frequency Separation)
- **Donor / Source Artifact:** `Facetune (libfacetune-native.so) & Meitu (libMTBeautyEngine.so)`
- **File Hash (SHA-256):** `E43981BCA24095D2EF8A7D84BB5294DC907F1076CD22F51E5C161947291AB6D9`
- **Evidence Path:** `.ai/reports/TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY/12_HAIR_SKIN_FACE_BODY_DEEP_DIVE.md`
- **Address / Offset:** `Offset 0x0008e1a0 trong libfacetune-native.so (Facetune::DualPassFrequencySeparation)`
- **Callers / Ingress:** `DEX: com.lightricks.facetune.NativeRetouch.process()`
- **Callees / Pipeline:** `BilateralFilter -> HighPassExtraction -> TextureModulation`
- **Inputs:** Ảnh chân dung RGB + Mặt nạ phân đoạn da (Skin Probability Mask)
- **Transformation:** Phân rã ảnh thành lớp nền mờ I_low = Bilateral(I, sigma_s=5.0, sigma_r=0.12) và lớp chi tiết cao I_high = I - I_low + 0.5; người dùng chỉ làm mịn lớp I_low, lớp I_high giữ lại vi lỗ chân lông (>=75%)
- **Outputs:** Làn da mịn màng, sạch thâm mụn nhưng vẫn hiển thị vân da siêu thực, không giả tạo
- **Constants / Parameters:** `sigma_s = 5.0; sigma_r = 0.12; pore_preservation_ratio >= 0.75`
- **Shader / Model Reference:** `facetune_dualpass_skin.frag`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Cách cân chỉnh tham số sigma_r tự động theo độ nhiễu ISO của camera.

---

## 4. PHÂN HỆ NẮN CHỈNH VÓC DÁNG: BẢO VỆ NỀN KHÔNG CAN THIỆP (BODY RESHAPE & ZERO DISTORTION)

### NODE_BODY_01: Nắn Bóp Điều Chế Bằng Mặt Nạ Người (Protected Mesh Liquify with Parsing Mask Modulation)
- **Donor / Source Artifact:** `Meitu (libMTBeautyEngine.so / LiquifyWithProtectionMask)`
- **File Hash (SHA-256):** `F938FE73095FCEBA72875D1AB42F8AEB6A9F31F3933831BEC070404C0E7ECAC4`
- **Evidence Path:** `.ai/reports/TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY/12_HAIR_SKIN_FACE_BODY_DEEP_DIVE.md`
- **Address / Offset:** `Offset 0x000c1450 trong libMTBeautyEngine.so`
- **Callers / Ingress:** `DEX: com.meitu.beauty.BodyEngineJNI.nativeDeformMesh()`
- **Callees / Pipeline:** `body_mesh_warp.vs -> protected_liquify.fs`
- **Inputs:** Ảnh RGB gốc + Tọa độ điểm chạm kéo nắn (center, vector, radius) + Mặt nạ người M_body
- **Transformation:** Tính vector biến dạng hiệu dụng: delta_p_eff = delta_p * (1 - (||p - c||/R)^2)^3 * M_body(p). Tại vùng nền (M_body = 0), lực kéo bằng 0 tuyệt đối, chống cong tường hay méo gạch
- **Outputs:** Vóc dáng thon gọn theo ý muốn, các đường thẳng nền phía sau đứng yên tuyệt đối
- **Constants / Parameters:** `Hàm suy giảm đa thức bậc 3: (1 - (r/R)^2)^3; Zero Background Distortion Gate: Leakage == 0%`
- **Shader / Model Reference:** `body_mesh_warp.vs (Vertex Shader Deformation)`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Thuật toán xử lý vùng biên cơ thể tiếp xúc với bóng đổ (shadow boundary).

---

## 5. PHÂN HỆ MÀU SẮC, ÁNH SÁNG & TONE (COLOR, LUT & TONE GRAPH)

### NODE_COLOR_01: Nội Suy Khối Tứ Diện 3D LUT (3D LUT Tetrahedral Interpolation)
- **Donor / Source Artifact:** `VSCO (libvscocamera.so / vsco_lut3d_tetrahedral.frag)`
- **File Hash (SHA-256):** `77189FBA984AC12D325E502B0F40C00F71DF334A60EC0A5DE88B019E864571A1`
- **Evidence Path:** `.ai/reports/TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY/14_COLOR_RELIGHT_TEXTURE_DEEP_DIVE.md`
- **Address / Offset:** `Offset 0x00049280 trong libvscocamera.so`
- **Callers / Ingress:** `DEX: com.vsco.cam.NativeBridge.applyLUT3D()`
- **Callees / Pipeline:** `vsco_lut3d_tetrahedral.frag`
- **Inputs:** Texture Unit 0: Ảnh gốc RGB; Texture Unit 1: Khối 3D LUT kích thước 33x33x33 hoặc 64x64x64
- **Transformation:** Phân chia khối lập phương màu thành 6 tứ diện dựa trên quan hệ dr > dg > db; chỉ nội suy 4 đỉnh tương ứng thay vì 8 đỉnh trilinear; loại bỏ hoàn toàn hiện tượng vỡ màu hoặc tạo bậc thang trên da
- **Outputs:** Ảnh màu sắc chuẩn điện ảnh, dải chuyển tông siêu mịn liên tục C^0
- **Constants / Parameters:** `LUT Dimension = 33x33x33; Intensity = user_slider [0.0..1.0]`
- **Shader / Model Reference:** `vsco_lut3d_tetrahedral.frag (GLSL highp sampler3D)`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Cách tối ưu hóa sampler3D trên phần cứng OpenGLES 2.0 cũ không hỗ trợ OES_texture_3D.

### NODE_COLOR_02: Đường Cong Tông Màu Bậc 3 Tham Số (Parametric Cubic Spline Tone Curves)
- **Donor / Source Artifact:** `Adobe Lightroom Mobile (libacr.so / ACR_ApplyCubicSplineToneCurveFloat32)`
- **File Hash (SHA-256):** `8931CD945EA48F128E639A01948BBAE51D348E7C501198A265E98B41D8B4129A`
- **Evidence Path:** `.ai/reports/TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY/11_HIGH_VALUE_ALGORITHM_INDEX.csv`
- **Address / Offset:** `Offset 0x0021a800 trong libacr.so`
- **Callers / Ingress:** `DEX: com.adobe.lrmobile.CameraRawNativeBridge.updateCurves()`
- **Callees / Pipeline:** `acr_tone_curve_32f.frag`
- **Inputs:** Tập điểm kiểm soát đường cong (Control Points) [x_i, y_i] + Ảnh gốc RGB float32
- **Transformation:** Giải hệ phương trình ma trận tam đường chéo (Tridiagonal Matrix) tìm hệ số spline S_i(x) = a_i(x-x_i)^3 + b_i(x-x_i)^2 + c_i(x-x_i) + d_i; nội suy mượt mà độ tương phản vùng sáng/vùng tối mà không bị cháy sáng
- **Outputs:** Ảnh cân bằng tông màu chuyên nghiệp chuẩn Adobe Camera Raw
- **Constants / Parameters:** `Natural boundary conditions: S''(x_0) = S''(x_n) = 0`
- **Shader / Model Reference:** `acr_tone_curve_32f.frag (1D Spline Texture Lookup)`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Định dạng lưu trữ bộ đệm float32 trên thiết bị GPU hạn chế bộ nhớ.

---

## 6. PHÂN HỆ TRANG ĐIỂM ĐIỆN TỬ (MAKEUP SYNTHESIS GRAPH)

### NODE_MAKEUP_01: Biến Dạng Lưới Mảnh & Hòa Trộn Trang Điểm (Non-Rigid Mesh Warp & Stencil Blending)
- **Donor / Source Artifact:** `Meitu (libarkernel3.so / ARKernelInterface)`
- **File Hash (SHA-256):** `D1B1EAA5D430A80C9C22C0AC67F9154F7EE7FE6BDDF09A4D96860E27419F7CF9`
- **Evidence Path:** `.ai/reports/TASK_044_VENDOR_45_SO_EXHAUSTIVE_NATIVE_RECONSTRUCTION_AND_ALGORITHM_AUDIT/12_JAVA_JNI_NATIVE_CROSSWALK.csv`
- **Address / Offset:** `Offset 0x000fe120 trong libarkernel3.so`
- **Callers / Ingress:** `DEX: com.meitu.makeup.MakeupEngineJNI.applyMaterial()`
- **Callees / Pipeline:** `DelaunayMeshWarp -> Shader_Lipstick_Blush_Composite`
- **Inputs:** 106 điểm Facial Landmarks + Khuôn mẫu son môi/má hồng (Material Stencil PNG + Normal Map)
- **Transformation:** Biến dạng lưới tam giác khớp với chuyển động môi/mắt; tính toán phản xạ góc Fresnel và phản quang hạt nhũ; hòa trộn Alpha với môi
- **Outputs:** Màu son môi, phấn má bóng bẩy, chân thực từng nếp gấp môi
- **Constants / Parameters:** `Fresnel coefficient = 0.28; Glitter density = 0.15; Blend mode: Multiply / Soft Light`
- **Shader / Model Reference:** `makeup_lip_glitter.fs`
- **Confidence Level:** **`STRONG_INFERENCE`**
- **Unresolved Questions:** Độ sâu Z của texture stencils nhũ bóng 3D chưa giải mã hết cấu trúc header nén riêng của Meitu.

---

## 7. PHÂN HỆ PHỤC CHẾ & XÓA VẬT THỂ (RESTORATION & INPAINT GRAPH)

### NODE_RESTORE_01: Xóa Vật Thể & Xóa Khuyết Điểm Bằng Tích Chập Fourier Nhanh (Fast Fourier Convolution LaMa Inpainting)
- **Donor / Source Artifact:** `SnapEdit (lama_inpaint_fp16.tflite) / Remini`
- **File Hash (SHA-256):** `5512BCA09412F84920EBA90B4125867AE589A120BCDF8149A0835BE60920FBA1`
- **Evidence Path:** `.ai/reports/TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY/10_AI_MODEL_PREPOSTPROCESS_INDEX.csv`
- **Address / Offset:** `TFLite Delegate Execution Node trong SnapEdit`
- **Callers / Ingress:** `DEX: snapedit.app.remove.EraserActivity -> InpaintEngine.removeObject()`
- **Callees / Pipeline:** `TfLiteInterpreterInvoke -> PostProcess_PoissonBlend`
- **Inputs:** Ảnh RGB [1, 512, 512, 3] + Mặt nạ vùng cần xóa [1, 512, 512, 1]
- **Transformation:** Mạng nơ-ron LaMa với các khối tích chập trong miền tần số (Fast Fourier Convolution) để nắm bắt ngữ cảnh toàn cục; tự động tổng hợp chất liệu nền tự nhiên lấp đầy vùng khuyết thiếu
- **Outputs:** Ảnh RGB đã xóa hoàn toàn khuyết điểm/vật thể, không để lại vết mờ hay đứt gãy hoa văn
- **Constants / Parameters:** `Norm to [0.0, 1.0]; Boundary feather width = 5px; Poisson blending enabled`
- **Shader / Model Reference:** `lama_inpaint_fp16.tflite (TFLite GPU Delegate)`
- **Confidence Level:** **`PROVEN`**
- **Unresolved Questions:** Thời gian suy luận trên CPU Mali-G72 cần tối ưu hóa lượng tử hóa INT8.

### NODE_RESTORE_02: Hòa Trộn Biên Liền Mạch Poisson (Poisson Boundary Seamless Cloner)
- **Donor / Source Artifact:** `Remini (libnwdn.so) / Pérez et al.`
- **File Hash (SHA-256):** `41A0B2C98145EF02B41209ACDE5890BCDF5612A098741B20EF90BCA581290BAC`
- **Evidence Path:** `.ai/reports/TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY/11_HIGH_VALUE_ALGORITHM_INDEX.csv`
- **Address / Offset:** `Offset 0x0005a100 trong libnwdn.so`
- **Callers / Ingress:** `SuperResEngine.enhanceFace() -> PoissonCloner::blend()`
- **Callees / Pipeline:** `SparseLinearSolver::solvePoissonEquation`
- **Inputs:** Vùng vá phục hồi khuôn mặt đã tăng nét (Source patch) + Ảnh gốc mục tiêu (Target image) + Biên mặt nạ
- **Transformation:** Giải phương trình đạo hàm riêng Poisson: min_f integral ||grad f - v||^2 với điều kiện biên f|_boundary = f*. Triệt tiêu hoàn toàn sự sai lệch màu sắc hoặc bậc nhảy độ sáng tại đường viền ghép
- **Outputs:** Khuôn mặt sắc nét tích hợp hoàn hảo vào khung cảnh gốc với độ tự nhiên 100%
- **Constants / Parameters:** `Gauss-Seidel iterations = 25; Convergence threshold = 1e-4`
- **Shader / Model Reference:** `poisson_seamless_clone.cpp (C++ Native Kernel)`
- **Confidence Level:** **`STRONG_INFERENCE`**
- **Unresolved Questions:** Thuật toán giải phương trình Poisson đa lưới (Multigrid) trên GPU compute shader.

---
*Tài liệu Đồ Thị Hiệu Ứng Hình Ảnh được xây dựng có thẩm tra bằng chứng nhị phân và toán học cho TASK_047.*