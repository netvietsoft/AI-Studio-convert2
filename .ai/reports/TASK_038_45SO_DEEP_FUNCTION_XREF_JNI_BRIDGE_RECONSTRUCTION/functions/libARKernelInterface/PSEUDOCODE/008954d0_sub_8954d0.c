// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x8954d0
// Recovered Name: sub_8954d0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8954d0 | Size: 492 bytes | SHA256: b0b2bb291fc79b48f2acc71613a4b9d337ddd58896112fef9bda34a0d84f7454
// Callers: 0 | Callees: 3 | Imports: 3

// Calls external APIs: _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   "Shaders/MTFilter_HairMaskMix.fs"
//   "Shaders/MTFilter_HairMaskMix.vs"

void sub_8954d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 123 instructions
    /* 0x8954d0 */ stp x29, x30, [sp, #0x60];
    /* 0x8954d4 */ stp x26, x25, [sp, #0x70];
    /* 0x8954d8 */ stp x24, x23, [sp, #0x80];
    /* 0x8954dc */ stp x22, x21, [sp, #0x90];
    /* 0x8954e0 */ stp x20, x19, [sp, #0xa0];
    /* 0x8954e4 */ add x29, sp, #0x60;
    /* 0x8954e8 */ mrs x24, tpidr_el0;
    /* 0x8954ec */ mov x19, x0;
    /* 0x8954f0 */ mov w0, wzr;
    /* 0x8954f4 */ ldr x8, [x24, #0x28];
    /* 0x8954f8 */ stur x8, [x29, #-8];
    sub_5a6eb4();
    sub_58f19c();
    sub_5abbf8();
    memmove();
    sub_5abbf8();
    memmove();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
