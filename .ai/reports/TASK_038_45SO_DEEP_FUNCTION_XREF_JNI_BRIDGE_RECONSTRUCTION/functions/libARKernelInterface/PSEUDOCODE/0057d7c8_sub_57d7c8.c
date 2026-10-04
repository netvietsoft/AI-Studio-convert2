// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d7c8
// Recovered Name: sub_57d7c8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d7c8 | Size: 20 bytes | SHA256: 00b3fe2b14e83d8b9c6735c6c686bb69e04ea1921da2f910b62f99fa1e71a627
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerMoveAdsorbIValue(J)I (table at 0x10cf068)

jlong sub_57d7c8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d7c8 */ cbz x2, #0x57d7d4;
    /* 0x57d7cc */ ldr w0, [x2, #0x48];
    return x0;
    /* 0x57d7d4 */ mov w0, wzr;
    return x0;
}
