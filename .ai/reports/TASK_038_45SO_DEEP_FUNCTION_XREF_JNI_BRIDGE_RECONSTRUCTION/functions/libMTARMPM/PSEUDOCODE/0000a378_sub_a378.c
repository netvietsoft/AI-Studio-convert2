// Library: libMTARMPM.so
// Function ID: libMTARMPM::0xa378
// Recovered Name: sub_a378
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa378 | Size: 80 bytes | SHA256: a49892782905d352a319bdcdebb8a6ba777b8ba1846291b6a187b46a6efdbd32
// Callers: 5 | Callees: 1 | Imports: 1

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv

void sub_a378(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0xa378 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xa37c */ str x19, [sp, #0x10];
    /* 0xa380 */ mov x29, sp;
    /* 0xa384 */ ldr x19, [x0, #8];
    /* 0xa388 */ cbz x19, #0xa39c;
    /* 0xa38c */ add x1, x19, #8;
    /* 0xa390 */ mov x0, #-1;
    sub_12cb0();
    /* 0xa398 */ cbz x0, #0xa3a8;
    /* 0xa39c */ ldr x19, [sp, #0x10];
    /* 0xa3a0 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
