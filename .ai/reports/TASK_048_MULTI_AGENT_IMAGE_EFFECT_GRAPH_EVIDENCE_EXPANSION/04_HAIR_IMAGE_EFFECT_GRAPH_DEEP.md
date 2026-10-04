# TASK_048 — HAIR IMAGE EFFECT GRAPH DEEP RECONSTRUCTION
**Authority:** Chủ tịch Tony  
**Task ID:** TASK_048_MULTI_AGENT_IMAGE_EFFECT_GRAPH_EVIDENCE_EXPANSION_ACTIVE  
**Predecessor Finding:** TASK_047 (Audit Verdict: NEEDS_FIX)  
**Execution Lane:** LANE A (Worker Identity: `WORKER-LANE-A-HAIR-GRAPH`)  
**Scope:** Khảo sát chi tiết 8 giai đoạn của chuỗi xử lý tóc từ UI Action tới từng Pixel.  
**Hard Gate:** HAIR V4 IMPLEMENTATION = BLOCKED (Zero production code changes to Hair V2/V3).  

---

## 1. TỔNG QUAN CHUỖI HIỆU ỨNG TÓC P0/P1
Chuỗi xử lý tóc của Meitu được thiết kế theo cấu trúc luồng FBO nối tiếp (Multi-Pass Ping-Pong Framebuffer Architecture), được điều phối từ tầng Java thông qua `MTIKHairFilter` và `LayerFlowNS::CLFDenseHairLayer`.

```
[UI: DENSE_HAIR_OPT_TYPE_HAIR_DYE = 2305 & MaterialData.lutPath]
                               │
                               ▼
     [Giai đoạn 1: Segmentation Mask (mtface_parsing.bin)]
                               │
                               ▼
    [Giai đoạn 2: Alpha Matting (hairMaskFilterToFBO)]
                               │
                               ▼
  [Giai đoạn 3: Luminance Extraction (grayFilterToFBO)]
                               │
                               ▼
 [Giai đoạn 4: Orientation Field (blurH/VFilterToFBO)]
                               │
                               ▼
 [Giai đoạn 5: 21-tap LIC Tangent Filter (softHairFilterToFBO)]
                               │
                               ▼
    [Giai đoạn 6: Color Recolor / Blend (Pegtop SoftLight)]
                               │
                               ▼
  [Giai đoạn 7: Shine & Clarity (9x9 Unsharp Mask, Clarity 0.4)]
                               │
                               ▼
[Giai đoạn 8: Final Alpha Compositing & Protected Isolation]
```

---

## 2. CHI TIẾT KỸ THUẬT 8 GIAI ĐOẠN

### GIAI ĐOẠN 1: MASK / SEMANTIC SEGMENTATION
- **Input:** Ảnh chân dung đầu vào RGB `[1, 512, 512, 3]`.
- **Thực thi:** Mô hình `mtface_parsing.bin` (kích thước 584,286 bytes, SHA256: `b5c17a63430e4b678b87d559811c7fae93f77ea53e34b9cfcf45baeb851df92e`) chạy qua bộ khung suy luận `libManis.so` (Build-ID `74c6f0b4d5ddcf4c758019c104a85b14038839b6`).
- **Output:** Tensor xác suất 19 lớp `[1, 512, 512, 19]`. Kênh số 17 là mặt nạ tóc nhị phân thô (Raw Binary Hair Mask).
- **Tác động pixel:** Phân tách ranh giới tóc sơ bộ; còn hiện tượng bậc thang (aliasing) tại đường chân tóc và lọn tóc mảnh.

### GIAI ĐOẠN 2: ALPHA MATTING & HAIRLINE FEATHERING
- **Input:** Mặt nạ tóc thô kênh 17 và Texture ảnh gốc.
- **Thực thi:** Hàm C++ `_ZN14MTFilterKernel16MTSoftHairFilter19hairMaskFilterToFBOEPKfS2_PNS_19GPUImageFramebufferES4_` trong `libMTFilterKernel.so`.
- **Thuật toán:** Bộ lọc làm mềm có hướng dẫn (Guided Filter) bán kính $r=4$, tham số điều hòa $\epsilon = 10^{-4}$.
- **Output:** Texture FBO Alpha mượt mà `[512, 512, RGBA]`, trong đó kênh Alpha mang giá trị liên tục trong đoạn $[0.0, 1.0]$.
- **Tác động pixel:** Triệt tiêu hoàn toàn răng cưa tại viền tóc; giữ lại độ trong suốt của các sợi tóc con mai và trán.

