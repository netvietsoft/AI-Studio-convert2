// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5853c4
// Recovered Name: sub_5853c4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5853c4 | Size: 20 bytes | SHA256: 4ad1fa7e88b5fbe8a1f35d6e4a901874c5a8ef64641ed1397ca3613a0d0aac79
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeTouchMove(JFFI)V (table at 0x10cf9b0)

jlong sub_5853c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5853c4 */ cbz x2, #0x5853d4;
    /* 0x5853c8 */ mov x0, x2;
    /* 0x5853cc */ mov w1, w3;
    /* 0x5853d0 */ b #0x583ec4;
    return x0;
}
