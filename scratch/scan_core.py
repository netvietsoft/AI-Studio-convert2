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
import datetime
import subprocess
from pathlib import Path
from collections import defaultdict, Counter
import re

ROOT = Path(r"F:\CONVERT")
OUTPUT_DIR = Path(r"C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2\.ai\reports\TASK_040_F_CONVERT_ROOT_SOURCE_TREE_FULL_DISCOVERY")
RAW_DIR = OUTPUT_DIR / "raw"
RAW_DIR.mkdir(parents=True, exist_ok=True)

# Candidate paths list
CANDIDATE_DIRS = [
    # Top-level direct children
    ROOT,
    ROOT / "com.lightricks.facetune.free",
    ROOT / "com.mt.mtxx.mtxx",
    ROOT / "Material Image Editor",
    ROOT / "tools",

    # Facetune Family
    ROOT / "com.lightricks.facetune.free" / "CONVERT",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "app",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "feature-ai-retouch",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "feature-cloud-ai",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "feature-story-maker",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "lib-billing",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "lib-filters",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "lib-image-editing",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "lib-logging",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "lib-storage-db",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "lib-ui-toolkit",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "lib-video-engine",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "mapping",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "ncnn-sdk",
    ROOT / "com.lightricks.facetune.free" / "CONVERT" / "reference",
    ROOT / "com.lightricks.facetune.free" / "SOURCE",
    ROOT / "com.lightricks.facetune.free" / "SOURCE" / "apktool_out",
    ROOT / "com.lightricks.facetune.free" / "SOURCE" / "com.lightricks.facetune.free",
    ROOT / "com.lightricks.facetune.free" / "SOURCE" / "extracted_xapk",
    ROOT / "com.lightricks.facetune.free" / "SOURCE" / "jadx_out",
    ROOT / "com.lightricks.facetune.free" / "SOURCE" / "Redesign",
    ROOT / "com.lightricks.facetune.free" / "SOURCE" / "Report",
    ROOT / "com.lightricks.facetune.free" / "SOURCE" / "report 2",
    ROOT / "com.lightricks.facetune.free" / "Report",
    ROOT / "com.lightricks.facetune.free" / "report 2",
    ROOT / "com.lightricks.facetune.free" / "ui screen short",
    ROOT / "com.lightricks.facetune.free" / ".ktcheck",
    ROOT / "com.lightricks.facetune.free" / ".ktcheck9",
    ROOT / "com.lightricks.facetune.free" / ".tmpdex",
    ROOT / "com.lightricks.facetune.free" / ".agents",

    # Meitu CONVERT V1 Monorepo Family
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "app",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "core",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "core" / "common",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "core" / "data",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "core" / "designsystem",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "core" / "native-bridge",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "core" / "network",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "core" / "render",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "aiphoto",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "album",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "beauty",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "camera",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "community",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "drafts",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "editor",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "home",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "idphoto",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "livephoto",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "nextai",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "poster",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "profile",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "puzzle",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "settings",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "templates",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "tools",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "videoedit",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "android" / "feature" / "vip",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "cms",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "desktop",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "ios",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "apps" / "web",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "ANDROID",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "AUTOMATION",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "BACKEND",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "BAOCAO",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "data",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "datasets",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "design",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "Docs",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "infra",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "packages",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "prototype",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "reconstruction-input",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "release",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "Report",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "scripts",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "services",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "tests",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "tools",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "worktrees",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT" / "YEUCAU",

    # Meitu CONVERT2 Workspace
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "app",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "backend",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "Docs",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "FIX",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "gallery",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "lib-ai-engine",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "lib-billing",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "lib-common-ui",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "lib-core-graphics",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "lib-photo-editor",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "lib-roboneo",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "lib-video-engine",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "mapping",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "scripts",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "tests",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "test_assets",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "Tip",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "validation_phase01",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "worktrees",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "TASK_022_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "TASK_023_FULL_BODY_PHYSICAL_DEVICE_VISUAL_GALLERY",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "TASK_025_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "TASK_026_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY",
    ROOT / "com.mt.mtxx.mtxx" / "CONVERT2" / "TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY",

    # Meitu SOURCE Decompiled Family
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "apktool_manifest",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "apktool_out",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "BAO CAO CHU TICH",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "Demo Data",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "dex_files",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "extracted_assets",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "extracted_native_libs",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "eye_verification_reports",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "full_system_verification_reports",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "jadx_src",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "jadx_src" / "sources",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "jadx_src" / "resources",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "mitu",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "mitu" / "Demo Data",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "mitu" / "Redesign",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "mitu" / "Report",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "mitu" / "UI ScreenShot",
    ROOT / "com.mt.mtxx.mtxx" / "SOURCE" / "Redesign",

    # Other Meitu Assets & Backups
    ROOT / "com.mt.mtxx.mtxx" / "_stray_backup_w9",
    ROOT / "com.mt.mtxx.mtxx" / "_stray_backup_w9" / "apps" / "android" / "feature" / "community",
    ROOT / "com.mt.mtxx.mtxx" / "Yeucau",
    ROOT / "com.mt.mtxx.mtxx" / "ẢNH",
    ROOT / "com.mt.mtxx.mtxx" / "beard_assets_10_png",
    ROOT / "com.mt.mtxx.mtxx" / ".vscode",

    # Material Image Editor
    ROOT / "Material Image Editor",
    ROOT / "Material Image Editor" / "Mitu",
    ROOT / "Material Image Editor" / "Mitu" / "material",

    # Tools
    ROOT / "tools",
    ROOT / "tools" / "docker",
    ROOT / "tools" / "minio"
]

