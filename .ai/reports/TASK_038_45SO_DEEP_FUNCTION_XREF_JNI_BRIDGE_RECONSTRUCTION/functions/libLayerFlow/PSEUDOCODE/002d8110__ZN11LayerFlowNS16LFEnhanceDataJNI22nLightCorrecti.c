// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d8110
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI22nLightCorrectionCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d8110 | Size: 32 bytes | SHA256: fe96c2e3455ac1462e48fcf22208c11ed6ee99059e04fb53581c9ece05d0e49e
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x5365a8)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI22nLightCorrectionCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2d8110 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d8114 */ mov x29, sp;
    /* 0x2d8118 */ mov w0, #0x18;
    _Znwm();
    /* 0x2d8120 */ stp xzr, xzr, [x0, #8];
    /* 0x2d8124 */ str xzr, [x0];
    /* 0x2d8128 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
