// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f4420
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI13nRtDataCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f4420 | Size: 36 bytes | SHA256: cb56d161d1ad4cdb447fcf6426e9b05c0ebdd6a88ea9c0265a35cd283d31804f
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x53b800)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFTextModularJNI13nRtDataCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2f4420 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2f4424 */ mov x29, sp;
    /* 0x2f4428 */ mov w0, #0x30;
    _Znwm();
    /* 0x2f4430 */ movi v0.2d, #0000000000000000;
    /* 0x2f4434 */ stp q0, q0, [x0];
    /* 0x2f4438 */ str q0, [x0, #0x20];
    /* 0x2f443c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
