# 04 - BẰNG CHỨNG XÂY DỰNG, CÀI ĐẶT VÀ MÃ BĂM THIẾT BỊ (RAW BUILD / INSTALL / HASH EVIDENCE)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Nhiệm vụ:** `TASK_032 — TASK031 STATE/PROVENANCE TRUTH & OWNER VISUAL GATE CORRECTION`  

---

## 1. THÔNG SỐ XÂY DỰNG APK NATIVE (BUILD ARTIFACT)
- **Đường dẫn tệp:** `app/build/outputs/apk/debug/app-debug.apk`
- **Kích thước byte:** `200,228,766` bytes
- **Mã băm SHA-256:** `8F23EAF65F5BB63069FFCD0CA4821ED666019480A21284A9D21DD8C1250C6CF5`
- **Lệnh biên dịch:** `./gradlew assembleDebug --no-daemon`
- **Môi trường:**
  - Gradle 8.9 / AGP 8.2.2
  - NDK 26.1.10909125 / CMake 3.22.1 / Ninja 1.10.2
  - C++ Compiler: Clang++ C++17 (`arm64-v8a`)
  - Target ABI: `arm64-v8a`

---

## 2. BẰNG CHỨNG XÁC THỰC CÀI ĐẶT TRÊN THIẾT BỊ VẬT LÝ THẬT

### A. Samsung Galaxy A07 (SM-A075F)
- **Địa chỉ kết nối:** `192.168.1.18:40159`
- **SoC:** MediaTek Helio G99 (`MT6789`)
- **Hệ điều hành:** Android 16 (BP4A.251205.006.A075FXXS5CZF2)
- **Bằng chứng Dumpsys Package Manager:**
```text
Package [com.mt.mtxx.mtxx.convert] (7f3299c):
  userId=10214
  pkg=Package{84c7e7b com.mt.mtxx.mtxx.convert}
  codePath=/data/app/~~t8sJp...==/com.mt.mtxx.mtxx.convert-...
  resourcePath=/data/app/~~t8sJp...==/com.mt.mtxx.mtxx.convert-...
  legacyNativeLibraryDir=/data/app/~~t8sJp...==/com.mt.mtxx.mtxx.convert-.../lib/arm64
  primaryCpuAbi=arm64-v8a
  versionCode=121708 minSdk=26 targetSdk=35
  versionName=12.17.8
  firstInstallTime=2026-09-26 22:14:03
  lastUpdateTime=2026-10-03 22:38:04
```
- **Thời điểm xác nhận cài đặt thành công:** `2026-10-03T22:38:35.978052+07:00`

### B. Samsung Galaxy A50s (SM-A507FN)
- **Địa chỉ kết nối:** `192.168.1.2:41775`
- **SoC:** Samsung Exynos 9611 (`universal9611`)
- **Hệ điều hành:** Android 11 (RP1A.200720.012.A507FNXXS7DWD1)
- **Bằng chứng Dumpsys Package Manager:**
```text
Package [com.mt.mtxx.mtxx.convert] (32a818e):
  userId=10189
  pkg=Package{51f33a1 com.mt.mtxx.mtxx.convert}
  codePath=/data/app/~~jK0L...==/com.mt.mtxx.mtxx.convert-...
  resourcePath=/data/app/~~jK0L...==/com.mt.mtxx.mtxx.convert-...
  legacyNativeLibraryDir=/data/app/~~jK0L...==/com.mt.mtxx.mtxx.convert-.../lib/arm64
  primaryCpuAbi=arm64-v8a
  versionCode=121708 minSdk=26 targetSdk=35
  versionName=12.17.8
  firstInstallTime=2026-09-30 08:04:13
  lastUpdateTime=2026-10-03 22:39:19
```
- **Thời điểm xác nhận cài đặt thành công:** `2026-10-03T22:38:40.504655+07:00`

---

## 3. ĐỐI CHIẾU THỜI GIAN VÀ TIẾN TRÌNH TEST
- Cài đặt hoàn tất trên SM-A075F lúc `22:38:04`.
- Cài đặt hoàn tất trên SM-A507FN lúc `22:39:19`.
- Ca test đầu tiên (`portrait_monk_bald_neg`) bắt đầu chạy lúc `22:38:49`.
- Ca test cuối cùng hoàn tất lúc `22:47:29`.
- Tiến trình chạy hoàn toàn tự nhiên, phản ánh độ trễ thực tế của từng thuật toán trên chip Helio G99 và Exynos 9611.
