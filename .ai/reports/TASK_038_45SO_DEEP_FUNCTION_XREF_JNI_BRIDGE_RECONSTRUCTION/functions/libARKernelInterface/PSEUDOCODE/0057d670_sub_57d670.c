// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d670
// Recovered Name: sub_57d670
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d670 | Size: 20 bytes | SHA256: 40f18e2b03d8a473a5def4277edd27b8c6a94c0b8c52ccb9b177a49b2c3c6e91
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerOutlineBorderMinValue(J)I (table at 0x10cee88)

jlong sub_57d670(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d670 */ cbz x2, #0x57d67c;
    /* 0x57d674 */ ldr w0, [x2, #0x20];
    return x0;
    /* 0x57d67c */ mov w0, wzr;
    return x0;
}
