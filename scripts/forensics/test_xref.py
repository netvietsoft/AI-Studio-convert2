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

# Target addresses to find XREFs for:
targets = {0x1ca2d8: 'Table 1', 0x1ca530: 'Table 2'}

# Scan for adrp + add/ldr
prev_adrp = {} # reg -> (page_addr, insn_addr)

for insn in md.disasm(text_data, text_addr):
    if insn.mnemonic == 'adrp':
        reg = insn.operands[0].reg
        imm = insn.operands[1].imm
        prev_adrp[reg] = (imm, insn.address)
    elif insn.mnemonic in ['add', 'ldr']:
        dst = insn.operands[0].reg
        if len(insn.operands) >= 2 and insn.operands[1].type == capstone.arm64.ARM64_OP_REG:
            src = insn.operands[1].reg
            if src in prev_adrp:
                page_addr, adrp_addr = prev_adrp[src]
                if len(insn.operands) >= 3 and insn.operands[2].type == capstone.arm64.ARM64_OP_IMM:
                    imm = insn.operands[2].imm
                    target_va = page_addr + imm
                    if target_va in targets:
                        print(f'XREF to {targets[target_va]} ({hex(target_va)}) from insn at {hex(insn.address)} (adrp at {hex(adrp_addr)})')
                elif insn.mnemonic == 'ldr' and len(insn.operands) == 2 and insn.operands[1].type == capstone.arm64.ARM64_OP_MEM:
                    mem = insn.operands[1].mem
                    if mem.base in prev_adrp:
                        page_addr, adrp_addr = prev_adrp[mem.base]
                        target_va = page_addr + mem.disp
                        if target_va in targets:
                            print(f'XREF to {targets[target_va]} ({hex(target_va)}) via ldr at {hex(insn.address)}')
        # if dst in prev_adrp and dst != src:
        #     del prev_adrp[dst]
