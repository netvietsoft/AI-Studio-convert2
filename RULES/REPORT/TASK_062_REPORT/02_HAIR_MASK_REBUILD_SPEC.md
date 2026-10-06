# TASK 062 – TECHNICAL SPECIFICATION: HAIR MASK REBUILD & SOFTLIGHT

## 1. Architectural Motivation
In mobile computer vision applications, hair color replacement presents two conflicting constraints:
1. **Fringe Coverage:** Fine hair strands and wisps frequently overlap skin, clothing, and background.
2. **Leakage Prohibition:** Dyeing any non-hair pixels (forehead skin, ears, eyelids, clothing collar) immediately breaks suspension of disbelief and registers as a critical software defect.

Previous heuristic implementations attempted to resolve this by circumscribing the face inside an analytical ellipse or thresholding YCrCb skin chrominance. These heuristics inevitably fail when:
- The subject's hairstyle does not fit an ellipse (curly hair, afros, side-swept bangs).
- The subject's skin luminance or hue varies across the face due to lighting, shadows, or tanning.
- The clothing color approximates hair or skin tones.

TASK_062 eliminates these heuristics and transitions to a strictly **semantic exclusion clamping pipeline** paired with **photometric Pegtop SoftLight deposition**.

---

## 2. Mask Exclusion Clamping

### 2.1 Theoretical Formulation
Let:
- $\mathbf{M}_{\text{hair}}(x, y) \in [0, 1]$ be the raw probability mask output by BiSeNet for semantic class 17 (Hair).
- $\mathbf{M}_{\text{excl}}(x, y) \in [0, 1]$ be the union exclusion mask:
  $$\mathbf{M}_{\text{excl}} = \max\left(\mathbf{M}_{\text{face\_skin}}, \mathbf{M}_{\text{neck}}, \mathbf{M}_{\text{ears}}, \mathbf{M}_{\text{clothing}}, \mathbf{M}_{\text{hat}}\right)$$

In Meitu's `MTFilter_HairMaskMix.fs`, the clamping is executed per-pixel:
$$\mathbf{V}_{\text{black}} = 1.0 - \mathbf{M}_{\text{excl}}$$
$$\mathbf{M}_{\text{clamped}} = \min\left(\mathbf{M}_{\text{hair}}, \mathbf{V}_{\text{black}}\right)$$

To enforce zero leakage across fuzzy boundaries:
$$\text{If } \mathbf{M}_{\text{excl}}(x, y) \ge 0.95 \implies \mathbf{M}_{\text{clamped}}(x, y) = 0.0$$

### 2.2 Boundary Behavior
- **Pure Hair Pixel ($\mathbf{M}_{\text{excl}} = 0.0$):**  
  $\mathbf{V}_{\text{black}} = 1.0 \implies \mathbf{M}_{\text{clamped}} = \min(\mathbf{M}_{\text{hair}}, 1.0) = \mathbf{M}_{\text{hair}}$. Full hair transparency preserved.
- **Pure Skin / Clothing Pixel ($\mathbf{M}_{\text{excl}} = 1.0$):**  
  $\mathbf{V}_{\text{black}} = 0.0 \implies \mathbf{M}_{\text{clamped}} = \min(\mathbf{M}_{\text{hair}}, 0.0) = 0.0$. Guaranteed zero dye deposition.
- **Hair Fringe Boundary ($\mathbf{M}_{\text{hair}} = 0.6, \mathbf{M}_{\text{excl}} = 0.3$):**  
  $\mathbf{V}_{\text{black}} = 0.7 \implies \mathbf{M}_{\text{clamped}} = 0.6$. The hair wisp retains its transparency.
- **Skin Boundary ($\mathbf{M}_{\text{hair}} = 0.4, \mathbf{M}_{\text{excl}} = 0.8$):**  
  $\mathbf{V}_{\text{black}} = 0.2 \implies \mathbf{M}_{\text{clamped}} = 0.2$. The dye is aggressively attenuated to prevent halo leakage.

---

## 3. Pegtop SoftLight Photometric Blending

### 3.1 Derivation & Mathematical Proof
Linear color blending replaces chrominance directly:
$$\mathbf{C}_{\text{out}} = \mathbf{C}_{\text{orig}} \cdot (1 - \alpha) + \mathbf{C}_{\text{dye}} \cdot \alpha$$
This crushes the reflectance variations of individual hair cuticles.

The Pegtop SoftLight formula computes continuous, smooth tone mapping where the blend color modulates the contrast curve of the base:
For base channel $A \in [0, 1]$ and blend channel $B \in [0, 1]$:
$$C(A, B) = \begin{cases}
2AB + A^2(1 - 2B) & \text{for } B \le 0.5 \\
2A(1 - B) + \sqrt{A}(2B - 1) & \text{for } B > 0.5
\end{cases}$$

### 3.2 Key Invariants
1. **Neutral Blend Color ($B = 0.5$):**
   $$C(A, 0.5) = 2A(0.5) + A^2(0) = A$$
   Applying a 50% neutral gray dye leaves the underlying hair completely unchanged.
2. **Shadow Crevice Invariance ($A = 0$):**
   $$\lim_{A \to 0} C(A, B) = 0 \quad \forall B \in [0, 1]$$
   Deep shadows remain deep black. No milky graying or washed-out roots.
