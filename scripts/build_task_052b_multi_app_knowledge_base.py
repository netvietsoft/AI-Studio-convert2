#!/usr/bin/env python3
"""
TASK_052B — F:\App\Image DEEP MULTI-APP SO KNOWLEDGE BASE ENGINE
Authority: Chairman Tony & Agent 0 (CEO / Orchestrator)
Standard: 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD & Development Workspace Standard V2.1.2
"""

import os
import sys
import io
import re
import csv
import json
import zipfile
import hashlib
import datetime
import subprocess
from collections import defaultdict
from elftools.elf.elffile import ELFFile

sys.stdout.reconfigure(encoding='utf-8')

REPO_ROOT = r"F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2"
APP_IMAGE_ROOT = r"F:\App\Image"
OUTPUT_DIR = os.path.join(REPO_ROOT, ".ai", "reports", "TASK_052B_F_APP_IMAGE_DEEP_MULTI_APP_SO_KNOWLEDGE_BASE")
NDK_BIN = r"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\26.1.10909125\toolchains\llvm\prebuilt\windows-x86_64\bin"

CXXFILT = os.path.join(NDK_BIN, "llvm-cxxfilt.exe")
READELF = os.path.join(NDK_BIN, "llvm-readelf.exe")
OBJDUMP = os.path.join(NDK_BIN, "llvm-objdump.exe")
NM = os.path.join(NDK_BIN, "llvm-nm.exe")
STRINGS = os.path.join(NDK_BIN, "llvm-strings.exe")

os.makedirs(OUTPUT_DIR, exist_ok=True)
os.makedirs(os.path.join(OUTPUT_DIR, "apps"), exist_ok=True)

