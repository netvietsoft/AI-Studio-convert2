// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58b46c
// Recovered Name: sub_58b46c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58b46c | Size: 28 bytes | SHA256: d85231110ee059ff8adcb0b9f4abec2505d010f95385b02e5a407fea356513cb
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetDefaultValue(J)F (table at 0x10d06d0)

jlong sub_58b46c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x58b46c */ cbz x2, #0x58b480;
    /* 0x58b470 */ ldr x8, [x2];
    /* 0x58b474 */ mov x0, x2;
    /* 0x58b478 */ ldr x1, [x8, #0x68];
    /* 0x58b47c */ br x1;
    /* 0x58b480 */ movi d0, #0000000000000000;
    return x0;
}
