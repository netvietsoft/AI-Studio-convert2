#!/usr/bin/env python3
"""
TASK_040 Full Discovery Execution Script
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

# Candidate directory definitions
# We systematically identify every significant directory under F:\CONVERT
CANDIDATE_PATHS = [
    # Top-level root
    ROOT,
    
    # 1. com.lightricks.facetune.free family
    ROOT / "com.lightricks.facetune.free",
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

    # 2. com.mt.mtxx.mtxx family - CONVERT (V1 Monorepo)
    ROOT / "com.mt.mtxx.mtxx",
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

    # 3. com.mt.mtxx.mtxx family - CONVERT2 (Current Workspace)
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

    # 4. com.mt.mtxx.mtxx family - SOURCE (Decompiled & Native Extract)
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

    # 5. Other under com.mt.mtxx.mtxx
    ROOT / "com.mt.mtxx.mtxx" / "_stray_backup_w9",
    ROOT / "com.mt.mtxx.mtxx" / "_stray_backup_w9" / "apps" / "android" / "feature" / "community",
    ROOT / "com.mt.mtxx.mtxx" / "Yeucau",
    ROOT / "com.mt.mtxx.mtxx" / "ẢNH",
    ROOT / "com.mt.mtxx.mtxx" / "beard_assets_10_png",
    ROOT / "com.mt.mtxx.mtxx" / ".vscode",

    # 6. Material Image Editor family
    ROOT / "Material Image Editor",
    ROOT / "Material Image Editor" / "Mitu",
    ROOT / "Material Image Editor" / "Mitu" / "material",

    # 7. tools family
    ROOT / "tools",
    ROOT / "tools" / "docker",
    ROOT / "tools" / "minio",
]

# Classification logic helper
def classify_dir(rel_str: str, path: Path, markers: list, ext_counts: Counter) -> str:
    # A ORIGINAL_SOURCE_PROJECT
    # B RECONSTRUCTED_CONVERT2_SOURCE
    # C DECOMPILED_JAVA_KOTLIN_SOURCE
    # D SMALI_DECOMPILE
    # E NATIVE_BINARY_EXTRACT
    # F NATIVE_PSEUDOCODE_OR_REVERSE_OUTPUT
    # G ASSET_RESOURCE_EXTRACT
    # H BUILD_OUTPUT_OR_CACHE
    # I DUPLICATE_COPY
    # J TOOL_WORKSPACE
    # K ARCHIVE/BACKUP
    # L UNKNOWN_NEEDS_REVIEW

    p_lower = str(path).lower()
    if "convert2" in rel_str.lower():
        if "gallery" in rel_str.lower():
            return "G ASSET_RESOURCE_EXTRACT"
        if "validation" in rel_str.lower():
            return "H BUILD_OUTPUT_OR_CACHE"
        return "B RECONSTRUCTED_CONVERT2_SOURCE"
    
    if "tools" in rel_str.lower() and ("docker" in rel_str.lower() or "minio" in rel_str.lower() or rel_str.lower() == "tools"):
        return "J TOOL_WORKSPACE"

    if "_stray_backup" in rel_str.lower():
        return "I DUPLICATE_COPY"

    if "extracted_native_libs" in rel_str.lower():
        return "E NATIVE_BINARY_EXTRACT"

    if "apktool_out" in rel_str.lower() or "smali" in rel_str.lower():
        return "D SMALI_DECOMPILE"

    if "jadx" in rel_str.lower():
        return "C DECOMPILED_JAVA_KOTLIN_SOURCE"

    if "extracted_assets" in rel_str.lower() or "material" in rel_str.lower() or "beard_assets" in rel_str.lower() or "ảnh" in rel_str.lower():
        return "G ASSET_RESOURCE_EXTRACT"

    if "dex_files" in rel_str.lower():
        return "E NATIVE_BINARY_EXTRACT"

    if "redesign" in rel_str.lower() or "report" in rel_str.lower() or "verification" in rel_str.lower() or "bao cao" in rel_str.lower():
        return "F NATIVE_PSEUDOCODE_OR_REVERSE_OUTPUT"

    if ".ktcheck" in rel_str.lower() or ".tmpdex" in rel_str.lower() or "cache" in rel_str.lower():
        return "H BUILD_OUTPUT_OR_CACHE"

    if "yeucau" in rel_str.lower() or "demo data" in rel_str.lower():
        return "G ASSET_RESOURCE_EXTRACT"

    if "com.lightricks.facetune.free\\convert" in rel_str.lower() or "com.mt.mtxx.mtxx\\convert" in rel_str.lower():
        return "B RECONSTRUCTED_CONVERT2_SOURCE"

    if "source" in rel_str.lower():
        return "C DECOMPILED_JAVA_KOTLIN_SOURCE"

    return "L UNKNOWN_NEEDS_REVIEW"

print("Candidate list initialized. Count:", len(CANDIDATE_PATHS))
