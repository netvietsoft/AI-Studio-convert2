// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d80c4
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI26nLightCorrectionItemCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d80c4 | Size: 28 bytes | SHA256: bbc27996cf252ac5b9dc182d7da680292bd21eccf3f7b79ed90c3a20432e4b7e
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x536518)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI26nLightCorrectionItemCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x2d80c4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d80c8 */ mov x29, sp;
    /* 0x2d80cc */ mov w0, #0x10;
    _Znwm();
    /* 0x2d80d4 */ stp xzr, xzr, [x0];
    /* 0x2d80d8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
