// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3bd95c
// Recovered Name: _ZN11LayerFlowNS28LFBgBeautifyAutoColorInfoJNI7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3bd95c | Size: 40 bytes | SHA256: ee8498ac19a0997f7a9db3bfd6060a70bdecead9075f8abd1cd8a81f3b66861d
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x53fe80)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS28LFBgBeautifyAutoColorInfoJNI7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x3bd95c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x3bd960 */ mov x29, sp;
    /* 0x3bd964 */ mov w0, #0x38;
    _Znwm();
    /* 0x3bd96c */ movi v0.2d, #0000000000000000;
    /* 0x3bd970 */ stp q0, q0, [x0];
    /* 0x3bd974 */ str q0, [x0, #0x20];
    /* 0x3bd978 */ str xzr, [x0, #0x30];
    /* 0x3bd97c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
