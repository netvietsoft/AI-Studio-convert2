// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d6c18
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI25nSkinWhitenMaterialCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d6c18 | Size: 28 bytes | SHA256: c2f89c15de194baba065f758c2a7d669fd802dff86fa3a22bc73c0263d6ef0ea
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x535eb8)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI25nSkinWhitenMaterialCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x2d6c18 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d6c1c */ mov x29, sp;
    /* 0x2d6c20 */ mov w0, #0x10;
    _Znwm();
    /* 0x2d6c28 */ stp xzr, xzr, [x0];
    /* 0x2d6c2c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
