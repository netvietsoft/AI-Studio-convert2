# Image Effect Graph: BeautyPlus

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Hair Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for BeautyPlus
- **Primary Domain**: Hair
- **Framework**: libMTFilterKernel.so + libVERenderer.so + libPixRenderCore.so
- **AI Integration**: Manis NPU Adapter + libaidetectionplugin.so + libAIModelKit.so
