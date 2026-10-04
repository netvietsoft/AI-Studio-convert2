// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d5644
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI15nIsUseAutoCleanEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d5644 | Size: 20 bytes | SHA256: 4ddc429c523439c62313032078f4bae375a3745ecbb36e3f9d867942bed0de60
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nIsUseAutoClean(J)Z (table at 0x5359c0)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI15nIsUseAutoCleanEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x2d5644 */ cbz x2, #0x2d5650;
    /* 0x2d5648 */ ldrb w0, [x2, #0x28];
    return x0;
    /* 0x2d5650 */ mov w0, wzr;
    return x0;
}
