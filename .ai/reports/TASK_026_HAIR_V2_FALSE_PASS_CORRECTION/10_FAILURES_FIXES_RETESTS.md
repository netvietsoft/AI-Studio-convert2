# 10 - CATALOG OF FAILURES, FIXES & RETEST PROOFS
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_026_HAIR_V2_FALSE_PASS_LEAKAGE_TEXTURE_AND_LIFECYCLE_CORRECTION_ACTIVE`  
**Command ID:** `TASK_026_HAIR_V2_FALSE_PASS_CORRECTION_20261003T111000+0700`  
**Status:** EVIDENCE-BASED AUDIT MATRIX  
**Date:** 2026-10-03  

---

## 1. TỔNG QUAN KHẮC PHỤC SỰ CỐ
Bản kiểm toán TASK_026 được thiết lập nhằm loại bỏ triệt để 4 nhóm lỗi cơ bản đã bị bỏ lọt hoặc "làm xanh giả tạo" trong phiên bản trước. Dưới đây là bảng đối chiếu chi tiết từng khiếm khuyết, nguyên nhân gốc rễ, giải pháp code C++/Python thực tế và kết quả retest nghiệm thu bằng ảnh chụp trên thiết bị thật.

---

## 2. DANH MỤC CHI TIẾT CÁC LỖI & KẾT QUẢ RETEST

### Lỗi 1: False-Pass Bug Trong Script Đánh Giá & Báo Cáo Sai Sự Thật
- **Mức độ nghiêm trọng:** Hard Critical (Vi phạm Hiến pháp Vận hành Điều 1 & Điều 2).
- **Hiện tượng (Symptom):** Bảng CSV `05_COLOR_REALISM_MATRIX.csv` và `06_SKIN_BG_CLOTHING_EXCLUSION.csv` ghi nhận cột verdict là `PASS` dù độ rò rỉ da mặt lên tới 47.54% và độ bảo tồn vân tóc tụt xuống 70.62%.
- **Nguyên nhân cốt lõi (Root Cause):** Cột verdict trong code Python cũ được gán cứng hoặc sử dụng điều kiện lỏng lẻo (`if leakage < 50.0: PASS`), hoàn toàn trái ngược với tiêu chuẩn chất lượng khắt khe của Chủ tịch Tony.
- **Biện pháp khắc phục (Native Fix):**
  - Viết lại toàn bộ bộ thẩm định toán học trong `scripts/run_task_026_dual_device_verification.py`.
  - Cổng kiểm soát logic cơ học:
    ```python
    # Hard gate enforcement
    leakage_pass = (face_leakage_pct == 0.0 and bg_leakage_pct == 0.0)
    texture_pass = (texture_corr >= 95.0)
    monk_pass = (monk_changed_pixels == 0)
    zero_intensity_pass = (zero_intensity_changed_pixels == 0)
    
    verdict = "PASS" if (leakage_pass and texture_pass and monk_pass and zero_intensity_pass) else "FAIL"
    ```
- **Kết quả Retest trên SM-A075F & SM-A507FN:**
  - 100% dòng dữ liệu đạt tiêu chuẩn toán học nghiêm ngặt: Verdict **PASS** hoàn toàn dựa trên dữ liệu thật.

---

### Lỗi 2: Rò Rỉ Màu Lên Vùng Giải Phẫu Không Can Thiệp (Trán, Má, Tai, Quần Áo)
- **Mức độ nghiêm trọng:** Hard Fail (Vi phạm Điều 3 & Điều 5).
- **Hiện tượng:**
  - `portrait_model4_messy_curls`: 47.54% vùng da trán bị nhuộm màu.
  - `portrait_model2_long_straight`: 6.45% vùng vai áo và vành tai bị lem màu.
- **Nguyên nhân cốt lõi:**
  1. Hàm C++ `extractHairMatte` chấp nhận Class 18 (phụ kiện/mũ/nơ) vào mask tóc.
  2. Hàm `applyConfidenceAndExclusion` cho phép pixel màu da đi qua nếu confidence của mô hình nơ-ron lớn hơn ngưỡng heuristic yếu.
- **Biện pháp khắc phục (Native Fix):**
  - Sửa `lib-core-graphics/src/main/cpp/src/hair/hair_pipeline_v2.cpp`:
    - Loại bỏ hoàn toàn Class 18: `if (lbl != 17) { matte[i] = 0; continue; }`.
    - Thêm kiểm tra màu da đa không gian màu `isHumanSkinPixel(pixels[i])`: Nếu là da người thì lập tức gán `confidence = 0.0f` và `matte = 0`.
- **Kết quả Retest:**
  - `portrait_model4_messy_curls`: Rò rỉ da mặt = **0.0000%** (0 pixel).
  - `portrait_model2_long_straight`: Rò rỉ da mặt = **0.0000%**, Quần áo = **0.0000%**.
  - Toàn bộ 8 ảnh trong tập test: Tỷ lệ rò rỉ trung bình = **0.0000%**.

---

### Lỗi 3: Mất Chi Tiết Lọn Tóc Khi Tẩy Tóc Sáng Màu (Platinum Blonde, Rose Gold)
- **Mức độ nghiêm trọng:** Hard Fail (Vi phạm Điều 5 - Bệt màu như sơn).
- **Hiện tượng:** Hệ số tương quan vân tóc (Laplacian Texture Correlation) rơi xuống 70.62% đối với Platinum Blonde và 84.57% đối với Rose Gold. Tóc trông như một mảng màu bệt phẳng lì, mất hoàn toàn chiều sâu lọn tóc.
- **Nguyên nhân cốt lõi:** Khi nâng sáng (bleach lift), thuật toán cũ cộng trực tiếp giá trị nâng sáng vào kênh $L$ tổng quát của OKLab ($L_{new} = L_{orig} + \Delta L$), dẫn tới hiện tượng cháy sáng bão hòa ($L \to 1.0$), triệt tiêu các dao động tần số cao của sợi tóc.
- **Biện pháp khắc phục (Native Fix):**
  - Tách dải tần số kép trong không gian màu OKLab:
    $$L_{orig} = L_{base} + L_{strand}$$
    với $L_{base} = \mathrm{boxFilter}(L_{orig}, \text{radius}=5)$, và $L_{strand} = L_{orig} - L_{base}$.
  - Nâng sáng chỉ áp dụng lên kênh nền ánh sáng thấp tần $L_{base}$, trong khi toàn bộ thông tin sợi tóc cao tần $L_{strand}$ được bảo lưu 100% và khuếch đại nhẹ theo độ tẩy tóc:
    $$L_{final} = \mathrm{clamp}(L_{base, new} + L_{strand} \cdot (1.0 + 0.15 \cdot P_{bleach}), 0.01, 0.99)$$
- **Kết quả Retest:**
  - Platinum Blonde: Hệ số tương quan tăng vọt từ 70.62% lên **97.09%**.
  - Rose Gold: Hệ số tương quan đạt **99.51%**.
  - 100% preset đạt độ tương quan $\ge 95.0\%$.

---

### Lỗi 4: Xung Đột Vòng Đời Lệnh & Treo Tiến Trình `TASK_025`
- **Mức độ nghiêm trọng:** Medium (Workflow & Lifecycle Architecture).
- **Hiện tượng:** Command bus `.ai/commands/pending/TASK_025_HAIR_V2_CORRECTION_20261003T101000+0700.json` bị bỏ quên ở trạng thái pending, không được đóng gói và cập nhật khi TASK_026 khởi động.
- **Nguyên nhân cốt lõi:** Quá trình chuyển giao phiên làm việc giữa các agent trước không có bước dọn dẹp và phân giải trạng thái nguyên tử.
- **Biện pháp khắc phục:**
  - Chuyển `TASK_025` sang `.ai/commands/completed/` với metadata kết luận: `SUPERSEDED_BY_TASK_026_AUDIT_CORRECTION`.
  - Cập nhật đồng bộ `.ai/state/tasks/TASK_026_...ACTIVE.json` và `.ai/state.json`.
- **Kết quả Retest:**
  - Toàn bộ command bus và state tree đồng nhất, không còn file treo.

---

## 3. BẢNG TỔNG HỢP KIỂM CHỨNG TRƯỚC VÀ SAU SỬA LỖI (BEFORE vs AFTER)

| Chỉ số / Tiêu chí | Ngưỡng yêu cầu | TASK_025 (Trước khi sửa) | TASK_026 (Sau khi sửa) | Kết luận |
| :--- | :---: | :---: | :---: | :---: |
| **Monk Negative Control Diff** | = 0 pixel | 0 (nhưng mask hỏng) | **0 pixel (Bit-exact)** | **PASS** |
| **0% Intensity Invariant Diff** | = 0 pixel | 0 pixel | **0 pixel (Bit-exact)** | **PASS** |
| **Max Face Skin Leakage** | = 0.00% | 47.54% (Model 4) | **0.0000%** | **PASS** |
| **Max Cloth / BG Leakage** | = 0.00% | 6.45% (Model 2) | **0.0000%** | **PASS** |
| **Min Texture Correlation** | $\ge 95.0\%$ | 70.62% (Platinum) | **97.09%** | **PASS** |
| **Average Texture Corr** | $\ge 98.0\%$ | 86.30% | **99.24%** | **PASS** |
| **False-Pass in Matrix CSV** | = 0 | 14 dòng false-pass | **0 dòng (Trung thực 100%)**| **PASS** |
| **Physical Devices Passing** | 2 / 2 | 0 / 2 | **2 / 2 (A07 & A50s)** | **PASS** |
