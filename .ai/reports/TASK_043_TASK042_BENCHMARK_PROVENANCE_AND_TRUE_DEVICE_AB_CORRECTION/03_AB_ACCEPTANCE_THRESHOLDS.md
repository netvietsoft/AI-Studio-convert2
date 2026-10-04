# 03. A/B ACCEPTANCE THRESHOLDS & PRE-BENCHMARK GATES

**Task ID**: `TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION_ACTIVE`  
**Governing Standard**: `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Policy**: ESTABLISHED BEFORE BENCHMARK RESULTS — ZERO RETROACTIVE MODIFICATION  

---

## 1. Nguyên Tắc Cốt Lõi Về Ngưỡng Đóng Cổng (Gating Policy)

Theo quy định nghiêm ngặt tại Điều 1 và Điều 2 của Hiến pháp Vận hành (`AGENTS.md`) và Chỉ thị bắt buộc số 7 của `TASK_043`:
> **"Establish acceptance thresholds before results. A candidate with material regression must be rejected, gated by content type, or corrected."**
> *(Thiết lập ngưỡng chấp nhận trước khi ghi nhận kết quả. Một module ứng viên có sự suy giảm thực chất (material regression) bắt buộc phải bị loại bỏ, đặt cổng chặn theo loại nội dung, hoặc sửa chữa.)*

Mọi ngưỡng chấp nhận định lượng được quy định dưới đây là bất biến. Không được phép hạ ngưỡng hoặc lấy trung bình cộng để bù trừ cho trường hợp suy giảm.

---

## 2. Chi Tiết 5 Cổng Nghiệm Thu Định Lượng (5 Quantitative Gates)

### Cổng 1: Không Được Phép Suy Giảm Độ Lưu Giữ Kết Cấu (Texture Non-Regression Gate)
- **Công thức tính độ lưu giữ kết cấu**:
  $$R_{tex} = \frac{\sigma^2(I_{out} - G_\sigma(I_{out}))}{\sigma^2(I_{orig} - G_\sigma(I_{orig}))} \times 100\%$$
  Trong đó $G_\sigma$ là phép lọc Gaussian 2D ($5 \times 5, \sigma=1.0$) trên kênh độ sáng (luminance) tại các pixel thuộc vùng tóc ($\alpha > 0.10$).
- **Độ chênh lệch giữa Ứng viên B và Chuẩn A**:
  $$\Delta R_{tex} = R_{tex}(B) - R_{tex}(A)$$
- **Ngưỡng chấp nhận (Pass Threshold)**:
  - $\Delta R_{tex} \ge -2.0\%$ trên **từng ca kiểm thử riêng biệt**.
  - **HARD FAIL**: Nếu bất kỳ chân dung nào có $\Delta R_{tex} < -2.0\%$, ứng viên bị coi là làm suy giảm kết cấu (Texture Degradation). Module không được phép tích hợp ở trạng thái thô mà phải bị từ chối hoặc áp dụng cổng phân nhánh theo nội dung (Content-Type Gating).

### Cổng 2: Cô Lập Tuyệt Đối Vùng Da Không Can Thiệp (Zero Skin Leakage Gate)
- **Công thức tính tỷ lệ lem da ($L_{skin}$)**:
  $$L_{skin} = \frac{1}{N_{non\_hair}} \sum_{i \notin \text{Hair}} \frac{|I_{orig}(i) - I_{out}(i)|}{255.0} \times 100\%$$
- **Ngưỡng chấp nhận (Pass Threshold)**:
  - $L_{skin} = \mathbf{0.0\%}$ (hoàn toàn không có biến đổi tại các pixel ngoài vùng tóc).
  - Vùng bảo vệ bao gồm: da trán, tai, mắt, lông mày, mũi, môi và nền tường phía sau.

### Cổng 3: Đối Chứng Âm Tính Bit-Exact Cho Người Trọc Đầu (Negative Control Bit-Exact Gate)
- **Mẫu kiểm thử**: Sư thầy đầu trọc (`portrait_monk_bald_neg`).
- **Ngưỡng chấp nhận (Pass Threshold)**:
  - Số pixel thay đổi: $N_{mod} = \mathbf{0}$.
  - Sai lệch pixel tối đa: $\max |I_{orig} - I_{out}| = \mathbf{0}$ (Bit-exact 100% pass-through).
  - Bất kỳ pixel nào bị nhuộm màu trên mẫu đầu trọc lập tức kích hoạt trạng thái **HARD FAIL**.

### Cổng 4: Kiểm Soát Cháy Sáng & Sai Màu Cảm Thụ (Gamut Clipping & Color Drift Gate)
- **Tỷ lệ giảm pixel cháy sáng ($R_{clip}$)**:
  $$R_{clip} = \frac{N_{blown}(A) - N_{blown}(B)}{N_{blown}(A)} \times 100\% \quad \ge \mathbf{0.0\%}$$
  Trong đó $N_{blown}$ là số pixel tóc có giá trị màu tuyến tính $\max(R, G, B) > 0.98$.
- **Khoảng cách màu sắc cảm thụ OKLab ($\Delta E_{AB}$)**:
  $$\Delta E_{AB} = \frac{1}{N_{hair}} \sum_{i \in \text{Hair}} \sqrt{(L_A - L_B)^2 + (a_A - a_B)^2 + (b_A - b_B)^2} \quad \le \mathbf{0.08}$$
  (Tương đương $\Delta E_{00} \le 1.0$ trên không gian CIE, dưới ngưỡng nhận thức của mắt người).

### Cổng 5: Ngân Sách Thời Gian Thực Thi & Bộ Nhớ (Latency & Memory Gate)
- **Ngân sách độ trễ CPU trên thiết bị di động tầm trung (Helio G99 / Exynos 9611)**:
  - Độ trễ tối đa cho phép của thuật toán lọc kết cấu tóc:
    $$T_{latency} \le \mathbf{200.0\text{ ms}} \quad (\text{độ phân giải } 1080\text{p})$$
  - Bội số độ trễ so với baseline:
    $$\frac{T_B}{T_A} \le \mathbf{3.0\times}$$
  - Nếu $T_B / T_A > 3.0\times$ hoặc $T_B > 200$ ms, thuật toán C++ CPU đơn luồng **không thể triển khai trực tiếp vào luồng UI của ứng dụng** và bắt buộc phải chuyển sang Vulkan Compute Shader.
- **Ngân sách bộ nhớ RAM (Peak Working Set RSS)**:
  - Độ tăng bộ nhớ RAM đỉnh: $\Delta \text{RSS} \le \mathbf{15.0\text{ MB}}$.

---

## 3. Bảng Tổng Hợp Tiêu Chuẩn Nghiệm Thu

| Cổng kiểm định | Chỉ số đo | Ngưỡng PASS | Ngưỡng CONDITIONAL / NEEDS_FIX | Ngưỡng HARD FAIL |
|---|---|---|---|---|
| **Cổng 1: Kết cấu** | $\Delta R_{tex}$ | $\ge 0.0\%$ (Tăng độ nét) | $-2.0\% \le \Delta R_{tex} < 0.0\%$ | $< -2.0\%$ (Suy giảm sợi tóc) |
| **Cổng 2: Ranh giới da** | $L_{skin}$ | $= 0.0\%$ (Không lem) | N/A | $> 0.0\%$ (Lem da) |
| **Cổng 3: Đầu trọc âm tính** | $\max |\Delta I|$ | $= 0$ (Bit-exact) | N/A | $> 0$ (Nhuộm nhầm đầu trọc) |
| **Cổng 4: Cháy sáng** | $R_{clip}$ | $\ge +10.0\%$ (Giảm cháy) | $0.0\% \le R_{clip} < 10.0\%$ | $< 0.0\%$ (Tăng cháy sáng) |
| **Cổng 4: Độ lệch màu** | $\Delta E_{AB}$ | $\le 0.05$ | $0.05 < \Delta E_{AB} \le 0.08$ | $> 0.08$ (Đổi tông màu) |
| **Cổng 5: Độ trễ CPU** | $T_{latency}$ | $\le 100\text{ ms}$ | $100\text{ ms} < T \le 200\text{ ms}$ | $> 200\text{ ms}$ (Gây lag UI) |
| **Cổng 5: Bộ nhớ RAM** | $\Delta \text{RSS}$ | $\le 10\text{ MB}$ | $10\text{ MB} < \Delta \text{RSS} \le 15\text{ MB}$ | $> 15\text{ MB}$ (Nguy cơ OOM) |
