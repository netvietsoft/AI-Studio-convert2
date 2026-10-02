# RAW LOGCAT CAPTURE COMMANDS & REPRODUCIBILITY GUIDE
**Task:** TASK_003_HCE_V1_GPU_EVIDENCE_INTEGRITY_AND_PHYSICAL_RERUN  
**Authority:** Chủ tịch Tony  
**Date:** 2026-10-02  
**Devices:**
- Samsung SM-A075F (`192.168.1.18:40159`, ARM Mali-G57 MC2, Android 16)
- Samsung SM-A507FN / Galaxy A50s (`192.168.1.2:41775`, ARM Mali-G72 MP3, Android 11)

---

## 1. ADB Connect Commands
```bash
adb connect 192.168.1.18:40159
adb connect 192.168.1.2:41775
```

## 2. APK Installation
```bash
adb -s 192.168.1.18:40159 install -r -d F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk
adb -s 192.168.1.2:41775 install -r -d F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk
```

## 3. Test Trigger Execution
```bash
# Push test portrait
adb -s <SERIAL> push scratch/0.jpg /sdcard/user_portrait.jpg
adb -s <SERIAL> shell run-as com.mt.mtxx.mtxx.convert cp /sdcard/user_portrait.jpg /data/data/com.mt.mtxx.mtxx.convert/files/user_portrait.jpg

# Clear logcat buffer and stop existing instance
adb -s <SERIAL> logcat -c
adb -s <SERIAL> shell am force-stop com.mt.mtxx.mtxx.convert

# Launch PhotoEditorActivity with benchmark flag
adb -s <SERIAL> shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity \
  --ez run_hce_benchmark true \
  --ei benchmark_iterations 3 \
  --es target_category cat_hair \
  --es tool_id tool_hair_rose_gold \
  --ei intensity 80
```

## 4. Raw Logcat Dump
```bash
adb -s 192.168.1.18:40159 logcat -d > RAW_HCE_VULKAN_LOGCAT_SM_A075F.txt
adb -s 192.168.1.2:41775 logcat -d > RAW_HCE_VULKAN_LOGCAT_SM_A507FN.txt
```

## 5. Raw Screenshot Capture
```bash
adb -s 192.168.1.18:40159 exec-out screencap -p > evidence_device_vulkan_rose_gold_a075f.png
adb -s 192.168.1.2:41775 exec-out screencap -p > evidence_device_vulkan_rose_gold_a50s.png
```
