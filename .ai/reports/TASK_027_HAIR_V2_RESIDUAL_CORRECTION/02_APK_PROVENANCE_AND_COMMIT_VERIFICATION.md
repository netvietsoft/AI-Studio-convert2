# 02 - NGUỒN GỐC APK & XÁC THỰC COMMIT (APK PROVENANCE & COMMIT VERIFICATION)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_027_HAIR_V2_RESIDUAL_LEAKAGE_TEXTURE_AND_COMMAND_LIFECYCLE_CORRECTION_ACTIVE`  

---

## 1. THÔNG SỐ BUILD APK NATIVE
Gói ứng dụng thử nghiệm được biên dịch trực tiếp từ mã nguồn C++ và Android Kotlin:

- **Đường dẫn cục bộ:** `app/build/outputs/apk/debug/app-debug.apk`
- **Kích thước file:** `184,413,246` bytes
- **Mã băm SHA-256:** `0bd519c9b7930aafe69d5bad0180aaa413f429464adb978adb5b835898d6df08`
- **Thời gian biên dịch:** 2026-10-03 13:48:47 +07:00
- **Lệnh build:** `./gradlew assembleDebug --no-daemon`
- **Môi trường Gradle:** Gradle 8.2, Android Gradle Plugin 8.2.2, Android NDK 26.1.10909125, CMake 3.22.1

---

## 2. NGUỒN GỐC GIT VÀ CÂY MÃ NGUỒN
- **Repository:** `https://github.com/netvietsoft/AI-Studio-convert2`
- **Nhánh làm việc (Branch):** `agent/TASK_027_HAIR_V2_RESIDUAL_CORRECTION_20261003T123500+0700`
- **Dispatch Commit SHA:** `fedb673d9265b0d1f38d23c2c667246f5c28154f`
- **Thư viện C++ Native:** `libcoregraphics.so` (`lib-core-graphics/src/main/cpp/`)
  - Chứa thuật toán `HairPipelineV2`
  - Đã tích hợp NCNN runtime có tăng tốc phần cứng FP16 / Arm Neon

---

## 3. XÁC THỰC CÀI ĐẶT TRÊN THIẾT BỊ VẬT LÝ
Gói APK được nạp lên đồng thời 2 thiết bị và xác thực thông qua Package Manager của Android (`dumpsys package`):

### A. Samsung Galaxy A07 (`192.168.1.18:40159`)
- **Package Name:** `com.mt.mtxx.mtxx.convert`
- **Version Code:** `1`
- **Version Name:** `1.0`
- **Thời gian cập nhật (lastUpdateTime):** `2026-10-03 13:49:33`
- **Trạng thái:** `INSTALLED & VERIFIED`

### B. Samsung Galaxy A50s (`192.168.1.2:41775`)
- **Package Name:** `com.mt.mtxx.mtxx.convert`
- **Version Code:** `1`
- **Version Name:** `1.0`
- **Thời gian cập nhật (lastUpdateTime):** `2026-10-03 13:50:46`
- **Trạng thái:** `INSTALLED & VERIFIED`
