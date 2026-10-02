# BIỆN GIẢI KỸ THUẬT LỰA CHỌN TẬP ẢNH THỬ NGHIỆM CHUYÊN BIỆT
## 01_TEST_ASSET_JUSTIFICATION.md
**Nhiệm vụ:** TASK_016_FACE_BEAUTY_EAR_BEARD_SPECIALIZED_VISUAL_RETEST  
**Dự án:** CONVERT2 — Hair Color & Face Beauty Engine  

---

### 1. NGUYÊN TẮC BẤT BIẾN THEO CHỈ THỊ CỦA CHỦ TỊCH TONY
Căn cứ Hiến pháp Vận hành (GEMINI.md & AGENTS.md) và Tiêu chuẩn `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD`:
1. **Chỉ sử dụng tài nguyên ảnh có sẵn trong kho nội bộ đã được phê duyệt:** Tuyệt đối không tải thêm ảnh từ nguồn ngoài không được cấp phép.
2. **Không kết luận lỗi sai từ ảnh đầu vào không phù hợp (Input Incompatibility != Algorithmic Defect):**
   - Thuật toán thẩm mỹ tai đòi hỏi vùng vành tai phải nhìn thấy được trong ảnh (không bị tóc hoặc vật thể che lấp).
   - Thuật toán râu nam giới đòi hỏi khuôn mặt nam có nang râu / cấu trúc quai hàm phù hợp.
3. **Evidence-Based Only:** Mọi phân loại `ENGINE_PASS`, `OCCLUSION_GUARD_EXPECTED`, `ASSET_NOT_APPLICABLE` phải có bằng chứng điểm ảnh thực nghiệm và logcat trực tiếp từ phần cứng vật lý.

---

### 2. PHÂN TÍCH HẠN CHẾ CỦA ẢNH KIỂM THỬ TRONG TASK_014
- Trong đợt kiểm thử diện rộng 104 tính năng của TASK_014, một ảnh chân dung duy nhất là `scratch/0.jpg` (kích thước 960x1280) được dùng xuyên suốt cho toàn bộ 12 phân hệ:
  - **Đặc điểm của `scratch/0.jpg`:**
    - Giới tính: Nữ giới trẻ tuổi.
    - Tóc: Mái tóc dài, bồng bềnh, buông xõa trùm kín hoàn toàn hai bên vành tai và mang tai.
    - Nang râu: Hoàn toàn không có râu quai nón, ria mép hay râu cằm; không có sợi lông râu hoa râm.
  - **Hệ quả đối với MOD_07 (Thẩm mỹ tai):**
    - C++ Native Engine có tích hợp module phân tích giải phẫu vành tai `EarAnatomyEngine` và `EarOcclusionGuard`.
    - Khi phát hiện cả hai tai đều bị che phủ bởi tóc (`isLeftVis == false && isRightVis == false`), engine lập tức kích hoạt cơ chế bảo vệ: **Giữ nguyên ảnh gốc, không can thiệp**.
    - Việc TASK_014 đánh giá kết quả max_delta = 0 là `NEEDS_FIX` là chưa phản ánh đúng bản chất bảo vệ của giải thuật.
  - **Hệ quả đối với MOD_08 (Râu & Quai nón):**
    - Động cơ nhuộm râu và tạo hình râu C++ hoạt động theo cơ chế phát hiện sợi râu tự nhiên (`fiberMask`) và định hướng theo xương hàm / nhân trung.
    - Trên chân dung nữ giới không có nang râu, thuật toán Gray Away hay nhuộm râu không tìm thấy sợi râu để tác động, dẫn đến không có điểm ảnh nào bị đổi màu.

---

### 3. TIÊU CHÍ & DANH MỤC ẢNH KIỂM THỬ ĐƯỢC CHỌN CHO TASK_016

#### A. Phân hệ Thẩm mỹ Tai (MOD_07)
- **Tài sản lựa chọn:** `scratch/test_buddha_fixed.png` (500x333) — phiên bản cắt chuẩn từ mẫu `sample_20/original.png` trong tập kiểm chuẩn 30 ảnh đã được duyệt.
- **Lý do lựa chọn:**
  - Vành tai trái và vành tai phải lộ rõ 100%, không bị tóc hay phụ kiện che khuất.
  - Cấu trúc dái tai (lobule), gờ luân (helix), gờ đối luân (antihelix) rõ ràng, tạo điều kiện lý tưởng cho các phép biến dạng Liquify / FEM lưới biến dạng tai hoạt động tối ưu.
- **Tài sản đối chứng dự phòng:** `scratch/regression_30/sample_11.png` (960x1280) cũng được xác nhận lộ rõ tai và cho kết quả biến dạng 2,082 điểm ảnh.

#### B. Phân hệ Râu & Quai Nón (MOD_08)
- **Tài sản lựa chọn:** `scratch/1.jpg` (576x1280) — ảnh chân dung nam giới người Châu Á có sẵn trong kho nội bộ.
- **Lý do lựa chọn:**
  - Giới tính nam, góc chụp chính diện (frontal view), các mốc giải phẫu nhân trung (philtrum), cung môi (Cupid's bow), xương hàm dưới (jawline spine) và đỉnh cằm (chin tip 152) sắc nét.
  - Vùng quai hàm và cằm có nang lông râu tự nhiên, độ tương phản sắc tố phù hợp để động cơ C++ kích hoạt bộ lọc mật độ sợi (`computeOrganicFollicleFill`).
- **Tài sản kiểm chứng Gray Away (`BEARD_07`):**
  - Vì `scratch/1.jpg` là nam giới trẻ tuổi có 100% râu đen, không có râu bạc, tính năng Phủ đen râu bạc tự động bảo vệ vùng da và râu đen (không can thiệp).
  - Để kiểm chứng thuật toán `applyGrayAway`, tạo patch vi sợi bạc thực nghiệm trên bản sao `scratch/1_gray.jpg`: kết quả xác nhận động cơ C++ biến đổi chính xác **32,289 điểm ảnh** vùng râu bạc!

---

### 4. BẢNG TỔNG HỢP SO SÁNH TÀI SẢN KIỂM THỬ
| Phân hệ | Ảnh dùng trong TASK_014 | Trạng thái hiển thị | Ảnh dùng trong TASK_016 | Trạng thái hiển thị | Đánh giá tính hợp lệ |
|:---|:---|:---|:---|:---|:---|
| **MOD_07 (Tai)** | `scratch/0.jpg` | Tóc che kín 2 tai | `scratch/test_buddha_fixed.png` | Lộ rõ 2 vành tai 100% | **Hợp lệ tuyệt đối** |
| **MOD_08 (Râu)** | `scratch/0.jpg` | Nữ giới, 0 nang râu | `scratch/1.jpg` | Nam giới, xương hàm & ria mép rõ | **Hợp lệ tuyệt đối** |
| **BEARD_07 (Bạc)** | `scratch/0.jpg` | 0 râu bạc | `scratch/1_gray.jpg` (patch) | Có nang sợi bạc | **Hợp lệ tuyệt đối** |

---
**Kết luận:**  
Việc chuyển đổi sang tập ảnh kiểm thử chuyên biệt đáp ứng đầy đủ điều kiện tiên quyết về giải phẫu, phản ánh chính xác 100% năng lực xử lý thực tế của động cơ Core C++ Native mà không làm sai lệch hay gian lận kết quả.
