# 02 — DIRECTIONAL 21-TAP LINE INTEGRAL CONVOLUTION (LIC)
**Authority:** Chủ tịch Tony  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Mục tiêu:** Khử nhiễu cảm biến dọc theo sợi tóc nhưng giữ nguyên cạnh vi mô.

## 1. Công thức Tích phân Đường (LIC Formula)
$$I_{LIC}(\mathbf{x}) = \frac{\sum_{k=-10}^{10} w_k \cdot I(\mathbf{x} + k \cdot \Delta s \cdot \vec{t}(\mathbf{x}))}{\sum_{k=-10}^{10} w_k}$$

Trong đó:
- Bước tích phân: $\Delta s = 1.0 \text{ pixel}$.
- Vector tiếp tuyến: $\vec{t}(\mathbf{x}) = (\cos \theta, \sin \theta)$.
- Trọng số Gauss: $w_k = \exp(-k^2 / (2 \sigma^2))$ với $\sigma = 3.5$.
