import struct
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

so_path = r'F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTFilterKernel.so'

with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    rela_dyn = elf.get_section_by_name('.rela.dyn')
    print('Found .rela.dyn with', rela_dyn.num_relocations(), 'relocations')
    
    # Check relocation types
    types = {}
    for rel in rela_dyn.iter_relocations():
        t = rel['r_info_type']
        types[t] = types.get(t, 0) + 1
    print('Relocation types:', types)
