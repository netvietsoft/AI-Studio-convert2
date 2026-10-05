#!/usr/bin/env python3
"""
Hybrid SO45 deep-scan planner.

Purpose:
- Reuse TASK_038 function inventory instead of rescanning/decompiling everything.
- Score functions for selective deep analysis.
- Produce deterministic HIGH/MEDIUM/LOW queues and per-library Ghidra-headless plans.
- Detect Ghidra headless if installed, but do not require it for the fast path.

This script is analysis-only. It never modifies source binaries.
"""
from __future__ import annotations
import argparse, csv, json, os, shutil
from collections import Counter, defaultdict
from pathlib import Path

DEFAULT_INV = Path(".ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION/03_ALL_FUNCTION_INVENTORY.csv")
DEFAULT_OUT = Path(".ai/reports/TASK_059_TASK058_EVIDENCE_TRUTH_AND_SO45_DEEP_PROVENANCE_CORRECTION/hybrid_deep_scan")
KEYWORDS = {
    "hair": 35, "matting": 35, "segment": 32, "trimap": 32,
    "shader": 28, "texture": 22, "fbo": 24, "render": 18, "glsl": 30,
    "color": 22, "lut": 28, "blend": 24, "hsv": 24, "rgb": 16,
    "warp": 28, "mesh": 25, "reshape": 30, "beauty": 24, "skin": 24,
    "mask": 24, "blur": 18, "sharpen": 22, "filter": 14, "tensor": 26,
}
FOCUS_LIBS = {
    "libMTFilterKernel.so", "libLayerFlow.so", "libManis.so",
    "libPVGColorFunctions.so", "libPVGImageCodec.so",
    "libARKernelInterface.so", "libarkernel3.so",
}

def truthy(v: str) -> bool:
    return str(v).strip().lower() in {"1","true","yes","y"}

def as_int(v, default=0):
    try: return int(str(v).strip() or default)
    except Exception: return default

def score(row):
    score = 0
    reasons = []
    blob = " ".join(str(row.get(k,"")) for k in (
        "RECOVERED_NAME","ORIGINAL_SYMBOL_IF_ANY","STRING_XREFS",
        "SEMANTIC_LABEL","IMPORTED_APIS","NOTES")).lower()
    for key, weight in KEYWORDS.items():
        if key in blob:
            score += weight
            reasons.append(key)
    if truthy(row.get("JNI_DIRECT_EXPORT","")):
        score += 30; reasons.append("jni")
    if truthy(row.get("REGISTER_NATIVES_TARGET","")):
        score += 35; reasons.append("register_natives")
    if row.get("LIBRARY","") in FOCUS_LIBS:
        score += 18; reasons.append("focus_lib")
    status = row.get("DECOMPILE_STATUS","").upper()
    conf = row.get("CONFIDENCE","").upper()
    if status not in {"SUCCESS","LOCAL_CFG_RECOVERED"}:
        score += 30; reasons.append("unresolved")
    if conf in {"HYPOTHESIS","UNKNOWN",""}:
        score += 25; reasons.append("low_confidence")
    degree = as_int(row.get("CALLER_COUNT")) + as_int(row.get("CALLEE_COUNT"))
    if degree >= 20: score += 18; reasons.append("graph_hub")
    elif degree >= 8: score += 10; reasons.append("graph_connected")
    if truthy(row.get("EXPORT","")):
        score += 8; reasons.append("export")
    return score, sorted(set(reasons))

def tier(n):
    if n >= 70: return "HIGH"
    if n >= 40: return "MEDIUM"
    return "LOW"

def find_ghidra_headless():
    env = os.environ.get("GHIDRA_HOME")
    candidates = []
    if env:
        candidates += [Path(env)/"support"/"analyzeHeadless.bat", Path(env)/"support"/"analyzeHeadless"]
    for root in (Path("C:/"), Path("D:/")):
        try:
            for p in root.glob("ghidra*"):
                candidates += [p/"support"/"analyzeHeadless.bat", p/"support"/"analyzeHeadless"]
        except OSError:
            pass
    for name in ("analyzeHeadless.bat","analyzeHeadless"):
        hit = shutil.which(name)
        if hit: candidates.append(Path(hit))
    for p in candidates:
        if p.exists(): return str(p)
    return None

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--inventory", type=Path, default=DEFAULT_INV)
    ap.add_argument("--out", type=Path, default=DEFAULT_OUT)
    ap.add_argument("--max-high", type=int, default=5000)
    ap.add_argument("--max-medium", type=int, default=10000)
    args = ap.parse_args()
    if not args.inventory.exists():
        raise SystemExit(f"inventory not found: {args.inventory}")
    args.out.mkdir(parents=True, exist_ok=True)

    selected = []
    counts = Counter()
    per_lib = defaultdict(list)
    with args.inventory.open("r", encoding="utf-8-sig", newline="") as f:
        for row in csv.DictReader(f):
            n, reasons = score(row)
            t = tier(n)
            counts[t] += 1
            item = {
                "tier": t, "score": n, "library": row.get("LIBRARY",""),
                "function_id": row.get("FUNCTION_ID",""), "rva": row.get("RVA",""),
                "recovered_name": row.get("RECOVERED_NAME",""),
                "decompile_status": row.get("DECOMPILE_STATUS",""),
                "confidence": row.get("CONFIDENCE",""),
                "reasons": ";".join(reasons),
            }
            if t != "LOW":
                selected.append(item)

    selected.sort(key=lambda x: (-x["score"], x["library"], x["rva"]))
    high = [x for x in selected if x["tier"]=="HIGH"][:args.max_high]
    medium = [x for x in selected if x["tier"]=="MEDIUM"][:args.max_medium]
    deep = high + medium
    for x in deep: per_lib[x["library"]].append(x)

    fields = ["tier","score","library","function_id","rva","recovered_name","decompile_status","confidence","reasons"]
    with (args.out/"priority_queue.csv").open("w", encoding="utf-8", newline="") as f:
        w=csv.DictWriter(f, fieldnames=fields); w.writeheader(); w.writerows(deep)
    plan_dir=args.out/"ghidra_plan"; plan_dir.mkdir(exist_ok=True)
    for lib, items in sorted(per_lib.items()):
        safe=lib.replace("/","_").replace("\\","_")
        with (plan_dir/f"{safe}.csv").open("w", encoding="utf-8", newline="") as f:
            w=csv.DictWriter(f, fieldnames=fields); w.writeheader(); w.writerows(items)

    ghidra=find_ghidra_headless()
    manifest={
        "inventory": str(args.inventory), "output": str(args.out),
        "tier_counts_full_inventory": dict(counts),
        "selected_high": len(high), "selected_medium": len(medium),
        "selected_total": len(deep), "libraries_selected": len(per_lib),
        "ghidra_headless": ghidra,
        "strategy": "TASK038_CACHE -> PRIORITY_SCORE -> SELECTIVE_DEEP_SCAN -> OPTIONAL_GHIDRA_HEADLESS -> IMAGE_EFFECT_GRAPH",
        "rule": "Ghidra is selective microscope, not brute-force census. Existing TASK_038 evidence is cache.",
    }
    (args.out/"manifest.json").write_text(json.dumps(manifest,indent=2),encoding="utf-8")
    print(json.dumps(manifest,indent=2))
    if not ghidra:
        print("[INFO] Ghidra headless not detected. Fast LLVM/Capstone path remains valid; HIGH queue is ready for later selective Ghidra analysis.")

if __name__=="__main__":
    main()
