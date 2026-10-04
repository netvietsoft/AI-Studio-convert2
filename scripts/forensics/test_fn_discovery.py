import os, sys, struct, hashlib
from elftools.elf.elffile import ELFFile
import capstone

so_path = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTFilterKernel.so"

def analyze_sample(so_path):
    with open(so_path, "rb") as f:
        elf = ELFFile(f)
        text_sec = elf.get_section_by_name('.text')
        text_start = text_sec.header['sh_addr']
        text_size = text_sec.header['sh_size']
        text_end = text_start + text_size
        text_data = text_sec.data()
        
        rodata_sec = elf.get_section_by_name('.rodata')
        rodata_start = rodata_sec.header['sh_addr']
        rodata_data = rodata_sec.data()
        
        # Build rodata string table
        strings = {}
        for off in range(len(rodata_data)):
            if rodata_data[off:off+1] != b'\x00' and (off == 0 or rodata_data[off-1:off] == b'\x00'):
                end = rodata_data.find(b'\x00', off)
                if end != -1 and 3 <= end - off <= 256:
                    try:
                        s = rodata_data[off:end].decode('utf-8')
                        if s.isprintable():
                            strings[rodata_start + off] = s
                    except Exception:
                        pass
                        
        print(f"Extracted {len(strings)} strings from .rodata")
        
        # Parse PLT to map PLT addresses to imported API names
        plt_sec = elf.get_section_by_name('.plt')
        rela_plt = elf.get_section_by_name('.rela.plt')
        dynsym = elf.get_section_by_name('.dynsym')
        
        plt_map = {}
        if plt_sec and rela_plt and dynsym:
            plt_start = plt_sec.header['sh_addr']
            # In ARM64, PLT0 is 32 bytes, then entries are 16 bytes each
            sym_list = list(dynsym.iter_symbols())
            for idx, rel in enumerate(rela_plt.iter_relocations()):
                sym_idx = rel['r_info_sym']
                if sym_idx < len(sym_list):
                    sym_name = sym_list[sym_idx].name
                    entry_addr = plt_start + 32 + idx * 16
                    plt_map[entry_addr] = sym_name
                    
        print(f"Mapped {len(plt_map)} PLT stubs")
        
        # Disassemble and find entrypoints
        md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
        md.detail = True
        
        entrypoints = set()
        # 1. Symbols in dynsym
        for s in dynsym.iter_symbols():
            if text_start <= s['st_value'] < text_end:
                entrypoints.add(s['st_value'])
                
        # 2. Fast scan of text for bl calls and prologues
        bl_targets = set()
        prev_adrp = {}
        
        count = 0
        for insn in md.disasm(text_data, text_start):
            count += 1
            if insn.mnemonic == 'bl':
                try:
                    target = int(insn.op_str.lstrip('#'), 16)
                    if text_start <= target < text_end:
                        entrypoints.add(target)
                except Exception:
                    pass
            elif insn.mnemonic in ['stp', 'pacibsp', 'paciasp']:
                if 'x29, x30' in insn.op_str:
                    entrypoints.add(insn.address)
                    
        print(f"Total disassembled instructions: {count}")
        print(f"Total discovered function entrypoints: {len(entrypoints)}")

analyze_sample(so_path)
