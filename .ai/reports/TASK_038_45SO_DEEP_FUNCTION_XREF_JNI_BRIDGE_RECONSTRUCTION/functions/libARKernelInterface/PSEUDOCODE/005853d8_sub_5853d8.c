// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5853d8
// Recovered Name: sub_5853d8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5853d8 | Size: 20 bytes | SHA256: 7a7afd8201d0f65bc2a52ebb6825c675ca38f55fd8d588808ae1009a9c081f3b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeTouchEnd(JFFI)V (table at 0x10cf9c8)

jlong sub_5853d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5853d8 */ cbz x2, #0x5853e8;
    /* 0x5853dc */ mov x0, x2;
    /* 0x5853e0 */ mov w1, w3;
    /* 0x5853e4 */ b #0x583ecc;
    return x0;
}
