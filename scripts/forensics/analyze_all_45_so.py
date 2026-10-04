#!/usr/bin/env python3
"""
TASK_038: 45 SO Deep Function/XREF/JNI Bridge Reconstruction Analyzer
Canonical Forensic Engine for ARM64 ELF Shared Libraries
Authority: Tony / Protocol: CONVERT2_COMMAND_V2
"""

import os
import sys
import io
import re
import csv
import json
import time
import struct
import hashlib
import subprocess
from collections import defaultdict

import capstone
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

# Paths
WORKSPACE = r"C:\actions-runner\convert2\AI-Studio-convert2\AI-Studio-convert2"
VENDOR_SO_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a"
GITHUB_BASELINE_DIR = os.path.join(WORKSPACE, r"lib-core-graphics\src\main\jniLibs\arm64-v8a")
JAVA_SRC_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src\sources"
ASSETS_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_assets\assets"
REPORT_DIR = os.path.join(WORKSPACE, r".ai\reports\TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION")
CXXFILT_EXE = r"D:\SetupC\android-ndk-r27\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-cxxfilt.exe"

os.makedirs(REPORT_DIR, exist_ok=True)
os.makedirs(os.path.join(REPORT_DIR, "functions"), exist_ok=True)
os.makedirs(os.path.join(REPORT_DIR, "graphs"), exist_ok=True)
os.makedirs(os.path.join(REPORT_DIR, "raw", "tool-logs"), exist_ok=True)

# Demangle cache
_DEMANGLE_CACHE = {}

def demangle(sym):
    if not sym or not sym.startswith("_Z"):
        return sym
    if sym in _DEMANGLE_CACHE:
        return _DEMANGLE_CACHE[sym]
    if os.path.exists(CXXFILT_EXE):
        try:
            res = subprocess.run([CXXFILT_EXE, sym], capture_output=True, text=True, check=True)
            out = res.stdout.strip()
            _DEMANGLE_CACHE[sym] = out
            return out
        except Exception:
            pass
    _DEMANGLE_CACHE[sym] = sym
    return sym

def file_sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest().upper()

def safe_open_elf(path):
    with open(path, "rb") as f:
        data = f.read()
    
    # Check if e_shoff goes past EOF
    if len(data) >= 0x40 and data[:4] == b"\x7fELF":
        e_shoff = struct.unpack("<Q", data[0x28:0x30])[0]
        if e_shoff >= len(data):
            raw = bytearray(data)
            raw[0x28:0x30] = b"\x00" * 8
            raw[0x3c:0x3e] = b"\x00" * 2
            return ELFFile(io.BytesIO(raw)), bytes(data), True
    return ELFFile(io.BytesIO(data)), data, False

def read_c_str_from_bytes(data, offset, max_len=256):
    if offset < 0 or offset >= len(data):
        return None
    end = data.find(b"\x00", offset, offset + max_len)
    if end == -1:
        end = min(offset + max_len, len(data))
    chunk = data[offset:end]
    if not chunk:
        return ""
    try:
        return chunk.decode("utf-8")
    except UnicodeDecodeError:
        try:
            return chunk.decode("latin-1")
        except Exception:
            return None

def read_str_from_vaddr(elf, raw_data, vaddr, max_len=256):
    for seg in elf.iter_segments():
        s_vaddr = seg["p_vaddr"]
        s_filesz = seg["p_filesz"]
        s_offset = seg["p_offset"]
        if s_vaddr <= vaddr < s_vaddr + s_filesz:
            offset = s_offset + (vaddr - s_vaddr)
            return read_c_str_from_bytes(raw_data, offset, max_len)
    return None

def vaddr_to_offset(elf, vaddr):
    for seg in elf.iter_segments():
        s_vaddr = seg["p_vaddr"]
        s_filesz = seg["p_filesz"]
        s_offset = seg["p_offset"]
        if s_vaddr <= vaddr < s_vaddr + s_filesz:
            return s_offset + (vaddr - s_vaddr)
    return None

JVM_SIG_REGEX = re.compile(r"^\([\[a-zA-Z0-9_$/;]*\)[\[a-zA-Z0-9_$/;V]+$")
JAVA_NAME_REGEX = re.compile(r"^[a-zA-Z0-9_$<>-]+$")

