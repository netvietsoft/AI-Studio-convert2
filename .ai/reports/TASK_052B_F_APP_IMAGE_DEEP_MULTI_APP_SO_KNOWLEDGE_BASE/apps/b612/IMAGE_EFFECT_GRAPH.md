# Image Effect Graph: B612

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Face Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for B612
- **Primary Domain**: Face
- **Framework**: libb612_glnativehelper.so + libst_mobile.so (SenseTime)
- **AI Integration**: TensorFlow Lite + SenseTime STMobile SDK
