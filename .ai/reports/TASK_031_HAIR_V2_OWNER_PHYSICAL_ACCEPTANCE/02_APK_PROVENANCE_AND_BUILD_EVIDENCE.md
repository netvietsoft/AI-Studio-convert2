# 02 - BẰNG CHỨNG NGUỒN GỐC BẢN DỰNG APK (APK PROVENANCE & BUILD EVIDENCE)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE_FINAL_APK_TEST_ACTIVE`  

---

## 1. THÔNG SỐ BUILD APK NATIVE TƯƠI MỚI (FRESH BUILD)
- **Đường dẫn file APK:** `app/build/outputs/apk/debug/app-debug.apk`
- **Kích thước file:** `200,228,766` bytes
- **Mã băm SHA-256:** `8F23EAF65F5BB63069FFCD0CA4821ED666019480A21284A9D21DD8C1250C6CF5`
- **Commit mã nguồn (Source Commit):** `beaa5fe385cc6a2847992a497e7ff186fe522838`
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
- **APK SHA-256:** `8F23EAF65F5BB63069FFCD0CA4821ED666019480A21284A9D21DD8C1250C6CF5`
- **Dumpsys Package Info:**
```text
versionCode=121708 minSdk=26 targetSdk=35
versionName=12.17.8
lastUpdateTime=2026-10-03 22:38:04
firstInstallTime=2026-09-26 22:14:03
```
- **Xác nhận:** Cài đặt thành công, gói ứng dụng sẵn sàng nhận intent và xử lý ảnh thực tế.

### SM-A507FN (192.168.1.2:41775)
- **Model:** `SM-A507FN`
- **Vi xử lý:** `Samsung Exynos 9611`
- **Android:** `11`
- **Package:** `com.mt.mtxx.mtxx.convert`
- **APK SHA-256:** `8F23EAF65F5BB63069FFCD0CA4821ED666019480A21284A9D21DD8C1250C6CF5`
- **Dumpsys Package Info:**
```text
versionCode=121708 minSdk=26 targetSdk=35
versionName=12.17.8
firstInstallTime=2026-09-30 08:04:13
lastUpdateTime=2026-10-03 22:39:19
```
- **Xác nhận:** Cài đặt thành công, gói ứng dụng sẵn sàng nhận intent và xử lý ảnh thực tế.

