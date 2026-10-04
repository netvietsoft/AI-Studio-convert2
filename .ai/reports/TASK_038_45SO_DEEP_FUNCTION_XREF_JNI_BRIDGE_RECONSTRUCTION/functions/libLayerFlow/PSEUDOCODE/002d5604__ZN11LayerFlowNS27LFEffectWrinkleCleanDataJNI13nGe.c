// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5604
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI13nGetNasoLevelEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5604 | Size: 20 bytes | SHA256: 6843b88d27053e4f98ece6ba17e0a29ab7e438dae8e22724aae9c1e0ca61f053
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetNasoLevel(J)D (table at 0x535960)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI13nGetNasoLevelEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2d5604 */ cbz x2, #0x2d5610;
    /* 0x2d5608 */ ldr d0, [x2, #0x18];
    return x0;
    /* 0x2d5610 */ movi d0, #0000000000000000;
    return x0;
}
