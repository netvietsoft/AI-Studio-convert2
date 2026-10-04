// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57a318
// Recovered Name: sub_57a318
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57a318 | Size: 16 bytes | SHA256: 6e79b6a5e8b39edb92060afd154567da9b4b89bf5b9119542a2d69b49f89a635
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeReplayBGM(J)V (table at 0x10ce5a0)

jlong sub_57a318(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x57a318 */ cbz x2, #0x57a324;
    /* 0x57a31c */ mov x0, x2;
    /* 0x57a320 */ b #0x90acd0;
    return x0;
}
