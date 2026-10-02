# P3 HAIR APPEARANCE ENGINE — METRIC DEFINITIONS & FORMULATIONS
**Document ID:** HCE-V1-P3-METRICS-01  
**Author:** Agent 0 (CEO / Orchestrator)  
**Standard:** Development Workspace Standard V2.1  
**Status:** VERIFIED (PROXY METRIC SUITE)  

---

## 1. CÔNG THỨC TOÁN HỌC TRÍCH XUẤT ÁNH SÁNG & ĐỘ SÂU BÓNG TỐI

### 1.1. Kênh Độ sáng Khử màu (Luminance Channel $Y$)
Độ sáng cơ bản được tính theo chuẩn Rec.601 từ các kênh sRGB tuyến tính:
$$Y = 0.299 R + 0.587 G + 0.114 B$$

### 1.2. Mặt nạ Vùng Bóng tối (Shadow Map $M_{\text{shadow}}$)
Vùng bóng tối nội tại của tóc được xác định qua phân ngưỡng thích nghi cục bộ kết hợp với phân vùng tóc P0:
$$M_{\text{shadow}}(x, y) = \begin{cases} 1.0 - \frac{Y(x, y)}{Y_{\text{shadow\_thresh}}}, & \text{nếu } Y(x, y) < Y_{\text{shadow\_thresh}} \text{ và } \alpha(x, y) \ge 0.5 \\ 0.0, & \text{ngược lại} \end{cases}$$
*Trong đó:* $Y_{\text{shadow\_thresh}} = \mu_Y - 0.5 \sigma_Y$.

### 1.3. Mặt nạ Vùng Điểm sáng (Highlight Mask $M_{\text{highlight}}$)
$$M_{\text{highlight}}(x, y) = \begin{cases} \frac{Y(x, y) - Y_{\text{high\_thresh}}}{1.0 - Y_{\text{high\_thresh}}}, & \text{nếu } Y(x, y) > Y_{\text{high\_thresh}} \text{ và } \alpha(x, y) \ge 0.5 \\ 0.0, & \text{ngược lại} \end{cases}$$
*Trong đó:* $Y_{\text{high\_thresh}} = \mu_Y + 0.75 \sigma_Y$.

### 1.4. Điểm Bảo lưu Bóng tối (Shadow Preservation Score $S_{\text{pres}}$)
$$S_{\text{pres}} = 1.0 - \frac{\sum_{(x, y) \in \text{Hair}} \left| Y_{\text{dyed}}(x, y) - Y_{\text{target}}(x, y) \right| \cdot M_{\text{shadow}}(x, y)}{\sum_{(x, y) \in \text{Hair}} M_{\text{shadow}}(x, y) + \epsilon}$$
*Phân loại:* Đây là **Proxy Metric** đo lường sự duy trì độ sâu khối của tóc, không phải ground-truth intrinsic decomposition.
