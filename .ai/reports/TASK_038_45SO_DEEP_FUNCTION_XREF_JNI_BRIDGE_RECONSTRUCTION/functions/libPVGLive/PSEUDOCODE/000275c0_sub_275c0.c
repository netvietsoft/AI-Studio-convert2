// Library: libPVGLive.so
// Function ID: libPVGLive::0x275c0
// Recovered Name: sub_275c0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x275c0 | Size: 20 bytes | SHA256: e2d84b8b3e8de84c0e509f6464fa4ca3dc80fa7006e7e5801788fce17648a88d
// Callers: 2 | Callees: 0 | Imports: 0


void sub_275c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x275c0 */ adrp x8, #0x94000;
    /* 0x275c4 */ add x8, x8, #0xd98;
    /* 0x275c8 */ stp xzr, xzr, [x0, #0x10];
    /* 0x275cc */ stp x8, xzr, [x0];
    return x0;
}
