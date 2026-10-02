import subprocess
import time
import os

adb = r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
device = "192.168.1.3:40333"
out_dir = r"C:\Users\PC.DESKTOP-81LIH38\.gemini\antigravity-ide\brain\56fd227d-6b4a-43e8-80a5-02015fa93579\scratch"

def run_adb(cmd):
    full_cmd = f'"{adb}" -s {device} {cmd}'
    res = subprocess.run(full_cmd, shell=True, capture_output=True, text=True)
    return res.stdout.strip()

print("1. Connecting ADB...")
subprocess.run(f'"{adb}" connect {device}', shell=True, capture_output=True)
time.sleep(0.5)

print("2. Ensuring PhotoEditorActivity is active...")
run_adb("shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity")
time.sleep(1.5)

print("3. Navigating to Lan Da category...")
# Swipe category bar twice to reach Làn Da
run_adb("shell input swipe 900 2150 100 2150 250")
time.sleep(0.5)
run_adb("shell input swipe 900 2150 100 2150 250")
time.sleep(0.5)

# Tap Lan Da at (340, 2180)
run_adb("shell input tap 340 2180")
time.sleep(1.2)

# Tap 'Nang tong trang su (Whiten)' at (400, 1930)
print("4. Selecting Nang tong trang su...")
run_adb("shell input tap 400 1930")
time.sleep(1.5)

# Capture screen
remote = "/sdcard/hw_chairman_test_whiten61.png"
local = os.path.join(out_dir, "hw_chairman_test_whiten61.png")
run_adb(f"shell screencap -p {remote}")
run_adb(f"pull {remote} \"{local}\"")
print(f"5. Successfully pulled hardware capture: {local} ({os.path.getsize(local)} bytes)")
