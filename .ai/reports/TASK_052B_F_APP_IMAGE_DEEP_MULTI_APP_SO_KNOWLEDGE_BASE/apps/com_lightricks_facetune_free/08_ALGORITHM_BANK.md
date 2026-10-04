# Algorithm Bank: Facetune: Hair & Photo Editor

### Recovered Algorithms & Architectural Primitives

1. **Primary Domain:** `Portrait Retouch, Hair Color & Reshape`
2. **AI Inference Framework:** `Facetune 3DMM Face Reconstruction + TFLite SelfieSeg (249 KB) + FSSD` (Libraries: `libtensorflowlite_gpu_jni.so, libtensorflowlite_jni.so`)
3. **Graphics Core:** `Render Core (735 KB) + TechTransfer ColorTransfer + VideoEngine + Xeno` (Libraries: `libface_detector_v2_jni.so, libfacetune.so, librender.so, libsurface_util_jni.so, libtech_transfer_color_transfer.so`)

### Core Mathematical Primitives
- **Spatial Filtering:** Multi-pass Gaussian & Bilateral smoothing for texture preservation.
- **Mesh Deformation:** Thin Plate Splines (TPS) / Radial Basis Function (RBF) landmark warps.
- **Color Space Math:** Tetrahedral 3D LUT interpolation with Display-P3 gamut preservation.
