// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5724b4
// Recovered Name: sub_5724b4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5724b4 | Size: 24 bytes | SHA256: 6c7b6b31556e275d8969e0b5f15964139d49ddda128e289fcae4a94737dbedfa
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeDestroyInstance(J)V (table at 0x10cd790)

jlong sub_5724b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x5724b4 */ cbz x2, #0x5724c8;
    /* 0x5724b8 */ ldr x8, [x2];
    /* 0x5724bc */ mov x0, x2;
    /* 0x5724c0 */ ldr x1, [x8, #8];
    /* 0x5724c4 */ br x1;
    return x0;
}
