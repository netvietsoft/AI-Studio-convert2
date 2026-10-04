// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a59c
// Recovered Name: sub_58a59c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a59c | Size: 20 bytes | SHA256: d1aaf598b02b219f1fb51b052ad616da1578e74c566039744f09bff5b813e2f4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetDefaultX(J)F (table at 0x10d0370)

jlong sub_58a59c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a59c */ cbz x2, #0x58a5a8;
    /* 0x58a5a0 */ mov x0, x2;
    /* 0x58a5a4 */ b #0xa2d48c;
    /* 0x58a5a8 */ movi d0, #0000000000000000;
    return x0;
}
