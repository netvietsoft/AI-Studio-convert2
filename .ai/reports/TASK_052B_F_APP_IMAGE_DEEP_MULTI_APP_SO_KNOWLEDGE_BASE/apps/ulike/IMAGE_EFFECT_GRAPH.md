# Image Effect Graph: Ulike

```mermaid
flowchart TD
    A[Input Bitmap / Camera Stream] --> B[Color Space Decode: sRGB / Display-P3]
    B --> C[AI Preprocessing & Landmark Tracking]
    C --> D[Hair Core Processing Engine]
    D --> E[FBO Render & Multi-pass Compositing]
    E --> F[Output Post-process: Tone Curve & Unsharp Mask]
    F --> G[Display Surface / PNG Encode]
```

### Pipeline Details for Ulike
- **Primary Domain**: Hair
- **Framework**: libeffect.so (EffectSDK) + libAGFX.so + libbrushEngine.so + libttvesdk.so
- **AI Integration**: ByteNN (libbytenn.so) + Amazing Graphics Engine
