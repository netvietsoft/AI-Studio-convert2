// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d55f8
// Recovered Name: _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI12nSetEyeLevelEP7_JNIEnvP7_jclassld
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d55f8 | Size: 12 bytes | SHA256: 1a37d7a8487626666355bf2126a7a07ef9e5e8a28f8eb07a4d5720d2bcb664f5
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetEyeLevel(JD)V (table at 0x535948)

jobject _ZN11LayerFlowNS27LFEffectWrinkleCleanDataJNI12nSetEyeLevelEP7_JNIEnvP7_jclassld(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x2d55f8 */ cbz x2, #0x2d5600;
    /* 0x2d55fc */ str d0, [x2, #0x10];
    return x0;
}
