// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2bed10
// Recovered Name: _ZN11LayerFlowNS18LFAutoBrushDataJNI33nCreateLFRewriteChildrenMaterialsEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2bed10 | Size: 80 bytes | SHA256: 67a9a81e8e5557e4471954f12be23ac308d1b6ce13259a572c839287aa78d09b
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x5319d0)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS18LFAutoBrushDataJNI33nCreateLFRewriteChildrenMaterialsEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0x2bed10 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2bed14 */ mov x29, sp;
    /* 0x2bed18 */ mov w0, #0x108;
    _Znwm();
    /* 0x2bed20 */ movi v0.2d, #0000000000000000;
    /* 0x2bed24 */ mov x8, #-0x4010000000000000;
    /* 0x2bed28 */ stp q0, q0, [x0];
    /* 0x2bed2c */ stp q0, q0, [x0, #0x20];
    /* 0x2bed30 */ stp q0, q0, [x0, #0x40];
    /* 0x2bed34 */ stp q0, q0, [x0, #0x60];
    /* 0x2bed38 */ stp q0, q0, [x0, #0x80];
    return x0;
}
