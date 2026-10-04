// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55df2c
// Recovered Name: sub_55df2c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55df2c | Size: 24 bytes | SHA256: 6c7b6b31556e275d8969e0b5f15964139d49ddda128e289fcae4a94737dbedfa
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeDestroyInstance(J)V (table at 0x10cc0c8)

jlong sub_55df2c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x55df2c */ cbz x2, #0x55df40;
    /* 0x55df30 */ ldr x8, [x2];
    /* 0x55df34 */ mov x0, x2;
    /* 0x55df38 */ ldr x1, [x8, #8];
    /* 0x55df3c */ br x1;
    return x0;
}
