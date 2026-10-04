// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58b5d4
// Recovered Name: sub_58b5d4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58b5d4 | Size: 32 bytes | SHA256: 5ece2477e9d4946c33df46af9951304edf4d6ceec2ee5833f85789e628da0f0c
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetEnable(JZ)V (table at 0x10d0748)

jlong sub_58b5d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x58b5d4 */ cbz x2, #0x58b5f0;
    /* 0x58b5d8 */ ldr x8, [x2];
    /* 0x58b5dc */ tst w3, #0xff;
    /* 0x58b5e0 */ mov x0, x2;
    /* 0x58b5e4 */ cset w1, ne;
    /* 0x58b5e8 */ ldr x3, [x8, #0xb0];
    /* 0x58b5ec */ br x3;
    return x0;
}
