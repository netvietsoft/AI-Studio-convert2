# Algorithm Bank: BeautyPlus - Easy Photo Editor

### Recovered Algorithms & Architectural Primitives

1. **Primary Domain:** `Selfie Retouch & Makeup`
2. **AI Inference Framework:** `Meitu Manis + MTAiInterface + ARSPM` (Libraries: `libAIModelKit.so, libAIModelSearchKit.so, libManis.so, libaicodec.so, libaidetectionplugin.so, libhiai.so, libhiai_ir.so, libhiai_ir_build.so, libmanis_npu_adapter.so`)
3. **Graphics Core:** `PixRenderCore + MTFilterKernel + MTRTEffectCore` (Libraries: `libARKernelInterface.so, libARSPM.so, libMT3DFaceJNI.so, libMTAiInterface.so, libMTFilterKernel.so`)

### Core Mathematical Primitives
- **Spatial Filtering:** Multi-pass Gaussian & Bilateral smoothing for texture preservation.
- **Mesh Deformation:** Thin Plate Splines (TPS) / Radial Basis Function (RBF) landmark warps.
- **Color Space Math:** Tetrahedral 3D LUT interpolation with Display-P3 gamut preservation.
