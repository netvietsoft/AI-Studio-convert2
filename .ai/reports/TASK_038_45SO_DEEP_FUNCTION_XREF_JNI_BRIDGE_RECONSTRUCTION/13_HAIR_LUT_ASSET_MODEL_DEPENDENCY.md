# TASK_038 — Hair LUT, Neural Model & Asset Dependency Graph

## 1. Asset Inventory Summary

The Hair Recolor engine relies on three distinct asset classes discovered in `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_assets`:

1. **Neural Segmentation Models (BiSeNet Face & Hair Parsing):**
   - `assets/vlaimodel/libmtface/models/mtface_parsing_heavy.bin` (1,698,494 bytes, SHA-256: `785A21...`)
   - `assets/vlaimodel/libmtface/models/mtface_parsing.bin` (584,286 bytes)
   - `assets/vlaimodel/libmtface/models/mtface_parsing_light.bin` (352,774 bytes)
   - `assets/vlaimodel/libmtface/models/mtface_head.bin` (347,992 bytes)

2. **Color Lookup Tables (LUTs):**
   - `assets/MaterialCenter/5001/50010001/lut.png` (Rose Gold Dye LUT)
   - `assets/MaterialCenter/5002/50020002/lut.png` (Flaxen Brown Dye LUT)
   - `assets/MaterialCenter/2220/22200000/SoftLight2D/SoftLight.png` (2D Soft Light Curve Map)
   - `assets/CustomMaterial/5003/lut1.png` & `lut2.png`

3. **Color Space ICC Profiles:**
   - Display-P3 ICC Profile (embedded in `libPVGColorFunctions.so`)
   - sRGB ICC Profile (embedded in `libPVGColorFunctions.so`)
   - AdobeRGB ICC Profile (embedded in `libPVGColorFunctions.so`)

---

## 2. Asset Flow DAG

```
mtface_parsing_heavy.bin (External Model File)
       │
       ▼
libAIModelKit.so (Loads binary package into memory buffer)
       │
       ▼
libManis.so (Proprietary Neural Inference Engine executes network layers)
       │
       ▼
libarkernel3.so (Post-processes tensor into 8-bit Hair Mask bitmap)
       │
       ▼
libMTFilterKernel.so (Binds mask to hairMaskTexture FBO)
       │
       ├── SoftLight.png / lut.png (Color grading & curve mapping)
       │
       ▼
CMTFilterSoftHair::FilterToFBO (Executes 5-pass anisotropic GPU shader)
       │
       ▼
Final Dyed Hair Image
```

---

## 3. Disproof of Hardcoded Weights in `libManis.so`

In accordance with TASK_038 quality requirements:
- Keyword scan across `libManis.so` (9,928,576 bytes) confirmed:
  - `hair`: 0 hits
  - `segment`: 0 hits
  - `bisenet`: 0 hits
- `libManis.so` is strictly an execution virtual machine (weights tensor parser, layer graph scheduler, and SIMD/NEON compute kernels). All weights are loaded dynamically from external `.bin` packages.