// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d6d0
// Recovered Name: sub_57d6d0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d6d0 | Size: 20 bytes | SHA256: a2a11d34dba4c4ddda6e2162674a7c56dabf095b026fdb854c14914e6560f96c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerOutlineBorderMarginTop(J)I (table at 0x10cef18)

jlong sub_57d6d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d6d0 */ cbz x2, #0x57d6dc;
    /* 0x57d6d4 */ ldr w0, [x2, #0x2c];
    return x0;
    /* 0x57d6dc */ mov w0, wzr;
    return x0;
}
