// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57c2d8
// Recovered Name: sub_57c2d8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57c2d8 | Size: 28 bytes | SHA256: b047f45e7fae3b6e3785982999706a2b6ddb9906e8fa88fa8c5baef72cb33ce9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetShoulderPointThreshold(JIF)V (table at 0x10cea50)

jlong sub_57c2d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x57c2d8 */ cbz x2, #0x57c2f0;
    /* 0x57c2dc */ cmp w3, #9;
    /* 0x57c2e0 */ b.hi #0x57c2f0;
    /* 0x57c2e4 */ mov w8, #0xa0;
    /* 0x57c2e8 */ umaddl x8, w3, w8, x2;
    /* 0x57c2ec */ str s0, [x8, #0xb4];
    return x0;
}
