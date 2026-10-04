// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5772bc
// Recovered Name: sub_5772bc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5772bc | Size: 28 bytes | SHA256: b4e01d33debdf7d21e5208c7d5126f88358a4ad403b117cc84b77d0fe76da669
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeInitializeWithNoOpenGLContext(J)V (table at 0x10cdcd0)

jlong sub_5772bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x5772bc */ cbz x2, #0x5772d4;
    /* 0x5772c0 */ mov x0, x2;
    /* 0x5772c4 */ mov w1, wzr;
    /* 0x5772c8 */ mov x2, xzr;
    /* 0x5772cc */ mov x3, xzr;
    /* 0x5772d0 */ b #0x574a30;
    return x0;
}
