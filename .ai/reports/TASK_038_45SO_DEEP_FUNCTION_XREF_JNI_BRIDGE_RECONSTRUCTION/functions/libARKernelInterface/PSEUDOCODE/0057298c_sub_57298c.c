// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57298c
// Recovered Name: sub_57298c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57298c | Size: 52 bytes | SHA256: f5129898849aa0926068c0b816acaf438982268dc17bf40c543b3adc2d3a96e3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetHandGestureScore(JI)F (table at 0x10cd928)

jlong sub_57298c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x57298c */ movi d0, #0000000000000000;
    /* 0x572990 */ cbz x2, #0x5729bc;
    /* 0x572994 */ cmp w3, #9;
    /* 0x572998 */ b.hi #0x5729bc;
    /* 0x57299c */ mov w8, #0xec;
    /* 0x5729a0 */ umaddl x8, w3, w8, x2;
    /* 0x5729a4 */ ldrb w8, [x8, #0x50];
    /* 0x5729a8 */ cbz w8, #0x5729bc;
    /* 0x5729ac */ mov w8, w3;
    /* 0x5729b0 */ mov w9, #0xec;
    /* 0x5729b4 */ umaddl x8, w8, w9, x2;
    return x0;
}
