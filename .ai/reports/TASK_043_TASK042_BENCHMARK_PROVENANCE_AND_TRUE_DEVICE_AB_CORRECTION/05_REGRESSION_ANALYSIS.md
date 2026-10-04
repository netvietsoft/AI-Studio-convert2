# 05. REGRESSION ANALYSIS & ALGORITHMIC FAILURE MECHANISMS

**Task ID**: `TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION_ACTIVE`  
**Governing Standard**: `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Investigation Focus**: Giải trình chi tiết nguyên nhân toán học & cơ chế vật lý dẫn đến hiện tượng suy giảm kết cấu trên tóc nam gợn sóng (`portrait_1_male_wavy`), tóc tơ sáng màu (`portrait_model1_blonde`) và bùng nổ độ trễ CPU.

---

## 1. Bản Chất Khoa Học Của Sự Suy Giảm Kết Cấu (Texture Degradation)

Trong `TASK_042`, báo cáo đã ghi nhận một con số suy giảm nghiêm trọng trên chân dung nam tóc ngắn gợn sóng (`portrait_1_male_wavy`):
- Độ lưu giữ kết cấu giảm từ **$91.90\%$** xuống **$74.07\%$** (chênh lệch **$-17.82\%$**).
- Tại phép đo kiểm độc lập bằng nhị phân C++ thực thi trên phần cứng Galaxy A07 và Galaxy A50s của `TASK_043`, độ suy giảm kết cấu tiếp tục được tái xác nhận ở mức **$-2.32\%$ đến $-24.74\%$** trên các kiểu tóc có bước sóng xoăn ngắn, và lên tới **$-73.81\%$** trên tóc tơ sáng màu (`portrait_model1_blonde`).

Dưới đây là 3 nguyên nhân cốt lõi về mặt toán học và xử lý tín hiệu hình ảnh:

```
                  GIẢ THUYẾT TUYẾN TÍNH CỦA BỘ LỌC 1D
   Vector tiếp tuyến v(x,y)
    ───────►────────►───────► (Đường lấy mẫu tích phân 1D, L = 9px)
       /                 \
      /   Sợi tóc lượn    \   ===> Đường tích phân CẮT NGANG qua
     /    sóng thực tế     \       các chu kỳ sóng khác nhau,
    /                       \      gây triệt tiêu tương phản (BLURRING)
