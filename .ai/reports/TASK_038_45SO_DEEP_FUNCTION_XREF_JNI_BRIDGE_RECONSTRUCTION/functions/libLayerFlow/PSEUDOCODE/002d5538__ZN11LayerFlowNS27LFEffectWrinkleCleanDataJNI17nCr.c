// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5538
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI17nCreateAutoParamsEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5538 | Size: 40 bytes | SHA256: 4483b77e4d96299d17788f56157ee5c7ae5d8cc43eed7788146bc6d07f9f0716
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x5358a0)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI17nCreateAutoParamsEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x2d5538 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d553c */ mov x29, sp;
    /* 0x2d5540 */ mov w0, #0x38;
    _Znwm();
    /* 0x2d5548 */ movi v0.2d, #0000000000000000;
    /* 0x2d554c */ stp q0, q0, [x0];
    /* 0x2d5550 */ str q0, [x0, #0x20];
    /* 0x2d5554 */ str xzr, [x0, #0x30];
    /* 0x2d5558 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
