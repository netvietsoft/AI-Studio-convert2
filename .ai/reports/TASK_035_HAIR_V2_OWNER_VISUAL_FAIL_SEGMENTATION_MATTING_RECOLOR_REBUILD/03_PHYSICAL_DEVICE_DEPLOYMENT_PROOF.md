# 03. PHYSICAL DEVICE DEPLOYMENT PROOF
**Task ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_SEGMENTATION_MATTING_NATURAL_RECOLOR_REBUILD_ACTIVE`  
**Command ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_REBUILD_20261004T090300+0700`  
**Standard:** Evidence-Based Only — Strict Physical Hardware Proof (SM-A075F & SM-A507FN)

---

## 1. Dual Physical Device Hardware Profile

### Device 1: Samsung Galaxy A07 (SM-A075F)
- **Device ID:** `sm_a075f`
- **ADB Endpoint:** `192.168.1.18:40159`
- **Model:** Samsung SM-A075F (`a07xx`)
- **SoC / Chipset:** MediaTek Helio G99 (`MT6789`) — Octa-core (2x Cortex-A76 @ 2.2GHz + 6x Cortex-A55 @ 2.0GHz)
- **GPU:** Mali-G57 MC2
- **Android OS Version:** Android 16 (API 36 / Platform `mt6789`)
- **Package Status:** `com.meitu.reborn` installed, target APK SHA256 verified.

### Device 2: Samsung Galaxy A50s (SM-A507FN)
- **Device ID:** `sm_a507fn`
- **ADB Endpoint:** `192.168.1.2:41775`
- **Model:** Samsung SM-A507FN (`a50sxx`)
- **SoC / Chipset:** Samsung Exynos 9611 — Octa-core (4x Cortex-A73 @ 2.3GHz + 4x Cortex-A53 @ 1.7GHz)
- **GPU:** Mali-G72 MP3
- **Android OS Version:** Android 11 (API 30 / Platform `exynos9610`)
- **Package Status:** `com.meitu.reborn` installed, target APK SHA256 verified.

---

## 2. Target Package & Native Binary Verification

| Property | Value |
|---|---|
| Target Application Package | `com.meitu.reborn` |
| Native Engine Library | `libmeitu_reborn_native.so` |
| Target Activity | `com.meitu.reborn.MeituAiPipelineActivity` |
| Built APK Location | `app/build/outputs/apk/debug/app-debug.apk` |
| Build Toolchain | Android NDK 27.0.12077973, CMake 3.22.1, Ninja, OpenMP enabled |
| Architecture Support | `arm64-v8a` (Primary target for A07 & A50s) |

---

## 3. Physical Screencap & Proof Artifacts
The following physical verification files are archived in the report repository:
- `gallery/00_DEVICE_PROOF/sm_a075f_device_proof.txt` (Dumpsys package, getprop dump, timestamp)
- `gallery/00_DEVICE_PROOF/sm_a075f_device_screen.png` (Live screencap from SM-A075F physical screen)
- `gallery/00_DEVICE_PROOF/sm_a507fn_device_proof.txt` (Dumpsys package, getprop dump, timestamp)
- `gallery/00_DEVICE_PROOF/sm_a507fn_device_screen.png` (Live screencap from SM-A507FN physical screen)
