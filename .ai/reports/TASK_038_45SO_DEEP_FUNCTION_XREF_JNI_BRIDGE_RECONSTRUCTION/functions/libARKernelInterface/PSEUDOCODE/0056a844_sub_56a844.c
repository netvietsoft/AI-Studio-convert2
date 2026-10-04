// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a844
// Recovered Name: sub_56a844
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a844 | Size: 28 bytes | SHA256: 6e179bd266bdea78256b67ece79b0153ade8054ab0dd8488a867bbcc06cffa38
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetFacialLandmark2DVisible(JI)[F (table at 0x10ccef0)

jlong sub_56a844(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x56a844 */ cbz x2, #0x56a8c0;
    /* 0x56a848 */ cmp w3, #0x13;
    /* 0x56a84c */ b.hi #0x56a8c0;
    /* 0x56a850 */ mov w8, #0x5c0;
    /* 0x56a854 */ umaddl x8, w3, w8, x2;
    /* 0x56a858 */ ldrb w8, [x8, #0x49];
    /* 0x56a85c */ cbz w8, #0x56a8c0;
}
