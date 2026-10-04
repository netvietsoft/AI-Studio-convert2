// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xf383c
// Recovered Name: _ZN14MTFilterKernel16MTSoftHairFilterD1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xf383c | Size: 256 bytes | SHA256: e543fc4c99d275b264bf382a7510d95e63684ccc664162d6230c250967afa370
// Callers: 1 | Callees: 1 | Imports: 1

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv

void _ZN14MTFilterKernel16MTSoftHairFilterD1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 64 instructions
    /* 0xf383c */ stp x29, x30, [sp, #-0x20]!;
    /* 0xf3840 */ stp x20, x19, [sp, #0x10];
    /* 0xf3844 */ mov x29, sp;
    /* 0xf3848 */ adrp x8, #0x1c5000;
    /* 0xf384c */ mov x19, x0;
    /* 0xf3850 */ ldr x8, [x8, #0x5f8];
    /* 0xf3854 */ ldr x20, [x0, #0x220];
    /* 0xf3858 */ add x8, x8, #0x10;
    /* 0xf385c */ str x8, [x0];
    /* 0xf3860 */ cbz x20, #0xf388c;
    /* 0xf3864 */ add x1, x20, #8;
    sub_1afd20();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_1afd20();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_1afd20();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_1afd20();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
}
