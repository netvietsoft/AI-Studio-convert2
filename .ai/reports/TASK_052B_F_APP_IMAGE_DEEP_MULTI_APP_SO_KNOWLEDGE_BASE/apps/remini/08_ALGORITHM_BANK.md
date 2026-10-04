# Algorithm Bank: Remini - AI Photo Enhancer

### Recovered Algorithms & Architectural Primitives

1. **Primary Domain:** `AI Super-Resolution & Restoration`
2. **AI Inference Framework:** `ONNX Runtime Mobile (19.3 MB) + Javet V8 Runtime (69.0 MB)` (Libraries: `libonnxruntime.so, libonnxruntime4j_jni.so`)
3. **Graphics Core:** `ONNX Tile Super-Resolution Pipeline + ByteDance PGL` (Libraries: `Native System Stack`)

### Core Mathematical Primitives
- **Spatial Filtering:** Multi-pass Gaussian & Bilateral smoothing for texture preservation.
- **Mesh Deformation:** Thin Plate Splines (TPS) / Radial Basis Function (RBF) landmark warps.
- **Color Space Math:** Tetrahedral 3D LUT interpolation with Display-P3 gamut preservation.
