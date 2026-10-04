// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b6d8
// Recovered Name: sub_57b6d8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b6d8 | Size: 20 bytes | SHA256: 977939c663d786fe5348a1c32c66c4b0e94e705906115e830871ce34fba0aa61
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetIsContinuousInputStream(J)Z (table at 0x10ce8e8)

jlong sub_57b6d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57b6d8 */ cbz x2, #0x57b6e4;
    /* 0x57b6dc */ ldrb w0, [x2, #0x1d];
    return x0;
    /* 0x57b6e4 */ mov w0, wzr;
    return x0;
}
