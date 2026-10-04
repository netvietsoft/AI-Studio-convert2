// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a348
// Recovered Name: sub_58a348
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a348 | Size: 20 bytes | SHA256: 1013fef379e7c8eee1162e43a621783372a76abcc97f4e4b317e48347c707c4c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetColorType(J)I (table at 0x10d01f0)

jlong sub_58a348(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x58a348 */ cbz x2, #0x58a354;
    /* 0x58a34c */ mov x0, x2;
    /* 0x58a350 */ b #0xa2c204;
    /* 0x58a354 */ mov w0, wzr;
    return x0;
}
