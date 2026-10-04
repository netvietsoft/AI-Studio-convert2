# Image & Video Effect Graph: VSCO: Photo & Video Editor

```mermaid
graph TD
  UI[VSCO: Photo & Video Editor UI Layer] -->|User Parameter| JNI[DEX JNI Bridge]
  JNI -->|Native Call| CORE[VSCOCore C++ (6.9 MB) + Rust UniFFI (2.1 MB) + FraggleRock]
  CORE -->|Feature Vector| AI[Google ML Kit Common Pipeline + TensorFlow Lite]
  AI -->|Landmark & Matte Mask| COMP[Compositor & Shader Stage]
  COMP -->|FBO Texture| DISP[SurfaceView / Hardware Display]
```

### Pipeline Stage Analysis
1. **Input & Parameter Normalization:** User adjustments from `VSCO: Photo & Video Editor` UI are marshaled into C++ structs.
2. **Vision Preprocessing:** `Google ML Kit Common Pipeline + TensorFlow Lite` performs landmark alignment, bounding box crop, and segmentation.
3. **Shader Transformation:** Core shaders apply pixel transforms (color space conversion, LUT mapping, mesh warping).
4. **Compositing:** Multi-layer blending combines base image, effect matte, and highlight passes.
