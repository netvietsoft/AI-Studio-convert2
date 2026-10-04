# Image & Video Effect Graph: B612 AI Photo & Video Editor

```mermaid
graph TD
  UI[B612 AI Photo & Video Editor UI Layer] -->|User Parameter| JNI[DEX JNI Bridge]
  JNI -->|Native Call| CORE[B612 GLNativeHelper + OpenCV 4.x]
  CORE -->|Feature Vector| AI[SenseTime Mobile (STMobile 240-pts) + TensorFlow Lite]
  AI -->|Landmark & Matte Mask| COMP[Compositor & Shader Stage]
  COMP -->|FBO Texture| DISP[SurfaceView / Hardware Display]
```

### Pipeline Stage Analysis
1. **Input & Parameter Normalization:** User adjustments from `B612 AI Photo & Video Editor` UI are marshaled into C++ structs.
2. **Vision Preprocessing:** `SenseTime Mobile (STMobile 240-pts) + TensorFlow Lite` performs landmark alignment, bounding box crop, and segmentation.
3. **Shader Transformation:** Core shaders apply pixel transforms (color space conversion, LUT mapping, mesh warping).
4. **Compositing:** Multi-layer blending combines base image, effect matte, and highlight passes.
