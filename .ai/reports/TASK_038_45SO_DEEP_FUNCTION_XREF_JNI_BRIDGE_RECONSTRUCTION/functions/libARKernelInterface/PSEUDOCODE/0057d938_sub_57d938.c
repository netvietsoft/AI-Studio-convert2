// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d938
// Recovered Name: sub_57d938
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d938 | Size: 12 bytes | SHA256: 2d3f8371bc92838616a6335aa74099f9fbecf4edd71b1961cd2a60a3aff60565
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerRotateAdsorbOValue(JI)V (table at 0x10cf170)

jlong sub_57d938(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d938 */ cbz x2, #0x57d940;
    /* 0x57d93c */ str w3, [x2, #0xfc];
    return x0;
}
