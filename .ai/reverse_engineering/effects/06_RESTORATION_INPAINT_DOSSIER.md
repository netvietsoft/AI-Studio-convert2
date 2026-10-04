# CONVERT2 — TECHNICAL EFFECT DOSSIER: RESTORATION & INPAINTING
**Authority:** Chủ tịch Tony | **Task:** TASK_047 | **Status:** PROVEN / STRONG_INFERENCE

## 1. XÓA VẬT THỂ BẰNG TÍCH CHẬP TẦN SỐ FOURIER (LAMA INPAINTING)
Nghiên cứu từ SnapEdit (`lama_inpaint_fp16.tflite`):
- Sử dụng khối FFC (Fast Fourier Convolution) để nắm bắt cấu trúc toàn cảnh.
- Bù đắp khuyết thiếu thông minh, không để lại vết mờ đục.
## 2. HÒA TRỘN LIỀN MẠCH POISSON
Nghiên cứu từ Remini (`libnwdn.so`):
- Giải phương trình Laplace/Poisson để triệt tiêu bậc nhảy màu tại đường viền ghép.
- Độ tin cậy: **PROVEN / STRONG_INFERENCE**