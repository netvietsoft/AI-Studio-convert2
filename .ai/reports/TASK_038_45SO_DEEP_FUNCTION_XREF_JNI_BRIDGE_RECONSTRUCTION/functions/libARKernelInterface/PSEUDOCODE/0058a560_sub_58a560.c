// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a560
// Recovered Name: sub_58a560
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a560 | Size: 20 bytes | SHA256: cf835bfebdb044ef4305ac6e4e0a01c8c74316267a704c7ff1433a6d11476d16
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetCurrentY(J)F (table at 0x10d0328)

jlong sub_58a560(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a560 */ cbz x2, #0x58a56c;
    /* 0x58a564 */ mov x0, x2;
    /* 0x58a568 */ b #0xa2d474;
    /* 0x58a56c */ movi d0, #0000000000000000;
    return x0;
}
