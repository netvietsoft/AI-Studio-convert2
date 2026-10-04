// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5888dc
// Recovered Name: sub_5888dc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5888dc | Size: 32 bytes | SHA256: 612ed7a933f8c03710f24c62616127fe917fd5eeeb85cd84b810defd332f2031
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetSpacing(J)F (table at 0x10cff20)

jlong sub_5888dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x5888dc */ cbz x2, #0x5888f4;
    /* 0x5888e0 */ ldr x0, [x2, #0x9e0];
    /* 0x5888e4 */ cbz x0, #0x5888fc;
    /* 0x5888e8 */ ldr x8, [x0];
    /* 0x5888ec */ ldr x1, [x8, #0x30];
    /* 0x5888f0 */ br x1;
    /* 0x5888f4 */ movi d0, #0000000000000000;
    return x0;
}
