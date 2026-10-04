import struct
from elftools.elf.elffile import ELFFile

so_path = r'F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTFilterKernel.so'

def read_cstring(data_map, addr, max_len=256):
    for vstart, (vend, b) in data_map.items():
        if vstart <= addr < vend:
            off = addr - vstart
            end = b.find(b'\x00', off)
            if end == -1 or end - off > max_len or end == off:
                return None
            try:
                s = b[off:end].decode('utf-8')
                if s.isprintable():
                    return s
            except Exception:
                pass
    return None

with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    
    # Load all PT_LOAD segments into bytearrays
    mem = {}
    for seg in elf.iter_segments():
        if seg.header['p_type'] == 'PT_LOAD':
            vaddr = seg.header['p_vaddr']
            mem[vaddr] = [vaddr + seg.header['p_memsz'], bytearray(seg.data())]
            # pad to memsz
            if seg.header['p_memsz'] > len(mem[vaddr][1]):
                mem[vaddr][1].extend(b'\x00' * (seg.header['p_memsz'] - len(mem[vaddr][1])))

    # Apply R_AARCH64_RELATIVE relocations (type 1027)
    rela_dyn = elf.get_section_by_name('.rela.dyn')
    if rela_dyn:
        for rel in rela_dyn.iter_relocations():
            if rel['r_info_type'] == 1027:
                offset = rel['r_offset']
                addend = rel['r_addend']
                for vstart, (vend, b) in mem.items():
                    if vstart <= offset < vend:
                        off = offset - vstart
                        b[off:off+8] = struct.pack('<Q', addend)

    text_sec = elf.get_section_by_name('.text')
    text_start = text_sec.header['sh_addr']
    text_end = text_start + text_sec.header['sh_size']
    
    # Scan for JNINativeMethod tables (name_ptr, sig_ptr, fn_ptr)
    methods = []
    for vstart, (vend, b) in mem.items():
        if vstart == text_start: # skip text
            continue
        for off in range(0, len(b) - 24, 8):
            name_p, sig_p, fn_p = struct.unpack('<QQQ', b[off:off+24])
            if text_start <= fn_p < text_end:
                name_s = read_cstring(mem, name_p)
                sig_s = read_cstring(mem, sig_p)
                if name_s and sig_s and sig_s.startswith('(') and ')' in sig_s:
                    methods.append((hex(vstart + off), name_s, sig_s, hex(fn_p)))

    print(f'Discovered {len(methods)} dynamic JNINativeMethod entries in libMTFilterKernel.so:')
    for m in methods:
        print(f'  Table entry {m[0]}: {m[1]}{m[2]} -> {m[3]}')
