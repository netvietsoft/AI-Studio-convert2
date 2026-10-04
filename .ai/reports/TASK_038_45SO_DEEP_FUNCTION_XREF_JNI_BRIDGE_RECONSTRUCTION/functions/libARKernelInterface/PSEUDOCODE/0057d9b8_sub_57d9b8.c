// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d9b8
// Recovered Name: sub_57d9b8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d9b8 | Size: 20 bytes | SHA256: ee6fd8848fafc4fc9de7880cd1a02f881fa677a6ffa064a6c02698cf3d808f8d
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerEnableDoubleTouchTranslate(JZ)V (table at 0x10cf200)

jlong sub_57d9b8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d9b8 */ cbz x2, #0x57d9c8;
    /* 0x57d9bc */ tst w3, #0xff;
    /* 0x57d9c0 */ cset w8, ne;
    /* 0x57d9c4 */ strb w8, [x2, #0x154];
    return x0;
}
