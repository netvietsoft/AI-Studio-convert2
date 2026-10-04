// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a6c0
// Recovered Name: sub_58a6c0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a6c0 | Size: 20 bytes | SHA256: 44aa9603a294a68b654f397fc2e85c23a46dec78c7773b6f6f974f796cd781ce
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetMinValue(J)F (table at 0x10d0460)

jlong sub_58a6c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a6c0 */ cbz x2, #0x58a6cc;
    /* 0x58a6c4 */ mov x0, x2;
    /* 0x58a6c8 */ b #0xa2d500;
    /* 0x58a6cc */ movi d0, #0000000000000000;
    return x0;
}
