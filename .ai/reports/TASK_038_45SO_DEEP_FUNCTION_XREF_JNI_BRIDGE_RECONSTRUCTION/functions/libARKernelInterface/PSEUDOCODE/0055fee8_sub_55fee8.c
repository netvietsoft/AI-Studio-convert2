// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55fee8
// Recovered Name: sub_55fee8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55fee8 | Size: 24 bytes | SHA256: 9023ea821f42a6523853c9947f2d9c71b012e70aed41e0b2b0f234e7d36d6535
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetGyroscopeQuaternionData(JFFFF)V (table at 0x10cc3f8)

jlong sub_55fee8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x55fee8 */ cbz x2, #0x55fefc;
    /* 0x55feec */ mov w8, #1;
    /* 0x55fef0 */ stp s0, s1, [x2, #0x1c];
    /* 0x55fef4 */ strb w8, [x2, #0x18];
    /* 0x55fef8 */ stp s2, s3, [x2, #0x24];
    return x0;
}
