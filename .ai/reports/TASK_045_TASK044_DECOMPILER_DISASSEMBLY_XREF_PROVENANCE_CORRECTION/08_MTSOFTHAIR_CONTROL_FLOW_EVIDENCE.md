# TASK_045 — MTSOFTHAIR FILTER CONTROL FLOW & SHADER EVIDENCE
## GROUND-TRUTH STATIC RECONSTRUCTION FROM `libMTFilterKernel.so`

### 1. Architectural Reality & Function Mapping
Forensic disassembly of `libMTFilterKernel.so` establishes that vendor code implements hair filtering across two distinct class architectures:
1. **`MTFilterKernel::MTSoftHairFilter` (Virtual `GPUImageFilter` Subclass):**
   - Vtable Address: `.data.rel.ro:0x1be1e8`
   - Primary Render Method: `renderToTextureWithVerticesAndTextureCoordinates` at address `0x0f3f58`
2. **`MTFilterKernel::CMTFilterSoftHair` (Dynamic Filter Pipeline Subclass):**
   - Vtable Address: `.data.rel.ro:0x1c1e28`
   - Primary Render Method: `FilterToFBO(int, int, bool)` at address `0x1344e8`

In TASK_044, the agent fabricated a nonexistent C++ function: `void MTSoftHairFilter::renderHairPipeline(...)` with imaginary member variables (`grayShader`, `blurHShader.setFloat("u_blurRadius", 2.5f)`). This fabrication is hereby formally **RETRACTED**.

---

### 2. Disassembly & Host Orchestration Control Flow

#### Pipeline 1: `MTSoftHairFilter::renderToTextureWithVerticesAndTextureCoordinates` (`0x0f3f58`)
```arm64
0x0f3f58:  stp       x29, x30, [sp, #0x50]
0x0f3f5c:  stp       x28, x27, [sp, #0x60]
0x0f3f60:  mov       x29, sp
...
0x0f3fac:  bl        #0xf42fc    // Pass 1: Call MTSoftHairFilter::grayFilterToFBO (Extract Luminance)
0x0f3fb0:  ldr       x3, [x20, #0x1e8]
0x0f3fb4:  ldr       x4, [x20, #0x1f8]
0x0f3fc0:  bl        #0xf4400    // Pass 2: Call MTSoftHairFilter::hairMaskFilterToFBO (Mask Isolation)
0x0f3fc4:  ldr       x3, [x20, #0x1f8]
0x0f3fc8:  ldr       x4, [x20, #0x208]
0x0f3fd4:  bl        #0xf4528    // Pass 3: Call MTSoftHairFilter::blurHFilterToFBO (Gaussian H Blur)
0x0f3fd8:  ldr       x3, [x20, #0x208]
0x0f3fdc:  ldr       x4, [x20, #0x218]
0x0f3fe8:  bl        #0xf46d0    // Pass 4: Call MTSoftHairFilter::blurVFilterToFBO (Gaussian V Blur)
...
0x0f400c:  mov       w9, #0x44a00000   // Float constant 1280.0f
0x0f4010:  fmov      s1, w9
0x0f401c:  movk      w8, #0x4470, lsl #16 // Float constant 962.0f
0x0f4020:  fmov      s0, w8
0x0f4024:  bl        #0xf4878    // Pass 5: Call MTSoftHairFilter::softHairFilterToFBO (Final Shader)
0x0f4058:  ret
```

#### Pipeline 2: `CMTFilterSoftHair::FilterToFBO` (`0x1344e8`)
```arm64
0x1344e8:  stp       x29, x30, [sp, #-0x60]!
...
0x1346fc:  bl        #0x13488c   // Pass 1: GrayFilterToFBO
0x134710:  bl        #0x134970   // Pass 2: HairMaskFilterToFBO
0x134724:  bl        #0x134a90   // Pass 3: BlurHFilterToFBO
0x134738:  bl        #0x134c10   // Pass 4: BlurVFilterToFBO
0x134758:  bl        #0x134d90   // Pass 5: SoftHairFilterToFBO
0x1347a4:  ret
```

---

### 3. Exact 1D Gaussian Kernel Weights & Step Coordinates
Disassembly of `blurHFilterToFBO` (0x0f4528) and `blurVFilterToFBO` (0x0f46d0) proves that Gaussian blur does not use a 5-tap kernel or a radius of 2.5f. Instead, it references calibrated IEEE-754 floating-point constants in `.rodata`:

- **Gaussian Blur Kernel Weights (`.rodata:0x8edd8`):**
  - Center & primary tap weights: `0.159676`, `0.263348`, `0.122118`, `0.030573`
  - High-order tap weights loaded in registers `w8`/`w9`: `0.011300`, `0.004122`
- **Horizontal Texture Coordinates Offsets (`.rodata:0x8edc4`):**
  - `(0.000000, 0.002250, 0.005256, 0.008271)`
- **Vertical Texture Coordinates Offsets (`.rodata:0x8edec`):**
  - `(0.000000, 0.002994, 0.006993, 0.011005)`

---

### 4. True Verbatim Embedded GLSL Shader Source
Extracted directly from `.rodata` offset `0x77b00` in `libMTFilterKernel.so` (origin: `/home/meitu/apollo-ws/src/MLabFilterOnline/MTFilter/FilterCore/DrawArrayFilter/MTSoftHairFilter.cpp`):

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
    if (mode == 1) {
        mixture = maskColor.r;
    }
    if (mixture > 0.005) {
        vec2 horizontalStep = vec2(texWidthOffset, 0.0) * 2.3;
        vec2 verticalStep = vec2(0.0, texHeightOffset) * 2.3;
        vec3 sumColor = vec3(0.0, 0.0, 0.0);
        
        // 9x9 box sample grid
        for (float t = -4.0; t < 4.5; t += 1.0) {
            for (float p = -4.0; p < 4.5; p += 1.0) {
                sumColor += texture2D(inputImageTexture, texCoord + t * horizontalStep + p * verticalStep).rgb;
            }
        }
        sumColor = sumColor * 0.0123; // Normalization factor (~ 1.0 / 81.0)
        
        // Unsharp Mask / Detail Exaggeration Boost
        sumColor = clamp(sumColor + (color.rgb - sumColor) * 1.8, 0.0, 1.0);
        sumColor = max(color.rgb, sumColor);
        
        // High-frequency dark halo differential with Gaussian blur texture
        lowp vec3 blurColor = texture2D(blurImageTexture, texCoord).rgb;
        lowp vec3 diffColor = color.rgb - blurColor;
        diffColor = min(diffColor, 0.0);
        
        // Hair strand clarity addition
        lowp float clarity = 0.4;
        sumColor += (diffColor + 0.015) * clarity;
        sumColor = clamp(sumColor, 0.0, 1.0);
        resultColor = sumColor;
    }
    gl_FragColor = vec4(resultColor, 1.0);
}
```

### 5. Architectural Findings & Verdict
The vendor `MTSoftHairFilter` is **NOT** a dye colorizer using Photoshop Soft Light. It is a **hair structure clarity, unsharp-masking, and edge-preserving texture enhancer**. Dye recoloring is applied modularly in `libLayerFlow.so` via `CLFDenseHairProcessor` and tone LUT mapping (`lut.png`).