KEYWORDS = [
    "hair", "dye", "matting", "segment", "parsing",
    "MTSoftHairFilter", "HairMaskFilterToFBO", "GrayFilterToFBO",
    "BlurHFilterToFBO", "BlurVFilterToFBO", "MakeupHairSoftPart",
    "nSetTraditionHairDyeIntensityAndShine", "RegisterNatives", "JNI_OnLoad",
    "JNINativeMethod", "external fun", "native", "System.loadLibrary",
    "CMakeLists", "HairPipeline", "FaceParsing", "LayerFlow", "Manis",
    "PVGColor", "FilterKernel"
]

def format_bytes(b):
    if b < 1024:
        return f"{b} B"
    elif b < 1024 * 1024:
        return f"{b / 1024:.2f} KB"
    elif b < 1024 * 1024 * 1024:
        return f"{b / (1024 * 1024):.2f} MB"
    else:
        return f"{b / (1024 * 1024 * 1024):.2f} GB"

def get_git_info(p: Path):
    git_dir = p / ".git"
    if not git_dir.exists():
        return False, None, None, None, 0, None, None
    try:
        p_head = subprocess.run(["git", "rev-parse", "HEAD"], cwd=str(p), capture_output=True, text=True, timeout=5)
        head = p_head.stdout.strip() if p_head.returncode == 0 else None
        p_branch = subprocess.run(["git", "rev-parse", "--abbrev-ref", "HEAD"], cwd=str(p), capture_output=True, text=True, timeout=5)
        branch = p_branch.stdout.strip() if p_branch.returncode == 0 else None
        p_remote = subprocess.run(["git", "remote", "-v"], cwd=str(p), capture_output=True, text=True, timeout=5)
        remote = p_remote.stdout.strip().splitlines()[0] if p_remote.returncode == 0 and p_remote.stdout.strip() else "None (Local repo)"
        
        # uncommitted changes
        p_status = subprocess.run(["git", "status", "--porcelain"], cwd=str(p), capture_output=True, text=True, timeout=5)
        uncommitted = len(p_status.stdout.strip().splitlines()) if p_status.returncode == 0 and p_status.stdout.strip() else 0
        
        # last commit
        p_log = subprocess.run(["git", "log", "-1", "--format=%cd|%s", "--date=iso"], cwd=str(p), capture_output=True, text=True, timeout=5)
        last_date, last_sub = None, None
        if p_log.returncode == 0 and "|" in p_log.stdout:
            parts = p_log.stdout.strip().split("|", 1)
            last_date, last_sub = parts[0], parts[1]

        return True, head, branch, remote, uncommitted, last_date, last_sub
    except Exception as e:
        return True, f"ERROR: {e}", None, None, 0, None, None

