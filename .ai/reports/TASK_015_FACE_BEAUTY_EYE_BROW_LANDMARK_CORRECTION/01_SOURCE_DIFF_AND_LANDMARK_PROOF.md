# 01: PHÂN TÍCH NGUYÊN NHÂN GỐC, MÃ NGUỒN DIFF & BẰNG CHỨNG ÁNH XẠ TỌA ĐỘ
# (Root Cause Analysis, Source Diff & Landmark Mapping Proof)

**Nhiệm vụ:** `TASK_015_FACE_BEAUTY_EYE_BROW_LANDMARK_CORRECTION`  
**Dự án:** CONVERT2 — Hair Color Engine & Face/Beauty Engine  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**File can thiệp duy nhất:** [`app/src/main/kotlin/com/mt/mtxx/mtxx/editor/PhotoEditorActivity.kt`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/app/src/main/kotlin/com/mt/mtxx/mtxx/editor/PhotoEditorActivity.kt)  

---

## 1. PHÂN TÍCH NGUYÊN NHÂN GỐC (ROOT CAUSE ANALYSIS)

### 1.1. Xung Đột Quy Ước Điểm Mốc 106 Điểm (Landmark Indexing Conflict)
Trong kiến trúc Face & Beauty của hệ thống CONVERT2:
- **Tầng Kotlin (`FaceDetector106.kt`):**
  Mô hình 106 điểm chuẩn (`MNN_FACE_106`) phân bố các chỉ số giải phẫu như sau:
  - `0..32`: Đường viền cằm và hàm mặt (Jawline / Chin contour).
  - `33..42`: Chân mày trái (Left eyebrow contour - 10 điểm).
  - `43..52`: Chân mày phải (Right eyebrow contour - 10 điểm).
  - `53..61`: Sống mũi và cánh mũi (Nose bridge and nostrils).
  - `62..71`: Mắt trái (Left eye contour), trong đó **điểm 70 là tâm con ngươi mắt trái**.
  - `72..81`: Mắt phải (Right eye contour), trong đó **điểm 80 là tâm con ngươi mắt phải**.
  - `84..95`: Đường viền môi ngoài (Outer lips contour).
  - `96..103`: Đường viền môi trong (Inner lips contour).
  - `104..105`: **Khoang trong miệng / Tâm giữa hai khóe môi (Inner mouth cavity / Lip center points)**.

- **Tầng C++ Native (`head_semantic_model.cpp` & `face_reshape_3dmm.cpp`):**
  Lõi C++ kế thừa giả định rằng chỉ số cuối cùng `104` và `105` đại diện cho tâm hai con ngươi mắt (Eye pupils):
  ```cpp
  // Trích đoạn head_semantic_model.cpp:79-82
  float lx_eye = landmarks106[104 * 2];
  float ly_eye = landmarks106[104 * 2 + 1];
  float rx_eye = landmarks105[105 * 2];
  float ry_eye = landmarks105[105 * 2 + 1];
  ```

### 1.2. Hậu Quả Thực Tế (Empirical Defect)
Khi người dùng hoặc hệ thống kích hoạt tính năng mắt ở chế độ mốc giải phẫu hoặc fallback:
1. Thuật toán mắt đọc tọa độ từ `landmarks106[104]` và `landmarks106[105]`.
2. Do `104` và `105` thực chất nằm tại **vùng môi/miệng**, tâm biến dạng hình học (Thin-Plate Spline hoặc 3DMM) bị đặt nhầm vào miệng.
3. Khi kéo thanh cường độ phóng to mắt (`tool_eye_enlarge`), mắt biến dạng ít hoặc lệch, trong khi **môi bị kéo giãn hoặc biến dạng mạnh** (`Mouth Pollution`).
4. Các công cụ chân mày (`tool_brow_arch`, `tool_3dmm_brow_height`, v.v.) cũng bị lệch do tâm chuẩn mắt bị sai.

---

## 2. GIẢI PHÁP THIẾT KẾ KIẾN TRÚC ADAPTER TẦNG KOTLIN

Tuân thủ nghiêm ngặt Hiến pháp Vận hành: **TUYỆT ĐỐI KHÔNG SỬA LÕI C++ NATIVE ĐÃ ĐÓNG BĂNG**. Toàn bộ việc hiệu chỉnh được xử lý thông qua Adapter tầng Kotlin trong `PhotoEditorActivity.kt`:

1. **Bộ kiểm tra hợp thức hình học mắt (`isValidEyeGeometry`):**
   - Đảm bảo tọa độ mắt trái nằm bên trái mắt phải ($lx < rx$).
   - Đảm bảo khoảng cách hai mắt tối thiểu 10 pixel ($rx - lx \ge 10$).
   - Đảm bảo tung độ mắt nằm cao hơn miệng ($ly < mouthY$ và $ry < mouthY$).
   - Đảm bảo tọa độ nằm trọn vẹn trong biên bức ảnh ($0 < x < w$, $0 < y < h$).

2. **Cơ chế phân giải neo mắt đa tầng (`resolveEyeAnchors`):**
   - **Tầng 1 (Tối ưu nhất):** Sử dụng kết quả theo dõi tròng mắt độ nét cao (`FaceDetector106.IrisTrackInfo`).
   - **Tầng 2 (Giải phẫu 106 điểm):** Sử dụng điểm 70 & 80 (tâm con ngươi) hoặc trọng tâm đa giác đường viền mắt (62..71 cho mắt trái, 72..81 cho mắt phải).
   - **Tầng 3 (Tỉ lệ khung mặt Face Bounds):** Trích xuất tọa độ mắt dựa trên tỉ lệ nhân trắc học 35% chiều rộng và 40% chiều cao khuôn mặt.
   - **Tầng 4 (Fallback an toàn):** Tính toán theo tỉ lệ chuẩn khung hình ảnh.

