// Library: libMTARMPM.so
// Function ID: libMTARMPM::0xa3cc
// Recovered Name: sub_a3cc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa3cc | Size: 172 bytes | SHA256: 3b39f5a78d12f808da4e0bea262ddff8082608f81c73aa9ab6783f5ff8100467
// Callers: 0 | Callees: 5 | Imports: 2

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, __stack_chk_fail

void sub_a3cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 43 instructions
    /* 0xa3cc */ stp x29, x30, [sp, #0x20];
    /* 0xa3d0 */ stp x20, x19, [sp, #0x30];
    /* 0xa3d4 */ add x29, sp, #0x20;
    /* 0xa3d8 */ mrs x20, tpidr_el0;
    /* 0xa3dc */ mov w19, w0;
    /* 0xa3e0 */ ldr x8, [x20, #0x28];
    /* 0xa3e4 */ stur x8, [x29, #-8];
    /* 0xa3e8 */ add x8, sp, #8;
    sub_e970();
    /* 0xa3f0 */ ldr x0, [sp, #8];
    /* 0xa3f4 */ cmp w19, #1;
    sub_ecb8();
    sub_12cb0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    return x0;
    sub_a378();
    sub_12e14();
    __stack_chk_fail();
}
