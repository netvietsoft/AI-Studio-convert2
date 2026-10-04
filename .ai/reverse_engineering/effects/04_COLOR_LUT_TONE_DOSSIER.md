# CONVERT2 — TECHNICAL EFFECT DOSSIER: COLOR SCIENCE, 3D LUT & TONE
**Authority:** Chủ tịch Tony | **Task:** TASK_047 | **Status:** PROVEN / EVIDENCE-BACKED

## 1. NỘI SUY TỨ DIỆN 3D LUT (TETRAHEDRAL INTERPOLATION)
Trích xuất từ VSCO (`libvscocamera.so` / `vsco_lut3d_tetrahedral.frag`):
- Khối lập phương màu được chia thành 6 tứ diện.
- Điểm ảnh chỉ nội suy 4 đỉnh của tứ diện tương ứng theo thứ tự `dr > dg > db`.
- Đảm bảo chuyển màu da và tóc siêu mịn, loại bỏ hoàn toàn sọc gãy bậc thang.

## 2. ĐƯỜNG CONG TÔNG MÀU BẬC 3 (PARAMETRIC CUBIC SPLINE)
Trích xuất từ Adobe Lightroom Mobile (`libacr.so`):
- Đường cong nội suy spline bậc 3 tự nhiên với điều kiện biên đạo hàm bậc 2 bằng 0.
- Độ tin cậy: **PROVEN**