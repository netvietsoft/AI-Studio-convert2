import os
import sys
import json
import csv
import re
import subprocess
from collections import defaultdict

JADX_SRC = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src"
V1_CPP = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT\apps\android\core\native-bridge\src\main\cpp"
CONVERT2_ROOT = r"C:\actions-runner-02\_work\AI-Studio-convert2\AI-Studio-convert2"
REPORT_DIR = r"C:\actions-runner-02\_work\AI-Studio-convert2\AI-Studio-convert2\.ai\reports\TASK_044_VENDOR_45_SO_EXHAUSTIVE_NATIVE_AUDIT"
RAW_DIR = os.path.join(REPORT_DIR, "raw")
SO_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a"

print("--- INITIALIZING CROSSWALK AND RECONSTRUCTION ENGINE ---")

# Step 1: Scan V1 C++ files
print("Scanning V1 C++ candidate files...")
v1_files = []
if os.path.exists(V1_CPP):
    for root, dirs, files in os.walk(V1_CPP):
        for f in files:
            if f.endswith(('.cpp', '.h', '.hpp', '.c')):
                rel_path = os.path.relpath(os.path.join(root, f), V1_CPP)
                v1_files.append((rel_path, os.path.join(root, f)))
print(f"Total V1 C++ files found: {len(v1_files)}")

# Step 2: Scan CONVERT2 C++ and Kotlin/Java files
print("Scanning CONVERT2 source files...")
convert2_files = []
for mod in ["lib-core-graphics", "lib-ai-engine", "lib-photo-editor", "lib-video-engine", "lib-roboneo", "app"]:
    mod_path = os.path.join(CONVERT2_ROOT, mod)
    if os.path.exists(mod_path):
        for root, dirs, files in os.walk(mod_path):
            for f in files:
                if f.endswith(('.cpp', '.h', '.hpp', '.c', '.kt', '.java')):
                    rel_path = os.path.relpath(os.path.join(root, f), CONVERT2_ROOT)
                    convert2_files.append((rel_path, os.path.join(root, f)))
print(f"Total CONVERT2 source files found: {len(convert2_files)}")

# Step 3: Scan JADX decompiled sources for native methods and System.loadLibrary calls
print("Scanning JADX decompiled sources for System.loadLibrary calls...")
so_java_loaders = defaultdict(list)
native_methods = []

# Compile regexes
load_lib_pattern = re.compile(r'System\.loadLibrary\s*\(\s*["\']([^"\']+)["\']\s*\)')
native_method_pattern = re.compile(r'public\s+(?:static\s+)?native\s+([^\(]+)\s+([a-zA-Z0-9_]+)\s*\(([^)]*)\)')

if os.path.exists(JADX_SRC):
    # Walk jadx_src
    for root, dirs, files in os.walk(JADX_SRC):
        for f in files:
            if f.endswith('.java'):
                fpath = os.path.join(root, f)
                rel_java = os.path.relpath(fpath, JADX_SRC)
                try:
                    with open(fpath, 'r', encoding='utf-8', errors='ignore') as jf:
                        content = jf.read()
                        
                        # Find loaded libraries
                        matches = load_lib_pattern.findall(content)
                        for m in matches:
                            so_java_loaders[m].append(rel_java)
                            
                        # If file contains native methods, parse them
                        if 'native ' in content:
                            pkg_match = re.search(r'package\s+([a-zA-Z0-9_.]+)\s*;', content)
                            pkg = pkg_match.group(1) if pkg_match else ""
                            cls_match = re.search(r'class\s+([a-zA-Z0-9_]+)', content)
                            cls_name = cls_match.group(1) if cls_match else f.replace('.java', '')
                            full_cls = f"{pkg}.{cls_name}" if pkg else cls_name
                            
                            for m in native_method_pattern.finditer(content):
                                ret_type = m.group(1).strip()
                                meth_name = m.group(2).strip()
                                args = m.group(3).strip()
                                native_methods.append({
                                    "class": full_cls,
                                    "method": meth_name,
                                    "return": ret_type,
                                    "args": args,
                                    "file": rel_java
                                })
                except Exception as e:
                    pass

print(f"JADX scan complete: {len(so_java_loaders)} unique loaded libraries found, {len(native_methods)} native methods indexed.")

with open(os.path.join(REPORT_DIR, "jadx_native_index.json"), "w", encoding="utf-8") as out:
    json.dump({
        "so_java_loaders": {k: v[:10] for k, v in so_java_loaders.items()},
        "native_methods_count": len(native_methods),
        "sample_methods": native_methods[:50]
    }, out, indent=2)

print("Saved JADX native index.")
