// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d690
// Recovered Name: sub_57d690
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d690 | Size: 20 bytes | SHA256: 3d4d7eac1277018d872c3a6f1fb08616c53438843579e99e41ac94166147ef40
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerOutlineBorderMarginLeft(J)I (table at 0x10ceeb8)

jlong sub_57d690(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d690 */ cbz x2, #0x57d69c;
    /* 0x57d694 */ ldr w0, [x2, #0x24];
    return x0;
    /* 0x57d69c */ mov w0, wzr;
    return x0;
}
