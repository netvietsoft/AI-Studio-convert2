// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d5b0
// Recovered Name: sub_57d5b0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d5b0 | Size: 20 bytes | SHA256: df3262842455451f77f7744b77544e0486c4dc7f58495367a775e9e046c46dd8
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetCanvasDirectionType(J)I (table at 0x10ced68)

jlong sub_57d5b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d5b0 */ cbz x2, #0x57d5bc;
    /* 0x57d5b4 */ ldr w0, [x2, #0x158];
    return x0;
    /* 0x57d5bc */ mov w0, wzr;
    return x0;
}
