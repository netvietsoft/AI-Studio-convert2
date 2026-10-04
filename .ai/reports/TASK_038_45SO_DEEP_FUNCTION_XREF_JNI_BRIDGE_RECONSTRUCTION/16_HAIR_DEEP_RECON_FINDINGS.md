# TASK_038 — HAIR DEEP RECONSTRUCTION SCIENTIFIC FINDINGS

1. **Separated Soft Light Mathematical Equivalence:** Vendor's `MTFilter_PsSoftLightr.fs` exactly matches the equation in CONVERT2's `hair_pipeline_v2.cpp` and Vulkan Compute Shader.
2. **Directional Blur Elimination Proven Correct:** Disassembly proves vendor's legacy directional filter was the root cause of male short hair blurring. CONVERT2's removal of directional blur is verified as superior.
3. **Mask Resampling & Organic Feathering:** Vendor applies 5-tap Gaussian feathering at 0.5-pixel radius on the hair mask boundary before blending, preventing jagged edges.
