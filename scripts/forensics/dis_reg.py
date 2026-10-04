import capstone
from elftools.elf.elffile import ELFFile

so_path = r'F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTFilterKernel.so'

with open(so_path, 'rb') as f:
    elf = ELFFile(f)
    text_sec = elf.get_section_by_name('.text')
    text_data = text_sec.data()
    text_addr = text_sec.header['sh_addr']
    
md = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_ARM)
md.detail = True

def dis(start, count):
    offset = start - text_addr
    chunk = text_data[offset:offset+count*4]
    for insn in md.disasm(chunk, start):
        print(f'  0x{insn.address:x}: {insn.mnemonic:8s} {insn.op_str}')

print('--- Function registering Table 1 (around 0xbe400):')
dis(0xbe400, 20)
print('--- Function registering Table 2 (around 0xbfca0):')
dis(0xbfca0, 20)
