# Image & Video Effect Graph: Adobe Lightroom Mobile (Uptodown Distribution Package)

```mermaid
graph TD
  UI[Adobe Lightroom Mobile (Uptodown Distribution Package) UI Layer] -->|User Parameter| JNI[DEX JNI Bridge]
  JNI -->|Native Call| CORE[AndroidX Graphics Path + Jetpack Compose Hybrid]
  CORE -->|Feature Vector| AI[Uptodown Native Services + AndroidX DataStore]
  AI -->|Landmark & Matte Mask| COMP[Compositor & Shader Stage]
  COMP -->|FBO Texture| DISP[SurfaceView / Hardware Display]
```

### Pipeline Stage Analysis
1. **Input & Parameter Normalization:** User adjustments from `Adobe Lightroom Mobile (Uptodown Distribution Package)` UI are marshaled into C++ structs.
2. **Vision Preprocessing:** `Uptodown Native Services + AndroidX DataStore` performs landmark alignment, bounding box crop, and segmentation.
3. **Shader Transformation:** Core shaders apply pixel transforms (color space conversion, LUT mapping, mesh warping).
4. **Compositing:** Multi-layer blending combines base image, effect matte, and highlight passes.