APPS_SPEC = [
    {
        "slug": "b612", "id": "APP_01", "name": "B612", "folder": "B612",
        "package": "com.linecorp.b612.android", "version": "15.4.0",
        "primary_apk": "B612_15.4.0.apks", "type": "APKS", "vendor": "SNOW / LINE Corp",
        "focus_domains": ["Face", "Camera", "Filter", "Segmentation"]
    },
    {
        "slug": "beautyplus", "id": "APP_02", "name": "BeautyPlus", "folder": "Beauty Plus",
        "package": "com.commsource.beautyplus", "version": "7.46.0",
        "primary_apk": "BeautyPlus_7.46.0.apks", "type": "APKS", "vendor": "Meitu Ecosystem / Pixocial",
        "focus_domains": ["Hair", "Face", "Skin", "Body", "Reshape", "Retouch", "Color", "Render"]
    },
    {
        "slug": "adobelightroom", "id": "APP_03", "name": "Adobe Lightroom Mobile", "folder": "com.adobe.lrmobile",
        "package": "com.adobe.lrmobile", "version": "9.4.2",
        "primary_apk": "uptodown-com.adobe.lrmobile.apk", "type": "APK_WRAPPER", "vendor": "Adobe Inc / Uptodown Stub",
        "focus_domains": ["Color", "Render", "Camera"]
    },
    {
        "slug": "facetune", "id": "APP_04", "name": "Facetune", "folder": "com.lightricks.facetune.free",
        "package": "com.lightricks.facetune.free", "version": "2.60.0.1",
        "primary_apk": "Facetune+Hair,+Photo+Editor_2.60.0.1-free_APKPure.xapk", "type": "XAPK", "vendor": "Lightricks Ltd",
        "focus_domains": ["Hair", "Face", "Skin", "Reshape", "Retouch", "Segmentation", "Render"]
    },
    {
        "slug": "meitu", "id": "APP_05", "name": "Meitu", "folder": "com.mt.mtxx.mtxx",
        "package": "com.mt.mtxx.mtxx", "version": "12.17.8",
        "primary_apk": "Meitu_12.17.8_APKPure.xapk", "type": "XAPK_DECOMPILED", "vendor": "Meitu Inc",
        "focus_domains": ["Hair", "Face", "Skin", "Body", "Reshape", "Retouch", "Color", "Segmentation", "Matting", "Render", "Video"]
    },
    {
        "slug": "future", "id": "APP_06", "name": "Future Self Aging", "folder": "Future",
        "package": "com.future.self.face.aging.changer", "version": "1.0.9.6",
        "primary_apk": "Future Self Face Aging Changer_1.0.9.6_28082026.apks", "type": "APKS", "vendor": "Future Tech",
        "focus_domains": ["Face", "Retouch", "Filter"]
    },
    {
        "slug": "faceapp", "id": "APP_07", "name": "FaceApp", "folder": "io.faceapp",
        "package": "io.faceapp", "version": "12.9.6",
        "primary_apk": "FaceApp+Perfect+Face+Editor_12.9.6_APKPure.apk", "type": "APK", "vendor": "FaceApp Inc",
        "focus_domains": ["Hair", "Face", "Skin", "Relight", "Segmentation"]
    },
    {
        "slug": "picsart", "id": "APP_08", "name": "PicsArt", "folder": "PicArt",
        "package": "com.picsart.studio", "version": "30.7.8",
        "primary_apk": "Picsart_30.7.8.apks", "type": "APKS", "vendor": "PicsArt Inc",
        "focus_domains": ["Retouch", "Filter", "Inpaint", "Render"]
    },
    {
        "slug": "remini", "id": "APP_09", "name": "Remini", "folder": "Remini",
        "package": "com.bigwinepot.nwdn.international", "version": "3.7.1447",
        "primary_apk": "Remini_3.7.1447.202524746.apks", "type": "APKS_DECOMPILED", "vendor": "Bending Spoons / Big Winepot",
        "focus_domains": ["Texture", "Face", "Skin", "Retouch"]
    },
    {
        "slug": "snapedit", "id": "APP_10", "name": "SnapEdit", "folder": "snapedit.app.remove",
        "package": "snapedit.app.remove", "version": "7.7.7",
        "primary_apk": "xapk_extracted", "type": "XAPK_DECOMPILED", "vendor": "SnapEdit Team",
        "focus_domains": ["Inpaint", "Segmentation", "Video", "Render"]
    },
    {
        "slug": "timewarpscan", "id": "APP_11", "name": "Time Warp Scan", "folder": "Time Warp Scan",
        "package": "com.timewarpscan.facescan", "version": "3.8.1",
        "primary_apk": "Time Warp Scan - Face Scan_3.8.1.apks", "type": "APKS", "vendor": "TimeWarp Apps",
        "focus_domains": ["Face", "Camera", "Render"]
    },
    {
        "slug": "ulike", "id": "APP_12", "name": "Ulike", "folder": "Ulike",
        "package": "com.gorgeous.lite", "version": "5.6.2",
        "primary_apk": "ULike_5.6.2.apks", "type": "APKS", "vendor": "ByteDance / Bytedance EffectSDK",
        "focus_domains": ["Hair", "Face", "Skin", "Reshape", "Retouch", "Filter", "Render", "Video"]
    },
    {
        "slug": "vsco", "id": "APP_13", "name": "VSCO", "folder": "VSCO",
        "package": "com.vsco.cam", "version": "495",
        "primary_apk": "extracted_apks", "type": "APKS_DECOMPILED", "vendor": "VSCO Visual Supply Co",
        "focus_domains": ["Color", "Texture", "Filter", "Camera"]
    },
    {
        "slug": "wink", "id": "APP_14", "name": "Wink", "folder": "Wink",
        "package": "com.meitu.wink", "version": "3.16.5",
        "primary_apk": "Wink_3.16.5.apks", "type": "APKS", "vendor": "Meitu Inc",
        "focus_domains": ["Hair", "Face", "Skin", "Body", "Reshape", "Retouch", "Color", "Render", "Video"]
    }
]

INFRA_PATTERNS = [
    r"^libc\+\+_shared\.so$", r"^libfbjni\.so$", r"^libjsc.*\.so$", r"^libv8.*\.so$",
    r"^libcrashlytics.*\.so$", r"^libapplovin.*\.so$", r"^libapminsight.*\.so$",
    r"^libandroidx\..*\.so$", r"^libbuffer_pgl\.so$", r"^libfile_lock.*\.so$",
    r"^libdatastore_shared_counter\.so$", r"^libpglarmor\.so$", r"^libnms\.so$",
    r"^libtobEmbedPagEncrypt\.so$", r"^libpairipcore\.so$", r"^libtt_ugen_layout\.so$",
    r"^libbugsnag.*\.so$", r"^libkoom.*\.so$", r"^libxcrash.*\.so$", r"^libbytehook\.so$",
    r"^libshadowhook.*\.so$", r"^libsigner\.so$", r"^libxdl\.so$", r"^libflutter\.so$",
    r"^libnpth.*\.so$", r"^libsscronet.*\.so$", r"^libttboringssl\.so$", r"^libttcrypto\.so$",
    r"^libsysoptimizer.*\.so$", r"^libgodzilla.*\.so$", r"^libjato\.so$", r"^libkeva\.so$",
    r"^libuptodown.*\.so$", r"^libutd-services.*\.so$", r"^libbilling\.so$"
]

