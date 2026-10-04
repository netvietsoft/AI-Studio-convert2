// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x568be8
// Recovered Name: sub_568be8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x568be8 | Size: 24 bytes | SHA256: 6c7b6b31556e275d8969e0b5f15964139d49ddda128e289fcae4a94737dbedfa
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeDestroyInstance(J)V (table at 0x10ccc68)

jlong sub_568be8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x568be8 */ cbz x2, #0x568bfc;
    /* 0x568bec */ ldr x8, [x2];
    /* 0x568bf0 */ mov x0, x2;
    /* 0x568bf4 */ ldr x1, [x8, #8];
    /* 0x568bf8 */ br x1;
    return x0;
}
