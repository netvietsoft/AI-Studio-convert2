// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e306c
// Recovered Name: _ZN11LayerFlowNS13LFFontInfoJNI7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e306c | Size: 44 bytes | SHA256: b991ff988b6c609777cb1c62aeaa720d909b38ca66c3c4a5344422542de110f1
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x537e40)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS13LFFontInfoJNI7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x2e306c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2e3070 */ mov x29, sp;
    /* 0x2e3074 */ mov w0, #0x68;
    _Znwm();
    /* 0x2e307c */ movi v0.2d, #0000000000000000;
    /* 0x2e3080 */ stp q0, q0, [x0];
    /* 0x2e3084 */ stp q0, q0, [x0, #0x20];
    /* 0x2e3088 */ stp q0, q0, [x0, #0x40];
    /* 0x2e308c */ str xzr, [x0, #0x60];
    /* 0x2e3090 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
