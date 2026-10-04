#!/usr/bin/env python3
"""
scripts/forensics/audit_toolchain.py
Audit installed tools on runner for TASK_038.
"""
import os
import sys
import json
import shutil
import platform
import subprocess
from pathlib import Path

def main():
    print("[*] Auditing local runner forensic toolchain...")
    report_raw_dir = Path(".ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION/raw/tool-logs")
    report_raw_dir.mkdir(parents=True, exist_ok=True)

    ndk_bin = Path(r"D:\SetupC\android-ndk-r27\toolchains\llvm\prebuilt\windows-x86_64\bin")
    tools = {
        "llvm-readelf": ndk_bin / "llvm-readelf.exe",
        "llvm-objdump": ndk_bin / "llvm-objdump.exe",
        "llvm-nm": ndk_bin / "llvm-nm.exe",
        "llvm-strings": ndk_bin / "llvm-strings.exe",
        "llvm-cxxfilt": ndk_bin / "llvm-cxxfilt.exe",
        "llvm-size": ndk_bin / "llvm-size.exe",
        "git": Path(shutil.which("git") or "git"),
        "python": Path(sys.executable),
    }

    tool_info = {}
    for name, path in tools.items():
        exists = path.exists() if isinstance(path, Path) and path.is_absolute() else (shutil.which(str(path)) is not None)
        version_str = "NOT_INSTALLED"
        if exists:
            try:
                cmd = [str(path), "--version"]
                res = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, timeout=10)
                version_str = res.stdout.strip().split("\n")[0] if res.stdout else res.stderr.strip().split("\n")[0]
            except Exception as e:
                version_str = f"EXISTS_VERSION_ERROR: {e}"
        tool_info[name] = {
            "path": str(path),
            "exists": exists,
            "version": version_str
        }
        print(f"  - {name}: {version_str} ({path})")

    # Python module inventory
    py_modules = {}
    for mod in ["elftools", "capstone", "networkx", "androguard", "apkInspector", "llvmlite", "torch", "ncnn"]:
        try:
            m = __import__(mod)
            v = getattr(m, "__version__", "installed")
            py_modules[mod] = {"installed": True, "version": str(v)}
            print(f"  - Python module {mod}: {v}")
        except ImportError:
            py_modules[mod] = {"installed": False, "version": None}
            print(f"  - Python module {mod}: NOT INSTALLED")

    runner_env = {
        "os": platform.platform(),
        "processor": platform.processor(),
        "machine": platform.machine(),
        "python_version": sys.version,
        "cpu_count": os.cpu_count(),
        "tools": tool_info,
        "python_modules": py_modules
    }

    out_file = report_raw_dir / "toolchain_audit.json"
    with open(out_file, "w", encoding="utf-8") as f:
        json.dump(runner_env, f, indent=2)

    print(f"[+] Toolchain audit written to {out_file}")

if __name__ == "__main__":
    main()
