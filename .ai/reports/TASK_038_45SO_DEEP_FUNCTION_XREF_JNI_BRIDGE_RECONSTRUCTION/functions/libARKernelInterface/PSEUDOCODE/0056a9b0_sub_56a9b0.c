// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a9b0
// Recovered Name: sub_56a9b0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a9b0 | Size: 60 bytes | SHA256: 1bfb2e7c957e8beb166580e5a0b9f98f98c10ee1c6f4feca74ec8963069e0499
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetSkin(JII)V (table at 0x10ccf68)

jlong sub_56a9b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x56a9b0 */ cbz x2, #0x56a9e8;
    /* 0x56a9b4 */ cmp w3, #0x13;
    /* 0x56a9b8 */ b.hi #0x56a9e8;
    /* 0x56a9bc */ mov w8, #0x5c0;
    /* 0x56a9c0 */ add w9, w4, #1;
    /* 0x56a9c4 */ mov w10, #1;
    /* 0x56a9c8 */ umaddl x8, w3, w8, x2;
    /* 0x56a9cc */ cmp w9, #5;
    /* 0x56a9d0 */ strb w10, [x8, #0x5d0];
    /* 0x56a9d4 */ b.hi #0x56a9e8;
    /* 0x56a9d8 */ mov w8, w3;
    return x0;
}
