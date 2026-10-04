import os
import sys
import struct
import re
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

SIBLING_SO_DIR = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a"

JVM_SIG_RE = re.compile(r"^\([a-zA-Z0-9_/$;\[]*\)[a-zA-Z0-9_/$;\[]+$")
IDENT_RE = re.compile(r"^[a-zA-Z0-9_]+$")

def analyze_lib_register_natives(path, fname):
    with open(path, "rb") as f:
        try:
            elf = ELFFile(f)
        except Exception as e:
            return []

        # Find .rodata and .text boundaries
        ro_data = b""
        ro_addr = 0
        text_addr = 0
        text_size = 0

        try:
            for sec in elf.iter_sections():
                if sec.name == ".rodata":
                    ro_data = sec.data()
                    ro_addr = sec["sh_addr"]
                elif sec.name == ".text":
                    text_addr = sec["sh_addr"]
                    text_size = sec["sh_size"]
        except Exception:
            return []

        def get_str(va):
            if ro_addr <= va < ro_addr + len(ro_data):
                off = va - ro_addr
                null_idx = ro_data.find(b"\x00", off)
                if null_idx != -1:
                    raw = ro_data[off:null_idx]
                    try:
                        return raw.decode("utf-8")
                    except:
                        pass
            return None

        # Build relocation map
        rel_map = {}
        try:
            for sec in elf.iter_sections():
                if isinstance(sec, RelocationSection):
                    for rel in sec.iter_relocations():
                        rel_map[rel.entry.r_offset] = getattr(rel.entry, "r_addend", 0)
        except Exception:
            pass

        # Scan for triples (offset, offset+8, offset+16)
        sorted_offsets = sorted([off for off in rel_map.keys() if off % 8 == 0])
        
        tables = []
        visited = set()

        for off in sorted_offsets:
            if off in visited:
                continue
            
            # Check if this could be the start of a JNINativeMethod array
            current_off = off
            methods = []
            while current_off in rel_map and (current_off + 8) in rel_map and (current_off + 16) in rel_map:
                name_va = rel_map[current_off]
                sig_va = rel_map[current_off + 8]
                fn_va = rel_map[current_off + 16]

                name_str = get_str(name_va)
                sig_str = get_str(sig_va)

                if name_str and sig_str and IDENT_RE.match(name_str) and JVM_SIG_RE.match(sig_str):
                    if text_addr <= fn_va < text_addr + text_size:
                        methods.append({
                            "name": name_str,
                            "signature": sig_str,
                            "fn_rva": f"0x{fn_va:08x}",
                            "entry_offset": f"0x{current_off:08x}"
                        })
                        visited.add(current_off)
                        visited.add(current_off + 8)
                        visited.add(current_off + 16)
                        current_off += 24
                        continue
                break

            if len(methods) >= 1:
                tables.append({
                    "library": fname,
                    "table_rva": f"0x{off:08x}",
                    "method_count": len(methods),
                    "methods": methods
                })

        return tables

def main():
    print("=== Scanning all 45 libraries for dynamic RegisterNatives tables ===")
    files = sorted([f for f in os.listdir(SIBLING_SO_DIR) if f.endswith(".so")])
    total_tables = 0
    total_methods = 0

    results = []
    for f in files:
        p = os.path.join(SIBLING_SO_DIR, f)
        tables = analyze_lib_register_natives(p, f)
        if tables:
            print(f"[{f}] Found {len(tables)} JNINativeMethod tables:")
            for t in tables:
                cnt = t["method_count"]
                print(f"   Table @ {t['table_rva']}: {cnt} methods (First: {t['methods'][0]['name']} {t['methods'][0]['signature']} -> {t['methods'][0]['fn_rva']})")
                total_methods += cnt
                total_tables += 1
            results.extend(tables)

    print(f"\nTotal RegisterNatives tables recovered: {total_tables}")
    print(f"Total dynamic native methods recovered: {total_methods}")

    with open(r"scratch\task038_recon\recovered_register_natives.json", "w", encoding="utf-8") as fp:
        import json
        json.dump(results, fp, indent=2)

if __name__ == "__main__":
    main()
