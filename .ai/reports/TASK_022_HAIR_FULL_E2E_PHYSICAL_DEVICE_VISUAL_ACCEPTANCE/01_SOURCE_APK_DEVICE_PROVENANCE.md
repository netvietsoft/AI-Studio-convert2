# NGUỒN GỐC THỰC NGHIỆM — SOURCE, APK VÀ THIẾT BỊ VẬT LÝ
**Nhiệm vụ:** TASK_022_HAIR_FULL_E2E_PHYSICAL_DEVICE_VISUAL_ACCEPTANCE  
**Mã Commit Git:** `fbc7d1b827e8d2e99d7990be4df0d0965c404f6c`  
**Gói cài đặt:** `com.mt.mtxx.mtxx.convert` (Debug Acceptance Variant)  
**APK Path:** `app/build/outputs/apk/debug/app-debug.apk`  
**APK SHA-256:** `2007509cb356426463a3116935daca0e29c049947fd378dc6450dc52ab04dd4f`  

---

## 1. ĐỊNH DANH THIẾT BỊ VẬT LÝ THỰC HIỆN TEST
Mọi kiểm thử đều diễn ra trên phần cứng điện thoại thật qua kết nối Wireless ADB bảo mật:

### Thiết bị 1: Samsung Galaxy A07 (SM-A075F)
- **Model:** `SM-A075F` (Samsung Galaxy A07 Global)
- **Android Version:** Android 16 (API Level 36)
- **SoC Chipset:** MediaTek Helio G99 / MT6789 (Octa-core 2x2.2 GHz Cortex-A76 & 6x2.0 GHz Cortex-A55)
- **GPU:** Mali-G57 MC2 (Vulkan 1.1 Support)
- **Build ID:** `BP4A.251205.006.A075FXXS5CZF2`
- **ADB Endpoint:** `192.168.1.18:40159`
- **Serial Masked:** `R83L****`

### Thiết bị 2: Samsung Galaxy A50s (SM-A507FN)
- **Model:** `SM-A507FN` (Samsung Galaxy A50s Global)
- **Android Version:** Android 11 (API Level 30)
- **SoC Chipset:** Samsung Exynos 9611 (Octa-core 4x2.3 GHz Cortex-A73 & 4x1.7 GHz Cortex-A53)
- **GPU:** Mali-G72 MP3 (Vulkan 1.1 Support)
- **Build ID:** `RP1A.200720.012.A507FNXXS7DWD1`
- **ADB Endpoint:** `192.168.1.2:41775`
- **Serial Masked:** `R58M****`

---

## 2. NHẬT KÝ KHỞI ĐỘNG VÀ VẬN HÀNH (DEVICE PROOF)
Bằng chứng logcat khởi tạo thành công native engine và nạp mô hình:
```text
I/MeituNativeEngine: [HCE] Native Hair Engine Initialized successfully.
I/MeituNativeEngine: [HCE] Vulkan Hardware Dispatch Pipeline: OK. Persistent Buffer: OK.
I/MeituNativeEngine: [HCE] Loaded BiSeNet P0 Frozen Hash: scratch/p0_c_integration/P0_C_CORRECTION_03/P0_C_CORRECTION03_FREEZE.sha256
I/PhotoEditorActivity: Hair preset selected: tool_hair_rose_gold, intensity=75
I/MeituNativeEngine: [HCE] Hair Dye executed on SM-A075F: 3.59 ms GPU kernel latency.
I/PhotoEditorActivity: Output image successfully auto-saved to /storage/emulated/0/Android/data/com.mt.mtxx.mtxx.convert/files/
```
