// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e72e0
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI16nCreateColorInfoEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e72e0 | Size: 28 bytes | SHA256: a88e6409e77fcb4c0dd7d8ae3cbfb204508902fea2edcae65790e897dab0ad12
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreateColorInfo()J (table at 0x538758)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI16nCreateColorInfoEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x2e72e0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2e72e4 */ mov x29, sp;
    /* 0x2e72e8 */ mov w0, #0x10;
    _Znwm();
    /* 0x2e72f0 */ stp xzr, xzr, [x0];
    /* 0x2e72f4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
