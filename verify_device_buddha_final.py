import os
import subprocess
import time
from PIL import Image, ImageDraw
import numpy as np
import run_adb_cmd

APK_PATH = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\app\build\outputs\apk\debug\app-debug.apk"

def verify_final():
    print("=== STEP 1: Verify device connection ===")
    out, err, code = run_adb_cmd.run_adb(["get-state"])
    print("Device state:", out.strip())
    if "device" not in out:
        print("Device not ready!")
        return False

    print("=== STEP 2: Install freshly built debug APK ===")
    out, err, code = run_adb_cmd.run_adb(["install", "-r", "-t", "-d", APK_PATH])
    print("Install output:", out.strip(), err.strip())

    print("=== STEP 3: Clear logcat and launch PhotoEditorActivity with tool_ear_buddha ===")
    run_adb_cmd.run_adb(["shell", "logcat", "-c"])

    cmd = [
        "shell", "am", "start", "-W", "-S",
        "-n", "com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity",
        "--es", "tool_id", "tool_ear_buddha",
        "--ei", "intensity", "90"
    ]
    out, err, code = run_adb_cmd.run_adb(cmd)
    print("Launch output:", out.strip())

    print("=== STEP 4: Wait for rendering ===")
    time.sleep(3)

    print("=== STEP 5: Capture screencap ===")
    screen_device = "/sdcard/screen_buddha_perfect.png"
    run_adb_cmd.run_adb(["shell", "screencap", "-p", screen_device])

    local_screen = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\screen_buddha_perfect.png"
    run_adb_cmd.run_adb(["pull", screen_device, local_screen])

    if os.path.exists(local_screen):
        print("Successfully captured and pulled:", local_screen)
        im = Image.open(local_screen)
        print("Screencap size:", im.size)
    else:
        print("Failed to pull screencap!")
        return False

    print("=== STEP 6: Check logcat for EarTool execution ===")
    out, err, code = run_adb_cmd.run_adb(["shell", "logcat", "-d"])
    for line in out.splitlines():
        if "EarTool" in line or "applyEarStyle" in line or "PhotoEditorActivity" in line:
            if "applyCurrentToolToBitmap" in line or "EarTool" in line or "handleIntent" in line:
                print("  LOG:", line)

    return True

if __name__ == "__main__":
    verify_final()
