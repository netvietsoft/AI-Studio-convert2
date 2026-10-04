# TASK_048 — MASTER IMAGE EFFECT GRAPH SPECIFICATION
**Authority:** Chủ tịch Tony  
**Task ID:** TASK_048_MULTI_AGENT_IMAGE_EFFECT_GRAPH_EVIDENCE_EXPANSION_ACTIVE  
**Standard:** Development Workspace Standard V2.1 + Hiến pháp Vận hành CONVERT  
**Scope:** Toàn bộ 6 phân hệ xử lý ảnh: Tóc, Da mặt, Vóc dáng, Màu sắc/LUT, Trang điểm, Xóa vật thể.  

---

## 1. NGUYÊN TẮC THIẾT KẾ ĐỒ THỊ HIỆU ỨNG (GRAPH DESIGN PRINCIPLES)
Mỗi hiệu ứng trong đồ thị phải tuân thủ chuẩn liên kết 8 tầng khép kín:
```
[Tầng 1: UI / Action Event]
       │
       ▼
[Tầng 2: DEX Class & ViewModel]
       │
       ▼
[Tầng 3: JNI Interface & RegisterNatives Binding]
       │
       ▼
[Tầng 4: Native C++ Engine Entry Point]
       │
       ▼
[Tầng 5: Internal Caller / Callee Subgraph]
       │
       ▼
[Tầng 6: AI Model / Shader / Render Pass Execution]
       │
       ▼
[Tầng 7: Intermediate FBO Textures & Mathematical Blending]
       │
       ▼
[Tầng 8: Final Compositing & Visible Pixel Transformation]
```

---

## 2. MA TRẬN 6 PHÂN HỆ ĐỒ THỊ HIỆU ỨNG CHÍNH

### PHÂN HỆ 1: CHUỖI NHUỘM VÀ XỬ LÝ TÓC (HAIR DYE & MATTING PIPELINE)
- **UI Trigger:** `HairViewModel.requestHairColorAigcEffect()`, `DENSE_HAIR_OPT_TYPE_HAIR_DYE = 2305`
- **DEX Layer:** `com.layer.flow.datas.LFEffectDenseHairData$DenseHairInfo`, `com.meitu.mtimagekit.filters.specialFilters.hairFilter.MTIKHairFilter`
- **JNI Binding:** `LayerFlowNS::LFEffectDenseHairDataJNI::nSetAlpha`, `nSetMaterialId`
- **Native Entry:** `LayerFlowNS::CLFDenseHairLayer::updateBy(CLFMaterial const&)`
- **Render Pass Subgraph:**
  1. `mtface_parsing.bin` -> Class 17 Hair Mask Tensor `[1, 512, 512, 1]`
  2. `MTSoftHairFilter::hairMaskFilterToFBO` -> Feathered Hair Alpha FBO
  3. `MTSoftHairFilter::grayFilterToFBO` -> Luminance FBO (ITU-R BT.601)
  4. `MTSoftHairFilter::blurHFilterToFBO` & `blurVFilterToFBO` -> Double-Angle Orientation Vector `(cos 2theta, sin 2theta)`
  5. `MTSoftHairFilter::softHairFilterToFBO` -> 21-tap Line Integral Convolution along tangent vector
  6. Recolor Pass -> SoftLight Pegtop blend: `f(a,b) = (1 - 2b)*a^2 + 2b*a`
  7. Shine/Clarity Pass -> 9x9 Unsharp Mask (Clarity 0.4, Gain 1.8)
  8. Alpha Composite -> Khóa 100% vùng không can thiệp: `mix(originalRGB, dyedRGB, hairMaskAlpha)`
- **Visible Pixel Effect:** Tóc đổi màu tự nhiên, giữ nguyên độ bóng lọn tóc, không lem vào trán/tai/nền.

### PHÂN HỆ 2: CHUỖI LÀM ĐẸP DA & KHUÔN MẶT (FACE & SKIN BEAUTY PIPELINE)
- **UI Trigger:** `BeautySetting.SKIN_SMOOTH_LEVEL`, `SKIN_WHITEN_LEVEL`
- **DEX Layer:** `com.meitu.meitupic.modularembellish.SkinViewModel`, `LFDermabrasionModular`
- **JNI Binding:** `LayerFlowNS::LFEffectDermabrasionDataJNI::nSetDermabrasionAlpha`
- **Native Entry:** `MTBeautyEngine::BilateralFilter::ProcessPores` trong `libMTBeautyEngine.so`
- **Render Pass Subgraph:**
  1. Tách tần số kép (Dual-Frequency Separation): Bộ lọc Bilateral tách ảnh thành Low-Frequency (màu sắc/khối) và High-Frequency (vi cấu trúc lỗ chân lông).
  2. Làm mượt có hướng trên Low-Frequency: Xóa mụn, vết thâm, làm đều màu da.
  3. Bảo tồn vi cấu trúc High-Frequency: Giữ lại >= 75% cấu trúc lỗ chân lông, không làm bệt da như sơn.
  4. Làm sáng da thích nghi (Skin Tone Curve): Nâng sáng theo vùng da người được khoanh vùng bởi `tt_skin_seg_v5.0.model` hoặc `mtface_parsing.bin`.
- **Visible Pixel Effect:** Da mịn màng, sáng khỏe, giữ nguyên chân thực từng sợi lông tơ và lỗ chân lông.

