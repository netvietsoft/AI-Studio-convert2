// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56ac28
// Recovered Name: sub_56ac28
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56ac28 | Size: 40 bytes | SHA256: 170d53612cae1511178d4b6ebef54e891b84282ec941b38e8387b5ed551040f4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetNeckRect(JIFFFF)V (table at 0x10cd028)

jlong sub_56ac28(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x56ac28 */ cbz x2, #0x56ac4c;
    /* 0x56ac2c */ cmp w3, #0x13;
    /* 0x56ac30 */ b.hi #0x56ac4c;
    /* 0x56ac34 */ mov w8, #0x5c0;
    /* 0x56ac38 */ mov w9, #1;
    /* 0x56ac3c */ umaddl x8, w3, w8, x2;
    /* 0x56ac40 */ strb w9, [x8, #0xa4];
    /* 0x56ac44 */ stp s0, s1, [x8, #0xa8];
    /* 0x56ac48 */ stp s2, s3, [x8, #0xb0];
    return x0;
}
