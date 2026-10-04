# Algorithm Bank: Meitu (Xiuxiu) Photo & Video Editor

### Recovered Algorithms & Architectural Primitives

1. **Primary Domain:** `Flagship Beauty & Hair Color Engine`
2. **AI Inference Framework:** `Manis NPU (3.4 MB) + ARKernel3 (17.8 MB) + BiSeNet CelebAMask-HQ` (Libraries: `libAIModelKit.so, libAIModelSearchKit.so, libManis.so, libaicodec.so, libaidetectionplugin.so, libhiai.so, libhiai_ir.so, libhiai_ir_build.so, libmanis_npu_adapter.so`)
3. **Graphics Core:** `MTFilterKernel (1.85 MB) + LayerFlow (890 KB) + PVGColorFunctions (412 KB)` (Libraries: `libARKernelInterface.so, libARSPM.so, libLayerFlow.so, libMTFilterKernel.so, libPVGColorFunctions.so`)

### Core Mathematical Primitives
- **Spatial Filtering:** Multi-pass Gaussian & Bilateral smoothing for texture preservation.
- **Mesh Deformation:** Thin Plate Splines (TPS) / Radial Basis Function (RBF) landmark warps.
- **Color Space Math:** Tetrahedral 3D LUT interpolation with Display-P3 gamut preservation.
