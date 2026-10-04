// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d6b0
// Recovered Name: sub_57d6b0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d6b0 | Size: 20 bytes | SHA256: fdd26fb7a57159a70aa7aa650d283e9c8c92b858bf7548bdacb5eebbd99b29b8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerOutlineBorderMarginRight(J)I (table at 0x10ceee8)

jlong sub_57d6b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d6b0 */ cbz x2, #0x57d6bc;
    /* 0x57d6b4 */ ldr w0, [x2, #0x28];
    return x0;
    /* 0x57d6bc */ mov w0, wzr;
    return x0;
}
