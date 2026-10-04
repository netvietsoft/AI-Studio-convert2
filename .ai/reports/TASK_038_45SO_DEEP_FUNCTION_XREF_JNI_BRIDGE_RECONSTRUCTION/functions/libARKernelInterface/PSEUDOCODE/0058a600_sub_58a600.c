// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a600
// Recovered Name: sub_58a600
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a600 | Size: 20 bytes | SHA256: b09eb81d4e8071fe75e77cd2fb0678b52a44dfe9ce86d787fdefc43919d0008c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetMinValue(J)F (table at 0x10d03e8)

jlong sub_58a600(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a600 */ cbz x2, #0x58a60c;
    /* 0x58a604 */ mov x0, x2;
    /* 0x58a608 */ b #0xa2d4b4;
    /* 0x58a60c */ movi d0, #0000000000000000;
    return x0;
}
