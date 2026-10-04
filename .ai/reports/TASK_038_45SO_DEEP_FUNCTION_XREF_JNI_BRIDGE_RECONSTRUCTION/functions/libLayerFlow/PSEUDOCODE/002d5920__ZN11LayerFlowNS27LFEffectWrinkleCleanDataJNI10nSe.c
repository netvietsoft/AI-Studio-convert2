// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5920
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI10nSetEnableEP7_JNIEnvP7_jclasslh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5920 | Size: 20 bytes | SHA256: 98584226fb92a2ac98bc5dcb54f3cff976b4255402c93e84df8a10291d0e0a8e
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetEnable(JZ)V (table at 0x535b10)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI10nSetEnableEP7_JNIEnvP7_jclasslh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2d5920 */ cbz x2, #0x2d5930;
    /* 0x2d5924 */ tst w3, #0xff;
    /* 0x2d5928 */ cset w8, ne;
    /* 0x2d592c */ strb w8, [x2];
    return x0;
}
