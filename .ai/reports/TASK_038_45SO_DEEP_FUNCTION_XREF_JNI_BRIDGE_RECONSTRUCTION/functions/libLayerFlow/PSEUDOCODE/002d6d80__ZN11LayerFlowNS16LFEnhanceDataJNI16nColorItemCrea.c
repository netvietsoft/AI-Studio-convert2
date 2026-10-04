// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d6d80
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI16nColorItemCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d6d80 | Size: 36 bytes | SHA256: aedb98173c42b278e65923174bc1106fdc30275d411f26277ec5440294a3b395
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x536008)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI16nColorItemCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2d6d80 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d6d84 */ mov x29, sp;
    /* 0x2d6d88 */ mov w0, #0x30;
    _Znwm();
    /* 0x2d6d90 */ movi v0.2d, #0000000000000000;
    /* 0x2d6d94 */ stp q0, q0, [x0];
    /* 0x2d6d98 */ str q0, [x0, #0x20];
    /* 0x2d6d9c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
