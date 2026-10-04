# Image & Video Effect Graph: BeautyPlus - Easy Photo Editor

```mermaid
graph TD
  UI[BeautyPlus - Easy Photo Editor UI Layer] -->|User Parameter| JNI[DEX JNI Bridge]
  JNI -->|Native Call| CORE[PixRenderCore + MTFilterKernel + MTRTEffectCore]
  CORE -->|Feature Vector| AI[Meitu Manis + MTAiInterface + ARSPM]
  AI -->|Landmark & Matte Mask| COMP[Compositor & Shader Stage]
  COMP -->|FBO Texture| DISP[SurfaceView / Hardware Display]
```

### Pipeline Stage Analysis
1. **Input & Parameter Normalization:** User adjustments from `BeautyPlus - Easy Photo Editor` UI are marshaled into C++ structs.
2. **Vision Preprocessing:** `Meitu Manis + MTAiInterface + ARSPM` performs landmark alignment, bounding box crop, and segmentation.
3. **Shader Transformation:** Core shaders apply pixel transforms (color space conversion, LUT mapping, mesh warping).
4. **Compositing:** Multi-layer blending combines base image, effect matte, and highlight passes.
