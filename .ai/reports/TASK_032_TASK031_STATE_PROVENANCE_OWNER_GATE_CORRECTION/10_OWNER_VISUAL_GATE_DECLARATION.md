# 10 - TUYÊN BỐ BÀN GIAO CỔNG THẨM ĐỊNH THỊ GIÁC CHỦ TỊCH (OWNER VISUAL GATE DECLARATION)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Nhiệm vụ:** `TASK_032 — TASK031 STATE/PROVENANCE TRUTH & OWNER VISUAL GATE CORRECTION`  
**Kính gửi:** Chủ tịch Tony  

---

## 1. NGUYÊN TẮC THẨM QUYỀN TỐI CAO
Theo Điều 7 trong Hiến pháp Vận hành và Chỉ thị số 3 trong TASK_032:
> *"TASK_031 requires owner visual ground-truth. Until an actual owner visual verdict exists, repository state must not claim final PASS. Use TECHNICAL_PASS_AWAITING_OWNER_VISUAL or equivalent truthful status."*

Hệ thống AI và toàn bộ các kỹ sư phụ tá nhận thức sâu sắc rằng:
- Các chỉ số toán học (Laplacian variance, Correlation, SSIM, LSB difference, 0% leakage) là căn cứ kỹ thuật bắt buộc nhưng **không thể thay thế đôi mắt và gu thẩm mỹ trực quan của Chủ tịch Tony**.
- Một tính năng làm đẹp tóc chỉ thực sự hoàn thiện khi Chủ tịch trực tiếp trải nghiệm, nhìn thấy màu tóc lên tự nhiên, không bệt như sơn, giữ trọn độ bóng mượt và chiều sâu từng lọn tóc trên thiết bị thật.

---

## 2. TRẠNG THÁI HIỆN TẠI & HƯỚNG DẪN KIỂM CHỨNG TRỰC TIẾP
Hệ thống chính thức bàn giao trạng thái:

$$\mathbf{STATUS:\ TECHNICAL\_PASS\_AWAITING\_OWNER\_VISUAL}$$

### Các thông tin cần thiết để Chủ tịch trải nghiệm:
1. **Thiết bị Galaxy A07 (SM-A075F, MediaTek Helio G99):**
   - Đã cài sẵn ứng dụng `com.mt.mtxx.mtxx.convert`.
   - Có thể mở trực tiếp từ màn hình chính hoặc qua lệnh:
     `adb shell am start -n com.mt.mtxx.mtxx.convert/.PhotoEditorActivity`
2. **Thiết bị Galaxy A50s (SM-A507FN, Samsung Exynos 9611):**
   - Đã cài sẵn ứng dụng `com.mt.mtxx.mtxx.convert`.
3. **Thư mục ảnh kiểm chứng đã kết xuất trên máy tính:**
   - [`TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY)
   - Chứa đầy đủ 42 ảnh render so sánh các màu: Rose Gold, Ash Brown, Burgundy, Caramel, Navy Blue, Pastel Pink, Platinum, Natural Black, Smokey Silver trên cả tóc xoăn, tóc thẳng, tóc tém, tóc mái bằng và trường hợp âm tính đầu trọc.

Sau khi Chủ tịch kiểm tra trực tiếp bằng mắt và đưa ra phán quyết, hệ thống sẽ căn cứ chỉ đạo đó để xác lập mốc đóng hoàn tất dự án.
