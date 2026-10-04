# 01 — STRUCTURE TENSOR & DOUBLE-ANGLE ORIENTATION
**Authority:** Chủ tịch Tony  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Mục tiêu:** Định hướng dòng chảy tiếp tuyến sợi tóc để phục vụ tích phân đường 21-tap LIC.

## 1. Cơ sở Toán học
1. **Đạo hàm không gian:**
   $$G_x = \frac{\partial I}{\partial x}, \quad G_y = \frac{\partial I}{\partial y}$$
2. **Thành phần Tensor:**
   $$J_{xx} = G_x^2, \quad J_{yy} = G_y^2, \quad J_{xy} = G_x G_y$$
3. **Làm mờ Gauss 5 điểm:**
   $$\bar{J}_{xx} = K_5 * J_{xx}, \quad \bar{J}_{yy} = K_5 * J_{yy}, \quad \bar{J}_{xy} = K_5 * J_{xy}$$
4. **Vector Góc Kép (Double-Angle Vector):**
   $$\vec{v} = (\cos 2\theta, \sin 2\theta) = \left(\frac{\bar{J}_{xx} - \bar{J}_{yy}}{\sqrt{(\bar{J}_{xx}-\bar{J}_{yy})^2 + 4\bar{J}_{xy}^2}}, \frac{2\bar{J}_{xy}}{\sqrt{(\bar{J}_{xx}-\bar{J}_{yy})^2 + 4\bar{J}_{xy}^2}}\right)$$
5. **Góc tiếp tuyến sợi tóc:**
   $$\theta = \frac{1}{2} \operatorname{atan2}(2\bar{J}_{xy}, \bar{J}_{xx} - \bar{J}_{yy}) + \frac{\pi}{2}$$
