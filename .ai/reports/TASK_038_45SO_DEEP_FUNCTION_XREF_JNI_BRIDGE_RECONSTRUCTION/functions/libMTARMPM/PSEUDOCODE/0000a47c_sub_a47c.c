// Library: libMTARMPM.so
// Function ID: libMTARMPM::0xa47c
// Recovered Name: sub_a47c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa47c | Size: 160 bytes | SHA256: eb32aa7cd1fba56bcdfc284029a2d1a91023a16b6353472232a78bd959475b32
// Callers: 0 | Callees: 5 | Imports: 2

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, __stack_chk_fail

void sub_a47c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 40 instructions
    /* 0xa47c */ stp x29, x30, [sp, #0x20];
    /* 0xa480 */ stp x20, x19, [sp, #0x30];
    /* 0xa484 */ add x29, sp, #0x20;
    /* 0xa488 */ mrs x20, tpidr_el0;
    /* 0xa48c */ ldr x8, [x20, #0x28];
    /* 0xa490 */ stur x8, [x29, #-8];
    /* 0xa494 */ add x8, sp, #8;
    sub_e970();
    /* 0xa49c */ ldr x0, [sp, #8];
    sub_ed24();
    /* 0xa4a4 */ ldr x19, [sp, #0x10];
    sub_12cb0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    return x0;
    sub_a378();
    sub_12e14();
    __stack_chk_fail();
}
