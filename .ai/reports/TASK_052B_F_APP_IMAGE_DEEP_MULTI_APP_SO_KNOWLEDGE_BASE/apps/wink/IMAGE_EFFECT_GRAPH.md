# Image Effect Graph: Wink

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Hair Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for Wink
- **Primary Domain**: Hair
- **Framework**: libVERenderer.so + libmtmvcore.so + libarkernel3.so + libPVGColorFunctions.so
- **AI Integration**: Manis NPU Engine + libaidetectionplugin.so + libAIModelKit.so
