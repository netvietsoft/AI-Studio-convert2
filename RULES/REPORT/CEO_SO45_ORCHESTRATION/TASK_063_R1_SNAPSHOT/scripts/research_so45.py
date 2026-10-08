#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
TASK_063 SO45 Input Truth, Evidence Baseline, and Research Dispatch.
Independent verification of all 45 SO files on disk:
- Byte counts and SHA-256 hashes
- Full ELF header and program/section boundary validation
- Truncation identification (especially libmfxkit.so)
- Container comparison (com.mt.mtxx.mtxx.apk, Meitu_12.17.8_APKPure.xapk)
- Audit of 5 critical historical claims
- 7 Lane assignments (TASK_064A..G)
"""

import os
import sys
import json
import struct
import hashlib
import zipfile
from pathlib import Path

SO_DIR = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a")
APK_PATH = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\com.mt.mtxx.mtxx.apk")
XAPK_PATH = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\Meitu_12.17.8_APKPure.xapk")
REPORT_DIR = Path(r"RULES\REPORT\TASK_063_REPORT")
RAW_DIR = REPORT_DIR / "raw"

def sha256_file(p: Path) -> str:
    h = hashlib.sha256()
    with open(p, "rb") as f:
        while chunk := f.read(1024 * 1024):
            h.update(chunk)
    return h.hexdigest()

def inspect_elf(p: Path):
    size = p.stat().st_size
    with open(p, "rb") as f:
        header = f.read(64)
        if len(header) < 64:
            return {"valid_header": False, "size": size, "error": "HEADER_TOO_SHORT"}
        
        # e_ident
        magic = header[:4]
        if magic != b"\x7fELF":
            return {"valid_header": False, "size": size, "error": "NOT_ELF"}
        
        ei_class = header[4] # 1: 32-bit, 2: 64-bit
        ei_data = header[5]  # 1: little-endian, 2: big-endian
        
        if ei_class != 2 or ei_data != 1:
            return {"valid_header": False, "size": size, "ei_class": ei_class, "ei_data": ei_data}
        
        # Unpack ELF64
        # e_type(H), e_machine(H), e_version(I), e_entry(Q), e_phoff(Q), e_shoff(Q), e_flags(I), e_ehsize(H), e_phentsize(H), e_phnum(H), e_shentsize(H), e_shnum(H), e_shstrndx(H)
        e_type, e_machine, e_version, e_entry, e_phoff, e_shoff, e_flags, e_ehsize, e_phentsize, e_phnum, e_shentsize, e_shnum, e_shstrndx = struct.unpack_from("<HHIQQQIHHHHHH", header, 16)
        
        # Program table bounds
        ph_end = e_phoff + e_phentsize * e_phnum
        program_table_bounded = (ph_end <= size) and (e_phoff < size)
        
        # Check load segments
        load_segments_bounded = True
        pt_loads = []
        if program_table_bounded and e_phnum > 0:
            f.seek(e_phoff)
            ph_data = f.read(e_phentsize * e_phnum)
            for i in range(e_phnum):
                offset = i * e_phentsize
                p_type, p_flags, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_align = struct.unpack_from("<IIQQQQQQ", ph_data, offset)
                if p_type == 1: # PT_LOAD
                    pt_loads.append({"offset": p_offset, "filesz": p_filesz, "memsz": p_memsz})
                    if p_offset + p_filesz > size:
                        load_segments_bounded = False
        else:
            load_segments_bounded = False
            
        # Section table bounds
        sh_end = e_shoff + e_shentsize * e_shnum
        section_table_bounded = (sh_end <= size) and (e_shoff < size)
        sections = []
        if section_table_bounded and e_shnum > 0:
            f.seek(e_shoff)
            sh_data = f.read(e_shentsize * e_shnum)
            for i in range(e_shnum):
                offset = i * e_shentsize
                sh_name, sh_type, sh_flags, sh_addr, sh_offset, sh_size, sh_link, sh_info, sh_addralign, sh_entsize = struct.unpack_from("<IIQQQQIIQQ", sh_data, offset)
                sections.append({"type": sh_type, "offset": sh_offset, "size": sh_size})
                if sh_type != 8: # SHT_NOBITS
                    if sh_offset + sh_size > size:
                        section_table_bounded = False
        else:
            section_table_bounded = False
            
        return {
            "valid_header": True,
            "size": size,
            "elf_class": 64 if ei_class == 2 else 32,
            "machine": e_machine,
            "e_phoff": e_phoff,
            "e_phnum": e_phnum,
            "program_table_bounded": program_table_bounded,
            "pt_loads": pt_loads,
            "load_segments_bounded": load_segments_bounded,
            "e_shoff": e_shoff,
            "e_shnum": e_shnum,
            "section_table_bounded": section_table_bounded,
            "sh_end": sh_end
        }

def main():
    print(f"Scanning SO files from {SO_DIR}...")
    so_files = sorted(list(SO_DIR.glob("*.so")))
    print(f"Found {len(so_files)} .so files.")
    
    # Check container files
    apk_libs = {}
    if APK_PATH.exists():
        try:
            with zipfile.ZipFile(APK_PATH, "r") as z:
                for info in z.infolist():
                    if info.filename.startswith("lib/arm64-v8a/"):
                        name = Path(info.filename).name
                        apk_libs[name] = {
                            "file_size": info.file_size,
                            "compress_size": info.compress_size,
                            "crc": info.CRC
                        }
        except Exception as e:
            print(f"Error reading APK: {e}")
            
    xapk_libs = {}
    if XAPK_PATH.exists():
        try:
            with zipfile.ZipFile(XAPK_PATH, "r") as z:
                for info in z.infolist():
                    if "arm64-v8a" in info.filename and info.filename.endswith(".so"):
                        name = Path(info.filename).name
                        xapk_libs[name] = {
                            "file_size": info.file_size,
                            "compress_size": info.compress_size,
                            "crc": info.CRC,
                            "zip_path": info.filename
                        }
        except Exception as e:
            print(f"Error reading XAPK: {e}")
            
    results = []
    for f in so_files:
        name = f.name
        size = f.stat().st_size
        sha = sha256_file(f)
        elf_info = inspect_elf(f)
        
        apk_info = apk_libs.get(name)
        xapk_info = xapk_libs.get(name)
        
        status = "VALID"
        err = ""
        if not elf_info.get("program_table_bounded"):
            status = "TRUNCATED_PROGRAM_HEADER"
            err = "Program table exceeds file bounds"
        elif not elf_info.get("load_segments_bounded"):
            status = "TRUNCATED_LOAD_SEGMENTS"
            err = f"PT_LOAD segment exceeds file size ({size})"
        elif not elf_info.get("section_table_bounded"):
            status = "TRUNCATED_SECTION_TABLE"
            err = f"Section table end ({elf_info.get('sh_end')}) exceeds file size ({size})"
            
        results.append({
            "name": name,
            "path": str(f),
            "size": size,
            "sha256": sha,
            "elf": elf_info,
            "apk_info": apk_info,
            "xapk_info": xapk_info,
            "status": status,
            "error": err
        })
        
    print(f"Processed {len(results)} files.")
    
    # Check libmfxkit specifically
    mfx = next((r for r in results if r["name"] == "libmfxkit.so"), None)
    if mfx:
        print(f"\n--- libmfxkit.so Deep Inspection ---")
        print(f"Actual file size on disk: {mfx['size']}")
        print(f"SHA-256: {mfx['sha256']}")
        print(f"Section table offset: {mfx['elf']['e_shoff']}")
        print(f"Section table entries: {mfx['elf']['e_shnum']}")
        print(f"Expected section table end: {mfx['elf']['sh_end']}")
        print(f"Bytes missing: {mfx['elf']['sh_end'] - mfx['size']}")
        if mfx['apk_info']:
            print(f"Declared uncompressed size in APK: {mfx['apk_info']['file_size']}")
        if mfx['xapk_info']:
            print(f"Declared uncompressed size in XAPK: {mfx['xapk_info']['file_size']}")
            
    # Save raw audit output
    RAW_DIR.mkdir(parents=True, exist_ok=True)
    with open(RAW_DIR / "so45_inspection_raw.json", "w", encoding="utf-8") as out:
        json.dump(results, out, indent=2)
        
    print(f"\nRaw inspection written to {RAW_DIR / 'so45_inspection_raw.json'}")

if __name__ == "__main__":
    main()
