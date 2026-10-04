// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d566c
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI12nCreateModelEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d566c | Size: 44 bytes | SHA256: 6a1655867942012c3198e79a6a8d465c02874460cbdc9a04c33820c4c676a6c9
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x5359f0)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI12nCreateModelEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x2d566c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d5670 */ mov x29, sp;
    /* 0x2d5674 */ mov w0, #0x58;
    _Znwm();
    /* 0x2d567c */ movi v0.2d, #0000000000000000;
    /* 0x2d5680 */ stp q0, q0, [x0];
    /* 0x2d5684 */ stp q0, q0, [x0, #0x20];
    /* 0x2d5688 */ str q0, [x0, #0x40];
    /* 0x2d568c */ str xzr, [x0, #0x50];
    /* 0x2d5690 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
