// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56d848
// Recovered Name: sub_56d848
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56d848 | Size: 40 bytes | SHA256: 863bb3d5ac3f1d5d5f497879d41cf04fc9fffad00799b866410535d251b0441e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetFoodRect(JIFFFF)V (table at 0x10cd388)

jlong sub_56d848(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x56d848 */ cbz x2, #0x56d86c;
    /* 0x56d84c */ cmp w3, #9;
    /* 0x56d850 */ b.hi #0x56d86c;
    /* 0x56d854 */ mov w8, #0x34;
    /* 0x56d858 */ mov w9, #1;
    /* 0x56d85c */ umaddl x8, w3, w8, x2;
    /* 0x56d860 */ strb w9, [x8, #0x20];
    /* 0x56d864 */ stp s0, s1, [x8, #0x24];
    /* 0x56d868 */ stp s2, s3, [x8, #0x2c];
    return x0;
}
