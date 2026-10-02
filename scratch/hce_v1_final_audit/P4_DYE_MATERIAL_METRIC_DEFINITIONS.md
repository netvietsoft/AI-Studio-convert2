# P4 SALON DYE MATERIAL ENGINE — METRIC DEFINITIONS & MODEL DISCLOSURE
**Document ID:** HCE-V1-P4-METRICS-01  
**Author:** Agent 0 (CEO / Orchestrator)  
**Standard:** Development Workspace Standard V2.1  
**Status:** VERIFIED (CANONICAL SUITE AUDITED)  

---

## 1. LÀM RÕ BẢN CHẤT MÔ HÌNH MELANIN (ISSUE E6 DISCLOSURE)
1. **Khẳng định dứt khoát:** Trong HCE V1, tham số "Melanin" (Eumelanin $\mu_{\text{eu}}$ và Pheomelanin $\mu_{\text{pheo}}$) là **THAM SỐ ĐIỀU KHIỂN HÌNH THÁI XUẤT HIỆN (Perceptual Appearance-Control Parameter)**, hoàn toàn **KHÔNG PHẢI** là phép đo quang phổ vật lý hay sinh thiết sắc tố sinh học thật.
2. **Quy tắc chuyển đổi:** Đường cong "Melanin Lift Curve" là hàm nâng sáng phi tuyến theo mô hình salon (Bleach Lift Simulation):
   $$L_{\text{lifted}} = L_{\text{base}} + (1.0 - L_{\text{base}}) \cdot \text{lift\_factor} \cdot (1.0 - \mu_{\text{eu}})$$

---

## 2. KHÔNG GIAN MÀU OKLAB & CÔNG THỨC $\Delta E_{\text{OKLab}}$
HCE V1 thực hiện toàn bộ phép đổi màu tóc trong không gian màu đều cảm nhận **OKLab**:
1. Từ sRGB sang linear sRGB:
   $$c_{\text{lin}} = \begin{cases} c / 12.92, & c \le 0.04045 \\ ((c + 0.055) / 1.055)^{2.4}, & c > 0.04045 \end{cases}$$
2. Từ linear sRGB sang cone response LMS:
   $$\begin{bmatrix} l \\ m \\ s \end{bmatrix} = \mathbf{M}_1 \begin{bmatrix} r_{\text{lin}} \\ g_{\text{lin}} \\ b_{\text{lin}} \end{bmatrix}$$
3. Từ khối lập phương LMS sang toạ độ OKLab $(L, a, b)$:
   $$L = 0.2104542553 l' + 0.7936177850 m' - 0.0040720468 s'$$
   $$a = 1.9779984951 l' - 2.4285922050 m' + 0.4505937099 s'$$
   $$b = 0.0259040371 l' + 0.7827717662 m' - 0.8086757660 s'$$
   *Trong đó:* $l' = l^{1/3}, m' = m^{1/3}, s' = s^{1/3}$.

Sai biệt màu $\Delta E_{\text{OKLab}}$ giữa màu tóc sau nhuộm và màu mẫu salon mục tiêu:
$$\Delta E_{\text{OKLab}} = \sqrt{(L_{\text{dyed}} - L_{\text{target}})^2 + (a_{\text{dyed}} - a_{\text{target}})^2 + (b_{\text{dyed}} - b_{\text{target}})^2}$$
- **Ngưỡng chấp nhận (Gate):** $\Delta E_{\text{OKLab}} \le 2.50$ (Mức mắt thường nhận diện là chuẩn salon).

---

## 3. ĐỘ ĐẬM CHÂN TÓC (ROOT DARKNESS RATIO) & KHÓA GAMUT
1. **Root Darkness Ratio ($R_{\text{root}}$):** Tỷ số độ sáng chân tóc sát da đầu so với ngọn tóc:
   $$R_{\text{root}} = \frac{L_{\text{root}}}{L_{\text{tip}}} \approx 0.90 \pm 0.05$$
2. **Khóa Gamut (Gamut Lock):** Mọi giá trị toạ độ màu sau khi biến đổi OKLab sang linear RGB đều được kiểm tra tính hợp lệ trong không gian sRGB $[0.0, 1.0]$. Bất kỳ giá trị nào ngoài dải đều được nén theo vector sắc độ (Chroma Desaturation Clamping), bảo đảm $0$ vi phạm gamut khi xuất hiển thị.
