import os, sys, struct
from elftools.elf.elffile import ELFFile

so_path = r'F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTFilterKernel.so'

def read_cstring(data, offset, max_len=256):
    if offset < 0 or offset >= len(data):
        return None
    end = data.find(b'\x00', offset)
    if end == -1 or end - offset > max_len or end == offset:
        return None
    try:
        s = data[offset:end].decode('utf-8')
        if s.isprintable():
            return s
    except Exception:
        pass
    return None

with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    # Load all loadable segments into a flat memory map based on vaddr
    mem = {}
    text_sec = elf.get_section_by_name('.text')
    text_start = text_sec.header['sh_addr']
    text_end = text_start + text_sec.header['sh_size']
    
    for seg in elf.iter_segments():
        if seg.header['p_type'] == 'PT_LOAD':
            vaddr = seg.header['p_vaddr']
            data = seg.data()
            mem[vaddr] = (vaddr + len(data), data)

    def read_mem(addr, size):
        for vstart, (vend, data) in mem.items():
            if vstart <= addr < vend:
                off = addr - vstart
                return data[off:off+size]
        return None

    def read_str_from_mem(addr):
        for vstart, (vend, data) in mem.items():
            if vstart <= addr < vend:
                off = addr - vstart
                return read_cstring(data, off)
        return None

    print(f'Text section: 0x{text_start:x} - 0x{text_end:x}')
    
    # Search for JNINativeMethod arrays in data segments
    # JNINativeMethod is 24 bytes: name_ptr (8B), sig_ptr (8B), fn_ptr (8B)
    methods_found = []
    for vstart, (vend, data) in mem.items():
        for off in range(0, len(data) - 24, 8):
            name_p, sig_p, fn_p = struct.unpack('<QQQ', data[off:off+24])
            if text_start <= fn_p < text_end:
                name_str = read_str_from_mem(name_p)
                sig_str = read_str_from_mem(sig_p)
                if name_str and sig_str and sig_str.startswith('(') and ')' in sig_str:
                    methods_found.append((hex(vstart + off), name_str, sig_str, hex(fn_p)))
                    
    print(f'Found {len(methods_found)} dynamically registered JNI methods in libMTFilterKernel.so:')
    for m in methods_found[:15]:
        print(f'  Table @ {m[0]}: {m[1]}{m[2]} -> {m[3]}')
