# tetrahedral_3d_lut_sample.md — HỒ SƠ PHÂN TÍCH HÀM LẤY MẪU NỘI SUY TỨ DIỆN 3D LUT
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Ký hiệu hàm:** `PVG_Apply3DLUTTetrahedral(const float* srcRGB, float* dstRGB, int width, int height, const float* lutData, int lutSize)`  
**Địa chỉ RVA:** `0x00011400`  
**Thư viện:** `libPVGColorFunctions.so` (Build-ID: `1011276c5b88cb50d83e7a8b444af1601979f983`)  
**Trạng thái Pháp lý:** **RULE 11 CLEAN-ROOM SPECIFICATION**  

---

## 1. MÃ GIẢ VÀ THANH GHI ARM64
- **Thanh ghi đầu vào:**
  * `x0`: Con trỏ mảng màu gốc `srcRGB` (kênh màu float32 [0.0, 1.0]).
  * `x1`: Con trỏ mảng kết quả `dstRGB`.
  * `w2`: Chiều rộng ảnh `width`.
  * `w3`: Chiều cao ảnh `height`.
  * `x4`: Con trỏ khối dữ liệu bảng màu 3D LUT kích thước 33x33x33x4 floats.
  * `w5`: Kích thước bảng tra màu `lutSize` (mặc định = 33).
- **Vòng lặp tính toán NEON Vector:**
  * Lệnh so sánh `FCMGE v2.4s, v0.4s, v1.4s` xác định thứ tự của $\Delta r, \Delta g, \Delta b$.
  * Lệnh nạp bảng gián tiếp `TBL` hoặc nạp trực tiếp qua tính toán địa chỉ offset:
    $$\text{offset} = (k \cdot N \cdot N + j \cdot N + i) \times 4 \times \text{sizeof}(float)$$
  * Sử dụng các lệnh `FMLA.4s` (Fused Multiply-Accumulate) để tổng hợp màu 4 đỉnh tứ diện trong 1 chu kỳ vi lệnh.

---

## 2. RÀO CHẮN BẢO VỆ DẢI MÀU (GAMUT BOUNDARY CLAMPING)
Hàm tự động kẹp giá trị tọa độ đầu vào vào khoảng an toàn $[0.0, 1.0]$ trước khi nhân với $(N - 1)$:
$$\text{clamped\_coord} = \operatorname{fmin}(\operatorname{fmax}(\mathbf{C}_{\text{in}}, 0.0\text{f}), 1.0\text{f})$$
Đảm bảo con trỏ bộ nhớ không bao giờ truy cập vượt giới hạn mảng $33 \times 33 \times 33$ (Zero Buffer Overflow / Memory Safety).
