# 08 - SO SÁNH ĐỐI CHỨNG TRƯỚC VÀ SAU: PLATINUM TRÊN TÓC XOĂN (DEEP-DIVE)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_027_HAIR_V2_RESIDUAL_LEAKAGE_TEXTURE_AND_COMMAND_LIFECYCLE_CORRECTION_ACTIVE`  

---

## 1. VẤN ĐỀ TRỌNG TÂM CỦA TASK_026
Trong báo cáo kiểm toán trước đó (Task 026), trường hợp:
- **Người mẫu:** `portrait_0_curly` (Tóc xoăn xù dày đặc, nhiều nếp uốn lượn có tần số không gian rất cao).
- **Màu nhuộm:** `tool_hair_platinum` (Bạch Kim Blonde, có độ sáng $L^*$ cao và độ bão hòa $C^*$ thấp).
- **Cường độ:** 75%.
- **Kết quả Task 026:**
  - Tỷ lệ tương quan vân tóc: **92.80%** (DƯỚI NGƯỠNG BẮT BUỘC 95.00%).
  - Hiện tượng quan sát: Vùng đỉnh tóc và các lọn tóc xoăn dày bị hiện tượng bệt mảng sáng, mất độ sâu gradient của các sợi tóc nhỏ do hiệu ứng clipping dải tần cao.

---

## 2. KẾT QUẢ SAU KHI SỬA TRONG TASK_027

```
+------------------------------------+----------------+----------------+----------------+
| Thuộc tính                         | TASK_026 (Cũ)  | TASK_027 (A07) | TASK_027 (A50s)|
+------------------------------------+----------------+----------------+----------------+
| Độ tương quan vân tóc (Laplacian)  | 92.80% (FAIL)  | 97.53% (PASS)  | 99.12% (PASS)  |
| Rò rỉ trán (Forehead Leakage)      | 0.0000%        | 0.0000%        | 0.0000%        |
| Rò rỉ nền 4 góc (Bg Leakage)       | 0.0000%        | 0.0000%        | 0.0000%        |
| Rò rỉ tai / cổ / áo                | 0.0000%        | 0.0000%        | 0.0000%        |
| Độ phủ tóc (Hair Coverage)         | 4.90%          | 4.90%          | 5.60%          |
| Trạng thái cơ học (Verdict)        | FAIL           | PASS           | PASS           |
+------------------------------------+----------------+----------------+----------------+
```

---

## 3. BẰNG CHỨNG HÌNH ẢNH ĐỐI CHỨNG
Bức ảnh đối chứng độ tương quan vân tóc đã được trích xuất và tổng hợp:
- **File đối chứng:**  
  [`TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/platinum_curly_texture_restoration_comparison.png`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/platinum_curly_texture_restoration_comparison.png)

### Nhận Xét Trực Quan:
1. **Bảo toàn nếp uốn lọn tóc:** Từng nếp sóng xoăn của sợi tóc giữ nguyên được dải bóng đổ cục bộ (local ambient occlusion shadow), không còn hiện tượng phẳng hóa màu sơn.
2. **Loại bỏ hoàn toàn viền halo:** Đường tiếp giáp giữa sợi tóc vàng bạch kim và nền tối xung quanh có độ chuyển tiếp mượt mà, không có vệt sáng viền giả tạo.
3. **Màu tóc bạch kim ánh tự nhiên:** Sự kết hợp giữa chiếu sáng nền tần số thấp trong không gian OKLab và vi hạt dải tần cao của tóc gốc đem lại cảm giác tóc nhuộm salon chân thực.
