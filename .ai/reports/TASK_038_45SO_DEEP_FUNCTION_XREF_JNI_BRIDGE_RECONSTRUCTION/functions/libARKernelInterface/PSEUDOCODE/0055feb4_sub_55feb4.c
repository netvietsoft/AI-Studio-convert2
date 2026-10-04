// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55feb4
// Recovered Name: sub_55feb4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55feb4 | Size: 20 bytes | SHA256: dbbb0e5f116e492f2572398deeadc00e21c66ffc6b6537a1b2e245b2ded9753f
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetIsFrontCamera(J)Z (table at 0x10cc3b0)

jlong sub_55feb4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x55feb4 */ cbz x2, #0x55fec0;
    /* 0x55feb8 */ ldrb w0, [x2, #0x10];
    return x0;
    /* 0x55fec0 */ mov w0, wzr;
    return x0;
}
