import os
import sys
import zipfile
import json
import re
import hashlib
from pathlib import Path

sys.stdout.reconfigure(encoding='utf-8')

ROOT_DIR = Path(r"F:\App\Image")
OUT_DIR = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\.ai\reports\TASK_046_F_APP_IMAGE_MULTI_APP_SURVEY")
RAW_DIR = OUT_DIR / "raw"
OUT_DIR.mkdir(parents=True, exist_ok=True)
RAW_DIR.mkdir(parents=True, exist_ok=True)

print(f"Scanning {ROOT_DIR} ...")

app_records = {}

MODEL_EXTS = {'.tflite', '.onnx', '.mnn', '.param', '.bin', '.pb', '.pt', '.pth', '.engine', '.nb', '.weights'}
SHADER_EXTS = {'.glsl', '.frag', '.vert', '.fs', '.vs', '.spv', '.comp', '.fsh', '.vsh', '.csh', '.shader'}
LUT_EXTS = {'.cube', '.look', '.3dl', '.icc', '.icm'}
CODE_EXTS = {'.java', '.kt', '.smali', '.cpp', '.c', '.cc', '.h', '.hpp'}

def inspect_zip_entries(zfile, prefix=""):
    so_files = []
    models = []
    shaders = []
    luts = []
    manifests = []
    dex_count = 0
    total_files = 0
    total_bytes = 0
    
    for info in zfile.infolist():
        if info.is_dir():
            continue
        total_files += 1
        total_bytes += info.file_size
        filename = info.filename
        low = filename.lower()
        
        if low.endswith(".so"):
            so_files.append({"name": filename, "size": info.file_size, "crc": info.CRC})
        elif any(low.endswith(ext) for ext in MODEL_EXTS) and ("model" in low or "net" in low or "weight" in low or "ai" in low or low.endswith('.tflite') or low.endswith('.onnx') or low.endswith('.mnn') or low.endswith('.param')):
            models.append({"name": filename, "size": info.file_size})
        elif any(low.endswith(ext) for ext in SHADER_EXTS):
            shaders.append({"name": filename, "size": info.file_size})
        elif any(low.endswith(ext) for ext in LUT_EXTS) or ("lut" in low and (low.endswith('.png') or low.endswith('.jpg'))):
            luts.append({"name": filename, "size": info.file_size})
        elif low.endswith(".dex"):
            dex_count += 1
        elif low.endswith("androidmanifest.xml"):
            manifests.append(filename)
            
    return {
        "total_files": total_files,
        "total_bytes": total_bytes,
        "so_files": so_files,
        "models": models,
        "shaders": shaders,
        "luts": luts,
        "dex_count": dex_count,
        "manifests": manifests
    }

