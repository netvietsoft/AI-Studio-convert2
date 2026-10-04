# 14 — HAIR PARAMETER AND DATA FLOW SPECIFICATION

**Task ID:** TASK_038_45_SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION_ACTIVE  

---

## 1. PARAMETER SPECIFICATION

| Parameter | Type | Valid Range | Default | Function |
|---|---|---|---|---|
| `shiftingSize` | `highp vec2` | `[1/W, 1/H]` | `(1/1024, 1/1024)` | Step size for gradient tensor and directional sampling |
| `threshold` | `highp float` | `[0.0, 1.0]` | `0.05` | Gradient noise floor gate (prevents blur in flat non-hair areas) |
| `gain` | `highp float` | `[0.0, 2.0]` | `1.0` | Directional filter blend amplification |
| `kernel[10]` | `highp float[10]` | Normalized | Gaussian | 10-tap Gaussian kernel weights along the strand orientation |
| `Weights[5]` | `highp float[5]` | $\sum = 1.0$ | `[0.227, 0.194, 0.121, 0.054, 0.016]` | Separable Gaussian blur weights |
| `Offsets[5]` | `highp float[5]` | Pixels | `[0.0, 1.38, 3.23, 5.07, 6.92] * stride` | Linear texture sampling offsets |
| `hairMask` | Texture | `[0, 255]` | - | 8-bit single channel hair segmentation mask |

---

## 2. BUFFER FORMATS & MEMORY OWNERSHIP
1. **Input Image Buffer:** `ARGB_8888` / `RGBA_8888`, stride = `width * 4`.
2. **Hair Mask Buffer:** Single-channel 8-bit grayscale (`GL_LUMINANCE` or `GL_RED`). Resampled bilinearly to match frame dimensions.
3. **Structure Tensor FBO:** 2-channel `GL_RG16F` or `GL_RG8` storing angle-doubled gradient orientation $(\cos 2	heta, \sin 2	heta)$.
4. **Intermediate FBOs:** Ping-pong framebuffers owned by `GPUImageFramebufferManager`. Zero memory leak upon `destroy()`.