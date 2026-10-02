# -*- coding: utf-8 -*-
"""
04_SCRIPT_HO_TRO_CONVERT_TU_DONG.py
Script công cụ hỗ trợ đọc file Java dịch ngược từ jadx_src và sinh khung Kotlin sạch
kèm header truy vết nguồn gốc, tự động khử synthetic rác.
"""
import os
import sys
import re

def convert_java_file_to_kotlin_stub(java_file_path, output_dir):
    if not os.path.exists(java_file_path):
        print(f"Error: {java_file_path} not found.")
        return

    with open(java_file_path, 'r', encoding='utf-8', errors='replace') as fp:
        lines = fp.readlines()

    # Bỏ qua nếu là class annotation processor sinh
    fname = os.path.basename(java_file_path)
    if any(ig in fname for ig in ["_Factory", "_MembersInjector", "$sam$", "$$ExternalSynthetic"]):
        print(f"Ignored synthetic class: {fname}")
        return

    pkg = ""
    class_def = ""
    for line in lines:
        if line.startswith("package "):
            pkg = line.strip()
        if "public class " in line or "public final class " in line or "public interface " in line:
            class_def = line.strip().replace("{", "")
            break

    rel_source = os.path.relpath(java_file_path, r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE").replace("\\", "/")
    
    kt_content = f"""// ============================================================================
// CONVERTED SOURCE FILE
// Source: {rel_source}
// Target Project: Meitu Reborn (CONVERT2)
// ============================================================================
{pkg}

// TODO: Thân hàm đang được refactor sang Clean Idiomatic Kotlin
{class_def} {{
    // Converted properties & methods will be populated here
}}
"""
    out_file = os.path.join(output_dir, fname.replace(".java", ".kt"))
    os.makedirs(output_dir, exist_ok=True)
    with open(out_file, 'w', encoding='utf-8') as fp:
        fp.write(kt_content)
    print(f"Generated Kotlin scaffold: {out_file}")

if __name__ == "__main__":
    if len(sys.argv) > 2:
        convert_java_file_to_kotlin_stub(sys.argv[1], sys.argv[2])
    else:
        print("Usage: python 04_SCRIPT_HO_TRO_CONVERT_TU_DONG.py <java_file_path> <output_dir>")
