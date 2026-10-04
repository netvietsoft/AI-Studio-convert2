# TASK_038 — HAIR LUT, ASSET & NEURAL MODEL DEPENDENCIES

1. **LUT Tables (`u_toneLutMap`):** 512x512 3D LUT unrolled into 2D texture format for smooth color grading.
2. **Neural Models (`libManis.so`):**
   - `libManis.so` is strictly an inference engine runtime (NCNN/MNN hybrid architecture).
   - **Evidence:** Zero model weight bytes inside binary; models are loaded externally from `assets/models/bisenet_hair.bin` or server packages.
