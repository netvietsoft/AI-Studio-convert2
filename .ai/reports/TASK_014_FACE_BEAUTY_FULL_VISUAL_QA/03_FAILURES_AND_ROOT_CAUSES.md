# PHÂN TÍCH NGUYÊN NHÂN GỐC RỄ & ĐỀ XUẤT CÁC TÁC VỤ SỬA LỖI HẸP (FAILURES & ROOT CAUSES REPORT)

**Mã nhiệm vụ:** `TASK_014_FACE_BEAUTY_FULL_VISUAL_QA`  
**Dự án:** CONVERT2 — Hair Color Engine & Face/Beauty Engine  
**Cơ quan kiểm định:** Visual AI Auditor & Agent 0  
**Nguyên tắc chỉ đạo:** Không sửa mã nguồn trong TASK_014; định vị chính xác nguyên nhân gốc rễ và phân rã các tác vụ hẹp để triển khai.  

---

## 1. Danh Sách Các Lỗi Được Xác Nhận Trên Thiết Bị Vật Lý (Confirmed Defects)

| STT | Phân hệ bị ảnh hưởng | Mã lỗi | Phân loại lỗi theo Hiến pháp | Mức độ nghiêm trọng | Hiện tượng thị giác thực tế |
|:---:|:---|:---|:---|:---:|:---|
| 1 | **MOD_01 (Mắt — 22 features)** | `DEFECT_EYE_ATTACHMENT_MOUTH` | `Effect attaches to wrong anatomical region` | **CRITICAL (Hard Fail)** | Toàn bộ 22 tính năng mắt (`tool_eye_enlarge`, `tool_eye_bright`, v.v.) không tác động vào vùng mắt mà làm biến dạng và đổi màu vùng môi ($Y \in [694, 839]$). |
| 2 | **MOD_02 (Mày — 4 features)** | `DEFECT_BROW_COLOR_ROUTING` | `Effect attaches to wrong anatomical region` | **HIGH** | Các công cụ đổi màu chân mày (`tool_brow_color_*`) sử dụng tọa độ mắt tham chiếu nên bị kéo lệch xuống vùng miệng. |
| 3 | **MOD_07 (Tai — 7 features)** | `DEFECT_EAR_OCCLUSION_BYPASS` | `Before/After not visually distinguishable` | **MEDIUM** | Các công cụ nắn tai phật, tai yêu tinh (`tool_ear_buddha`..`tool_ear_thickness`) không thay đổi điểm ảnh nào (`max_diff = 0.0`) trên ảnh mẫu chuẩn `scratch/0.jpg`. |
| 4 | **MOD_08 (Râu — 6 features)** | `DEFECT_BEARD_ASSET_MISMATCH` | `Before/After not visually distinguishable` | **MEDIUM** | Các công cụ nhuộm râu, cấy ria mép (`tool_beard_dye`..`tool_beard_gray_away`) không thay đổi điểm ảnh nào (`max_diff = 0.0`) trên ảnh chân dung nữ `scratch/0.jpg`. |

---

## 2. Phân Tích Kỹ Thuật Chuyên Sâu Từng Nguyên Nhân Gốc Rễ (Deep Root Cause Analysis)

