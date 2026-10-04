// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x43fc80
// Recovered Name: _ZN11LayerFlowNS25LFPrepareManagerPluginJNI6createEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x43fc80 | Size: 64 bytes | SHA256: 81570db00f64a165752d12719dc48952ca1dc0529620b076140db5523e2c8c55
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x545dd0)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS25LFPrepareManagerPluginJNI6createEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x43fc80 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x43fc84 */ stp x20, x19, [sp, #0x10];
    /* 0x43fc88 */ mov x29, sp;
    /* 0x43fc8c */ mov w0, #0x30;
    _Znwm();
    /* 0x43fc94 */ mov x19, x0;
    _ZN11LayerFlowNS25LFPrepareManagerPluginJNIC2Ev();
    /* 0x43fc9c */ mov x0, x19;
    /* 0x43fca0 */ ldp x20, x19, [sp, #0x10];
    /* 0x43fca4 */ ldp x29, x30, [sp], #0x20;
    /* 0x43fca8 */ b #0x45a6b8;
    _ZdlPv();
    sub_526544();
}
