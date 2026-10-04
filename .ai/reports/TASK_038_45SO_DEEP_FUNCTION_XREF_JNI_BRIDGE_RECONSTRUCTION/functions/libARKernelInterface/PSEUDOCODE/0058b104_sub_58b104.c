// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58b104
// Recovered Name: sub_58b104
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58b104 | Size: 28 bytes | SHA256: 858d71675d70af2bfa6609f0d374f8d666178119b5bf48b8d920d341e875d1c4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetDefaultOpacityValue(J)F (table at 0x10d05e0)

jlong sub_58b104(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x58b104 */ cbz x2, #0x58b118;
    /* 0x58b108 */ ldr x8, [x2];
    /* 0x58b10c */ mov x0, x2;
    /* 0x58b110 */ ldr x1, [x8, #0x88];
    /* 0x58b114 */ br x1;
    /* 0x58b118 */ movi d0, #0000000000000000;
    return x0;
}
