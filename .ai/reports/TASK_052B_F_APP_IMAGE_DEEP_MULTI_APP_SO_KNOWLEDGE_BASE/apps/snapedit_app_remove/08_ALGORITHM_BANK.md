# Algorithm Bank: SnapEdit - AI Photo Editor & Object Removal

### Recovered Algorithms & Architectural Primitives

1. **Primary Domain:** `AI Object Removal & Inpainting`
2. **AI Inference Framework:** `TensorFlow Lite Mobile (4.3 MB) + Cloud Inpainting Diffusion` (Libraries: `libpairipcore.so, libtensorflowlite_jni.so`)
3. **Graphics Core:** `Xeno Native Core (21.7 MB) + FFmpeg Suite (AVCodec 13.5 MB)` (Libraries: `libavfilter.so, libsurface_util_jni.so`)

### Core Mathematical Primitives
- **Spatial Filtering:** Multi-pass Gaussian & Bilateral smoothing for texture preservation.
- **Mesh Deformation:** Thin Plate Splines (TPS) / Radial Basis Function (RBF) landmark warps.
- **Color Space Math:** Tetrahedral 3D LUT interpolation with Display-P3 gamut preservation.
