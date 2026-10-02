# -*- coding: utf-8 -*-
"""
scan_sources.py — Quét cây nguồn dịch ngược (jadx) Meitu và xuất bộ ánh xạ:
  01_package_map.md        : phân loại package (độc quyền / bên thứ ba) + thống kê
  02_class_inventory.json  : mọi class độc quyền (path, dex, kích thước, kotlin file)
  03_jni_bridge.json       : bảng loadLibrary + chữ ký native method (JNI bridge map)
  03_jni_bridge.md         : bảng chữ ký JNI dạng đọc được — đặc tả cho clean-room wrappers
  04_kotlin_structure.json : ánh xạ class Java dịch ngược -> file Kotlin gốc (@DebugMetadata)
  _utils_struct.json       : ánh xạ riêng cho các file utils
"""
import os
import sys
import json
import re
import time
import shutil
from pathlib import Path
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor

sys.stdout.reconfigure(encoding='utf-8')

SOURCES = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src\sources")
OUT = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\mapping")
OUT.mkdir(parents=True, exist_ok=True)

PROPRIETARY_ROOTS = (
    "com/meitu",
    "com/mt",
    "com/mtxx",
    "com/mtie",
    "com/layerflow",
    "com/layer",
    "com/starii",
    "com/teemo",
    "com/bugtrace",
    "com/mtpay"
)

RE_DEBUG_META = re.compile(r'@DebugMetadata\(c = "([^"]+)", f = "([^"]+)", l = \{([^}]*)\}, m = "([^"]+)"\)')
RE_LOADED_FROM = re.compile(r"loaded from:\s*(\S+)")
RE_LOAD_LIB = re.compile(r'System\.loadLibrary\("([^"]+)"\)')
RE_NATIVE = re.compile(
    r"(?:(?:public|private|protected)\s+)?"
    r"(?:(?:static|final|synchronized)\s+)*"
    r"native\s+(?:synchronized\s+)?"
    r"([\w<>\[\].,? ]+?)\s+(\w+)\s*\(([^)]*)\)\s*;"
)

def classify_rel(rel_posix: str) -> str:
    for root in PROPRIETARY_ROOTS:
        if rel_posix.startswith(root + "/"):
            return "proprietary"
    return "third_party"

def fqcn(rel_posix: str) -> str:
    return rel_posix.removesuffix(".java").replace("/", ".")

print(f"Bắt đầu thu thập danh sách tệp từ: {SOURCES}...")
t0 = time.time()

stats = defaultdict(lambda: {"files": 0, "bytes": 0})
proprietary_files = []

# Duyệt thư mục nhanh bằng os.walk
sources_str = str(SOURCES)
for root, dirs, files in os.walk(sources_str):
    for f in files:
        if not f.endswith(".java"):
            continue
        full_path = os.path.join(root, f)
        rel_posix = os.path.relpath(full_path, sources_str).replace("\\", "/")
        try:
            sz = os.path.getsize(full_path)
        except OSError:
            sz = 0
            
        kind = classify_rel(rel_posix)
        stats[kind]["files"] += 1
        stats[kind]["bytes"] += sz
        
        if kind == "proprietary":
            proprietary_files.append((full_path, rel_posix, sz))

t_collect = time.time()
print(f"Thu thập {stats['proprietary']['files'] + stats['third_party']['files']:,} files "
      f"({stats['proprietary']['files']:,} độc quyền, {stats['third_party']['files']:,} bên thứ ba) "
      f"trong {t_collect - t0:.2f}s.")

# Xử lý song song các tệp độc quyền
proprietary = []
jni_bridge = []
kotlin_structure = defaultdict(lambda: {"methods": set(), "classes": []})

