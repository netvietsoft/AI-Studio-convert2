# Image & Video Effect Graph: Wink - Video Retouching & AI

```mermaid
graph TD
  UI[Wink - Video Retouching & AI UI Layer] -->|User Parameter| JNI[DEX JNI Bridge]
  JNI -->|Native Call| CORE[MTMVCore (6.1 MB) + MTAurora (5.8 MB) + PVG Suite]
  CORE -->|Feature Vector| AI[Meitu Vision Language AI (VLAI 18.9 MB) + Manis (10.5 MB) + ARKernel3 (18.1 MB)]
  AI -->|Landmark & Matte Mask| COMP[Compositor & Shader Stage]
  COMP -->|FBO Texture| DISP[SurfaceView / Hardware Display]
```

### Pipeline Stage Analysis
1. **Input & Parameter Normalization:** User adjustments from `Wink - Video Retouching & AI` UI are marshaled into C++ structs.
2. **Vision Preprocessing:** `Meitu Vision Language AI (VLAI 18.9 MB) + Manis (10.5 MB) + ARKernel3 (18.1 MB)` performs landmark alignment, bounding box crop, and segmentation.
3. **Shader Transformation:** Core shaders apply pixel transforms (color space conversion, LUT mapping, mesh warping).
4. **Compositing:** Multi-layer blending combines base image, effect matte, and highlight passes.
