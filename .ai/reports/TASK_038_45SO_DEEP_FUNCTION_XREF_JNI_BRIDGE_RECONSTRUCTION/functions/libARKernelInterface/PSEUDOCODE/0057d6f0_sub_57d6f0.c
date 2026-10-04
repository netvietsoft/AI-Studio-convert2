// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d6f0
// Recovered Name: sub_57d6f0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d6f0 | Size: 20 bytes | SHA256: 5bcf5b934610207e0af15862bcb020f5b6a68350e176b2ee5cad9ab80cc214e8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerOutlineBorderMarginBottom(J)I (table at 0x10cef48)

jlong sub_57d6f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d6f0 */ cbz x2, #0x57d6fc;
    /* 0x57d6f4 */ ldr w0, [x2, #0x30];
    return x0;
    /* 0x57d6fc */ mov w0, wzr;
    return x0;
}