def is_infra_noise(so_name):
    for pat in INFRA_PATTERNS:
        if re.search(pat, so_name, re.IGNORECASE):
            return True
    return False

def classify_so(so_name):
    name_l = so_name.lower()
    if is_infra_noise(so_name):
        return "RUNTIME_INFRA", "INFRASTRUCTURE", 10
    
    if "hair" in name_l:
        return "Hair", "PRODUCT_MEANINGFUL", 95
    if any(k in name_l for k in ["facetune", "st_mobile", "stmobile", "facelandmark", "3dface", "beautyplusjni"]):
        return "Face", "PRODUCT_MEANINGFUL", 90
    if any(k in name_l for k in ["body", "slim", "pose"]):
        return "Body", "PRODUCT_MEANINGFUL", 85
    if any(k in name_l for k in ["color", "pvg", "lut", "tone", "vscocore"]):
        return "Color", "PRODUCT_MEANINGFUL", 90
    if any(k in name_l for k in ["seg", "matting", "mask"]):
        return "Segmentation", "PRODUCT_MEANINGFUL", 85
    if any(k in name_l for k in ["filter", "stunning"]):
        return "Filter", "PRODUCT_MEANINGFUL", 85
    if any(k in name_l for k in ["render", "verenderer", "layerflow", "effect", "gecore", "pixrender", "fragglerock"]):
        return "Render", "PRODUCT_MEANINGFUL", 90
    if any(k in name_l for k in ["video", "mtmvcore", "ffmpeg", "avcodec", "videocore", "ttvesdk"]):
        return "Video", "PRODUCT_MEANINGFUL", 85
    if any(k in name_l for k in ["inpaint", "smudge", "bucketfill", "brush"]):
        return "Inpaint", "PRODUCT_MEANINGFUL", 85
    if any(k in name_l for k in ["camera", "arkernel"]):
        return "Camera", "PRODUCT_MEANINGFUL", 80
    if any(k in name_l for k in ["texture", "remini"]):
        return "Texture", "PRODUCT_MEANINGFUL", 80
    if any(k in name_l for k in ["manis", "mnn", "onnx", "tensorflow", "tflite", "bytenn", "ncnn"]):
        return "AI_RUNTIME", "PRODUCT_MEANINGFUL", 85
    if any(k in name_l for k in ["opencv", "yuv", "jpeg", "image", "bmp"]):
        return "IMAGE_IO", "PRODUCT_MEANINGFUL", 75
    
    return "GENERAL_GRAPHICS", "PRODUCT_MEANINGFUL", 70

def demangle(sym):
    if not sym.startswith("_Z"):
        return sym
    try:
        p = subprocess.run([CXXFILT, sym], capture_output=True, text=True, timeout=2)
        if p.returncode == 0:
            return p.stdout.strip()
    except Exception:
        pass
    return sym

def get_elf_info(so_bytes):
    sha = hashlib.sha256(so_bytes).hexdigest()
    size = len(so_bytes)
    arch = "UNKNOWN"
    build_id = "NONE"
    soname = "NONE"
    dyn_symbols = []
    sections = []
    
    try:
        elf = ELFFile(io.BytesIO(so_bytes))
        arch = elf.get_machine_arch()
        
        # Sections
        for s in elf.iter_sections():
            sections.append(s.name)
            
        # Build ID
        note_sec = elf.get_section_by_name('.note.gnu.build-id')
        if note_sec:
            for note in note_sec.iter_notes():
                desc = note.get('n_desc')
                if desc:
                    build_id = desc
                    
        # Dynamic tags (SONAME)
        dyn_sec = elf.get_section_by_name('.dynamic')
        if dyn_sec:
            for tag in dyn_sec.iter_tags():
                if tag.entry.d_tag == 'DT_SONAME':
                    soname = tag.soname
                    
        # Dynsym
        dynsym = elf.get_section_by_name('.dynsym')
        if dynsym:
            for sym in dynsym.iter_symbols():
                if sym.name:
                    dyn_symbols.append({
                        "name": sym.name,
                        "value": hex(sym['st_value']),
                        "size": sym['st_size'],
                        "type": sym['st_info']['type'],
                        "bind": sym['st_info']['bind']
                    })
    except Exception as e:
        arch = f"ERROR: {e}"
        
    return {
        "sha256": sha,
        "size_bytes": size,
        "arch": arch,
        "build_id": build_id,
        "soname": soname,
        "sections": sections,
        "symbols": dyn_symbols
    }

print("[TASK_052B] Scanning all 14 apps and collecting libraries...")
