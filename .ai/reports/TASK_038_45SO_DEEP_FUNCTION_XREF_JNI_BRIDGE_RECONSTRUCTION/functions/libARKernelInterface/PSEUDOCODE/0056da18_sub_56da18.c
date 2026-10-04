// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56da18
// Recovered Name: sub_56da18
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56da18 | Size: 52 bytes | SHA256: eb1ba1b81d717f1179a243db87c2dce1049774379b24429394f2cf7de8431681
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFoodLabelScore(JI)F (table at 0x10cd430)

jlong sub_56da18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x56da18 */ movi d0, #0000000000000000;
    /* 0x56da1c */ cbz x2, #0x56da48;
    /* 0x56da20 */ cmp w3, #9;
    /* 0x56da24 */ b.hi #0x56da48;
    /* 0x56da28 */ mov w8, #0x34;
    /* 0x56da2c */ umaddl x8, w3, w8, x2;
    /* 0x56da30 */ ldrb w8, [x8, #0x44];
    /* 0x56da34 */ cbz w8, #0x56da48;
    /* 0x56da38 */ mov w8, w3;
    /* 0x56da3c */ mov w9, #0x34;
    /* 0x56da40 */ umaddl x8, w8, w9, x2;
    return x0;
}
