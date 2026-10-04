// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d6a88
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI17nLightParamCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d6a88 | Size: 40 bytes | SHA256: 7d7c02e3b8aea99b31e1c8f91c8c25680400e50ab66ddcaf72c4dc95b4b1abdf
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x535b88)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI17nLightParamCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x2d6a88 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d6a8c */ mov x29, sp;
    /* 0x2d6a90 */ mov w0, #0x50;
    _Znwm();
    /* 0x2d6a98 */ movi v0.2d, #0000000000000000;
    /* 0x2d6a9c */ stp q0, q0, [x0];
    /* 0x2d6aa0 */ stp q0, q0, [x0, #0x20];
    /* 0x2d6aa4 */ str q0, [x0, #0x40];
    /* 0x2d6aa8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
