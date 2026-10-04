// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57a348
// Recovered Name: sub_57a348
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57a348 | Size: 20 bytes | SHA256: 97ada736b8ae2ad103abbf2d88f691c0bcccb20fe8b0a6ac40fe104c037dbd3a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetBGMPosition(J)F (table at 0x10ce5e8)

jlong sub_57a348(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57a348 */ cbz x2, #0x57a354;
    /* 0x57a34c */ mov x0, x2;
    /* 0x57a350 */ b #0x90ae80;
    /* 0x57a354 */ movi d0, #0000000000000000;
    return x0;
}
