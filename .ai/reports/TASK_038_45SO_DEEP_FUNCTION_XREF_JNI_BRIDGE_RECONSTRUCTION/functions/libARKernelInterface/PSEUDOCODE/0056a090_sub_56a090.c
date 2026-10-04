// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a090
// Recovered Name: sub_56a090
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a090 | Size: 40 bytes | SHA256: dc2ec0e389a5259b3fea17ea7db2717b3b52752f851f8e9b6b8d7fe05845cce4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFaceRect(JIFFFF)V (table at 0x10cce48)

jlong sub_56a090(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x56a090 */ cbz x2, #0x56a0b4;
    /* 0x56a094 */ cmp w3, #0x13;
    /* 0x56a098 */ b.hi #0x56a0b4;
    /* 0x56a09c */ mov w8, #0x5c0;
    /* 0x56a0a0 */ mov w9, #1;
    /* 0x56a0a4 */ umaddl x8, w3, w8, x2;
    /* 0x56a0a8 */ strb w9, [x8, #0x30];
    /* 0x56a0ac */ stp s0, s1, [x8, #0x34];
    /* 0x56a0b0 */ stp s2, s3, [x8, #0x3c];
    return x0;
}
