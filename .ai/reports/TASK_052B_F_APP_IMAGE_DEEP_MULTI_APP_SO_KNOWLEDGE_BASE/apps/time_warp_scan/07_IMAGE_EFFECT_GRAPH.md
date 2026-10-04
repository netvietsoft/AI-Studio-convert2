# Image & Video Effect Graph: Time Warp Scan - Face Scan

```mermaid
graph TD
  UI[Time Warp Scan - Face Scan UI Layer] -->|User Parameter| JNI[DEX JNI Bridge]
  JNI -->|Native Call| CORE[CVAlgo Slit-Scan Slit Buffer + Flutter Engine]
  CORE -->|Feature Vector| AI[Alibaba MNN Engine + Face Landmarks (91 KB)]
  AI -->|Landmark & Matte Mask| COMP[Compositor & Shader Stage]
  COMP -->|FBO Texture| DISP[SurfaceView / Hardware Display]
```

### Pipeline Stage Analysis
1. **Input & Parameter Normalization:** User adjustments from `Time Warp Scan - Face Scan` UI are marshaled into C++ structs.
2. **Vision Preprocessing:** `Alibaba MNN Engine + Face Landmarks (91 KB)` performs landmark alignment, bounding box crop, and segmentation.
3. **Shader Transformation:** Core shaders apply pixel transforms (color space conversion, LUT mapping, mesh warping).
4. **Compositing:** Multi-layer blending combines base image, effect matte, and highlight passes.
