#!/usr/bin/env python3
"""
TASK_038 - Forensic Module 2: Complete JNI Bridge Extraction (Direct & Dynamic)
Governing Standard: 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD & Development Workspace Standard V2.1
Authority: Chairman Tony
"""

import os
import sys
import struct
import csv
import re
from elftools.elf.elffile import ELFFile

SIBLING_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a"
JADX_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src"

def demangle_jni_name(sym):
    # Java_com_meitu_core_MTFilterKernelConfigJNI_nInit
    # Special character escapes:
    # _1 -> _
    # _2 -> ;
    # _3 -> [
    # _0XXXX -> unicode
    if not sym.startswith("Java_"):
        return None, None, None
    parts = sym[5:].split("__")
    sig_suffix = None
    if len(parts) > 1:
        sig_suffix = parts[1]
    main_part = parts[0]
    
    tokens = main_part.split("_")
    # Replace escapes
    clean_tokens = []
    i = 0
    while i < len(tokens):
        t = tokens[i]
        t = t.replace("_1", "_").replace("_2", ";").replace("_3", "[")
        clean_tokens.append(t)
        i += 1
        
    if len(clean_tokens) >= 2:
        method = clean_tokens[-1]
        cls_name = ".".join(clean_tokens[:-1])
        return cls_name, method, sig_suffix
    elif len(clean_tokens) == 1:
        return "UnknownClass", clean_tokens[0], sig_suffix
    return "UnknownClass", sym, sig_suffix

def read_cstring(mem, addr, max_len=256):
    for vstart, (vend, b) in mem.items():
        if vstart <= addr < vend:
            off = addr - vstart
            end = b.find(b'\x00', off)
            if end == -1 or end - off > max_len or end == off:
                return None
            try:
                s = b[off:end].decode('utf-8', errors='ignore')
                if s.isprintable() and len(s) > 0:
                    return s
            except Exception:
                pass
    return None

def parse_jvm_signature(sig):
    # Returns (params_str, ret_str, input_types, output_types)
    if not (sig.startswith("(") and ")" in sig):
        return sig, "void", "UNKNOWN", "UNKNOWN"
    param_part = sig[1:sig.index(")")]
    ret_part = sig[sig.index(")") + 1:]
    
    type_map = {
        'V': 'void', 'Z': 'boolean', 'B': 'byte', 'C': 'char',
        'S': 'short', 'I': 'int', 'J': 'long', 'F': 'float', 'D': 'double'
    }
    
    def decode_types(s):
        types = []
        i = 0
        while i < len(s):
            if s[i] in type_map:
                types.append(type_map[s[i]])
                i += 1
            elif s[i] == '[':
                # array
                dim = 1
                i += 1
                while i < len(s) and s[i] == '[':
                    dim += 1
                    i += 1
                if i < len(s) and s[i] in type_map:
                    types.append(type_map[s[i]] + "[]" * dim)
                    i += 1
                elif i < len(s) and s[i] == 'L':
                    end = s.find(';', i)
                    if end != -1:
                        cls = s[i+1:end].replace('/', '.')
                        types.append(cls + "[]" * dim)
                        i = end + 1
                    else:
                        break
            elif s[i] == 'L':
                end = s.find(';', i)
                if end != -1:
                    cls = s[i+1:end].replace('/', '.')
                    types.append(cls)
                    i = end + 1
                else:
                    break
            else:
                i += 1
        return types

    in_types = decode_types(param_part)
    out_types = decode_types(ret_part)
    return in_types, out_types

