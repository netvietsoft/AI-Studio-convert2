# Image Effect Graph: Adobe Lightroom Mobile

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Color Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for Adobe Lightroom Mobile
- **Primary Domain**: Color
- **Framework**: libuptodown-native.so + libutd-services-native.so (Container Stub)
- **AI Integration**: Cloud ACR Backend (On-device native ACR core packaged in separate split)
