// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3c0044
// Recovered Name: _ZN11LayerFlowNS24LFFormulaRenderPluginJNI6createEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3c0044 | Size: 92 bytes | SHA256: a039a2d471ff39137014f6d015233fe926aac0367105a4af934101e0ddf191c2
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x540228)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS24LFFormulaRenderPluginJNI6createEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x3c0044 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x3c0048 */ stp x20, x19, [sp, #0x10];
    /* 0x3c004c */ mov x29, sp;
    /* 0x3c0050 */ mov x20, x0;
    /* 0x3c0054 */ mov w0, #0x6b0;
    _Znwm();
    /* 0x3c005c */ mov x19, x0;
    _ZN11LayerFlowNS24LFFormulaRenderPluginJNIC1Ev();
    /* 0x3c0064 */ ldr x8, [x20];
    /* 0x3c0068 */ add x1, x19, #0x5e0;
    /* 0x3c006c */ mov x0, x20;
    return x0;
    _ZdlPv();
    sub_526544();
}
