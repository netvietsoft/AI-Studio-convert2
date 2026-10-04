import os, sys, struct, glob
from elftools.elf.elffile import ELFFile

sibling = r'F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a'
so_files = sorted([f for f in os.listdir(sibling) if f.endswith('.so')])

def read_cstring(mem, addr, max_len=256):
    for vstart, (vend, b) in mem.items():
        if vstart <= addr < vend:
            off = addr - vstart
            end = b.find(b'\x00', off)
            if end == -1 or end - off > max_len or end == off:
                return None
            try:
                s = b[off:end].decode('utf-8')
                if s.isprintable() and len(s) > 0:
                    return s
            except Exception:
                pass
    return None

results = {}

for so_name in so_files:
    so_path = os.path.join(sibling, so_name)
    direct_jni = []
    dyn_jni = []
    has_jni_onload = False
    
    with open(so_path, 'rb') as f:
        elf = ELFFile(f)
        
        # 1. Direct symbols from .dynsym
        dynsym = elf.get_section_by_name('.dynsym')
        if dynsym:
            for s in dynsym.iter_symbols():
                name = s.name
                if name.startswith('Java_'):
                    direct_jni.append((name, hex(s['st_value']), s['st_size']))
                elif name == 'JNI_OnLoad':
                    has_jni_onload = True
                    
        # 2. Dynamic RegisterNatives tables
        text_sec = elf.get_section_by_name('.text')
        if text_sec:
            text_start = text_sec.header['sh_addr']
            text_end = text_start + text_sec.header['sh_size']
            
            # Load memory segments
            mem = {}
            for seg in elf.iter_segments():
                if seg.header['p_type'] == 'PT_LOAD':
                    vaddr = seg.header['p_vaddr']
                    mem[vaddr] = [vaddr + seg.header['p_memsz'], bytearray(seg.data())]
                    if seg.header['p_memsz'] > len(mem[vaddr][1]):
                        mem[vaddr][1].extend(b'\x00' * (seg.header['p_memsz'] - len(mem[vaddr][1])))
                        
            # Apply R_AARCH64_RELATIVE relocations
            rela_dyn = elf.get_section_by_name('.rela.dyn')
            if rela_dyn:
                for rel in rela_dyn.iter_relocations():
                    if rel['r_info_type'] == 1027: # R_AARCH64_RELATIVE
                        offset = rel['r_offset']
                        addend = rel['r_addend']
                        for vstart, (vend, b) in mem.items():
                            if vstart <= offset < vend:
                                off = offset - vstart
                                b[off:off+8] = struct.pack('<Q', addend)
                                
            # Scan for JNINativeMethod triples: (name_p, sig_p, fn_p)
            for vstart, (vend, b) in mem.items():
                if vstart == text_start:
                    continue
                for off in range(0, len(b) - 24, 8):
                    name_p, sig_p, fn_p = struct.unpack('<QQQ', b[off:off+24])
                    if text_start <= fn_p < text_end:
                        name_s = read_cstring(mem, name_p)
                        sig_s = read_cstring(mem, sig_p)
                        if name_s and sig_s and sig_s.startswith('(') and ')' in sig_s and len(name_s) < 64:
                            # Verify name is valid java identifier
                            if all(c.isalnum() or c == '_' or c == '$' for c in name_s):
                                dyn_jni.append((hex(vstart + off), name_s, sig_s, hex(fn_p)))
                                
    results[so_name] = {
        'direct_count': len(direct_jni),
        'dyn_count': len(dyn_jni),
        'has_jni_onload': has_jni_onload,
        'direct_samples': direct_jni[:3],
        'dyn_samples': dyn_jni[:3]
    }
    print(f'{so_name:28s} | JNI_OnLoad: {str(has_jni_onload):5s} | Direct JNI: {len(direct_jni):4d} | Dynamic JNI: {len(dyn_jni):4d}')
