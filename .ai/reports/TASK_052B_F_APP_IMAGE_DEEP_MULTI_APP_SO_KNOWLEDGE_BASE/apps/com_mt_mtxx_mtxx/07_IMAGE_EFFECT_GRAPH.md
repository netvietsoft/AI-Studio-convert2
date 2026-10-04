# Image & Video Effect Graph: Meitu (Xiuxiu) Photo & Video Editor

```mermaid
graph TD
  UI[Meitu (Xiuxiu) Photo & Video Editor UI Layer] -->|User Parameter| JNI[DEX JNI Bridge]
  JNI -->|Native Call| CORE[MTFilterKernel (1.85 MB) + LayerFlow (890 KB) + PVGColorFunctions (412 KB)]
  CORE -->|Feature Vector| AI[Manis NPU (3.4 MB) + ARKernel3 (17.8 MB) + BiSeNet CelebAMask-HQ]
  AI -->|Landmark & Matte Mask| COMP[Compositor & Shader Stage]
  COMP -->|FBO Texture| DISP[SurfaceView / Hardware Display]
```

### Pipeline Stage Analysis
1. **Input & Parameter Normalization:** User adjustments from `Meitu (Xiuxiu) Photo & Video Editor` UI are marshaled into C++ structs.
2. **Vision Preprocessing:** `Manis NPU (3.4 MB) + ARKernel3 (17.8 MB) + BiSeNet CelebAMask-HQ` performs landmark alignment, bounding box crop, and segmentation.
3. **Shader Transformation:** Core shaders apply pixel transforms (color space conversion, LUT mapping, mesh warping).
4. **Compositing:** Multi-layer blending combines base image, effect matte, and highlight passes.