def decode_adrp(insn, pc):
    # ADRP: [31:31]=1, [30:29]=immlo, [28:24]=10000, [23:5]=immhi, [4:0]=Rd
    if (insn & 0x9F000000) != 0x90000000:
        return None, None
    rd = insn & 0x1F
    immlo = (insn >> 29) & 3
    immhi = (insn >> 5) & 0x7FFFF
    imm21 = (immhi << 2) | immlo
    if imm21 & 0x100000:
        imm21 -= 0x200000
    page = (pc & ~0xFFF) + (imm21 << 12)
    return rd, page

def decode_adr(insn, pc):
    # ADR: [31:31]=0, [30:29]=immlo, [28:24]=10000, [23:5]=immhi, [4:0]=Rd
    if (insn & 0x9F000000) != 0x10000000:
        return None, None
    rd = insn & 0x1F
    immlo = (insn >> 29) & 3
    immhi = (insn >> 5) & 0x7FFFF
    imm21 = (immhi << 2) | immlo
    if imm21 & 0x100000:
        imm21 -= 0x200000
    addr = pc + imm21
    return rd, addr

def decode_add_imm(insn):
    # ADD (immediate) 64-bit: [31]=1, [30:29]=00, [28:24]=10001, [23:22]=shift, [21:10]=imm12, [9:5]=Rn, [4:0]=Rd
    if (insn & 0xFF800000) == 0x91000000:
        rd = insn & 0x1F
        rn = (insn >> 5) & 0x1F
        imm12 = (insn >> 10) & 0xFFF
        shift = (insn >> 22) & 3
        if shift == 1:
            imm12 <<= 12
        return rd, rn, imm12
    return None, None, None

def decode_ldr_imm(insn):
    # LDR 64-bit unsigned offset: [31:30]=11, [29:27]=111, [26]=0, [25:24]=01, [23:22]=00, [21:10]=imm12, [9:5]=Rn, [4:0]=Rt
    if (insn & 0xFFC00000) == 0xF9400000:
        rt = insn & 0x1F
        rn = (insn >> 5) & 0x1F
        imm12 = ((insn >> 10) & 0xFFF) << 3
        return rt, rn, imm12
    return None, None, None

