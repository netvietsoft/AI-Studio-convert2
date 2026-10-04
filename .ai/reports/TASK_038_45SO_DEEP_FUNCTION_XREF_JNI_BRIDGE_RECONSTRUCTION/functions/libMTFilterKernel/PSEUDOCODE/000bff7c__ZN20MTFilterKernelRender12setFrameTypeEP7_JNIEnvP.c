// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbff7c
// Recovered Name: _ZN20MTFilterKernelRender12setFrameTypeEP7_JNIEnvP8_jobjectli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xbff7c | Size: 20 bytes | SHA256: 564c2fcac07ae05cec21a3a35eb6c608499de452f9f8909a00d0433f471100bb
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetFrameType(JI)V (table at 0x1ca5d8)

jlong _ZN20MTFilterKernelRender12setFrameTypeEP7_JNIEnvP8_jobjectli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0xbff7c */ cbz x2, #0xbff8c;
    /* 0xbff80 */ mov x0, x2;
    /* 0xbff84 */ mov w1, w3;
    /* 0xbff88 */ b #0x1aa064;
    return x0;
}
