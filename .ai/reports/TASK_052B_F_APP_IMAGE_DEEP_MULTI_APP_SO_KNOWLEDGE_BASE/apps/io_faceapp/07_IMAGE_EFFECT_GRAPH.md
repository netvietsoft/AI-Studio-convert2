# Image & Video Effect Graph: FaceApp: Perfect Face Editor

```mermaid
graph TD
  UI[FaceApp: Perfect Face Editor UI Layer] -->|User Parameter| JNI[DEX JNI Bridge]
  JNI -->|Native Call| CORE[Dynamic Split Feature Delivery + Native Android ExoPlayer]
  CORE -->|Feature Vector| AI[Cloud Neural Generative Face Server (REST/WebSocket API)]
  AI -->|Landmark & Matte Mask| COMP[Compositor & Shader Stage]
  COMP -->|FBO Texture| DISP[SurfaceView / Hardware Display]
```

### Pipeline Stage Analysis
1. **Input & Parameter Normalization:** User adjustments from `FaceApp: Perfect Face Editor` UI are marshaled into C++ structs.
2. **Vision Preprocessing:** `Cloud Neural Generative Face Server (REST/WebSocket API)` performs landmark alignment, bounding box crop, and segmentation.
3. **Shader Transformation:** Core shaders apply pixel transforms (color space conversion, LUT mapping, mesh warping).
4. **Compositing:** Multi-layer blending combines base image, effect matte, and highlight passes.
