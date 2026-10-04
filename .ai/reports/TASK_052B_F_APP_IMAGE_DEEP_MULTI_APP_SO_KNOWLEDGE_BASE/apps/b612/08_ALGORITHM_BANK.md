# Algorithm Bank: B612 AI Photo & Video Editor

### Recovered Algorithms & Architectural Primitives

1. **Primary Domain:** `Camera & Portrait Beauty`
2. **AI Inference Framework:** `SenseTime Mobile (STMobile 240-pts) + TensorFlow Lite` (Libraries: `libpairipcore.so, libtensorflowlite_c.so, libtensorflowlite_gpu_delegate.so`)
3. **Graphics Core:** `B612 GLNativeHelper + OpenCV 4.x` (Libraries: `libst_mobile.so, libsurface_util_jni.so`)

### Core Mathematical Primitives
- **Spatial Filtering:** Multi-pass Gaussian & Bilateral smoothing for texture preservation.
- **Mesh Deformation:** Thin Plate Splines (TPS) / Radial Basis Function (RBF) landmark warps.
- **Color Space Math:** Tetrahedral 3D LUT interpolation with Display-P3 gamut preservation.
