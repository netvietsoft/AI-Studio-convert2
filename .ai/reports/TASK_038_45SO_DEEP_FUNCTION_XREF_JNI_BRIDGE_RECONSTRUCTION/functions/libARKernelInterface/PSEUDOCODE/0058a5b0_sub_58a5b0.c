// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a5b0
// Recovered Name: sub_58a5b0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a5b0 | Size: 20 bytes | SHA256: a2e89587498b315921c62be132db38c0a5b7a2221b1aa3a3c7bb753a3ab250ec
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetDefaultY(J)F (table at 0x10d0388)

jlong sub_58a5b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a5b0 */ cbz x2, #0x58a5bc;
    /* 0x58a5b4 */ mov x0, x2;
    /* 0x58a5b8 */ b #0xa2d494;
    /* 0x58a5bc */ movi d0, #0000000000000000;
    return x0;
}
