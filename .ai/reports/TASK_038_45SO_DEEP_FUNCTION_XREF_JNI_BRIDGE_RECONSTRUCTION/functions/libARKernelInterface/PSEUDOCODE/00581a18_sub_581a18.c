// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x581a18
// Recovered Name: sub_581a18
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x581a18 | Size: 32 bytes | SHA256: a139f626068f081bac72cf2c2111a387bcf6cb87f56df54feb864d6552e84ed3
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetSpeed(J)F (table at 0x10cf2f0)

jlong sub_581a18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x581a18 */ cbz x2, #0x581a30;
    /* 0x581a1c */ ldr x0, [x2, #0x1a0];
    /* 0x581a20 */ cbz x0, #0x581a38;
    /* 0x581a24 */ ldr x8, [x0];
    /* 0x581a28 */ ldr x1, [x8, #0x30];
    /* 0x581a2c */ br x1;
    /* 0x581a30 */ movi d0, #0000000000000000;
    return x0;
}
