# Image Effect Graph: VSCO

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Color Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for VSCO
- **Primary Domain**: Color
- **Framework**: libvscocore.so + libfragglerock.so + libuniffi_cel.so
- **AI Integration**: TensorFlow Lite + MLKit Common Pipeline
