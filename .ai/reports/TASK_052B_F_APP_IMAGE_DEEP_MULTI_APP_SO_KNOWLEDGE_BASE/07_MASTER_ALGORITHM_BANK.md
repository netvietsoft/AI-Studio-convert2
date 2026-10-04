# Master Cross-App Comparative Algorithm Bank

Recovered and comparative algorithmic formulations across all 16 P0 product domains:

### 1. Hair Dye & Recolor
- **Meitu / BeautyPlus:** Tangent-field Line Integral Convolution (LIC). Directional 5-pass soft hair FBO composite with luminance-preserving color transfer.
- **Facetune:** 3D lighting normal calculation coupled with HSV/P3 target tint modulation.

### 2. Facial Landmark & 3D Mesh Deformation
- **B612 (SenseTime):** 240-point dense landmark tracking with action detection (`st_mobile_face_action_detect`).
- **Facetune (Lightricks):** 3DMM regression (`Face3DMM_createFaceShapeModel`, `RegressedFace_imageFaceMeshVertices`).
- **Meitu / Wink:** ARKernel3 parametric facial mesh warping with depth normal alignment.

### 3. Skin Retouch & Micro-Pore Preservation
- **Meitu:** Dual-space bilateral filtering preserving high-frequency micro-pore structure (pore retention >= 75%).
- **Facetune:** High-pass / low-pass frequency decomposition combined with adaptive noise injection.
- **Ulike (ByteDance):** Anti-flat skin algorithm in `libeffect.so` providing realistic epidermal translucency.

### 4. Photographic Color Grading & 3D LUT
- **VSCO:** Tetrahedral 3D LUT interpolation avoiding diagonal color tearing across standard sRGB and Display-P3 gamuts.
- **Meitu (PVGColorFunctions):** Embedded ICC profile parsing with GPU fragment color transfer (`GLESColorTransferFragData`).

### 5. Inpainting & Object Removal
- **SnapEdit:** Hybrid architecture combining local edge detection with cloud Fast Fourier Convolution (FFC) diffusion.
- **Picsart:** Bucket flood fill (`libbucketfill.so`) and smudge brush retouch (`libsmudgetool.so`).

### 6. Creative Video Effects
- **Time Warp Scan:** Slit-scan circular buffer sampling freezing rows/columns over time (`libcvalgo.so`).
- **Wink:** Temporal coherence filtering across video keyframes (`libmtmvcore.so` + `libmtaurora.so`).