for app_folder in sorted(ROOT_DIR.iterdir()):
    if not app_folder.is_dir():
        continue
    
    app_name = app_folder.name
    print(f"\nProcessing {app_name}...")
    
    record = {
        "app_dir": app_name,
        "status": "UNKNOWN",
        "archives": [],
        "decompiled_dirs": [],
        "so_files": [],
        "models": [],
        "shaders": [],
        "luts": [],
        "dex_count": 0,
        "code_files": {"java": 0, "kt": 0, "smali": 0, "cpp": 0, "c": 0, "h": 0},
        "total_files": 0,
        "total_size": 0,
        "package_name": "",
        "version_name": "",
        "version_code": "",
        "tech_stack": []
    }
    
    # Check top level items
    for item in app_folder.iterdir():
        if item.is_file():
            size = item.stat().st_size
            record["total_size"] += size
            record["total_files"] += 1
            low = item.name.lower()
            
            if low.endswith(".apks"):
                record["archives"].append({"name": item.name, "type": "APKS", "size": size})
                # Inspect inside APKS
                try:
                    with zipfile.ZipFile(item, 'r') as apks_zip:
                        for inner_name in apks_zip.namelist():
                            if inner_name.lower().endswith(".apk"):
                                with apks_zip.open(inner_name) as inner_apk_file:
                                    # read into ZipFile
                                    import io
                                    apk_bytes = inner_apk_file.read()
                                    with zipfile.ZipFile(io.BytesIO(apk_bytes), 'r') as inner_zip:
                                        res = inspect_zip_entries(inner_zip, prefix=f"{item.name}/{inner_name}/")
                                        record["so_files"].extend(res["so_files"])
                                        record["models"].extend(res["models"])
                                        record["shaders"].extend(res["shaders"])
                                        record["luts"].extend(res["luts"])
                                        record["dex_count"] += res["dex_count"]
                except Exception as e:
                    print(f"  Error reading APKS {item.name}: {e}")
                    
            elif low.endswith(".xapk"):
                record["archives"].append({"name": item.name, "type": "XAPK", "size": size})
                try:
                    with zipfile.ZipFile(item, 'r') as xapk_zip:
                        for inner_name in xapk_zip.namelist():
                            if inner_name.lower().endswith(".apk"):
                                with xapk_zip.open(inner_name) as inner_apk_file:
                                    import io
                                    apk_bytes = inner_apk_file.read()
                                    with zipfile.ZipFile(io.BytesIO(apk_bytes), 'r') as inner_zip:
                                        res = inspect_zip_entries(inner_zip, prefix=f"{item.name}/{inner_name}/")
                                        record["so_files"].extend(res["so_files"])
                                        record["models"].extend(res["models"])
                                        record["shaders"].extend(res["shaders"])
                                        record["luts"].extend(res["luts"])
                                        record["dex_count"] += res["dex_count"]
                            elif inner_name.lower().endswith("manifest.json"):
                                try:
                                    data = json.loads(xapk_zip.read(inner_name).decode('utf-8', errors='ignore'))
                                    record["package_name"] = data.get("package_name", record["package_name"])
                                    record["version_name"] = data.get("version_name", record["version_name"])
                                    record["version_code"] = str(data.get("version_code", record["version_code"]))
                                except Exception:
                                    pass
                except Exception as e:
                    print(f"  Error reading XAPK {item.name}: {e}")
                    
            elif low.endswith(".apk"):
                record["archives"].append({"name": item.name, "type": "APK", "size": size})
                try:
                    with zipfile.ZipFile(item, 'r') as apk_zip:
                        res = inspect_zip_entries(apk_zip, prefix=f"{item.name}/")
                        record["so_files"].extend(res["so_files"])
                        record["models"].extend(res["models"])
                        record["shaders"].extend(res["shaders"])
                        record["luts"].extend(res["luts"])
                        record["dex_count"] += res["dex_count"]
                except Exception as e:
                    print(f"  Error reading APK {item.name}: {e}")
                    
        elif item.is_dir():
            record["decompiled_dirs"].append(item.name)
            # Scan directory tree
            for root, dirs, files in os.walk(item):
                record["total_files"] += len(files)
                for f in files:
                    fp = Path(root) / f
                    try:
                        fsize = fp.stat().st_size
                        record["total_size"] += fsize
                    except Exception:
                        fsize = 0
                    flow = f.lower()
                    
                    if flow.endswith(".so"):
                        rel = str(fp.relative_to(app_folder))
                        record["so_files"].append({"name": rel, "size": fsize})
                    elif any(flow.endswith(ext) for ext in MODEL_EXTS) and ("model" in flow or "net" in flow or "weight" in flow or flow.endswith('.tflite') or flow.endswith('.onnx') or flow.endswith('.mnn')):
                        rel = str(fp.relative_to(app_folder))
                        record["models"].append({"name": rel, "size": fsize})
                    elif any(flow.endswith(ext) for ext in SHADER_EXTS):
                        rel = str(fp.relative_to(app_folder))
                        record["shaders"].append({"name": rel, "size": fsize})
                    elif any(flow.endswith(ext) for ext in LUT_EXTS) or ("lut" in flow and (flow.endswith('.png') or flow.endswith('.jpg'))):
                        rel = str(fp.relative_to(app_folder))
                        record["luts"].append({"name": rel, "size": fsize})
                    elif flow.endswith(".java"):
                        record["code_files"]["java"] += 1
                    elif flow.endswith(".kt"):
                        record["code_files"]["kt"] += 1
                    elif flow.endswith(".smali"):
                        record["code_files"]["smali"] += 1
                    elif flow.endswith(".cpp") or flow.endswith(".cc"):
                        record["code_files"]["cpp"] += 1
                    elif flow.endswith(".c"):
                        record["code_files"]["c"] += 1
                    elif flow.endswith(".h") or flow.endswith(".hpp"):
                        record["code_files"]["h"] += 1
                    elif flow.endswith(".dex"):
                        record["dex_count"] += 1

    # Deduplicate SO files by name
    unique_sos = {}
    for s in record["so_files"]:
        base = Path(s["name"]).name
        if base not in unique_sos or s.get("size", 0) > unique_sos[base].get("size", 0):
            unique_sos[base] = s
    record["unique_so_count"] = len(unique_sos)
    record["unique_sos"] = sorted(list(unique_sos.keys()))

    print(f"  Archives: {[a['name'] for a in record['archives']]}")
    print(f"  Decompiled dirs: {record['decompiled_dirs']}")
    print(f"  DEX count: {record['dex_count']}, SO count: {len(record['so_files'])} (unique: {record['unique_so_count']})")
    print(f"  Models: {len(record['models'])}, Shaders: {len(record['shaders'])}, LUTs: {len(record['luts'])}")
    print(f"  Code files: {record['code_files']}")
    print(f"  Total files: {record['total_files']}, Total size: {record['total_size'] / (1024*1024):.2f} MB")
    
    app_records[app_name] = record

with open(RAW_DIR / "inventory_raw.json", "w", encoding="utf-8") as f:
    json.dump(app_records, f, indent=2, ensure_ascii=False)

print("\nSaved raw inventory to raw/inventory_raw.json")