### 2.1 Nguyên nhân gốc rễ 1: Lệch chỉ mục Landmark con ngươi dự phòng (`DEFECT_EYE_ATTACHMENT_MOUTH`)
- **Tập tin phát sinh:** [`app/src/main/kotlin/com/mt/mtxx/mtxx/editor/PhotoEditorActivity.kt`](file:///C:/actions-runner/convert2/AI-Studio-convert2/AI-Studio-convert2/app/src/main/kotlin/com/mt/mtxx/mtxx/editor/PhotoEditorActivity.kt)
- **Đoạn mã có lỗi (Dòng 1702 - 1706):**
  ```kotlin
  // Eyes: 104 (left pupil), 105 (right pupil)
  lxEye = detectedIrisTrack?.leftCenterX ?: landmarks106[104 * 2]
  lyEye = detectedIrisTrack?.leftCenterY ?: landmarks106[104 * 2 + 1]
  rxEye = detectedIrisTrack?.rightCenterX ?: landmarks106[105 * 2]
  ryEye = detectedIrisTrack?.rightCenterY ?: landmarks106[105 * 2 + 1]
  ```
- **Bản chất lỗi:**
  1. Khi nạp ảnh tĩnh trên thiết bị, `detectedIrisTrack` trả về `null` vì mạng 478 Dense Mesh iris tracking chỉ kích hoạt trong luồng video/camera hoặc chưa được nạp trọng số NCNN tương thích.
  2. Khi đó, `PhotoEditorActivity` rơi vào luồng dự phòng (fallback) và đọc tọa độ từ `landmarks106[104 * 2]` và `landmarks106[105 * 2]`.
  3. Tuy nhiên, theo đặc tả chuẩn 106 điểm của Meitu được triển khai trong [`FaceDetector106.kt`](file:///C:/actions-runner/convert2/AI-Studio-convert2/AI-Studio-convert2/lib-ai-engine/src/main/kotlin/com/meitu/ai/facedetect/FaceDetector106.kt) (Dòng 362 - 371):
     - Các điểm từ **82 đến 97** là **Môi ngoài** (Outer Mouth).
     - Các điểm từ **98 đến 105** là **Môi trong** (Inner Mouth).
     - Điểm **104** và **105** chính là **2 điểm góc môi trong**!
     - Trong khi đó, con ngươi và mắt chuẩn của Meitu 106 points nằm tại:
       - Điểm **38** (hoặc 70): Con ngươi mắt trái (Left pupil).
       - Điểm **57** (hoặc 80): Con ngươi mắt phải (Right pupil).
  4. Hậu quả: Tọa độ `lxEye, lyEye` bị gán bằng $(461.2, 762.4)$ và `rxEye, ryEye` bị gán bằng $(515.4, 769.9)$ — hoàn toàn nằm trên môi của nhân vật! Khi JNI gọi `nativeApplyEyeShape(workingBitmap, lxEye, lyEye, rxEye, ryEye, ...)`, thuật toán C++ nắn bóp chính xác vùng môi thay vì vùng mắt.

---

### 2.2 Nguyên nhân gốc rễ 2: Cơ chế phòng vệ che khuất vành tai (`DEFECT_EAR_OCCLUSION_BYPASS`)
- **Tập tin liên quan:** `lib-core-graphics/src/main/cpp/src/face_retouch_detail.cpp` & `PhotoEditorActivity.kt`
- **Bản chất lỗi:**
  - Hàm `getEarAnatomyReport` phân tích vành tai qua cấu trúc giải phẫu cạnh khuôn mặt.
  - Trên ảnh mẫu `scratch/0.jpg`, tóc nhân vật uốn lọn che phủ 80% vành tai trái và vành tai phải.
  - Thuật toán C++ Core nhận diện độ tin cậy vành tai $< 0.2$ và tự động ngắt (bypass) lệnh nắn bóp để tránh làm rách nền hoặc kéo dạt tóc dị dạng.
  - Đây là hành vi thuật toán đúng đắn về mặt an toàn, nhưng thiếu 2 yếu tố hệ thống:
    1. Bộ kiểm thử tự động của Gate 7 dùng đơn nhất ảnh mẫu `scratch/0.jpg` mà không tự động chuyển sang ảnh mẫu chuẩn lộ vành tai (`scratch/regression_30/sample_27.png`).
    2. Giao diện UI thiếu phản hồi cho người dùng biết "Vành tai bị tóc che phủ, vui lòng vén tóc hoặc chọn ảnh rõ tai".

---

### 2.3 Nguyên nhân gốc rễ 3: Thiếu dữ liệu nang lông râu trên ảnh chân dung nữ (`DEFECT_BEARD_ASSET_MISMATCH`)
- **Tập tin liên quan:** `PhotoEditorActivity.kt` & Test Harness
- **Bản chất lỗi:**
  - Các công cụ nhuộm màu râu (`tool_beard_dye`), ria mép (`tool_beard_mustache_only`), râu quai nón (`tool_beard_quai_non`), và làm đen râu bạc (`tool_beard_gray_away`) hoạt động dựa trên thuật toán lọc sắc tố của sợi râu hiện hữu trên vùng da cằm.
  - Ảnh chân dung `scratch/0.jpg` là phụ nữ trẻ có làn da cằm nhẵn mịn, không có nang lông râu. Do đó thuật toán nhận diện mật độ râu bằng 0 và không kích hoạt đổi màu.
  - Cần phải kiểm chuẩn các tính năng râu trên ảnh chân dung nam giới (`scratch/regression_30/sample_21.png` hoặc `sample_08.png`).

---

## 3. Đề Xuất Các Tác Vụ Sửa Lỗi Hẹp (Proposed Narrow Correction Tasks)

Tuân thủ nghiêm ngặt Điều XIII của `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD`, Agent 0 đề xuất Chủ tịch Tony phê duyệt mở 02 tác vụ sửa lỗi hẹp có giới hạn phạm vi rõ ràng:

### Tác vụ 1: `TASK_015_FACE_BEAUTY_LANDMARK_AND_EYE_ATTACHMENT_CORRECTION`
- **Mục tiêu:** Sửa dứt điểm lỗi ánh xạ chỉ mục landmark mắt trong `PhotoEditorActivity.kt`.
- **Phạm vi file cho phép sửa (`files_allowed`):**
  - `app/src/main/kotlin/com/mt/mtxx/mtxx/editor/PhotoEditorActivity.kt`
- **Nội dung sửa đổi cụ thể:**
  1. Thay thế chỉ mục fallback từ `104`/`105` sang `38`/`57` (hoặc `70`/`80` theo đúng cấu trúc `FaceDetector106.kt`).
  2. Bổ sung kiểm tra hợp lý hình học (Sanity Geometry Check): Tọa độ mắt bắt buộc phải nằm phía trên sống mũi (`lyEye < noseY` và `ryEye < noseY`); nếu không thỏa mãn, tự động suy diễn từ bounding box khuôn mặt (`cy - bh * 0.10f`).
  3. Cập nhật các công cụ màu chân mày (`tool_brow_color_*`) sử dụng trực tiếp tọa độ cung mày `landmarks106[33..52]` thay vì mắt.
- **Tiêu chuẩn nghiệm thu:** Chạy lại visual capture 22 tính năng mắt trên Samsung Galaxy A07, khẳng định vùng biến dạng nằm 100% tại $Y \in [400, 560]$ (vùng mắt), sai khác tại vùng miệng triệt tiêu về 0.

### Tác vụ 2: `TASK_016_FACE_BEAUTY_EAR_BEARD_SPECIALIZED_ASSET_HARNESS`
- **Mục tiêu:** Hoàn thiện bộ kiểm chuẩn thị giác cho các tính năng Tai và Râu bằng ảnh chân dung chuyên dụng.
- **Phạm vi file cho phép sửa (`files_allowed`):**
  - `app/src/main/kotlin/com/mt/mtxx/mtxx/editor/PhotoEditorActivity.kt` (Bổ sung Toast/HUD cảnh báo khi tai/râu bị che khuất)
  - `scripts/` (Cập nhật script điều phối kiểm chuẩn tự động hỗ trợ cờ `--es image_path` theo module)
- **Tiêu chuẩn nghiệm thu:**
  - Tai (MOD_07): Kiểm thử trên `scratch/regression_30/sample_27.png` đạt `max_diff > 30.0` tại vành tai.
  - Râu (MOD_08): Kiểm thử trên `scratch/regression_30/sample_21.png` đạt `max_diff > 30.0` tại vùng hàm/quai nón.
