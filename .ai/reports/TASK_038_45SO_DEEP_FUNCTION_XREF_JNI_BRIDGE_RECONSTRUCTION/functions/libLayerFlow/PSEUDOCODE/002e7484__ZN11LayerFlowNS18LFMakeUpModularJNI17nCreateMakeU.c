// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e7484
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI17nCreateMakeUpInfoEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e7484 | Size: 84 bytes | SHA256: 180393e4695fb6e8dc8388e9bed4bb66c1465b12cd05fea37bc524d2ee360d5c
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nCreateMakeUpInfo()J (table at 0x5389f8)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI17nCreateMakeUpInfoEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 21 instructions
    /* 0x2e7484 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2e7488 */ stp x20, x19, [sp, #0x10];
    /* 0x2e748c */ mov x29, sp;
    /* 0x2e7490 */ mov w0, #0x58;
    _Znwm();
    /* 0x2e7498 */ movi v0.2d, #0000000000000000;
    /* 0x2e749c */ mov x19, x0;
    /* 0x2e74a0 */ str xzr, [x0, #0x50];
    /* 0x2e74a4 */ stp q0, q0, [x0];
    /* 0x2e74a8 */ stp q0, q0, [x0, #0x20];
    /* 0x2e74ac */ str q0, [x0, #0x40];
    _ZN10MakeUpInfoC2Ev();
    return x0;
    _ZdlPv();
    sub_526544();
}
