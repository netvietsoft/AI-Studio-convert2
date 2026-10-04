# Image Effect Graph: Time Warp Scan

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Face Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for Time Warp Scan
- **Primary Domain**: Face
- **Framework**: libhscore.so + libcvalgo.so + OpenGL ES
- **AI Integration**: Alibaba MNN (libMNN.so) + libfacelandmarks.so
