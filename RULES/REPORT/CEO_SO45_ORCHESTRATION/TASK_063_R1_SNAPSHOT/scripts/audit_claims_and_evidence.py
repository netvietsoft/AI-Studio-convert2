#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Auditing 5 Critical Claims across the 45 Native SO files:
1. Mask exclusion channel & output alpha (libMTFilterKernel.so / libarkernel3.so / shaders)
2. SoftLight formula (libPVGColorFunctions.so / libMTFilterKernel.so / shaders)
3. Blur sampling offsets & Gaussian weights (libMTFilterKernel.so)
4. Hair material config -> native ordering (libarkernel3.so / libMTFilterKernel.so)
5. Confidence & segmentation source (BiSeNet / NCNN / TFLite / MediaPipe)
"""

import os
import re
import json
import struct
import hashlib
from pathlib import Path

SO_DIR = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a")
REPORT_DIR = Path(r"RULES\REPORT\TASK_063_REPORT")
RAW_DIR = REPORT_DIR / "raw"

def get_strings(p: Path, min_len=4):
    with open(p, "rb") as f:
        data = f.read()
    # Extract ascii strings
    pattern = re.compile(b"[A-Za-z0-9_./\\-]{" + str(min_len).encode() + b",}")
    return [m.group(0).decode("ascii", "replace") for m in pattern.finditer(data)]

def check_claim_1_exclusion():
    """Claim 1: Mask exclusion channel + output alpha"""
    # Check libMTFilterKernel.so and libarkernel3.so for exclusion symbols/strings
    res = {}
    for lib_name in ["libMTFilterKernel.so", "libarkernel3.so", "libLayerFlow.so"]:
        p = SO_DIR / lib_name
        if not p.exists(): continue
        with open(p, "rb") as f: data = f.read()
        matches = []
        for term in [b"exclusion", b"mask_mix", b"HairMask", b"hair_mask", b"raw_hair", b"skin_mask", b"alpha"]:
            count = data.count(term)
            matches.append(f"{term.decode()}: {count}")
        res[lib_name] = matches
    return res

def check_claim_2_softlight():
    """Claim 2: SoftLight formula in binaries and shaders"""
    res = {}
    # Look for softlight string or shader routines
    for lib_name in ["libMTFilterKernel.so", "libPVGColorFunctions.so", "libVERenderer.so", "libfantasy.so"]:
        p = SO_DIR / lib_name
        if not p.exists(): continue
        with open(p, "rb") as f: data = f.read()
        matches = []
        for term in [b"SoftLight", b"softlight", b"soft_light", b"Pegtop", b"pegtop", b"blend_softlight", b"PsSoftLight"]:
            count = data.count(term)
            if count > 0:
                matches.append(f"{term.decode()}: {count}")
        res[lib_name] = matches
    return res

def check_claim_3_blur_weights():
    """Claim 3: Blur sampling offsets & 5-tap Gaussian kernel [0.159676, 0.263348, 0.122118, 0.030573, 0.004122]"""
    # Check if exact IEEE-754 floats exist in libMTFilterKernel.so
    p = SO_DIR / "libMTFilterKernel.so"
    weights = [0.159676, 0.263348, 0.122118, 0.030573, 0.004122]
    res = {"target_weights": weights}
    with open(p, "rb") as f: data = f.read()
    
    found_weights = {}
    for w in weights:
        b_single = struct.pack("<f", w)
        b_double = struct.pack("<d", w)
        count_single = data.count(b_single)
        count_double = data.count(b_double)
        found_weights[str(w)] = {"float_count": count_single, "double_count": count_double}
    res["weight_presence"] = found_weights
    return res

def check_claim_4_hair_material():
    """Claim 4: Hair material config -> native ordering"""
    res = {}
    for lib_name in ["libarkernel3.so", "libMTFilterKernel.so"]:
        p = SO_DIR / lib_name
        with open(p, "rb") as f: data = f.read()
        matches = []
        for term in [b"CMTFilterSoftHair", b"HairDye", b"hair_color", b"hairColor", b"specularParams", b"unsharpFactor"]:
            count = data.count(term)
            if count > 0:
                matches.append(f"{term.decode()}: {count}")
        res[lib_name] = matches
    return res

def check_claim_5_segmentation():
    """Claim 5: Confidence / segmentation source (BiSeNet vs MediaPipe vs NCNN vs Manis)"""
    res = {}
    for lib_name in ["libManis.so", "libmanis_npu_adapter.so", "libaidetectionplugin.so", "libAIModelKit.so"]:
        p = SO_DIR / lib_name
        with open(p, "rb") as f: data = f.read()
        matches = []
        for term in [b"bisenet", b"BiSeNet", b"hair_seg", b"segmentation", b"hair", b"Manis", b"ncnn", b"tflite"]:
            count = data.count(term)
            if count > 0:
                matches.append(f"{term.decode()}: {count}")
        res[lib_name] = matches
    return res

def main():
    RAW_DIR.mkdir(parents=True, exist_ok=True)
    audit = {
        "claim_1_exclusion": check_claim_1_exclusion(),
        "claim_2_softlight": check_claim_2_softlight(),
        "claim_3_blur_weights": check_claim_3_blur_weights(),
        "claim_4_hair_material": check_claim_4_hair_material(),
        "claim_5_segmentation": check_claim_5_segmentation()
    }
    with open(RAW_DIR / "critical_claim_raw_audit.json", "w", encoding="utf-8") as out:
        json.dump(audit, out, indent=2)
    print("Claim audit written to raw/critical_claim_raw_audit.json")
    print(json.dumps(audit, indent=2))

if __name__ == "__main__":
    main()
