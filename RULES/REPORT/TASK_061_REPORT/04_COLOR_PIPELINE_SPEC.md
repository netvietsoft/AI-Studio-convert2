# 04_COLOR_PIPELINE_SPEC — RECOVERED MEITU HAIR RECOLORING ENGINE

**Document ID:** `TASK_061_REPORT/04_COLOR_PIPELINE_SPEC.md`  
**Classification:** OBSERVED (Reverse Engineered from Bytecode / Shaders / Structs)  
**Target Entities:** `T1 (libmtImageKit.so - API Schema)`, `T2 (libARKernelInterface.so)`, `T4 (libMTFilterKernel.so)`, `T5 (libLayerFlow.so)`, `T6 (Asset Shaders)`

---

## 1. DYE MATERIAL SCHEMA & LAYER PIPELINE

In Meitu's engine (`libmtImageKit.so`, `libLayerFlow.so`), hair recoloring is structured as a multi-layer composition pipeline. Rather than replacing hair chrominance with a uniform constant value, the pipeline applies ordered passes:

```
                          ┌─────────────────────────────┐
                          │   Original Hair Pixels (A)  │
                          └──────────────┬──────────────┘
                                         │
                                         ▼
                          ┌─────────────────────────────┐
                          │ STAGE 0: HAIR PRE-WHITENING │
                          │     (needWhitenHair == true)│
                          │   Lift dark melanin base    │
                          └──────────────┬──────────────┘
                                         │
                                         ▼
                          ┌─────────────────────────────┐
                          │ STAGE 1: COLOR LUT SAMPLING │
                          │     (lutPath, lutOrder)     │
                          │  3D Color Look-up Table     │
                          └──────────────┬──────────────┘
                                         │
                                         ▼
                          ┌─────────────────────────────┐
                          │ STAGE 2: PS BLEND MODES     │
                          │ (SoftLight / Screen Overlay)│
                          │  Modulate hair luminance    │
                          └──────────────┬──────────────┘
                                         │
                                         ▼
                          ┌─────────────────────────────┐
                          │ STAGE 3: STRAND SHARPEN     │
                          │(sharpenOrder, sharpenAlpha) │
                          │ Restore cuticle micro-fiber │
                          └──────────────┬──────────────┘
                                         │
                                         ▼
                          ┌─────────────────────────────┐
                          │ STAGE 4: MASK-GATED BLEND   │
                          │   out = mix(orig, dyed, a)  │
                          │   gated by clamped hair mask│
                          └─────────────────────────────┘
```

---

## 2. STRUCT DEFINITIONS (OBSERVED FROM JADX & NATIVE SYMBOLS)

### `DyeHairMaterialInfo`:
```java
public class DyeHairMaterialInfo {
    public ArrayList<MaterialData> materialDataArray; // Ordered layer array
    public float maxAlpha = 1.0f;                     // Global opacity ceiling [0.0, 1.0]
    public boolean needWhitenHair = false;            // Dark-hair luminance pre-lift flag
}
```

### `MaterialData`:
```java
public class MaterialData {
    public String lutPath = "";         // 3D LUT texture resource
    public String materialPath = "";    // Overlay texture resource
    public String psPath = "";          // Secondary blend texture
    public int lutOrder = -1;           // Execution priority for LUT pass
    public int blendOrder = -1;         // Execution priority for Blend pass
    public int sharpenOrder = -1;       // Execution priority for Sharpen pass
    public float sharpenAlpha = 0.0f;   // High-frequency detail injection [0.0, 1.0]
    public int blendType = 0;           // 0 = SoftLight, 1 = Screen, 2 = Multiply
    public float blendAlpha = 1.0f;     // Layer opacity [0.0, 1.0]
}
```

---

## 3. STAGE 0: DARK HAIR PRE-WHITENING / LUMINANCE LIFTING

When dyeing dark Asian/brunette hair with light fashion colors (e.g. Platinum, Rose Gold, Milk Tea), applying dye directly to low luminance results in dirty/muddy tones. Meitu implements an optional pre-lift (`needWhitenHair`):

### Mathematical Formulation:
1. **Luminance Calculation:**
   $$Y_{\text{orig}} = 0.298912 \cdot R + 0.586611 \cdot G + 0.114478 \cdot B$$
2. **Luminance Expansion:**
   $$Y_{\text{lifted}} = Y_{\text{orig}} + (1.0 - Y_{\text{orig}}) \cdot k_{\text{whiten}}$$
   Where $k_{\text{whiten}} \in [0.15, 0.40]$ depending on preset base melanin level.
3. **Luminance Normalized Color:**
   $$RGB_{\text{lifted}} = \text{clamp}\left(RGB_{\text{orig}} \cdot \frac{Y_{\text{lifted}}}{\max(Y_{\text{orig}}, 10^{-4})}, \, 0.0, \, 1.0\right)$$

This preserves per-strand texture ratios while elevating the dynamic range to accept vibrant highlights.

---

## 4. STAGE 1: COLOR LUT MAPPING

### Physical Evidence:
- Asset references: `HairLutPath` (`libARKernelInterface.so` offset `0x00e76a58`).
- LUT textures: `ARKernelBuiltin/BeautyResource/LUT64.jpg` (512x512 pixels, standard 64x64x64 color cube).

