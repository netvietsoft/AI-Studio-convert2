#!/usr/bin/env python3
"""
scripts/forensics/census_binaries.py
Verify and census all 45 vendor ARM64 shared libraries for TASK_038 (Quality Gate G1).
"""
import os
import sys
import json
import hashlib
from pathlib import Path
from elftools.elf.elffile import ELFFile
from elftools.elf.dynamic import DynamicSection

def get_hashes(filepath):
    sha256 = hashlib.sha256()
    md5 = hashlib.md5()
    with open(filepath, "rb") as f:
        while chunk := f.read(65536):
            sha256.update(chunk)
            md5.update(chunk)
    return sha256.hexdigest(), md5.hexdigest()

def analyze_elf(filepath):
    sha256, md5 = get_hashes(filepath)
    size = filepath.stat().st_size
    
    info = {
        "filename": filepath.name,
        "path": str(filepath),
        "size_bytes": size,
        "sha256": sha256,
        "md5": md5,
        "elf_header": {},
        "sections": [],
        "needed_libraries": [],
        "soname": None
    }
    
    with open(filepath, "rb") as f:
        elf = ELFFile(f)
        info["elf_header"] = {
            "class": elf.header["e_ident"]["EI_CLASS"],
            "data": elf.header["e_ident"]["EI_DATA"],
            "version": elf.header["e_ident"]["EI_VERSION"],
            "osabi": elf.header["e_ident"]["EI_OSABI"],
            "type": elf.header["e_type"],
            "machine": elf.header["e_machine"],
            "entry_point": hex(elf.header["e_entry"]),
            "flags": hex(elf.header["e_flags"])
        }
        
        try:
            for section in elf.iter_sections():
                info["sections"].append({
                    "name": section.name,
                    "type": section["sh_type"],
                    "addr": hex(section["sh_addr"]),
                    "offset": hex(section["sh_offset"]),
                    "size": section["sh_size"],
                    "flags": hex(section["sh_flags"])
                })
                if isinstance(section, DynamicSection):
                    for tag in section.iter_tags():
                        if tag.entry.d_tag == "DT_NEEDED":
                            info["needed_libraries"].append(tag.needed)
                        elif tag.entry.d_tag == "DT_SONAME":
                            info["soname"] = tag.soname
        except Exception as e:
            info["section_parse_error"] = str(e)
                        
    return info

def main():
    src_dir = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a")
    baseline_dir = Path("lib-core-graphics/src/main/jniLibs/arm64-v8a")
    out_dir = Path(".ai/reports/TASK_038_45SO_DEEP_FUNCTION_XREF_JNI_BRIDGE_RECONSTRUCTION/raw")
    out_dir.mkdir(parents=True, exist_ok=True)
    
    if not src_dir.exists():
        print(f"[!] Error: Source directory {src_dir} does not exist.")
        sys.exit(1)
        
    so_files = sorted(list(src_dir.glob("*.so")))
    print(f"[*] Found {len(so_files)} vendor .so files in {src_dir}")
    
    census = []
    baseline_comparison = []
    
    for so in so_files:
        print(f"  -> Analyzing {so.name} ({so.stat().st_size} bytes)...")
        info = analyze_elf(so)
        census.append(info)
        
        # Baseline comparison
        base_so = baseline_dir / so.name
        matched = False
        base_sha256 = None
        if base_so.exists():
            base_sha256, _ = get_hashes(base_so)
            matched = (base_sha256 == info["sha256"])
        
        baseline_comparison.append({
            "filename": so.name,
            "source_size": info["size_bytes"],
            "source_sha256": info["sha256"],
            "baseline_exists": base_so.exists(),
            "baseline_sha256": base_sha256,
            "hash_match": matched
        })
        
    out_file = out_dir / "binary_census.json"
    with open(out_file, "w", encoding="utf-8") as f:
        json.dump(census, f, indent=2)
        
    comp_file = out_dir / "baseline_hash_comparison.json"
    with open(comp_file, "w", encoding="utf-8") as f:
        json.dump(baseline_comparison, f, indent=2)
        
    print(f"[+] Census written to {out_file}")
    print(f"[+] Baseline comparison written to {comp_file}")
    print(f"[+] Total accounted vendor SOs: {len(census)}")
    if len(census) == 45:
        print("[+] Quality Gate G1: EXACTLY 45 SOs VERIFIED (PASS)")
    else:
        print(f"[!] Quality Gate G1: Expected 45, got {len(census)} (FAIL)")

if __name__ == "__main__":
    main()
