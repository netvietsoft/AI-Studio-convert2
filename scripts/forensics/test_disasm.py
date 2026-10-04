#!/usr/bin/env python3
"""
Test Capstone disassembly and PC-relative XREF on libPVGColorFunctions.so
"""
import struct
from pathlib import Path
from elftools.elf.elffile import ELFFile
from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM

def test():
    so_path = Path(r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGColorFunctions.so")
    with open(so_path, "rb") as f:
        elf = ELFFile(f)
        rela_plt = elf.get_section_by_name(".rela.plt")
        dynsym = elf.get_section_by_name(".dynsym")
        plt = elf.get_section_by_name(".plt")
        print(".plt addr:", hex(plt["sh_addr"]) if plt else None)
        if rela_plt and dynsym:
            print("Rela PLT relocations:", rela_plt.num_relocations())
            for i in range(min(15, rela_plt.num_relocations())):
                rel = rela_plt.get_relocation(i)
                sym = dynsym.get_symbol(rel["r_info_sym"])
                print(f"Reloc {i}: GOT offset {hex(rel['r_offset'])}, symbol: {sym.name}")


if __name__ == "__main__":
    test()
