// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c2ab8
// Recovered Name: _ZN11LayerFlowNS25LFAutoWrinkleCleanDataJNI20nPutFaceDataByFaceIdEP7_JNIEnvP7_jclasslil
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c2ab8 | Size: 216 bytes | SHA256: 258c72751a9bb46bb8960e7c2f0886de08e39e1237ee228df479f67d290c2bb8
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nPutFaceDataByFaceId(JIJ)V (table at 0x532210)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS25LFAutoWrinkleCleanDataJNI20nPutFaceDataByFaceIdEP7_JNIEnvP7_jclasslil(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 54 instructions
    /* 0x2c2ab8 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2c2abc */ stp x24, x23, [sp, #0x10];
    /* 0x2c2ac0 */ stp x22, x21, [sp, #0x20];
    /* 0x2c2ac4 */ stp x20, x19, [sp, #0x30];
    /* 0x2c2ac8 */ mov x29, sp;
    /* 0x2c2acc */ mov x23, x2;
    /* 0x2c2ad0 */ mov x19, x4;
    /* 0x2c2ad4 */ mov x20, x2;
    /* 0x2c2ad8 */ ldr x8, [x23, #0x28]!;
    /* 0x2c2adc */ mov w22, w3;
    /* 0x2c2ae0 */ cbnz x8, #0x2c2af8;
    _Znwm();
    sub_2bc34c();
    return x0;
}
