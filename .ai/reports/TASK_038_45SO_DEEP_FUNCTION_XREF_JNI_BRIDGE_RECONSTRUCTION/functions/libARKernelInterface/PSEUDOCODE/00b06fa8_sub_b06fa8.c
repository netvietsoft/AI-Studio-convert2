// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb06fa8
// Recovered Name: sub_b06fa8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb06fa8 | Size: 512 bytes | SHA256: f083a3da49f0cfdf670942c57d5235e190c938026e4b551a0e7302e45f818678
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   "Shaders/Anatta/FaceAdjustment/MTFilter_Blur.fs"
//   "Shaders/Anatta/FaceAdjustment/MTFilter_Blur.vs"

void sub_b06fa8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 128 instructions
    /* 0xb06fa8 */ stp x29, x30, [sp, #0x60];
    /* 0xb06fac */ stp x26, x25, [sp, #0x70];
    /* 0xb06fb0 */ stp x24, x23, [sp, #0x80];
    /* 0xb06fb4 */ stp x22, x21, [sp, #0x90];
    /* 0xb06fb8 */ stp x20, x19, [sp, #0xa0];
    /* 0xb06fbc */ add x29, sp, #0x60;
    /* 0xb06fc0 */ mrs x24, tpidr_el0;
    /* 0xb06fc4 */ mov x19, x0;
    /* 0xb06fc8 */ ldr x8, [x24, #0x28];
    /* 0xb06fcc */ stur x8, [x29, #-8];
    sub_69c64c();
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
