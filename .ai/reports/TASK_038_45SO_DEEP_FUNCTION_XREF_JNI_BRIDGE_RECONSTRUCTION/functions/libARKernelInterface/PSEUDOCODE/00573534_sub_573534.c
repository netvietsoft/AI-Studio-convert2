// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x573534
// Recovered Name: sub_573534
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x573534 | Size: 24 bytes | SHA256: 6c7b6b31556e275d8969e0b5f15964139d49ddda128e289fcae4a94737dbedfa
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeDestroyInstance(J)V (table at 0x10cd9e8)

jlong sub_573534(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x573534 */ cbz x2, #0x573548;
    /* 0x573538 */ ldr x8, [x2];
    /* 0x57353c */ mov x0, x2;
    /* 0x573540 */ ldr x1, [x8, #8];
    /* 0x573544 */ br x1;
    return x0;
}
