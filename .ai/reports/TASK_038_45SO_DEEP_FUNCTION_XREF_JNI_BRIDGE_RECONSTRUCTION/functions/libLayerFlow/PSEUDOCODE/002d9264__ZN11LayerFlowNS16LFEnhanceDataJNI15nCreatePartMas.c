// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d9264
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI15nCreatePartMaskEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d9264 | Size: 36 bytes | SHA256: 396954b0bd36175e075dcc4289958bd241ef657ab92339e1b13d8d3f90e63a80
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreatePartMask()J (table at 0x5368d8)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI15nCreatePartMaskEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2d9264 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d9268 */ mov x29, sp;
    /* 0x2d926c */ mov w0, #0x28;
    _Znwm();
    /* 0x2d9274 */ movi v0.2d, #0000000000000000;
    /* 0x2d9278 */ stp q0, q0, [x0];
    /* 0x2d927c */ str xzr, [x0, #0x20];
    /* 0x2d9280 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
