#!/usr/bin/env python3
"""
scripts/forensics/analyze_hair_core.py
Deep inspection of Hair functions, shaders, and call flows in libMTFilterKernel.so,
libarkernel3.so, libLayerFlow.so, libManis.so, libPVGColorFunctions.so.
"""
import struct
from pathlib import Path
from elftools.elf.elffile import ELFFile
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM

def analyze_libmtfilterkernel():
    path = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTFilterKernel.so")
    print("=== Analyzing libMTFilterKernel.so Hair Pipeline ===")
    with open(path, "rb") as f:
        elf = ELFFile(f)
        text = elf.get_section_by_name(".text")
        rodata = elf.get_section_by_name(".rodata")
        dynsym = elf.get_section_by_name(".dynsym")
        t_data = text.data()
        t_addr = text["sh_addr"]
        r_data = rodata.data()
        r_addr = rodata["sh_addr"]
        
        sym_map = {s["st_value"]: s.name for s in dynsym.iter_symbols()}
        
        md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
        md.detail = True
        
        # Targets
        targets = [
            ("Initlize", 0x1342dc, 524),
            ("FilterToFBO", 0x1344e8, 708),
            ("GrayFilterToFBO", 0x13488c, 228),
            ("HairMaskFilterToFBO", 0x134970, 288),
            ("BlurHFilterToFBO", 0x134a90, 384),
            ("BlurVFilterToFBO", 0x134c10, 384),
            ("SoftHairFilterToFBO", 0x134d90, 516)
        ]
        
        for name, rva, size in targets:
            print(f"\n--- Function: {name} (RVA: {hex(rva)}, Size: {size}) ---")
            code = t_data[rva - t_addr : rva - t_addr + size]
            adrp_map = {}
            for insn in md.disasm(code, rva):
                mn = insn.mnemonic
                op = insn.op_str
                if mn == "adrp":
                    reg = op.split(",")[0].strip()
                    adrp_map[reg] = insn.operands[1].imm
                elif mn == "add" and len(insn.operands) >= 3:
                    dst = op.split(",")[0].strip()
                    src = op.split(",")[1].strip()
                    if src in adrp_map:
                        t_va = adrp_map[src] + insn.operands[2].imm
                        if r_addr <= t_va < r_addr + len(r_data):
                            raw = r_data[t_va - r_addr : t_va - r_addr + 120].split(b"\x00")[0]
                            try:
                                s = raw.decode("utf-8")
                                print(f"  {hex(insn.address)}: STRING XREF: \"{s}\"")
                            except Exception:
                                pass
                elif mn == "adr":
                    t_va = insn.operands[1].imm
                    if r_addr <= t_va < r_addr + len(r_data):
                        raw = r_data[t_va - r_addr : t_va - r_addr + 120].split(b"\x00")[0]
                        try:
                            s = raw.decode("utf-8")
                            print(f"  {hex(insn.address)}: STRING XREF: \"{s}\"")
                        except Exception:
                            pass
                elif mn in ("bl", "b") and insn.operands and insn.operands[0].type == 2:
                    tgt = insn.operands[0].imm
                    callee_name = sym_map.get(tgt, hex(tgt))
                    print(f"  {hex(insn.address)}: CALL {callee_name}")

if __name__ == "__main__":
    analyze_libmtfilterkernel()
