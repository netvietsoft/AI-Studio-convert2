#!/usr/bin/env python3
"""
TASK_038 - Forensic Module 3: Java & Kotlin Native Declaration Scanner (Optimized)
Governing Standard: 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD & Development Workspace Standard V2.1
Authority: Chairman Tony
"""

import os
import sys
import subprocess
import re
import csv

JADX_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src"
PROJECT_DIRS = [
    r"app\src\main",
    r"lib-core-graphics",
    r"lib-ai-engine"
]

def scan_java_native_declarations():
    print("[JAVA-SCAN] Scanning jadx_src and project source for native declarations...")
    cmd = ["rg", "--vimgrep", "-e", r"\bnative\s+.*\b\w+\s*\(", JADX_DIR]
    print("[JAVA-SCAN] Executing ripgrep on jadx_src...")
    proc = subprocess.run(cmd, capture_output=True, text=True, errors="ignore")
    lines = proc.stdout.splitlines()
    print(f"[JAVA-SCAN] ripgrep found {len(lines)} raw native lines in jadx_src")
    
    records = []
    # Regex matching native method declaration line
    # e.g.: public static native String guulam(Context context, String str);
    # e.g.: public static native Class<?> fC(String str) throws Throwable;
    nat_pat = re.compile(r"\bnative\s+([A-Za-z0-9_$<>\[\],\s\?]+?)\s+([A-Za-z0-9_$]+)\s*\((.*?)\)(?:\s*throws\s+[A-Za-z0-9_$,\s]+)?\s*;")
    
    seen = set()
    for line in lines:
        parts = line.split(":", 3)
        if len(parts) < 4:
            continue
        filepath, lnum, col, text = parts[0], parts[1], parts[2], parts[3]
        
        norm_path = filepath.replace("/", "\\")
        if "\\sources\\" in norm_path:
            rel = norm_path.split("\\sources\\")[1]
            cls_name = rel.replace("\\", ".").replace(".java", "")
        else:
            cls_name = os.path.basename(filepath).replace(".java", "")
            
        m = nat_pat.search(text)
        if m:
            ret_type = m.group(1).strip()
            method_name = m.group(2).strip()
            params = m.group(3).strip()
            
            # Clean up modifiers from ret_type if any got caught
            for mod in ["public", "private", "protected", "static", "final", "synchronized", "strictfp"]:
                if ret_type.startswith(mod + " "):
                    ret_type = ret_type[len(mod)+1:].strip()
                    
            key = (cls_name, method_name, params)
            if key not in seen:
                seen.add(key)
                records.append({
                    "class": cls_name,
                    "method": method_name,
                    "return_type": ret_type,
                    "parameters": params,
                    "file": filepath,
                    "line": lnum,
                    "source_type": "JAVA_DECOMPILED"
                })
                
    # Also scan Kotlin project files for `external fun`
    for pdir in PROJECT_DIRS:
        if os.path.exists(pdir):
            for root, _, files in os.walk(pdir):
                for f in files:
                    if f.endswith(".kt") or f.endswith(".java"):
                        fp = os.path.join(root, f)
                        with open(fp, "r", encoding="utf-8", errors="ignore") as kf:
                            for idx, kline in enumerate(kf, 1):
                                if "external fun" in kline:
                                    ext_m = re.search(r"external\s+fun\s+([A-Za-z0-9_$]+)\s*\((.*?)\)(?:\s*:\s*([A-Za-z0-9_$<>\[\]?]+))?", kline)
                                    if ext_m:
                                        mname = ext_m.group(1)
                                        mparams = ext_m.group(2)
                                        mret = ext_m.group(3) or "Unit"
                                        cls = f.replace(".kt", "").replace(".java", "")
                                        key = (cls, mname, mparams)
                                        if key not in seen:
                                            seen.add(key)
                                            records.append({
                                                "class": cls,
                                                "method": mname,
                                                "return_type": mret,
                                                "parameters": mparams,
                                                "file": fp,
                                                "line": str(idx),
                                                "source_type": "KOTLIN_PROJECT"
                                            })
                                            
    print(f"[JAVA-SCAN] Extracted {len(records)} unique Java/Kotlin native declarations")
    return records

if __name__ == "__main__":
    records = scan_java_native_declarations()
    print("Sample extracted records:")
    for r in records[:15]:
        print(f"  {r['class']}.{r['method']}({r['parameters']}) : {r['return_type']} [{r['source_type']}]")
