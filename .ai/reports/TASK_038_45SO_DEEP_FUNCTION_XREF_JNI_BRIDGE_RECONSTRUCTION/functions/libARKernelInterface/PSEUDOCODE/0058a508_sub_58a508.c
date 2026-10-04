// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58a508
// Recovered Name: sub_58a508
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58a508 | Size: 16 bytes | SHA256: 1812cf4e9f73bf85b6bb0d3ee74352e1c9c3e445720bb54e21cd30bed35c121f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetCurrentValueXY(JFF)V (table at 0x10d02b0)

jlong sub_58a508(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x58a508 */ cbz x2, #0x58a514;
    /* 0x58a50c */ mov x0, x2;
    /* 0x58a510 */ b #0xa2d3b0;
    return x0;
}
