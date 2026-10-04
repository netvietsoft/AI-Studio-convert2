// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56aab4
// Recovered Name: sub_56aab4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56aab4 | Size: 68 bytes | SHA256: 8ba2183d8f5c5b8040f05f59a4233d39c601d68597cdbaf696f161c2a0203dc6
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetChildAgeType(JI)I (table at 0x10ccfe0)

jlong sub_56aab4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x56aab4 */ mov w0, #-1;
    /* 0x56aab8 */ cbz x2, #0x56aaf4;
    /* 0x56aabc */ cmp w3, #0x13;
    /* 0x56aac0 */ b.hi #0x56aaf4;
    /* 0x56aac4 */ mov w8, #0x5c0;
    /* 0x56aac8 */ umaddl x8, w3, w8, x2;
    /* 0x56aacc */ ldrb w8, [x8, #0x80];
    /* 0x56aad0 */ cbz w8, #0x56aaf4;
    /* 0x56aad4 */ mov w8, w3;
    /* 0x56aad8 */ mov w9, #0x5c0;
    /* 0x56aadc */ umaddl x8, w8, w9, x2;
    return x0;
}
