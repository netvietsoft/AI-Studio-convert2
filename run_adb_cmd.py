import subprocess
import sys

ADB = r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe"

def get_active_device():
    res = subprocess.run([ADB, "devices"], capture_output=True, text=True, encoding="utf-8", errors="ignore")
    lines = res.stdout.strip().splitlines()
    active = []
    for line in lines[1:]:
        parts = line.strip().split()
        if len(parts) >= 2 and parts[1] == "device":
            active.append(parts[0])
    if active:
        # Prefer the mDNS TLS or wifi device
        for d in active:
            if "adb-" in d or "192.168." in d:
                return d
        return active[0]
    return "192.168.1.3:40333"

def run_adb(args):
    target = get_active_device()
    full_cmd = [ADB, "-s", target] + args
    res = subprocess.run(full_cmd, capture_output=True, text=True, encoding="utf-8", errors="ignore")
    return res.stdout, res.stderr, res.returncode

if __name__ == "__main__":
    if len(sys.argv) > 1:
        out, err, code = run_adb(sys.argv[1:])
        print(out)
        if err:
            print("ERR:", err, file=sys.stderr)
        sys.exit(code)
    else:
        print("Usage: python run_adb_cmd.py <adb-args>")
