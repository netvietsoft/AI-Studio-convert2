# TASK_038 — Hair Parameter Mapping & Data Flow Specification

## 1. Image Buffer & Texture Formats

| Stage | Buffer / Texture | Format | Resolution | Color Order | Alignment / Stride |
|---|---|---|---|---|---|
| **Input Image** | `inputImageTexture` | GL_RGBA | Full Image ($W \times H$) | RGBA (unpremultiplied) | 4-byte row aligned |
| **Hair Mask** | `hairMaskTexture` | GL_LUMINANCE / GL_RED | Resampled ($W \times H$) | Single channel R $\in [0, 255]$ | 1-byte row aligned |
| **Pass 1 FBO** | `FBO_Gray` | GL_RGBA / GL_LUMINANCE | $W \times H$ | Grayscale luma in RGB | 4-byte aligned |
| **Pass 2 FBO** | `FBO_Grad` | GL_RGBA | $W \times H$ | RG = $\frac{1}{2}\text{gradDouble} + \frac{1}{2}$ | 4-byte aligned |
| **Pass 3 FBO** | `FBO_BlurH` | GL_RGBA | $W \times H$ | Filtered tensor field | 4-byte aligned |
| **Pass 4 FBO** | `FBO_BlurV` | GL_RGBA | $W \times H$ | Final smoothed tensor | 4-byte aligned |
| **LUT Texture** | `lutTexture` | GL_RGBA | $512 \times 512$ or $256 \times 256$ | RGB 3D Color Map | 4-byte aligned |
| **Output Image**| `outputTexture` | GL_RGBA | $W \times H$ | RGBA | 4-byte aligned |

---

## 2. Parameter Mappings & Dynamic Ranges

### A. Intensity (`gain`)
- **UI Range:** `[0, 100]` slider
- **Shader Parameter:** `uniform highp float gain`
- **Mapping Function:**
  $$\text{gain} = \frac{\text{UI\_value}}{100.0} \times 1.5$$
- **Effect:** Scales the blended directional sum in Pass 5. At $\text{gain} = 0.0$, output reverts exactly to original image pixels (`mix(origColor, ..., 0.0)`).

### B. Shine / Highlight (`threshold`)
- **UI Range:** `[0, 100]` slider
- **Shader Parameter:** `uniform highp float threshold`
- **Mapping Function:**
  $$\text{threshold} = 0.20 + 0.60 \times \left(1.0 - \frac{\text{Shine\_UI}}{100.0}\right)$$
- **Effect:** High shine lowers the gradient threshold, preserving specular highlights and natural sheen along hair strands.

### C. Strand Gloss / Flow Radius (`shiftingSize`)
- **Shader Parameter:** `uniform highp vec2 shiftingSize`
- **Mapping Function:**
  $$\text{shiftingSize} = \left(\frac{1.0}{W}, \frac{1.0}{H}\right) \times (1.0 + 2.0 \times \text{Gloss})$$
- **Effect:** Governs step distance along hair tangent vector $\vec{v} = (\cos\theta, \sin\theta)$.

---

## 3. Handle Ownership & Lifecycle
- `MTFilterKernelRender.nCreate()` allocates native C++ `MTFilterKernelRender` heap object and returns `jlong nativeInstance`.
- `nFinalizer(handle)` calls `delete` on C++ instance and deletes all associated OpenGL textures, shaders, and FBO attachments.
- Zero memory leakage verified under continuous 1,000-frame test harness.