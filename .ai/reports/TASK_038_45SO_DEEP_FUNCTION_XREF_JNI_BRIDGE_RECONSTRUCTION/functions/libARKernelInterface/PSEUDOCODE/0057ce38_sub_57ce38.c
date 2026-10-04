// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57ce38
// Recovered Name: sub_57ce38
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57ce38 | Size: 24 bytes | SHA256: bd4dfca2a5b24fd332c5eafdb94c3c641cba61219063b5093e6224870b1e429f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetTextureValidRect(JIIIII)V (table at 0x10ceb40)

jlong sub_57ce38(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x57ce38 */ cbz x2, #0x57ce4c;
    /* 0x57ce3c */ mov w8, #0x64;
    /* 0x57ce40 */ smaddl x8, w3, w8, x2;
    /* 0x57ce44 */ stp w4, w5, [x8, #0x10];
    /* 0x57ce48 */ stp w6, w7, [x8, #0x18];
    return x0;
}
