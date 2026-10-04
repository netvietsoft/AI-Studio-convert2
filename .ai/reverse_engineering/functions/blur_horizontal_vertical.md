# MTSoftHairFilter Gaussian Blur Passes
**Thư viện:** `libMTFilterKernel.so`  
**Địa chỉ offset:** `0x000f4528` (Ngang) & `0x000f46d0` (Dọc)  
**Bảng trọng số .rodata:** `0x0008edd8`  

### 1. Bảng Trọng Số Tĩnh Thực Nghiệm 5 Điểm (Separable 1D Gaussian)
`weights[5] = {0.159676f, 0.263348f, 0.122118f, 0.030573f, 0.004122f}`  
Tổng đối xứng $W = w_0 + 2 \sum_{i=1}^4 w_i = 1.000004 \approx 1.0$.
