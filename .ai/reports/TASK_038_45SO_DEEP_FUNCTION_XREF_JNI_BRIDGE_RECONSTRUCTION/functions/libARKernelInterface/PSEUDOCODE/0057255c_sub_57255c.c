// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57255c
// Recovered Name: sub_57255c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57255c | Size: 40 bytes | SHA256: 64b2a1bef887b104b5d82c64e8b37fc4abc85e04f999469da7d0ed04c35ca184
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetHandRect(JIFFFF)V (table at 0x10cd820)

jlong sub_57255c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x57255c */ cbz x2, #0x572580;
    /* 0x572560 */ cmp w3, #9;
    /* 0x572564 */ b.hi #0x572580;
    /* 0x572568 */ mov w8, #0xec;
    /* 0x57256c */ mov w9, #1;
    /* 0x572570 */ umaddl x8, w3, w8, x2;
    /* 0x572574 */ strb w9, [x8, #0x20];
    /* 0x572578 */ stp s0, s1, [x8, #0x24];
    /* 0x57257c */ stp s2, s3, [x8, #0x2c];
    return x0;
}
