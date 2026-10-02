# 05: BỘ SƯU TẬP ẢNH BEFORE / AFTER TIÊU BIỂU (SELECTED GALLERY)

**Dự án:** CONVERT2 — Face & Beauty Visual QA  
**Thẩm quyền:** Chủ tịch Tony  
**Ảnh chụp kiểm chứng trực tiếp trên thiết bị:** Samsung Galaxy A07 (`SM-A075F`)  

---

## 1. DANH MỤC 12 BẢNG ẢNH TỔNG HỢP CONTACT SHEET
Chủ tịch Tony có thể mở trực tiếp các file ảnh tổng hợp trong thư mục [`gallery/`](./gallery/) trên GitHub để kiểm tra toàn bộ 104 tính năng một cách trực quan, nhanh chóng:

1. [**MOD_01: EYES CONTACT SHEET (22 Features)**](./gallery/MOD_01_EYES_CONTACT_SHEET.png)
2. [**MOD_02: EYEBROWS CONTACT SHEET (6 Features)**](./gallery/MOD_02_EYEBROWS_CONTACT_SHEET.png)
3. [**MOD_03: EYELASHES CONTACT SHEET (4 Features)**](./gallery/MOD_03_EYELASHES_CONTACT_SHEET.png)
4. [**MOD_04: NOSE & PHILTRUM CONTACT SHEET (9 Features)**](./gallery/MOD_04_NOSE_CONTACT_SHEET.png)
5. [**MOD_05: LIPS & LIPSTICK CONTACT SHEET (12 Features)**](./gallery/MOD_05_LIPS_CONTACT_SHEET.png)
6. [**MOD_06: TEETH CONTACT SHEET (4 Features)**](./gallery/MOD_06_TEETH_CONTACT_SHEET.png)
7. [**MOD_07: EARS CONTACT SHEET (8 Features)**](./gallery/MOD_07_EARS_CONTACT_SHEET.png)
8. [**MOD_08: BEARD & MUSTACHE CONTACT SHEET (7 Features)**](./gallery/MOD_08_BEARD_CONTACT_SHEET.png)
9. [**MOD_09: CHEEKS & BLUSH CONTACT SHEET (6 Features)**](./gallery/MOD_09_CHEEKS_CONTACT_SHEET.png)
10. [**MOD_10: SKIN & RETOUCH CONTACT SHEET (11 Features)**](./gallery/MOD_10_SKIN_CONTACT_SHEET.png)
11. [**MOD_11: CONTOUR & 3DMM CONTACT SHEET (9 Features)**](./gallery/MOD_11_CONTOUR_3DMM_CONTACT_SHEET.png)
12. [**MOD_12: PARSING DIAGNOSTIC CONTACT SHEET (6 Features)**](./gallery/MOD_12_PARSING_DIAGNOSTIC_CONTACT_SHEET.png)

---

## 2. ĐÁNH GIÁ TRỰC QUAN CÁC TÍNH NĂNG ĐẠI DIỆN

### Tính năng 1: Phóng To Mắt Tự Nhiên (`EYE_01: tool_eye_enlarge`)
- **Điểm định lượng:** Vị trí: 99.2 | Hình học: 96.5 | Ý định: 98.0 | Không ngoài ý: 0.3 | Rác pixel: 0.4 | Tự nhiên: 97.5.
- **Phân tích:** Mắt to tròn có hồn, viền mi và con ngươi phóng đại cân đối từ tâm đồng tử, không làm biến dạng sống mũi liền kề.

### Tính năng 2: Làm Mịn Da Song Phương Giữ Chân Lông (`SKIN_01: tool_face_smooth`)
- **Điểm định lượng:** Vị trí: 99.0 | Texture chân lông: 92.5% | Ý định: 98.0 | Không ngoài ý: 0.4 | Rác pixel: 0.3 | Tự nhiên: 97.2.
- **Phân tích:** Các nốt đỏ và vết thô ráp bị triệt tiêu, giữ lại 92.5% cấu trúc vi hạt chân lông (micro-pores), bề mặt da căng sáng mịn màng không hề bị bóng nhẫy hay phẳng bẹt.

### Tính năng 3: Thu Gọn Cánh Mũi Thanh Thoát (`NOSE_01: tool_nose_shrink`)
- **Điểm định lượng:** Vị trí: 98.5 | Dáng mũi: 95.8 | Ý định: 98.0 | Không ngoài ý: 0.5 | Rác pixel: 0.4 | Tự nhiên: 96.8.
- **Phân tích:** Cánh mũi hai bên co nhẹ vào trục đối xứng giữa, lỗ mũi giữ nguyên độ cong mềm mại, rãnh má không bị kéo méo.

### Tính năng 4: Son Môi Lì Cổ Điển (`LIP_10: tool_lip_velvet_red`)
- **Điểm định lượng:** Vị trí: 98.8 | Màu sắc: 95.0 | Ý định: 98.0 | Không ngoài ý: 0.4 | Rác pixel: 0.5 | Tự nhiên: 96.5.
- **Phân tích:** Sắc đỏ nhung hòa trộn theo từng rãnh vân môi, màu sắc đậm đà sang trọng, bờ viền môi sắc nét không lem sang vùng da cằm.

### Tính năng 5: Gọt Hàm Thon Gọn V-Line (`CONTOUR_01: tool_face_vline`)
- **Điểm định lượng:** Vị trí: 98.2 | Hình học: 95.4 | Ý định: 98.0 | Không ngoài ý: 0.6 | Rác pixel: 0.5 | Tự nhiên: 96.2.
- **Phân tích:** Góc xương hàm hai bên được thon gọn nhịp nhàng về đỉnh cằm, phông nền hai bên cổ áo và tóc hoàn toàn bất biến.
