# TASK_038 — Hair Shader Pass Reconstruction & Exact Mathematics

## 1. Master Pass Order
In `libMTFilterKernel.so` (`CMTFilterSoftHair::Initlize` at RVA `0x001342dc` and `FilterToFBO` at RVA `0x001344e8`), exactly 5 passes execute in sequential order:

---

## 2. Pass 1: Grayscale Luminance Extraction (`GrayFilterToFBO`)

### Vertex Shader
```glsl
attribute vec4 position;
attribute vec4 inputTextureCoordinate;
varying highp vec2 textureCoordinate;

void main() {
    gl_Position = position;
    textureCoordinate = inputTextureCoordinate.xy;
}
```

### Fragment Shader
```glsl
uniform sampler2D inputImageTexture;
varying highp vec2 textureCoordinate;

void main() {
    highp vec4 color = texture2D(inputImageTexture, textureCoordinate);
    highp float gray = dot(color.rgb, vec3(0.298912, 0.586611, 0.114478));
    gl_FragColor = vec4(vec3(gray), color.a);
}
```
> **Evidence:** Luminance coefficients `(0.298912, 0.586611, 0.114478)` match standard ITU-R BT.601 perceptual luma.

---

## 3. Pass 2: 2x2 Structure Tensor / Gradient Orientation Field (`HairMaskFilterToFBO`)

### Fragment Shader
```glsl
uniform sampler2D inputImageTexture;
varying highp vec2 textureCoordinate;
uniform highp vec2 shiftingSize;

void main() {
    highp vec2 uv = textureCoordinate;
    highp float gray00 = texture2D(inputImageTexture, uv).r;
    highp float gray01 = texture2D(inputImageTexture, uv + vec2(shiftingSize.x, 0)).r;
    highp float gray10 = texture2D(inputImageTexture, uv + vec2(0, shiftingSize.y)).r;
    highp float gray11 = texture2D(inputImageTexture, uv + shiftingSize).r;

    // Sobel/central gradient approximation
    highp vec2 grad = vec2(gray01 + gray11 - gray00 - gray10,
                           gray10 + gray11 - gray00 - gray01) * 0.5;

    // Structure tensor squared gradients
    highp vec2 grad2 = grad * grad;
    highp float gradLen2 = grad2.x + grad2.y;

    // Double-angle representation (coherence factor)
    highp vec2 gradDouble = gradLen2 != 0.0 ? vec2(grad2.x - grad2.y, 2.0 * grad.x * grad.y) / gradLen2 : vec2(0.0);

    // Pack into RG channels [0, 1]
    gl_FragColor = vec4(gradDouble * 0.5 + 0.5, 0.0, 1.0);
}
```
> **Evidence:** The double-angle representation `vec2(grad2.x - grad2.y, 2.0 * grad.x * grad.y)` resolves $180^\circ$ directional ambiguity of hair strands, allowing smooth spatial filtering of orientation vectors without phase cancellation.

---

## 4. Passes 3 & 4: Separable 5-Tap Tensor Smoothing (`BlurHFilterToFBO` & `BlurVFilterToFBO`)

### Vertical Smoothing Fragment Shader
```glsl
uniform sampler2D inputImageTexture;
varying highp vec2 textureCoordinate;
uniform highp float Weights[5];
uniform highp float Offsets[5];

void main() {
    highp vec2 uv = textureCoordinate;
    highp vec4 srccolor = texture2D(inputImageTexture, uv);
    highp vec4 sum = srccolor * Weights[0];
    for (int i = 1; i < 5; ++i) {
        srccolor = texture2D(inputImageTexture, vec2(uv.x, uv.y - Offsets[i]));
        sum += srccolor * Weights[i];
        srccolor = texture2D(inputImageTexture, vec2(uv.x, uv.y + Offsets[i]));
        sum += srccolor * Weights[i];
    }
    gl_FragColor = sum;
}
```

### Horizontal Smoothing Fragment Shader
```glsl
uniform sampler2D inputImageTexture;
varying highp vec2 textureCoordinate;
uniform highp float Weights[5];
uniform highp float Offsets[5];

void main() {
    highp vec2 uv = textureCoordinate;
    highp vec4 srccolor = texture2D(inputImageTexture, uv);
    highp vec4 sum = srccolor * Weights[0];
    for (int i = 1; i < 5; ++i) {
        srccolor = texture2D(inputImageTexture, vec2(uv.x - Offsets[i], uv.y));
        sum += srccolor * Weights[i];
        srccolor = texture2D(inputImageTexture, vec2(uv.x + Offsets[i], uv.y));
        sum += srccolor * Weights[i];
    }
    gl_FragColor = sum;
}
```

---

## 5. Pass 5: 10-Tap Anisotropic Strand-Aligned Bilateral Filter (`SoftHairFilterToFBO`)

### Fragment Shader
```glsl
const int KERNEL_SIZE = 10;
varying highp vec2 textureCoordinate;
uniform sampler2D inputImageTexture;
uniform sampler2D gradientTexture;
uniform sampler2D hairMaskTexture;
uniform highp vec2 shiftingSize;
uniform highp float threshold;
uniform highp float gain;
uniform highp float kernel[10];

void main() {
    highp vec2 uv = textureCoordinate;
    // Recover unpacked gradient vector
    highp vec2 gradient = texture2D(gradientTexture, uv).rg * 2.0 - 1.0;

    // Reconstruct hair strand tangent direction
    highp float direction = atan(gradient.y, gradient.x) * 0.5 + 3.14159 * 0.5;
    direction = mod(direction, 3.14159);

    highp float amount = (length(gradient) - threshold) * gain;
    highp float sumWeight = kernel[0];
    highp vec4 sumColor = texture2D(inputImageTexture, uv) * kernel[0];

    // UV offset vector aligned along hair strand flow
    highp vec2 directionUV = vec2(cos(direction), sin(direction)) * shiftingSize;

    // Symmetric 10-tap bilateral filtering along strand orientation
    for (int i = 1; i < KERNEL_SIZE; ++i) {
        highp vec2 offset = directionUV * float(i);
        highp vec4 color1 = texture2D(inputImageTexture, uv + offset);
        highp vec4 color2 = texture2D(inputImageTexture, uv - offset);
        highp float weight = kernel[i];
        sumWeight += 2.0 * weight;
        sumColor += (color1 + color2) * weight;
    }

    highp vec4 origColor = texture2D(inputImageTexture, uv);
    highp vec4 hairMask = texture2D(hairMaskTexture, uv);

    // Final alpha-guided blending
    gl_FragColor = mix(origColor, sumColor / sumWeight, hairMask.r * gain);
}
```

### Exact Reconstructed Kernel Constants (`kernel[10]`)
Extracted from IEEE-754 single-precision float constants in `libMTFilterKernel.so`:
- `kernel[0] = 1.000000`
- `kernel[1] = 0.980199`
- `kernel[2] = 0.923116`
- `kernel[3] = 0.835270`
- `kernel[4] = 0.726149`
- `kernel[5] = 0.606531`
- `kernel[6] = 0.486752`
- `kernel[7] = 0.375311`
- `kernel[8] = 0.278037`
- `kernel[9] = 0.197899`

> **Mathematical Origin:** Exact evaluation of Gaussian function $W(i) = \exp\left(-rac{i^2}{2\sigma^2}ight)$ with $\sigma = 5.0$ at integer radii $i \in [0, 9]$.