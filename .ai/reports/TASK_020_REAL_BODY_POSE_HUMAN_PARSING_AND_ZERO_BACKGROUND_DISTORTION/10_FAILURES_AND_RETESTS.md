# NHẬT KÝ LỖI PHÁT HIỆN, SỬA CHỮA VÀ TÁI KIỂM TRA — PHASE 09
**Thẩm quyền:** Chủ tịch Tony  
**Nhiệm vụ:** TASK_020_REAL_BODY_POSE_HUMAN_PARSING_AND_ZERO_BACKGROUND_DISTORTION  

---

## 1. DANH SÁCH LỖI PHÁT HIỆN VÀ BIỆN PHÁP KHẮC PHỤC

### Lỗi 1: TypeError giải nén dòng trong `analyze_structural_lines`
- **Hiện tượng:** Khi chạy bộ kiểm thử tự động, hàm OpenCV `cv2.HoughLinesP` trả về mảng có định dạng `(N, 1, 4)`. Khi truy cập `line[0]`, một số phiên bản OpenCV trả về mảng con khiến lệnh unpack `x1, y1, x2, y2 = line[0]` báo lỗi `TypeError: cannot unpack non-iterable numpy.int32 object`.
- **Khắc phục:** Sử dụng hàm phẳng hóa `pts = line.reshape(-1)`, kiểm tra độ dài `len(pts) >= 4`, gán tường minh `x1, y1, x2, y2 = int(pts[0]), int(pts[1]), int(pts[2]), int(pts[3])`, và dùng `np.clip` giới hạn tọa độ trong biên ảnh.
- **Kết quả tái kiểm tra:** 100% kịch bản chạy mượt mà, phân tích chính xác độ lệch đường thẳng kiến trúc.

### Lỗi 2: Nguy cơ méo ảnh khi chỉnh sửa ảnh chụp bán thân / cận ngực (Bust Crop)
- **Hiện tượng:** Với ảnh chụp cận cảnh chỉ có mặt và ngực, các khớp hông và đầu gối không xuất hiện. Nếu cố ép nắn bóp chân (`tool_long_legs`, `tool_body_height`), các tọa độ giả lập cũ sẽ kéo dãn méo mép dưới bức ảnh.
- **Khắc phục:** Triển khai cơ chế bảo vệ `Joint Visibility Guard`. Nếu tỷ lệ chiều cao sẵn có dưới ngực nhỏ hơn 2.2 lần chiều cao đầu hoặc độ tin cậy khớp chân $< 0.20$, công cụ trả về trạng thái `PASS_GUARDED` và giữ nguyên 100% điểm ảnh gốc.
- **Kết quả tái kiểm tra:** Kịch bản SCENARIO_14 và SCENARIO_21 đạt chuẩn `PASS_GUARDED`, 0 pixel bị biến dạng ngoài ý muốn.
