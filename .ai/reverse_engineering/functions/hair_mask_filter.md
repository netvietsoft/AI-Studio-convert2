# MTSoftHairFilter::hairMaskFilterToFBO
**Thư viện:** `libMTFilterKernel.so`  
**Địa chỉ offset:** `0x000f4400`  
**Vai trò:** Pass 2 trong chuỗi kết xuất MTSoftHairFilter  

### 1. Cơ chế lọc mặt nạ
Khử nhiễu biên và tạo đường chuyển tiếp dải mềm (feathering) với hệ số chuyển đổi:
`feather = smoothstep(0.05, 0.20, maskVal) * clamp(alpha, 0.0, 1.0)`.
Bảo vệ tuyệt đối 100% vùng da mặt, tai, cổ không bị lem màu.
