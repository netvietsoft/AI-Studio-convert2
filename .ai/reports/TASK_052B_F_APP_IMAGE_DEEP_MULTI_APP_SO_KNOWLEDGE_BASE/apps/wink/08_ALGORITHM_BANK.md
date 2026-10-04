# Algorithm Bank: Wink - Video Retouching & AI

### Recovered Algorithms & Architectural Primitives

1. **Primary Domain:** `AI Video Portrait Retouching`
2. **AI Inference Framework:** `Meitu Vision Language AI (VLAI 18.9 MB) + Manis (10.5 MB) + ARKernel3 (18.1 MB)` (Libraries: `libAIModelKit.so, libManis.so, libaidetectionplugin.so, libhiai.so, libhiai_ir.so, libhiai_ir_build.so, libmanis_npu_adapter.so`)
3. **Graphics Core:** `MTMVCore (6.1 MB) + MTAurora (5.8 MB) + PVG Suite` (Libraries: `libARSPM.so, libPVGColorFunctions.so, libVERenderer.so, libarkernel3.so, libarkernel3_android.so`)

### Core Mathematical Primitives
- **Spatial Filtering:** Multi-pass Gaussian & Bilateral smoothing for texture preservation.
- **Mesh Deformation:** Thin Plate Splines (TPS) / Radial Basis Function (RBF) landmark warps.
- **Color Space Math:** Tetrahedral 3D LUT interpolation with Display-P3 gamut preservation.
