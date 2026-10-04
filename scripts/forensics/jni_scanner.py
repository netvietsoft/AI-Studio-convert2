#!/usr/bin/env python3
"""
scripts/forensics/jni_scanner.py
JNI Bridge Reconstruction, RegisterNatives Recovery & Java/Kotlin Crosscheck
"""

import os
import re
import csv
import json
from collections import defaultdict

JAVA_TYPE_TO_JVM = {
    "void": "V",
    "boolean": "Z",
    "byte": "B",
    "char": "C",
    "short": "S",
    "int": "I",
    "long": "J",
    "float": "F",
    "double": "D",
    "String": "Ljava/lang/String;",
    "Object": "Ljava/lang/Object;",
    "Class": "Ljava/lang/Class;",
    "Bitmap": "Landroid/graphics/Bitmap;",
    "ByteBuffer": "Ljava/nio/ByteBuffer;",
    "Context": "Landroid/content/Context;",
    "boolean[]": "[Z",
    "byte[]": "[B",
    "char[]": "[C",
    "short[]": "[S",
    "int[]": "[I",
    "long[]": "[J",
    "float[]": "[F",
    "double[]": "[D",
    "String[]": "[Ljava/lang/String;",
    "Object[]": "[Ljava/lang/Object;",
    "byte[][]": "[[B",
    "int[][]": "[[I",
    "float[][]": "[[F"
}

def type_to_jvm(t):
    t = t.strip()
    # strip annotations
    t = re.sub(r"@\w+\s*", "", t).strip()
    if t in JAVA_TYPE_TO_JVM:
        return JAVA_TYPE_TO_JVM[t]
    if t.endswith("[]"):
        base = t[:-2].strip()
        return "[" + type_to_jvm(base)
    # Generic or custom class
    base = t.split("<")[0].strip()
    base_clean = base.replace(".", "/")
    return f"L{base_clean};"

def build_jvm_signature(param_str, ret_type):
    param_sig = ""
    if param_str and param_str.strip():
        # Split params handling generics or brackets
        params = [p.strip() for p in param_str.split(",") if p.strip()]
        for p in params:
            # Each param is like: "int i" or "final long j" or "@Nullable Bitmap bitmap"
            parts = p.split()
            # The type is the second to last or last depending on identifiers
            # Usually last item is param name, before is type
            if len(parts) >= 2:
                p_type = parts[-2]
                if p_type in ("final", "@NonNull", "@Nullable", "@Keep"):
                    p_type = parts[-1]
            else:
                p_type = parts[0]
            param_sig += type_to_jvm(p_type)
    ret_sig = type_to_jvm(ret_type)
    return f"({param_sig}){ret_sig}"

def decode_direct_jni_name(sym):
    # Java_com_meitu_core_MTFilterKernelConfigJNI_nInit
    if not sym.startswith("Java_"):
        return None, None, None
    parts = sym[5:].split("_")
    if len(parts) < 2:
        return None, None, None
    method_name = parts[-1]
    class_parts = parts[:-1]
    class_name = "/".join(class_parts)
    return class_name, method_name, sym

def scan_java_native_declarations(java_roots):
    print("Scanning Java/Kotlin source trees for native declarations...")
    native_methods = []
    class_to_so_map = defaultdict(set)
    
    native_regex = re.compile(
        r"(?:public|protected|private|static|final|synchronized|\s)*native\s+([a-zA-Z0-9_<>[\]@\s]+?)\s+([a-zA-Z0-9_$]+)\s*\(([^)]*)\)\s*;"
    )
    load_lib_regex = re.compile(r'(?:System|ReLinker)\.loadLibrary\s*\(\s*(?:[^,]+,\s*)?["\']([^"\']+)["\']\s*\)')
    package_regex = re.compile(r"^\s*package\s+([a-zA-Z0-9_.]+)\s*;", re.MULTILINE)
    class_regex = re.compile(r"(?:public|protected|private|final|abstract|\s)*class\s+([a-zA-Z0-9_$]+)")

    for root_dir in java_roots:
        if not os.path.exists(root_dir):
            continue
        for root, _, files in os.walk(root_dir):
            for file in files:
                if file.endswith((".java", ".kt")):
                    filepath = os.path.join(root, file)
                    try:
                        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
                            content = f.read()
                    except Exception:
                        continue
                        
                    if "native " not in content and "external " not in content:
                        continue
                        
                    pkg_match = package_regex.search(content)
                    pkg = pkg_match.group(1).replace(".", "/") if pkg_match else ""
                    
                    cls_match = class_regex.search(content)
                    cls_name = cls_match.group(1) if cls_match else file.replace(".java", "").replace(".kt", "")
                    full_cls = f"{pkg}/{cls_name}" if pkg else cls_name
                    
                    # Loaded libraries
                    for lib_match in load_lib_regex.finditer(content):
                        so_name = lib_match.group(1)
                        if not so_name.startswith("lib"):
                            so_name = f"lib{so_name}"
                        if not so_name.endswith(".so"):
                            so_name = f"{so_name}.so"
                        class_to_so_map[full_cls].add(so_name)

                    # Extract methods
                    for m in native_regex.finditer(content):
                        ret_type = m.group(1).strip()
                        m_name = m.group(2).strip()
                        params = m.group(3).strip()
                        jvm_sig = build_jvm_signature(params, ret_type)
                        
                        native_methods.append({
                            "CLASS": full_cls,
                            "METHOD": m_name,
                            "RAW_RETURN": ret_type,
                            "RAW_PARAMS": params,
                            "JVM_SIGNATURE": jvm_sig,
                            "SOURCE_FILE": filepath,
                            "LOADED_LIBS": ";".join(sorted(class_to_so_map[full_cls])) if class_to_so_map[full_cls] else "UNKNOWN"
                        })
                        
    print(f"Discovered {len(native_methods)} Java/Kotlin native method declarations across {len(class_to_so_map)} classes.")
    return native_methods, class_to_so_map
