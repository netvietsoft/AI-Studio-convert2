// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb33398
// Recovered Name: sub_b33398
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb33398 | Size: 504 bytes | SHA256: 07a5ff49776f609f84bd6ea5dbc6be4eb671aa56f33ec7fd90a979163ad033ab
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, __stack_chk_fail, memmove
// Strings referenced:
//   "Shaders/HairSoft/MTFilter_Mix.fs"
//   "Shaders/HairSoft/MTFilter_Mix.vs"
//   "alpha"

void sub_b33398(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 126 instructions
    /* 0xb33398 */ stp x29, x30, [sp, #0x60];
    /* 0xb3339c */ str x25, [sp, #0x70];
    /* 0xb333a0 */ stp x24, x23, [sp, #0x80];
    /* 0xb333a4 */ stp x22, x21, [sp, #0x90];
    /* 0xb333a8 */ stp x20, x19, [sp, #0xa0];
    /* 0xb333ac */ add x29, sp, #0x60;
    /* 0xb333b0 */ mrs x22, tpidr_el0;
    /* 0xb333b4 */ mov x19, x0;
    /* 0xb333b8 */ ldr x8, [x22, #0x28];
    /* 0xb333bc */ stur x8, [x29, #-8];
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
