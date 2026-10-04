// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a6ac
// Recovered Name: sub_58a6ac
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a6ac | Size: 20 bytes | SHA256: 92283c1a23de15a925e44b0d6c15aae6490e570d610b879725748be3aebf6f79
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetMaxValue(J)F (table at 0x10d0448)

jlong sub_58a6ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a6ac */ cbz x2, #0x58a6b8;
    /* 0x58a6b0 */ mov x0, x2;
    /* 0x58a6b4 */ b #0xa2d4f8;
    /* 0x58a6b8 */ movi d0, #0000000000000000;
    return x0;
}
