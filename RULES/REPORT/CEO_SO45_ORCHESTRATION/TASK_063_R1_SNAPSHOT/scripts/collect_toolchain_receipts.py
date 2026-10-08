#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Collect toolchain versions, paths, SHA-256 hashes, and execution receipts for TASK_063.
"""

import os
import sys
import json
import hashlib
import subprocess
from pathlib import Path

REPORT_DIR = Path(r"RULES\REPORT\TASK_063_REPORT")
RAW_DIR = REPORT_DIR / "raw"

TOOLS = {
    "java": r"F:\TOOLS\jdk-21.0.12.1+1\bin\java.exe",
    "javac": r"F:\TOOLS\jdk-21.0.12.1+1\bin\javac.exe",
    "llvm_readelf": r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\26.1.10909125\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-readelf.exe",
    "llvm_objdump": r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\26.1.10909125\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-objdump.exe",
    "clang": r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\26.1.10909125\toolchains\llvm\prebuilt\windows-x86_64\bin\clang.exe",
    "glslc": r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\26.1.10909125\shader-tools\windows-x86_64\glslc.exe",
    "spirv_dis": r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\26.1.10909125\shader-tools\windows-x86_64\spirv-dis.exe",
    "spirv_val": r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\26.1.10909125\shader-tools\windows-x86_64\spirv-val.exe"
}

def sha256_file(p):
    h = hashlib.sha256()
    with open(p, "rb") as f:
        while chunk := f.read(1024 * 1024):
            h.update(chunk)
    return h.hexdigest()

def run_version(name, exe_path, flag="--version"):
    p = Path(exe_path)
    if not p.exists():
        return {"name": name, "path": exe_path, "status": "NOT_FOUND"}
    
    sha = sha256_file(p)
    size = p.stat().st_size
    try:
        res = subprocess.run([str(p), flag], capture_output=True, text=True, timeout=10)
        output = (res.stdout + res.stderr).strip()
        # Save raw output
        with open(RAW_DIR / f"tool_{name}_version.txt", "w", encoding="utf-8") as rf:
            rf.write(f"COMMAND: {p} {flag}\nEXIT: {res.returncode}\nSHA256: {sha}\nSIZE: {size}\n---\n{output}\n")
            
        return {
            "name": name,
            "path": str(p),
            "size": size,
            "sha256": sha,
            "exit_code": res.returncode,
            "version_snippet": output.splitlines()[0] if output else ""
        }
    except Exception as e:
        return {"name": name, "path": str(p), "size": size, "sha256": sha, "error": str(e)}

def main():
    RAW_DIR.mkdir(parents=True, exist_ok=True)
    tool_receipts = {}
    for name, path in TOOLS.items():
        flag = "-version" if name in ["java", "javac"] else "--version"
        tool_receipts[name] = run_version(name, path, flag)
        
    # Check Ghidra
    ghidra_dir = Path(r"F:\TOOLS\ghidra_12.1.4_PUBLIC")
    ghidra_info = {
        "name": "ghidra",
        "path": str(ghidra_dir),
        "exists": ghidra_dir.exists(),
        "launch_bat": str(ghidra_dir / "ghidraRun.bat"),
        "launch_bat_sha256": sha256_file(ghidra_dir / "ghidraRun.bat") if (ghidra_dir / "ghidraRun.bat").exists() else None
    }
    
    # Heartbeat receipt
    heartbeat_receipt = {
        "engine": "paseo",
        "command": "paseo heartbeat create --cron '* * * * *' --timezone Asia/Bangkok --name 'AGY SO45 task scanner' <prompt> --json",
        "heartbeat_id": "068c797c",
        "name": "AGY SO45 task scanner",
        "cadence": "cron:* * * * * (Asia/Bangkok)",
        "target": "agent:ace29908-a2b0-4777-a070-6bd100509738",
        "status": "active",
        "registered_at": "2026-10-08T03:50:16.000Z",
        "next_run": "2026-10-08T03:51:00.000Z",
        "prompt_file": ".ai/ceo/AGY_SCAN_PROMPT.txt"
    }
    
    final_receipt = {
        "task_id": "TASK_063",
        "toolchains": tool_receipts,
        "ghidra": ghidra_info,
        "heartbeat": heartbeat_receipt
    }
    
    out_file = REPORT_DIR / "06_TOOLCHAIN_AND_HEARTBEAT_RECEIPTS.json"
    with open(out_file, "w", encoding="utf-8") as f:
        json.dump(final_receipt, f, indent=2)
    print(f"Toolchain receipts written to {out_file}")

if __name__ == "__main__":
    main()
