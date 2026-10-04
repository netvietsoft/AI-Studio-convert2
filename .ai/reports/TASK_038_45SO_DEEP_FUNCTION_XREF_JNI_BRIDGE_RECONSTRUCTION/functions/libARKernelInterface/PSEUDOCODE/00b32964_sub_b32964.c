// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb32964
// Recovered Name: sub_b32964
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb32964 | Size: 548 bytes | SHA256: 0ce68b4019352f378ffd259f0b10c63fe5f7d25578300219eb5adf42979eefb1
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   "Shaders/HairSoft/MTFilter_gradient.fs"
//   "Shaders/HairSoft/MTFilter_gradient.vs"
//   "texelSize"

void sub_b32964(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 137 instructions
    /* 0xb32964 */ stp x29, x30, [sp, #0x60];
    /* 0xb32968 */ str x25, [sp, #0x70];
    /* 0xb3296c */ stp x24, x23, [sp, #0x80];
    /* 0xb32970 */ stp x22, x21, [sp, #0x90];
    /* 0xb32974 */ stp x20, x19, [sp, #0xa0];
    /* 0xb32978 */ add x29, sp, #0x60;
    /* 0xb3297c */ mrs x22, tpidr_el0;
    /* 0xb32980 */ mov x19, x0;
    /* 0xb32984 */ ldr x8, [x22, #0x28];
    /* 0xb32988 */ stur x8, [x29, #-8];
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
