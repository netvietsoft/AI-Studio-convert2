// Library: libmanis_npu_adapter.so
// Function ID: libmanis_npu_adapter::0x71f8c
// Recovered Name: sub_71f8c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x71f8c | Size: 80 bytes | SHA256: b6182bd717799080886f94a8ececcb15c3a87093962687a0062f9980cff151fb
// Callers: 80 | Callees: 1 | Imports: 1

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv

void sub_71f8c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0x71f8c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x71f90 */ str x19, [sp, #0x10];
    /* 0x71f94 */ mov x29, sp;
    /* 0x71f98 */ ldr x19, [x0, #8];
    /* 0x71f9c */ cbz x19, #0x71fb0;
    /* 0x71fa0 */ add x1, x19, #8;
    /* 0x71fa4 */ mov x0, #-1;
    sub_eb300();
    /* 0x71fac */ cbz x0, #0x71fbc;
    /* 0x71fb0 */ ldr x19, [sp, #0x10];
    /* 0x71fb4 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
