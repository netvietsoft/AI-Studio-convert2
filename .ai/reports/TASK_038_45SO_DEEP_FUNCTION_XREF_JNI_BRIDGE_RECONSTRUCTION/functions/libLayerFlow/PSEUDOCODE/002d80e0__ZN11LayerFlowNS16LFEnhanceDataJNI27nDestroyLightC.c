// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d80e0
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI27nDestroyLightCorrectionItemEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d80e0 | Size: 16 bytes | SHA256: 580d4933e14e2c0c360077a80aa7346e4fa955e358d2378c1cd85ca088a89d79
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x536530)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI27nDestroyLightCorrectionItemEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2d80e0 */ cbz x2, #0x2d80ec;
    /* 0x2d80e4 */ mov x0, x2;
    /* 0x2d80e8 */ b #0x52a280;
    return x0;
}
