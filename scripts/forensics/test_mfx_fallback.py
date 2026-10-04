import struct, os
import capstone

mfx_path = r"F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libmfxkit.so"
file_size = os.path.getsize(mfx_path)

with open(mfx_path, "rb") as f:
    hdr = f.read(64)
    magic, e_type, e_machine, e_version, e_entry, e_phoff, e_shoff, e_flags, e_ehsize, e_phentsize, e_phnum, e_shentsize, e_shnum, e_shstrndx = struct.unpack('<16sHHIQQQIHHHHHH', hdr)
    f.seek(e_phoff)
    load_segs = []
    for i in range(e_phnum):
        p_type, p_flags, p_offset, p_vaddr, p_paddr, p_filesz, p_memsz, p_align = struct.unpack('<IIQQQQQQ', f.read(56))
        if p_type == 1: # PT_LOAD
            load_segs.append((p_offset, p_vaddr, min(p_filesz, file_size - p_offset), p_flags))

print(f"libmfxkit.so has {len(load_segs)} PT_LOAD segments within file bounds")
for s in load_segs:
    print(f"  off={hex(s[0])} vaddr={hex(s[1])} size={s[2]} flags={hex(s[3])}")
    
# Test disassembling first executable segment
code_seg = [s for s in load_segs if s[3] & 1][0] # PF_X
with open(mfx_path, "rb") as f:
    f.seek(code_seg[0])
    chunk = f.read(1000)
    
md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
insns = list(md.disasm(chunk, code_seg[1]))
print(f"Successfully disassembled {len(insns)} instructions from libmfxkit.so")
