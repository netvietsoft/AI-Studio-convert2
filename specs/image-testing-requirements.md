# Docs/Testing/image-testing-requirements.md — QUY CHUẨN KIỂM THỬ ẢNH & VIDEO TỪNG BIT, PIXEL
# Căn cứ: F:\CONVERT\com.mt.mtxx.mtxx\Yeucau_Test_anh.txt & Chỉ thị Chủ tịch Tony
# Thẩm quyền: Chủ tịch Tony ban hành — Giám sát thực thi: CEO (Agent 0 - Orchestrator)

---

## 1. NGUYÊN TẮC TỐI CAO: REFERENCE-BASED VALIDATION

> **ĐIỀU CỐT LÕI**:
> **ẢNH GỐC LÀ GROUND TRUTH** cho mọi phần mà USER không yêu cầu thay đổi.
> **USER_REQUEST LÀ GROUND TRUTH** cho phần mà USER muốn thay đổi.
> **TUYỆT ĐỐI KHÔNG ĐƯỢC ĐÁNH GIÁ `EDITED_IMAGE` ĐỘC LẬP.**

Mọi output chỉnh sửa ảnh, video phải được kiểm thử nghiêm ngặt theo chuỗi hợp nhất:

```
ORIGINAL_IMAGE  +  USER_REQUEST  +  EDITED_IMAGE
                       ↓
           REFERENCE-BASED VALIDATION
                       ↓
             DIFF & BIT/PIXEL VERIFY
                       ↓
              SEMANTIC VALIDATION
                       ↓
              QUALITY VALIDATION
                       ↓
             PASS / RETRY / FAIL
```

---

## 2. DỮ LIỆU ĐẦU VÀO BẮT BUỘC (MANDATORY INPUTS)

Mọi ca test chỉnh sửa hình ảnh phải nhận đủ 5 tham số đầu vào:
1. `ORIGINAL_IMAGE`: Ảnh gốc tham chiếu (Ground Truth).
2. `EDITED_IMAGE`: Ảnh kết quả sau khi xử lý qua Lõi Core C++ Native (`libmeitu_reborn_native.so`).
3. `USER_REQUEST`: Yêu cầu chỉnh sửa ban đầu của người dùng/chủ tịch.
4. `TARGET_REGION`: Vùng/đối tượng dự kiến được chỉnh sửa (Bounding Box, Semantic Mask, Face Mesh, Body Joints).
5. `EDIT_PARAMETERS`: Các thông số chỉnh sửa định lượng (cường độ slider, mã màu Hex, độ mờ feathering, bán kính tác động...).

---

## 3. BỘ 12 TIÊU CHUẨN KIỂM THỬ ĐỘ CHÍNH XÁC TỪNG BIT, PIXEL

### 3.1. Kiểm Tra Đúng Vị Trí (Position Accuracy)
So sánh đối chiếu trực tiếp `ORIGINAL_IMAGE` với `EDITED_IMAGE`:
- Vùng cần sửa có được sửa đúng không?
- Có sửa nhầm vùng không?
- Có ảnh hưởng pixel/vật thể ngoài vùng yêu cầu không (Leakage Test)?
- Biên chỉnh sửa có lem không (Edge Feathering & Transition)?
- Background có bị thay đổi ngoài ý muốn không (Boundary Clamping)?
- Khuôn mặt, tóc, tay, chân, quần áo hoặc vật thể khác có bị biến dạng không?
- **Chỉ số**: `POSITION_ACCURACY = 0–100` (Ngưỡng đạt: $\ge 95$).

### 3.2. Kiểm Tra Màu Sắc (Color Accuracy)
Nếu `USER_REQUEST` có yêu cầu chỉnh sửa/áp dụng màu:
- So sánh: `TARGET_COLOR` vs `EDITED_COLOR`.
- Kiểm tra: Hue, Saturation, Brightness, Temperature, Tint.
- **Yêu cầu vật liệu**: Phải bảo toàn ánh sáng gốc (specular highlights), bóng đổ (shadows), chất cảm bề mặt (texture) và vật liệu gốc (material). Không được đạt màu bằng cách bôi bệt hoặc làm mất chi tiết vật liệu.
- **Chỉ số**: `COLOR_ACCURACY = 0–100` (Ngưỡng đạt: $\ge 90$).

