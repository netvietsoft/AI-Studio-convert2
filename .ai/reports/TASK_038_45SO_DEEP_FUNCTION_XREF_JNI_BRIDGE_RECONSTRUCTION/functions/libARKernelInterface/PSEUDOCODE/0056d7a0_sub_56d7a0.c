// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56d7a0
// Recovered Name: sub_56d7a0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56d7a0 | Size: 24 bytes | SHA256: 6c7b6b31556e275d8969e0b5f15964139d49ddda128e289fcae4a94737dbedfa
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeDestroyInstance(J)V (table at 0x10cd2f8)

jlong sub_56d7a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x56d7a0 */ cbz x2, #0x56d7b4;
    /* 0x56d7a4 */ ldr x8, [x2];
    /* 0x56d7a8 */ mov x0, x2;
    /* 0x56d7ac */ ldr x1, [x8, #8];
    /* 0x56d7b0 */ br x1;
    return x0;
}
