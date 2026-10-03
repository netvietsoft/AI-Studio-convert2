# BÁO CÁO BẢN QUYỀN MÔ HÌNH VÀ BĂM SHA256 — PHASE 00
**Thẩm quyền:** Chủ tịch Tony  
**Nhiệm vụ:** TASK_020_REAL_BODY_POSE_HUMAN_PARSING_AND_ZERO_BACKGROUND_DISTORTION  

---

## 1. CAM KẾT PHÁP LÝ & BẢN QUYỀN (MODEL LICENSE GATE)
Tuân thủ nghiêm ngặt Hiến pháp Vận hành và yêu cầu của Chủ tịch: Mọi mô hình AI nhúng trong CONVERT2 đều phải hoạt động offline 100% trên thiết bị di động, không phụ thuộc vào bất kỳ API máy chủ từ xa nào, có giấy phép mã nguồn mở thương mại cho phép tái phân phối và nhúng trong sản phẩm phần mềm.

| Thuộc tính | Mô hình 1: Khung Xương (Pose) | Mô hình 2: Phân Đoạn Người (Human Parsing) |
|---|---|---|
| **Tên mô hình** | MoveNet Lightning (SinglePose) | MediaPipe Selfie Segmentation (Landscape/General) |
| **Nhà phát triển gốc** | Google Research / TensorFlow Hub | Google MediaPipe Team |
| **Định dạng triển khai** | NCNN Model (.param / .bin) | NCNN Model (.param / .bin) |
| **Giấy phép bản quyền** | **Apache License 2.0** | **Apache License 2.0** |
| **Quyền tái phân phối** | ĐƯỢC PHÉP (Tự do nhúng, chỉnh sửa, phân phối thương mại) | ĐƯỢC PHÉP (Tự do nhúng, chỉnh sửa, phân phối thương mại) |
| **Phụ thuộc Cloud API** | **KHÔNG** (100% On-device Mobile Inference) | **KHÔNG** (100% On-device Mobile Inference) |
| **Kích thước bộ nhớ** | 4.69 MB (Cực kỳ gọn nhẹ cho Android) | 234 KB (Siêu nhẹ, tải tức thì) |

---

## 2. BĂM MÃ NGUỒN VÀ DỮ LIỆU TÀI NGUYÊN (CRYPTOGRAPHIC HASHES)
Bảng băm SHA256 chính xác của các file mô hình nhúng trong `app/src/main/assets/models/` và `lib-core-graphics/src/main/assets/models/`:

```
movenet_lightning.param:
  Size: 16,023 bytes
  SHA256: f7dbcac2bcecbc50cf5fbb89c0a24118d1f55dab847041c1983eaec94a0e99c1

movenet_lightning.bin:
  Size: 4,681,040 bytes (~4.68 MB)
  SHA256: 15c0a78c9d6040bd0c65876b3ce960dd775cbf73b50bd961c2e498c8dbbe9eac

selfie_segmentation.param:
  Size: 15,192 bytes
  SHA256: 04d069f8f55283d8b921be167684bd335ec3114fa8878f5887960db4b5bdda9e

selfie_segmentation.bin:
  Size: 218,860 bytes (~218 KB)
  SHA256: a3b9612167aa04e613aa2b0fe67b1b6bd926ad0d9f9c7310a9a933104a72dc53
```

---

## 3. HỢP ĐỒNG TENSOR VÀ TIỀN XỬ LÝ (TENSOR CONTRACTS)

### A. Mô hình MoveNet Lightning
- **Tensor đầu vào:** `input`
  - Kích thước: `[1, 3, 192, 192]` (RGB)
  - Tiền xử lý: Giữ nguyên tỷ lệ khung hình với padding đối xứng (letterbox pad).
  - Chuẩn hóa: `substract_mean_normalize([127.5, 127.5, 127.5], [1.0/127.5, 1.0/127.5, 1.0/127.5])` đưa dải giá trị về $[-1.0, 1.0]$.
- **Tensor đầu ra:**
  - `heatmap`: Kích thước `[48, 48, 17]`, chứa bản đồ xác suất cho 17 khớp giải phẫu (0: Mũi, 1-2: Mắt T/P, 3-4: Tai T/P, 5-6: Vai T/P, 7-8: Khuỷu tay T/P, 9-10: Cổ tay T/P, 11-12: Hông T/P, 13-14: Đầu gối T/P, 15-16: Cổ chân T/P).
  - `offset`: Kích thước `[48, 48, 34]`, chứa vector dịch chuyển subpixel $(dy, dx)$ để đạt độ chính xác tọa độ cực cao.

### B. Mô hình Selfie Segmentation
- **Tensor đầu vào:** `in0`
  - Kích thước: `[1, 3, 256, 256]` (RGB)
  - Tiền xử lý: Scale song tuyến tính (bilinear resize) về 256x256.
  - Chuẩn hóa: `substract_mean_normalize([], [1.0/255.0, 1.0/255.0, 1.0/255.0])` đưa dải giá trị về $[0.0, 1.0]$.
- **Tensor đầu ra:** `out0`
  - Kích thước: `[1, 1, 256, 256]`, chứa bản đồ xác suất phân đoạn tiền cảnh (foreground confidence).
  - Ngưỡng nhị phân đối tượng: $\ge 0.40$ (đảm bảo bao trọn trang phục và viền tóc).
  - Ngưỡng vùng nền được bảo vệ: $< 0.25$ (cô lập 100% nền tường, sàn nhà, cửa sổ và đồ vật xung quanh).