### 3.3. Kiểm Tra Form / Hình Dáng (Shape & Geometry Accuracy)
Đối chiếu hình học 3 chiều: `ORIGINAL_GEOMETRY` vs `EDITED_GEOMETRY` vs `USER_REQUEST`.
- Form có đúng yêu cầu?
- Tỷ lệ có tự nhiên (Anatomical Proportions)?
- Phối cảnh (Perspective) đúng chuẩn?
- Pose có bị thay đổi ngoài ý muốn?
- Giải phẫu sinh học (Anatomy) có bị lỗi/dị tật?
- Đường cong có bị gãy méo? Quần áo có bị co rúm biến dạng vô lý?
- Chi tiết họa tiết dệt (pattern), đường may (seam), cúc áo (button), túi áo (pocket) có bị biến dạng?
- Khuôn mặt có giữ nguyên nhận dạng (Identity Preservation)?
- **Chỉ số**: `SHAPE_ACCURACY = 0–100` (Ngưỡng đạt: $\ge 92$).

### 3.4. Kiểm Tra Đúng Ý Người Dùng (User Intent - Quan Trọng Nhất)
Không chỉ hỏi "Ảnh có đẹp không?", mà bắt buộc phải hỏi: **"Ảnh có thực hiện đúng `USER_REQUEST` không?"**.
- Ví dụ vi phạm: User yêu cầu *"Đổi áo thành màu trắng, còn lại giữ nguyên"*. Kết quả áo trắng đẹp nhưng background bị mờ đi, da bị làm trắng toát, mặt bị đổi khối -> **FAIL NGAY LẬP TỨC**.
- **Chỉ số**: `USER_INTENT_SCORE = 0–100` (Ngưỡng đạt: $\ge 95$).

### 3.5. Kiểm Tra Bảo Toàn Ảnh Gốc (Original Preservation & Mask Isolation)
Thiết lập 2 vùng mặt nạ toán học:
- `EXPECTED_CHANGE_MASK`: Cho phép thay đổi theo đúng `USER_REQUEST`.
- `EXPECTED_PRESERVE_MASK`: Bắt buộc bảo lưu tối đa giống `ORIGINAL_IMAGE`.
- Kiểm tra vùng ngoài can thiệp:
  - Face identity, Pose, Body silhouette, Hair strands;
  - Background, Lighting, Surrounding objects;
  - Clothing details, Accessories, Composition, Camera perspective.
- **Chỉ số**: `UNWANTED_CHANGE_SCORE = 0–100` (Càng thấp càng tốt, Ngưỡng đạt: $\le 5$).

### 3.6. Kiểm Tra Khuyết Tật & Rỗ Pixel (Artifact Control)
Rà soát vi sai từng cụm pixel:
- Blur bất thường, ghosting, double edge, halo viền sáng quanh tóc/thân;
- Seam nếp gấp ghép nối, texture repetition, mẫu rỗ AI;
- Ngón tay/bàn tay lỗi, mắt lé/mắt dị thường, tóc bết dính giả tạo;
- Da sáp/da nhựa (Plastic skin) do làm mịn quá tay;
- Quần áo bị chảy nhão, cúc áo biến mất, khóa kéo zipper méo;
- Chi tiết nền bị uốn cong theo cơ thể;
- Ánh sáng không thống nhất giữa đối tượng can thiệp và bối cảnh.
- **Chỉ số**: `ARTIFACT_SCORE = 0–100` (Càng thấp càng tốt, Ngưỡng đạt: $\le 5$).

### 3.7. So Sánh Chất Lượng Trước / Sau (Technical & Visual Parity)
Phân tích theo 4 trục:
1. **Technical Quality**: Độ sắc nét (Sharpness), chi tiết vi mô (Micro-detail), độ nhiễu hạt (Noise), kiểm soát viền (Edge quality), độ nhất quán phân giải.
2. **Visual Quality**: Bố cục, hài hòa màu sắc, ánh sáng chân thực, tính tự nhiên.
3. **Edit Quality**: Chỉnh sửa tự nhiên, hòa nhập hoàn hảo vào bối cảnh gốc, không để lại dấu vết cắt ghép nhân tạo.
4. **User-Goal Quality**: Đầu ra phục vụ tối ưu mục đích sử dụng.
- **Kết luận bắt buộc**: `BETTER` | `EQUIVALENT` | `WORSE`. (Phân định rõ cải tiến kỹ thuật khách quan vs cảm tính thẩm mỹ).

