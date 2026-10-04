// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb33130
// Recovered Name: sub_b33130
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb33130 | Size: 524 bytes | SHA256: 05c04dade2ab590479cdb38554d3504ccd46ec848d02ef63698aff2596a5820f
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   "Shaders/HairSoft/MTFilter_PsFilterColor.fs"
//   "Shaders/HairSoft/MTFilter_PsFilterColor.vs"
//   "alpha"

void sub_b33130(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 131 instructions
    /* 0xb33130 */ stp x29, x30, [sp, #0x60];
    /* 0xb33134 */ str x25, [sp, #0x70];
    /* 0xb33138 */ stp x24, x23, [sp, #0x80];
    /* 0xb3313c */ stp x22, x21, [sp, #0x90];
    /* 0xb33140 */ stp x20, x19, [sp, #0xa0];
    /* 0xb33144 */ add x29, sp, #0x60;
    /* 0xb33148 */ mrs x22, tpidr_el0;
    /* 0xb3314c */ mov x19, x0;
    /* 0xb33150 */ ldr x8, [x22, #0x28];
    /* 0xb33154 */ stur x8, [x29, #-8];
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
