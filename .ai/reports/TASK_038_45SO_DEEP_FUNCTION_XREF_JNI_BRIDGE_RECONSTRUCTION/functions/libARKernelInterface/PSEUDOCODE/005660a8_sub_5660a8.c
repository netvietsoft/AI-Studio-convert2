// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5660a8
// Recovered Name: sub_5660a8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5660a8 | Size: 24 bytes | SHA256: 6c7b6b31556e275d8969e0b5f15964139d49ddda128e289fcae4a94737dbedfa
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeDestroyInstance(J)V (table at 0x10cc818)

jlong sub_5660a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x5660a8 */ cbz x2, #0x5660bc;
    /* 0x5660ac */ ldr x8, [x2];
    /* 0x5660b0 */ mov x0, x2;
    /* 0x5660b4 */ ldr x1, [x8, #8];
    /* 0x5660b8 */ br x1;
    return x0;
}
