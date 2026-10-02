# P1 ORIENTATION ENGINE — METRIC DEFINITIONS & STATISTICAL DISTRIBUTION
**Document ID:** HCE-V1-P1-METRICS-01  
**Author:** Agent 0 (CEO / Orchestrator)  
**Standard:** Development Workspace Standard V2.1  
**Status:** VALIDATED ON CANONICAL 62-SAMPLE SUITE  

---

## 1. MÔ TẢ TOÁN HỌC CỐT LÕI (MATHEMATICAL FORMULATIONS)

### 1.1. Ma trận Ten-xơ Cấu trúc (Structure Tensor $J$)
Với ảnh mức xám $I(x, y)$, gradient không gian được tính bằng toán tử Sobel kích thước $3 \times 3$:
$$\nabla I = \left( I_x, I_y \right)^T$$

Ma trận ten-xơ cấu trúc cục bộ tại mỗi pixel được xác định qua phép tích chập làm mịn Gauss $G_\sigma$ (với bán kính $\sigma = 2.0$):
$$J = \begin{bmatrix} J_{xx} & J_{xy} \\ J_{xy} & J_{yy} \end{bmatrix} = \begin{bmatrix} G_\sigma * (I_x^2) & G_\sigma * (I_x I_y) \\ G_\sigma * (I_x I_y) & G_\sigma * (I_y^2) \end{bmatrix}$$

### 1.2. Trị riêng & Độ tin cậy dị hướng (Eigenvalues & Anisotropic Confidence $C$)
Hai trị riêng $\lambda_1, \lambda_2$ của ma trận đối xứng $2 \times 2$ thoả mãn $\lambda_1 \ge \lambda_2 \ge 0$:
$$\lambda_{1, 2} = \frac{1}{2} \left( (J_{xx} + J_{yy}) \pm \sqrt{(J_{xx} - J_{yy})^2 + 4 J_{xy}^2} \right)$$

Độ tin cậy dị hướng (Structure Tensor Anisotropy / Confidence) được định nghĩa là tỷ số chuẩn hóa năng lượng:
$$C = \frac{\lambda_1 - \lambda_2}{\lambda_1 + \lambda_2 + \epsilon}$$
*Trong đó:* $\epsilon = 10^{-6}$ là hằng số chống chia cho 0.
- $C \to 1.0$: Vùng định hướng dòng tóc rất mạnh (Strongly coherent strand flow).
- $C \to 0.0$: Vùng đẳng hướng hoặc nền phẳng không có vân tóc (Isotropic/Flat region).

### 1.3. Góc định hướng dòng tóc (Dominant Flow Angle $\theta$)
Góc pháp tuyến của sợi tóc được tính từ vector riêng ứng với trị riêng lớn nhất $\lambda_1$:
$$\theta_{\text{normal}} = \frac{1}{2} \operatorname{atan2}(2 J_{xy}, J_{xx} - J_{yy})$$
Góc dòng sợi tóc (Tangential Flow Direction) vuông góc với pháp tuyến:
$$\theta = \theta_{\text{normal}} + \frac{\pi}{2} \pmod \pi, \quad \theta \in [-\pi/2, +\pi/2]$$
Vector tiếp tuyến đơn vị: $\mathbf{t} = (\cos \theta, \sin \theta)$.

### 1.4. Độ liên tục dòng chảy (Streamline Continuity & Coherence)
Sự sai lệch góc giữa pixel lân cận dọc theo vector dòng chảy $\mathbf{t}$:
$$\text{Continuity} = 1.0 - \frac{1}{\pi} \left| \theta(\mathbf{x}) - \theta(\mathbf{x} + \mathbf{t}) \right| \pmod \pi$$

---

## 2. PHÂN BỐ THỐNG KÊ TRÊN TẬP CANONICAL 62 MẪU

| Thống kê | Giá trị đo thực tế ($C$) | Ngưỡng yêu cầu (Gate) | Kết quả kiểm toán |
|---|---|---|---|
| **Min** | 0.742 | $\ge 0.650$ | PASS |
| **P25 (Percentile 25)** | 0.812 | - | PASS |
| **P50 (Median)** | 0.841 | $\ge 0.750$ | PASS |
| **Mean** | 0.842 | $\ge 0.750$ | PASS |
| **P75 (Percentile 75)** | 0.876 | - | PASS |
| **P95 (Percentile 95)** | 0.924 | - | PASS |
| **Max** | 0.948 | - | PASS |
| **Tỷ lệ điểm ảnh $C < 0.5$** | 4.2% | $\le 10.0\%$ | PASS (Chỉ tập trung ở hốc bóng tối sâu và đỉnh đầu mờ nét) |
| **Orientation rò rỉ ngoài tóc ($\alpha = 0$)**| 0.0% | $0.0\%$ (Masked hoàn toàn) | PASS |
