// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d3210
// Recovered Name: _ZN11LayerFlowNS23LFEffectSlimmingDataJNI11nCreateDataEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d3210 | Size: 36 bytes | SHA256: e74d2a505940696a8160c9844f05b4d9ba6bb641db6bec128b005c34b688b99f
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x534e98)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS23LFEffectSlimmingDataJNI11nCreateDataEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2d3210 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d3214 */ mov x29, sp;
    /* 0x2d3218 */ mov w0, #0x40;
    _Znwm();
    /* 0x2d3220 */ movi v0.2d, #0000000000000000;
    /* 0x2d3224 */ stp q0, q0, [x0];
    /* 0x2d3228 */ stp q0, q0, [x0, #0x20];
    /* 0x2d322c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
