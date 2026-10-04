# Image Effect Graph: Remini

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Texture Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for Remini
- **Primary Domain**: Texture
- **Framework**: libjavet-v8-android.so + libbuffer.so
- **AI Integration**: Microsoft ONNX Runtime (libonnxruntime.so) + Cloud Super-Resolution
