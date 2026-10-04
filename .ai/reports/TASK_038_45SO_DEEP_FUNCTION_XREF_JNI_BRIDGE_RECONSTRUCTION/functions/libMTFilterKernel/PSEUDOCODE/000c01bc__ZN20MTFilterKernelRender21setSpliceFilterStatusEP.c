// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xc01bc
// Recovered Name: _ZN20MTFilterKernelRender21setSpliceFilterStatusEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xc01bc | Size: 24 bytes | SHA256: 817fe6e0310c1d7678a50249e49a3bebc655decd0be0db770fcf86745ed4c3e6
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetSpliceFilterStatus(JZ)V (table at 0x1ca638)

jlong _ZN20MTFilterKernelRender21setSpliceFilterStatusEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0xc01bc */ cbz x2, #0xc01d0;
    /* 0xc01c0 */ tst w3, #0xff;
    /* 0xc01c4 */ mov x0, x2;
    /* 0xc01c8 */ cset w1, ne;
    /* 0xc01cc */ b #0x1aa870;
    return x0;
}