---

## 4. BẢNG TEST BẮT BUỘC (MANDATORY SCORECARD)

Mọi báo cáo nghiệm thu thuật toán chỉnh sửa ảnh/video phải lập bảng điểm:

| TIÊU CHÍ TEST | ĐIỂM SỐ | KẾT QUẢ | ĐIỀU KIỆN ĐẠT |
|---|---|---|---|
| 1. Edit Position | xx/100 | PASS / FAIL | $\ge 95/100$ |
| 2. Color Accuracy | xx/100 | PASS / FAIL / N/A | $\ge 90/100$ |
| 3. Shape Accuracy | xx/100 | PASS / FAIL / N/A | $\ge 92/100$ |
| 4. User Intent | xx/100 | PASS / FAIL | $\ge 95/100$ |
| 5. Original Preservation | xx/100 | PASS / FAIL | $\ge 95/100$ (Unwanted $\le 5$) |
| 6. Artifact Control | xx/100 | PASS / FAIL | $\ge 95/100$ (Artifact $\le 5$) |
| 7. Technical Quality | xx/100 | PASS / FAIL | $\ge 90/100$ |
| 8. Naturalness | xx/100 | PASS / FAIL | $\ge 90/100$ |

---

## 5. ĐIỀU KIỆN HARD FAIL (ĐÁNH TRƯỢT NGAY LẬP TỨC)

Một kết quả bị đánh trượt `HARD FAIL` ngay lập tức mà không xét đến các điểm số khác nếu rơi vào các trường hợp:
1. Sửa sai đối tượng hoặc sai phân vùng.
2. Không thực hiện yêu cầu chính của người dùng/Chủ tịch.
3. Làm thay đổi khuôn mặt hoặc mất nhận dạng khi không được yêu cầu.
4. Làm thay đổi/méo bối cảnh nền hoặc vật thể xung quanh khi yêu cầu giữ nguyên.
5. Làm thay đổi form dáng sản phẩm khi chỉ yêu cầu đổi màu/vật liệu.
6. Làm mất chi tiết cấu trúc vi mô quan trọng (vi lỗ chân lông, hoa văn sợi vải, cúc áo, đường chỉ).
7. Tự ý sinh thêm hoặc xóa bỏ vật thể ngoài yêu cầu.
8. Lỗi giải phẫu cơ thể sinh học nghiêm trọng (tay thừa ngón, khớp gãy méo).
9. Output bị vỡ hạt, rỗ pixel, lem màu, rách biên.

---

## 6. QUY TRÌNH TỰ ĐỘNG KHẮC PHỤC (AUTO-RETRY PIPELINE)

Nếu kết quả kiểm thử rơi vào `FAIL`:
**TUYỆT ĐỐI CẤM gửi output hỏng cho Chủ tịch / Người dùng.**

```
GENERATE / PROCESS (Lõi C++ Native)
                ↓
    COMPARE WITH ORIGINAL (Bit/Pixel Diff)
                ↓
      VALIDATE USER REQUEST
                ↓
              FAIL?
                ↓
         ANALYZE FAILURE
                ↓
     CREATE CORRECTION INSTRUCTION
                ↓
        RE-EDIT / ADJUST PARAMS
                ↓
         COMPARE AGAIN
                ↓
          PASS (100%)
                ↓
      CHẤP THUẬN XUẤT OUTPUT
```

---

## 7. BÁO CÁO LỖI & KẾ HOẠCH KHẮC PHỤC (FAILURE REPORT & CORRECTION)

Khi gặp lỗi, hệ thống phải tự động phân loại theo chuẩn:
- `FAILURE_REASON`: `wrong_position` | `wrong_color` | `wrong_shape` | `unwanted_change` | `identity_changed` | `background_changed` | `clothing_detail_changed` | `artifact` | `unnatural` | `user_intent_not_satisfied`.
- `CORRECTION_PLAN`: Xác định chính xác preserve mask cần khóa cứng, điều chỉnh giảm bán kính tác động, tăng hệ số giảm chấn vật liệu hoặc khôi phục pixel nguyên bản từ `ORIGINAL_IMAGE`.
