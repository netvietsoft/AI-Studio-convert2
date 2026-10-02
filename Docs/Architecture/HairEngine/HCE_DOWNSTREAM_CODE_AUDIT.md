# BÁO CÁO KIỂM ĐỊNH MÃ NGUỒN VÀ TẦNG GIAO TIẾP THỰC TẾ (HCE_DOWNSTREAM_CODE_AUDIT.md)
**Dự án:** CONVERT2 — Hair Color Engine (Phase P1–P6)  
**Tác giả:** Agent 1 (System & Engine Architect)  
**Phê duyệt:** Agent 0 (CEO / Orchestrator)  
**Tiêu chuẩn:** Hiến pháp Vận hành + Development Workspace Standard V2.1.2  
**Thời điểm thực hiện:** 2026-10-02T10:15:00+07:00  
**Trạng thái:** HOÀN THÀNH — ĐÃ XÁC MINH TRÊN MÃ NGUỒN PRODUCTION THỰC TẾ  

---

## 1. Mục Tiêu Kiểm Định
Audit toàn bộ hiện trạng mã nguồn C++, JNI và Kotlin liên quan đến hệ thống tóc (Hair Matting, Hair Engine, Hair Strand Dye) trong `CONVERT2`, nhằm:
1. Xác định chính xác các kiểu dữ liệu, hàm và hợp đồng thực tế đang chạy.
2. Tuyệt đối không tự bịa đặt ký hiệu (Do not invent symbols).
3. Làm căn cứ bất biến để đóng băng bản đặc tả hợp đồng chung `HCE_CONTRACT_V1.md`.

---

## 2. Kết Quả Kiểm Định Từng Module Sản Xuất

### 2.1. Module P0 — Hair Matting Engine (ĐÃ ĐÓNG BĂNG & BẤT BIẾN)
- **Tệp nguồn:** 
  - `lib-core-graphics/src/main/cpp/include/hair_matting_engine.h` (SHA-256: `66d9f9fd6516a199c0ad5fda3e9a99c85f900db2238a76fd96f43b448e3ffb6e`)
  - `lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp` (SHA-256: `c2d2e4949eb31953c0f204d9fa43b43e5148c2729914107399a4cfa5a0cc53a6`)
- **Giao diện cung cấp cho Downstream:**
  ```cpp
  bool extractFullSizeMatte(
      const uint32_t* pixels,
      int width,
      int height,
      const MeituReborn::FusedFaceGeometry& fused,
      std::vector<float>& outFullAlpha
  );
  ```
- **Ngữ nghĩa dữ liệu đầu ra:**
  - `outFullAlpha`: vector một chiều gồm $W \times H$ phần tử `float`, dải giá trị $[0.0f, 1.0f]$.
  - Thứ tự: Raster row-major từ góc trên-trái $(0, 0)$.
  - Vùng bảo vệ (`0.0f`): Da mặt, mắt, mũi, miệng, tai, cổ, quần áo, thanh công cụ UI.
  - Vùng tóc chắc chắn (`1.0f`): Lõi khối tóc được phân đoạn chính xác bởi BiSeNet Class 17.
  - Vùng chuyển tiếp `(0.0f, 1.0f)`: Rìa chân tóc và sợi tóc con sub-pixel.

### 2.2. Module Hair Engine Cũ
- **Tệp nguồn:**
  - `lib-core-graphics/src/main/cpp/include/hair_engine.h`
  - `lib-core-graphics/src/main/cpp/src/hair_engine.cpp`
- **Cấu trúc dữ liệu hiện có:**
  - `HairRegionMap`: chứa `hairMask`, `hairline`, `bangsMask`, `topCrownMask`, `sideHairMask`, `backHairMask`, và các ranh giới tiếp giáp.
  - `HairStructuralFeatures`: chứa `orientationField` (vector `float` góc $[-\pi/2, \pi/2]$), `coherenceField` ($[0.0f, 1.0f]$), `curlWaveScore`, `volumeScore`, `flyawayStrands`.
  - `HairAppearanceModel`: chứa `baseColor`, `localColorMap`, `highlightMap`, `shadowMap`, `apparentShine`, `localContrast`.
- **Đánh giá của Architect:**
  - `HairStructuralFeatures` đã có ý tưởng về trường hướng (`orientationField`) và độ đồng hướng (`coherenceField`), nhưng chưa chuẩn hóa tính chất tuần hoàn $\pi$ (`PI-periodic doubling angle`) và chưa phân tách kiến trúc module theo P1–P6.
  - Cần kế thừa các khái niệm này vào `HCE_CONTRACT_V1` một cách chuẩn tắc.

### 2.3. Module Hair Strand Dye Engine
- **Tệp nguồn:**
  - `lib-core-graphics/src/main/cpp/include/hair_strand_dye.h`
  - `lib-core-graphics/src/main/cpp/src/hair_strand_dye.cpp`
- **Giao diện hiện có:**
  - `HairDyePreset`: 10 bộ màu chuẩn salon (`Natural Black`, `Chestnut Brown`, `Ash Brown`, `Platinum Blonde`, `Smokey Silver`, `Rose Gold`, `Wine Burgundy`, `Peach Lilac`, `Navy Blue`, `Caramel Honey`).
  - `applyStrandDye(...)` và `applyCustomStrandDye(...)`.
- **Đánh giá của Architect:**
  - `applyCustomStrandDye` hiện đã trực tiếp gọi `HairMattingEngine::getInstance().extractFullSizeMatte(...)`.
  - Hiện tại thuật toán đang xử lý làm sáng và tạo vệt bóng Marschner R-lobe cơ bản, nhưng cần nâng cấp thành pipeline module hóa hoàn chỉnh theo 6 phase P1-P6: P1 Flow Field $\to$ P2 Texture $\to$ P3 Appearance $\to$ P4 Material $\to$ P5 Specular $\to$ P6 GPU Backend.

### 2.4. Tầng Cầu Nối JNI & Kotlin Controller
- **Tệp nguồn:**
  - `lib-core-graphics/src/main/cpp/src/jni_bridge.cpp`
  - `lib-core-graphics/src/main/kotlin/com/meitu/core/nativeengine/MeituNativeEngine.kt`
- **Giao diện JNI thực tế:**
  ```cpp
  Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyHairStrandDye(...)
  Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyCustomHairDye(...)
  ```
- **Kotlin External Functions:**
  ```kotlin
  external fun nativeApplyHairStrandDye(bitmap: Bitmap, presetId: Int, intensity: Float, gloss: Float = 0.5f): Boolean
  external fun nativeApplyCustomHairDye(bitmap: Bitmap, targetR: Int, targetG: Int, targetB: Int, bleachPower: Float, intensity: Float, gloss: Float = 0.5f): Boolean
  ```

---

## 3. Kết Luận Kiểm Định (Architectural Verdict)
1. Toàn bộ nền tảng mã nguồn thực tế đã có đầy đủ khung kết nối từ Kotlin qua JNI xuống C++ Native Engine.
2. P0 Hair Matting đã cung cấp chính xác `outFullAlpha` $(W \times H)$ chất lượng cao.
3. Việc chuẩn hóa `HCE_CONTRACT_V1` sẽ trực tiếp kế thừa và chuẩn hóa các cấu trúc này thành các C++ structs độc lập, strongly-typed, hỗ trợ cả CPU đa luồng (OpenMP) và GPU (Vulkan Compute / Metal-ready).
