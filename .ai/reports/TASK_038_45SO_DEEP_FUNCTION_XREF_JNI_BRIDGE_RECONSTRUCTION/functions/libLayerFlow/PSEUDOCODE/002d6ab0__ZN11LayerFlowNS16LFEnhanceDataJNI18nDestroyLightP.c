// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d6ab0
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI18nDestroyLightParamEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d6ab0 | Size: 16 bytes | SHA256: 862ed59e3622972637c256978536b8295dff96be62426dfc6b9ffaae29099b2a
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x535ba0)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI18nDestroyLightParamEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2d6ab0 */ cbz x2, #0x2d6abc;
    /* 0x2d6ab4 */ mov x0, x2;
    /* 0x2d6ab8 */ b #0x52a280;
    return x0;
}
