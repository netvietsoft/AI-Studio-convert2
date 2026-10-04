import os
import sys
import json
import re

JADX_SRC_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src\sources"

def build_java_native_index():
    print("Indexing Java classes with native methods...")
    java_index = {} # class_name -> list of native methods
    
    # Regex to find native methods: native <ret> <name>(<args>);
    re_native = re.compile(r"native\s+([a-zA-Z0-9_<>\[\],\s]+?)\s+([a-zA-Z0-9_]+)\s*\(([^)]*)\)\s*;")
    re_pkg = re.compile(r"package\s+([a-zA-Z0-9_.]+)\s*;")

    count = 0
    for root, dirs, files in os.walk(JADX_SRC_DIR):
        for f in files:
            if f.endswith(".java"):
                fpath = os.path.join(root, f)
                try:
                    with open(fpath, "r", encoding="utf-8", errors="ignore") as fp:
                        content = fp.read()
                        if "native " in content:
                            pkg_m = re_pkg.search(content)
                            pkg = pkg_m.group(1) if pkg_m else ""
                            cls_name = f[:-5]
                            full_cls = f"{pkg}.{cls_name}" if pkg else cls_name
                            
                            methods = []
                            for m in re_native.finditer(content):
                                ret, mname, args = m.groups()
                                methods.append({
                                    "name": mname,
                                    "return": ret.strip(),
                                    "args": args.strip()
                                })
                            if methods:
                                java_index[full_cls] = {
                                    "path": os.path.relpath(fpath, JADX_SRC_DIR),
                                    "methods": methods,
                                    "method_names": set(m["name"] for m in methods)
                                }
                                count += 1
                except:
                    pass
    print(f"Indexed {count} Java classes declaring native methods.")
    return java_index

def match_tables_to_java(tables, java_index):
    print("Matching RegisterNatives tables to Java classes...")
    matched = 0
    for t in tables:
        t_methods = set(m["name"] for m in t["methods"])
        best_cls = None
        best_score = 0
        
        for cls_name, cinfo in java_index.items():
            common = t_methods.intersection(cinfo["method_names"])
            if len(common) > 0:
                # Score based on Jaccard similarity and size
                score = len(common) / len(t_methods)
                if score > best_score:
                    best_score = score
                    best_cls = cls_name
        
        if best_cls and best_score >= 0.5:
            t["matched_java_class"] = best_cls
            t["matched_java_file"] = java_index[best_cls]["path"]
            t["match_confidence"] = f"{best_score*100:.1f}%"
            matched += 1
        else:
            t["matched_java_class"] = "UNRESOLVED_DYNAMIC"
            t["matched_java_file"] = "N/A"
            t["match_confidence"] = "0%"

    print(f"Matched {matched} out of {len(tables)} tables to Java classes.")

def main():
    java_index = build_java_native_index()
    
    with open(r"scratch\task038_recon\recovered_register_natives.json", "r", encoding="utf-8") as fp:
        tables = json.load(fp)
        
    match_tables_to_java(tables, java_index)
    
    with open(r"scratch\task038_recon\tables_with_java_classes.json", "w", encoding="utf-8") as fp:
        json.dump(tables, fp, indent=2)
        
    # Also save java_index summary
    summary = {cls: {"path": v["path"], "count": len(v["methods"]), "methods": [m["name"] for m in v["methods"]]} for cls, v in java_index.items()}
    with open(r"scratch\task038_recon\java_native_classes.json", "w", encoding="utf-8") as fp:
        json.dump(summary, fp, indent=2)

if __name__ == "__main__":
    main()
