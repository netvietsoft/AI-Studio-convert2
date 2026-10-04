# Image Effect Graph: FaceApp

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Hair Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for FaceApp
- **Primary Domain**: Hair
- **Framework**: OpenGL ES FBO Blending + Android Canvas
- **AI Integration**: FaceSSD Local Landmark Tracker + Server Neural Generative Pipeline
