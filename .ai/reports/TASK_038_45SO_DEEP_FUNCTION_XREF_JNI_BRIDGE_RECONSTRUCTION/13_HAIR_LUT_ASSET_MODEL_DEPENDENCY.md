# 13 — HAIR LUT, ASSET & MODEL DEPENDENCY GRAPH

**Task ID:** TASK_038_45_SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION_ACTIVE  

---

## 1. INVENTORY OF HAIR-RELATED ASSETS

From `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_assets\assets`:
1. **3D LUT Shaders & Textures:**
   - `ARKernel3Builtin/3XShaders/3dLut.fs` (3D LUT volume lookup in GLSL)
   - `ARKernel3Builtin/BeautyResource/LUT64.jpg` (64x64x64 standard color grading identity cube)
   - `ARKernel3Builtin/spirv/finial_lut_map.frag.spv` (Vulkan compiled SPIR-V LUT shader)
   - `ARKernel3Builtin/spirv/lut3d_to_2d.frag.spv`
2. **Hair Shader Assets:**
   - `ARKernel3Builtin/Shaders/HairSoft/MTFilter_HairSoftMix.fs` & `.vs` (Meitu obfuscated shader pack)
   - `ARKernel3Builtin/Shaders/MTFilter_HairMaskMix.fs` & `.vs`
   - `beauty/hairGrow/hairSmear/ar_effect/ar/res/brushTool/genCurlHair.frag` & `.vert`
3. **Color Palettes & Material Plists:**
   - `CustomMaterial/5003/lut1.png` & `lut2.png`
   - `lip_custom_color/ar/res/lip_lut.plist`

---

## 2. NEURAL MODEL VERIFICATION: `libManis.so`
- **Weight Separation:** Binary analysis of `libManis.so` (9,928,576 bytes) confirms that `libManis.so` is an inference execution runtime (similar to NCNN/TNN/ONNXRuntime).
- It does **NOT** embed hardcoded neural weights within `.rodata`.
- Hair segmentation and face parsing weights are loaded dynamically from `.manis` or `.bin` model files in external assets.
- In CONVERT2, our standalone NCNN model `hair_matting_mobile.param` and `hair_matting_mobile.bin` serves this exact functional role with zero external network dependency.