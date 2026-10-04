from elftools.elf.elffile import ELFFile

so_path = r'F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTFilterKernel.so'

with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    dynsym = elf.get_section_by_name('.dynsym')
    java_syms = []
    reg_syms = []
    for s in dynsym.iter_symbols():
        name = s.name
        if name.startswith('Java_'):
            java_syms.append((name, hex(s['st_value'])))
        if 'Register' in name or 'JNI_OnLoad' in name:
            reg_syms.append((name, hex(s['st_value'])))
            
    print(f'Direct Java_* exports in libMTFilterKernel.so: {len(java_syms)}')
    for sym in java_syms[:15]:
        print(' ', sym)
    print(f'JNI_OnLoad / Register symbols: {len(reg_syms)}')
    for sym in reg_syms:
        print(' ', sym)
