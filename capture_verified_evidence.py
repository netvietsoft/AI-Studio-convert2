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
    # 1. Bật sáng màn hình và mở khóa
    print("[1] Waking up device...")
    run_adb(["shell", "input", "keyevent", "224"]) # KEYCODE_WAKEUP
    run_adb(["shell", "input", "keyevent", "82"])  # KEYCODE_MENU (unlock)
    run_adb(["shell", "svc", "power", "stayon", "true"]) # Giữ màn hình sáng khi cắm nguồn
    time.sleep(1)

    # 2. Khởi chạy VideoEditorActivity
    print("[2] Starting VideoEditorActivity...")
    run_adb(["shell", "am", "start", "-n", f"{PACKAGE}/com.mt.mtxx.mtxx.video.VideoEditorActivity", "-f", "0x10000000"])
    time.sleep(2.5)

    # Dismiss compatibility dialog nếu có
    tap(540, 950)
    time.sleep(1)

    capture("evidence_video_editor_1_initial.png")

    # 3. Kéo timeline sang 60%
    print("[3] Scrubbing timeline to 60%...")
    # Tọa độ SeekBar timeline khoảng Y = 740 trên màn hình 1080x2340 hoặc 720x1560 của Galaxy A50
    # Galaxy A50: 1080 x 2340 resolution
    swipe(250, 740, 750, 740, 400)
    time.sleep(1.5)
    capture("evidence_video_editor_2_scrubbed.png")

    # 4. Chuyển sang Tab "Bộ Lọc Video"
    print("[4] Selecting Filter tab...")
    # Category tab nằm dưới thanh công cụ
    tap(420, 2220)
    time.sleep(1)

    # Chọn filter "Cinematic Film 35mm"
    print("[5] Selecting Cinematic Filter...")
    tap(180, 2050)
    time.sleep(1.5)
    capture("evidence_video_editor_3_cinematic.png")

    # Chọn filter "Neon Cyberpunk 4K"
    print("[6] Selecting Cyberpunk Filter...")
    tap(650, 2050)
    time.sleep(1.5)
    capture("evidence_video_editor_4_cyberpunk.png")

    # 5. Playback C++ frame loop
    print("[7] Testing Realtime Playback...")
    tap(540, 700) # Play button
    time.sleep(3)
    capture("evidence_video_editor_5_playback.png")
    tap(540, 700) # Pause
    time.sleep(1)

    # 6. Khởi chạy PhotoEditorActivity
    print("[8] Starting PhotoEditorActivity for BiSeNet Face Parsing...")
    run_adb(["shell", "am", "start", "-n", f"{PACKAGE}/com.mt.mtxx.mtxx.editor.PhotoEditorActivity", "-f", "0x10000000"])
    time.sleep(2.5)
    tap(540, 950) # Dismiss dialog if any
    time.sleep(1)
    capture("evidence_photo_editor_bisenet_real.png")

    print("[SUCCESS] All screenshots captured successfully!")

if __name__ == "__main__":
    main()
