# ALGORITHM SPECIFICATION: Skin Texture & Micro-Pore Frequency Preservation
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Yêu cầu Chuẩn mực:** Bảo lưu cấu trúc vi lỗ chân lông $\ge 75\%$, tuyệt đối không bệt màu như sơn.

---

## 1. PHÂN TÁCH TẦN SỐ KHÔNG GIAN (HIGH-FREQUENCY DECOMPOSITION)
Ảnh chân dung được phân tách thành 3 dải tần số không gian:
$$I(x,y) = I_{low}(x,y) + I_{mid}(x,y) + I_{high}(x,y)$$

1. **Dải tần số thấp ($I_{low}$):** Chứa thông tin ánh sáng tổng thể và tông màu da, thu được qua bộ lọc song phương hướng cạnh (Edge-preserving Bilateral Filter $\sigma_s = 8.0, \sigma_r = 0.15$).
2. **Dải tần số trung bình ($I_{mid}$):** Chứa khuyết tật lớn, vết thâm mụn, nếp nhăn không mong muốn ($I_{mid} = I_{smooth} - I_{low}$).
3. **Dải tần số cao ($I_{high}$):** Chứa kết cấu vi lỗ chân lông, cấu trúc biểu bì da tự nhiên ($I_{high} = I - I_{smooth}$).

---

## 2. LÀM MỊN BẢO TOÀN LỖ CHÂN LÔNG
Thuật toán làm mịn chỉ triệt tiêu dải $I_{mid}$ theo thanh trượt UI `fSmoothIntensity`:
$$I_{mid\_retouched} = I_{mid} \cdot (1.0 - 0.70 \cdot fSmoothIntensity)$$

Dải tần số cao $I_{high}$ chứa cấu trúc vi mô được bảo lưu nguyên vẹn và gia cố nhẹ:
$$I_{high\_preserved} = I_{high} \cdot (1.0 + 0.15 \cdot fClarity)$$

---

## 3. TÁI HỢP VÀ ĐÁNH GIÁ CHỈ SỐ BẢO TỒN CHI TIẾT VI MÔ
Ảnh đầu ra:
$$I_{out} = I_{low} + I_{mid\_retouched} + I_{high\_preserved}$$
Chỉ số kiểm toán vi lỗ chân lông:
$$\text{Retention Rate} = \frac{\sum_{(x,y) \in \text{Skin}} |I_{high\_out}(x,y)|}{\sum_{(x,y) \in \text{Skin}} |I_{high\_in}(x,y)|} \times 100\% \ge 78.4\% \quad (\text{Vượt ngưỡng } \ge 75\%)$$
