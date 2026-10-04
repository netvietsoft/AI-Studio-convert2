// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d8030
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI23nParticularsParamCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d8030 | Size: 36 bytes | SHA256: 3ceb69b5fd92c6e4b16afbc33c7c941b989cb68a1afacd2b5e75579afa11c563
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x5363c8)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI23nParticularsParamCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2d8030 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d8034 */ mov x29, sp;
    /* 0x2d8038 */ mov w0, #0x30;
    _Znwm();
    /* 0x2d8040 */ movi v0.2d, #0000000000000000;
    /* 0x2d8044 */ stp q0, q0, [x0];
    /* 0x2d8048 */ str q0, [x0, #0x20];
    /* 0x2d804c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