### GIAI ĐOẠN 3: LUMINANCE / FEATURE EXTRACTION
- **Input:** Texture ảnh gốc `inputImageTexture`.
- **Thực thi:** Hàm C++ `_ZN14MTFilterKernel16MTSoftHairFilter15grayFilterToFBOEPKfS2_PNS_19GPUImageFramebufferES4_` trong `libMTFilterKernel.so`.
- **Mã nguồn GLSL:**
  ```glsl
  lowp vec4 color = texture2D(inputImageTexture, texCoord);
  float gray = dot(color.rgb, vec3(0.299, 0.587, 0.114));
  gl_FragColor = vec4(vec3(gray), 1.0);
  ```
- **Output:** Texture FBO độ chói đơn sắc `LuminanceFBO`.
- **Tác động pixel:** Chuẩn hóa dải sáng của sợi tóc, làm cơ sở tính toán hướng cấu trúc và giữ độ sáng thực khi nhuộm màu.

### GIAI ĐOẠN 4: ORIENTATION / STRUCTURE TENSOR FIELD
- **Input:** Texture `LuminanceFBO`.
- **Thực thi:** Hai hàm tách hướng Gaussian 5-tap:
  - `_ZN14MTFilterKernel16MTSoftHairFilter16blurHFilterToFBOEPKfS2_PNS_19GPUImageFramebufferES4_`
  - `_ZN14MTFilterKernel16MTSoftHairFilter16blurVFilterToFBOEPKfS2_PNS_19GPUImageFramebufferES4_`
- **Thuật toán:**
  1. Tính đạo hàm không gian Sobel: $G_x = rac{\partial I}{\partial x}, G_y = rac{\partial I}{\partial y}$.
  2. Tính các thành phần tensor cấu trúc: $J_{xx} = G_x^2, J_{yy} = G_y^2, J_{xy} = G_x G_y$.
  3. Lọc mượt Gaussian 5-tap ngang và dọc trên các thành phần $J_{xx}, J_{yy}, J_{xy}$.
  4. Vector góc kép (Double-Angle Vector): $ec{v} = (\cos 2	heta, \sin 2	heta) = \left(rac{J_{xx} - J_{yy}}{\sqrt{(J_{xx}-J_{yy})^2 + 4J_{xy}^2}}, rac{2J_{xy}}{\sqrt{(J_{xx}-J_{yy})^2 + 4J_{xy}^2}}ight)$.
- **Output:** Texture Vector FBO lưu hướng tiếp tuyến sợi tóc.
- **Tác động pixel:** Xác lập trường dòng chảy liên tục của toàn bộ mái tóc, phát hiện các lọn tóc xoăn và hướng chải.

### GIAI ĐOẠN 5: DIRECTIONAL FILTERING (21-TAP LIC)
- **Input:** Texture ảnh tóc và Texture Vector FBO.
- **Thực thi:** Hàm C++ `_ZN14MTFilterKernel16MTSoftHairFilter19softHairFilterToFBOEPKfS2_iiiNS_6CGSizeEPNS_19GPUImageFramebufferE`.
- **Thuật toán:** Tích phân đường Line Integral Convolution (LIC) 21 taps dọc theo đường tiếp tuyến:
  $$I_{LIC}(\mathbf{x}) = rac{\sum_{k=-10}^{10} w_k \cdot I(\mathbf{x} + k \cdot \Delta s \cdot ec{t}(\mathbf{x}))}{\sum_{k=-10}^{10} w_k}$$
  với bước nhảy $\Delta s = 1.0 	ext{ pixel}$, trọng số Gaussian $w_k = \exp(-k^2 / (2 \sigma^2)), \sigma = 3.5$.
- **Output:** Texture tóc làm mượt có hướng `SoftHairFBO`.
- **Tác động pixel:** Khử các hạt nhiễu cảm biến camera trên tóc nhưng gia cố các sợi tóc thành từng dải mượt mà bóng bẩy.

### GIAI ĐOẠN 6: RECOLOR / TONE BLENDING
- **Input:** `SoftHairFBO` và bảng màu nhuộm tóc từ `MaterialData.lutPath`.
- **Thực thi:** Shader hòa trộn SoftLight không phân nhánh (Non-branching Pegtop formula) nhúng tại rodata `libMTFilterKernel.so`:
  ```glsl
  // Pegtop SoftLight formula
  vec3 blendSoftLight(vec3 base, vec3 blend) {
      return (1.0 - 2.0 * blend) * base * base + 2.0 * blend * base;
  }
  ```
