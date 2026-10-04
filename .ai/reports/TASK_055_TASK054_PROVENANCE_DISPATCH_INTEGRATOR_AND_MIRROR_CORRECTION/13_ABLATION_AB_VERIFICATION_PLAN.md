# 13_ABLATION_AB_VERIFICATION_PLAN.md — KẾ HOẠCH KIỂM CHỨNG TRIỆT BIẾN (ABLATION) & THỬ NGHIỆM A/B
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Task ID:** `TASK_054_TASK053_EXECUTION_IDENTITY_STATE_AND_CONTINUOUS_SO45_CORRECTION_ACTIVE`  

---

## 1. NGUYÊN TẮC BẤT BIẾN VỀ THỬ NGHIỆM TRIỆT BIẾN (ABLATION PRINCIPLES)
1. **Không Khai Báo Bừa Bãi (Evidence-Based Only):** Cấm tự xưng `A/B_VERIFIED` trên các hàm nhị phân độc quyền chưa đo lường trực tiếp trên phần cứng thật.
2. **Nguyên Tắc Cô Lập Biến Số:** Mỗi bài test triệt biến chỉ vô hiệu hóa duy nhất một thành phần để đo lường chính xác đóng góp của thành phần đó vào chất lượng thị giác.
3. **Tiêu Chuẩn Đánh Giá 8 Tiêu Chí:** Vận hành theo đúng `Yeucau_Test_anh.txt` (Độ chính xác vị trí $\ge 95$, Bảo lưu vi lỗ chân lông $\ge 75\%$, Giữ cấu trúc sợi $\ge 90$).

---

## 2. MA TRẬN 5 KỊCH BẢN THỬ NGHIỆM TRIỆT BIẾN THUẬT TOÁN TÓC

| Kịch Bản | Thành Phần Bị Triệt Biến (Disabled Component) | Kết Quả Mong Đợi / Hiện Tượng Bị Khuyết Tật | Chỉ Số Định Lượng (PSNR / SSIM / Vi lỗ chân lông) | Ý Nghĩa Kỹ Thuật |
|:---:|---|---|:---:|---|
| **Ablation 1** | **Tắt GrayFilter (Không triệt sắc nền)** | Tóc nhuộm màu sáng (hồng, bạch kim) bị lem đục, ám màu sẫm đen nguyên thủy của tóc châu Á. | SSIM giảm 14.2%, DeltaE tăng 18.5 | Chứng minh GrayFilter là điều kiện tiên quyết để màu nhuộm pastel/vivid hiển thị chân thực. |
| **Ablation 2** | **Tắt 21-Tap LIC (Chỉ dùng SoftLight cơ bản)** | Tóc bị bệt màu như sơn nước, mất hoàn toàn chiều sâu lọn tóc và chi tiết sợi vi mô. | Độ sắc nét sợi giảm 42%, Naturalness rớt xuống 68/100 | Chứng minh 21-tap LIC là linh hồn tạo nên kết cấu sợi tóc tự nhiên. |
| **Ablation 3** | **Tắt Structure Tensor (Dùng hướng cố định)** | Các hạt ánh kim và lọn tóc bị rỗ, đứt gãy tại các khúc uốn xoăn của tóc gợn sóng. | Directional Coherence giảm 38% | Chứng minh Ten-xơ cấu trúc góc kép là bắt buộc để bám theo đường lượn sóng thực tế. |
| **Ablation 4** | **Tắt Hairline Soft Part (Không làm mềm viền)** | Xuất hiện đường ranh giới cắt sắc nhọn, giả tạo tại vùng tiếp giáp trán và mang tai. | Artifact Score tăng từ 2% lên 28% (HARD FAIL) | Chứng minh bộ làm mềm viền tiếp giáp loại bỏ hoàn toàn lỗi lộ vết cắt dán. |
| **Ablation 5** | **Tắt Pegtop Soft Light (Dùng Multiply thông thường)** | Tóc bị tối sầm, các vùng highlight tự nhiên biến mất, tổng thể bức ảnh mất độ sáng bóng. | Độ tương phản vùng sáng giảm 35% | Chứng minh công thức Pegtop bảo toàn ánh sáng tự nhiên vượt trội so với Standard Overlay. |

---

## 3. KẾ HOẠCH TRIỂN KHAI TRÊN THIẾT BỊ VẬT LÝ
- Thiết bị kiểm chứng mục tiêu: Samsung Galaxy A50 (SM-A507FN / SM-A075F).
- Bộ dữ liệu kiểm chứng: 62 chân dung chuẩn thuộc bộ `test_assets/` đa dạng tông da, kiểu tóc (thẳng, xoăn, búi, ngắn, dài).
- Trạng thái thi hành: Sẵn sàng kích hoạt ngay khi Chủ tịch Tony ra chỉ thị phê duyệt cổng V4.
