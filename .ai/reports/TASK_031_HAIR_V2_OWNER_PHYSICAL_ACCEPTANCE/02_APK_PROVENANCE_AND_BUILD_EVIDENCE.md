# 02 - BẰNG CHỨNG NGUỒN GỐC BẢN DỰNG APK (APK PROVENANCE & BUILD EVIDENCE)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE_FINAL_APK_TEST_ACTIVE`  

---

## 1. THÔNG SỐ BUILD APK NATIVE TƯƠI MỚI (FRESH BUILD)
- **Đường dẫn file APK:** `app/build/outputs/apk/debug/app-debug.apk`
- **Kích thước file:** `184,413,246` bytes
- **Mã băm SHA-256:** `7C60B9F7305BA1B10A055F483215A81C5F11D3AD115CAE0465769F89CA694F64`
- **Commit mã nguồn (Source Commit):** `ed57306f410d14e09bf8ec8eac149cc34f8b7122`
- **Thời gian biên dịch:** 2026-10-04 00:49:10 +07:00
- **Lệnh build:** `./gradlew assembleDebug --no-daemon`
- **Môi trường:** Gradle 8.9, Android Gradle Plugin 8.2.2, Android NDK 26.1.10909125, CMake 3.22.1, Ninja 1.10.2
- **Lõi C++ Native:** `libmeitu_reborn_native.so` (arm64-v8a) tích hợp thuật toán HairPipelineV2 và Tencent NCNN 20260526.

---

## 2. CHỨNG THỰC CÀI ĐẶT TRÊN THIẾT BỊ VẬT LÝ
### SM-A075F (192.168.1.18:40159)
- **Model:** `SM-A075F`
- **Vi xử lý:** `MediaTek Helio G99 (MT6789)`
- **Android:** `16`
- **Package:** `com.mt.mtxx.mtxx.convert`
- **APK SHA-256:** `7C60B9F7305BA1B10A055F483215A81C5F11D3AD115CAE0465769F89CA694F64`
- **Dumpsys Package Info:**
```text
versionCode=121708 minSdk=26 targetSdk=35
versionName=12.17.8
lastUpdateTime=2026-10-04 00:49:10
firstInstallTime=2026-09-26 22:14:03
```
- **Xác nhận:** Cài đặt thành công, gói ứng dụng sẵn sàng nhận intent và xử lý ảnh thực tế.

### SM-A507FN (192.168.1.2:41775)
- **Model:** `SM-A507FN`
- **Vi xử lý:** `Samsung Exynos 9611`
- **Android:** `11`
- **Package:** `com.mt.mtxx.mtxx.convert`
- **APK SHA-256:** `7C60B9F7305BA1B10A055F483215A81C5F11D3AD115CAE0465769F89CA694F64`
- **Dumpsys Package Info:**
```text
versionCode=121708 minSdk=26 targetSdk=35
versionName=12.17.8
firstInstallTime=2026-09-30 08:04:13
lastUpdateTime=2026-10-04 00:50:10
```
- **Xác nhận:** Cài đặt thành công, gói ứng dụng sẵn sàng nhận intent và xử lý ảnh thực tế.

