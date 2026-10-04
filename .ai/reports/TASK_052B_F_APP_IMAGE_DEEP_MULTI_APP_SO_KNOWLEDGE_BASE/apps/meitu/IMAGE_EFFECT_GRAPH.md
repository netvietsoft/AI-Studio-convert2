# Image Effect Graph: Meitu

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Hair Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for Meitu
- **Primary Domain**: Hair
- **Framework**: libMTFilterKernel.so (5-pass LIC) + libVERenderer.so + libLayerFlow.so
- **AI Integration**: Manis NCNN/MNN Engine + BiSeNet 19-class + AIModelKit
