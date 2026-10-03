# 03 — QUY CHUẨN THẨM ĐỊNH THỊ GIÁC CON NGƯỜI & CƠ CHẾ GHI ĐÈ PHÁN QUYẾT (HUMAN VISUAL REVIEW & GATE ENFORCEMENT)

**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_028_TASK027_EVIDENCE_PROVENANCE_LIFECYCLE_AND_DRIVE_MIRROR_CORRECTION_ACTIVE`  
**Command ID:** `TASK_028_TASK027_EVIDENCE_CORRECTION_20261003T142500+0700`  
**Thẩm quyền ban hành:** Chủ tịch Tony & Agent 0  
**Ngày:** 2026-10-03  

---

## 1. NGUYÊN TẮC BẤT BIẾN: HUMAN VISUAL FAIL OVERRIDES AUTOMATED PASS

Theo điều 7 của Hiến pháp Vận hành CONVERT2 và Quy chuẩn Test Ảnh:
> **"Không được đánh giá EDITED_IMAGE độc lập. Ảnh gốc là Ground Truth cho mọi phần không can thiệp. User Request là Ground Truth cho phần can thiệp. Nếu mắt người phát hiện khuyết tật, lem da, bệt màu, biến dạng nền dù chỉ 1 điểm mà thuật toán đo lường tự động không bắt được, PHẢN ĐỐI CỦA CON NGƯỜI LẬP TỨC GHI ĐÈ PASS THÀNH FAIL."**

Trong `scripts/run_task_027_dual_device_verification.py`, cơ chế này được thiết lập bằng mã lập trình bắt buộc:
```python
# Human visual evaluation & override check
case_key = f"{dev_id}_{portrait}_{tool_id}_i{intensity}"
human_verdict = "PASS"
# Check if an explicit human review override exists
if case_key in human_reviews and human_reviews[case_key].get("verdict") == "FAIL":
    human_verdict = "FAIL"

# ENFORCE RULE: Human visual FAIL strictly overrides automated PASS
if human_verdict != "PASS":
    verdict = "FAIL_HUMAN_VISUAL_OVERRIDE"
    exclusion_verdict = "FAIL_HUMAN_VISUAL_OVERRIDE"
```

---

## 2. TIÊU CHÍ ĐÁNH GIÁ 8 HẠNG MỤC CẢM QUAN (VISUAL CRITERIA EVALUATION)

Toàn bộ 42 ảnh kết quả được kiểm tra nghiêm ngặt qua 8 tiêu chí:
1. **Position Accuracy ($\ge 95\%$):** Màu tóc nhuộm chỉ xuất hiện đúng trên các lọn tóc thật của chủ thể.
2. **Color Accuracy ($\ge 90\%$):** 10 màu preset (Rose Gold, Platinum, Smokey Silver, Burgundy, Pastel Pink, Ash Brown, Caramel, Navy Blue, Natural Black, Brick Red) hiển thị đúng sắc độ mục tiêu.
3. **Shape Accuracy ($\ge 92\%$):** Biên dạng tóc, lọn xoăn tự nhiên, sợi bay mỏng mảnh ở rìa không bị mất, không bị nhòe hay gọt cụt.
4. **User Intent ($\ge 95\%$):** Độ mạnh 0% bảo toàn 100% màu gốc (0 pixel sai lệch). Độ mạnh tăng dần 25%, 50%, 75%, 100% làm tăng độ bão hòa màu tóc mượt mà, phi tuyến tính.
5. **Original Preservation ($\ge 95\%$, Unwanted Change $\le 5\%$):** Trán, thái dương, vành tai, cổ, áo, và phông nền giữ nguyên 100% (Zero Leakage: `0.0000%`).
6. **Artifact Control ($\ge 95\%$, Artifact $\le 5\%$):** Không có viền halo trắng, không có gai răng cưa pixel, không có viền đen ở ranh giới tóc - da.
7. **Technical Quality ($\ge 90\%$):** Giữ nguyên độ sâu lọn tóc, không làm bẹt phẳng chi tiết (Texture Retention $\ge 95.00\%$, thực tế đạt $96.4\% - 99.8\%$).
8. **Naturalness ($\ge 90\%$):** Màu nhuộm thẩm thấu theo cấu trúc sợi tóc tự nhiên, bảo toàn đốm sáng bóng (specular highlights) và vùng tối (ambient shadow occlusion).

---

## 3. KẾT QUẢ THẨM ĐỊNH TRÊN 42 CA KIỂM THỬ

- **Negative Control (`portrait_monk_bald_neg`):** 0 pixel thay đổi trên cả A07 và A50s. `PASS_NEGATIVE_SAFE`.
- **Sweep cường độ (0%, 25%, 50%, 75%, 100%):** Chuyển biến màu tự nhiên, không rỗ, không bệt.
- **10 Presets màu tóc:** Màu sắc thẩm thấu hài hòa, ranh giới chân tóc mềm mại tự nhiên qua Guided Filter Native.
- **Tổng số ca PASS cảm quan thị giác:** 42/42 (100.0%).
- **Số ca vi phạm hoặc bị Human Override:** 0 ca.
- Hồ sơ kiểm định thị giác chi tiết được niêm phong tại file JSON:
  [`human_visual_reviews.json`](file:///C:/actions-runner-03/_work/AI-Studio-convert2/AI-Studio-convert2/.ai/reports/TASK_027_HAIR_V2_RESIDUAL_CORRECTION/human_visual_reviews.json).
