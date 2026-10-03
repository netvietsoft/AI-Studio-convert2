# 04 - ĐỘ CHÍNH XÁC MÀU, CÔ LẬP RÒ RỈ & BẢO TOÀN VÂN TÓC V2
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_027_HAIR_V2_RESIDUAL_LEAKAGE_TEXTURE_AND_COMMAND_LIFECYCLE_CORRECTION_ACTIVE`  

---

## 1. PHẠM VI KIỂM TOÁN VÀ BỘ MẪU TEST
Bộ kiểm thử bao gồm **21 trường hợp thử nghiệm** trên mỗi thiết bị, tương ứng **42 lượt chạy trên 2 thiết bị vật lý**:
- **01 Mẫu Negative Control:** `portrait_monk_bald_neg` + Rose Gold 75% (yêu cầu chính xác 0 pixel thay đổi).
- **01 Mẫu Cường Độ 0%:** `portrait_0_curly` + Rose Gold 0% (yêu cầu chính xác 0 pixel thay đổi).
- **04 Mẫu Quét Cường Độ (Intensity Sweep):** `portrait_0_curly` + Rose Gold (25%, 50%, 75%, 100%).
- **09 Mẫu Preset Màu Khác:** `portrait_0_curly` + Platinum, Smokey Silver, Burgundy, Pastel Pink, Ash Brown, Caramel, Navy Blue, Natural Black, Brick Red (ở cường độ 75%).
- **06 Mẫu Người & Kiểu Tóc Khác Nhau:** 
  1. `portrait_1_male_wavy` (Tóc lượn sóng nam giới)
  2. `portrait_model1_blonde` (Tóc vàng phương Tây)
  3. `portrait_model2_long_straight` (Tóc thẳng dài)
  4. `portrait_model3_wavy_curls` (Tóc xoăn sóng lớn)
  5. `portrait_model4_messy_curls` (Tóc xoăn rối)
  6. `portrait_model6_fringe_bangs` (Tóc mái bằng phủ trán)

---

## 2. KẾT QUẢ TỔNG HỢP KIỂM CHỨNG TRÊN 2 MÁY THỰC TẾ

```
========================================================================================================
Thiết bị: SM-A075F (Samsung Galaxy A07)
Tổng số test: 21 | PASS: 21 (100.0%) | Rò rỉ trán trung bình: 0.0000% | Vân tóc trung bình: 98.41%
--------------------------------------------------------------------------------------------------------
Thiết bị: SM-A507FN (Samsung Galaxy A50s)
Tổng số test: 21 | PASS: 21 (100.0%) | Rò rỉ trán trung bình: 0.0000% | Vân tóc trung bình: 98.26%
========================================================================================================
CHUNG CUỘC TOÀN BỘ 42 HÀNG: 42/42 PASS (100.0%)
========================================================================================================
```

---

## 3. ĐÁNH GIÁ 3 CHỈ TIÊU KỸ THUẬT QUAN TRỌNG NHẤT

### A. Rò Rỉ Vùng Trán & Da Mặt (`ForeheadLeakagePct`)
- **Tiêu chuẩn:** $0.0000\%$ (không có ngoại lệ).
- **Thực tế đo được:** **0.0000% trên toàn bộ 42 bài test**.
- Không có hiện tượng lem màu sang trán, khóe mắt, vành tai, hoặc chân mày. Ngay cả với kiểu tóc mái rủ `portrait_model6_fringe_bangs`, vùng trán dưới mái tóc vẫn được bảo vệ tuyệt đối với 0 pixel rò rỉ.

### B. Rò Rỉ Vùng Nền & Áo Quần (`BgCornerLeakagePct`)
- **Tiêu chuẩn:** $0.0000\%$ tại 4 góc khung hình ($y < 0.15H, x < 0.20W$ hoặc $x > 0.80W$) và vùng áo.
- **Thực tế đo được:** **0.0000% trên toàn bộ 42 bài test**.

### C. Độ Bảo Toàn Vân Tóc (`TextureCorrPct`)
- **Tiêu chuẩn:** $\ge 95.00\%$ đối với mọi hàng trạng thái PASS.
- **Thực tế đo được:**
  - Điểm thấp nhất: **96.45%** (`portrait_0_curly` + `Navy Blue` trên A50s).
  - Mẫu sửa đổi trọng tâm (`Platinum Blonde 75%` trên `portrait_0_curly`):
    - **A07:** **97.53%** (vượt chuẩn +2.53%)
    - **A50s:** **99.12%** (vượt chuẩn +4.12%)
  - Điểm trung bình toàn bộ preset: **98.34%**.

---

## 4. BẢO VỆ TUYỆT ĐỐI BẤT BIẾN TOÁN HỌC (INVARIANTS)
1. **Negative Control Invariant:**
   - Khi chạy `portrait_monk_bald_neg` (nhà sư trọc đầu) với preset màu bất kỳ, mask tóc trích xuất có diện tích bằng 0.
   - Số lượng pixel biến đổi: **Đúng 0 pixel** trên cả 2 máy.
2. **0% Intensity Invariant:**
   - Khi chạy `intensity = 0%`, toán tử hòa trộn tuyến tính nhân với $\alpha = 0.0$.
   - Số lượng pixel biến đổi: **Đúng 0 pixel** trên cả 2 máy.
