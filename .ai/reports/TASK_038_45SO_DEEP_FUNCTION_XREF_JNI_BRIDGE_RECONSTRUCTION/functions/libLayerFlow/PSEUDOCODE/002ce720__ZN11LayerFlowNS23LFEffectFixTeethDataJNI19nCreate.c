// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ce720
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI19nCreateRepairParamsEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ce720 | Size: 52 bytes | SHA256: 1e09d25939de75005384b47f6b4f5d6a77b5bd2a31532aeafa802c82b9f64a24
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x534328)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI19nCreateRepairParamsEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x2ce720 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2ce724 */ mov x29, sp;
    /* 0x2ce728 */ mov w0, #0x20;
    _Znwm();
    /* 0x2ce730 */ movi v0.2d, #0000000000000000;
    /* 0x2ce734 */ mov w8, #-1;
    /* 0x2ce738 */ stp q0, q0, [x0];
    /* 0x2ce73c */ str w8, [x0];
    /* 0x2ce740 */ strb wzr, [x0, #5];
    /* 0x2ce744 */ str wzr, [x0, #8];
    /* 0x2ce748 */ strb wzr, [x0, #0x18];
    return x0;
}
