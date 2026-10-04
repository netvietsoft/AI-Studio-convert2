# Image Effect Graph: PicsArt

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Retouch Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for PicsArt
- **Primary Domain**: Retouch
- **Framework**: libgecore.so + libsmudgetool.so + libbucketfill.so + libnative-filters.so
- **AI Integration**: PicsArt AI Pipeline + Fresco Native Image Pipeline
