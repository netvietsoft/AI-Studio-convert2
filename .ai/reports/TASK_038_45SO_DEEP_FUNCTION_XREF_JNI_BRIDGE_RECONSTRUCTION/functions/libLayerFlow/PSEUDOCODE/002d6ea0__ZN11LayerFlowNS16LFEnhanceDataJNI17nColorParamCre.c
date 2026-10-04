// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d6ea0
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI17nColorParamCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d6ea0 | Size: 72 bytes | SHA256: 9a2ed1466917e8da75113d4896dc22364bcdb3f57629c07b291e313510f0bd4a
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x5360f8)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI17nColorParamCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x2d6ea0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d6ea4 */ mov x29, sp;
    /* 0x2d6ea8 */ mov w0, #0x138;
    _Znwm();
    /* 0x2d6eb0 */ movi v0.2d, #0000000000000000;
    /* 0x2d6eb4 */ stp q0, q0, [x0];
    /* 0x2d6eb8 */ stp q0, q0, [x0, #0x20];
    /* 0x2d6ebc */ stp q0, q0, [x0, #0x40];
    /* 0x2d6ec0 */ stp q0, q0, [x0, #0x60];
    /* 0x2d6ec4 */ stp q0, q0, [x0, #0x80];
    /* 0x2d6ec8 */ stp q0, q0, [x0, #0xa0];
    return x0;
}
