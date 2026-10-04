# Algorithm Bank: Picsart AI Photo Editor & Video

### Recovered Algorithms & Architectural Primitives

1. **Primary Domain:** `All-in-One Photo/Video Studio`
2. **AI Inference Framework:** `Picsart Pilibs AI Vision + Cloud Diffusion` (Libraries: `Integrated / Server`)
3. **Graphics Core:** `Pilibs Core C++ + Native Filters + BucketFill + Smudge` (Libraries: `libbucketfill.so, libnative-filters.so, libpilibs.so, libsmudgetool.so`)

### Core Mathematical Primitives
- **Spatial Filtering:** Multi-pass Gaussian & Bilateral smoothing for texture preservation.
- **Mesh Deformation:** Thin Plate Splines (TPS) / Radial Basis Function (RBF) landmark warps.
- **Color Space Math:** Tetrahedral 3D LUT interpolation with Display-P3 gamut preservation.
