// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2b8fac
// Recovered Name: _ZN11LayerFlowNS18LFAigcCacheDataJNI15nGetOpenEyeModeEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2b8fac | Size: 20 bytes | SHA256: a189e164622a415da3f7b6e374c0d12fdf9264c7871c0af7d705b0f5fcc1d982
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetOpenEyeMode(J)I (table at 0x531108)

jobject _ZN11LayerFlowNS18LFAigcCacheDataJNI15nGetOpenEyeModeEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2b8fac */ cbz x2, #0x2b8fb8;
    /* 0x2b8fb0 */ ldr w0, [x2];
    return x0;
    /* 0x2b8fb8 */ mov w0, #-1;
    return x0;
}