- **Output:** Texture tóc đã nhuộm màu `DyedHairFBO`.
- **Tác động pixel:** Màu nhuộm ngấm sâu vào từng sợi tóc; các vùng tóc sáng (highlights) giữ được độ sáng, vùng tóc tối (shadows) giữ được chiều sâu, không bị bệt màu như sơn quét.

### GIAI ĐOẠN 7: SHINE & CLARITY BOOST
- **Input:** `DyedHairFBO` và `blurImageTexture`.
- **Thực thi:** Bộ lọc Unsharp Mask 9x9 nguyên văn từ `libMTFilterKernel.so`:
  ```glsl
  precision highp float;
  varying vec2 texCoord;
  uniform sampler2D inputImageTexture;
  uniform sampler2D inputImageMaskTexture;
  uniform sampler2D blurImageTexture;
  uniform float texWidthOffset;
  uniform float texHeightOffset;
  uniform int mode;
  void main() {
      lowp vec4 color = texture2D(inputImageTexture, texCoord);
      lowp vec4 maskColor = texture2D(inputImageMaskTexture, texCoord);
      lowp vec3 resultColor = color.rgb;
      lowp float mixture = maskColor.a;
      if (mode == 1) { mixture = maskColor.r; }
      if(mixture > 0.005) {
          vec2 horizontalStep = vec2(texWidthOffset, 0.0) * 2.3;
          vec2 verticalStep = vec2(0.0, texHeightOffset) * 2.3;
          vec3 sumColor = vec3(0.0, 0.0, 0.0);
          for(float t = -4.0; t < 4.5; t += 1.0) {
              for(float p = -4.0; p < 4.5; p += 1.0) {
                  sumColor += texture2D(inputImageTexture, texCoord + t * horizontalStep + p * verticalStep).rgb;
              }
          }
          sumColor = sumColor * 0.0123;
          sumColor = clamp(sumColor + (color.rgb - sumColor) * 1.8, 0.0, 1.0);
          sumColor = max(color.rgb, sumColor);
          lowp vec3 blurColor = texture2D(blurImageTexture, texCoord).rgb;
          lowp vec3 diffColor = color.rgb - blurColor;
          diffColor = min(diffColor, 0.0);
          lowp float clarity = 0.4;
          sumColor += (diffColor + 0.015) * clarity;
          sumColor = clamp(sumColor, 0.0, 1.0);
          resultColor = sumColor;
      }
      gl_FragColor = vec4(resultColor, 1.0);
  }
  ```
- **Hằng số toán học:**
  - Lưới lấy mẫu 9x9 (`t, p in [-4.0, 4.0]`, 81 taps, chuẩn hóa `* 0.0123`).
  - Hệ số giãn cách bước lấy mẫu: `* 2.3`.
  - Hệ số khuếch đại chi tiết biên: `* 1.8`.
  - Hệ số tăng độ trong trẻo (Clarity): `0.4`.
  - Hằng số bù trừ độ lệch tối: `0.015`.
- **Output:** Texture tóc hoàn thiện có độ bóng lọn tóc rõ rệt.
- **Tác động pixel:** Từng sợi tóc ánh lên độ bóng khỏe mạnh tự nhiên, chi tiết sợi tóc sắc nét mà không bị gai nhiễu hạt.

### GIAI ĐOẠN 8: COMPOSITING & PROTECTED ISOLATION
- **Input:** Texture ảnh gốc `OriginalRGB`, Texture tóc hoàn thiện `DyedEnhancedRGB`, Mặt nạ tóc tinh chỉnh `FeatheredAlpha`.
- **Thực thi:** Phép hòa trộn Alpha Compositing:
  $$	ext{FinalPixel} = (1.0 - 	ext{FeatheredAlpha}) \cdot 	ext{OriginalRGB} + 	ext{FeatheredAlpha} \cdot 	ext{DyedEnhancedRGB}$$
- **Vùng bảo vệ tuyệt đối:**
  - Vùng da mặt, trán, tai, cổ: $	ext{FeatheredAlpha} = 0.0 \implies 	ext{FinalPixel} = 	ext{OriginalRGB}$ (Bảo vệ 100%).
  - Hậu cảnh, tường, đồ đạc: $	ext{FeatheredAlpha} = 0.0 \implies 	ext{FinalPixel} = 	ext{OriginalRGB}$ (Bảo vệ 100%).
- **Tác động pixel:** Không một pixel nào ngoài vùng tóc bị lem màu hay biến dạng.
