// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d1d4
// Recovered Name: sub_57d1d4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d1d4 | Size: 24 bytes | SHA256: 6c7b6b31556e275d8969e0b5f15964139d49ddda128e289fcae4a94737dbedfa
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeDestroyInstance(J)V (table at 0x10cec48)

jlong sub_57d1d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x57d1d4 */ cbz x2, #0x57d1e8;
    /* 0x57d1d8 */ ldr x8, [x2];
    /* 0x57d1dc */ mov x0, x2;
    /* 0x57d1e0 */ ldr x1, [x8, #8];
    /* 0x57d1e4 */ br x1;
    return x0;
}