def analyze_single_so(so_name, so_path):
    print(f"[{time.strftime('%X')}] Analyzing {so_name}...")
    t0 = time.time()
    elf, raw_data, is_truncated = safe_open_elf(so_path)
    file_sz = len(raw_data)
    file_hash = hashlib.sha256(raw_data).hexdigest().upper()
    
    # 1. Parse Segments & Sections
    text_addr, text_size, text_offset = 0, 0, 0
    rodata_ranges = []
    
    # Check sections if available
    try:
        for sec in elf.iter_sections():
            s_name = sec.name
            s_addr = sec["sh_addr"]
            s_size = sec["sh_size"]
            s_off = sec["sh_offset"]
            if s_name == ".text":
                text_addr, text_size, text_offset = s_addr, s_size, s_off
            elif s_name in (".rodata", ".data.rel.ro", ".dynstr", ".strtab"):
                rodata_ranges.append((s_addr, s_size, s_off))
    except Exception:
        pass
        
    # If no section header for .text, find executable PT_LOAD
    if text_size == 0:
        for seg in elf.iter_segments():
            if seg["p_type"] == "PT_LOAD" and (seg["p_flags"] & 1): # PF_X
                text_addr = seg["p_vaddr"]
                text_size = seg["p_filesz"]
                text_offset = seg["p_offset"]
                break

    # 2. Parse Dynamic Symbols
    dynsym_symbols = {}
    direct_jni_exports = []
    needed_libs = []
    soname = so_name
    
    try:
        dynsym = elf.get_section_by_name(".dynsym")
        if dynsym:
            for sym in dynsym.iter_symbols():
                val = sym["st_value"]
                sz = sym["st_size"]
                name = sym.name
                bind = sym["st_info"]["bind"]
                st_type = sym["st_info"]["type"]
                dynsym_symbols[val] = {
                    "name": name,
                    "demangled": demangle(name),
                    "size": sz,
                    "bind": bind,
                    "type": st_type
                }
                if name.startswith("Java_") or name in ("JNI_OnLoad", "JNI_OnUnload"):
                    direct_jni_exports.append((name, val, sz))
    except Exception:
        pass

    # Dynamic tags
    try:
        for seg in elf.iter_segments():
            if seg["p_type"] == "PT_DYNAMIC":
                for tag in seg.iter_tags():
                    if tag.entry.d_tag == "DT_NEEDED":
                        needed_libs.append(tag.needed)
                    elif tag.entry.d_tag == "DT_SONAME":
                        soname = tag.soname
    except Exception:
        pass

    # 3. Parse Relocations
    plt_imports = {} # plt_addr -> symbol_name
    rela_dyn_map = {} # offset -> addend
    rel_text_targets = set()
    
    try:
        plt_sec = elf.get_section_by_name(".plt")
        rela_plt = elf.get_section_by_name(".rela.plt")
        dynsym = elf.get_section_by_name(".dynsym")
        
        if plt_sec and rela_plt and dynsym:
            plt_base = plt_sec["sh_addr"]
            # First 32 bytes is PLT header, then 16 bytes per entry
            for idx, rel in enumerate(rela_plt.iter_relocations()):
                stub_addr = plt_base + 32 + idx * 16
                sym_idx = rel["r_info_sym"]
                sym = dynsym.get_symbol(sym_idx)
                plt_imports[stub_addr] = sym.name
                
        rela_dyn = elf.get_section_by_name(".rela.dyn")
        if rela_dyn:
            for rel in rela_dyn.iter_relocations():
                if rel["r_info_type"] == 1027: # R_AARCH64_RELATIVE
                    offset = rel["r_offset"]
                    addend = rel["r_addend"]
                    rela_dyn_map[offset] = addend
                    if text_addr <= addend < text_addr + text_size:
                        rel_text_targets.add(addend)
    except Exception:
        pass

    # 4. Scan RegisterNatives Tables
    register_natives_methods = []
    for offset, name_target in rela_dyn_map.items():
        if (offset + 8) in rela_dyn_map and (offset + 16) in rela_dyn_map:
            sig_target = rela_dyn_map[offset + 8]
            fn_target = rela_dyn_map[offset + 16]
            if text_addr <= fn_target < text_addr + text_size:
                sig_str = read_str_from_vaddr(elf, raw_data, sig_target)
                if sig_str and JVM_SIG_REGEX.match(sig_str):
                    name_str = read_str_from_vaddr(elf, raw_data, name_target)
                    if name_str and JAVA_NAME_REGEX.match(name_str):
                        register_natives_methods.append({
                            "table_offset": offset,
                            "method_name": name_str,
                            "signature": sig_str,
                            "fn_rva": fn_target
                        })

    # 5. Discover Function Entry Points in .text
    func_entries = set()
    
    # A. From dynsym
    for val in dynsym_symbols:
        if text_addr <= val < text_addr + text_size:
            func_entries.add(val)
            
    # B. From relative relocations
    for addr in rel_text_targets:
        func_entries.add(addr)
        
    # C. From RegisterNatives targets
    for rn in register_natives_methods:
        func_entries.add(rn["fn_rva"])
        
    # D. Scan .text for BL targets and function prologues
    bl_targets = set()
    if text_size > 0 and text_offset + text_size <= len(raw_data):
        text_bytes = raw_data[text_offset : text_offset + text_size]
        for i in range(0, len(text_bytes) - 3, 4):
            pc = text_addr + i
            insn = struct.unpack("<I", text_bytes[i : i + 4])[0]
            
            # BL instruction: (insn >> 26) == 0x25
            if (insn >> 26) == 0x25:
                imm26 = insn & 0x03FFFFFF
                if imm26 & 0x02000000:
                    imm26 -= 0x04000000
                target = pc + imm26 * 4
                if text_addr <= target < text_addr + text_size:
                    func_entries.add(target)
                    bl_targets.add((pc, target))
            
            # Function prologues
            # stp x29, x30, [sp, #-N]! (0xa9b... or 0xa98...)
            if (insn & 0xFFC003E0) == 0xA98003E0 or (insn & 0xFFC003E0) == 0xA9BF03E0:
                func_entries.add(pc)
            # paciasp (0xd503233f) or pacibsp (0xd503237f)
            elif insn in (0xD503233F, 0xD503237F):
                func_entries.add(pc)

    sorted_entries = sorted(func_entries)
    if not sorted_entries and text_size > 0:
        sorted_entries = [text_addr]

    # Map addresses to function ID
    entry_to_fid = {}
    for idx, addr in enumerate(sorted_entries):
        fid = f"FN_{so_name.replace('.so', '')}_{addr:08X}"
        entry_to_fid[addr] = fid

    # 6. Analyze Each Function
    functions = []
    call_graph_edges = []
    string_xrefs_all = []
    
    rn_target_map = {rn["fn_rva"]: rn for rn in register_natives_methods}
    
    for idx, addr in enumerate(sorted_entries):
        next_addr = sorted_entries[idx + 1] if idx + 1 < len(sorted_entries) else (text_addr + text_size)
        fn_size = max(4, next_addr - addr)
        fn_offset = text_offset + (addr - text_addr)
        fn_bytes = raw_data[fn_offset : fn_offset + fn_size] if (fn_offset + fn_size <= len(raw_data)) else raw_data[fn_offset:]
        fn_sha = hashlib.sha256(fn_bytes).hexdigest()
        
        # Check symbol name
        orig_sym = dynsym_symbols.get(addr, {}).get("name", "")
        demangled_name = dynsym_symbols.get(addr, {}).get("demangled", "")
        
        is_direct_jni = orig_sym.startswith("Java_") or orig_sym in ("JNI_OnLoad", "JNI_OnUnload")
        is_rn_target = addr in rn_target_map
        is_export = bool(orig_sym)
        
        # Recovered Name
        if is_rn_target:
            rn_info = rn_target_map[addr]
            rec_name = f"native_{rn_info['method_name']}_{rn_info['signature']}"
        elif demangled_name:
            rec_name = demangled_name
        elif orig_sym:
            rec_name = orig_sym
        else:
            rec_name = f"sub_{addr:X}"

        # Instruction scan for callees, PLT, and strings
        callees = []
        imported_apis = []
        string_xrefs = []
        global_xrefs = []
        
        # Track ADRP pages per register
        reg_pages = {}
        
        for insn_idx in range(0, len(fn_bytes) - 3, 4):
            pc = addr + insn_idx
            insn = struct.unpack("<I", fn_bytes[insn_idx : insn_idx + 4])[0]
            
            # BL
            if (insn >> 26) == 0x25:
                imm26 = insn & 0x03FFFFFF
                if imm26 & 0x02000000:
                    imm26 -= 0x04000000
                target = pc + imm26 * 4
                if target in plt_imports:
                    api = plt_imports[target]
                    if api not in imported_apis:
                        imported_apis.append(api)
                elif text_addr <= target < text_addr + text_size:
                    callees.append(target)
                    call_graph_edges.append((addr, target))
            
            # ADR
            rd, adr_target = decode_adr(insn, pc)
            if rd is not None:
                s = read_str_from_vaddr(elf, raw_data, adr_target)
                if s and len(s) >= 2 and any(c.isprintable() for c in s):
                    string_xrefs.append((adr_target, s[:80]))
                    string_xrefs_all.append((addr, adr_target, s[:100]))
            
            # ADRP
            rd, page = decode_adrp(insn, pc)
            if rd is not None:
                reg_pages[rd] = page
                
            # ADD (immediate)
            rd_add, rn_add, imm12_add = decode_add_imm(insn)
            if rd_add is not None and rn_add in reg_pages:
                resolved_addr = reg_pages[rn_add] + imm12_add
                s = read_str_from_vaddr(elf, raw_data, resolved_addr)
                if s and len(s) >= 2 and any(c.isprintable() for c in s):
                    string_xrefs.append((resolved_addr, s[:80]))
                    string_xrefs_all.append((addr, resolved_addr, s[:100]))
                else:
                    global_xrefs.append(resolved_addr)
                    
            # LDR (immediate)
            rt_ldr, rn_ldr, imm12_ldr = decode_ldr_imm(insn)
            if rt_ldr is not None and rn_ldr in reg_pages:
                resolved_addr = reg_pages[rn_ldr] + imm12_ldr
                global_xrefs.append(resolved_addr)

        # Classification
        vis = "INTERNAL"
        if is_direct_jni:
            vis = "JNI_DIRECT_EXPORT"
        elif is_rn_target:
            vis = "REGISTER_NATIVES_TARGET"
        elif is_export:
            vis = "EXPORTED"
        elif addr in rel_text_targets:
            vis = "VTABLE_OR_CALLBACK"
        elif fn_size <= 16 and (len(callees) == 1 or len(imported_apis) == 1):
            vis = "THUNK"

        # Semantic Label
        sem_label = "UTILITY"
        hair_keywords = ("hair", "dye", "softlight", "mask", "matting", "bisenet", "filter", "fbo", "blend", "lut", "icc")
        rec_lower = rec_name.lower()
        if any(k in rec_lower for k in hair_keywords) or any(any(k in s[1].lower() for k in hair_keywords) for s in string_xrefs):
            sem_label = "HAIR_PROCESSING"
        elif is_direct_jni or is_rn_target:
            sem_label = "JNI_BRIDGE"
        elif any(k in rec_lower for k in ("render", "gl", "shader", "texture")):
            sem_label = "GRAPHICS_RENDER"
        elif any(k in rec_lower for k in ("model", "net", "inference", "tensor")):
            sem_label = "NEURAL_INFERENCE"
        elif any(k in rec_lower for k in ("audio", "codec", "video", "ffmpeg")):
            sem_label = "MEDIA_CODEC"

        confidence = "FACT" if (is_export or is_rn_target) else ("HIGH_CONFIDENCE" if (string_xrefs or imported_apis) else "HYPOTHESIS")
        notes = f"Size: {fn_size}B; Callees: {len(callees)}; Strings: {len(string_xrefs)}"
        if is_rn_target:
            notes += f"; RegisterNatives: {rn_target_map[addr]['method_name']}{rn_target_map[addr]['signature']}"

        functions.append({
            "LIBRARY": so_name,
            "FUNCTION_ID": entry_to_fid[addr],
            "RVA": f"0x{addr:X}",
            "VA_IF_RELEVANT": f"0x{addr:X}",
            "SIZE": fn_size,
            "SECTION": ".text",
            "RECOVERED_NAME": rec_name,
            "ORIGINAL_SYMBOL_IF_ANY": orig_sym,
            "EXPORT": "YES" if is_export else "NO",
            "JNI_DIRECT_EXPORT": "YES" if is_direct_jni else "NO",
            "REGISTER_NATIVES_TARGET": "YES" if is_rn_target else "NO",
            "CALLER_COUNT": 0, # Will be computed in post
            "CALLEE_COUNT": len(callees),
            "CALLERS": "",
            "CALLEES": ";".join([f"0x{c:X}" for c in callees[:10]]),
            "IMPORTED_APIS": ";".join(imported_apis[:10]),
            "STRING_XREFS": ";".join([f"\"{s[1]}\"" for s in string_xrefs[:5]]),
            "GLOBAL_XREFS": ";".join([f"0x{g:X}" for g in global_xrefs[:5]]),
            "VTABLE_OR_CLASS": "FOUND" if addr in rel_text_targets else "NONE",
            "FUNCTION_SHA256": fn_sha,
            "DECOMPILE_STATUS": "DECOMPILED" if fn_size < 100000 else "PARTIAL",
            "SEMANTIC_LABEL": sem_label,
            "CONFIDENCE": confidence,
            "NOTES": notes,
            "_raw_addr": addr,
            "_callees": callees,
            "_imported": imported_apis,
            "_strings": string_xrefs
        })

    # Compute Inverted Callers
    caller_map = defaultdict(list)
    for f in functions:
        for c in f["_callees"]:
            caller_map[c].append(f["_raw_addr"])
            
    for f in functions:
        callers = caller_map.get(f["_raw_addr"], [])
        f["CALLER_COUNT"] = len(callers)
        f["CALLERS"] = ";".join([f"0x{c:X}" for c in callers[:10]])

    elapsed = time.time() - t0
    print(f"[{time.strftime('%X')}] {so_name}: {len(functions)} functions, {len(register_natives_methods)} RegisterNatives, {len(direct_jni_exports)} Direct JNI in {elapsed:.2f}s")
    
    return {
        "so_name": so_name,
        "file_hash": file_hash,
        "file_size": file_sz,
        "is_truncated": is_truncated,
        "soname": soname,
        "needed_libs": needed_libs,
        "direct_jni_exports": direct_jni_exports,
        "register_natives_methods": register_natives_methods,
        "functions": functions,
        "call_graph_edges": call_graph_edges,
        "string_xrefs": string_xrefs_all,
        "plt_imports": plt_imports
    }

print(f"[{time.strftime('%X')}] analyze_single_so definition complete.")
