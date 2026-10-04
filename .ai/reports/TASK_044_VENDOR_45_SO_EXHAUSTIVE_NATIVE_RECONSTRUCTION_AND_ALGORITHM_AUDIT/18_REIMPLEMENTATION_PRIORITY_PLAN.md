# TASK_044 — CLEAN-ROOM REIMPLEMENTATION PRIORITY PLAN

Based on exhaustive analysis of all 45 vendor libraries, the clean-room reimplementation priority for CONVERT2 is:

1. **Phase 1: Soft Light Hair Dye GPU Shader (Vulkan Compute):** Port `MTFilter_PsSoftLightr.fs` blending algorithm directly to Vulkan compute shader `vulkan_hair_pipeline.comp`.
2. **Phase 2: Separable 2-Pass Gaussian Mask Feathering:** Port `BlurHFilterToFBO` and `BlurVFilterToFBO` to Vulkan compute for subpixel edge transition.
3. **Phase 3: Soft-Knee Tanh Chroma Compression:** Integrate the verified saturation compression algorithm from `libPVGColorFunctions.so`.
4. **Phase 4: Multi-Layer Compositing Engine:** Adapt the DAG modular structure from `libLayerFlow.so` to orchestrate multi-preset hair dyeing.
