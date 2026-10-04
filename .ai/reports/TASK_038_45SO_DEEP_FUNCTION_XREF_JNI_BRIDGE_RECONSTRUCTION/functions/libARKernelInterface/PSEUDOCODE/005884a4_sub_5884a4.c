// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5884a4
// Recovered Name: sub_5884a4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5884a4 | Size: 60 bytes | SHA256: 0cb849b311f19e9b83dab62b05b8cb7611eff8174848105ae1e7bca117ebba52
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nativeGetIsStrikeThrough(J)Z (table at 0x10cfe00)

jlong sub_5884a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x5884a4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x5884a8 */ mov x29, sp;
    /* 0x5884ac */ cbz x2, #0x5884d0;
    /* 0x5884b0 */ ldr x0, [x2, #0x7a0];
    /* 0x5884b4 */ cbz x0, #0x5884dc;
    /* 0x5884b8 */ ldr x8, [x0];
    /* 0x5884bc */ ldr x8, [x8, #0x30];
    /* 0x5884c0 */ blr x8;
    /* 0x5884c4 */ and w0, w0, #1;
    /* 0x5884c8 */ ldp x29, x30, [sp], #0x10;
    return x0;
    return x0;
    sub_581efc();
}
