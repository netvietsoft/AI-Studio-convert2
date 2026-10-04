// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d55c4
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI13nGetNeckLevelEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d55c4 | Size: 20 bytes | SHA256: de0a9781d1b56013d287eaa90dd9cca3dd02608a0cf042d87c727b2eab13a485
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetNeckLevel(J)D (table at 0x535900)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI13nGetNeckLevelEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2d55c4 */ cbz x2, #0x2d55d0;
    /* 0x2d55c8 */ ldr d0, [x2, #8];
    return x0;
    /* 0x2d55d0 */ movi d0, #0000000000000000;
    return x0;
}
