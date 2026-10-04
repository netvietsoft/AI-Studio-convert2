// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a588
// Recovered Name: sub_58a588
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a588 | Size: 20 bytes | SHA256: db3b5a81d609416a91479133ed6fd6389d75dd9ba0d7b25d32e7c323e6cd8836
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetCurrentW(J)F (table at 0x10d0358)

jlong sub_58a588(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a588 */ cbz x2, #0x58a594;
    /* 0x58a58c */ mov x0, x2;
    /* 0x58a590 */ b #0xa2d484;
    /* 0x58a594 */ movi d0, #0000000000000000;
    return x0;
}
