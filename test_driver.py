import subprocess, time
from PIL import Image

ADB_EXE = r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
DEVICE_IP = "192.168.1.18:34335"

def run_adb(args):
    # Luôn đảm bảo kết nối
    subprocess.run([ADB_EXE, "connect", DEVICE_IP], capture_output=True)
    full_cmd = [ADB_EXE, "-s", DEVICE_IP] + args
    res = subprocess.run(full_cmd, capture_output=True)
    return res

def tap(x, y):
    run_adb(["shell", "input", "tap", str(int(x)), str(int(y))])

def take_screenshot(filename):
    subprocess.run([ADB_EXE, "connect", DEVICE_IP], capture_output=True)
    cmd = [ADB_EXE, "-s", DEVICE_IP, "exec-out", "screencap", "-p"]
    with open(filename, "wb") as f:
        subprocess.run(cmd, stdout=f)
    print(f"Saved: {filename}")

if __name__ == "__main__":
    # Test tap trên SeekBar (màn hình 720x1600, SeekBar Y nằm ở Y ~ 1205)
    # Kéo slider sang 85% (X = 600, Y = 1205)
    tap(600, 1205)
    time.sleep(2)
    take_screenshot("evidence_1_rose_gold_applied.png")
