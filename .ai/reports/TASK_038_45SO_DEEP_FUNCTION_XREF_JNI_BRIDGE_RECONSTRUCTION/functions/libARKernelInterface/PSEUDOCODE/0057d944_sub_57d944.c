// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d944
// Recovered Name: sub_57d944
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d944 | Size: 20 bytes | SHA256: eadcacb52a552f4d5892bb8503c7cf75cf8c62509138d8253f7bd98f97a6eaef
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerRotateAdsorbOValue(J)I (table at 0x10cf188)

jlong sub_57d944(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d944 */ cbz x2, #0x57d950;
    /* 0x57d948 */ ldr w0, [x2, #0xfc];
    return x0;
    /* 0x57d950 */ mov w0, wzr;
    return x0;
}
