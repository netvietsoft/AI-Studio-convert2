// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e2cdc
// Recovered Name: _ZN11LayerFlowNS18LFFilterModularJNI8rdCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e2cdc | Size: 36 bytes | SHA256: 1d61227c546eba379e99881ba3fff5d8c645535ea2126f312ac6dd1ccf5d5b2b
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x537dc8)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS18LFFilterModularJNI8rdCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2e2cdc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2e2ce0 */ mov x29, sp;
    /* 0x2e2ce4 */ mov w0, #0x40;
    _Znwm();
    /* 0x2e2cec */ movi v0.2d, #0000000000000000;
    /* 0x2e2cf0 */ stp q0, q0, [x0];
    /* 0x2e2cf4 */ stp q0, q0, [x0, #0x20];
    /* 0x2e2cf8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
