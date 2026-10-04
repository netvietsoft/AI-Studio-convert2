// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f2678
// Recovered Name: _ZN11LayerFlowNS16LFTextModularJNI23nDestroyLFWatermarkInfoEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f2678 | Size: 16 bytes | SHA256: 98b22238e50ad852c4a7bb9215d93ffe302621295897e81dcc350d34f5249aa2
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x53a600)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS16LFTextModularJNI23nDestroyLFWatermarkInfoEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2f2678 */ cbz x2, #0x2f2684;
    /* 0x2f267c */ mov x0, x2;
    /* 0x2f2680 */ b #0x52a280;
    return x0;
}
