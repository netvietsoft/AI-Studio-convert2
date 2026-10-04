// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5854c4
// Recovered Name: sub_5854c4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5854c4 | Size: 20 bytes | SHA256: 599189da9b778da3c532be4ecc3ab8f140c2369f98b84d1d88a3a913be21907d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetSelectedLayer(JJ)V (table at 0x10cfa58)

jlong sub_5854c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5854c4 */ cbz x2, #0x5854d4;
    /* 0x5854c8 */ mov x0, x2;
    /* 0x5854cc */ mov x1, x3;
    /* 0x5854d0 */ b #0x58437c;
    return x0;
}
