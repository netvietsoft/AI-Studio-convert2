// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d9cc
// Recovered Name: sub_57d9cc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d9cc | Size: 20 bytes | SHA256: f78a4d597c8a14fb29ea3d11132d86b607e0687eeb95e5781f6c5317167f52be
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerEnableDoubleTouchTranslate(J)Z (table at 0x10cf218)

jlong sub_57d9cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d9cc */ cbz x2, #0x57d9d8;
    /* 0x57d9d0 */ ldrb w0, [x2, #0x154];
    return x0;
    /* 0x57d9d8 */ mov w0, wzr;
    return x0;
}
