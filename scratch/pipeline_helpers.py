#!/usr/bin/env python3
"""
TASK_040 Full Discovery & Forensic Engine
Authoritative scan root: F:\CONVERT
Strictly Read-Only on F:\CONVERT
"""

import os
import sys
import json
import csv
import hashlib
import time
import subprocess
from pathlib import Path
from collections import defaultdict, Counter
import re

ROOT = Path(r"F:\CONVERT")
OUTPUT_DIR = Path(r"C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2\.ai\reports\TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY")
RAW_DIR = OUTPUT_DIR / "raw"
RAW_DIR.mkdir(parents=True, exist_ok=True)

SOURCE_EXTS = {
    '.java', '.kt', '.c', '.cc', '.cpp', '.cxx', '.h', '.hpp',
    '.smali', '.xml', '.gradle', '.kts', '.py', '.sh', '.bat', '.cmd',
    '.json', '.so', '.a', '.dll', '.dylib', '.txt', '.md', '.csv',
    '.cmake', '.proto', '.glsl', '.vert', '.frag', '.comp', '.lua'
}

BINARY_EXTS = {'.so', '.a', '.dll', '.dex', '.apk', '.xapk', '.jar', '.aar', '.bin', '.param', '.onnx', '.pt', '.pth'}
IMAGE_EXTS = {'.png', '.jpg', '.jpeg', '.webp', '.bmp', '.gif'}

KEYWORDS = [
    "hair", "dye", "matting", "segment", "parsing",
    "MTSoftHairFilter", "HairMaskFilterToFBO", "GrayFilterToFBO",
    "BlurHFilterToFBO", "BlurVFilterToFBO", "MakeupHairSoftPart",
    "nSetTraditionHairDyeIntensityAndShine", "RegisterNatives", "JNI_OnLoad",
    "JNINativeMethod", "external fun", "native", "System.loadLibrary",
    "CMakeLists", "HairPipeline", "FaceParsing", "LayerFlow", "Manis",
    "PVGColor", "FilterKernel"
]

# Case-sensitive mapping for specific symbols
CASE_SENSITIVE_KEYWORDS = {
    "MTSoftHairFilter", "HairMaskFilterToFBO", "GrayFilterToFBO",
    "BlurHFilterToFBO", "BlurVFilterToFBO", "MakeupHairSoftPart",
    "nSetTraditionHairDyeIntensityAndShine", "RegisterNatives", "JNI_OnLoad",
    "JNINativeMethod", "external fun", "HairPipeline", "FaceParsing",
    "LayerFlow", "Manis", "PVGColor", "FilterKernel"
}

def get_git_info(path: Path):
    git_dir = path / ".git"
    if not git_dir.exists():
        return False, None, None, None
    try:
        p_head = subprocess.run(["git", "rev-parse", "HEAD"], cwd=str(path), capture_output=True, text=True, timeout=5)
        head = p_head.stdout.strip() if p_head.returncode == 0 else None
        p_branch = subprocess.run(["git", "rev-parse", "--abbrev-ref", "HEAD"], cwd=str(path), capture_output=True, text=True, timeout=5)
        branch = p_branch.stdout.strip() if p_branch.returncode == 0 else None
        p_remote = subprocess.run(["git", "remote", "-v"], cwd=str(path), capture_output=True, text=True, timeout=5)
        remote = p_remote.stdout.strip().splitlines()[0] if p_remote.returncode == 0 and p_remote.stdout.strip() else "None (Local repo)"
        return True, head, branch, remote
    except Exception as e:
        return True, f"ERROR: {e}", None, None

def detect_markers_in_dir(path: Path):
    markers = []
    marker_checks = [
        "settings.gradle", "settings.gradle.kts",
        "build.gradle", "build.gradle.kts",
        "gradlew", "gradlew.bat",
        "AndroidManifest.xml",
        "CMakeLists.txt", "Android.mk", "Application.mk",
        "apktool.yml", ".git", "local.properties"
    ]
    for m in marker_checks:
        if (path / m).exists():
            markers.append(m)
    
    # check subdirs
    if (path / "src" / "main" / "java").exists():
        markers.append("src/main/java")
    if (path / "src" / "main" / "kotlin").exists():
        markers.append("src/main/kotlin")
    if (path / "src" / "main" / "cpp").exists():
        markers.append("src/main/cpp")
    if (path / "src" / "main" / "jniLibs").exists():
        markers.append("src/main/jniLibs")
    if (path / "jniLibs").exists():
        markers.append("jniLibs")
    if (path / "smali").exists():
        markers.append("smali")
    if (path / "sources").exists():
        markers.append("sources")
    if (path / "resources").exists():
        markers.append("resources")
    if (path / "assets").exists():
        markers.append("assets")
    if (path / "res").exists():
        markers.append("res")
    return markers

def detect_build_system(markers, path: Path):
    bs = []
    if any(m.startswith("settings.gradle") or m.startswith("build.gradle") or "gradlew" in m for m in markers):
        bs.append("Gradle")
    if "CMakeLists.txt" in markers or (path / "CMakeLists.txt").exists():
        bs.append("CMake")
    if "Android.mk" in markers or (path / "Android.mk").exists():
        bs.append("NDK-Build")
    if any(f.name.endswith(".py") for f in path.glob("*.py")):
        bs.append("Python")
    if not bs:
        return "None"
    return "/".join(bs)

def detect_package_id(path: Path):
    # Check AndroidManifest.xml
    manifests = list(path.glob("**/AndroidManifest.xml"))
    for m in manifests[:5]:
        try:
            with open(m, "r", encoding="utf-8", errors="ignore") as f:
                content = f.read(4096)
                pkg = re.search(r'package="([^"]+)"', content)
                if pkg:
                    return pkg.group(1)
        except Exception:
            pass
    # Check build.gradle or build.gradle.kts
    for bg in [path / "build.gradle.kts", path / "build.gradle", path / "app" / "build.gradle.kts", path / "app" / "build.gradle"]:
        if bg.exists():
            try:
                with open(bg, "r", encoding="utf-8", errors="ignore") as f:
                    content = f.read(8192)
                    app_id = re.search(r'applicationId\s*=\s*["\']([^"\']+)["\']', content)
                    if not app_id:
                        app_id = re.search(r'applicationId\s+["\']([^"\']+)["\']', content)
                    if not app_id:
                        app_id = re.search(r'namespace\s*=\s*["\']([^"\']+)["\']', content)
                    if app_id:
                        return app_id.group(1)
            except Exception:
                pass
    return "N/A"

print("Helper functions defined successfully.")
