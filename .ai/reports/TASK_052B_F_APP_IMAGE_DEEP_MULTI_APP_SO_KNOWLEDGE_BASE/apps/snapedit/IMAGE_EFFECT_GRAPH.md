# Image Effect Graph: SnapEdit

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Inpaint Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for SnapEdit
- **Primary Domain**: Inpaint
- **Framework**: libavcodec.so + libavfilter.so + libavformat.so + libswscale.so
- **AI Integration**: MediaPipe SelfieSegmentation FP16 + MobileNetV2 Text Detector
