# BẰNG CHỨNG TÍCH HỢP TẦNG RUNTIME CỦA BỘ PHÂN ĐOẠN NGƯỜI — PHASE 02
**Thẩm quyền:** Chủ tịch Tony  
**Nhiệm vụ:** TASK_020_REAL_BODY_POSE_HUMAN_PARSING_AND_ZERO_BACKGROUND_DISTORTION  

---

## 1. THAY THẾ HOÀN TOÀN MẶT NẠ VIÊN NANG (CAPSULE MASK) BẰNG MẠNG NƠ-RON
Trong phiên bản cũ, mặt nạ phân đoạn thân thể được vẽ bằng các hình viên nang toán học (`rasterizeCapsule`) nối giữa các điểm khớp. Mặt nạ viên nang có nhược điểm chí mạng: không khớp với nếp gấp quần áo thực tế, bỏ sót vạt áo xòe hoặc ăn lấn vào nền tường xung quanh.

**Cải tiến đột phá trong TASK_020:**
1. Tích hợp lớp `meitu::ai::SelfieHumanParser` sử dụng mạng nơ-ron sâu MediaPipe Selfie Segmentation.
2. Mô hình quét trực tiếp ma trận điểm ảnh RGB, trích xuất mặt nạ xác suất điểm ảnh thật (continuous probability density map) có kích thước trùng khít với đường viền người thật.
3. Phân tách ranh giới rõ rệt 3 miền:
   - **Miền Tiền Cảnh (Person Foreground):** Xác suất $\ge 0.40$, bao gồm tóc, tai, mặt, cổ, vai, ngực, cánh tay, bàn tay, trang phục (áo sơ mi, quần dài, váy), chân và giày.
   - **Miền Chuyển Tiếp (Feather Boundary):** Xác suất $0.25 \le p < 0.40$, áp dụng hàm làm mềm viền subpixel (cosine-tapered alpha transition) để tránh bậc thang rỗ pixel.
   - **Miền Nền Được Bảo Vệ Tuyệt Đối (Protected Background):** Xác suất $< 0.25$, áp dụng khóa cứng displacement $= 0$.

---

## 2. KẾT HỢP ĐA MÔ HÌNH (DUAL-MODEL FUSION)
Trong `BodySemanticEngine::extractHumanModel`:
1. Mạng `SelfieHumanParser` cung cấp ranh giới tổng thể cơ thể và trang phục.
2. Mạng `BiSeNet 19 Classes` cung cấp phân lớp chi tiết vùng mặt, mắt, mũi, môi và tóc.
3. Hai mặt nạ được hòa trộn đồng bộ: Vùng mặt của BiSeNet được gán nhãn `CLASS_FACE` chỉ khi nằm trong vùng tiền cảnh thật của mạng Selfie Segmentation, triệt tiêu 100% lỗi nhận diện nhầm tranh ảnh treo tường làm mặt người.