### PHÂN HỆ 3: CHUỖI NẮN BÓP VÓC DÁNG KHÓA NỀN (BODY LIQUIFY & BACKGROUND PROTECTION)
- **UI Trigger:** `BodyShapeViewModel.applySlim()`, `LFBodyShapeModular`
- **DEX Layer:** `com.layer.flow.datas.LFEffectBodyShapeData`
- **JNI Binding:** `LayerFlowNS::LFEffectBodyShapeDataJNI::nSetBodySlimLevel`
- **Native Entry:** `MTBeautyEngine::BodyReshape::ApplyDeformation`
- **Render Pass Subgraph:**
  1. Human Pose & Silhouette Parsing: Mô hình `tt_pose_detection_v3.0.model` và `M_SenseME_Segment_Figure_p_4.14.1.1.model` xác định khung xương và mặt nạ cơ thể.
  2. Mesh Warping có điều biến: Tạo lưới biến dạng (Deformation Grid), chỉ dịch chuyển đỉnh lưới nằm trong mặt nạ người.
  3. Radial Falloff Function: Bán kính suy giảm `w(r) = (1 - (r/R)^2)^3` giảm dần về 0 tại biên giới người và nền.
  4. Khóa nền tuyệt đối (Zero Background Distortion): Vùng ngoài mặt nạ cơ thể giữ tọa độ UV gốc `(u, v) = (u, v)`.
- **Visible Pixel Effect:** Thon gọn eo, chân dài, vai thon; các đường chỉ gạch, tường, cửa sổ phía sau thẳng tắp 100%.

### PHÂN HỆ 4: CHUỖI MÀU SẮC, 3D LUT & TONE CURVE (COLOR GRADING & FILM EMULATION)
- **UI Trigger:** `FilterViewModel.selectFilter()`, `LFFilterModular`
- **DEX Layer:** `com.meitu.mtimagekit.filters.specialFilters.MTIKLutFilter`
- **JNI Binding:** `PVGColorFunctions::apply3DLUT` trong `libPVGColorFunctions.so`
- **Native Entry:** `ColorLUT::SampleTetrahedral` (tương đương chuẩn VSCO `vsco_lut3d_tetrahedral.frag`)
- **Render Pass Subgraph:**
  1. Không gian màu đầu vào: Chuyển đổi từ sRGB sang Display-P3 hoặc Linear RGB qua `libPVGColorFunctions.so`.
  2. Nội suy tứ diện 3D LUT (Tetrahedral Interpolation): Lấy mẫu thể tích màu chia 6 khối tứ diện đơn hình (simplices), loại bỏ hiện tượng giật màu (color banding) của nội suy trilinear.
  3. Hiệu chỉnh đường cong Spline bậc 3: Điều chỉnh Shadows, Midtones, Highlights không cắt xén dải động.
- **Visible Pixel Effect:** Tông màu điện ảnh sâu thẳm, chuyển tiếp dải màu mượt mà, không nhiễu hạt sắc độ.

### PHÂN HỆ 5: CHUỖI TRANG ĐIỂM BIẾN DẠNG LƯỚI 106 ĐIỂM (MAKEUP SYNTHESIS PIPELINE)
- **UI Trigger:** `MakeupViewModel.selectLipstick()`, `LFMakeUpModular`
- **DEX Layer:** `com.layer.flow.datas.LFEffectMakeupData`
- **JNI Binding:** `ARKernelInterface::setMakeupFeature` trong `libARKernelInterface.so`
- **Native Entry:** `ARKernel::RenderMeshWarp`
- **Render Pass Subgraph:**
  1. Trích xuất Landmark 106 điểm từ `Lanmark.bin` (BeautyPlus/Meitu).
  2. Tạo lưới tam giác Delaunay bám sát đường viền môi, mí mắt, gò má.
  3. Biến dạng UV texture của mẫu son/phấn theo chuyển động cơ mặt.
  4. Hòa trộn Multiply hoặc SoftLight kết hợp phản xạ Specular Highlight để giữ độ bóng của môi.
- **Visible Pixel Effect:** Màu son, phấn mắt tự nhiên, bám chặt theo cơ mặt, có độ bóng ẩm thực tế.

### PHÂN HỆ 6: CHUỖI XÓA VẬT THỂ & PHỤC HỒI (OBJECT REMOVAL & INPAINTING)
- **UI Trigger:** `EraserViewModel.eraseObject()`, `LFAutoRemoveModular`
- **DEX Layer:** `com.layer.flow.datas.LFEffectAutoRemoveData`
- **JNI Binding:** `LayerFlowNS::LFEffectAutoRemoveDataJNI::nProcessInpaint`
- **Native Entry:** `SnapEdit / Meitu Inpaint Pipeline`
- **Render Pass Subgraph:**
  1. Tạo mặt nạ vùng cần xóa từ thao tác cọ vẽ của người dùng.
  2. Mở rộng biên mặt nạ (Morphological Dilation) 5-8 pixel để bao phủ toàn bộ bóng đổ.
  3. Khối suy luận Inpainting (Fast Fourier Convolutions trên Cloud API hoặc Mobile TFLite).
  4. Hòa trộn biên Poisson (Poisson Seamless Blending): Giải hệ phương trình Poisson gradient để triệt tiêu vệt cắt ghép tại viền.
- **Visible Pixel Effect:** Vật thể biến mất hoàn toàn, kết cấu nền (cỏ, gỗ, gạch) được tái tạo tự nhiên, không lộ vết xóa.
