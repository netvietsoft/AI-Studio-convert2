// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a528
// Recovered Name: sub_58a528
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a528 | Size: 16 bytes | SHA256: fc0b08dcbe403e91daa0f4e98a244910e06ff82dcfec09e1dee5fc9bc62b1b96
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCurrentValueXYZW(JFFFF)V (table at 0x10d02e0)

jlong sub_58a528(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x58a528 */ cbz x2, #0x58a534;
    /* 0x58a52c */ mov x0, x2;
    /* 0x58a530 */ b #0xa2d428;
    return x0;
}
