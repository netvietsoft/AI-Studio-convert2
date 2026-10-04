# 04 — 9X9 UNSHARP MASK & CLARITY ENHANCEMENT
**Authority:** Chủ tịch Tony  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Mục tiêu:** Tăng cường độ tương phản lọn tóc và độ bóng sáng tự nhiên.

## 1. Thuật toán Lấy mẫu Hộp 9x9 (81 Taps)
$$\bar{C}(x, y) = \frac{1}{81} \sum_{t=-4}^{4} \sum_{p=-4}^{4} I(x + 2.3 t \cdot \Delta u, y + 2.3 p \cdot \Delta v)$$

## 2. Khuếch đại Tương phản & Clarity
$$C_{sharp} = \operatorname{clamp}(\bar{C} + (I - \bar{C}) \cdot 1.8, 0.0, 1.0)$$
$$C_{final} = C_{sharp} + (\min(I - I_{blur}, 0.0) + 0.015) \cdot 0.4$$
