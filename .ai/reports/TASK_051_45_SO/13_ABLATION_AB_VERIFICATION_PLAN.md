# TASK_051 — ABLATION & A/B VERIFICATION PLAN (HAIR RECONSTRUCTION)
**Authority:** Chủ tịch Tony  
**Task ID:** TASK_051_P0_45_SO_MAX_DEPTH_CONTINUOUS_RECONSTRUCTION_ACTIVE  
**Standard:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Runner Identity:** CONVERT2-WINDOWS-02 (GITHUB_ACTIONS_37204962051)  
**Commit SHA:** b7ca2dc975472c14bf586c67f93d54b226169971  
**Verification Target:** Samsung Galaxy A50 (Physical Hardware Target) & Host Benchmark  

---

## 1. MỤC TIÊU KIỂM ĐỊNH TRIỆT TIÊU (ABLATION GOAL)
Để bảo đảm thuật toán tái dựng phòng sạch đạt độ chính xác từng bit, pixel và không suy diễn sai lệch, kế hoạch kiểm định triệt tiêu (Ablation Test) được thiết lập nhằm đo lường vai trò định lượng độc lập của từng module thành phần trong chuỗi 8 giai đoạn.

---

## 2. DANH MỤC 4 BÀI KIỂM ĐỊNH TRIỆT TIÊU ĐỊNH LƯỢNG (QUANTITATIVE ABLATION TESTS)

### BÀI TEST 1: Full Pipeline vs. Ablated No-LIC (Khảo sát Tác dụng của 21-tap LIC)
- **Mục tiêu:** Đo lường vai trò của phép tích phân đường 21 taps dọc theo tiếp tuyến dòng chảy sợi tóc.
- **Biến thể A (Ground Truth Reconstruction):** Đầy đủ 8 giai đoạn có 21-tap LIC.
- **Biến thể B (Ablated):** Bỏ qua giai đoạn 5, áp dụng làm mờ đẳng hướng tiêu chuẩn (Isotropic Blur).
- **Chỉ số đo lường:**
  - Độ nét lọn tóc (Hair Strand Directional Coherence Score >= 0.92).
  - Hiện tượng bệt màu như sơn quét (Flatness Index <= 0.05).
- **Ngưỡng nghiệm thu:** Biến thể A phải duy trì độ sâu các lọn tóc xoăn và chiều hướng chải tóc tự nhiên mà không làm mờ đục chi tiết.

### BÀI TEST 2: Full Pipeline vs. Ablated No-Unsharp Mask (Khảo sát Tác dụng của 9x9 Unsharp Mask & Clarity 0.4)
- **Mục tiêu:** Đo lường vai trò của bộ lọc tương phản hộp 9x9 và hệ số tăng độ trong trẻo `clarity = 0.4`.
- **Biến thể A:** Đầy đủ 9x9 Unsharp Mask (bước nhảy 2.3x, gain 1.8x, clarity 0.4).
- **Biến thể B:** Bỏ qua Unsharp Mask, chỉ áp dụng hòa trộn màu SoftLight thông thường.
- **Chỉ số đo lường:**
  - Độ tương phản vi mô sợi tóc (Local Contrast Metric >= 85.0).
  - Độ sáng bóng tự nhiên của tóc (Hair Highlight Specularity Ratio >= 1.45).
- **Ngưỡng nghiệm thu:** Biến thể A thể hiện rõ ánh bóng khỏe khoắn của mái tóc dưới nguồn sáng; Biến thể B bị xỉn màu và mất độ tương phản.

### BÀI TEST 3: Full Pipeline vs. Ablated Naive Alpha Blending (Khảo sát Tác dụng của Pegtop SoftLight)
- **Mục tiêu:** Đo lường vai trò của công thức SoftLight Pegtop không phân nhánh so với phép trộn Alpha đè màu thông thường (Linear Normal Alpha Blend).
- **Biến thể A:** Pegtop SoftLight formula kết hợp 3D LUT trong không gian Lab.
- **Biến thể B:** Linear Alpha Blend: Cout = (1 - alpha)*Csrc + alpha*Cdye.
- **Chỉ số đo lường:**
  - Bảo tồn dải sáng tối tự nhiên (Luminance Dynamic Range Preservation >= 95%).
  - Độ sai lệch màu (Color Delta Eab <= 2.0 so với màu nhuộm chuẩn).
- **Ngưỡng nghiệm thu:** Biến thể B làm tóc như bị phủ một lớp sơn nhựa đục ngầu, mất hoàn toàn cấu trúc sợi; Biến thể A giữ nguyên 100% sợi tóc gốc trong khi màu nhuộm ngấm sâu tự nhiên.

### BÀI TEST 4: Protected Isolation Delta Gate (Kiểm định Tuyệt Đối Vùng Không Can Thiệp)
- **Mục tiêu:** Chứng minh toán học rằng không có bất kỳ pixel nào thuộc da mặt, trán, tai, cổ áo hay hậu cảnh bị biến đổi giá trị.
- **Quy trình kiểm tra:**
  1. Trích xuất Mask bảo vệ: Mprotect = 1.0 - FeatheredHairMask.
  2. Tính hiệu số pixel trên ảnh đã xử lý so với ảnh gốc: Delta P = |Output - Original| * Mprotect.
- **Ngưỡng Hard Fail:**
  - Nếu bất kỳ pixel nào trong vùng bảo vệ có Delta P > 0 => **HARD FAIL (LỖI LEM DA/NỀN)**.
  - Tỷ lệ vi lỗ chân lông da mặt được bảo tồn: >= 75%.

---

## 3. TIÊU CHÍ NGHIỆM THU ĐÁNH GIÁ ẢNH (BỘ 8 TIÊU CHÍ CHUẨN MỰC TONY)

Mọi kết quả render kiểm thử phải đạt điểm đánh giá tối thiểu:
1. **Position Accuracy:** >= 95/100 (Mặt nạ khớp chính xác 100% vùng tóc).
2. **Color Accuracy:** >= 90/100 (Màu nhuộm chuẩn xác theo mã màu swatch Rose Gold/Brown/Ash).
3. **Shape Accuracy:** >= 92/100 (Không làm biến dạng phom dáng đầu hay tai).
4. **User Intent:** >= 95/100 (Đúng ý định nhuộm/làm bóng tóc của người dùng).
5. **Original Preservation:** >= 95/100 (Bảo lưu 100% da mặt, cổ áo, nền tường; Unwanted change <= 5%).
6. **Artifact Control:** >= 95/100 (Không lem màu, không quầng sáng halo, không rỗ pixel).
7. **Technical Quality:** >= 90/100 (Độ sắc nét cao, không giảm độ phân giải canvas).
8. **Naturalness:** >= 90/100 (Tự nhiên như nhuộm tóc thật tại salon chuyên nghiệp).