### Mathematical Formulation:
For a 3D LUT of size $N=64$:
$$u = \frac{\lfloor B \cdot (N-1) \rfloor \bmod 8}{8} + \frac{R \cdot (N-1)}{8 \cdot N}$$
$$v = \frac{\lfloor B \cdot (N-1) \rfloor / 8}{8} + \frac{G \cdot (N-1)}{8 \cdot N}$$
$$RGB_{\text{lut}} = \text{sample2D}\big(\text{LUTTexture}, \, (u, v)\big)$$
Trilinear interpolation provides smooth chromatic transition without banding.

---

## 5. STAGE 2: BLEND MODES (SOFTLIGHT & SCREEN)

### 5.1 SoftLight Blending (blendType == 0)
**Physical Evidence:**
- File: `ARKernel3Builtin/Shaders/HairSoft/MTFilter_PsSoftLightr.fs`
- SHA-256: `e5b2c2ea4a28f954d1798b0456319eee6d2c593eb088ab092717830b2eaafb15`
- Texture: `ARKernelBuiltin/Overlay/PSBlend/BlendSoftLight.jpg` (256x256 precomputed LUT).

**Verbatim Shader Code:**
```glsl
float SoftLight_Fcn(float A, float B) {
    float C = 0.0;
    if (B <= 0.5) {
        C = A * B / 0.5 + A * A * (1.0 - 2.0 * B);
    } else {
        C = A * (1.0 - B) / 0.5 + sqrt(A) * (2.0 * B - 1.0);
    }
    return C;
}
```

**Mathematical Formula:**
For base $A$ and overlay $B$ in $[0.0, 1.0]$:
$$C = \begin{cases}
2 A B + A^2 (1 - 2 B), & \text{for } B \le 0.5 \\
2 A (1 - B) + \sqrt{A} (2 B - 1), & \text{for } B > 0.5
\end{cases}$$

**Layer Opacity Mix:**
$$RGB_{\text{blend}} = A \cdot (1.0 - \text{blendAlpha}) + C \cdot \text{blendAlpha}$$

*Significance:* Because $C$ is a function of $A$ and $A^2$ or $\sqrt{A}$, dark lock shadows remain dark and specular hair glints remain bright. The hair **never appears flat/painted** like a solid coat of paint.

---

### 5.2 Screen Blending (blendType == 1)
**Physical Evidence:**
- File: `ARKernel3Builtin/Shaders/HairSoft/MTFilter_PsFilterColor.fs`
- SHA-256: `18f7d93414...`

**Verbatim Shader Code:**
```glsl
vec3 res_color = 1.0 - (1.0 - src_color) * (1.0 - overlay_color);
gl_FragColor = vec4(mix(src_color, res_color, alpha), 1.0);
```

**Mathematical Formula:**
$$RGB_{\text{screen}} = 1.0 - (1.0 - A) \cdot (1.0 - B)$$
Used for brightening and metallic pastel overlays.

---

## 6. STAGE 3: ORIENTED DETAIL RESTORATION & SHARPEN

### Physical Evidence:
- `libMTFilterKernel.so`: `MTFilterKernel::MTSoftHairFilter::softHairFilterToFBO` (address `0x000f4878`).
- Shaders: `MTFilter_gradient.fs` & `MTFilter_HairSoftMix.fs`.

### Recovered Algorithm:
1. **Strand Gradient & Orientation:**
   Gradient vector $(gx, gy)$ computed across 2x2 texel stencil.
   $$\text{gradDouble} = \left(\frac{gx^2 - gy^2}{gx^2 + gy^2}, \, \frac{2 gx gy}{gx^2 + gy^2}\right)$$
   $$\theta = \frac{1}{2} \text{atan2}(\text{gradDouble}.y, \, \text{gradDouble}.x) + \frac{\pi}{2}$$
2. **Directional Convolution along Strands:**
   $K = 10$ sampling taps along $\vec{u} = (\cos \theta, \sin \theta) \cdot \text{shiftingSize}$.
   Taps only accepted where neighbor $\text{mask} > 0.1$.
3. **High-Frequency Cuticle Extraction:**
   $$\text{HighFreq} = RGB_{\text{orig}} - RGB_{\text{oriented\_blur}}$$
4. **Detail Injection:**
   $$RGB_{\text{sharpened}} = RGB_{\text{blend}} + \text{HighFreq} \cdot \text{sharpenAlpha}$$

---

## 7. STAGE 4: COMPOSITE PASS

### Physical Evidence:
- File: `ARKernel3Builtin/Shaders/HairSoft/MTFilter_Mix.fs` (`9be11ef5b8...`).
- Native JNI: `nSetDyeHairRenderAlpha(long, float, int)` & `maxAlpha`.

### Verbatim Shader Code:
```glsl
vec4 src_color = texture2D(s_texture, texcoordOut);
vec4 ref_color = texture2D(ref_texture, texcoordOut);
float mask_val = texture2D(mask_texture, texcoordOut).r;

vec4 mix_color = mix(src_color, ref_color, alpha);
gl_FragColor = mix(src_color, mix_color, mask_val);
```

### Exact Mathematical Formula:
$$\alpha_{\text{eff}}(x, y) = M_{\text{final}}(x, y) \cdot \text{renderAlpha} \cdot \text{maxAlpha}$$
$$\text{Output}(x, y) = RGB_{\text{orig}}(x, y) \cdot \big(1.0 - \alpha_{\text{eff}}(x, y)\big) + RGB_{\text{sharpened}}(x, y) \cdot \alpha_{\text{eff}}(x, y)$$
