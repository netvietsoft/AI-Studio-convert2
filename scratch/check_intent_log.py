import subprocess

adb = r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"
target = "192.168.1.18:34335"

subprocess.run([adb, "connect", target], capture_output=True, text=True)
res = subprocess.run([adb, "-s", target, "logcat", "-d"], capture_output=True, text=True, encoding="utf-8", errors="ignore")

for line in res.stdout.split("\n"):
    if "20:54:56" in line and ("PhotoEditorActivity" in line or "Hair" in line or "17798" in line):
        print(line)
