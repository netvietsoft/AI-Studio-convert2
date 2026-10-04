// Library: libMTARMPM.so
// Function ID: libMTARMPM::0xa2c8
// Recovered Name: sub_a2c8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa2c8 | Size: 176 bytes | SHA256: e7e900d57acb758b6062342014f4290ed4f1312aa5f1cf995ecd86b2701c3f78
// Callers: 0 | Callees: 5 | Imports: 2

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, __stack_chk_fail

void sub_a2c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0xa2c8 */ stp x29, x30, [sp, #0x20];
    /* 0xa2cc */ str x21, [sp, #0x30];
    /* 0xa2d0 */ stp x20, x19, [sp, #0x40];
    /* 0xa2d4 */ add x29, sp, #0x20;
    /* 0xa2d8 */ mrs x21, tpidr_el0;
    /* 0xa2dc */ ldr x8, [x21, #0x28];
    /* 0xa2e0 */ stur x8, [x29, #-8];
    /* 0xa2e4 */ add x8, sp, #8;
    sub_e970();
    /* 0xa2ec */ ldr x0, [sp, #8];
    sub_eb5c();
    sub_12cb0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    return x0;
    sub_a378();
    sub_12e14();
    __stack_chk_fail();
}
