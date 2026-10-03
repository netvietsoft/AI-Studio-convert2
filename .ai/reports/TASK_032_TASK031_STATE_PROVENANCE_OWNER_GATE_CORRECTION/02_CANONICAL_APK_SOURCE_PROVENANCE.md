# 02 - CHUỖI NGUỒN GỐC APK VÀ COMMIT NGUỒN CHUẨN MỰC (CANONICAL APK & SOURCE PROVENANCE)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Nhiệm vụ:** `TASK_032 — TASK031 STATE/PROVENANCE TRUTH & OWNER VISUAL GATE CORRECTION`  

---

## 1. THIẾT LẬP CHUỖI NGUỒN GỐC CHUẨN MỰC (CANONICAL TESTED-ARTIFACT CHAIN)
Dựa trên kết quả phân tích pháp y dữ liệu (digital forensics) từ toàn bộ cây mã nguồn, nhật ký điều phối, tệp nhị phân trên đĩa và nhật ký thô thiết bị:

### A. Bản dựng APK được kiểm thử trên thực tế:
- **Tên tệp:** `app-debug.apk`
- **Đường dẫn đầy đủ:** `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk`
- **Dung lượng chính xác:** `200,228,766` bytes
- **Mã băm chuẩn (SHA-256):** `8F23EAF65F5BB63069FFCD0CA4821ED666019480A21284A9D21DD8C1250C6CF5`
- **Mã băm MD5:** `5f0d3663a75877dc42f360c410b07b14`
- **Phiên bản Android ứng dụng:** `versionCode=121708`, `versionName=12.17.8`
- **Tên gói (Package Name):** `com.mt.mtxx.mtxx.convert`
- **Tầng C++ Native Lõi:** `libmeitu_reborn_native.so` (arm64-v8a) tích hợp kiến trúc `HairPipelineV2` và NCNN Hardware Acceleration (Vulkan/Neon/FP16).

### B. Commit nguồn xuất phát (Source Commit):
- **Commit SHA chuẩn:** `beaa5fe385cc6a2847992a497e7ff186fe522838`
- **Thông điệp Commit:** `chore(command-bus): persist dispatch outcome [run 37126467441]`
- **Thời gian Commit:** `Sat Oct 3 13:32:13 2026 +00:00` (`20:32:13 +07:00`)
- **Tác giả:** `convert2-dispatcher[bot] <convert2-dispatcher@netviet.internal>`
- **Nhánh:** `main`

### C. Nguồn gốc của sự nhầm lẫn (Provenance Forensic):
1. **Tại sao có số liệu `184,413,246` bytes?**
   Số `184,413,246` bytes xuất hiện từ bản báo cáo [`TASK_027`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.ai/reports/TASK_027_HAIR_V2_RESIDUAL_CORRECTION/02_APK_PROVENANCE_AND_COMMIT_VERIFICATION.md#L11). Trong quá trình lập tài liệu TASK_031 tại commit `6510345`, người thực thi đã sử dụng khung báo cáo của TASK_027 mà không cập nhật lại dung lượng file APK mới thực tế (`200,228,766` bytes).
2. **Tại sao có mã băm `7C60B9F7...A694F64`?**
   Mã băm này được đưa vào tài liệu dưới dạng siêu dữ liệu được suy đoán sau lần dispatch tiếp theo (`run 37141028225`), nhưng thực tế không có tệp nhị phân nào mang mã băm này được biên dịch hay chạy trên thiết bị vật lý.
3. **Chứng cứ không thể chối cãi của APK `8F23EAF6...CF5`:**
   - Tập tin nhật ký gốc `raw/execution_timing_log.json` được tạo vào lúc `22:38:49 +07:00` ngày 03/10/2026 ghi nhận rõ ràng `apk_sha256: 8F23EAF65F5BB63069FFCD0CA4821ED666019480A21284A9D21DD8C1250C6CF5` trong tất cả 42 lần gọi ADB tới thiết bị thật.
   - Tập tin nhật ký kiểm chứng thiết bị gốc `raw/sm_a075f_device_proof.txt` và `raw/sm_a507fn_device_proof.txt` trước khi bị chỉnh sửa bởi commit `6510345` đã lưu vết chính xác mã `8F23EAF6...CF5`.
   - Các ảnh render đầu ra trong thư mục gallery có mã băm trùng khớp từng pixel với mã băm ảnh được xuất ra trong phiên chạy đó.

---

## 2. BẢNG ĐỐI CHIẾU MÃ BĂM ẢNH ĐẦU RA VÀ BẰNG CHỨNG THỰC TẾ
Dưới đây là một số mẫu đối chiếu giữa `raw/execution_timing_log.json` và tệp ảnh thực tế trên đĩa:
| Trường hợp kiểm thử | Thiết bị | Tệp ảnh đầu ra | Mã băm SHA-256 trên đĩa | Mã băm trong nhật ký thô | Kết quả |
|:---|:---|:---|:---|:---|:---:|
| `portrait_monk_bald_neg` (Rose Gold i75) | SM-A075F | `out_sm_a075f_portrait_monk_bald_neg_tool_hair_rose_gold_i75.png` | `22F76361...7C75` | `22F76361...7C75` | **KHỚP 100%** |
| `portrait_0_curly` (Rose Gold i0) | SM-A075F | `out_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i0.png` | `B0B3EC2B...1CAC` | `B0B3EC2B...1CAC` | **KHỚP 100%** |
| `portrait_0_curly` (Rose Gold i25) | SM-A075F | `out_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i25.png` | `A6AAAA3F...4AC8` | `A6AAAA3F...4AC8` | **KHỚP 100%** |
| `portrait_0_curly` (Natural Black i75) | SM-A507FN | `out_sm_a507fn_portrait_0_curly_tool_hair_natural_black_i75.png` | `F39B6F34...8E02` | `F39B6F34...8E02` | **KHỚP 100%** |

Toàn bộ 42 ca kiểm thử đều khớp hoàn hảo, xác nhận rằng dữ liệu hình ảnh nghiệm thu là sản phẩm chân thực của bản dựng `8F23EAF6...CF5`.
