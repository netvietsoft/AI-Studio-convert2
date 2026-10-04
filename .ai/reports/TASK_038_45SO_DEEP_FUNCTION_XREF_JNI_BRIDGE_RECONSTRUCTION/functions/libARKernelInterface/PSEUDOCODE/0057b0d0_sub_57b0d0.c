// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b0d0
// Recovered Name: sub_57b0d0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b0d0 | Size: 20 bytes | SHA256: 4d9155bf5067f610e3de89af2d602c24fd396fb59de727170a901c36af14e843
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetMemoryUsage(J)J (table at 0x10ce768)

jlong sub_57b0d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57b0d0 */ cbz x2, #0x57b0dc;
    /* 0x57b0d4 */ mov x0, x2;
    /* 0x57b0d8 */ b #0x90b0b8;
    /* 0x57b0dc */ mov x0, xzr;
    return x0;
}
