// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3bbadc
// Recovered Name: _ZN11LayerFlowNS29LFAutoMagicPenResourceDataJNI7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3bbadc | Size: 64 bytes | SHA256: d67aaf97d2064b59117ab3b6f3a2528b1be6169a6d3208479b435d6a218acb8d
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x53fc70)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS29LFAutoMagicPenResourceDataJNI7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x3bbadc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x3bbae0 */ mov x29, sp;
    /* 0x3bbae4 */ mov w0, #0x70;
    _Znwm();
    /* 0x3bbaec */ movi v0.2d, #0000000000000000;
    /* 0x3bbaf0 */ add x8, x0, #8;
    /* 0x3bbaf4 */ stp q0, q0, [x0];
    /* 0x3bbaf8 */ stp q0, q0, [x0, #0x20];
    /* 0x3bbafc */ stp q0, q0, [x0, #0x40];
    /* 0x3bbb00 */ str q0, [x0, #0x60];
    /* 0x3bbb04 */ str x8, [x0];
    return x0;
}
