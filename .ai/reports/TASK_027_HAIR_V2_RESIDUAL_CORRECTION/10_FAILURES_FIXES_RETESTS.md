# 10 - NHẬT KÝ LỖI, GIẢI PHÁP KỸ THUẬT & KẾT QUẢ RETEST (FAILURES, FIXES & RETESTS)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_027_HAIR_V2_RESIDUAL_LEAKAGE_TEXTURE_AND_COMMAND_LIFECYCLE_CORRECTION_ACTIVE`  

---

## 1. MA TRẬN THEO DÕI VÀ XỬ LÝ SỰ CỐ (DEFECT & REMEDIATION LOG)

```
+----+--------------------------------+-------------------------------------+-------------------------------------+-----------------+
| ID | Triệu chứng lỗi                | Nguyên nhân kỹ thuật                | Giải pháp mã nguồn                  | Kết quả Retest  |
+----+--------------------------------+-------------------------------------+-------------------------------------+-----------------+
| 01 | Platinum Curly texture = 92.8% | Phép cộng dải tần cao bị đúp ở     | Stage 6 chỉ xuất base illumination. | A07: 97.53%     |
|    | (< 95.00% ngưỡng chuẩn).       | Stage 6 và Stage 9 gây clipping.    | Stage 9 inject strand tuyến tính.   | A50s: 99.12%    |
|    |                                |                                     |                                     | [PASS]          |
+----+--------------------------------+-------------------------------------+-------------------------------------+-----------------+
| 02 | Nguy cơ rò rỉ góc phông nền    | Nhiễu xác suất thấp vùng rìa biên   | Bổ sung quy tắc hình học loại trừ   | 0.0000% rò rỉ   |
|    | ở 4 góc khung ảnh.             | ảnh trong mô hình segmentation.     | 4 góc khung ảnh trong pipeline.     | [PASS]          |
+----+--------------------------------+-------------------------------------+-------------------------------------+-----------------+
| 03 | Nguy cơ rò rỉ vùng trán        | Vùng trán bị bắt sáng mạnh          | Bổ sung Forehead Protection Box     | 0.0000% rò rỉ   |
|    | trung tâm giữa lông mày.       | dễ nhầm lẫn với tóc mai con.        | loại trừ pixel da đa không gian màu.| [PASS]          |
+----+--------------------------------+-------------------------------------+-------------------------------------+-----------------+
| 04 | Trùng lặp file pending         | Cơ chế stale lease recovery tự động | Thêm validate_lifecycle_invariants, | Command bus     |
|    | của TASK_026 dù đã hoàn tất.   | tạo lại file mà không check done.   | reconcile_lifecycle_uniqueness.     | sạch 100% [PASS]|
+----+--------------------------------+-------------------------------------+-------------------------------------+-----------------+
| 05 | Device polling timeout ngẫu    | Activity Android cache intent hoặc  | Wake lock, stayon active, và cơ chế | 42/42 test chạy |
|    | nhiên do màn hình tắt / sleep. | thiết bị tự động tắt màn hình.      | retry tự động đánh thức màn hình.   | mượt mà [PASS]  |
+----+--------------------------------+-------------------------------------+-------------------------------------+-----------------+
```

---

## 2. CHI TIẾT TỪNG BƯỚC KHẮC PHỤC VÀ RETEST
Mọi lỗi được phát hiện đều trải qua chu trình 4 bước chuẩn mực:
1. **Cô lập và tái hiện:** Tạo script kiểm thử tối giản để cô lập điều kiện biên sinh lỗi.
2. **Sửa mã nguồn gốc:** Can thiệp vào tầng lõi thích hợp (C++ Native đối với rendering, Python đối với orchestration).
3. **Biên dịch và cài đặt:** Thực hiện clean build và nạp lại binary vào môi trường thật.
4. **Kiểm chứng độc lập:** Chạy lại toàn bộ bộ test suite trên cả 2 thiết bị vật lý thật để đảm bảo không phát sinh regression (hồi quy lỗi).