3. **Specular Highlight Invariance ($A = 1$):**
   $$\text{For } B \le 0.5: \quad C(1, B) = 2B + (1 - 2B) = 1$$
   $$\text{For } B > 0.5: \quad C(1, B) = 2(1 - B) + (2B - 1) = 1$$
   Specular glints and sheen reflections remain pure white ($1.0$), ensuring natural glossiness.

---

## 4. C++ Integration (`hair_pipeline_v2.cpp`)

```cpp
// Static inline photometric Pegtop SoftLight operator
static inline float softLightPegtop(float A, float B) {
    if (B <= 0.5f) {
        return (2.0f * A * B) + (A * A * (1.0f - 2.0f * B));
    } else {
        return (2.0f * A * (1.0f - B)) + (std::sqrt(std::max(0.0f, A)) * (2.0f * B - 1.0f));
    }
}

// SIMD / OpenMP Scanline Implementation
#pragma omp parallel for schedule(dynamic, 128)
for (int i = 0; i < pixel_count; ++i) {
    float excl = exclusion_mask[i];
    float raw_hair = hair_mask[i];
    
    // Mask Exclusion Clamping
    float blackvalue = 1.0f - excl;
    float hair_alpha = std::min(raw_hair, blackvalue);
    if (excl >= 0.95f) {
        hair_alpha = 0.0f;
    }
    
    if (hair_alpha <= 0.001f) {
        output_rgb[i * 3 + 0] = input_rgb[i * 3 + 0];
        output_rgb[i * 3 + 1] = input_rgb[i * 3 + 1];
        output_rgb[i * 3 + 2] = input_rgb[i * 3 + 2];
        continue;
    }
    
    float r = input_rgb[i * 3 + 0] / 255.0f;
    float g = input_rgb[i * 3 + 1] / 255.0f;
    float b = input_rgb[i * 3 + 2] / 255.0f;
    
    // Melanin Desaturation (Bleach Factor)
    float Y = 0.299f * r + 0.587f * g + 0.114f * b;
    float base_r = r * (1.0f - bleach_factor) + Y * bleach_factor;
    float base_g = g * (1.0f - bleach_factor) + Y * bleach_factor;
    float base_b = b * (1.0f - bleach_factor) + Y * bleach_factor;
    
    // Photometric Pegtop SoftLight
    float dyed_r = softLightPegtop(base_r, dye_r);
    float dyed_g = softLightPegtop(base_g, dye_g);
    float dyed_b = softLightPegtop(base_b, dye_b);
    
    // Alpha Composite
    output_rgb[i * 3 + 0] = (uint8_t)(std::round((r * (1.0f - hair_alpha) + dyed_r * hair_alpha) * 255.0f));
    output_rgb[i * 3 + 1] = (uint8_t)(std::round((g * (1.0f - hair_alpha) + dyed_g * hair_alpha) * 255.0f));
    output_rgb[i * 3 + 2] = (uint8_t)(std::round((b * (1.0f - hair_alpha) + dyed_b * hair_alpha) * 255.0f));
}
```

---

## 5. GLSL Fragment Shader Reference

### 5.1 `MTFilter_HairMaskMix.fs`
```glsl
precision highp float;
varying highp vec2 textureCoordinate;
uniform sampler2D inputImageTexture;  // Raw hair mask
uniform sampler2D inputImageTexture2; // Semantic exclusion mask

void main() {
    float raw_hair = texture2D(inputImageTexture, textureCoordinate).r;
    float excl = texture2D(inputImageTexture2, textureCoordinate).r;
    
    float blackvalue = 1.0 - excl;
    float clamped = min(raw_hair, blackvalue);
    if (excl >= 0.95) {
        clamped = 0.0;
    }
    gl_FragColor = vec4(vec3(clamped), 1.0);
}
```

### 5.2 `MTFilter_PsSoftLightr.fs`
```glsl
precision highp float;
varying highp vec2 textureCoordinate;
uniform sampler2D inputImageTexture;   // Camera / Base Texture
uniform sampler2D inputImageTexture2;  // Clamped Hair Mask
uniform vec3 targetDyeColor;           // RGB normalized [0, 1]
uniform float bleachFactor;

float softLightChannel(float A, float B) {
    if (B <= 0.5) {
        return (2.0 * A * B) + (A * A * (1.0 - 2.0 * B));
    } else {
        return (2.0 * A * (1.0 - B)) + (sqrt(max(0.0, A)) * (2.0 * B - 1.0));
    }
}

void main() {
    vec4 baseColor = texture2D(inputImageTexture, textureCoordinate);
    float mask = texture2D(inputImageTexture2, textureCoordinate).r;
    
    if (mask <= 0.001) {
        gl_FragColor = baseColor;
        return;
    }
    
    float Y = dot(baseColor.rgb, vec3(0.299, 0.587, 0.114));
    vec3 desat = mix(baseColor.rgb, vec3(Y), bleachFactor);
    
    vec3 dyed;
    dyed.r = softLightChannel(desat.r, targetDyeColor.r);
    dyed.g = softLightChannel(desat.g, targetDyeColor.g);
    dyed.b = softLightChannel(desat.b, targetDyeColor.b);
    
    gl_FragColor = vec4(mix(baseColor.rgb, dyed, mask), baseColor.a);
}
```
