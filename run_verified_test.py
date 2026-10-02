import subprocess
import time
import sys

ADB_EXE = r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
DEVICE_IP = "192.168.1.18:34335"
PACKAGE = "com.mt.mtxx.mtxx.convert"

def run_adb(args):
    subprocess.run([ADB_EXE, "connect", DEVICE_IP], capture_output=True)
    full_cmd = [ADB_EXE, "-s", DEVICE_IP] + args
    res = subprocess.run(full_cmd, capture_output=True, text=True)
    return res

def tap(x, y):
    run_adb(["shell", "input", "tap", str(int(x)), str(int(y))])

def swipe(x1, y1, x2, y2, dur=300):
    run_adb(["shell", "input", "swipe", str(int(x1)), str(int(y1)), str(int(x2)), str(int(y2)), str(int(dur))])

def capture(filename):
    subprocess.run([ADB_EXE, "connect", DEVICE_IP], capture_output=True)
    cmd = [ADB_EXE, "-s", DEVICE_IP, "exec-out", "screencap", "-p"]
    with open(filename, "wb") as f:
        subprocess.run(cmd, stdout=f)
    print(f"Captured: {filename}")

def main():
    print("[1] Waking up device...")
    run_adb(["shell", "input", "keyevent", "224"])
    run_adb(["shell", "input", "keyevent", "82"])
    run_adb(["shell", "svc", "power", "stayon", "true"])
    time.sleep(1)

    # Force stop background apps
    run_adb(["shell", "am", "force-stop", "com.dmv.permit.practice.test.debug"])
    run_adb(["shell", "am", "force-stop", "org.telegram.messenger"])

    # Launch VideoEditorActivity
    print("[2] Launching VideoEditorActivity with -S...")
    run_adb(["shell", "am", "start", "-S", "-n", f"{PACKAGE}/com.mt.mtxx.mtxx.video.VideoEditorActivity"])
    time.sleep(3)

    # Dismiss any compatibility or warning dialog
    tap(540, 950)
    time.sleep(1)

    capture("evidence_video_editor_native_fixed.png")

    # Scrub timeline SeekBar
    print("[3] Scrubbing timeline...")
    swipe(200, 740, 600, 740, 350)
    time.sleep(1.5)
    capture("evidence_video_editor_scrubbed_fixed.png")

    # Select Filter tab & apply filter
    print("[4] Selecting Filter tab...")
    tap(420, 2220)
    time.sleep(1)
    tap(180, 2050) # Cinematic
    time.sleep(1.5)
    capture("evidence_video_editor_cinematic_fixed.png")

    # Launch PhotoEditorActivity
    print("[5] Launching PhotoEditorActivity for BiSeNet verification...")
    run_adb(["shell", "am", "start", "-S", "-n", f"{PACKAGE}/com.mt.mtxx.mtxx.editor.PhotoEditorActivity"])
    time.sleep(3)
    tap(540, 950)
    time.sleep(1)
    capture("evidence_photo_editor_bisenet_verified.png")

    print("[DONE] Verification finished!")

if __name__ == "__main__":
    main()
