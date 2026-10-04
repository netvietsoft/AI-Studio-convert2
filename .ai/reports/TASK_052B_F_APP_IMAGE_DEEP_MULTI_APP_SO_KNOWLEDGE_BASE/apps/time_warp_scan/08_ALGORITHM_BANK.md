# Algorithm Bank: Time Warp Scan - Face Scan

### Recovered Algorithms & Architectural Primitives

1. **Primary Domain:** `Creative Slit-Scan Video Filter`
2. **AI Inference Framework:** `Alibaba MNN Engine + Face Landmarks (91 KB)` (Libraries: `libMNN.so`)
3. **Graphics Core:** `CVAlgo Slit-Scan Slit Buffer + Flutter Engine` (Libraries: `libcvalgo.so, libfacelandmarks.so, libsurface_util_jni.so`)

### Core Mathematical Primitives
- **Spatial Filtering:** Multi-pass Gaussian & Bilateral smoothing for texture preservation.
- **Mesh Deformation:** Thin Plate Splines (TPS) / Radial Basis Function (RBF) landmark warps.
- **Color Space Math:** Tetrahedral 3D LUT interpolation with Display-P3 gamut preservation.
