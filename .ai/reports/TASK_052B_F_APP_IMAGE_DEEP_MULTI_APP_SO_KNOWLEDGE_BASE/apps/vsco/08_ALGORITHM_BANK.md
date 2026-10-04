# Algorithm Bank: VSCO: Photo & Video Editor

### Recovered Algorithms & Architectural Primitives

1. **Primary Domain:** `Film Emulation & Color Grading`
2. **AI Inference Framework:** `Google ML Kit Common Pipeline + TensorFlow Lite` (Libraries: `libtensorflowlite_jni.so`)
3. **Graphics Core:** `VSCOCore C++ (6.9 MB) + Rust UniFFI (2.1 MB) + FraggleRock` (Libraries: `libvscocore.so`)

### Core Mathematical Primitives
- **Spatial Filtering:** Multi-pass Gaussian & Bilateral smoothing for texture preservation.
- **Mesh Deformation:** Thin Plate Splines (TPS) / Radial Basis Function (RBF) landmark warps.
- **Color Space Math:** Tetrahedral 3D LUT interpolation with Display-P3 gamut preservation.
