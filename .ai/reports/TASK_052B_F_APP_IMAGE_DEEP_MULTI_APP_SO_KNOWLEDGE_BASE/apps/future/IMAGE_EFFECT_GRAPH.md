# Image Effect Graph: Future Self Aging

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Face Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for Future Self Aging
- **Primary Domain**: Face
- **Framework**: libucrop.so + libamg.so
- **AI Integration**: Cloud Aging API + Local Facial Landmark Preprocessing
