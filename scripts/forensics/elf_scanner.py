#!/usr/bin/env python3
"""
scripts/forensics/elf_scanner.py
High-Performance ARM64 ELF Function Census, Disassembly & XREF Analyzer
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

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

CXXFILT_EXE = r"D:\SetupC\android-ndk-r27\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-cxxfilt.exe"

_DEMANGLE_CACHE = {}

def batch_demangle(symbols):
    mangled = [s for s in symbols if s and s.startswith("_Z")]
    to_resolve = [s for s in set(mangled) if s not in _DEMANGLE_CACHE]
    if to_resolve and os.path.exists(CXXFILT_EXE):
        try:
            proc = subprocess.Popen([CXXFILT_EXE], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
            out, _ = proc.communicate("\n".join(to_resolve))
            demangled_lines = out.strip().split("\n")
            for orig, dem in zip(to_resolve, demangled_lines):
                _DEMANGLE_CACHE[orig] = dem.strip()
        except Exception:
            pass
    return {s: _DEMANGLE_CACHE.get(s, s) for s in symbols}

def safe_open_elf(path):
    with open(path, "rb") as f:
        data = f.read()
    
    if len(data) >= 0x40 and data[:4] == b"\x7fELF":
        e_shoff = struct.unpack("<Q", data[0x28:0x30])[0]
        if e_shoff >= len(data):
            raw = bytearray(data)
            raw[0x28:0x30] = b"\x00" * 8
            raw[0x3c:0x3e] = b"\x00" * 2
            return ELFFile(io.BytesIO(raw)), bytes(data), True
    return ELFFile(io.BytesIO(data)), data, False

def read_c_str_from_bytes(data, offset, max_len=128):
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

JVM_SIG_REGEX = re.compile(r"^\([\[a-zA-Z0-9_$/;]*\)[\[a-zA-Z0-9_$/;V]+$")
JAVA_NAME_REGEX = re.compile(r"^[a-zA-Z0-9_$<>-]+$")

def scan_library_functions(so_name, so_path):
    t0 = time.time()
    elf, raw_data, is_truncated = safe_open_elf(so_path)
    file_sz = len(raw_data)
    file_hash = hashlib.sha256(raw_data).hexdigest().upper()
    
    # 1. Segments & Section Layout
    seg_list = []
    for seg in elf.iter_segments():
        seg_list.append((seg["p_vaddr"], seg["p_filesz"], seg["p_offset"], seg["p_flags"]))

    def vaddr_to_offset_fast(vaddr):
        for s_vaddr, s_filesz, s_offset, _ in seg_list:
            if s_vaddr <= vaddr < s_vaddr + s_filesz:
                return s_offset + (vaddr - s_vaddr)
        return None

    _STR_CACHE = {}
    def read_str_fast(vaddr):
        if vaddr in _STR_CACHE:
            return _STR_CACHE[vaddr]
        off = vaddr_to_offset_fast(vaddr)
        if off is None:
            _STR_CACHE[vaddr] = None
            return None
        s = read_c_str_from_bytes(raw_data, off)
        _STR_CACHE[vaddr] = s
        return s

    text_addr, text_size, text_offset = 0, 0, 0
    rodata_ranges = []
    try:
        for sec in elf.iter_sections():
            if sec.name == ".text":
                text_addr, text_size, text_offset = sec["sh_addr"], sec["sh_size"], sec["sh_offset"]
            elif sec.name in (".rodata", ".data.rel.ro", ".dynstr", ".strtab"):
                rodata_ranges.append((sec["sh_addr"], sec["sh_addr"] + sec["sh_size"]))
    except Exception:
        pass
        
    if text_size == 0:
        for s_vaddr, s_filesz, s_offset, s_flags in seg_list:
            if s_flags & 1: # PF_X
                text_addr = s_vaddr
                text_size = s_filesz
                text_offset = s_offset
                break
            elif not (s_flags & 2): # Read-only
                rodata_ranges.append((s_vaddr, s_vaddr + s_filesz))

    def in_rodata(vaddr):
        for start, end in rodata_ranges:
            if start <= vaddr < end:
                return True
        return False

    # 2. Dynamic Symbols & Tags
    raw_syms = []
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
                raw_syms.append((val, sz, name, bind, st_type))
                if name.startswith("Java_") or name in ("JNI_OnLoad", "JNI_OnUnload"):
                    direct_jni_exports.append({
                        "name": name,
                        "rva": val,
                        "size": sz
                    })
    except Exception:
        pass

    # Batch demangle all symbols in one fast call
    all_sym_names = [s[2] for s in raw_syms]
    demangled_map = batch_demangle(all_sym_names)
    dynsym_symbols = {}
    for val, sz, name, bind, st_type in raw_syms:
        dynsym_symbols[val] = {
            "name": name,
            "demangled": demangled_map.get(name, name),
            "size": sz,
            "bind": bind,
            "type": st_type
        }

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

    # 3. Relocations & PLT
    plt_imports = {}
    rela_dyn_map = {}
    rel_text_targets = set()
    
    try:
        plt_sec = elf.get_section_by_name(".plt")
        rela_plt = elf.get_section_by_name(".rela.plt")
        dynsym = elf.get_section_by_name(".dynsym")
        
        if plt_sec and rela_plt and dynsym:
            plt_base = plt_sec["sh_addr"]
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

    # 4. RegisterNatives Static Recovery
    register_natives_methods = []
    for offset, name_target in rela_dyn_map.items():
        if (offset + 8) in rela_dyn_map and (offset + 16) in rela_dyn_map:
            sig_target = rela_dyn_map[offset + 8]
            fn_target = rela_dyn_map[offset + 16]
            if text_addr <= fn_target < text_addr + text_size:
                sig_str = read_str_fast(sig_target)
                if sig_str and JVM_SIG_REGEX.match(sig_str):
                    name_str = read_str_fast(name_target)
                    if name_str and JAVA_NAME_REGEX.match(name_str):
                        register_natives_methods.append({
                            "table_offset": offset,
                            "method_name": name_str,
                            "signature": sig_str,
                            "fn_rva": fn_target
                        })

    # 5. Function Entry Discovery (Pass 1)
    func_entries = set()
    for val in dynsym_symbols:
        if text_addr <= val < text_addr + text_size:
            func_entries.add(val)
    for addr in rel_text_targets:
        func_entries.add(addr)
    for rn in register_natives_methods:
        func_entries.add(rn["fn_rva"])
        
    text_bytes = raw_data[text_offset : text_offset + text_size]
    for i in range(0, len(text_bytes) - 3, 4):
        pc = text_addr + i
        insn = struct.unpack("<I", text_bytes[i : i + 4])[0]
        if (insn >> 26) == 0x25: # BL
            imm26 = insn & 0x03FFFFFF
            if imm26 & 0x02000000:
                imm26 -= 0x04000000
            target = pc + imm26 * 4
            if text_addr <= target < text_addr + text_size:
                func_entries.add(target)
        elif (insn & 0xFFC003E0) == 0xA98003E0 or (insn & 0xFFC003E0) == 0xA9BF03E0: # STP x29, x30
            func_entries.add(pc)
        elif insn in (0xD503233F, 0xD503237F): # PACIASP / PACIBSP
            func_entries.add(pc)

    sorted_entries = sorted(func_entries)
    if not sorted_entries and text_size > 0:
        sorted_entries = [text_addr]

    func_cnt = len(sorted_entries)
    entry_to_fid = {addr: f"FN_{so_name.replace('.so', '')}_{addr:08X}" for addr in sorted_entries}
    rn_target_map = {rn["fn_rva"]: rn for rn in register_natives_methods}

    # Pre-initialize function structures
    functions = []
    callees_list = [[] for _ in range(func_cnt)]
    imported_list = [[] for _ in range(func_cnt)]
    string_xrefs_list = [[] for _ in range(func_cnt)]
    global_xrefs_list = [[] for _ in range(func_cnt)]
    call_graph_edges = []
    string_xrefs_all = []

    # 6. Single Linear Sweep over .text (Pass 2)
    func_idx = 0
    next_func_pc = sorted_entries[1] if func_cnt > 1 else text_addr + text_size
    reg_pages = {}

    for i in range(0, len(text_bytes) - 3, 4):
        pc = text_addr + i
        if pc >= next_func_pc:
            while func_idx + 1 < func_cnt and pc >= sorted_entries[func_idx + 1]:
                func_idx += 1
            next_func_pc = sorted_entries[func_idx + 1] if func_idx + 1 < func_cnt else text_addr + text_size

        insn = struct.unpack("<I", text_bytes[i : i + 4])[0]
        
        # BL
        if (insn >> 26) == 0x25:
            imm26 = insn & 0x03FFFFFF
            if imm26 & 0x02000000:
                imm26 -= 0x04000000
            target = pc + imm26 * 4
            if target in plt_imports:
                api = plt_imports[target]
                if api not in imported_list[func_idx]:
                    imported_list[func_idx].append(api)
            elif text_addr <= target < text_addr + text_size:
                callees_list[func_idx].append(target)
                call_graph_edges.append((sorted_entries[func_idx], target))
        
        # ADR
        elif (insn & 0x9F000000) == 0x10000000:
            immlo = (insn >> 29) & 3
            immhi = (insn >> 5) & 0x7FFFF
            imm21 = (immhi << 2) | immlo
            if imm21 & 0x100000:
                imm21 -= 0x200000
            adr_target = pc + imm21
            if in_rodata(adr_target):
                s = read_str_fast(adr_target)
                if s and len(s) >= 2 and any(c.isprintable() for c in s):
                    clean_s = re.sub(r'[\r\n\t,"]', ' ', s).strip()
                    string_xrefs_list[func_idx].append((adr_target, clean_s[:80]))
                    string_xrefs_all.append((sorted_entries[func_idx], adr_target, clean_s[:100]))

        # ADRP
        elif (insn & 0x9F000000) == 0x90000000:
            rd = insn & 0x1F
            immlo = (insn >> 29) & 3
            immhi = (insn >> 5) & 0x7FFFF
            imm21 = (immhi << 2) | immlo
            if imm21 & 0x100000:
                imm21 -= 0x200000
            reg_pages[rd] = (pc & ~0xFFF) + (imm21 << 12)

        # ADD (immediate)
        elif (insn & 0xFF800000) == 0x91000000:
            rd = insn & 0x1F
            rn = (insn >> 5) & 0x1F
            if rn in reg_pages:
                imm12 = (insn >> 10) & 0xFFF
                shift = (insn >> 22) & 3
                if shift == 1:
                    imm12 <<= 12
                resolved_addr = reg_pages[rn] + imm12
                if in_rodata(resolved_addr):
                    s = read_str_fast(resolved_addr)
                    if s and len(s) >= 2 and any(c.isprintable() for c in s):
                        clean_s = re.sub(r'[\r\n\t,"]', ' ', s).strip()
                        string_xrefs_list[func_idx].append((resolved_addr, clean_s[:80]))
                        string_xrefs_all.append((sorted_entries[func_idx], resolved_addr, clean_s[:100]))
                    else:
                        global_xrefs_list[func_idx].append(resolved_addr)
                else:
                    global_xrefs_list[func_idx].append(resolved_addr)

        # LDR (immediate)
        elif (insn & 0xFFC00000) == 0xF9400000:
            rt = insn & 0x1F
            rn = (insn >> 5) & 0x1F
            if rn in reg_pages:
                imm12 = ((insn >> 10) & 0xFFF) << 3
                global_xrefs_list[func_idx].append(reg_pages[rn] + imm12)

    # 7. Build Canonical Function Census Records
    for idx, addr in enumerate(sorted_entries):
        next_addr = sorted_entries[idx + 1] if idx + 1 < func_cnt else (text_addr + text_size)
        fn_size = max(4, next_addr - addr)
        fn_offset = text_offset + (addr - text_addr)
        fn_bytes = raw_data[fn_offset : fn_offset + fn_size] if (fn_offset + fn_size <= len(raw_data)) else raw_data[fn_offset:]
        fn_sha = hashlib.sha256(fn_bytes).hexdigest()
        
        orig_sym = dynsym_symbols.get(addr, {}).get("name", "")
        demangled_name = dynsym_symbols.get(addr, {}).get("demangled", "")
        
        is_direct_jni = orig_sym.startswith("Java_") or orig_sym in ("JNI_OnLoad", "JNI_OnUnload")
        is_rn_target = addr in rn_target_map
        is_export = bool(orig_sym)
        
        if is_rn_target:
            rn_info = rn_target_map[addr]
            rec_name = f"native_{rn_info['method_name']}_{rn_info['signature']}"
        elif demangled_name:
            rec_name = demangled_name
        elif orig_sym:
            rec_name = orig_sym
        else:
            rec_name = f"sub_{addr:X}"

        callees = callees_list[idx]
        imported_apis = imported_list[idx]
        string_xrefs = string_xrefs_list[idx]
        global_xrefs = global_xrefs_list[idx]

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
            "CALLER_COUNT": 0,
            "CALLEE_COUNT": len(callees),
            "CALLERS": "",
            "CALLEES": ";".join([f"0x{c:X}" for c in callees[:10]]),
            "IMPORTED_APIS": ";".join(imported_apis[:10]),
            "STRING_XREFS": ";".join([s[1] for s in string_xrefs[:5]]),
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

    # Invert callers
    caller_map = defaultdict(list)
    for f in functions:
        for c in f["_callees"]:
            caller_map[c].append(f["_raw_addr"])
            
    for f in functions:
        callers = caller_map.get(f["_raw_addr"], [])
        f["CALLER_COUNT"] = len(callers)
        f["CALLERS"] = ";".join([f"0x{c:X}" for c in callers[:10]])

    elapsed = time.time() - t0
    print(f"[{time.strftime('%X')}] {so_name}: {len(functions)} functions, {len(register_natives_methods)} RN, {len(direct_jni_exports)} direct JNI in {elapsed:.2f}s", flush=True)

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
