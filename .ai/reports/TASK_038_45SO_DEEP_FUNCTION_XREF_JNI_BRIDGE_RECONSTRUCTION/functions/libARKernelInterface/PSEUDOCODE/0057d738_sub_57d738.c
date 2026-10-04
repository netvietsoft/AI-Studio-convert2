// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d738
// Recovered Name: sub_57d738
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d738 | Size: 20 bytes | SHA256: 688d958b74f8247b3fcff1015bd98bde494ff099afc0a78de91b0533475f6440
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerMarginMinValue(J)I (table at 0x10cefa8)

jlong sub_57d738(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d738 */ cbz x2, #0x57d744;
    /* 0x57d73c */ ldr w0, [x2, #0x38];
    return x0;
    /* 0x57d744 */ mov w0, wzr;
    return x0;
}
