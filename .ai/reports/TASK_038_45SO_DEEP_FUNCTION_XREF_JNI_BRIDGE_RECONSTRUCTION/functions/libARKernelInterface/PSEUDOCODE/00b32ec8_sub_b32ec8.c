// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb32ec8
// Recovered Name: sub_b32ec8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb32ec8 | Size: 524 bytes | SHA256: e58c63d1caa1a8ce565364d52d90accf07fecfd26cf4b95ae1d6a33040a9100b
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   "Shaders/HairSoft/MTFilter_PsSoftLightr.fs"
//   "Shaders/HairSoft/MTFilter_PsSoftLightr.vs"
//   "alpha"

void sub_b32ec8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 131 instructions
    /* 0xb32ec8 */ stp x29, x30, [sp, #0x60];
    /* 0xb32ecc */ str x25, [sp, #0x70];
    /* 0xb32ed0 */ stp x24, x23, [sp, #0x80];
    /* 0xb32ed4 */ stp x22, x21, [sp, #0x90];
    /* 0xb32ed8 */ stp x20, x19, [sp, #0xa0];
    /* 0xb32edc */ add x29, sp, #0x60;
    /* 0xb32ee0 */ mrs x22, tpidr_el0;
    /* 0xb32ee4 */ mov x19, x0;
    /* 0xb32ee8 */ ldr x8, [x22, #0x28];
    /* 0xb32eec */ stur x8, [x29, #-8];
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
