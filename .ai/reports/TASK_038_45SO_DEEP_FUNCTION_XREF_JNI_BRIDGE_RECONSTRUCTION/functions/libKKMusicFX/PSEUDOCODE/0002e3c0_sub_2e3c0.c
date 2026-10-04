// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x2e3c0
// Recovered Name: sub_2e3c0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2e3c0 | Size: 36 bytes | SHA256: 63d0b6230922a432a94d9ef67ea68db20de26870b84c4145e80d43c53fe9365e
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void sub_2e3c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2e3c0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2e3c4 */ str x19, [sp, #0x10];
    /* 0x2e3c8 */ mov x29, sp;
    /* 0x2e3cc */ mov x19, x0;
    sub_2e2d0();
    /* 0x2e3d4 */ mov x0, x19;
    /* 0x2e3d8 */ ldr x19, [sp, #0x10];
    /* 0x2e3dc */ ldp x29, x30, [sp], #0x20;
    /* 0x2e3e0 */ b #0x7a870;
}