def process_file(item):
    full_path, rel_posix, size = item
    parts = rel_posix.split("/")
    entry = {
        "path": rel_posix,
        "package": "/".join(parts[:-1]),
        "class": parts[-1].removesuffix(".java"),
        "fqcn": fqcn(rel_posix),
        "bytes": size,
        "dex": None,
        "kotlin_file": None,
        "kotlin_method": None,
        "kotlin_fqcn": None,
    }
    
    libraries, natives = [], []
    try:
        with open(full_path, "r", encoding="utf-8", errors="replace") as fp:
            text = fp.read()
    except OSError:
        text = ""

    m = RE_LOADED_FROM.search(text)
    if m:
        entry["dex"] = m.group(1)

    m = RE_DEBUG_META.search(text)
    if m:
        entry["kotlin_fqcn"] = m.group(1)
        entry["kotlin_file"] = m.group(2)
        entry["kotlin_method"] = m.group(4)

    for lib in RE_LOAD_LIB.findall(text):
        if lib not in libraries:
            libraries.append(lib)
            
    for m2 in RE_NATIVE.finditer(text):
        natives.append({
            "name": m2.group(2),
            "returns": m2.group(1).strip(),
            "args": m2.group(3).strip()
        })

    jni_item = None
    if libraries or natives:
        jni_item = {
            "class": entry["fqcn"],
            "path": entry["path"],
            "dex": entry["dex"],
            "load_libraries": libraries,
            "native_methods": natives,
        }

    return entry, jni_item

print("Đang phân tích cấu trúc mã nguồn độc quyền đa luồng (16 workers)...")
t_scan_start = time.time()

with ThreadPoolExecutor(max_workers=16) as pool:
    for entry, jni_item in pool.map(process_file, proprietary_files):
        proprietary.append(entry)
        if entry["kotlin_file"]:
            kotlin_structure[entry["kotlin_file"]]["methods"].add(entry["kotlin_method"])
            kotlin_structure[entry["kotlin_file"]]["classes"].append(entry["fqcn"])
        if jni_item:
            jni_bridge.append(jni_item)

t_scan_end = time.time()
print(f"Phân tích hoàn tất {len(proprietary):,} files độc quyền trong {t_scan_end - t_scan_start:.2f}s.")

proprietary.sort(key=lambda e: e["path"])
jni_bridge.sort(key=lambda e: e["class"])

# --- 01: package map (markdown) ---
pkg_stats = defaultdict(lambda: {"files": 0, "bytes": 0, "jni": 0, "native": 0})
for e in proprietary:
    p = e["package"]
    pkg_stats[p]["files"] += 1
    pkg_stats[p]["bytes"] += e["bytes"]
for j in jni_bridge:
    p = "/".join(j["path"].split("/")[:-1])
    pkg_stats[p]["jni"] += 1
    pkg_stats[p]["native"] += len(j["native_methods"])

lines = [
    "# 01 — BẢN ĐỒ PACKAGE & PHÂN LOẠI MÃ NGUỒN",
    "",
    "Nguồn quét: `jadx_src/sources/` (jadx decompile, APK Meitu 12.17.8 / com.mt.mtxx.mtxx)",
    "Phạm vi phân tích: **dữ kiện cấu trúc** (tên package/class, chữ ký, ánh xạ tệp). Thân hàm độc quyền không được trích xuất bừa bãi.",
    "",
    "## A. Phân loại cấp gốc",
    "",
    "| Loại | Số file | Dung lượng |",
    "| :--- | ---: | ---: |",
]
for kind in ("proprietary", "third_party"):
    lines.append(f"| {kind} | {stats[kind]['files']:,} | {stats[kind]['bytes']/1e6:.1f} MB |")
lines += [
    "",
    "**Ghi chú:** `third_party` (androidx, com.google, okhttp3, retrofit2, kotlin, kotlinx, "
    "io.reactivex, org.*, com.facebook, coil, bytedance, tencent, alibaba, applovin, ...) được khai báo qua Gradle Version Catalog — không đưa vào mã nguồn.",
    "Nhóm độc quyền gồm: `com/meitu/*`, `com/mt/*`, `com/mtxx/*`, `com/mtie/*`, `com/layerflow/*`, `com/layer/*`, `com/starii/*`, `com/teemo/*`, `com/bugtrace/*`, `com/mtpay/*`.",
    "",
    "## B. Cây package độc quyền",
    "",
    "| Package | Files | Dung lượng | Class JNI | Native methods |",
    "| :--- | ---: | ---: | ---: | ---: |",
]
for p in sorted(pkg_stats, key=lambda x: -pkg_stats[x]["files"]):
    s = pkg_stats[p]
    lines.append(f"| `{p}` | {s['files']} | {s['bytes']/1e3:.0f} KB | {s['jni']} | {s['native']} |")