def extract_jni_for_library(so_name, filepath):
    direct_methods = []
    dynamic_methods = []
    tables = {}
    has_jni_onload = False
    
    try:
        with open(filepath, "rb") as f:
            elf = ELFFile(f)
            
            # Check dynamic symbols
            dynsym = elf.get_section_by_name('.dynsym')
            if dynsym:
                for s in dynsym.iter_symbols():
                    name = s.name
                    if name.startswith('Java_'):
                        cls_name, method, sig_suffix = demangle_jni_name(name)
                        rva = s['st_value']
                        size = s['st_size']
                        direct_methods.append({
                            "symbol": name,
                            "class": cls_name,
                            "method": method,
                            "sig_suffix": sig_suffix or "",
                            "rva": hex(rva),
                            "size": size,
                            "library": so_name
                        })
                    elif name == 'JNI_OnLoad':
                        has_jni_onload = True
                        
            # Check dynamic registration
            text_sec = elf.get_section_by_name('.text')
            if text_sec:
                text_start = text_sec.header['sh_addr']
                text_end = text_start + text_sec.header['sh_size']
                
                # Load segments
                mem = {}
                for seg in elf.iter_segments():
                    if seg.header['p_type'] == 'PT_LOAD':
                        vaddr = seg.header['p_vaddr']
                        mem[vaddr] = [vaddr + seg.header['p_memsz'], bytearray(seg.data())]
                        if seg.header['p_memsz'] > len(mem[vaddr][1]):
                            mem[vaddr][1].extend(b'\x00' * (seg.header['p_memsz'] - len(mem[vaddr][1])))
                            
                # Apply R_AARCH64_RELATIVE relocations
                rela_dyn = elf.get_section_by_name('.rela.dyn')
                if rela_dyn:
                    for rel in rela_dyn.iter_relocations():
                        if rel['r_info_type'] == 1027:
                            offset = rel['r_offset']
                            addend = rel['r_addend']
                            for vstart, (vend, b) in mem.items():
                                if vstart <= offset < vend:
                                    off = offset - vstart
                                    b[off:off+8] = struct.pack('<Q', addend)
                                    
                # Find JNINativeMethod tables
                for vstart, (vend, b) in mem.items():
                    if vstart == text_start:
                        continue
                    off = 0
                    current_table_start = None
                    current_table_entries = []
                    while off <= len(b) - 24:
                        name_p, sig_p, fn_p = struct.unpack('<QQQ', b[off:off+24])
                        if text_start <= fn_p < text_end:
                            name_s = read_cstring(mem, name_p)
                            sig_s = read_cstring(mem, sig_p)
                            if name_s and sig_s and sig_s.startswith('(') and ')' in sig_s and len(name_s) < 64:
                                if all(c.isalnum() or c == '_' or c == '$' for c in name_s):
                                    if not current_table_entries:
                                        current_table_start = vstart + off
                                    entry = {
                                        "table_va": hex(vstart + off),
                                        "name": name_s,
                                        "signature": sig_s,
                                        "fn_rva": hex(fn_p),
                                        "library": so_name
                                    }
                                    current_table_entries.append(entry)
                                    dynamic_methods.append(entry)
                                    off += 24
                                    continue
                        if current_table_entries:
                            tables[hex(current_table_start)] = current_table_entries
                            current_table_entries = []
                            current_table_start = None
                        off += 8
                    if current_table_entries:
                        tables[hex(current_table_start)] = current_table_entries
    except Exception as e:
        print(f"  [WARN] Exception extracting JNI from {so_name}: {e}")
        
    return direct_methods, dynamic_methods, tables, has_jni_onload

def main():
    print("[JNI-EXTRACT] Starting exhaustive JNI extraction across all 45 libraries...")
    so_files = sorted([f for f in os.listdir(SIBLING_DIR) if f.endswith(".so")])
    
    all_direct = []
    all_dynamic = []
    all_tables_by_lib = {}
    onload_libs = []
    
    for idx, fname in enumerate(so_files, 1):
        fpath = os.path.join(SIBLING_DIR, fname)
        direct, dynamic, tables, has_onload = extract_jni_for_library(fname, fpath)
        all_direct.extend(direct)
        all_dynamic.extend(dynamic)
        if tables:
            all_tables_by_lib[fname] = tables
        if has_onload:
            onload_libs.append(fname)
        print(f"  [{idx:02d}/45] {fname:28s} | JNI_OnLoad: {str(has_onload):5s} | Direct: {len(direct):4d} | Dynamic: {len(dynamic):4d} in {len(tables)} tables")
        
    print(f"\n[JNI-EXTRACT] SUMMARY:")
    print(f"  Total Direct JNI Exports: {len(all_direct)}")
    print(f"  Total Dynamic JNI Registrations: {len(all_dynamic)}")
    print(f"  Total JNI Bridges: {len(all_direct) + len(all_dynamic)}")
    print(f"  Libraries with JNI_OnLoad: {len(onload_libs)}")
    print(f"  Libraries with JNINativeMethod tables: {len(all_tables_by_lib)}")

if __name__ == "__main__":
    main()
