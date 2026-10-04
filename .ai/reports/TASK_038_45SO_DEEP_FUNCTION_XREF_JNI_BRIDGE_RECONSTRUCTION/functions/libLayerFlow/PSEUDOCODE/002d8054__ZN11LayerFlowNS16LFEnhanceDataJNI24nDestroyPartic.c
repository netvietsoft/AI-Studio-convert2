// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d8054
// Recovered Name: _ZN11LayerFlowNS16LFEnhanceDataJNI24nDestroyParticularsParamEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d8054 | Size: 16 bytes | SHA256: fb232f31ddc721b43d2709b3b45af20aae0948705af1af2ad4c7bdac241da739
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x5363e0)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS16LFEnhanceDataJNI24nDestroyParticularsParamEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2d8054 */ cbz x2, #0x2d8060;
    /* 0x2d8058 */ mov x0, x2;
    /* 0x2d805c */ b #0x52a280;
    return x0;
}
