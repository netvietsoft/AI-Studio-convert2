import os
import sys
from elftools.elf.elffile import ELFFile

so_path = r'F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTFilterKernel.so'
with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    print('ELF class:', elf.elfclass, 'Machine:', elf.header['e_machine'])
    for sec in elf.iter_sections():
        if sec.name in ['.text', '.rodata', '.data', '.dynsym', '.plt', '.got']:
            print(f'Section {sec.name}: addr={hex(sec.header["sh_addr"])}, size={sec.header["sh_size"]}')
