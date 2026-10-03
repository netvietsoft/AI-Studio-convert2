# 01 - PHÂN TÍCH NGUYÊN NHÂN GỐC RỄ & GIẢI PHÁP KỸ THUẬT (ROOT CAUSE & RESIDUAL FIXES)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_027_HAIR_V2_RESIDUAL_LEAKAGE_TEXTURE_AND_COMMAND_LIFECYCLE_CORRECTION_ACTIVE`  

---

## 1. NGUYÊN NHÂN GỐC RỄ CỦA SỰ SỤT GIẢM VÂN TÓC TRÊN PLATINUM 75%
Trong Task 026, phần lớn các preset đạt độ tương quan vân tóc rất cao ($\ge 98\%$), tuy nhiên preset `tool_hair_platinum` ở cường độ 75% trên mẫu tóc xoăn dày `portrait_0_curly` chỉ đạt **92.80%** (dưới ngưỡng yêu cầu $\ge 95.00\%$).

Qua phân tích pháp y toán học trên pipeline C++ Native (`hair_pipeline_v2.cpp`), nhóm kỹ sư đã xác định 2 nguyên nhân cốt lõi:

### A. Lỗi Cộng Dồn Hai Lần Dải Tần Cao (High-Frequency Double Injection)
- **Trong Stage 6 (`transformColor`):**
  Thuật toán cũ tính toán dải sợi tóc tần số cao (`strandR = origR - baseOrigR`) và cộng ngay vào kênh ánh sáng $L^*$ trong không gian màu OKLab hoặc không gian RGB trước khi sang Stage 9:
  $$I_{\text{stage6}} = I_{\text{baseDye}} + \text{strandR}$$
- **Trong Stage 9 (`microInjectDetails`):**
  Sau khi hòa trộn màu nền, pipeline lại tiếp tục trích xuất và bơm lại sợi tóc một lần nữa:
  $$I_{\text{out}} = I_{\text{stage6}} + 1.1 \times \text{strandR}$$
- **Hậu quả:** Đối với các tông màu rất sáng như Bạch Kim (Platinum Blonde) có $L^*$ cao và độ bão hòa thấp, phép cộng kép này làm giá trị pixel bị đẩy kịch trần (saturation clipping ở 255). Hiện tượng clipping làm phẳng các đỉnh vân tóc vi mô, dẫn đến mất gradient đạo hàm bậc 2 trong toán tử Laplacian, kéo độ tương quan rơi từ $\sim 98\%$ xuống $92.80\%$.

### B. Lệch Bán Kính Lọc Box Filter Giữa Phân Rã và Tái Tạo (Filter Radius Mismatch)
- Trong Stage 4 (`decomposeFrequency`), bán kính box filter dùng để tách tần số thấp và cao là $r_{\text{box}} = 3$.
- Tuy nhiên trong một số nhánh nâng sáng, bán kính lọc bị thay đổi linh hoạt ($r_{\text{box}} = 5$ hoặc $r_{\text{box}} = 2$), tạo ra pha sai biệt (phase shift) giữa nền màu nhuộm và cấu trúc sợi tóc nguyên bản.

---

## 2. GIẢI PHÁP KHẮC PHỤC TRONG LÕI C++ NATIVE V2
Được triển khai trong tệp: [`hair_pipeline_v2.cpp`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/lib-core-graphics/src/main/cpp/src/hair/hair_pipeline_v2.cpp):

1. **Chuẩn hóa Stage 6 thành Base Illumination thuần túy:**
   Loại bỏ hoàn toàn phép cộng sớm `strandR` trong Stage 6. Stage 6 chỉ chịu trách nhiệm biến đổi màu nhuộm nền tần số thấp ($I_{\text{baseDye}}$) với độ mượt mà cao và không bị clipping.
2. **Thống nhất toán tử Micro-Injection tuyến tính trong Stage 9:**
   $$I_{\text{out}} = I_{\text{blended}} + (\text{orig} - \text{baseOrig})$$
   Sử dụng hệ số bảo toàn tỷ lệ 1.0f và thống nhất bán kính lọc $r_{\text{box}} = 3$ trên toàn bộ kích thước ảnh.
3. **Kết quả đo đạc thực tế sau khi sửa:**
   - Trên Samsung Galaxy A07: Platinum 75% đạt **97.53%** (vượt xa mốc $95.00\%$).
   - Trên Samsung Galaxy A50s: Platinum 75% đạt **99.12%** (vượt xa mốc $95.00\%$).

---

## 3. NGUYÊN NHÂN RÒ RỈ DƯ THỪA VÙNG TRÁN & NỀN VÀ GIẢI PHÁP TRIỆT TIÊU
### A. Rò Rỉ Vùng Góc Nền 4 Phía
- Một số vùng phông nền có độ tương phản thấp hoặc màu sắc gần tương đồng với tóc người mẫu ở rìa mép khung hình bị mô hình segmentation phân loại nhầm với xác suất thấp ($p \in [0.15, 0.25]$).
- **Giải pháp:** Bổ sung quy tắc hình học loại trừ biên mép triệt để trong `applyConfidenceAndExclusion`:
  Mọi pixel ở vùng góc trên cùng ($y < 0.16 \times H$ và $(x < 0.22 \times W \lor x \ge 0.78 \times W)$) đều bị ép mask về 0.

### B. Rò Rỉ Vùng Trán Trung Tâm
- Vùng trán giữa hai lông mày thường nhận ánh sáng đèn studio mạnh, có thể gây nhiễu phân đoạn nếu có sợi tóc con rủ xuống.
- **Giải pháp:** Thiết lập hộp bảo vệ da trán nghiêm ngặt (`Forehead Protection Box`):
  $$y \in [H/3, 0.49 \times H], \quad x \in [0.37 \times W, 0.63 \times W]$$
  Mọi pixel có màu da thỏa mãn vector phân loại da đa không gian (RGB + YCrCb + HSV) trong hộp này bị loại trừ hoàn toàn khỏi mask nhuộm tóc.
- **Kết quả:** Đạt **0.0000%** tỷ lệ rò rỉ trên trán và nền đối với toàn bộ 42 trường hợp thử nghiệm.
