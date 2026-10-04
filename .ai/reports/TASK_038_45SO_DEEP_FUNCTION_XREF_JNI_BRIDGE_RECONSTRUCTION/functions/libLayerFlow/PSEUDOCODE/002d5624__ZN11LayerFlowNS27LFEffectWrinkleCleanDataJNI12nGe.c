// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5624
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI12nGetLipLevelEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5624 | Size: 20 bytes | SHA256: 12bd59479588caa2306cf1d0f126c0da21f71106f6872ac1be64fe4185883469
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetLipLevel(J)D (table at 0x535990)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI12nGetLipLevelEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2d5624 */ cbz x2, #0x2d5630;
    /* 0x2d5628 */ ldr d0, [x2, #0x20];
    return x0;
    /* 0x2d5630 */ movi d0, #0000000000000000;
    return x0;
}
