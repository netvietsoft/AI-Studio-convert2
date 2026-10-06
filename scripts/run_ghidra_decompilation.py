"""
Ghidra Decompiler Runner for TASK_061
Runs analyzeHeadless on target libraries and exports decompiled C code.
"""

import os
import sys
import subprocess
import time
from datetime import datetime, timezone, timedelta

REPO_ROOT = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2"
SO_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a"
GHIDRA_DIR = r"F:\TOOLS\ghidra_12.1.4_PUBLIC"
JDK_DIR = r"F:\TOOLS\jdk-21.0.12.1+1"
PROJECT_DIR = r"F:\TOOLS\ghidra_projects"
SCRIPT_DIR = os.path.join(REPO_ROOT, "scripts", "ghidra_scripts")
OUTPUT_DIR = os.path.join(REPO_ROOT, ".ai", "reconstruction", "evidence", "TASK_061", "ghidra_decompiled")
LOG_DIR = os.path.join(REPO_ROOT, "RULES", "REPORT", "TASK_061_REPORT", "08_COMMAND_LOG")

VN_TZ = timezone(timedelta(hours=7))

def run_headless_on_so(so_name, max_cpu=2):
    os.makedirs(PROJECT_DIR, exist_ok=True)
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    os.makedirs(LOG_DIR, exist_ok=True)

    so_path = os.path.join(SO_DIR, so_name)
    if not os.path.exists(so_path):
        print(f"Error: {so_path} does not exist!")
        return False

    headless_bat = os.path.join(GHIDRA_DIR, "support", "analyzeHeadless.bat")
    log_file = os.path.join(LOG_DIR, f"ghidra_{so_name}.log")

    env = os.environ.copy()
    env["JAVA_HOME"] = JDK_DIR
    env["PATH"] = os.path.join(JDK_DIR, "bin") + os.pathsep + env.get("PATH", "")
    env["GHIDRA_HEADLESS_MAXMEM"] = "4G"

    cmd = [
        headless_bat,
        PROJECT_DIR,
        "TASK_061_PROJ",
        "-import", so_path,
        "-scriptPath", SCRIPT_DIR,
        "-postScript", "ExportDecompiledTargets.java",
        "-max-cpu", str(max_cpu),
        "-overwrite"
    ]

    t0_dt = datetime.now(VN_TZ)
    t0 = time.time()
    print(f"[{t0_dt.isoformat()}] Starting Ghidra analysis on {so_name}...")
    print(f"Command: {' '.join(cmd)}")

    with open(log_file, "w", encoding="utf-8") as lf:
        lf.write(f"=== Command Start: {t0_dt.isoformat()} ===\n")
        lf.write(f"Command: {' '.join(cmd)}\n\n")
        lf.flush()

        proc = subprocess.Popen(
            cmd,
            env=env,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            bufsize=1
        )

        for line in proc.stdout:
            lf.write(line)
            lf.flush()
            if "INFO" in line or "Exporting" in line or "Exported" in line or "ERROR" in line:
                print(f"  [{so_name}] {line.strip()}")

        proc.wait()

    t1_dt = datetime.now(VN_TZ)
    elapsed = time.time() - t0
    print(f"[{t1_dt.isoformat()}] Finished {so_name} in {elapsed:.2f}s (Exit code: {proc.returncode})")
    return proc.returncode == 0

if __name__ == "__main__":
    target = sys.argv[1] if len(sys.argv) > 1 else "libMTFilterKernel.so"
    run_headless_on_so(target)
