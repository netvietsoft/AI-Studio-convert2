// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d6c6c
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI17nSkinWhitenCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d6c6c | Size: 32 bytes | SHA256: cb1ec6e9e7adb9aaf93df613fa2cef4e7474c7cf3ba8e42e303c2b6013d64334
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x535f48)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI17nSkinWhitenCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2d6c6c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d6c70 */ mov x29, sp;
    /* 0x2d6c74 */ mov w0, #0x20;
    _Znwm();
    /* 0x2d6c7c */ movi v0.2d, #0000000000000000;
    /* 0x2d6c80 */ stp q0, q0, [x0];
    /* 0x2d6c84 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
