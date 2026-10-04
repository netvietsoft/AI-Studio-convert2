// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb32b88
// Recovered Name: sub_b32b88
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb32b88 | Size: 496 bytes | SHA256: f7430117fa0dddd8067a98cccc0b860384b6742e2fa40ff795e16dcbbdc6829c
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   "Shaders/HairSoft/MTFilter_HairSoftMix.fs"
//   "Shaders/HairSoft/MTFilter_HairSoftMix.vs"

void sub_b32b88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 124 instructions
    /* 0xb32b88 */ stp x29, x30, [sp, #0x60];
    /* 0xb32b8c */ str x25, [sp, #0x70];
    /* 0xb32b90 */ stp x24, x23, [sp, #0x80];
    /* 0xb32b94 */ stp x22, x21, [sp, #0x90];
    /* 0xb32b98 */ stp x20, x19, [sp, #0xa0];
    /* 0xb32b9c */ add x29, sp, #0x60;
    /* 0xb32ba0 */ mrs x22, tpidr_el0;
    /* 0xb32ba4 */ mov x19, x0;
    /* 0xb32ba8 */ ldr x8, [x22, #0x28];
    /* 0xb32bac */ stur x8, [x29, #-8];
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
