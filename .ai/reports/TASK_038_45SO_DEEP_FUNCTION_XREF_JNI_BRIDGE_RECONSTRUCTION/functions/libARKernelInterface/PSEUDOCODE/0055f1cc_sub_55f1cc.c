// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55f1cc
// Recovered Name: sub_55f1cc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55f1cc | Size: 52 bytes | SHA256: b508e180460c7ddbbfbed2f023a188830b98b77a613288dadb1a234b588bd593
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetScore(JI)F (table at 0x10cc308)

jlong sub_55f1cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x55f1cc */ movi d0, #0000000000000000;
    /* 0x55f1d0 */ cbz x2, #0x55f1fc;
    /* 0x55f1d4 */ cmp w3, #9;
    /* 0x55f1d8 */ b.hi #0x55f1fc;
    /* 0x55f1dc */ mov w8, #0x140;
    /* 0x55f1e0 */ umaddl x8, w3, w8, x2;
    /* 0x55f1e4 */ ldrb w8, [x8, #0x3c];
    /* 0x55f1e8 */ cbz w8, #0x55f1fc;
    /* 0x55f1ec */ mov w8, w3;
    /* 0x55f1f0 */ mov w9, #0x140;
    /* 0x55f1f4 */ umaddl x8, w8, w9, x2;
    return x0;
}
