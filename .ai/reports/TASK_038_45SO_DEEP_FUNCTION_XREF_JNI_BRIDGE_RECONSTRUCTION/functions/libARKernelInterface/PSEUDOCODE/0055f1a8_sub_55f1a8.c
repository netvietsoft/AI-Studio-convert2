// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55f1a8
// Recovered Name: sub_55f1a8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55f1a8 | Size: 36 bytes | SHA256: 4be99d6f473a81150ff2b40a11cb9c2052639512a0b5969aa38b054c9cde40af
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetScore(JIF)V (table at 0x10cc2f0)

jlong sub_55f1a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x55f1a8 */ cbz x2, #0x55f1c8;
    /* 0x55f1ac */ cmp w3, #9;
    /* 0x55f1b0 */ b.hi #0x55f1c8;
    /* 0x55f1b4 */ mov w8, #0x140;
    /* 0x55f1b8 */ mov w9, #1;
    /* 0x55f1bc */ umaddl x8, w3, w8, x2;
    /* 0x55f1c0 */ strb w9, [x8, #0x3c];
    /* 0x55f1c4 */ str s0, [x8, #0x40];
    return x0;
}
