# TASK_047 — IMAGE EFFECT GRAPH TECHNICAL SPECIFICATION
Tài liệu này dẫn chiếu trực tiếp đến file chuẩn bền vững [01_IMAGE_EFFECT_GRAPH.md](../../reverse_engineering/01_IMAGE_EFFECT_GRAPH.md).

## TÓM TẮT SỐ LƯỢNG NODE
- Tổng số Node trong đồ thị: 17 Nodes
- Phân hệ Tóc P0: 9 Nodes (100% PROVEN)
- Phân hệ Da & Mặt: 2 Nodes (100% PROVEN)
- Phân hệ Vóc Dáng: 1 Node (100% PROVEN)
- Phân hệ Màu Sắc: 2 Nodes (100% PROVEN)
- Phân hệ Trang Điểm: 1 Node (STRONG_INFERENCE)
- Phân hệ Phục Chế / Inpaint: 2 Nodes (PROVEN / STRONG_INFERENCE)

Tất cả các node đều có địa chỉ offset lệnh máy, SHA256 file nguồn, công thức toán học và GLSL shader tham chiếu.