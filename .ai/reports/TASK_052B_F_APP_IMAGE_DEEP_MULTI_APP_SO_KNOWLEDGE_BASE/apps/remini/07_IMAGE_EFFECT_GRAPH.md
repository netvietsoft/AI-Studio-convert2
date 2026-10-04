# Image & Video Effect Graph: Remini - AI Photo Enhancer

```mermaid
graph TD
  UI[Remini - AI Photo Enhancer UI Layer] -->|User Parameter| JNI[DEX JNI Bridge]
  JNI -->|Native Call| CORE[ONNX Tile Super-Resolution Pipeline + ByteDance PGL]
  CORE -->|Feature Vector| AI[ONNX Runtime Mobile (19.3 MB) + Javet V8 Runtime (69.0 MB)]
  AI -->|Landmark & Matte Mask| COMP[Compositor & Shader Stage]
  COMP -->|FBO Texture| DISP[SurfaceView / Hardware Display]
```

### Pipeline Stage Analysis
1. **Input & Parameter Normalization:** User adjustments from `Remini - AI Photo Enhancer` UI are marshaled into C++ structs.
2. **Vision Preprocessing:** `ONNX Runtime Mobile (19.3 MB) + Javet V8 Runtime (69.0 MB)` performs landmark alignment, bounding box crop, and segmentation.
3. **Shader Transformation:** Core shaders apply pixel transforms (color space conversion, LUT mapping, mesh warping).
4. **Compositing:** Multi-layer blending combines base image, effect matte, and highlight passes.
