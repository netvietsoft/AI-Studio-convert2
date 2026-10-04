// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbfd28
// Recovered Name: _ZN20MTFilterKernelRender10nFinalizerEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbfd28 | Size: 24 bytes | SHA256: 6c7b6b31556e275d8969e0b5f15964139d49ddda128e289fcae4a94737dbedfa
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nFinalizer(J)V (table at 0x1ca548)

jlong _ZN20MTFilterKernelRender10nFinalizerEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0xbfd28 */ cbz x2, #0xbfd3c;
    /* 0xbfd2c */ ldr x8, [x2];
    /* 0xbfd30 */ mov x0, x2;
    /* 0xbfd34 */ ldr x1, [x8, #8];
    /* 0xbfd38 */ br x1;
    return x0;
}