(OUT / "01_package_map.md").write_text("\n".join(lines) + "\n", encoding="utf-8")
print("Xuất thành công: 01_package_map.md")

# --- 02: class inventory ---
print("Đang ghi 02_class_inventory.json...")
(OUT / "02_class_inventory.json").write_text(
    json.dumps({
        "total_files": len(proprietary),
        "total_bytes": sum(e["bytes"] for e in proprietary),
        "classes": proprietary
    }, indent=1, ensure_ascii=False),
    encoding="utf-8"
)
print("Xuất thành công: 02_class_inventory.json")

# --- 03: JNI bridge ---
print("Đang ghi 03_jni_bridge.json...")
(OUT / "03_jni_bridge.json").write_text(
    json.dumps({
        "total_classes": len(jni_bridge),
        "total_native_methods": sum(len(j["native_methods"]) for j in jni_bridge),
        "libraries": sorted({l for j in jni_bridge for l in j["load_libraries"]}),
        "bridges": jni_bridge
    }, indent=1, ensure_ascii=False),
    encoding="utf-8"
)
print("Xuất thành công: 03_jni_bridge.json")

# --- 03b: JNI bridge (markdown, human-readable) ---
print("Đang ghi 03_jni_bridge.md...")
jni_lines = [
    "# 03 — BẢNG CẦU NỐI JNI (INTEROP SURFACE)",
    "",
    "Chữ ký native method = dữ kiện chức năng cần thiết để gọi `.so` từ Kotlin/JNI.",
    "Dùng làm đặc tả cho clean-room wrapper và interop binding.",
    "",
    f"Thư viện phát hiện: `{', '.join(sorted({l for j in jni_bridge for l in j['load_libraries']}))}`",
    "",
]
for j in jni_bridge:
    jni_lines.append(f"## {j['class']}")
    jni_lines.append("")
    jni_lines.append(f"- path: `{j['path']}` | dex: `{j['dex']}` | libraries: `{', '.join(j['load_libraries']) or '—'}`")
    jni_lines.append("")
    jni_lines.append("| Method | Returns | Args |")
    jni_lines.append("| :--- | :--- | :--- |")
    for n in j["native_methods"]:
        jni_lines.append(f"| `{n['name']}` | `{n['returns']}` | `{n['args']}` |")
    jni_lines.append("")

(OUT / "03_jni_bridge.md").write_text("\n".join(jni_lines), encoding="utf-8")
print("Xuất thành công: 03_jni_bridge.md")

# --- 04: Kotlin structure map ---
print("Đang ghi 04_kotlin_structure.json...")
kotlin_out = {
    k: {
        "classes": sorted(set(v["classes"])),
        "methods": sorted(v["methods"])
    } for k, v in sorted(kotlin_structure.items())
}
(OUT / "04_kotlin_structure.json").write_text(
    json.dumps({
        "kotlin_files": len(kotlin_out),
        "map": kotlin_out
    }, indent=1, ensure_ascii=False),
    encoding="utf-8"
)
print("Xuất thành công: 04_kotlin_structure.json")

# --- _utils_struct.json ---
utils_out = {
    k: v for k, v in kotlin_out.items()
    if any(u in k.lower() for u in ("util", "helper", "common", "ext"))
}
(OUT / "_utils_struct.json").write_text(
    json.dumps(utils_out, indent=1, ensure_ascii=False),
    encoding="utf-8"
)
print("Xuất thành công: _utils_struct.json")

# Sao chép chính file scan_sources.py vào thư mục đích mapping
this_file = Path(__file__).resolve()
target_script = OUT / "scan_sources.py"
shutil.copy2(this_file, target_script)
print(f"Đã sao chép: {target_script}")

print("\n=== THỐNG KÊ TỔNG KẾT MAPPING MEITU ===")
print(f"Proprietary files : {len(proprietary):,}")
print(f"Third-party files : {stats['third_party']['files']:,}")
print(f"JNI bridge classes: {len(jni_bridge):,} | native methods: {sum(len(j['native_methods']) for j in jni_bridge):,}")
print(f"Libraries         : {sorted({l for j in jni_bridge for l in j['load_libraries']})}")
print(f"Kotlin files      : {len(kotlin_out):,}")
print(f"Thư mục xuất      : {OUT}")
