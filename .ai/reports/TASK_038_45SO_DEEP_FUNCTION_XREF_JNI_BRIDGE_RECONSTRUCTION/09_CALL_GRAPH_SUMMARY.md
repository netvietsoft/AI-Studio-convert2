# TASK_038 — CALL GRAPH ARCHITECTURE SUMMARY

## Subsystem Call Graph Decomposition

1. **Core Graphics & Filter Cluster (10 SOs):**
   - `libMTFilterKernel.so` -> Entry `JNI_OnLoad` -> Registers `MTFilterKernelFaceData` (25 methods) and `MTFilterKernelRender` (17 methods).
   - `nRenderToOutTexture` -> calls internal shader blit pipeline -> `MTFilter_PsSoftLightr` -> FBO swap.

2. **Computer Vision & Neural Inference (8 SOs):**
   - `libManis.so` -> High-performance neural inference engine (ARM64 FP16/Int8 execution). Consumes BiSeNet model tensors.

3. **Media & Color Processing (13 SOs):**
   - `libPVGColorFunctions.so` -> Gamut conversion matrices Display P3 <-> sRGB.

4. **AR & Face Makeup Cluster (5 SOs):**
   - `libarkernel3.so` & `libarkernel3_android.so` -> MakeupHairSoftPart, hair shine and gloss parameters.

5. **Layer Flow Compositing (9 SOs):**
   - `libLayerFlow.so` -> DenseHairModular (31 tables, 1,907 methods) managing hair dye config and strand alpha.
