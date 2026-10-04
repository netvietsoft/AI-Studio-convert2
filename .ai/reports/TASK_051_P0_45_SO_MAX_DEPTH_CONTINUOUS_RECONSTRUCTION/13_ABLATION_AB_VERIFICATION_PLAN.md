# 13_ABLATION_AB_VERIFICATION_PLAN.md — KẾ HOẠCH THỬ NGHIỆM A/B & PHÂN TÍCH TRIỆT TIÊU (ABLATION PROTOCOL)
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Mã Nhiệm vụ:** `TASK_051_P0_45_SO_MAX_DEPTH_CONTINUOUS_RECONSTRUCTION_ACTIVE`  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Mục tiêu:** Đo lường sự đóng góp chính xác của từng thành phần thuật toán được tái dựng đối với chất lượng hình ảnh đầu ra.  

---

## 1. NGUYÊN TẮC THỬ NGHIỆM ĐỐI CHỨNG A/B & TRIỆT TIÊU (ABLATION)

Để chứng minh từng phát hiện kỹ thuật đảo ngược có giá trị thực tế và không tạo ra hồi quy:
1. **Thiết bị kiểm chứng chuẩn:** Samsung Galaxy A50s (SM-A507FN) và Samsung Galaxy A07 (SM-A075F).
2. **Bộ ảnh thử nghiệm chuẩn:** 10 ảnh chân dung đại diện các tông da, cấu trúc tóc thẳng/xoăn/dài/ngắn (`photo_01` đến `photo_10`).
3. **8 Tiêu chuẩn thẩm định hình ảnh:** Position Accuracy, Color Accuracy, Shape Accuracy, User Intent, Original Preservation, Artifact Control, Technical Quality, Naturalness.

---

## 2. MA TRẬN 5 KỊCH BẢN THỬ NGHIỆM TRIỆT TIÊU (ABLATION EXPERIMENTS)

| Mã Thử Nghiệm | Thành Phần Thuật Toán Bị Triệt Tiêu (Disabled / Ablated) | Cấu Hình Đối Chứng (A/B Baseline vs Candidate) | Chỉ Số Đo Lường (Metrics) | Tác Động Dự Kiến (Hypothesis / Visual Artifacts) |
| :--- | :--- | :--- | :--- | :--- |
| `ABL-01` | **9x9 Unsharp Mask Clarity Boost (offset `0x77afa`)** | **A:** Đầy đủ 5-Pass `MTSoftHairFilter`  <br>**B:** Bỏ Unsharp Mask, chỉ dùng Gaussian Blur | Tần số chi tiết cao (Laplacian variance), Độ sắc nét sợi tóc | **Không có Unsharp Mask:** Sợi tóc bết dính như mảng sơn, mất kết cấu vi mô từng lọn tóc, điểm Naturalness giảm $>15%$. |
| `ABL-02` | **5-Tap Gaussian Blur Weights (offset `0x0008edd8`)** | **A:** Trọng số tĩnh `[0.159676, 0.263348, ...]`  <br>**B:** Trọng số hộp đều (Box blur `0.2`) | Độ mượt mà chuyển vùng sáng/tối, Dải chuyển tiếp màu sắc | **Dùng Box Blur:** Xuất hiện dải bậc thang (Color banding) và viền nhân tạo (Halo artifacts) dọc theo ranh giới lọn tóc. |
| `ABL-03` | **Pegtop SoftLight Formula (offset `0x82369`)** | **A:** Pegtop `(1-2b)*a^2 + 2b*a`  <br>**B:** Hòa trộn Multiply thuần túy `a * b` | Độ tương phản vùng highlight, Độ giữ sáng sợi tóc | **Dùng Multiply:** Tóc nhuộm bị tối sầm, cháy màu ở vùng bóng đổ, mất hoàn toàn ánh kim lấp lánh (Shine). |
| `ABL-04` | **21-Tap Directional LIC (offset `0x00024880`)** | **A:** Tích phân đường cong 21 điểm dọc hướng tiếp tuyến  <br>**B:** Lấy mẫu đẳng hướng (Isotropic blur) | Độ đẳng hướng sợi tóc (Anisotropy ratio), Độ tự nhiên của lọn xoăn | **Bỏ LIC:** Các lọn tóc xoăn mất chiều sâu, sợi tóc bị nhòe mờ cắt ngang thay vì chảy mượt theo chiều lọn tóc. |
| `ABL-05` | **Hair Mask Feathering Pass (offset `0x000f4400`)** | **A:** Cắt lọc mặt nạ có làm mềm biên  <br>**B:** Mặt nạ nhị phân cứng ngưỡng 0.5 | Độ lem da mặt/trán/tai (Leakage pixel count) | **Mặt nạ cứng:** Răng cưa viền tóc lộ rõ, lem màu sang vùng da trán và vành tai $>5%$, vi phạm Hard Gate Zero Leakage. |

---

## 3. QUY TRÌNH THỰC HIỆN & ĐÁNH GIÁ ĐỘC LẬP
1. Biên dịch các biến thể C++ engine vào `libmeitu_reborn_native.so` với cờ `#define ABLATION_MODE`.
2. Chạy lệnh kiểm thử tự động trên Galaxy A50 qua ADB runner.
3. Xuất xưởng bảng so sánh tiếp xúc (Contact Sheets) 5 khung hình lossless.
4. Đệ trình Chủ tịch Tony và Ban Giám sát độc lập thẩm định trực quan.
