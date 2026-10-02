import subprocess
import time
import os
import sys
import numpy as np
from PIL import Image

adb = r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
device = "192.168.1.3:40333"
out_dir = r"C:\Users\PC.DESKTOP-81LIH38\.gemini\antigravity-ide\brain\6746e7a3-7b67-49ce-9e7d-78a23785399e"

def run_adb(cmd):
    full_cmd = f'"{adb}" -s {device} {cmd}'
    res = subprocess.run(full_cmd, shell=True, capture_output=True, text=True)
    return res.stdout.strip()

print("1. Connecting to ADB device...")
subprocess.run(f'"{adb}" connect {device}', shell=True, capture_output=True)
time.sleep(0.5)

# Ensure app is in foreground
run_adb("shell am start -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity")
time.sleep(1.0)

# Swipe category bar twice to reach Làn Da
print("2. Navigating to Làn Da category...")
run_adb("shell input swipe 900 2150 100 2150 250")
time.sleep(0.5)
run_adb("shell input swipe 900 2150 100 2150 250")
time.sleep(0.5)

# Tap Làn Da at (340, 2180)
run_adb("shell input tap 340 2180")
time.sleep(1.2)

def capture_screen(filename):
    remote = f"/sdcard/{filename}"
    local = os.path.join(out_dir, filename)
    run_adb(f"shell screencap -p {remote}")
    run_adb(f"pull {remote} \"{local}\"")
    return local

# Capture base original state (before tools)
# To get unedited photo: tap on 'Chạm & Giữ để xem ảnh gốc' or we have original image
# Let's capture the tool states
tools = [
    ("tool_smooth", 140, 1930, "proof_skin_smooth.png"),
    ("tool_bright", 400, 1930, "proof_skin_bright.png"),
    ("tool_acne", 670, 1930, "proof_skin_acne.png"),
    ("tool_eyebags", 930, 1930, "proof_skin_eyebags.png")
]

# For eyebags, if it is partially scrolled or need slight swipe on tool row
# Tool row is around y=1930
captured_files = {}

for name, x, y, fname in tools:
    print(f"Testing {name} at ({x}, {y})...")
    run_adb(f"shell input tap {x} {y}")
    time.sleep(1.2)
    path = capture_screen(fname)
    captured_files[name] = path
    print(f"  -> Captured {fname} ({os.path.getsize(path)} bytes)")

# Now test smile lines: swipe tool row left
print("Scrolling tool row to reach smile lines & oil control...")
run_adb("shell input swipe 900 1930 200 1930 250")
time.sleep(0.8)

# Now smile lines is visible
tools_row2 = [
    ("tool_smile_lines", 400, 1930, "proof_skin_smile_lines.png"),
    ("tool_oil_control", 670, 1930, "proof_skin_oil_control.png")
]

for name, x, y, fname in tools_row2:
    print(f"Testing {name} at ({x}, {y})...")
    run_adb(f"shell input tap {x} {y}")
    time.sleep(1.2)
    path = capture_screen(fname)
    captured_files[name] = path
    print(f"  -> Captured {fname} ({os.path.getsize(path)} bytes)")

print("\n--- ALL SCREENSHOTS CAPTURED SUCCESSFULLY ---")
