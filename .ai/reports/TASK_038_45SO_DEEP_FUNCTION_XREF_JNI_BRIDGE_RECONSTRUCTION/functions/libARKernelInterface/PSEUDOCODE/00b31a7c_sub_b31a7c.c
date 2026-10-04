// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb31a7c
// Recovered Name: sub_b31a7c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb31a7c | Size: 536 bytes | SHA256: cf24ea12ab3a0fb4730137bb16a7f719b887eccbf140dce42784e3f18288a15d
// Callers: 0 | Callees: 1 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "EnableSamllFaceReduceAlpha"
//   "HairSoft"
//   "HairsoftAlpha"
//   "HairsoftAlphaSecond"
//   "MergesrcAlpha"

void sub_b31a7c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 134 instructions
    /* 0xb31a7c */ stp x29, x30, [sp, #0x20];
    /* 0xb31a80 */ stp x22, x21, [sp, #0x30];
    /* 0xb31a84 */ stp x20, x19, [sp, #0x40];
    /* 0xb31a88 */ add x29, sp, #0x20;
    /* 0xb31a8c */ mrs x22, tpidr_el0;
    /* 0xb31a90 */ mov x19, x1;
    /* 0xb31a94 */ mov x20, x0;
    /* 0xb31a98 */ ldr x8, [x22, #0x28];
    /* 0xb31a9c */ mov x0, x19;
    /* 0xb31aa0 */ stur x8, [x29, #-8];
    /* 0xb31aa4 */ ldr x8, [x1];
    sub_58f19c();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
