# 14 — HAIR RECOLOR PARAMETER RANGES & BUFFER DATA FLOW

### 1. JNI Input Parameter Ranges
- **`intensity`**: Float [0.0, 1.0] (UI slider 0..100 divided by 100). Default: 0.75 for Rose Gold.
- **`shine`**: Float [0.0, 1.0] (Controls specular curve multiplier in `s_lightLutMap`).
- **`gloss`**: Float [0.0, 1.0] (Controls micro-contrast highlight preservation).
- **`smearMaskColor`**: RGBA float vector `[r, g, b, a]` normalized to [0.0, 1.0].

### 2. Buffer & Pixel Formats
- **Source Image**: `RGBA_8888` (32-bit unsigned, row stride = width * 4).
- **Neural Segmentation Matte**: `ALPHA_8` / `R8` (single channel 8-bit, 0..255).
- **Intermediate Render Buffers**: GL FBO texture attachments (`GL_RGBA` / `GL_RGBA8`).
- **Feathered Mask Buffers**: Intermediate ping-pong FBOs (`BlurH` and `BlurV`).
