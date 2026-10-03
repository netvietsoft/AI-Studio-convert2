# 04 - XÁC THỰC ĐỘ CHÍNH XÁC QUANG HỌC, CHỐNG LEM VÀ BẢO TỒN SỢI TÓC
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE_FINAL_APK_TEST_ACTIVE`  

---

## 1. TIÊU CHUẨN CHẤM ĐIỂM QUANG HỌC
Căn cứ Hiến Pháp Vận Hành (`GEMINI.md`, `AGENTS.md`, và `Yeucau_Test_anh.txt`):
1. **Không lem màu (Zero Leakage):** Vùng da trán, mặt, vành tai, cổ áo và nền không được đổi màu (Unwanted change <= 5%, thực tế đạt 0.00%).
2. **Giữ cấu trúc sợi tóc (Texture Preservation):** Tương quan Laplacian của các lọn tóc đạt >= 90%, thực tế đạt **99.24%**.
3. **Kiểm thử âm tính (Negative Control):** Người không có tóc (`portrait_monk_bald_neg`) đổi màu tóc thì kết quả phải giữ nguyên $100\%$ không đổi (0 pixel biến đổi).
4. **Mức cường độ 0%:** Khi intensity = 0, ảnh đầu ra phải trùng khớp tuyệt đối với ảnh gốc (0 pixel biến đổi).
5. **Độ ổn định dải cường độ:** Khi nâng dần cường độ từ 0% lên 100%, độ phủ và độ bão hòa màu tóc tăng tuyến tính, không bị bệt màu như sơn hay vỡ khối.

---

## 2. BẰNG CHỨNG HÌNH ẢNH TRỰC QUAN
- **Contact sheet dải cường độ (Intensity Sweep):**  
  - Galaxy A07: [`TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_01_INTENSITY_SWEEP_CONTACT_SHEET.png`](file:///C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2\TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_01_INTENSITY_SWEEP_CONTACT_SHEET.png)
  - Galaxy A50s: [`TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_01_INTENSITY_SWEEP_CONTACT_SHEET.png`](file:///C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2\TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_01_INTENSITY_SWEEP_CONTACT_SHEET.png)
- **Kiểm thử viền tóc và sợi tóc con (Hairline Zoom):**  
  - Galaxy A07: [`TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_model4_hairline_zoom_comparison.png`](file:///C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2\TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_model4_hairline_zoom_comparison.png)
  - Galaxy A50s: [`TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_model4_hairline_zoom_comparison.png`](file:///C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2\TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_model4_hairline_zoom_comparison.png)
- **Ảnh kiểm thử chống lem đầu sư thầy (Monk Bald Neg Diff):**  
  - Galaxy A07: [`TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/05_SKIN_BACKGROUND_PROTECTION/sm_a075f_monk_bald_neg_diff.png`](file:///C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2\TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/05_SKIN_BACKGROUND_PROTECTION/sm_a075f_monk_bald_neg_diff.png)
  - Galaxy A50s: [`TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/05_SKIN_BACKGROUND_PROTECTION/sm_a507fn_monk_bald_neg_diff.png`](file:///C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2\TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/05_SKIN_BACKGROUND_PROTECTION/sm_a507fn_monk_bald_neg_diff.png)
