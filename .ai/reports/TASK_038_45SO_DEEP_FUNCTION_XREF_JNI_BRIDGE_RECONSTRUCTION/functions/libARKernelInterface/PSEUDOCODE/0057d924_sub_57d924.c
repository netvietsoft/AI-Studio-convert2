// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d924
// Recovered Name: sub_57d924
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d924 | Size: 20 bytes | SHA256: 90ccad4279e73960a221e73159fe6bffff04d40b25884be1bfdac16300a5fbb3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerRotateAdsorbIValue(J)I (table at 0x10cf158)

jlong sub_57d924(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d924 */ cbz x2, #0x57d930;
    /* 0x57d928 */ ldr w0, [x2, #0xf8];
    return x0;
    /* 0x57d930 */ mov w0, wzr;
    return x0;
}
