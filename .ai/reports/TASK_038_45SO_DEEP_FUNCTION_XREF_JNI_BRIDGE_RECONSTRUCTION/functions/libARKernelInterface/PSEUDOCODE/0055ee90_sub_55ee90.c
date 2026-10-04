// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55ee90
// Recovered Name: sub_55ee90
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55ee90 | Size: 40 bytes | SHA256: dcb2a0fab7381e422600412e99cd21b1fe479f4ecae8a15abcb29ceb217ecded
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetAnimalRect(JIFFFF)V (table at 0x10cc260)

jlong sub_55ee90(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x55ee90 */ cbz x2, #0x55eeb4;
    /* 0x55ee94 */ cmp w3, #9;
    /* 0x55ee98 */ b.hi #0x55eeb4;
    /* 0x55ee9c */ mov w8, #0x140;
    /* 0x55eea0 */ mov w9, #1;
    /* 0x55eea4 */ umaddl x8, w3, w8, x2;
    /* 0x55eea8 */ strb w9, [x8, #0x28];
    /* 0x55eeac */ stp s0, s1, [x8, #0x2c];
    /* 0x55eeb0 */ stp s2, s3, [x8, #0x34];
    return x0;
}
