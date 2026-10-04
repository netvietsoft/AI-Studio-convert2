// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x448554
// Recovered Name: _ZN11LayerFlowNS15LFJsonPluginJNI6createEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x448554 | Size: 64 bytes | SHA256: 8dd7b776e3996c1c77166db5005ede25ffc3ea2222f07a60961856d06cd35a3c
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x5461d8)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS15LFJsonPluginJNI6createEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x448554 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x448558 */ stp x20, x19, [sp, #0x10];
    /* 0x44855c */ mov x29, sp;
    /* 0x448560 */ mov w0, #0x20;
    _Znwm();
    /* 0x448568 */ mov x19, x0;
    _ZN11LayerFlowNS12LFJsonPluginC2Ev();
    /* 0x448570 */ mov x0, x19;
    /* 0x448574 */ ldp x20, x19, [sp, #0x10];
    /* 0x448578 */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    sub_526544();
}
