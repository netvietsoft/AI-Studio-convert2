// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e734c
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI17nCreateMakeUpDataEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e734c | Size: 40 bytes | SHA256: a37dfd00c196f2c00b1003c5b2a48d5171a09d4e4e94b17f87e909a10373bcef
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreateMakeUpData()J (table at 0x538848)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI17nCreateMakeUpDataEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x2e734c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2e7350 */ mov x29, sp;
    /* 0x2e7354 */ mov w0, #0x50;
    _Znwm();
    /* 0x2e735c */ movi v0.2d, #0000000000000000;
    /* 0x2e7360 */ stp q0, q0, [x0];
    /* 0x2e7364 */ stp q0, q0, [x0, #0x20];
    /* 0x2e7368 */ str q0, [x0, #0x40];
    /* 0x2e736c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
