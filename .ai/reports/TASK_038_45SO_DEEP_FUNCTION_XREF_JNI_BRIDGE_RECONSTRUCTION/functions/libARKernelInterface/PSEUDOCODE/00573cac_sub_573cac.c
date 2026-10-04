// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x573cac
// Recovered Name: sub_573cac
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x573cac | Size: 24 bytes | SHA256: 6c7b6b31556e275d8969e0b5f15964139d49ddda128e289fcae4a94737dbedfa
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeDestroyInstance(J)V (table at 0x10cdac0)

jlong sub_573cac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x573cac */ cbz x2, #0x573cc0;
    /* 0x573cb0 */ ldr x8, [x2];
    /* 0x573cb4 */ mov x0, x2;
    /* 0x573cb8 */ ldr x1, [x8, #8];
    /* 0x573cbc */ br x1;
    return x0;
}
