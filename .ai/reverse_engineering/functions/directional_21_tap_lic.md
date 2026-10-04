# LFDenseHairModular::computeDirectionalLIC
**Thư viện:** `libLayerFlow.so`  
**Địa chỉ offset:** `0x00024880`  
**Vai trò:** Tích phân đường cong Line Integral Convolution 21 điểm  

### 1. Lấy mẫu tích phân đối xứng
Lấy mẫu 21 điểm dọc theo vector tiếp tuyến $\mathbf{v} = (-\sin\theta, \cos\theta)$:
$$I(x) = \frac{\sum_{k=-10}^{10} w_k \cdot T(x + k \cdot \Delta s \cdot \mathbf{v})}{\sum w_k}$$
Tạo độ bóng sáng tự nhiên dọc theo nếp lọn tóc.
