import subprocess

adb = r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
target = "192.168.1.18:34335"

res = subprocess.run([adb, "-s", target, "logcat", "-d"], capture_output=True, text=True, encoding="utf-8", errors="ignore")
lines = [line for line in res.stdout.split("\n") if "17798" in line]
print(f"Total lines for PID 17798: {len(lines)}")
for line in lines[:80]:
    print(line)
