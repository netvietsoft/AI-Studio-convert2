# Image Effect Graph: Facetune

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Hair Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for Facetune
- **Primary Domain**: Hair
- **Framework**: libfacetune.so + librender.so + libfs-native.so
- **AI Integration**: TensorFlow Lite + MediaPipe SelfieSegmentation FP16 + FaceSSD
