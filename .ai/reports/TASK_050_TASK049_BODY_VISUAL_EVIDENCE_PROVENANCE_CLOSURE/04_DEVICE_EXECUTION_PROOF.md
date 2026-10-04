# DEVICE EXECUTION PROOF — TASK_050
**Test Hardware:** Dual Physical Android Devices  
**APK Path:** `app/build/outputs/apk/debug/app-debug.apk`  
**APK SHA256:** `1D8B81ECEEE9400850A6A69B073D72D01C5C007062E408F9CE986934ABE4D0D1`  
**Package:** `com.mt.mtxx.mtxx.convert`  

---

## 1. Hardware Specifications

| Property | Device 1 | Device 2 |
|---|---|---|
| **Model** | Samsung Galaxy A07 (`SM-A075F`) | Samsung Galaxy A50s (`SM-A507FN`) |
| **Serial / Transport** | `192.168.1.18:40159` | `192.168.1.2:41775` |
| **Android Version** | Android 15 (API 35) | Android 11 (API 30) |
| **Build Number** | `UP1A.231005.007.A075FXXU1AXB4` | `RP1A.200720.012.A507FNXXU5DVE4` |
| **SoC / Chipset** | MediaTek Helio G99 / MT6789 | Samsung Exynos 9611 |
| **GPU Architecture** | Mali-G57 MC2 | Mali-G72 MP3 |
| **Vulkan Support** | Vulkan 1.3 / Driver 44.0.0 | Vulkan 1.1 / Driver 38.1.0 |

---

## 2. Test Execution Log
1. **Asset Deployment:**
   - Full body asset: `scratch/1.jpg` (576x1280, SHA256: `EA9082B0C554FE169089B4CB7BC59A0C76119CEEDCCBB307C218EFCF3ED72C38`) pushed to `/sdcard/body_test_full.jpg`
   - Bust crop asset: `scratch/0.jpg` (960x1280, SHA256: `F13FDAC1C436D9D9108F38FB37EE1957799FF60BE772975A9D64B32B2D796814`) pushed to `/sdcard/body_test_bust.jpg`
   - Multi-person asset: `scratch/multi_person_orig.jpg` (576x1280, SHA256: `54C532270E7F5BA6FDEBB90309EE58CF7B56A2BC2DF6FB0FB5C9C17BB10CBDD6`) pushed to `/sdcard/multi_person_orig.jpg`
2. **Device Invocation Command:**
   ```bash
   am start -S -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity \
     --es image_path <REMOTE_IMAGE_PATH> \
     --es tool_id <TOOL_ID> \
     --ei intensity <INTENSITY_PERCENT> \
     --es auto_save_path /sdcard/Download/qa_outputs/<OUT_FILE>
   ```
3. **Evidence Extraction:**
   - Pulled 56 lossless PNGs from `SM-A075F` into `scratch/device_evidence_SM-A075F/`.
   - Pulled 53 lossless PNGs from `SM-A507FN` into `scratch/device_evidence_SM-A507FN/`.
   - All files verified non-empty, valid PNG headers, lossless ARGB8888 compression.
