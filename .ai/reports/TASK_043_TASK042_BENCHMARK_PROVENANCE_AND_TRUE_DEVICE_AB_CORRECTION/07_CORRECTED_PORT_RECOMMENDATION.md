# 07. CORRECTED PORT RECOMMENDATION ROADMAP

**Task ID**: `TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION_ACTIVE`  
**Governing Standard**: `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Policy**: EVIDENCE-BASED REVISION OF TASK_042 RECOMMENDATIONS — NO CODE MUTATION IN TASK_043  

---

## 1. Rà Soát & Điều Chỉnh Quyết Liệt Khuyến Nghị Của TASK_042

Dựa trên các bằng chứng đo kiểm thực tế trên hai phần cứng Samsung Galaxy A07 và Galaxy A50s, danh mục đề xuất tích hợp từ `TASK_042` bắt buộc phải được điều chỉnh căn bản:

```
+--------------------------------------------------------------------------------+
|                        MA TRẬN QUYẾT ĐỊNH TÍCH HỢP MỚI                         |
+-----------------------------------+--------------------------------------------+
| Ứng viên V1 trong TASK_042         | Phán quyết điều chỉnh trong TASK_043       |
+-----------------------------------+--------------------------------------------+
| 1. Directional Filter (P1 cũ)     | ❌ BÁC BỎ ĐẠI TRÀ -> CHUYỂN SANG CỔNG CHẶN |
| 2. Soft-Knee Tanh Chroma (P2 cũ)  | ✅ NÂNG LÊN ƯU TIÊN 1 (ACCEPT FOR PORT)    |
| 3. Landmark Barrier (P6 cũ)       | ✅ NÂNG LÊN ƯU TIÊN 2 (ACCEPT FOR PORT)    |
| 4. Marschner Dual-Lobe (P5 cũ)    | ✅ DUY TRÌ ƯU TIÊN 3 (ACCEPT FOR PORT)     |
| 5. Pipeline Coordinator C++       | ⛔ TUYỆT ĐỐI CẤM (DESTROY GPU PIPELINE)    |
+-----------------------------------+--------------------------------------------+
```

---

## 2. Chi Tiết Danh Mục Khuyến Nghị Đã Hiệu Chỉnh

### Ưu Tiên 1 (CẤP THIẾT): Soft-Knee Tanh Gamut Compression
- **Nguồn trích xuất**: `hair_v2_color.cpp` (`softChromaCompress`)
- **Vị trí tích hợp mục tiêu**: Vulkan Compute Shader `hair_composite_blend.comp` (hoặc `lib-core-graphics/src/main/cpp/src/hair/hair_color_pipeline.cpp`)
- **Căn cứ thực nghiệm**:
  - Giảm **$25.49\%$** pixel cháy sáng trên tóc xoăn và **$33.33\%$** trên tóc nam gợn sóng.
  - Độ lệch màu cảm thụ $\Delta E_{AB} < 0.03$ (mắt người không nhận ra sự thay đổi màu sắc của salon dye).
  - Độ phức tạp $O(1)$, không tốn bộ nhớ đệm, hoàn toàn tương thích với pipeline GPU Vulkan hiện hữu.

### Ưu Tiên 2 (AN TOÀN BẢO VỆ): Secondary Landmark Geometric Protection Barrier
- **Nguồn trích xuất**: `hair_v2_barrier.cpp` (`buildAnatomicalProtectionMask`)
- **Vị trí tích hợp mục tiêu**: `lib-core-graphics/src/main/cpp/src/hair/hair_pipeline_v2.cpp`
- **Căn cứ thực nghiệm**:
  - Đóng vai trò lớp phòng thủ chiều sâu thứ hai (Defense-in-depth) bảo vệ vành tai, trán và lông mày khi BiSeNet gặp góc nghiêng lớn (Yaw/Pitch $> 10^\circ$).
  - Hoàn toàn độc lập với luồng xử lý ảnh; chỉ kích hoạt khi có lưới điểm landmark 106 điểm.

### Ưu Tiên 3 (THẨM MỸ NÂNG CAO): Marschner Dual-Lobe Anisotropic Specular Sheen
- **Nguồn trích xuất**: `hair_v2_specular.cpp` (`computeAnisotropicHairSheen`)
- **Vị trí tích hợp mục tiêu**: `lib-core-graphics/src/main/cpp/src/hair/hair_anisotropic_specular_engine.cpp`
- **Căn cứ thực nghiệm**:
  - Bổ sung thùy phản xạ thứ hai (secondary tinted cuticle reflection lobe) nghiêng $-3^\circ$, tạo dải bóng suôn mượt tự nhiên cho tóc dài thẳng (`portrait_model2_long_straight`).

---

## 3. Danh Mục Bị Bác Bỏ & Đặt Cổng Chặn Nghiêm Ngặt

### 1. BÁC BỎ LỌC ĐỊNH HƯỚNG ĐẠI TRÀ (Unconditioned Directional Filter Rejection)
- **Module**: `hair_v2_directional_filter.cpp` (`directionalFilter1D`)
- **Lý do bác bỏ**:
  - Gây suy giảm kết cấu thực tế từ **$-2.32\%$** đến **$-73.81\%$** trên tóc nam gợn sóng và tóc tơ blonde.
  - Gây bùng nổ thời gian thực thi CPU gấp **$15\times – 19\times$** (tốn 586 ms trên Helio G99 và 1,341 ms trên Exynos 9611), phá vỡ giới hạn thời gian phản hồi UI ($<200$ ms).
  - Làm tăng gấp đôi bộ nhớ RAM đỉnh (+51.9 MB).
- **Điều kiện mở lại (Conditional Gating Protocol)**:
  Chỉ được phép xem xét tích hợp lại trong tương lai nếu thỏa mãn đồng thời 3 điều kiện:
  1. **Cổng phân loại nội dung**: Chỉ kích hoạt trên tóc nữ dài xoăn có độ đồng hướng dòng chảy $\text{Coherence} > 0.65$ và bước sóng cong $> 15\text{ px}$. Tuyệt đối bỏ qua đối với tóc nam cắt ngắn hoặc tóc tơ.
  2. **Tăng tốc phần cứng**: Bắt buộc viết lại bằng Vulkan Compute Shader để khai thác năng lực tính toán song song của GPU (Mali-G57 / Mali-G72), không được chạy trên CPU.
  3. **Vượt qua cổng kiểm thử A/B**: Đảm bảo $\Delta R_{tex} \ge 0.0\%$ trên toàn bộ 8 chân dung chuẩn.

### 2. CẤM THAY THẾ KIẾN TRÚC ĐIỀU PHỐI (Pipeline Coordinator Rejection)
- **Module**: `hair_v2_pipeline.cpp`
- **Lý do nghiêm cấm**: Bộ điều phối monolithic CPU của V1 hoàn toàn thiếu vắng cơ chế Vulkan GPU dispatch, không có JNI async threading và can thiệp thô bạo vào ranh giới P0 (`tau_aspect = 1.80`). Việc thay thế sẽ phá hủy hoàn toàn kiến trúc hiện tại của CONVERT2.

---

## 4. Lộ Trình Triển Khai Cho Task Tiếp Theo

1. **Giai đoạn 1**: Tạo nhánh task chuyên trách để đưa `softChromaCompress` vào shader Vulkan `hair_composite_blend.comp`.
2. **Giai đoạn 2**: Đưa `buildAnatomicalProtectionMask` vào tầng tiền xử lý JNI native.
3. **Giai đoạn 3**: Chạy lại bộ kiểm thử A/B tự động trên Galaxy A07 và Galaxy A50s để khẳng định không còn bất kỳ ca suy giảm chất lượng nào.
