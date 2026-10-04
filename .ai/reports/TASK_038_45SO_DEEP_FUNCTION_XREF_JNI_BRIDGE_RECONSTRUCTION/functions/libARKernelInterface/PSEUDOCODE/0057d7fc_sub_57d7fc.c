// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d7fc
// Recovered Name: sub_57d7fc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d7fc | Size: 12 bytes | SHA256: 92f199ffc6c97417687037d7504a8d9cde521f0f56d7051a69b1413bd3bcf245
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerAdsorbDatumLineCount(JI)V (table at 0x10cf0b0)

jlong sub_57d7fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d7fc */ cbz x2, #0x57d804;
    /* 0x57d800 */ str w3, [x2, #0x50];
    return x0;
}
