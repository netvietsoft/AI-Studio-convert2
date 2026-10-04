// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579e30
// Recovered Name: sub_579e30
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579e30 | Size: 24 bytes | SHA256: b315af6eac2acf052e936cd29db8536fd19c53f38f2d08d4f8a8046c50293292
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetEyePartEffectAlpha(JI)F (table at 0x10ce408)

jlong sub_579e30(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x579e30 */ cbz x2, #0x579e40;
    /* 0x579e34 */ mov x0, x2;
    /* 0x579e38 */ mov w1, w3;
    /* 0x579e3c */ b #0x8e0f7c;
    /* 0x579e40 */ fmov s0, #1.00000000;
    return x0;
}
