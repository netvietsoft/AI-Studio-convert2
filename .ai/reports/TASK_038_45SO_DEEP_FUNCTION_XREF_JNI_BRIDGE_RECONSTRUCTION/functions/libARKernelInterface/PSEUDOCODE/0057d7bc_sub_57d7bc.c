// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d7bc
// Recovered Name: sub_57d7bc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d7bc | Size: 12 bytes | SHA256: b96b8cb645f1c47b168b59218bdff45dd4eb31b35c6bd6ff58ef65719a6f8c06
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerMoveAdsorbIValue(JI)V (table at 0x10cf050)

jlong sub_57d7bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d7bc */ cbz x2, #0x57d7c4;
    /* 0x57d7c0 */ str w3, [x2, #0x48];
    return x0;
}
