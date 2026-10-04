// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ed188
// Recovered Name: _ZN11LayerFlowNS13LFMaterialJNI7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ed188 | Size: 88 bytes | SHA256: e4a7691abe4a3282c2a352263d15f2c8ecac2fc4ab95fc76df3636696309a886
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x539390)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS13LFMaterialJNI7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 22 instructions
    /* 0x2ed188 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2ed18c */ mov x29, sp;
    /* 0x2ed190 */ mov w0, #0x1b8;
    _Znwm();
    /* 0x2ed198 */ movi v0.2d, #0000000000000000;
    /* 0x2ed19c */ stp q0, q0, [x0];
    /* 0x2ed1a0 */ stp q0, q0, [x0, #0x20];
    /* 0x2ed1a4 */ stp q0, q0, [x0, #0x40];
    /* 0x2ed1a8 */ stp q0, q0, [x0, #0x60];
    /* 0x2ed1ac */ stp q0, q0, [x0, #0x80];
    /* 0x2ed1b0 */ stp q0, q0, [x0, #0xa0];
    return x0;
}
