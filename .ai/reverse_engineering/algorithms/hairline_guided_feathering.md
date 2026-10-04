# ALGORITHM SPECIFICATION: Hairline Guided Feathering & Edge Alpha Matting
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Rule 11 Clean-Room  
**Lớp Thuật Toán:** Phân định biên tiếp giáp da - tóc (Hairline Boundary Transition)  
**Mục tiêu Kỹ thuật:** Triệt tiêu hoàn toàn viền lem màu lên trán, tai, cổ và lông mày, đạt yêu cầu Zero Leakage theo tiêu chuẩn V2.1.

---

## 1. NGUYÊN LÝ LỌC DẪN ĐƯỜNG PHI TUYẾN (GUIDED FILTER TRANSITION)
Biên giới tiếp giáp giữa tóc và da được lọc bằng Guided Filter đa tầng có tham chiếu kênh sắc độ da gốc $I_{skin}$:
$$q_i = a_k I_i + b_k \quad \forall i \in \omega_k$$
$$a_k = \frac{\frac{1}{|\omega|} \sum_{i \in \omega_k} I_i p_i - \mu_k \bar{p}_k}{\sigma_k^2 + \epsilon}$$
$$b_k = \bar{p}_k - a_k \mu_k$$

Trong đó:
- $p$: Mặt nạ thô BiSeNet Class 17 ($M_{hair\_raw}$).
- $I$: Ảnh hướng dẫn xám (grayscale guide image).
- $\epsilon = 10^{-4}$: Tham số bảo tồn cạnh vi mô của các sợi tóc mai mỏng.

---

## 2. KHÓA BẢO VỆ VÙNG KHÔNG CAN THIỆP (SKIN PROTECTION GATE)
Để đảm bảo 100% không dính màu lên da mặt, trán và vành tai:
1. Xác định mặt nạ da mặt $M_{face}$ từ BiSeNet Class 1 (Skin) và 106 điểm MediaPipe Face Landmarks.
2. Thiết lập vùng cấm tuyệt đối:
$$M_{hair\_feathered}(x,y) = M_{guided}(x,y) \cdot \left(1.0 - \text{SmoothStep}(0.05, 0.40, M_{face}(x,y))\right)$$
3. Với vùng tóc mai tiếp giáp tai (Ear Exclusion Zone):
Bán kính vùng đệm $\Delta r = 3 \text{ px}$ xung quanh vành tai được khóa cứng hệ số mặt nạ về 0 nếu độ tương phản sắc tố $\Delta E_{Lab} < 8.0$.
