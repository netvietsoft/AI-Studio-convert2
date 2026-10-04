// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57c140
// Recovered Name: sub_57c140
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57c140 | Size: 36 bytes | SHA256: b5eda71e7d51a847f92d9311bf8a80c4bb4a01d20d2c7c05ba9200898b089822
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetShoulderID(JII)V (table at 0x10ce9d8)

jlong sub_57c140(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x57c140 */ cbz x2, #0x57c160;
    /* 0x57c144 */ cmp w3, #9;
    /* 0x57c148 */ b.hi #0x57c160;
    /* 0x57c14c */ mov w8, #0xa0;
    /* 0x57c150 */ mov w9, #1;
    /* 0x57c154 */ umaddl x8, w3, w8, x2;
    /* 0x57c158 */ strb w9, [x8, #0x18];
    /* 0x57c15c */ str w4, [x8, #0x1c];
    return x0;
}
