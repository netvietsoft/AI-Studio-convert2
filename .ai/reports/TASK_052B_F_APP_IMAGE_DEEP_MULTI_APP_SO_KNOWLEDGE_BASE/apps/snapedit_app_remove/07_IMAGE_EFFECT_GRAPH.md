# Image & Video Effect Graph: SnapEdit - AI Photo Editor & Object Removal

```mermaid
graph TD
  UI[SnapEdit - AI Photo Editor & Object Removal UI Layer] -->|User Parameter| JNI[DEX JNI Bridge]
  JNI -->|Native Call| CORE[Xeno Native Core (21.7 MB) + FFmpeg Suite (AVCodec 13.5 MB)]
  CORE -->|Feature Vector| AI[TensorFlow Lite Mobile (4.3 MB) + Cloud Inpainting Diffusion]
  AI -->|Landmark & Matte Mask| COMP[Compositor & Shader Stage]
  COMP -->|FBO Texture| DISP[SurfaceView / Hardware Display]
```

### Pipeline Stage Analysis
1. **Input & Parameter Normalization:** User adjustments from `SnapEdit - AI Photo Editor & Object Removal` UI are marshaled into C++ structs.
2. **Vision Preprocessing:** `TensorFlow Lite Mobile (4.3 MB) + Cloud Inpainting Diffusion` performs landmark alignment, bounding box crop, and segmentation.
3. **Shader Transformation:** Core shaders apply pixel transforms (color space conversion, LUT mapping, mesh warping).
4. **Compositing:** Multi-layer blending combines base image, effect matte, and highlight passes.
