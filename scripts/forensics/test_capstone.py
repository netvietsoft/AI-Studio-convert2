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

count = 0
for insn in md.disasm(text_data[:200], text_addr):
    print(f'0x{insn.address:08x}: {insn.mnemonic} {insn.op_str}')
    count += 1
    if count >= 10:
        break
