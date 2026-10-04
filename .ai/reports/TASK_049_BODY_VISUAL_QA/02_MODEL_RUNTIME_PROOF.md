# MODEL RUNTIME PROOF — TASK_049
**Authority:** Chủ tịch Tony  
**Task:** TASK_049_BODY_VISUAL_QA  
**Date:** 2026-10-04  

## 1. MoveNet SinglePose Lightning v4
- **Framework:** NCNN C++ Native Engine
- **Param File:** `lib-core-graphics/src/main/assets/models/movenet_lightning.param`
- **Bin File:** `lib-core-graphics/src/main/assets/models/movenet_lightning.bin`
- **Input Size:** 192x192 RGB Normalized
- **Output:** 17 Keypoints (Heatmap 48x48x17, Offset 48x48x34)
- **License:** Apache 2.0 (Google MediaPipe / TFHub)
- **Runtime Execution:** Real device JNI binding verified on SM-A075F and SM-A507FN.

## 2. MediaPipe Selfie Segmentation
- **Framework:** NCNN C++ Native Engine
- **Param File:** `lib-core-graphics/src/main/assets/models/selfie_segmentation.param`
- **Bin File:** `lib-core-graphics/src/main/assets/models/selfie_segmentation.bin`
- **Input Size:** 256x256 RGB Normalized
- **Output:** Probability map `[1, 256, 256]`
- **License:** Apache 2.0
- **Runtime Execution:** Real device JNI binding verified.
