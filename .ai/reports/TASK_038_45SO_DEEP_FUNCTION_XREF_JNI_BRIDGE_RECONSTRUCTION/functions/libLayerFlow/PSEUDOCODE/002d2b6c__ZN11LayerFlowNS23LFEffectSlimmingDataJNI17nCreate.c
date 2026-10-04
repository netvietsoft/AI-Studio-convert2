// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d2b6c
// Recovered Name: _ZN11LayerFlowNS23LFEffectSlimmingDataJNI17nCreateFaceParamsEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d2b6c | Size: 36 bytes | SHA256: 1eef5b5b0c8b24b394740b2fbd42af0216bc78b80c6f55bcf2bb3cded371dd70
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x535168)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS23LFEffectSlimmingDataJNI17nCreateFaceParamsEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2d2b6c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2d2b70 */ mov x29, sp;
    /* 0x2d2b74 */ mov w0, #0x1c;
    _Znwm();
    /* 0x2d2b7c */ stp xzr, xzr, [x0, #8];
    /* 0x2d2b80 */ str xzr, [x0];
    /* 0x2d2b84 */ str wzr, [x0, #0x18];
    /* 0x2d2b88 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
