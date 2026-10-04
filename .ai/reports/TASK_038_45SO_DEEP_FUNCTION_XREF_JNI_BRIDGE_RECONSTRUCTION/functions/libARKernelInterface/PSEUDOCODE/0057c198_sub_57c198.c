// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57c198
// Recovered Name: sub_57c198
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57c198 | Size: 40 bytes | SHA256: 29d88ac6b576939bf0f0c2d65b8992b442ebf230328c81d3b09e1e67628be094
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetShoulderRect(JIFFFF)V (table at 0x10cea08)

jlong sub_57c198(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x57c198 */ cbz x2, #0x57c1bc;
    /* 0x57c19c */ cmp w3, #9;
    /* 0x57c1a0 */ b.hi #0x57c1bc;
    /* 0x57c1a4 */ mov w8, #0xa0;
    /* 0x57c1a8 */ mov w9, #1;
    /* 0x57c1ac */ umaddl x8, w3, w8, x2;
    /* 0x57c1b0 */ strb w9, [x8, #0x20];
    /* 0x57c1b4 */ stp s0, s1, [x8, #0x24];
    /* 0x57c1b8 */ stp s2, s3, [x8, #0x2c];
    return x0;
}
