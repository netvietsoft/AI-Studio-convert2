import os
import sys
import struct
import hashlib
import json
import csv
import re
from collections import defaultdict
from elftools.elf.elffile import ELFFile
from elftools.elf.sections import SymbolTableSection
from elftools.elf.relocation import RelocationSection
import capstone

SIBLING_SO_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a"
LLVM_CXXFILT = r"D:\SetupC\android-ndk-r27\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-cxxfilt.exe"

md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail = True

def demangle(name):
    if not name or not name.startswith("_Z"):
        return name
    # We can do quick demangle or call llvm-cxxfilt in batch
    return name

def analyze_single_library(so_name, out_base_dir, register_natives_map):
    so_path = os.path.join(SIBLING_SO_DIR, so_name)
    print(f"--> Analyzing {so_name}...")
    
    with open(so_path, "rb") as f:
        file_bytes = f.read()

    try:
        from io import BytesIO
        elf = ELFFile(BytesIO(file_bytes))
    except Exception as e:
        print(f"Error parsing ELF {so_name}: {e}")
        return []

    # Map sections
    sections = {}
    ro_data = b""
    ro_addr = 0
    text_data = b""
    text_addr = 0
    text_size = 0
    plt_addr = 0
    plt_size = 0

    try:
        for sec in elf.iter_sections():
            s_name = sec.name
            s_addr = sec["sh_addr"]
            s_size = sec["sh_size"]
            sections[s_name] = (s_addr, s_size, sec.data())
            if s_name == ".rodata":
                ro_data = sec.data()
                ro_addr = s_addr
            elif s_name == ".text":
                text_data = sec.data()
                text_addr = s_addr
                text_size = s_size
            elif s_name == ".plt":
                plt_addr = s_addr
                plt_size = s_size
    except Exception:
        pass

    # Read dynamic relocations
    rel_map = {}
    try:
        for sec in elf.iter_sections():
            if isinstance(sec, RelocationSection):
                for rel in sec.iter_relocations():
                    rel_map[rel.entry.r_offset] = getattr(rel.entry, "r_addend", 0)
    except Exception:
        pass

    # Helper to resolve string in .rodata
    def resolve_ro_str(va):
        if ro_addr <= va < ro_addr + len(ro_data):
            off = va - ro_addr
            null_idx = ro_data.find(b"\x00", off)
            if null_idx != -1:
                raw = ro_data[off:null_idx]
                try:
                    s = raw.decode("utf-8")
                    if s.isprintable() and len(s) >= 2:
                        return s
                except:
                    pass
        return None

    # Discover functions from symbols
    funcs_dict = {} # rva -> {info}
    try:
        for sec in elf.iter_sections():
            if isinstance(sec, SymbolTableSection):
                for sym in sec.iter_symbols():
                    st_val = sym.entry.st_value
                    st_sz = sym.entry.st_size
                    st_type = sym.entry.st_info.type
                    st_bind = sym.entry.st_info.bind
                    s_name = sym.name

                    if st_type == "STT_FUNC" and st_val != 0:
                        funcs_dict[st_val] = {
                            "rva": st_val,
                            "size": st_sz,
                            "name": s_name,
                            "bind": st_bind,
                            "is_export": (st_bind in ["STB_GLOBAL", "STB_WEAK"]),
                            "is_jni": s_name.startswith("Java_"),
                            "section": ".text" if text_addr <= st_val < text_addr + text_size else "OTHER"
                        }
    except Exception:
        pass

    # Also include known RegisterNatives entry points
    rn_methods = register_natives_map.get(so_name, [])
    for rnm in rn_methods:
        fn_rva = int(rnm["fn_rva"], 16)
        if fn_rva not in funcs_dict:
            funcs_dict[fn_rva] = {
                "rva": fn_rva,
                "size": 0, # to be inferred
                "name": f"RN_{rnm['name']}",
                "bind": "STB_LOCAL",
                "is_export": False,
                "is_jni": True,
                "section": ".text"
            }
        funcs_dict[fn_rva]["register_natives_target"] = True
        funcs_dict[fn_rva]["rn_name"] = rnm["name"]
        funcs_dict[fn_rva]["rn_sig"] = rnm["signature"]

    # Sort RVAs to estimate size for 0-size functions
    sorted_rvas = sorted(funcs_dict.keys())
    for i, rva in enumerate(sorted_rvas):
        if funcs_dict[rva]["size"] == 0:
            if i + 1 < len(sorted_rvas):
                funcs_dict[rva]["size"] = min(sorted_rvas[i+1] - rva, 4096)
            else:
                funcs_dict[rva]["size"] = 128

    print(f"  Total discovered functions in {so_name}: {len(funcs_dict)}")
    return funcs_dict

def main():
    with open(r"scratch\task038_recon\recovered_register_natives.json", "r", encoding="utf-8") as fp:
        tables = json.load(fp)

    rn_map = defaultdict(list)
    for t in tables:
        lib = t["library"]
        for m in t["methods"]:
            rn_map[lib].append(m)

    test_libs = ["libMTFilterKernel.so", "libPVGColorFunctions.so"]
    for lib in test_libs:
        funcs = analyze_single_library(lib, "scratch/test_out", rn_map)
        print(f"Successfully analyzed {lib}: {len(funcs)} functions")

if __name__ == "__main__":
    main()
