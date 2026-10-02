# HCE V1 — P0-P5 IMMUTABILITY & CONTRACT INTEGRITY CHECK
**Task:** TASK_003_HCE_V1_GPU_EVIDENCE_INTEGRITY_AND_PHYSICAL_RERUN  
**Date:** 2026-10-02  
**Authority:** Chủ tịch Tony  

---

## 1. BẢO TOÀN TUYỆT ĐỐI P0-P5
- **P0 Status:** CLOSED_FROZEN (tau_aspect = 1.80 bất biến, BiSeNet P0 preprocessing không can thiệp).
- **P0 Freeze Hash Record:** `scratch/p0_c_integration/P0_C_CORRECTION_03/P0_C_CORRECTION03_FREEZE.sha256`
- **P1 (Orientation):** Giữ nguyên thuật toán Sobel + Gaussian Tensor + Angle Regularization.
- **P2 (Texture):** Giữ nguyên cấu trúc Bilateral + Gabor filter bank.
- **P3 (Appearance):** Giữ nguyên Shadow / Highlight separation và Luma depth preserving.
- **P4 (Salon Dye):** Giữ nguyên không gian màu Oklab melanin lifting và Chroma response.
- **P5 (Specular):** Giữ nguyên mô hình phản xạ Marschner R-lobe anisotropic glint.

## 2. P6 VULKAN COMPUTE INTEGRATION
Lõi Vulkan Compute SPIR-V bytecode (`5034baa195ed0853dad89931a11db0a88253feafa45d72552708c1d1fd113690`) triển khai đúng đặc tả toán học của P1-P5 mà không làm sai lệch bất kỳ hằng số nào của các phase thượng nguồn.

## 3. P7 STATUS
`P7`: **STRICTLY_BLOCKED** (Không mở rộng, không kích hoạt, tuân thủ Section VIII).
