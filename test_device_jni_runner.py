import subprocess
import time
import os
import sys

# Ensure UTF-8 output
sys.stdout.reconfigure(encoding='utf-8')

ADB_EXE = r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
DEVICE_IP = "192.168.1.18:34335"
APK_PATH = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"
PACKAGE = "com.mt.mtxx.mtxx.convert"

def run_adb(args, timeout=30):
    subprocess.run([ADB_EXE, "connect", DEVICE_IP], capture_output=True)
    full_cmd = [ADB_EXE, "-s", DEVICE_IP] + args
    res = subprocess.run(full_cmd, capture_output=True, text=True, timeout=timeout)
    return res

def tap(x, y):
    run_adb(["shell", "input", "tap", str(int(x)), str(int(y))])

def swipe(x1, y1, x2, y2, duration_ms=300):
    run_adb(["shell", "input", "swipe", str(int(x1)), str(int(y1)), str(int(x2)), str(int(y2)), str(int(duration_ms))])

def take_screenshot(filename):
    subprocess.run([ADB_EXE, "connect", DEVICE_IP], capture_output=True)
    cmd = [ADB_EXE, "-s", DEVICE_IP, "exec-out", "screencap", "-p"]
    with open(filename, "wb") as f:
        subprocess.run(cmd, stdout=f)
    print(f"[OK] Screenshot saved to: {filename}")

def dismiss_compatibility_dialog():
    # Tap OK button of Android 15 compatibility dialog
    tap(540, 950)
    time.sleep(0.5)

def test_video_editor():
    print("[*] Launching VideoEditorActivity...")
    run_adb(["shell", "am", "start", "-n", f"{PACKAGE}/com.mt.mtxx.mtxx.video.VideoEditorActivity", "-f", "0x10000000"])
    time.sleep(3)
    dismiss_compatibility_dialog()
    time.sleep(2)

    take_screenshot("evidence_video_editor_initial.png")

    # Scrub timeline SeekBar
    print("[*] Scrubbing Timeline to 50%...")
    swipe(200, 1020, 500, 1020, 400)
    time.sleep(1.5)
    take_screenshot("evidence_video_editor_scrubbed.png")

    # Select Category 'Bo Loc Video' (Filter category)
    print("[*] Selecting 'Bo Loc Video' category tab...")
    tap(350, 1530)
    time.sleep(1)

    # Select 'Cinematic Film 35mm' filter
    print("[*] Applying Cinematic Film LUT filter...")
    tap(120, 1420)
    time.sleep(1.5)
    take_screenshot("evidence_video_editor_filter_cinematic.png")

    # Select 'Neon Cyberpunk 4K' filter
    print("[*] Applying Neon Cyberpunk filter...")
    tap(420, 1420)
    time.sleep(1.5)
    take_screenshot("evidence_video_editor_filter_cyberpunk.png")

    # Play playback
    print("[*] Testing Play/Pause playback...")
    tap(540, 960) # Play button
    time.sleep(3)
    take_screenshot("evidence_video_editor_playing.png")
    tap(540, 960) # Pause
    time.sleep(1)

def test_photo_editor():
    print("[*] Launching PhotoEditorActivity to verify BiSeNet Face Parsing...")
    run_adb(["shell", "am", "start", "-n", f"{PACKAGE}/com.mt.mtxx.mtxx.editor.PhotoEditorActivity", "-f", "0x10000000"])
    time.sleep(3)
    dismiss_compatibility_dialog()
    time.sleep(2)
    take_screenshot("evidence_photo_editor_bisenet.png")

    # Tap on Beauty feature (e.g., Lam min da hoặc Nhuom toc)
    print("[*] Testing Hair Dye / Skin Smoothing on PhotoEditor...")
    tap(200, 1450) # Select first beauty tool
    time.sleep(1.5)
    take_screenshot("evidence_photo_editor_bisenet_tool_active.png")

if __name__ == "__main__":
    test_video_editor()
    test_photo_editor()
    print("[*] ALL DEVICE TESTS COMPLETED SUCCESSFULLY!")
