// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d958
// Recovered Name: sub_57d958
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d958 | Size: 12 bytes | SHA256: 76bd9506fe7096cccec15a0df7f2225fa77a9909d69e6d935f848c275d90e4b5
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerAdsorbDatumAngleCount(JI)V (table at 0x10cf1a0)

jlong sub_57d958(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d958 */ cbz x2, #0x57d960;
    /* 0x57d95c */ str w3, [x2, #0x100];
    return x0;
}
