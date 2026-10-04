import os
import sys
import struct
import re
import csv
import json
from elftools.elf.elffile import ELFFile
from elftools.elf.sections import SymbolTableSection
from elftools.elf.relocation import RelocationSection
import capstone

SIBLING_SO_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a"
JADX_SRC_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\jadx_src\sources"

def demangle_jni(sym):
    # Java_com_meitu_core_MTFilterKernelConfigJNI_nInit -> com.meitu.core.MTFilterKernelConfigJNI.nInit
    if not sym.startswith("Java_"):
        return sym, "", ""
    parts = sym[5:].split("_")
    # In JNI mangling: _1 -> _, _2 -> ;, _3 -> [
    # Class path is separated by _
    # Usually the last part is method name
    # But could be overloaded with __
    if len(parts) >= 2:
        pkg_class = ".".join(parts[:-1]).replace("_1", "_")
        method = parts[-1].replace("_1", "_")
        return sym, pkg_class, method
    return sym, parts[0], ""

def scan_direct_jni(so_path, lib_name):
    direct_exports = []
    with open(so_path, "rb") as f:
        try:
            elf = ELFFile(f)
            for sec in elf.iter_sections():
                if isinstance(sec, SymbolTableSection):
                    for sym in sec.iter_symbols():
                        if sym.name.startswith("Java_"):
                            _, pkg_class, method = demangle_jni(sym.name)
                            direct_exports.append({
                                "library": lib_name,
                                "symbol": sym.name,
                                "rva": f"0x{sym.entry.st_value:08x}",
                                "size": sym.entry.st_size,
                                "binding_type": "DIRECT_EXPORT",
                                "java_class": pkg_class,
                                "java_method": method,
                                "signature": "N/A_DIRECT_EXPORT"
                            })
        except Exception as e:
            pass
    return direct_exports

def main():
    print("=== Scanning Native Direct JNI Exports across 45 files ===")
    all_direct_exports = []
    files = sorted([f for f in os.listdir(SIBLING_SO_DIR) if f.endswith(".so")])
    for f in files:
        p = os.path.join(SIBLING_SO_DIR, f)
        exports = scan_direct_jni(p, f)
        if exports:
            print(f"  {f:28s}: {len(exports):4d} direct JNI exports")
            all_direct_exports.extend(exports)

    print(f"Total direct JNI exports found: {len(all_direct_exports)}")
    
    # Save raw direct exports
    os.makedirs(r"scratch\task038_recon", exist_ok=True)
    with open(r"scratch\task038_recon\direct_jni_exports.json", "w", encoding="utf-8") as fp:
        json.dump(all_direct_exports, fp, indent=2)

if __name__ == "__main__":
    main()
