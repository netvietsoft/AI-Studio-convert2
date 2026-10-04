// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d964
// Recovered Name: sub_57d964
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d964 | Size: 20 bytes | SHA256: 7468e5acbf218fcfaa39a3a22df4962b2c3e2a59de28f947056f9247d818ad1b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerAdsorbDatumAngleCount(J)I (table at 0x10cf1b8)

jlong sub_57d964(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d964 */ cbz x2, #0x57d970;
    /* 0x57d968 */ ldr w0, [x2, #0x100];
    return x0;
    /* 0x57d970 */ mov w0, wzr;
    return x0;
}
