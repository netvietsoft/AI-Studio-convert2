# Image & Video Effect Graph: Ulike - Define Your Spotless Selfie

```mermaid
graph TD
  UI[Ulike - Define Your Spotless Selfie UI Layer] -->|User Parameter| JNI[DEX JNI Bridge]
  JNI -->|Native Call| CORE[TTVESDK (9.8 MB) + BrushEngine + AGFX + AudioEffect]
  CORE -->|Feature Vector| AI[ByteDance EffectSDK (26.8 MB) + ByteNN (2.3 MB)]
  AI -->|Landmark & Matte Mask| COMP[Compositor & Shader Stage]
  COMP -->|FBO Texture| DISP[SurfaceView / Hardware Display]
```

### Pipeline Stage Analysis
1. **Input & Parameter Normalization:** User adjustments from `Ulike - Define Your Spotless Selfie` UI are marshaled into C++ structs.
2. **Vision Preprocessing:** `ByteDance EffectSDK (26.8 MB) + ByteNN (2.3 MB)` performs landmark alignment, bounding box crop, and segmentation.
3. **Shader Transformation:** Core shaders apply pixel transforms (color space conversion, LUT mapping, mesh warping).
4. **Compositing:** Multi-layer blending combines base image, effect matte, and highlight passes.
