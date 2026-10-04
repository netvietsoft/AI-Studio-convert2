// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc36820
// Recovered Name: sub_c36820
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc36820 | Size: 132 bytes | SHA256: 222662bea086fd1412d7bbce3be0b0fbc0981d245508f2b7e57a50445bfa771b
// Callers: 1 | Callees: 1 | Imports: 0

// Strings referenced:
//   "AdvanceMakeupHairMaskMidPoint"

void sub_c36820(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0xc36820 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xc36824 */ str x21, [sp, #0x10];
    /* 0xc36828 */ stp x20, x19, [sp, #0x20];
    /* 0xc3682c */ mov x29, sp;
    /* 0xc36830 */ ldr x8, [x1];
    /* 0xc36834 */ mov x19, x0;
    /* 0xc36838 */ mov x0, x1;
    /* 0xc3683c */ mov x21, x1;
    /* 0xc36840 */ ldr x8, [x8, #0xa8];
    /* 0xc36844 */ blr x8;
    /* 0xc36848 */ ldr x8, [x21];
    sub_5a8de8();
    return x0;
}
