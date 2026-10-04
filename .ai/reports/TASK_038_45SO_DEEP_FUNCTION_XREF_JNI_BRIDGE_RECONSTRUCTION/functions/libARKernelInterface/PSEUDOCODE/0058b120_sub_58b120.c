// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58b120
// Recovered Name: sub_58b120
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58b120 | Size: 28 bytes | SHA256: 9c995a1f4b0e6ce5de8a8f26ea8c5a1af2c5bcf8bbfe587355a64052be4f6531
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetCurrentOpacityValue(J)F (table at 0x10d05f8)

jlong sub_58b120(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x58b120 */ cbz x2, #0x58b134;
    /* 0x58b124 */ ldr x8, [x2];
    /* 0x58b128 */ mov x0, x2;
    /* 0x58b12c */ ldr x1, [x8, #0x78];
    /* 0x58b130 */ br x1;
    /* 0x58b134 */ movi d0, #0000000000000000;
    return x0;
}
