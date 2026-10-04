# Image & Video Effect Graph: Facetune: Hair & Photo Editor

```mermaid
graph TD
  UI[Facetune: Hair & Photo Editor UI Layer] -->|User Parameter| JNI[DEX JNI Bridge]
  JNI -->|Native Call| CORE[Render Core (735 KB) + TechTransfer ColorTransfer + VideoEngine + Xeno]
  CORE -->|Feature Vector| AI[Facetune 3DMM Face Reconstruction + TFLite SelfieSeg (249 KB) + FSSD]
  AI -->|Landmark & Matte Mask| COMP[Compositor & Shader Stage]
  COMP -->|FBO Texture| DISP[SurfaceView / Hardware Display]
```

### Pipeline Stage Analysis
1. **Input & Parameter Normalization:** User adjustments from `Facetune: Hair & Photo Editor` UI are marshaled into C++ structs.
2. **Vision Preprocessing:** `Facetune 3DMM Face Reconstruction + TFLite SelfieSeg (249 KB) + FSSD` performs landmark alignment, bounding box crop, and segmentation.
3. **Shader Transformation:** Core shaders apply pixel transforms (color space conversion, LUT mapping, mesh warping).
4. **Compositing:** Multi-layer blending combines base image, effect matte, and highlight passes.
