// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x903cf0
// Recovered Name: sub_903cf0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x903cf0 | Size: 628 bytes | SHA256: 81f18963d211f7d55994430a5ab1f8651b05c5ac87489665cd878cc9377ef229
// Callers: 0 | Callees: 5 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "VideoFluffyHairSlider"
//   "pNX"

void sub_903cf0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 157 instructions
    /* 0x903cf0 */ stp x29, x30, [sp, #0x90];
    /* 0x903cf4 */ stp x24, x23, [sp, #0xa0];
    /* 0x903cf8 */ stp x22, x21, [sp, #0xb0];
    /* 0x903cfc */ stp x20, x19, [sp, #0xc0];
    /* 0x903d00 */ add x29, sp, #0x90;
    /* 0x903d04 */ mrs x23, tpidr_el0;
    /* 0x903d08 */ mov x19, x0;
    /* 0x903d0c */ ldr x8, [x23, #0x28];
    /* 0x903d10 */ stur x8, [x29, #-8];
    sub_8dde24();
    /* 0x903d18 */ mov w20, w0;
    sub_58f19c();
    sub_58f19c();
    sub_58f19c();
    _Znwm();
    sub_a048d8();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_7593fc();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
    sub_7593e8();
}