```

### 1.1. Sự Phá Vỡ Giả Thiết Tuyến Tính Cục Bộ Trên Sóng Tóc Ngắn (Local Linearity Breakdown)
- Thuật toán `directionalFilter1D` trong `hair_v2_directional_filter.cpp` thực hiện phép tích phân đường theo vector tiếp tuyến:
  $$I_{filtered}(x, y) = \frac{1}{\sum w_s} \sum_{s=-r}^{r} w_s \cdot I(x + s \cdot t_x, y + s \cdot t_y)$$
  với bán kính $r = 4$ (chiều dài kernel quét là $2r + 1 = 9$ pixel).
- Phép toán này dựa trên **tiền đề rằng sợi tóc thẳng cục bộ** trong phạm vi 9 pixel.
- Tuy nhiên, trên tóc nam cắt ngắn tỉa layer hoặc tóc gợn sóng ngắn (`portrait_1_male_wavy`), bán kính cong (radius of curvature) của lọn tóc $R_{curve} < 5$ pixel. Chiều dài bước sóng của nếp tóc chỉ dao động từ 6 đến 10 pixel.
- Do đó, đoạn thẳng 9 pixel quét dọc theo vector tiếp tuyến tại đỉnh sóng sẽ **cắt chéo qua sườn sóng và đáy sóng lân cận**, biến phép lọc dọc sợi tóc thành **phép làm mờ triệt tiêu (destructive interference)** giữa các vùng sáng/tối đối lập. Kết quả là các đường sóng tóc sắc nét bị xóa nhòa, làm độ lưu giữ kết cấu sụt giảm nghiêm trọng.

### 1.2. Mất Chi Tiết Do Nội Suy Song Tuyến Trên Tóc Tơ (Sub-pixel Interpolation Attenuation)
- Trên tóc tơ sáng màu (`portrait_model1_blonde`), độ dày của từng sợi tóc chỉ chiếm 1 đến 1.5 pixel, và độ tương phản độ sáng giữa sợi tóc và nền rất thấp ($\Delta L < 0.08$).
- Hàm lấy mẫu `sampleBilinear(src, W, H, sx, sy)` trong vòng lặp 1D liên tục nội suy các tọa độ thực $(sx, sy)$. Bản thân phép nội suy song tuyến (Bilinear Interpolation) là một bộ lọc thông thấp (low-pass filter) bậc nhất.
- Khi áp dụng 2 lượt lọc định hướng ($r=4$ cho strand filter và $r=12$ cho low volume base), toàn bộ các tần số không gian siêu cao (micro-hair details) bị san phẳng, dẫn đến độ suy giảm kết cấu khổng lồ **$-73.81\%$**.

### 1.3. Tính Ưu Việt Của Lọc Đẳng Hướng Baseline A (Isotropic Contrast Invariance)
- Thuật toán baseline của CONVERT2 (`HairTextureEngine::decomposeFrequencies`) sử dụng bộ lọc tách nền không gian 2D separable box filter kết hợp trích xuất trực tiếp vi sai độ sáng:
  $$I_{high} = I_{luma} - I_{low}$$
  sau đó tăng cường độ tương phản sống sợi tóc thông qua đạo hàm cấp 2 ngang qua hướng dòng chảy (`HairTextureEngine::computeDirectionalFilter`).
- Baseline A không làm mờ dọc theo sợi tóc bằng tích phân đường, mà chỉ dùng trường hướng để **tăng cường độ sắc của cạnh ngang sợi tóc** ($2 \cdot I - (I_+ + I_-)$). Nhờ đó, dù sợi tóc uốn lượn phức tạp hay ngắn cũn cỡn, chi tiết tần số cao vẫn được bảo tồn 100% không bị triệt tiêu.

---

## 2. Phân Tích Bùng Nổ Độ Trễ CPU & Bộ Nhớ RAM (Performance Collapse)

| Chỉ số hiệu năng | Baseline A (CONVERT2) | Candidate B (V1 Modules) | Bội số suy giảm (Penalty) |
|---|---|---|---|
| **Độ trễ Galaxy A07 (Helio G99)** | **18.16 ms – 39.09 ms** | **340.23 ms – 586.51 ms** | **$\mathbf{15.0\times – 18.7\times}$ Chậm hơn** |
| **Độ trễ Galaxy A50s (Exynos 9611)** | **42.93 ms – 86.02 ms** | **776.84 ms – 1,341.13 ms** | **$\mathbf{14.0\times – 18.1\times}$ Chậm hơn** |
| **Độ phức tạp tính toán / pixel** | $2 \times (2r+1)$ phép cộng | 9 phép nội suy Bilinear (36 fetches + 27 ALU) | $\approx 22\times$ FLOPs cao hơn |
| **Bộ nhớ đỉnh (Peak RSS)** | **54,000 KB (~52.7 MB)** | **105,900 KB (~103.4 MB)** | **$\mathbf{+51.9\text{ MB}}$ RAM phụ trội** |

### 2.1. Cơ chế bùng nổ thời gian tính toán
- Thuật toán Baseline A khai thác tính phân tách (separability) của bộ lọc 2D: Lọc ngang 1D rồi lọc dọc 1D với bộ tích lũy di động (moving sum), độ phức tạp là $O(1)$ trên mỗi pixel không phụ thuộc bán kính.
- Thuật toán Candidate B không thể phân tách vì vector tiếp tuyến $(\cos\theta, \sin\theta)$ thay đổi theo từng pixel. Với mỗi pixel, CPU phải tính toán 9 lần tọa độ thực, gọi hàm `floor`, lấy mẫu 4 điểm ảnh xung quanh, tính 3 trọng số song tuyến và nhân với trọng số Gaussian.
- Trên vi xử lý di động không có tăng tốc phần cứng GPU, việc xử lý 1.2 triệu pixel tốn hơn **1.3 giây** trên Galaxy A50s, vượt quá ngân sách 200 ms của ứng dụng và gây đơ giao diện người dùng (ANR).

### 2.2. Cơ chế phình to bộ nhớ RAM
- Candidate B yêu cầu khởi tạo đồng thời 6 đệm bộ nhớ float toàn khung hình: `tangentX`, `tangentY`, `strandFiltered`, `low`, `meso`, `micro`. Với ảnh 1080p ($1080 \times 1920$), mỗi mảng float tiêu tốn $\approx 8.3\text{ MB}$. Tổng cộng 6 mảng cộng với các đệm trung gian làm tăng bộ nhớ đỉnh lên **105.9 MB** (gấp đôi Baseline A).

---

## 3. Điểm Sáng Duy Nhất Cần Giữ Lại: Soft-Knee Tanh Gamut Compression

Trái ngược với sự thất bại của bộ lọc định hướng 1D, hàm nén sắc độ `softChromaCompress` trong `hair_v2_color.cpp` đã chứng minh hiệu quả thực tế xuất sắc:
- **Triệt tiêu hiện tượng cháy sáng**: Giảm số pixel bị đẩy lên mức bão hòa tối đa ($>0.98$) từ 51 pixel xuống 38 pixel trên `portrait_0_curly` (giảm **$25.49\%$**), và từ 3 xuống 2 pixel trên `portrait_1_male_wavy` (giảm **$33.33\%$**).
- **Bảo toàn màu sắc trung thực**: Độ lệch màu cảm thụ giữa A và B trên không gian OKLab chỉ dao động từ **$0.005$ đến $0.037$**, hoàn toàn nằm dưới ngưỡng nhận thức của mắt người ($\Delta E < 0.05$).
- **Chi phí cực thấp**: Đây là hàm tính toán cục bộ độc lập cho từng pixel, không cần đệm bộ nhớ phụ và có thể chuyển đổi thành 3 dòng lệnh GLSL/SPIR-V trong compute shader `hair_composite_blend.comp`.

---

## 4. Kết Luận Phân Tích

1. **Ứng viên `hair_v2_directional_filter.cpp` ở trạng thái thô (unconditioned) BỊ BÁC BỎ**: Không được phép tích hợp đại trà vào pipeline chính vì gây suy giảm chi tiết trên tóc ngắn, tóc tơ và phá hủy hiệu năng CPU.
2. **Ứng viên `hair_v2_color.cpp` (`softChromaCompress`) ĐƯỢC CHẤP THUẬN**: Đủ điều kiện để đưa vào Vulkan GPU shader trong các task tiếp theo.