def detect_markers(p: Path):
    markers = []
    checks = [
        "settings.gradle", "settings.gradle.kts",
        "build.gradle", "build.gradle.kts",
        "gradlew", "gradlew.bat",
        "AndroidManifest.xml",
        "CMakeLists.txt", "Android.mk", "Application.mk",
        "apktool.yml", ".git", "local.properties"
    ]
    for m in checks:
        if (p / m).exists():
            markers.append(m)
    if (p / "src" / "main" / "java").exists():
        markers.append("src/main/java")
    if (p / "src" / "main" / "kotlin").exists():
        markers.append("src/main/kotlin")
    if (p / "src" / "main" / "cpp").exists():
        markers.append("src/main/cpp")
    if (p / "src" / "main" / "jniLibs").exists():
        markers.append("src/main/jniLibs")
    if (p / "jniLibs").exists():
        markers.append("jniLibs")
    if (p / "smali").exists() or any((p / f"smali_classes{i}").exists() for i in range(2, 10)):
        markers.append("smali")
    if (p / "sources").exists():
        markers.append("sources")
    if (p / "resources").exists():
        markers.append("resources")
    if (p / "assets").exists():
        markers.append("assets")
    if (p / "res").exists():
        markers.append("res")
    return markers

def detect_build_system(markers, p: Path):
    bs = []
    if any(m.startswith("settings.gradle") or m.startswith("build.gradle") or "gradlew" in m for m in markers):
        bs.append("Gradle")
    if "CMakeLists.txt" in markers or (p / "CMakeLists.txt").exists():
        bs.append("CMake")
    if "Android.mk" in markers or (p / "Android.mk").exists():
        bs.append("NDK-Build")
    if any(f.name.endswith(".py") for f in p.glob("*.py")):
        bs.append("Python")
    if not bs:
        return "None"
    return "/".join(bs)

def detect_package_id(p: Path):
    for m in p.glob("**/AndroidManifest.xml"):
        try:
            with open(m, "r", encoding="utf-8", errors="ignore") as f:
                content = f.read(4096)
                pkg = re.search(r'package="([^"]+)"', content)
                if pkg:
                    return pkg.group(1)
        except Exception:
            pass
    for bg in [p / "build.gradle.kts", p / "build.gradle", p / "app" / "build.gradle.kts", p / "app" / "build.gradle"]:
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

def classify(rel_str: str, path: Path, markers: list, ext_counts: Counter):
    rel_low = rel_str.lower().replace("/", "\\")
    
    if rel_low == ".":
        return "A ORIGINAL_SOURCE_PROJECT"

    # CONVERT2 workspace
    if "convert2" in rel_low:
        if "gallery" in rel_low:
            return "G ASSET_RESOURCE_EXTRACT"
        if "validation" in rel_low:
            return "H BUILD_OUTPUT_OR_CACHE"
        return "B RECONSTRUCTED_CONVERT2_SOURCE"

    # Facetune CONVERT
    if "facetune" in rel_low and "convert" in rel_low:
        if "ncnn-sdk" in rel_low:
            return "E NATIVE_BINARY_EXTRACT"
        return "B RECONSTRUCTED_CONVERT2_SOURCE"

    # Meitu CONVERT V1
    if "com.mt.mtxx.mtxx\\convert" in rel_low:
        if "report" in rel_low or "baocao" in rel_low or "automation\\report" in rel_low:
            return "F NATIVE_PSEUDOCODE_OR_REVERSE_OUTPUT"
        if "reconstruction-input" in rel_low or "datasets" in rel_low or "data" in rel_low or "yeucau" in rel_low:
            return "G ASSET_RESOURCE_EXTRACT"
        if "release" in rel_low:
            return "H BUILD_OUTPUT_OR_CACHE"
        return "B RECONSTRUCTED_CONVERT2_SOURCE"

    # Tools
    if "tools" in rel_low and ("docker" in rel_low or "minio" in rel_low or rel_low.endswith("tools")):
        return "J TOOL_WORKSPACE"

    # Backups
    if "_stray_backup" in rel_low:
        return "I DUPLICATE_COPY"

    # Binaries
    if "extracted_native_libs" in rel_low or "dex_files" in rel_low:
        return "E NATIVE_BINARY_EXTRACT"

    # Smali
    if "apktool" in rel_low or "smali" in rel_low:
        return "D SMALI_DECOMPILE"

    # Decompile Java
    if "jadx" in rel_low:
        return "C DECOMPILED_JAVA_KOTLIN_SOURCE"

    # Assets
    if "material" in rel_low or "beard_assets" in rel_low or "ảnh" in rel_low or "extracted_assets" in rel_low or "demo data" in rel_low or "yeucau" in rel_low:
        return "G ASSET_RESOURCE_EXTRACT"

    # Reverse outputs
    if "redesign" in rel_low or "report" in rel_low or "verification" in rel_low or "bao cao" in rel_low:
        return "F NATIVE_PSEUDOCODE_OR_REVERSE_OUTPUT"

    # Build outputs / scratch
    if ".ktcheck" in rel_low or ".tmpdex" in rel_low or "ui screen short" in rel_low:
        return "H BUILD_OUTPUT_OR_CACHE"

    if "source" in rel_low:
        return "C DECOMPILED_JAVA_KOTLIN_SOURCE"

    return "L UNKNOWN_NEEDS_REVIEW"