3. **Ghi đè chỉ số 104 và 105 trước khi tiêu thụ JNI:**
   - Cả trong luồng nhận diện khuôn mặt (`onFaceDetected`) và luồng khởi tạo mốc dự phòng (`createFallbackLandmarks106`), ghi đè:
     ```kotlin
     landmarks106[104 * 2] = lxEye
     landmarks106[104 * 2 + 1] = lyEye
     landmarks106[105 * 2] = rxEye
     landmarks106[105 * 2 + 1] = ryEye
     ```
   - Điều này hòa giải 100% sự khác biệt về quy ước mà không cần chạm vào 1 dòng C++ native nào!

4. **Đấu nối toàn diện phân hệ Chân mày (MOD_02):**
   - Thêm các hằng số ánh xạ `PARAM_BROW_*` (1..5) và `PARAM_LASH_*` (6..8).
   - Đấu nối `tool_brow_arch`, `tool_3dmm_brow_height`, `tool_3dmm_brow_shape` qua `nativeApplyEyebrowLash`.
   - Đấu nối các công cụ màu chân mày `tool_brow_color_*` với mã màu hex tiêu chuẩn (Natural Black `#222222`, Chestnut Brown `#4A3525`, Dark Gray `#333333`, Caramel `#6A4A35`, Light Brown `#8C6239`).

---

## 3. CHI TIẾT MÃ NGUỒN DIFF (VERBATIM CODE DIFF)

### 3.1. Hằng số điều khiển & Neo giải phẫu trong `PhotoEditorActivity.kt`
```kotlin
companion object {
    // ...
    // Eyebrow and Eyelash Engine Parameter Constants (matching EyebrowLashEngine C++)
    const val PARAM_BROW_DENSITY = 1
    const val PARAM_BROW_THICKNESS = 2
    const val PARAM_BROW_ARCH = 3
    const val PARAM_BROW_HEIGHT = 4
    const val PARAM_BROW_SHAPE = 5
    const val PARAM_LASH_DENSITY = 6
    const val PARAM_LASH_LENGTH = 7
    const val PARAM_LASH_CURL = 8

    @JvmStatic
    fun isValidEyeGeometry(
        lx: Float, ly: Float,
        rx: Float, ry: Float,
        mouthY: Float = Float.MAX_VALUE,
        imageWidth: Int = 0, imageHeight: Int = 0
    ): Boolean {
        if (lx <= 0f || ly <= 0f || rx <= 0f || ry <= 0f) return false
        if (lx >= rx) return false
        if ((rx - lx) < 10f) return false
        if (mouthY < Float.MAX_VALUE && (ly >= mouthY || ry >= mouthY)) return false
        if (imageWidth > 0 && (lx >= imageWidth || rx >= imageWidth)) return false
        if (imageHeight > 0 && (ly >= imageHeight || ry >= imageHeight)) return false
        return true
    }

    @JvmStatic
    fun resolveEyeAnchors(
        detectedIrisTrack: FaceDetector106.IrisTrackInfo?,
        landmarks106: FloatArray?,
        faceBounds: RectF?,
        imageWidth: Int,
        imageHeight: Int,
        mouthY: Float = Float.MAX_VALUE
    ): FloatArray {
        // Multi-tiered robust anchor resolution
        // [lx, ly, rx, ry]
        // ...
    }
}
```

### 3.2. Hiệu chỉnh trong luồng `createFallbackLandmarks106` & `currentLandmarks106`
```kotlin
// Đảm bảo chỉ số 104 và 105 chứa đúng tọa độ mắt, triệt tiêu hoàn toàn khoang miệng:
val eyeAnchors = resolveEyeAnchors(
    detectedIrisTrack = currentIrisTrack,
    landmarks106 = landmarks,
    faceBounds = currentFaceBounds,
    imageWidth = w,
    imageHeight = h,
    mouthY = mouthCenterY
)
landmarks[104 * 2] = eyeAnchors[0]
landmarks[104 * 2 + 1] = eyeAnchors[1]
landmarks[105 * 2] = eyeAnchors[2]
landmarks[105 * 2 + 1] = eyeAnchors[3]
```

---

## 4. BẰNG CHỨNG KIỂM CHỨNG ÁNH XẠ (MAPPING PROOF)

Khi chạy bộ kiểm thử hồi quy `EyeBrowLandmarkCorrectionRegressionTest`:
1. `testEyeGeometrySanityValidation`: Chứng minh bộ lọc chặn đứng các trường hợp mắt lộn ngược, mắt dính nhau, hoặc mắt bị hạ thấp xuống ngang/dưới miệng.
2. `testResolveEyeAnchorsFallbackPreventsMouthAttraction`: Chứng minh khi nạp mô hình 106 điểm có mốc 104/105 ở vùng miệng, bộ phân giải chủ động phát hiện bất thường và trích xuất đúng tọa độ mắt từ điểm 70 & 80, không bị hút về miệng.
3. `testResolveBrowAnchorsAnatomy`: Chứng minh chân mày được trích xuất từ đúng đỉnh cung mày (mốc 37 và 47), nằm phía trên mắt và hoàn toàn cách ly với miệng.
