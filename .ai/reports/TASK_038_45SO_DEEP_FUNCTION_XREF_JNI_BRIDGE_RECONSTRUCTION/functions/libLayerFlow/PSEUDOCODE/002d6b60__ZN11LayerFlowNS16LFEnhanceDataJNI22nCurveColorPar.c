// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d6b60
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI22nCurveColorParamCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d6b60 | Size: 44 bytes | SHA256: 1d1adf7b23285c0c500cc0060bef66b56ac665da06b59d49b0fdbd6c5d28ec8f
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x535d98)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI22nCurveColorParamCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x2d6b60 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d6b64 */ mov x29, sp;
    /* 0x2d6b68 */ mov w0, #0x68;
    _Znwm();
    /* 0x2d6b70 */ movi v0.2d, #0000000000000000;
    /* 0x2d6b74 */ stp q0, q0, [x0];
    /* 0x2d6b78 */ stp q0, q0, [x0, #0x20];
    /* 0x2d6b7c */ stp q0, q0, [x0, #0x40];
    /* 0x2d6b80 */ str xzr, [x0, #0x60];
    /* 0x2d6b84 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
