import subprocess
adb = r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
res = subprocess.run(f'"{adb}" -s 192.168.1.3:40333 logcat -d -s BodyContour:I PhotoEditorActivity:I', shell=True, capture_output=True, text=True)
lines = [l for l in res.stdout.split("\n") if l.strip()]
print(f"Total lines: {len(lines)}")
for line in lines[-25:]:
    print(line)
