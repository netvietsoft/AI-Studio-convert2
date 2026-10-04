// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56b024
// Recovered Name: sub_56b024
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56b024 | Size: 28 bytes | SHA256: 42684127e35a0817fbcf081f152a648abcaea0b0630e4181cadfdb4ddd2bd909
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetHeadPoints(JI)[F (table at 0x10cd0a0)

jlong sub_56b024(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x56b024 */ cbz x2, #0x56b0ac;
    /* 0x56b028 */ cmp w3, #0x13;
    /* 0x56b02c */ b.hi #0x56b0ac;
    /* 0x56b030 */ mov w8, #0x5c0;
    /* 0x56b034 */ umaddl x8, w3, w8, x2;
    /* 0x56b038 */ ldrb w8, [x8, #0x1d4];
    /* 0x56b03c */ cbz w8, #0x56b0ac;
}
