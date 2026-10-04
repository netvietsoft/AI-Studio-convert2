// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5855e8
// Recovered Name: sub_5855e8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5855e8 | Size: 24 bytes | SHA256: b6c06ea3e29d8afc6a63d1db1e9cf8a34013dca5958ee1526903f6d0a7e13957
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetEnableDeselect(JZ)V (table at 0x10cfb30)

jlong sub_5855e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x5855e8 */ cbz x2, #0x5855fc;
    /* 0x5855ec */ tst w3, #0xff;
    /* 0x5855f0 */ mov x0, x2;
    /* 0x5855f4 */ cset w1, ne;
    /* 0x5855f8 */ b #0x5843c4;
    return x0;
}
