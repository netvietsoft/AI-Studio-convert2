# TASK_045 — HIGH-VALUE FUNCTION PSEUDOCODE EVIDENCE

**Canonical Authority:** Chủ tịch Tony  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Mục tiêu:** Công bố mã giả trung thực, có liên kết địa chỉ nhị phân trực tiếp, phân định rõ giữa mã GLSL nhúng và luồng điều khiển máy chủ.  

---

## 1. MÃ GIẢ ĐIỀU KHIỂN ĐÃ XÁC THỰC: `MTSoftHairFilter::renderToTexture`
*Khôi phục chính xác từ ARM64 Disassembly tại địa chỉ `0x000f3f58` trong `libMTFilterKernel.so`.*

```cpp
// PROVENANCE: libMTFilterKernel.so (offset: 0x000f3f58, ARM64 little-endian)
// VERIFIED BY: LLVM 19.0.1 objdump & CFG branch reconstruction
void MTSoftHairFilter::renderToTextureWithVerticesAndTextureCoordinates(
    const float* vertices,
    const float* textureCoordinates,
    GPUImageFramebuffer* sourceFBO,
    GPUImageFramebuffer* maskFBO,
    const MTImgTextureManger& textureManager)
{
    // Step 0: Ensure internal framebuffers are allocated (0xf405c)
    if (this->m_grayFBO == nullptr) {
        allocateInternalFramebuffers(); // 104 bytes per FBO instance
    }

    // Step 1: Render Luminance pass (Address: 0x000f42fc)
    // Converts input RGB into high-frequency luminance texture
    this->grayFilterToFBO(vertices, textureCoordinates, sourceFBO, this->m_grayFBO);

    // Step 2: Render Hair Mask preprocessing pass (Address: 0x000f4400)
    // Extracts alpha/red channel mask depending on mode
    this->hairMaskFilterToFBO(vertices, textureCoordinates, maskFBO, this->m_maskFBO);

    // Step 3: Horizontal 5-tap Gaussian Blur (Address: 0x000f4528)
    // Uses static weights at 0x8edd8 and horizontal offsets at 0x8edc4
    this->blurHFilterToFBO(vertices, textureCoordinates, this->m_maskFBO, this->m_blurHFBO);

    // Step 4: Vertical 5-tap Gaussian Blur (Address: 0x000f46d0)
    // Uses static weights at 0x8edd8 and vertical offsets at 0x8edec
    this->blurVFilterToFBO(vertices, textureCoordinates, this->m_blurHFBO, this->m_blurVFBO);

    // Step 5: Final Hair Clarity & Unsharp Mask Enhancer (Address: 0x000f4878)
    // Hardcoded canvas dimension constants: 962.0f x 1280.0f
    CGSize targetSize = CGSize(962.0f, 1280.0f);
    int mode = this->m_context->m_params->mode; // Offset +0x50
    this->softHairFilterToFBO(
        vertices,
        textureCoordinates,
        sourceFBO->getTextureId(),
        this->m_blurVFBO->getTextureId(),
        mode,
        targetSize,
        this->m_outputFBO
    );
}
```

---

## 2. NGUYÊN VĂN MÃ NGUỒN SHADER NHÚNG: `MTSoftHairFilter.cpp`
*Trích xuất nguyên văn từ chuỗi nhúng tại offset `0x77afa` trong `libMTFilterKernel.so`.*

```glsl
// PROVENANCE: libMTFilterKernel.so (offset: 0x77afa)
// COMPILATION PATH: Source/DrawArrayFilter/MTSoftHairFilter.cpp
precision highp float;
varying vec2 texCoord;

uniform sampler2D inputImageTexture;     // Gốc ảnh chân dung RGB
uniform sampler2D inputImageMaskTexture; // Mặt nạ tóc (Alpha hoặc Red)
uniform sampler2D blurImageTexture;      // Mặt nạ làm mờ 2 lượt Gauss
uniform float texWidthOffset;            // Bước nhảy pixel ngang (1.0 / Width)
uniform float texHeightOffset;           // Bước nhảy pixel dọc (1.0 / Height)
uniform int mode;                        // Chế độ mặt nạ: 0 = Alpha, 1 = Red

void main() {
    lowp vec4 color = texture2D(inputImageTexture, texCoord);
    lowp vec4 maskColor = texture2D(inputImageMaskTexture, texCoord);
    lowp vec3 resultColor = color.rgb;
    lowp float mixture = maskColor.a;
    
    if (mode == 1) { 
        mixture = maskColor.r; 
    }
    
    // Ngưỡng can thiệp tóc: chỉ áp dụng khi độ tin cậy mặt nạ > 0.5%
    if (mixture > 0.005) {
        vec2 horizontalStep = vec2(texWidthOffset, 0.0) * 2.3;
        vec2 verticalStep = vec2(0.0, texHeightOffset) * 2.3;
        vec3 sumColor = vec3(0.0, 0.0, 0.0);
        
        // Lưới lấy mẫu hộp 9x9 (81 điểm ảnh xung quanh)
        for (float t = -4.0; t < 4.5; t += 1.0) {
            for (float p = -4.0; p < 4.5; p += 1.0) {
                sumColor += texture2D(inputImageTexture, texCoord + t * horizontalStep + p * verticalStep).rgb;
            }
        }
        
        // Chuẩn hóa bộ lọc hộp: 1.0 / 81.0 = 0.012345679
        sumColor = sumColor * 0.0123;
        
        // Tăng cường tương phản sợi tóc Unsharp Mask (Hệ số 1.8x)
        sumColor = clamp(sumColor + (color.rgb - sumColor) * 1.8, 0.0, 1.0);
        sumColor = max(color.rgb, sumColor);
        
        // Khôi phục chi tiết tối & độ trong trẻo sợi tóc (Clarity)
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

---

## 3. HÀM TOÁN HỌC GLSL SOFT LIGHT THỰC TẾ TRONG NHỊ PHÂN
*Trích xuất nguyên văn từ chuỗi nhúng tại offset `0x82369` trong `libMTFilterKernel.so`.*

```glsl
// PROVENANCE: libMTFilterKernel.so (offset: 0x82369)
highp vec3 blendSoftLight(in highp vec3 base, in highp vec3 blend) {
    // Vùng sáng (blend > 0.5): công thức căn bậc hai Pegtop
    highp vec3 above = sqrt(base) * (2.0 * blend - 1.0) + 2.0 * base * (1.0 - blend);
    // Vùng tối (blend <= 0.5): công thức bậc hai Photoshop chuẩn
    highp vec3 below = 2.0 * base * blend + base * base * (1.0 - 2.0 * blend);
    // Hòa trộn mượt mà không phân nhánh điều kiện trên GPU
    return mix(below, above, step(0.5, blend));
}

highp vec3 blendSoftLight(in highp vec3 base, in highp vec3 blend, in highp float opacity) {
    return mix(base, blendSoftLight(base, blend), opacity);
}
```
