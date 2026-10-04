# 13 — HAIR LUT, ASSET & NEURAL MODEL DEPENDENCY GRAPH

| Asset Path | Type | Consumer Library / Class | Function / Stage |
|---|---|---|---|
| `ARKernel3Builtin/Shaders/HairSoft/MTFilter_HairSoftMix.fs` | Encrypted GLSL Fragment | `libarkernel3.so` (`MakeupHairSoftPart`) | Soft hair blend & highlight |
| `ARKernel3Builtin/Shaders/MTFilter_HairMaskMix.fs` | Encrypted GLSL Fragment | `libarkernel3.so` (`MakeupHairPart`) | Hair mask mixing |
| `beauty/hairGrow/hairSmear/ar_effect/.../genCurlHair.frag` | Obfuscated GLSL | `libLayerFlow.so` (`CLFDenseHairLayer`) | Hair daub & curling effect |
| `MTAurora.bundle/Shaders/hairmask_blur.fs.spirv` | Vulkan SPIR-V Binary | `libLayerFlow.so` | Real-time hair matte blur |
| `vlaimodel/libMerakInnovationHairFluffyStatic/...` | Neural Weight Package | `libManis.so` | Static fluffy hair inference |
| `vlaimodel/libMerakInnovationHairCurly/...` | Neural Weight Package | `libManis.so` | Curly hair generation |
