// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e7374
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI18nDestroyMakeUpDataEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e7374 | Size: 16 bytes | SHA256: cfa4bd13fbe4790b47e116175e5f7c70a1671050c2763a24527f28510f46da9f
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroyMakeUpData(J)V (table at 0x538860)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI18nDestroyMakeUpDataEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2e7374 */ cbz x2, #0x2e7380;
    /* 0x2e7378 */ mov x0, x2;
    /* 0x2e737c */ b #0x52a280;
    return x0;
}
