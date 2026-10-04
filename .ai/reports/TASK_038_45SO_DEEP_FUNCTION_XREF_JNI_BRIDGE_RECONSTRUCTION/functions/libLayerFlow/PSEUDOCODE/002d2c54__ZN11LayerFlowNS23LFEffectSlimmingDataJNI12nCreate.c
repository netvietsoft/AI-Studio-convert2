// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d2c54
// Recovered Name: _ZN11LayerFlowNS23LFEffectSlimmingDataJNI12nCreateModelEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d2c54 | Size: 40 bytes | SHA256: 252a998a4037d761ca66de36ebb651b6aa66fdb797428f35fbf1bd85e1a8a94e
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x534f88)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS23LFEffectSlimmingDataJNI12nCreateModelEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x2d2c54 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d2c58 */ mov x29, sp;
    /* 0x2d2c5c */ mov w0, #0x50;
    _Znwm();
    /* 0x2d2c64 */ movi v0.2d, #0000000000000000;
    /* 0x2d2c68 */ stp q0, q0, [x0];
    /* 0x2d2c6c */ stp q0, q0, [x0, #0x20];
    /* 0x2d2c70 */ str q0, [x0, #0x40];
    /* 0x2d2c74 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