def score_directory(rel_str: str, classification: str, markers: list, ext_counts: Counter, path: Path):
    rel_low = rel_str.lower().replace("/", "\\")
    
    # Defaults
    src_score = 0
    hair_score = 0
    jni_score = 0
    confidence = "HIGH"

    # High-value native bridge & hair modules
    if "native-bridge" in rel_low:
        src_score = 5
        hair_score = 5
        jni_score = 5
        return src_score, hair_score, jni_score, confidence

    if "lib-core-graphics" in rel_low:
        src_score = 5
        hair_score = 5
        jni_score = 5
        return src_score, hair_score, jni_score, confidence

    if "feature\\beauty" in rel_low:
        src_score = 5
        hair_score = 5
        jni_score = 4
        return src_score, hair_score, jni_score, confidence

    if "feature-ai-retouch" in rel_low:
        src_score = 5
        hair_score = 4
        jni_score = 4
        return src_score, hair_score, jni_score, confidence

    if "lib-photo-editor" in rel_low:
        src_score = 4
        hair_score = 4
        jni_score = 4
        return src_score, hair_score, jni_score, confidence

    if "core\\render" in rel_low:
        src_score = 4
        hair_score = 3
        jni_score = 4
        return src_score, hair_score, jni_score, confidence

    if "apps\\android" in rel_low:
        src_score = 5
        hair_score = 4
        jni_score = 5
        return src_score, hair_score, jni_score, confidence

    if "extracted_native_libs" in rel_low:
        src_score = 4
        hair_score = 5
        jni_score = 5
        return src_score, hair_score, jni_score, confidence

    if "jadx" in rel_low:
        src_score = 4
        hair_score = 4
        jni_score = 4
        return src_score, hair_score, jni_score, confidence

    if "material" in rel_low or "beard_assets" in rel_low:
        src_score = 2
        hair_score = 3
        jni_score = 1
        return src_score, hair_score, jni_score, confidence

    if "_stray_backup" in rel_low:
        src_score = 3
        hair_score = 1
        jni_score = 1
        return src_score, hair_score, jni_score, confidence

    if "tools" in rel_low:
        src_score = 1
        hair_score = 0
        jni_score = 0
        return src_score, hair_score, jni_score, confidence

    if "convert2" in rel_low:
        src_score = 5
        hair_score = 5
        jni_score = 5
        return src_score, hair_score, jni_score, confidence

    if "convert" in rel_low:
        src_score = 4
        hair_score = 3
        jni_score = 3
        return src_score, hair_score, jni_score, confidence

    if "source" in rel_low:
        src_score = 3
        hair_score = 3
        jni_score = 3
        return src_score, hair_score, jni_score, confidence

    return 2, 1, 1, "MEDIUM"

print("Scanner engine components compiled.")
