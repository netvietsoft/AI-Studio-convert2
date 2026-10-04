// Library: libAIModelSearchKit.so
// Function ID: libAIModelSearchKit::0x72860
// Recovered Name: _ZN13aimodelsearch27findMTAIMODELSEARCHKITClassEP7_JNIEnvPKc
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x72860 | Size: 332 bytes | SHA256: dd49a5e72eb81f29232c492bcd71e13f47333fd7d97538f732a7146bf9d538b6
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz

void _ZN13aimodelsearch27findMTAIMODELSEARCHKITClassEP7_JNIEnvPKc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 83 instructions
    /* 0x72860 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x72864 */ str x23, [sp, #0x10];
    /* 0x72868 */ stp x22, x21, [sp, #0x20];
    /* 0x7286c */ stp x20, x19, [sp, #0x30];
    /* 0x72870 */ mov x29, sp;
    /* 0x72874 */ mov x19, x0;
    /* 0x72878 */ mov x0, xzr;
    /* 0x7287c */ cbz x19, #0x728e0;
    /* 0x72880 */ adrp x22, #0xfc000;
    /* 0x72884 */ ldr x22, [x22, #0xf98];
    /* 0x72888 */ ldr x8, [x22];
    return x0;
    _ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz();
    return x0;
    return x0;
}
