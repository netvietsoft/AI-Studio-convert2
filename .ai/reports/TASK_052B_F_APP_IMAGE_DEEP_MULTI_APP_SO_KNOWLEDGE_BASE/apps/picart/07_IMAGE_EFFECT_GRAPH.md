# Image & Video Effect Graph: Picsart AI Photo Editor & Video

```mermaid
graph TD
  UI[Picsart AI Photo Editor & Video UI Layer] -->|User Parameter| JNI[DEX JNI Bridge]
  JNI -->|Native Call| CORE[Pilibs Core C++ + Native Filters + BucketFill + Smudge]
  CORE -->|Feature Vector| AI[Picsart Pilibs AI Vision + Cloud Diffusion]
  AI -->|Landmark & Matte Mask| COMP[Compositor & Shader Stage]
  COMP -->|FBO Texture| DISP[SurfaceView / Hardware Display]
```

### Pipeline Stage Analysis
1. **Input & Parameter Normalization:** User adjustments from `Picsart AI Photo Editor & Video` UI are marshaled into C++ structs.
2. **Vision Preprocessing:** `Picsart Pilibs AI Vision + Cloud Diffusion` performs landmark alignment, bounding box crop, and segmentation.
3. **Shader Transformation:** Core shaders apply pixel transforms (color space conversion, LUT mapping, mesh warping).
4. **Compositing:** Multi-layer blending combines base image, effect matte, and highlight passes.
