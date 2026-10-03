# THIẾT KẾ GIẢI THUẬT BẢO VỆ NỀN KHÔNG BIẾN DẠNG — PHASES 03 & 04
**Thẩm quyền:** Chủ tịch Tony  
**Nhiệm vụ:** TASK_020_REAL_BODY_POSE_HUMAN_PARSING_AND_ZERO_BACKGROUND_DISTORTION  

---

## 1. NGUYÊN LÝ TOÁN HỌC KHÓA CỨNG DỊCH CHUYỂN NỀN (ZERO-DISPLACEMENT FIELD)
Yêu cầu tối cao của Chủ tịch Tony: Khi nắn bóp eo, thu nhỏ đùi, kéo dài chân hay nở ngực, **tuyệt đối không được làm cong tường, méo khung cửa, uốn cong chân bàn hay vặn xoắn gạch men**.

Để thỏa mãn điều kiện nghiêm ngặt này:
1. Trường biến dạng hình học $D(x, y) = (\Delta x, \Delta y)$ được tính toán thông qua giải thuật Moving Least Squares (MLS) Affine/Similarity Warping.
2. Hệ số suy giảm biên (boundary attenuation factor) $lpha(x, y)$ được nội suy từ mặt nạ phân đoạn người:
   $$lpha(x, y) = egin{cases} 
   1.0 & 	ext{nếu } (x, y) \in 	ext{Person Core} \
   \cos^2\left(rac{\pi}{2} \cdot rac{0.40 - p(x, y)}{0.40 - 0.25}ight) & 	ext{nếu } 0.25 \le p(x, y) < 0.40 \
   0.0 & 	ext{nếu } p(x, y) < 0.25 	ext{ (Protected Background)}
   \end{cases}$$
3. Trường dịch chuyển hiệu dụng thực tế:
   $$D_{	ext{effective}}(x, y) = lpha(x, y) \cdot D_{	ext{MLS}}(x, y)$$
   Tại mọi điểm ảnh thuộc miền nền được bảo vệ ($lpha = 0$), $D_{	ext{effective}}(x, y) \equiv (0, 0)$. Điểm ảnh gốc được sao chép nguyên vẹn từng bit màu, đảm bảo sai lệch tuyệt đối bằng **0 LSB**!

---

## 2. TÁI DỰNG VÙNG KHUYẾT LÕM THÔNG MINH (VACATED BACKGROUND RECONSTRUCTION)
Khi thực hiện thao tác co nhỏ (contraction) như bóp eo (`tool_body_waist`) hoặc thu nhỏ người (`tool_body_slim`), cơ thể người co vào trong sẽ để lộ ra một vùng khuyết lõm (vacated hole) trước đó bị che khuất.

**Khắc phục lỗi sao chép lân cận đơn giản (Ad-hoc Neighbor Copy):**
TASK_019 bị phê bình vì sao chép 1 chiều làm bệt màu. Trong TASK_020, chúng tôi triển khai cấu trúc tái dựng 2 giai đoạn:
1. **Ngoại suy đường cấu trúc (Structural Line Continuation):** Phát hiện các đường thẳng kiến trúc chạy qua mép lỗ khuyết (sử dụng biến đổi Hough cục bộ). Kéo dài liên tục các đường này xuyên qua vùng khuyết, bảo toàn hướng dốc và độ dày của mép cửa/mép tường.
2. **Nội suy Gradient Isophote (Gradient-Preserving Biharmonic Inpainting):** Lan truyền màu sắc và độ nhám (texture) từ 8 hướng lân cận dọc theo đường đẳng sáng (isophotes), giữ nguyên chiều sâu và hạt nhiễu tự nhiên của nền phòng.
